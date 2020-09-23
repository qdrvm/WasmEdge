// SPDX-License-Identifier: Apache-2.0
//===-- ssvm/loader/symbol.h - Symbol holder definition -------------------===//
//
// Part of the SSVM Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the DLSymbol and DLHandle, which holds
/// pointer to compiled object symbols.
///
//===----------------------------------------------------------------------===//
#pragma once

#include <memory>
#include <type_traits>

namespace SSVM {

class DLHandle;

/// Holder class for dlsym symbol
template <typename T = void> class DLSymbol {
private:
  friend class DLHandle;
  template <typename> friend class DLSymbol;

  DLSymbol(std::shared_ptr<DLHandle> H, T *S)
      : Handle(std::move(H)), Symbol(S) {}

public:
  DLSymbol() = default;
  DLSymbol(const DLSymbol &) = default;
  DLSymbol &operator=(const DLSymbol &) = default;
  DLSymbol(DLSymbol &&) = default;
  DLSymbol &operator=(DLSymbol &&) = default;

  operator bool() const noexcept { return Symbol != nullptr; }
  std::add_lvalue_reference_t<T> operator*() const noexcept { return *Symbol; }
  T *operator->() const noexcept { return Symbol; }
  std::add_lvalue_reference_t<T> operator[](size_t Index) const noexcept {
    return Symbol[Index];
  }
  template <typename... ArgT>
  auto operator()(ArgT... Args) const
      noexcept(noexcept(this->Symbol(std::forward<ArgT>(Args)...))) {
    return Symbol(std::forward<ArgT>(Args)...);
  }
  T *get() const noexcept { return Symbol; }
  template <typename U> DLSymbol<U> cast() const & {
    return DLSymbol<U>(Handle, reinterpret_cast<U *>(Symbol));
  }
  template <typename U> DLSymbol<U> cast() && {
    return DLSymbol<U>(Handle, reinterpret_cast<U *>(std::move(Symbol)));
  }
  auto index(size_t Index) {
    return DLSymbol<std::remove_pointer_t<T>>(Handle, Symbol[Index]);
  }

private:
  std::shared_ptr<DLHandle> Handle;
  T *Symbol = nullptr;
};

/// Holder class for dlopen handle
class DLHandle : public std::enable_shared_from_this<DLHandle> {
  DLHandle(const DLHandle &) = delete;
  DLHandle &operator=(const DLHandle &) = delete;
  DLHandle(DLHandle &&) = delete;
  DLHandle &operator=(DLHandle &&) = delete;

public:
  static std::shared_ptr<DLHandle> open(const char *Path);
  DLHandle() = default;
  ~DLHandle() noexcept;
  template <typename T = void> auto getSymbol(const char *Name) noexcept {
    return DLSymbol<T>(shared_from_this(),
                       static_cast<T *>(getRawSymbol(Name)));
  }

private:
  void *getRawSymbol(const char *Name) noexcept;
  void *Handle = nullptr;
};

} // namespace SSVM
