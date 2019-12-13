// SPDX-License-Identifier: Apache-2.0
#pragma once

#include "wasi.h"

namespace SSVM {
namespace Executor {

class WasiEnvironGet : public Wasi {
public:
  WasiEnvironGet(VM::WasiEnvironment &Env);
  WasiEnvironGet() = delete;
  virtual ~WasiEnvironGet() = default;

  virtual ErrCode run(VM::EnvironmentManager &EnvMgr, std::vector<Value> &Args,
                      std::vector<Value> &Res, StoreManager &Store,
                      Instance::ModuleInstance *ModInst);
};

} // namespace Executor
} // namespace SSVM
