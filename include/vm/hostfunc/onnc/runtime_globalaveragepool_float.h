// SPDX-License-Identifier: Apache-2.0
#pragma once

#include "onncwasm.h"

namespace SSVM {
namespace Executor {

class ONNCRuntimeGlobalaveragepoolFloat
    : public ONNCWasm<ONNCRuntimeGlobalaveragepoolFloat> {
public:
  ONNCRuntimeGlobalaveragepoolFloat()
      : ONNCWasm("ONNC_RUNTIME_globalaveragepool_float") {}
  ErrCode body(VM::EnvironmentManager &EnvMgr,
               Instance::MemoryInstance &MemInst, uint32_t RuntimeContextOff,
               uint32_t InXOff, uint32_t InXNDim, uint32_t InXDimsOff,
               uint32_t OutYOff, uint32_t OutYNDim, uint32_t OutYDimsOff);
};

} // namespace Executor
} // namespace SSVM
