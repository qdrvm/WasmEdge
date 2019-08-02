//===-- ssvm/executor/frameentry.h - Frame Entry class definition ---------===//
//
// Part of the SSVM Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the definition of Frame Entry class in stack manager.
///
//===----------------------------------------------------------------------===//
#pragma once

#include "ast/common.h"
#include "common.h"
#include "valueentry.h"
#include <memory>
#include <variant>
#include <vector>

class FrameEntry {
public:
  /// Constructor of initialization of a frame.
  ///
  /// Initialize the frame with parameters and local variables.
  ///
  /// \param ModuleAddr the module instance address in store manager.
  /// \param Arity the return counts of this function type.
  /// \param Args the arguments popped from stack for calling function.
  /// \param LocalDef the local variables definition in function instance.
  ///
  /// \returns None.
  FrameEntry(unsigned int ModuleAddr, unsigned int Arity,
             std::vector<std::unique_ptr<ValueEntry>> &Args,
             std::vector<std::pair<unsigned int, AST::ValType>> &LocalDef);
  ~FrameEntry() = default;

  /// Getter of module address.
  Executor::ErrCode getModuleAddr(unsigned int &Addr);

  /// Getter of arity.
  Executor::ErrCode getArity(unsigned int &Arity);

  /// Getters of local variables.
  Executor::ErrCode getValueI32(unsigned int Idx, int32_t &Val);
  Executor::ErrCode getValueI64(unsigned int Idx, int64_t &Val);
  Executor::ErrCode getValueF32(unsigned int Idx, float &Val);
  Executor::ErrCode getValueF64(unsigned int Idx, double &Val);

  /// Setters of local variables.
  Executor::ErrCode setValueI32(unsigned int Idx, int32_t Val);
  Executor::ErrCode setValueI64(unsigned int Idx, int64_t Val);
  Executor::ErrCode setValueF32(unsigned int Idx, float Val);
  Executor::ErrCode setValueF64(unsigned int Idx, double Val);

private:
  /// \name Data of frame entry.
  /// @{
  unsigned int FuncArity;
  unsigned int ModAddr;
  std::vector<std::variant<int32_t, int64_t, float, double>> Locals;
  /// @}
};