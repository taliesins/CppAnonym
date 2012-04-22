#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_CONTROLFLOWS_H
#define URASANDESU_CPPANONYM_METADATA_CONTROLFLOWS_H

#ifndef URASANDESU_CPPANONYM_METADATA_CONTROLFLOW_H
#include <Urasandesu/CppAnonym/Metadata/ControlFlow.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    struct ControlFlows
    {
        static const ControlFlow Branch;
        static const ControlFlow Break;
        static const ControlFlow Call;
        static const ControlFlow CondBranch;
        static const ControlFlow Meta;
        static const ControlFlow Next;
        static const ControlFlow Return;
        static const ControlFlow Throw;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_CONTROLFLOWS_H