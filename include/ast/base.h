//===-- ssvm/ast/base.h - AST node base class definition -----*- C++ -*-===//
//
// Part of the SSVM Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the AST node base class, which is the
/// base class for all of the AST nodes.
///
//===----------------------------------------------------------------------===//
#pragma once

#include "executor/rtdatamgr.h"
#include "loader/filemgr.h"

namespace AST {

/// Base class of AST node.
class Base {
public:
  /// AST node attributes enumeration class.
  enum class Attr {
    Module,
    Sec_Custom,
    Sec_Type,
    Sec_Import,
    Sec_Function,
    Sec_Table,
    Sec_Memory,
    Sec_Global,
    Sec_Export,
    Sec_Start,
    Sec_Element,
    Sec_Code,
    Sec_Data,
    Desc_Import,
    Desc_Export,
    Seg_Global,
    Seg_Element,
    Seg_Code,
    Seg_Data,
    Type_Function,
    Type_Limit,
    Type_Memory,
    Type_Table,
    Type_Global,
    Expression
  };

  /// Value types enumeration class.
  enum class ValType : unsigned char {
    None = 0x40,
    I32 = 0x7F,
    I64 = 0x7E,
    F32 = 0x7D,
    F64 = 0x7C
  };

  /// Element types enumeration class.
  enum class ElemType : unsigned char { Func = 0x60, FuncRef = 0x70 };

  /// Value mutability enumeration class.
  enum class ValMut : unsigned char { Const = 0x00, Var = 0x01 };

  Base() = default;
  virtual ~Base() = default;

  /// Binary loading from file manager.
  virtual Loader::ErrCode loadBinary(FileMgr &Mgr) {
    return Loader::ErrCode::InvalidGrammar;
  };

  /// Valitation checing.
  virtual Loader::ErrCode checkValidation() {
    return Loader::ErrCode::Success;
  };

  /// Instantiation to store manager.
  virtual Executor::ErrCode instantiate(StoreMgr &Mgr, unsigned int Id) {
    return Executor::ErrCode::InstantiateFailed;
  }

protected:
  /// AST node attribute.
  Attr NodeAttr;
};

} // namespace AST