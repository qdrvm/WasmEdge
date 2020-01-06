// SPDX-License-Identifier: Apache-2.0
#pragma once

#include "wasi.h"

namespace SSVM {
namespace Executor {

class WasiFdPrestatDirName : public Wasi {
public:
  WasiFdPrestatDirName(VM::WasiEnvironment &Env);

  ErrCode run(VM::EnvironmentManager &EnvMgr, StackManager &StackMgr,
              Instance::MemoryInstance &MemInst) override;

  ErrCode body(VM::EnvironmentManager &EnvMgr,
               Instance::MemoryInstance &MemInst, uint32_t &ErrNo, int32_t Fd,
               uint32_t PathBufPtr, uint32_t PathLen);
};

} // namespace Executor
} // namespace SSVM
