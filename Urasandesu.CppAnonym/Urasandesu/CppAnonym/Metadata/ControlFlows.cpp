
#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_METADATA_CONTROLFLOW_H
#include <Urasandesu/CppAnonym/Metadata/ControlFlow.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_CONTROLFLOWS_H
#include <Urasandesu/CppAnonym/Metadata/ControlFlows.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    const ControlFlow ControlFlows::Branch = ControlFlow(ControlFlowTypes::CFT_BRANCH);
    const ControlFlow ControlFlows::Break = ControlFlow(ControlFlowTypes::CFT_BREAK);
    const ControlFlow ControlFlows::Call = ControlFlow(ControlFlowTypes::CFT_CALL);
    const ControlFlow ControlFlows::CondBranch = ControlFlow(ControlFlowTypes::CFT_COND_BRANCH);
    const ControlFlow ControlFlows::Meta = ControlFlow(ControlFlowTypes::CFT_META);
    const ControlFlow ControlFlows::Next = ControlFlow(ControlFlowTypes::CFT_NEXT);
    const ControlFlow ControlFlows::Return = ControlFlow(ControlFlowTypes::CFT_RETURN);
    const ControlFlow ControlFlows::Throw = ControlFlow(ControlFlowTypes::CFT_THROW);

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {
