// SPDX-License-Identifier: Apache-2.0
#include "vm/hostfunc/ethereum/callDelegate.h"

namespace SSVM {
namespace Executor {

ErrCode EEICallDelegate::body(VM::EnvironmentManager &EnvMgr,
                              Instance::MemoryInstance &MemInst, uint32_t &Ret,
                              uint64_t Gas, uint32_t AddressOffset,
                              uint32_t DataOffset, uint32_t DataLength) {
  /// Prepare call message.
  evmc_address Addr;
  if (ErrCode Status = loadAddress(MemInst, Addr, AddressOffset);
      Status != ErrCode::Success) {
    return Status;
  }
  evmc_message CallMsg = {
      .kind = evmc_call_kind::EVMC_DELEGATECALL,
      .flags = Env.getFlag() & evmc_flags::EVMC_STATIC,
      .depth = static_cast<int32_t>(Env.getDepth() + 1),
      .gas = static_cast<int64_t>(std::min(Gas, getMaxCallGas())),
      .destination = Addr,
      .sender = Env.getAddressEVMC(),
      .input_data = nullptr,
      .input_size = 0,
      .value = Env.getCallValueEVMC()};

  /// Return: Result(i32)
  return callContract(EnvMgr, MemInst, Ret, CallMsg, DataOffset, DataLength);
}

} // namespace Executor
} // namespace SSVM
