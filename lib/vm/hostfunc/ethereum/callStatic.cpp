// SPDX-License-Identifier: Apache-2.0
#include "vm/hostfunc/ethereum/callStatic.h"
#include "keccak/Keccak.h"
#include "support/hexstr.h"
#include <boost/multiprecision/cpp_int.hpp>

namespace SSVM {
namespace Executor {

ErrCode EEICallStatic::body(VM::EnvironmentManager &EnvMgr,
                            Instance::MemoryInstance &MemInst, uint32_t &Ret,
                            uint64_t Gas, uint32_t AddressOffset,
                            uint32_t DataOffset, uint32_t DataLength) {
  /// TODO: Add additional gas cost.
  std::vector<unsigned char> Address;
  std::vector<unsigned char> Data;
  if (ErrCode Status = MemInst.getBytes(Address, AddressOffset, 20);
      Status != ErrCode::Success) {
    return Status;
  }
  if (ErrCode Status = MemInst.getBytes(Data, DataOffset, DataLength);
      Status != ErrCode::Success) {
    return Status;
  }

  boost::multiprecision::uint256_t AddressNum = 0;
  for (auto It = Address.cbegin(); It != Address.cend(); It++) {
    AddressNum <<= 8;
    AddressNum += *It;
  }

  Ret = 1U;
  if (AddressNum == 9) {
    /// Run Keccak
    Keccak K(256);
    for (auto It = Data.cbegin(); It != Data.cend(); It++) {
      K.addData(*It);
    }
    std::vector<unsigned char> &ReturnData = Env.getReturnData();
    ReturnData = K.digest();
    Ret = 0U;
  }

  return ErrCode::Success;
}

} // namespace Executor
} // namespace SSVM
