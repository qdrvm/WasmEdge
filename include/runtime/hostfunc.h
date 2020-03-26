// SPDX-License-Identifier: Apache-2.0
//===-- ssvm/runtime/hostfunc.h - host function interface -----------------===//
//
// Part of the SSVM Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the interface of host function class.
///
//===----------------------------------------------------------------------===//
#pragma once

#include "common/value.h"
#include "instance/type.h"
#include "instance/memory.h"
#include "stackmgr.h"

#include <memory>
#include <tuple>
#include <vector>

namespace SSVM {
namespace Runtime {

class HostFunctionBase {
public:
  HostFunctionBase() = delete;
  HostFunctionBase(const uint64_t FuncCost) : Cost(FuncCost) {}
  virtual ~HostFunctionBase() = default;

  virtual ErrCode run(StackManager &StackMgr,
                      Instance::MemoryInstance &MemInst) = 0;

  /// Getter of function type.
  const Instance::FType &getFuncType() const { return FuncType; }

  /// Getter of host function cost.
  const uint64_t getCost() const { return Cost; }

protected:
  Instance::FType FuncType;
  const uint64_t Cost;
};

template <typename T> class HostFunction : public HostFunctionBase {
public:
  HostFunction(const uint64_t FuncCost = 0) : HostFunctionBase(FuncCost) {
    initializeFuncType();
  }

  ErrCode run(StackManager &StackMgr,
              Instance::MemoryInstance &MemInst) override {
    return invoke(StackMgr, MemInst);
  }

protected:
  ErrCode invoke(StackManager &StackMgr, Instance::MemoryInstance &MemInst) {
    using H = Helper<decltype(&T::body)>;
    using ArgsT = typename H::ArgsT;
    constexpr const size_t kSize = std::tuple_size_v<ArgsT>;
    if (StackMgr.size() < kSize) {
      return ErrCode::CallFunctionError;
    }
    auto GeneralArguments = std::tie(*static_cast<T *>(this), MemInst);
    auto Tuple = popTuple<ArgsT>(StackMgr, StackMgr.size() - kSize,
                                 std::make_index_sequence<kSize>());

    if constexpr (H::hasReturn) {
      using RetT = typename H::RetT;
      RetT Ret;
      ErrCode Status =
          std::apply(&T::body, std::tuple_cat(std::move(GeneralArguments),
                                              std::tie(Ret), std::move(Tuple)));

      StackMgr.push(Ret);
      return Status;
    } else {
      ErrCode Status =
          std::apply(&T::body, std::tuple_cat(std::move(GeneralArguments),
                                              std::move(Tuple)));
      return Status;
    }
  }

  void initializeFuncType() {
    using H = Helper<decltype(&T::body)>;
    using ArgsT = typename H::ArgsT;
    constexpr const size_t kSize = std::tuple_size_v<ArgsT>;
    pushValType<ArgsT>(std::make_index_sequence<kSize>());
    if constexpr (H::hasReturn) {
      using RetT = typename H::RetT;
      FuncType.Returns.push_back(ValTypeFromType<RetT>());
    }
  }

private:
  template <typename U> struct Helper;
  template <typename R, typename C, typename... A>
  struct Helper<ErrCode (C::*)(Instance::MemoryInstance &, R &, A...)> {
    using ArgsT = std::tuple<A...>;
    using RetT = R;
    static inline constexpr const bool hasReturn = true;
  };
  template <typename C, typename... A>
  struct Helper<ErrCode (C::*)(Instance::MemoryInstance &, A...)> {
    using ArgsT = std::tuple<A...>;
    static inline constexpr const bool hasReturn = false;
  };

  template <typename U>
  static U getBottomN(StackManager &StackMgr, std::size_t N) {
    return retrieveValue<U>(StackMgr.getBottomN(N));
  }
  template <typename Tuple, std::size_t... Indices>
  static Tuple popTuple(StackManager &StackMgr, std::size_t N,
                        std::index_sequence<Indices...>) {
    Tuple Result(getBottomN<std::tuple_element_t<Indices, Tuple>>(
        StackMgr, N + Indices)...);
    ((StackMgr.pop(), (void)Indices), ...);
    return Result;
  }
  template <typename Tuple, std::size_t... Indices>
  void pushValType(std::index_sequence<Indices...>) {
    (FuncType.Params.push_back(
         ValTypeFromType<std::tuple_element_t<Indices, Tuple>>()),
     ...);
  }
};

} // namespace Runtime
} // namespace SSVM
