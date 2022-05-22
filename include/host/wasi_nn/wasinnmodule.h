// SPDX-License-Identifier: Apache-2.0
// SPDX-FileCopyrightText: 2019-2022 Second State INC

#pragma once

#include "host/wasi_nn/wasinnenv.h"
#include "runtime/instance/module.h"

namespace WasmEdge {
namespace Host {

class WasiNNModule : public Runtime::Instance::ModuleInstance {
public:
  WasiNNModule();

private:
  WASINN::WasiNNEnvironment Env;
};

} // namespace Host
} // namespace WasmEdge
