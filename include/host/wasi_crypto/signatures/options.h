// SPDX-License-Identifier: Apache-2.0
// SPDX-FileCopyrightText: 2019-2022 Second State INC

//===-- wasi_crypto/signatures/options.h - Signatures Options definition --===//
//
// Part of the WasmEdge Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the Signatures Options class definition of wasi-crypto
///
//===----------------------------------------------------------------------===//
#pragma once

#include "common/span.h"
#include "host/wasi_crypto/utils/error.h"

#include <string_view>

namespace WasmEdge {
namespace Host {
namespace WasiCrypto {
namespace Signatures {

class Options {
public:
  WasiCryptoExpect<void> set(std::string_view Name,
                             Span<const uint8_t> Value) noexcept;

  WasiCryptoExpect<void> setU64(std::string_view Name, uint64_t Value) noexcept;

  WasiCryptoExpect<void> setGuestBuffer(std::string_view Name,
                                        Span<uint8_t> Buffer) noexcept;

  WasiCryptoExpect<size_t> get(std::string_view Name,
                               Span<uint8_t> Value) const noexcept;

  WasiCryptoExpect<uint64_t> getU64(std::string_view Name) const noexcept;
};

} // namespace Signatures
} // namespace WasiCrypto
} // namespace Host
} // namespace WasmEdge
