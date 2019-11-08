#include "ast/instruction.h"
#include "executor/common.h"
#include "executor/instance/memory.h"
#include "executor/worker.h"
#include "executor/worker/util.h"
#include "support/casting.h"

#include <cstdint>
#include <type_traits>

namespace SSVM {
namespace Executor {

template <typename T>
TypeT<T, ErrCode> Worker::runLoadOp(AST::Instruction *Instr,
                                    unsigned int BitWidth) {
  /// Get Memory Instance
  ErrCode Status = ErrCode::Success;
  Instance::MemoryInstance *MemoryInst = nullptr;
  if ((Status = getMemInstByIdx(0, MemoryInst)) != ErrCode::Success) {
    return Status;
  };

  /// Calculate EA
  std::unique_ptr<ValueEntry> Val;
  StackMgr.pop(Val);
  uint32_t EA = retrieveValue<uint32_t>(*Val.get()) + Instr->getMemoryOffset();

  /// Value = Mem.Data[EA : N / 8]
  T Value;
  if ((Status = MemoryInst->loadValue(Value, EA, BitWidth / 8)) !=
      ErrCode::Success) {
    return Status;
  }
  return StackMgr.pushValue(Support::toUnsigned(Value));
}

template <typename T>
TypeB<T, ErrCode> Worker::runStoreOp(AST::Instruction *Instr,
                                     unsigned int BitWidth) {
  /// Get Memory Instance
  ErrCode Status = ErrCode::Success;
  Instance::MemoryInstance *MemoryInst = nullptr;
  if ((Status = getMemInstByIdx(0, MemoryInst)) != ErrCode::Success) {
    return Status;
  };

  /// Pop the value t.const c from the Stack
  std::unique_ptr<ValueEntry> C;
  StackMgr.pop(C);

  /// Calculate EA = i + offset
  std::unique_ptr<ValueEntry> I;
  StackMgr.pop(I);
  uint32_t EA = retrieveValue<uint32_t>(*I.get()) + Instr->getMemoryOffset();

  /// Store value to bytes.
  T Value = retrieveValue<T>(*C.get());
  if ((Status = MemoryInst->storeValue(Value, EA, BitWidth / 8)) !=
      ErrCode::Success) {
    return Status;
  };
  return ErrCode::Success;
}

} // namespace Executor
} // namespace SSVM
