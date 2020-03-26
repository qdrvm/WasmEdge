// SPDX-License-Identifier: Apache-2.0
#include "common/ast/section.h"
#include "runtime/instance/module.h"
#include "runtime/instance/table.h"
#include "interpreter/interpreter.h"

namespace SSVM {
namespace Interpreter {

/// Instantiate table instance. See "include/interpreter/interpreter.h".
Expect<void>
Interpreter::instantiate(Runtime::StoreManager &StoreMgr,
                         Runtime::Instance::ModuleInstance &ModInst,
                         const AST::TableSection &TabSec) {
  /// Iterate and instantiate table types.
  for (const auto &TabType : TabSec.getContent()) {
    /// Make a new table instance.
    auto NewTabInst = std::make_unique<Runtime::Instance::TableInstance>(
        TabType->getElementType(), *TabType->getLimit());

    /// Insert table instance to store manager.
    uint32_t NewTabInstAddr;
    if (InsMode == InstantiateMode::Instantiate) {
      NewTabInstAddr = StoreMgr.pushTable(NewTabInst);
    } else {
      NewTabInstAddr = StoreMgr.importTable(NewTabInst);
    }
    ModInst.addTableAddr(NewTabInstAddr);
  }
  return {};
}

} // namespace Interpreter
} // namespace SSVM
