// SPDX-License-Identifier: Apache-2.0
#include "vm/hostfunc/ethereum/callDelegate.h"

namespace SSVM {
namespace Executor {

ErrCode EEICallDelegate::body(VM::EnvironmentManager &EnvMgr,
                              Instance::MemoryInstance &MemInst, uint32_t &Ret,
                              uint64_t Gas, uint32_t AddressOffset,
                              uint32_t DataOffset, uint32_t DataLength) {
  /// TODO: Implement this function.
  Ret = 2;
  return ErrCode::Revert;
}

} // namespace Executor
} // namespace SSVM
