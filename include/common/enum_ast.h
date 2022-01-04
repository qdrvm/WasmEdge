// SPDX-License-Identifier: Apache-2.0
// SPDX-FileCopyrightText: 2019-2022 Second State INC

//===-- wasmedge/common/enum_ast.h - AST enumeration definition -----------===//
//
// Part of the WasmEdge Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the definitions of Wasm VM used AST and instruction nodes
/// enumerations.
///
//===----------------------------------------------------------------------===//

/// This header is not exported to the C API.

#ifndef WASMEDGE_C_API_ENUM_AST_H
#define WASMEDGE_C_API_ENUM_AST_H

#ifdef __cplusplus
#include <cstdint>
#include <string>
#include <unordered_map>
#endif

namespace WasmEdge {

/// AST node attributes enumeration class.
enum class ASTNodeAttr : uint8_t {
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
  Sec_DataCount,
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
  Expression,
  Instruction,
  Sec_AOT,
};

/// AST node attributes enumeration string mapping.
static inline std::unordered_map<ASTNodeAttr, std::string> ASTNodeAttrStr = {
    {ASTNodeAttr::Module, "module"},
    {ASTNodeAttr::Sec_Custom, "custom section"},
    {ASTNodeAttr::Sec_Type, "type section"},
    {ASTNodeAttr::Sec_Import, "import section"},
    {ASTNodeAttr::Sec_Function, "function section"},
    {ASTNodeAttr::Sec_Table, "table section"},
    {ASTNodeAttr::Sec_Memory, "memory section"},
    {ASTNodeAttr::Sec_Global, "global section"},
    {ASTNodeAttr::Sec_Export, "export section"},
    {ASTNodeAttr::Sec_Start, "start section"},
    {ASTNodeAttr::Sec_Element, "element section"},
    {ASTNodeAttr::Sec_Code, "code section"},
    {ASTNodeAttr::Sec_Data, "data section"},
    {ASTNodeAttr::Sec_DataCount, "data count section"},
    {ASTNodeAttr::Desc_Import, "import description"},
    {ASTNodeAttr::Desc_Export, "export description"},
    {ASTNodeAttr::Seg_Global, "global segment"},
    {ASTNodeAttr::Seg_Element, "element segment"},
    {ASTNodeAttr::Seg_Code, "code segment"},
    {ASTNodeAttr::Seg_Data, "data segment"},
    {ASTNodeAttr::Type_Function, "function type"},
    {ASTNodeAttr::Type_Limit, "limit"},
    {ASTNodeAttr::Type_Memory, "memory type"},
    {ASTNodeAttr::Type_Table, "table type"},
    {ASTNodeAttr::Type_Global, "global type"},
    {ASTNodeAttr::Expression, "expression"},
    {ASTNodeAttr::Instruction, "instruction"}};

/// Instruction opcode enumeration class.
enum class OpCode : uint16_t {
  /// Control instructions
  Unreachable = 0x00,
  Nop = 0x01,
  Block = 0x02,
  Loop = 0x03,
  If = 0x04,
  Else = 0x05,
  End = 0x0B,
  Br = 0x0C,
  Br_if = 0x0D,
  Br_table = 0x0E,
  Return = 0x0F,
  Call = 0x10,
  Call_indirect = 0x11,

  /// Reference Instructions
  Ref__null = 0xD0,
  Ref__is_null = 0xD1,
  Ref__func = 0xD2,

  /// Parametric Instructions
  Drop = 0x1A,
  Select = 0x1B,
  Select_t = 0x1C,

  /// Variable Instructions
  Local__get = 0x20,
  Local__set = 0x21,
  Local__tee = 0x22,
  Global__get = 0x23,
  Global__set = 0x24,

  /// Table Instructions (part 1)
  Table__get = 0x25,
  Table__set = 0x26,

  /// Memory Instructions (part 1)
  I32__load = 0x28,
  I64__load = 0x29,
  F32__load = 0x2A,
  F64__load = 0x2B,
  I32__load8_s = 0x2C,
  I32__load8_u = 0x2D,
  I32__load16_s = 0x2E,
  I32__load16_u = 0x2F,
  I64__load8_s = 0x30,
  I64__load8_u = 0x31,
  I64__load16_s = 0x32,
  I64__load16_u = 0x33,
  I64__load32_s = 0x34,
  I64__load32_u = 0x35,
  I32__store = 0x36,
  I64__store = 0x37,
  F32__store = 0x38,
  F64__store = 0x39,
  I32__store8 = 0x3A,
  I32__store16 = 0x3B,
  I64__store8 = 0x3C,
  I64__store16 = 0x3D,
  I64__store32 = 0x3E,
  Memory__size = 0x3F,
  Memory__grow = 0x40,

  /// Const numeric instructions
  I32__const = 0x41,
  I64__const = 0x42,
  F32__const = 0x43,
  F64__const = 0x44,

  /// Numeric instructions
  I32__eqz = 0x45,
  I32__eq = 0x46,
  I32__ne = 0x47,
  I32__lt_s = 0x48,
  I32__lt_u = 0x49,
  I32__gt_s = 0x4A,
  I32__gt_u = 0x4B,
  I32__le_s = 0x4C,
  I32__le_u = 0x4D,
  I32__ge_s = 0x4E,
  I32__ge_u = 0x4F,
  I64__eqz = 0x50,
  I64__eq = 0x51,
  I64__ne = 0x52,
  I64__lt_s = 0x53,
  I64__lt_u = 0x54,
  I64__gt_s = 0x55,
  I64__gt_u = 0x56,
  I64__le_s = 0x57,
  I64__le_u = 0x58,
  I64__ge_s = 0x59,
  I64__ge_u = 0x5A,
  F32__eq = 0x5B,
  F32__ne = 0x5C,
  F32__lt = 0x5D,
  F32__gt = 0x5E,
  F32__le = 0x5F,
  F32__ge = 0x60,
  F64__eq = 0x61,
  F64__ne = 0x62,
  F64__lt = 0x63,
  F64__gt = 0x64,
  F64__le = 0x65,
  F64__ge = 0x66,
  I32__clz = 0x67,
  I32__ctz = 0x68,
  I32__popcnt = 0x69,
  I32__add = 0x6A,
  I32__sub = 0x6B,
  I32__mul = 0x6C,
  I32__div_s = 0x6D,
  I32__div_u = 0x6E,
  I32__rem_s = 0x6F,
  I32__rem_u = 0x70,
  I32__and = 0x71,
  I32__or = 0x72,
  I32__xor = 0x73,
  I32__shl = 0x74,
  I32__shr_s = 0x75,
  I32__shr_u = 0x76,
  I32__rotl = 0x77,
  I32__rotr = 0x78,
  I64__clz = 0x79,
  I64__ctz = 0x7a,
  I64__popcnt = 0x7b,
  I64__add = 0x7c,
  I64__sub = 0x7d,
  I64__mul = 0x7e,
  I64__div_s = 0x7f,
  I64__div_u = 0x80,
  I64__rem_s = 0x81,
  I64__rem_u = 0x82,
  I64__and = 0x83,
  I64__or = 0x84,
  I64__xor = 0x85,
  I64__shl = 0x86,
  I64__shr_s = 0x87,
  I64__shr_u = 0x88,
  I64__rotl = 0x89,
  I64__rotr = 0x8A,
  F32__abs = 0x8B,
  F32__neg = 0x8C,
  F32__ceil = 0x8D,
  F32__floor = 0x8E,
  F32__trunc = 0x8F,
  F32__nearest = 0x90,
  F32__sqrt = 0x91,
  F32__add = 0x92,
  F32__sub = 0x93,
  F32__mul = 0x94,
  F32__div = 0x95,
  F32__min = 0x96,
  F32__max = 0x97,
  F32__copysign = 0x98,
  F64__abs = 0x99,
  F64__neg = 0x9A,
  F64__ceil = 0x9B,
  F64__floor = 0x9C,
  F64__trunc = 0x9D,
  F64__nearest = 0x9E,
  F64__sqrt = 0x9F,
  F64__add = 0xA0,
  F64__sub = 0xA1,
  F64__mul = 0xA2,
  F64__div = 0xA3,
  F64__min = 0xA4,
  F64__max = 0xA5,
  F64__copysign = 0xA6,
  I32__wrap_i64 = 0xA7,
  I32__trunc_f32_s = 0xA8,
  I32__trunc_f32_u = 0xA9,
  I32__trunc_f64_s = 0xAA,
  I32__trunc_f64_u = 0xAB,
  I64__extend_i32_s = 0xAC,
  I64__extend_i32_u = 0xAD,
  I64__trunc_f32_s = 0xAE,
  I64__trunc_f32_u = 0xAF,
  I64__trunc_f64_s = 0xB0,
  I64__trunc_f64_u = 0xB1,
  F32__convert_i32_s = 0xB2,
  F32__convert_i32_u = 0xB3,
  F32__convert_i64_s = 0xB4,
  F32__convert_i64_u = 0xB5,
  F32__demote_f64 = 0xB6,
  F64__convert_i32_s = 0xB7,
  F64__convert_i32_u = 0xB8,
  F64__convert_i64_s = 0xB9,
  F64__convert_i64_u = 0xBA,
  F64__promote_f32 = 0xBB,
  I32__reinterpret_f32 = 0xBC,
  I64__reinterpret_f64 = 0xBD,
  F32__reinterpret_i32 = 0xBE,
  F64__reinterpret_i64 = 0xBF,
  I32__extend8_s = 0xC0,
  I32__extend16_s = 0xC1,
  I64__extend8_s = 0xC2,
  I64__extend16_s = 0xC3,
  I64__extend32_s = 0xC4,
  I32__trunc_sat_f32_s = 0xFC00,
  I32__trunc_sat_f32_u = 0xFC01,
  I32__trunc_sat_f64_s = 0xFC02,
  I32__trunc_sat_f64_u = 0xFC03,
  I64__trunc_sat_f32_s = 0xFC04,
  I64__trunc_sat_f32_u = 0xFC05,
  I64__trunc_sat_f64_s = 0xFC06,
  I64__trunc_sat_f64_u = 0xFC07,

  /// Memory Instructions (part 2)
  Memory__init = 0xFC08,
  Data__drop = 0xFC09,
  Memory__copy = 0xFC0A,
  Memory__fill = 0xFC0B,

  /// Table Instructions (part 2)
  Table__init = 0xFC0C,
  Elem__drop = 0xFC0D,
  Table__copy = 0xFC0E,
  Table__grow = 0xFC0F,
  Table__size = 0xFC10,
  Table__fill = 0xFC11,

  /// SIMD Memory Instructions
  V128__load = 0xFD00,
  V128__load8x8_s = 0xFD01,
  V128__load8x8_u = 0xFD02,
  V128__load16x4_s = 0xFD03,
  V128__load16x4_u = 0xFD04,
  V128__load32x2_s = 0xFD05,
  V128__load32x2_u = 0xFD06,
  V128__load8_splat = 0xFD07,
  V128__load16_splat = 0xFD08,
  V128__load32_splat = 0xFD09,
  V128__load64_splat = 0xFD0A,
  V128__load32_zero = 0xFD5C,
  V128__load64_zero = 0xFD5D,
  V128__store = 0xFD0B,
  V128__load8_lane = 0xFD54,
  V128__load16_lane = 0xFD55,
  V128__load32_lane = 0xFD56,
  V128__load64_lane = 0xFD57,
  V128__store8_lane = 0xFD58,
  V128__store16_lane = 0xFD59,
  V128__store32_lane = 0xFD5A,
  V128__store64_lane = 0xFD5B,

  /// SIMD Const Instructions
  V128__const = 0xFD0C,

  /// SIMD Shuffle Instructions
  I8x16__shuffle = 0xFD0D,

  /// SIMD Lane Instructions
  I8x16__extract_lane_s = 0xFD15,
  I8x16__extract_lane_u = 0xFD16,
  I8x16__replace_lane = 0xFD17,
  I16x8__extract_lane_s = 0xFD18,
  I16x8__extract_lane_u = 0xFD19,
  I16x8__replace_lane = 0xFD1A,
  I32x4__extract_lane = 0xFD1B,
  I32x4__replace_lane = 0xFD1C,
  I64x2__extract_lane = 0xFD1D,
  I64x2__replace_lane = 0xFD1E,
  F32x4__extract_lane = 0xFD1F,
  F32x4__replace_lane = 0xFD20,
  F64x2__extract_lane = 0xFD21,
  F64x2__replace_lane = 0xFD22,

  /// SIMD Numeric Instructions
  I8x16__swizzle = 0xFD0E,
  I8x16__splat = 0xFD0F,
  I16x8__splat = 0xFD10,
  I32x4__splat = 0xFD11,
  I64x2__splat = 0xFD12,
  F32x4__splat = 0xFD13,
  F64x2__splat = 0xFD14,

  I8x16__eq = 0xFD23,
  I8x16__ne = 0xFD24,
  I8x16__lt_s = 0xFD25,
  I8x16__lt_u = 0xFD26,
  I8x16__gt_s = 0xFD27,
  I8x16__gt_u = 0xFD28,
  I8x16__le_s = 0xFD29,
  I8x16__le_u = 0xFD2A,
  I8x16__ge_s = 0xFD2B,
  I8x16__ge_u = 0xFD2C,

  I16x8__eq = 0xFD2D,
  I16x8__ne = 0xFD2E,
  I16x8__lt_s = 0xFD2F,
  I16x8__lt_u = 0xFD30,
  I16x8__gt_s = 0xFD31,
  I16x8__gt_u = 0xFD32,
  I16x8__le_s = 0xFD33,
  I16x8__le_u = 0xFD34,
  I16x8__ge_s = 0xFD35,
  I16x8__ge_u = 0xFD36,

  I32x4__eq = 0xFD37,
  I32x4__ne = 0xFD38,
  I32x4__lt_s = 0xFD39,
  I32x4__lt_u = 0xFD3A,
  I32x4__gt_s = 0xFD3B,
  I32x4__gt_u = 0xFD3C,
  I32x4__le_s = 0xFD3D,
  I32x4__le_u = 0xFD3E,
  I32x4__ge_s = 0xFD3F,
  I32x4__ge_u = 0xFD40,

  I64x2__eq = 0xFDD6,
  I64x2__ne = 0xFDD7,
  I64x2__lt_s = 0xFDD8,
  I64x2__gt_s = 0xFDD9,
  I64x2__le_s = 0xFDDA,
  I64x2__ge_s = 0xFDDB,

  F32x4__eq = 0xFD41,
  F32x4__ne = 0xFD42,
  F32x4__lt = 0xFD43,
  F32x4__gt = 0xFD44,
  F32x4__le = 0xFD45,
  F32x4__ge = 0xFD46,

  F64x2__eq = 0xFD47,
  F64x2__ne = 0xFD48,
  F64x2__lt = 0xFD49,
  F64x2__gt = 0xFD4A,
  F64x2__le = 0xFD4B,
  F64x2__ge = 0xFD4C,

  V128__not = 0xFD4D,
  V128__and = 0xFD4E,
  V128__andnot = 0xFD4F,
  V128__or = 0xFD50,
  V128__xor = 0xFD51,
  V128__bitselect = 0xFD52,
  V128__any_true = 0xFD53,

  I8x16__abs = 0xFD60,
  I8x16__neg = 0xFD61,
  I8x16__popcnt = 0xFD62,
  I8x16__all_true = 0xFD63,
  I8x16__bitmask = 0xFD64,
  I8x16__narrow_i16x8_s = 0xFD65,
  I8x16__narrow_i16x8_u = 0xFD66,
  I8x16__shl = 0xFD6B,
  I8x16__shr_s = 0xFD6C,
  I8x16__shr_u = 0xFD6D,
  I8x16__add = 0xFD6E,
  I8x16__add_sat_s = 0xFD6F,
  I8x16__add_sat_u = 0xFD70,
  I8x16__sub = 0xFD71,
  I8x16__sub_sat_s = 0xFD72,
  I8x16__sub_sat_u = 0xFD73,
  I8x16__min_s = 0xFD76,
  I8x16__min_u = 0xFD77,
  I8x16__max_s = 0xFD78,
  I8x16__max_u = 0xFD79,
  I8x16__avgr_u = 0xFD7B,

  I16x8__abs = 0xFD80,
  I16x8__neg = 0xFD81,
  I16x8__all_true = 0xFD83,
  I16x8__bitmask = 0xFD84,
  I16x8__narrow_i32x4_s = 0xFD85,
  I16x8__narrow_i32x4_u = 0xFD86,
  I16x8__extend_low_i8x16_s = 0xFD87,
  I16x8__extend_high_i8x16_s = 0xFD88,
  I16x8__extend_low_i8x16_u = 0xFD89,
  I16x8__extend_high_i8x16_u = 0xFD8A,
  I16x8__shl = 0xFD8B,
  I16x8__shr_s = 0xFD8C,
  I16x8__shr_u = 0xFD8D,
  I16x8__add = 0xFD8E,
  I16x8__add_sat_s = 0xFD8F,
  I16x8__add_sat_u = 0xFD90,
  I16x8__sub = 0xFD91,
  I16x8__sub_sat_s = 0xFD92,
  I16x8__sub_sat_u = 0xFD93,
  I16x8__mul = 0xFD95,
  I16x8__min_s = 0xFD96,
  I16x8__min_u = 0xFD97,
  I16x8__max_s = 0xFD98,
  I16x8__max_u = 0xFD99,
  I16x8__avgr_u = 0xFD9B,
  I16x8__extmul_low_i8x16_s = 0xFD9C,
  I16x8__extmul_high_i8x16_s = 0xFD9D,
  I16x8__extmul_low_i8x16_u = 0xFD9E,
  I16x8__extmul_high_i8x16_u = 0xFD9F,
  I16x8__q15mulr_sat_s = 0xFD82,
  I16x8__extadd_pairwise_i8x16_s = 0xFD7C,
  I16x8__extadd_pairwise_i8x16_u = 0xFD7D,

  I32x4__abs = 0xFDA0,
  I32x4__neg = 0xFDA1,
  I32x4__all_true = 0xFDA3,
  I32x4__bitmask = 0xFDA4,
  I32x4__extend_low_i16x8_s = 0xFDA7,
  I32x4__extend_high_i16x8_s = 0xFDA8,
  I32x4__extend_low_i16x8_u = 0xFDA9,
  I32x4__extend_high_i16x8_u = 0xFDAA,
  I32x4__shl = 0xFDAB,
  I32x4__shr_s = 0xFDAC,
  I32x4__shr_u = 0xFDAD,
  I32x4__add = 0xFDAE,
  I32x4__sub = 0xFDB1,
  I32x4__mul = 0xFDB5,
  I32x4__min_s = 0xFDB6,
  I32x4__min_u = 0xFDB7,
  I32x4__max_s = 0xFDB8,
  I32x4__max_u = 0xFDB9,
  I32x4__dot_i16x8_s = 0xFDBA,
  I32x4__extmul_low_i16x8_s = 0xFDBC,
  I32x4__extmul_high_i16x8_s = 0xFDBD,
  I32x4__extmul_low_i16x8_u = 0xFDBE,
  I32x4__extmul_high_i16x8_u = 0xFDBF,
  I32x4__extadd_pairwise_i16x8_s = 0xFD7E,
  I32x4__extadd_pairwise_i16x8_u = 0xFD7F,

  I64x2__abs = 0xFDC0,
  I64x2__neg = 0xFDC1,
  I64x2__all_true = 0xFDC3,
  I64x2__bitmask = 0xFDC4,
  I64x2__extend_low_i32x4_s = 0xFDC7,
  I64x2__extend_high_i32x4_s = 0xFDC8,
  I64x2__extend_low_i32x4_u = 0xFDC9,
  I64x2__extend_high_i32x4_u = 0xFDCA,
  I64x2__shl = 0xFDCB,
  I64x2__shr_s = 0xFDCC,
  I64x2__shr_u = 0xFDCD,
  I64x2__add = 0xFDCE,
  I64x2__sub = 0xFDD1,
  I64x2__mul = 0xFDD5,
  I64x2__extmul_low_i32x4_s = 0xFDDC,
  I64x2__extmul_high_i32x4_s = 0xFDDD,
  I64x2__extmul_low_i32x4_u = 0xFDDE,
  I64x2__extmul_high_i32x4_u = 0xFDDF,

  F32x4__abs = 0xFDE0,
  F32x4__neg = 0xFDE1,
  F32x4__sqrt = 0xFDE3,
  F32x4__add = 0xFDE4,
  F32x4__sub = 0xFDE5,
  F32x4__mul = 0xFDE6,
  F32x4__div = 0xFDE7,
  F32x4__min = 0xFDE8,
  F32x4__max = 0xFDE9,
  F32x4__pmin = 0xFDEA,
  F32x4__pmax = 0xFDEB,
  F32x4__ceil = 0xFD67,
  F32x4__floor = 0xFD68,
  F32x4__trunc = 0xFD69,
  F32x4__nearest = 0xFD6A,

  F64x2__abs = 0xFDEC,
  F64x2__neg = 0xFDED,
  F64x2__sqrt = 0xFDEF,
  F64x2__add = 0xFDF0,
  F64x2__sub = 0xFDF1,
  F64x2__mul = 0xFDF2,
  F64x2__div = 0xFDF3,
  F64x2__min = 0xFDF4,
  F64x2__max = 0xFDF5,
  F64x2__pmin = 0xFDF6,
  F64x2__pmax = 0xFDF7,
  F64x2__ceil = 0xFD74,
  F64x2__floor = 0xFD75,
  F64x2__trunc = 0xFD7A,
  F64x2__nearest = 0xFD94,

  I32x4__trunc_sat_f32x4_s = 0xFDF8,
  I32x4__trunc_sat_f32x4_u = 0xFDF9,
  F32x4__convert_i32x4_s = 0xFDFA,
  F32x4__convert_i32x4_u = 0xFDFB,
  I32x4__trunc_sat_f64x2_s_zero = 0xFDFC,
  I32x4__trunc_sat_f64x2_u_zero = 0xFDFD,
  F64x2__convert_low_i32x4_s = 0xFDFE,
  F64x2__convert_low_i32x4_u = 0xFDFF,
  F32x4__demote_f64x2_zero = 0xFD5E,
  F64x2__promote_low_f32x4 = 0xFD5F
};

/// Instruction opcode enumeration string mapping.
static inline std::unordered_map<OpCode, std::string> OpCodeStr = {
    /// Control instructions
    {OpCode::Unreachable, "unreachable"},
    {OpCode::Nop, "nop"},
    {OpCode::Block, "block"},
    {OpCode::Loop, "loop"},
    {OpCode::If, "if"},
    {OpCode::Else, "else"},
    {OpCode::End, "end"},
    {OpCode::Br, "br"},
    {OpCode::Br_if, "br_if"},
    {OpCode::Br_table, "br_table"},
    {OpCode::Return, "return"},
    {OpCode::Call, "call"},
    {OpCode::Call_indirect, "call_indirect"},

    /// Reference Instructions
    {OpCode::Ref__null, "ref.null"},
    {OpCode::Ref__is_null, "ref.is_null"},
    {OpCode::Ref__func, "ref.func"},

    /// Parametric Instructions
    {OpCode::Drop, "drop"},
    {OpCode::Select, "select"},
    {OpCode::Select_t, "select"},

    /// Variable Instructions
    {OpCode::Local__get, "local.get"},
    {OpCode::Local__set, "local.set"},
    {OpCode::Local__tee, "local.tee"},
    {OpCode::Global__get, "global.get"},
    {OpCode::Global__set, "global.set"},

    /// Table Instructions (part 1)
    {OpCode::Table__get, "table.get"},
    {OpCode::Table__set, "table.set"},

    /// Memory Instructions (part 1)
    {OpCode::I32__load, "i32.load"},
    {OpCode::I64__load, "i64.load"},
    {OpCode::F32__load, "f32.load"},
    {OpCode::F64__load, "f64.load"},
    {OpCode::I32__load8_s, "i32.load8_s"},
    {OpCode::I32__load8_u, "i32.load8_u"},
    {OpCode::I32__load16_s, "i32.load16_s"},
    {OpCode::I32__load16_u, "i32.load16_u"},
    {OpCode::I64__load8_s, "i64.load8_s"},
    {OpCode::I64__load8_u, "i64.load8_u"},
    {OpCode::I64__load16_s, "i64.load16_s"},
    {OpCode::I64__load16_u, "i64.load16_u"},
    {OpCode::I64__load32_s, "i64.load32_s"},
    {OpCode::I64__load32_u, "i64.load32_u"},
    {OpCode::I32__store, "i32.store"},
    {OpCode::I64__store, "i64.store"},
    {OpCode::F32__store, "f32.store"},
    {OpCode::F64__store, "f64.store"},
    {OpCode::I32__store8, "i32.store8"},
    {OpCode::I32__store16, "i32.store16"},
    {OpCode::I64__store8, "i64.store8"},
    {OpCode::I64__store16, "i64.store16"},
    {OpCode::I64__store32, "i64.store32"},
    {OpCode::Memory__size, "memory.size"},
    {OpCode::Memory__grow, "memory.grow"},

    /// Const numeric instructions
    {OpCode::I32__const, "i32.const"},
    {OpCode::I64__const, "i64.const"},
    {OpCode::F32__const, "f32.const"},
    {OpCode::F64__const, "f64.const"},

    /// Numeric instructions
    {OpCode::I32__eqz, "i32.eqz"},
    {OpCode::I32__eq, "i32.eq"},
    {OpCode::I32__ne, "i32.ne"},
    {OpCode::I32__lt_s, "i32.lt_s"},
    {OpCode::I32__lt_u, "i32.lt_u"},
    {OpCode::I32__gt_s, "i32.gt_s"},
    {OpCode::I32__gt_u, "i32.gt_u"},
    {OpCode::I32__le_s, "i32.le_s"},
    {OpCode::I32__le_u, "i32.le_u"},
    {OpCode::I32__ge_s, "i32.ge_s"},
    {OpCode::I32__ge_u, "i32.ge_u"},
    {OpCode::I64__eqz, "i64.eqz"},
    {OpCode::I64__eq, "i64.eq"},
    {OpCode::I64__ne, "i64.ne"},
    {OpCode::I64__lt_s, "i64.lt_s"},
    {OpCode::I64__lt_u, "i64.lt_u"},
    {OpCode::I64__gt_s, "i64.gt_s"},
    {OpCode::I64__gt_u, "i64.gt_u"},
    {OpCode::I64__le_s, "i64.le_s"},
    {OpCode::I64__le_u, "i64.le_u"},
    {OpCode::I64__ge_s, "i64.ge_s"},
    {OpCode::I64__ge_u, "i64.ge_u"},
    {OpCode::F32__eq, "f32.eq"},
    {OpCode::F32__ne, "f32.ne"},
    {OpCode::F32__lt, "f32.lt"},
    {OpCode::F32__gt, "f32.gt"},
    {OpCode::F32__le, "f32.le"},
    {OpCode::F32__ge, "f32.ge"},
    {OpCode::F64__eq, "f64.eq"},
    {OpCode::F64__ne, "f64.ne"},
    {OpCode::F64__lt, "f64.lt"},
    {OpCode::F64__gt, "f64.gt"},
    {OpCode::F64__le, "f64.le"},
    {OpCode::F64__ge, "f64.ge"},
    {OpCode::I32__clz, "i32.clz"},
    {OpCode::I32__ctz, "i32.ctz"},
    {OpCode::I32__popcnt, "i32.popcnt"},
    {OpCode::I32__add, "i32.add"},
    {OpCode::I32__sub, "i32.sub"},
    {OpCode::I32__mul, "i32.mul"},
    {OpCode::I32__div_s, "i32.div_s"},
    {OpCode::I32__div_u, "i32.div_u"},
    {OpCode::I32__rem_s, "i32.rem_s"},
    {OpCode::I32__rem_u, "i32.rem_u"},
    {OpCode::I32__and, "i32.and"},
    {OpCode::I32__or, "i32.or"},
    {OpCode::I32__xor, "i32.xor"},
    {OpCode::I32__shl, "i32.shl"},
    {OpCode::I32__shr_s, "i32.shr_s"},
    {OpCode::I32__shr_u, "i32.shr_u"},
    {OpCode::I32__rotl, "i32.rotl"},
    {OpCode::I32__rotr, "i32.rotr"},
    {OpCode::I64__clz, "i64.clz"},
    {OpCode::I64__ctz, "i64.ctz"},
    {OpCode::I64__popcnt, "i64.popcnt"},
    {OpCode::I64__add, "i64.add"},
    {OpCode::I64__sub, "i64.sub"},
    {OpCode::I64__mul, "i64.mul"},
    {OpCode::I64__div_s, "i64.div_s"},
    {OpCode::I64__div_u, "i64.div_u"},
    {OpCode::I64__rem_s, "i64.rem_s"},
    {OpCode::I64__rem_u, "i64.rem_u"},
    {OpCode::I64__and, "i64.and"},
    {OpCode::I64__or, "i64.or"},
    {OpCode::I64__xor, "i64.xor"},
    {OpCode::I64__shl, "i64.shl"},
    {OpCode::I64__shr_s, "i64.shr_s"},
    {OpCode::I64__shr_u, "i64.shr_u"},
    {OpCode::I64__rotl, "i64.rotl"},
    {OpCode::I64__rotr, "i64.rotr"},
    {OpCode::F32__abs, "f32.abs"},
    {OpCode::F32__neg, "f32.neg"},
    {OpCode::F32__ceil, "f32.ceil"},
    {OpCode::F32__floor, "f32.floor"},
    {OpCode::F32__trunc, "f32.trunc"},
    {OpCode::F32__nearest, "f32.nearest"},
    {OpCode::F32__sqrt, "f32.sqrt"},
    {OpCode::F32__add, "f32.add"},
    {OpCode::F32__sub, "f32.sub"},
    {OpCode::F32__mul, "f32.mul"},
    {OpCode::F32__div, "f32.div"},
    {OpCode::F32__min, "f32.min"},
    {OpCode::F32__max, "f32.max"},
    {OpCode::F32__copysign, "f32.copysign"},
    {OpCode::F64__abs, "f64.abs"},
    {OpCode::F64__neg, "f64.neg"},
    {OpCode::F64__ceil, "f64.ceil"},
    {OpCode::F64__floor, "f64.floor"},
    {OpCode::F64__trunc, "f64.trunc"},
    {OpCode::F64__nearest, "f64.nearest"},
    {OpCode::F64__sqrt, "f64.sqrt"},
    {OpCode::F64__add, "f64.add"},
    {OpCode::F64__sub, "f64.sub"},
    {OpCode::F64__mul, "f64.mul"},
    {OpCode::F64__div, "f64.div"},
    {OpCode::F64__min, "f64.min"},
    {OpCode::F64__max, "f64.max"},
    {OpCode::F64__copysign, "f64.copysign"},
    {OpCode::I32__wrap_i64, "i32.wrap_i64"},
    {OpCode::I32__trunc_f32_s, "i32.trunc_f32_s"},
    {OpCode::I32__trunc_f32_u, "i32.trunc_f32_u"},
    {OpCode::I32__trunc_f64_s, "i32.trunc_f64_s"},
    {OpCode::I32__trunc_f64_u, "i32.trunc_f64_u"},
    {OpCode::I64__extend_i32_s, "i64.extend_i32_s"},
    {OpCode::I64__extend_i32_u, "i64.extend_i32_u"},
    {OpCode::I64__trunc_f32_s, "i64.trunc_f32_s"},
    {OpCode::I64__trunc_f32_u, "i64.trunc_f32_u"},
    {OpCode::I64__trunc_f64_s, "i64.trunc_f64_s"},
    {OpCode::I64__trunc_f64_u, "i64.trunc_f64_u"},
    {OpCode::F32__convert_i32_s, "f32.convert_i32_s"},
    {OpCode::F32__convert_i32_u, "f32.convert_i32_u"},
    {OpCode::F32__convert_i64_s, "f32.convert_i64_s"},
    {OpCode::F32__convert_i64_u, "f32.convert_i64_u"},
    {OpCode::F32__demote_f64, "f32.demote_f64"},
    {OpCode::F64__convert_i32_s, "f64.convert_i32_s"},
    {OpCode::F64__convert_i32_u, "f64.convert_i32_u"},
    {OpCode::F64__convert_i64_s, "f64.convert_i64_s"},
    {OpCode::F64__convert_i64_u, "f64.convert_i64_u"},
    {OpCode::F64__promote_f32, "f64.promote_f32"},
    {OpCode::I32__reinterpret_f32, "i32.reinterpret_f32"},
    {OpCode::I64__reinterpret_f64, "i64.reinterpret_f64"},
    {OpCode::F32__reinterpret_i32, "f32.reinterpret_i32"},
    {OpCode::F64__reinterpret_i64, "f64.reinterpret_i64"},
    {OpCode::I32__extend8_s, "i32.extend8_s"},
    {OpCode::I32__extend16_s, "i32.extend16_s"},
    {OpCode::I64__extend8_s, "i64.extend8_s"},
    {OpCode::I64__extend16_s, "i64.extend16_s"},
    {OpCode::I64__extend32_s, "i64.extend32_s"},
    {OpCode::I32__trunc_sat_f32_s, "i32.trunc_sat_f32_s"},
    {OpCode::I32__trunc_sat_f32_u, "i32.trunc_sat_f32_u"},
    {OpCode::I32__trunc_sat_f64_s, "i32.trunc_sat_f64_s"},
    {OpCode::I32__trunc_sat_f64_u, "i32.trunc_sat_f64_u"},
    {OpCode::I64__trunc_sat_f32_s, "i64.trunc_sat_f32_s"},
    {OpCode::I64__trunc_sat_f32_u, "i64.trunc_sat_f32_u"},
    {OpCode::I64__trunc_sat_f64_s, "i64.trunc_sat_f64_s"},
    {OpCode::I64__trunc_sat_f64_u, "i64.trunc_sat_f64_u"},

    /// Memory Instructions (part 2)
    {OpCode::Memory__init, "memory.init"},
    {OpCode::Data__drop, "data.drop"},
    {OpCode::Memory__copy, "memory.copy"},
    {OpCode::Memory__fill, "memory.fill"},

    /// Table Instructions (part 2)
    {OpCode::Table__init, "table.init"},
    {OpCode::Elem__drop, "elem.drop"},
    {OpCode::Table__copy, "table.copy"},
    {OpCode::Table__grow, "table.grow"},
    {OpCode::Table__size, "table.size"},
    {OpCode::Table__fill, "table.fill"},

    /// SIMD Memory Instructions
    {OpCode::V128__load, "v128.load"},
    {OpCode::V128__load8x8_s, "v128.load8x8_s"},
    {OpCode::V128__load8x8_u, "v128.load8x8_u"},
    {OpCode::V128__load16x4_s, "v128.load16x4_s"},
    {OpCode::V128__load16x4_u, "v128.load16x4_u"},
    {OpCode::V128__load32x2_s, "v128.load32x2_s"},
    {OpCode::V128__load32x2_u, "v128.load32x2_u"},
    {OpCode::V128__load8_splat, "v128.load8_splat"},
    {OpCode::V128__load16_splat, "v128.load16_splat"},
    {OpCode::V128__load32_splat, "v128.load32_splat"},
    {OpCode::V128__load64_splat, "v128.load64_splat"},
    {OpCode::V128__load32_zero, "v128.load32_zero"},
    {OpCode::V128__load64_zero, "v128.load64_zero"},
    {OpCode::V128__store, "v128.store"},
    {OpCode::V128__load8_lane, "v128.load8_lane"},
    {OpCode::V128__load16_lane, "v128.load16_lane"},
    {OpCode::V128__load32_lane, "v128.load32_lane"},
    {OpCode::V128__load64_lane, "v128.load64_lane"},
    {OpCode::V128__store8_lane, "v128.store8_lane"},
    {OpCode::V128__store16_lane, "v128.store16_lane"},
    {OpCode::V128__store32_lane, "v128.store32_lane"},
    {OpCode::V128__store64_lane, "v128.store64_lane"},

    /// SIMD Const Instructions
    {OpCode::V128__const, "v128.const"},

    /// SIMD Shuffle Instructions
    {OpCode::I8x16__shuffle, "i8x16.shuffle"},

    /// SIMD Lane Instructions
    {OpCode::I8x16__extract_lane_s, "i8x16.extract_lane_s"},
    {OpCode::I8x16__extract_lane_u, "i8x16.extract_lane_u"},
    {OpCode::I8x16__replace_lane, "i8x16.replace_lane"},
    {OpCode::I16x8__extract_lane_s, "i16x8.extract_lane_s"},
    {OpCode::I16x8__extract_lane_u, "i16x8.extract_lane_u"},
    {OpCode::I16x8__replace_lane, "i16x8.replace_lane"},
    {OpCode::I32x4__extract_lane, "i32x4.extract_lane"},
    {OpCode::I32x4__replace_lane, "i32x4.replace_lane"},
    {OpCode::I64x2__extract_lane, "i64x2.extract_lane"},
    {OpCode::I64x2__replace_lane, "i64x2.replace_lane"},
    {OpCode::F32x4__extract_lane, "f32x4.extract_lane"},
    {OpCode::F32x4__replace_lane, "f32x4.replace_lane"},
    {OpCode::F64x2__extract_lane, "f64x2.extract_lane"},
    {OpCode::F64x2__replace_lane, "f64x2.replace_lane"},

    /// SIMD Numeric Instructions
    {OpCode::I8x16__swizzle, "i8x16.swizzle"},
    {OpCode::I8x16__splat, "i8x16.splat"},
    {OpCode::I16x8__splat, "i16x8.splat"},
    {OpCode::I32x4__splat, "i32x4.splat"},
    {OpCode::I64x2__splat, "i64x2.splat"},
    {OpCode::F32x4__splat, "f32x4.splat"},
    {OpCode::F64x2__splat, "f64x2.splat"},

    {OpCode::I8x16__eq, "i8x16.eq"},
    {OpCode::I8x16__ne, "i8x16.ne"},
    {OpCode::I8x16__lt_s, "i8x16.lt_s"},
    {OpCode::I8x16__lt_u, "i8x16.lt_u"},
    {OpCode::I8x16__gt_s, "i8x16.gt_s"},
    {OpCode::I8x16__gt_u, "i8x16.gt_u"},
    {OpCode::I8x16__le_s, "i8x16.le_s"},
    {OpCode::I8x16__le_u, "i8x16.le_u"},
    {OpCode::I8x16__ge_s, "i8x16.ge_s"},
    {OpCode::I8x16__ge_u, "i8x16.ge_u"},

    {OpCode::I16x8__eq, "i16x8.eq"},
    {OpCode::I16x8__ne, "i16x8.ne"},
    {OpCode::I16x8__lt_s, "i16x8.lt_s"},
    {OpCode::I16x8__lt_u, "i16x8.lt_u"},
    {OpCode::I16x8__gt_s, "i16x8.gt_s"},
    {OpCode::I16x8__gt_u, "i16x8.gt_u"},
    {OpCode::I16x8__le_s, "i16x8.le_s"},
    {OpCode::I16x8__le_u, "i16x8.le_u"},
    {OpCode::I16x8__ge_s, "i16x8.ge_s"},
    {OpCode::I16x8__ge_u, "i16x8.ge_u"},

    {OpCode::I32x4__eq, "i32x4.eq"},
    {OpCode::I32x4__ne, "i32x4.ne"},
    {OpCode::I32x4__lt_s, "i32x4.lt_s"},
    {OpCode::I32x4__lt_u, "i32x4.lt_u"},
    {OpCode::I32x4__gt_s, "i32x4.gt_s"},
    {OpCode::I32x4__gt_u, "i32x4.gt_u"},
    {OpCode::I32x4__le_s, "i32x4.le_s"},
    {OpCode::I32x4__le_u, "i32x4.le_u"},
    {OpCode::I32x4__ge_s, "i32x4.ge_s"},
    {OpCode::I32x4__ge_u, "i32x4.ge_u"},

    {OpCode::I64x2__eq, "i64x2.eq"},
    {OpCode::I64x2__ne, "i64x2.ne"},
    {OpCode::I64x2__lt_s, "i64x2.lt_s"},
    {OpCode::I64x2__gt_s, "i64x2.gt_s"},
    {OpCode::I64x2__le_s, "i64x2.le_s"},
    {OpCode::I64x2__ge_s, "i64x2.ge_s"},

    {OpCode::F32x4__eq, "f32x4.eq"},
    {OpCode::F32x4__ne, "f32x4.ne"},
    {OpCode::F32x4__lt, "f32x4.lt"},
    {OpCode::F32x4__gt, "f32x4.gt"},
    {OpCode::F32x4__le, "f32x4.le"},
    {OpCode::F32x4__ge, "f32x4.ge"},

    {OpCode::F64x2__eq, "f64x2.eq"},
    {OpCode::F64x2__ne, "f64x2.ne"},
    {OpCode::F64x2__lt, "f64x2.lt"},
    {OpCode::F64x2__gt, "f64x2.gt"},
    {OpCode::F64x2__le, "f64x2.le"},
    {OpCode::F64x2__ge, "f64x2.ge"},

    {OpCode::V128__not, "v128.not"},
    {OpCode::V128__and, "v128.and"},
    {OpCode::V128__andnot, "v128.andnot"},
    {OpCode::V128__or, "v128.or"},
    {OpCode::V128__xor, "v128.xor"},
    {OpCode::V128__bitselect, "v128.bitselect"},
    {OpCode::V128__any_true, "v128.any_true"},

    {OpCode::I8x16__abs, "i8x16.abs"},
    {OpCode::I8x16__neg, "i8x16.neg"},
    {OpCode::I8x16__popcnt, "i8x16.popcnt"},
    {OpCode::I8x16__all_true, "i8x16.all_true"},
    {OpCode::I8x16__bitmask, "i8x16.bitmask"},
    {OpCode::I8x16__narrow_i16x8_s, "i8x16.narrow_i16x8_s"},
    {OpCode::I8x16__narrow_i16x8_u, "i8x16.narrow_i16x8_u"},
    {OpCode::I8x16__shl, "i8x16.shl"},
    {OpCode::I8x16__shr_s, "i8x16.shr_s"},
    {OpCode::I8x16__shr_u, "i8x16.shr_u"},
    {OpCode::I8x16__add, "i8x16.add"},
    {OpCode::I8x16__add_sat_s, "i8x16.add_sat_s"},
    {OpCode::I8x16__add_sat_u, "i8x16.add_sat_u"},
    {OpCode::I8x16__sub, "i8x16.sub"},
    {OpCode::I8x16__sub_sat_s, "i8x16.sub_sat_s"},
    {OpCode::I8x16__sub_sat_u, "i8x16.sub_sat_u"},
    {OpCode::I8x16__min_s, "i8x16.min_s"},
    {OpCode::I8x16__min_u, "i8x16.min_u"},
    {OpCode::I8x16__max_s, "i8x16.max_s"},
    {OpCode::I8x16__max_u, "i8x16.max_u"},
    {OpCode::I8x16__avgr_u, "i8x16.avgr_u"},

    {OpCode::I16x8__abs, "i16x8.abs"},
    {OpCode::I16x8__neg, "i16x8.neg"},
    {OpCode::I16x8__all_true, "i16x8.all_true"},
    {OpCode::I16x8__bitmask, "i16x8.bitmask"},
    {OpCode::I16x8__narrow_i32x4_s, "i16x8.narrow_i32x4_s"},
    {OpCode::I16x8__narrow_i32x4_u, "i16x8.narrow_i32x4_u"},
    {OpCode::I16x8__extend_low_i8x16_s, "i16x8.extend_low_i8x16_s"},
    {OpCode::I16x8__extend_high_i8x16_s, "i16x8.extend_high_i8x16_s"},
    {OpCode::I16x8__extend_low_i8x16_u, "i16x8.extend_low_i8x16_u"},
    {OpCode::I16x8__extend_high_i8x16_u, "i16x8.extend_high_i8x16_u"},
    {OpCode::I16x8__shl, "i16x8.shl"},
    {OpCode::I16x8__shr_s, "i16x8.shr_s"},
    {OpCode::I16x8__shr_u, "i16x8.shr_u"},
    {OpCode::I16x8__add, "i16x8.add"},
    {OpCode::I16x8__add_sat_s, "i16x8.add_sat_s"},
    {OpCode::I16x8__add_sat_u, "i16x8.add_sat_u"},
    {OpCode::I16x8__sub, "i16x8.sub"},
    {OpCode::I16x8__sub_sat_s, "i16x8.sub_sat_s"},
    {OpCode::I16x8__sub_sat_u, "i16x8.sub_sat_u"},
    {OpCode::I16x8__mul, "i16x8.mul"},
    {OpCode::I16x8__min_s, "i16x8.min_s"},
    {OpCode::I16x8__min_u, "i16x8.min_u"},
    {OpCode::I16x8__max_s, "i16x8.max_s"},
    {OpCode::I16x8__max_u, "i16x8.max_u"},
    {OpCode::I16x8__avgr_u, "i16x8.avgr_u"},
    {OpCode::I16x8__extmul_low_i8x16_s, "i16x8.extmul_low_i8x16_s"},
    {OpCode::I16x8__extmul_high_i8x16_s, "i16x8.extmul_high_i8x16_s"},
    {OpCode::I16x8__extmul_low_i8x16_u, "i16x8.extmul_low_i8x16_u"},
    {OpCode::I16x8__extmul_high_i8x16_u, "i16x8.extmul_high_i8x16_u"},
    {OpCode::I16x8__q15mulr_sat_s, "i16x8.q15mulr_sat_s"},
    {OpCode::I16x8__extadd_pairwise_i8x16_s, "i16x8.extadd_pairwise_i8x16_s"},
    {OpCode::I16x8__extadd_pairwise_i8x16_u, "i16x8.extadd_pairwise_i8x16_u"},

    {OpCode::I32x4__abs, "i32x4.abs"},
    {OpCode::I32x4__neg, "i32x4.neg"},
    {OpCode::I32x4__all_true, "i32x4.all_true"},
    {OpCode::I32x4__bitmask, "i32x4.bitmask"},
    {OpCode::I32x4__extend_low_i16x8_s, "i32x4.extend_low_i16x8_s"},
    {OpCode::I32x4__extend_high_i16x8_s, "i32x4.extend_high_i16x8_s"},
    {OpCode::I32x4__extend_low_i16x8_u, "i32x4.extend_low_i16x8_u"},
    {OpCode::I32x4__extend_high_i16x8_u, "i32x4.extend_high_i16x8_u"},
    {OpCode::I32x4__shl, "i32x4.shl"},
    {OpCode::I32x4__shr_s, "i32x4.shr_s"},
    {OpCode::I32x4__shr_u, "i32x4.shr_u"},
    {OpCode::I32x4__add, "i32x4.add"},
    {OpCode::I32x4__sub, "i32x4.sub"},
    {OpCode::I32x4__mul, "i32x4.mul"},
    {OpCode::I32x4__min_s, "i32x4.min_s"},
    {OpCode::I32x4__min_u, "i32x4.min_u"},
    {OpCode::I32x4__max_s, "i32x4.max_s"},
    {OpCode::I32x4__max_u, "i32x4.max_u"},
    {OpCode::I32x4__dot_i16x8_s, "i32x4.dot_i16x8_s"},
    {OpCode::I32x4__extmul_low_i16x8_s, "i32x4.extmul_low_i16x8_s"},
    {OpCode::I32x4__extmul_high_i16x8_s, "i32x4.extmul_high_i16x8_s"},
    {OpCode::I32x4__extmul_low_i16x8_u, "i32x4.extmul_low_i16x8_u"},
    {OpCode::I32x4__extmul_high_i16x8_u, "i32x4.extmul_high_i16x8_u"},
    {OpCode::I32x4__extadd_pairwise_i16x8_s, "i32x4.extadd_pairwise_i16x8_s"},
    {OpCode::I32x4__extadd_pairwise_i16x8_u, "i32x4.extadd_pairwise_i16x8_u"},

    {OpCode::I64x2__abs, "i64x2.abs"},
    {OpCode::I64x2__neg, "i64x2.neg"},
    {OpCode::I64x2__all_true, "i64x2.all_true"},
    {OpCode::I64x2__bitmask, "i64x2.bitmask"},
    {OpCode::I64x2__extend_low_i32x4_s, "i64x2.extend_low_i32x4_s"},
    {OpCode::I64x2__extend_high_i32x4_s, "i64x2.extend_high_i32x4_s"},
    {OpCode::I64x2__extend_low_i32x4_u, "i64x2.extend_low_i32x4_u"},
    {OpCode::I64x2__extend_high_i32x4_u, "i64x2.extend_high_i32x4_u"},
    {OpCode::I64x2__shl, "i64x2.shl"},
    {OpCode::I64x2__shr_s, "i64x2.shr_s"},
    {OpCode::I64x2__shr_u, "i64x2.shr_u"},
    {OpCode::I64x2__add, "i64x2.add"},
    {OpCode::I64x2__sub, "i64x2.sub"},
    {OpCode::I64x2__mul, "i64x2.mul"},
    {OpCode::I64x2__extmul_low_i32x4_s, "i64x2.extmul_low_i32x4_s"},
    {OpCode::I64x2__extmul_high_i32x4_s, "i64x2.extmul_high_i32x4_s"},
    {OpCode::I64x2__extmul_low_i32x4_u, "i64x2.extmul_low_i32x4_u"},
    {OpCode::I64x2__extmul_high_i32x4_u, "i64x2.extmul_high_i32x4_u"},

    {OpCode::F32x4__abs, "f32x4.abs"},
    {OpCode::F32x4__neg, "f32x4.neg"},
    {OpCode::F32x4__sqrt, "f32x4.sqrt"},
    {OpCode::F32x4__add, "f32x4.add"},
    {OpCode::F32x4__sub, "f32x4.sub"},
    {OpCode::F32x4__mul, "f32x4.mul"},
    {OpCode::F32x4__div, "f32x4.div"},
    {OpCode::F32x4__min, "f32x4.min"},
    {OpCode::F32x4__max, "f32x4.max"},
    {OpCode::F32x4__pmin, "f32x4.pmin"},
    {OpCode::F32x4__pmax, "f32x4.pmax"},
    {OpCode::F32x4__ceil, "f32x4.ceil"},
    {OpCode::F32x4__floor, "f32x4.floor"},
    {OpCode::F32x4__trunc, "f32x4.trunc"},
    {OpCode::F32x4__nearest, "f32x4.nearest"},

    {OpCode::F64x2__abs, "f64x2.abs"},
    {OpCode::F64x2__neg, "f64x2.neg"},
    {OpCode::F64x2__sqrt, "f64x2.sqrt"},
    {OpCode::F64x2__add, "f64x2.add"},
    {OpCode::F64x2__sub, "f64x2.sub"},
    {OpCode::F64x2__mul, "f64x2.mul"},
    {OpCode::F64x2__div, "f64x2.div"},
    {OpCode::F64x2__min, "f64x2.min"},
    {OpCode::F64x2__max, "f64x2.max"},
    {OpCode::F64x2__pmin, "f64x2.pmin"},
    {OpCode::F64x2__pmax, "f64x2.pmax"},
    {OpCode::F64x2__ceil, "f64x2.ceil"},
    {OpCode::F64x2__floor, "f64x2.floor"},
    {OpCode::F64x2__trunc, "f64x2.trunc"},
    {OpCode::F64x2__nearest, "f64x2.nearest"},

    {OpCode::I32x4__trunc_sat_f32x4_s, "i32x4.trunc_sat_f32x4_s"},
    {OpCode::I32x4__trunc_sat_f32x4_u, "i32x4.trunc_sat_f32x4_u"},
    {OpCode::F32x4__convert_i32x4_s, "f32x4.convert_i32x4_s"},
    {OpCode::F32x4__convert_i32x4_u, "f32x4.convert_i32x4_u"},
    {OpCode::I32x4__trunc_sat_f64x2_s_zero, "i32x4.trunc_sat_f64x2_s_zero"},
    {OpCode::I32x4__trunc_sat_f64x2_u_zero, "i32x4.trunc_sat_f64x2_u_zero"},
    {OpCode::F64x2__convert_low_i32x4_s, "f64x2.convert_low_i32x4_s"},
    {OpCode::F64x2__convert_low_i32x4_u, "f64x2.convert_low_i32x4_u"},
    {OpCode::F32x4__demote_f64x2_zero, "f32x4.demote_f64x2_zero"},
    {OpCode::F64x2__promote_low_f32x4, "f64x2.promote_low_f32x4"}};

} // namespace WasmEdge

#endif /// WASMEDGE_C_API_ENUM_AST_H
