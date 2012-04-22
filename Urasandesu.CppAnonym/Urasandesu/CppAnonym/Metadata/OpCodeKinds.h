#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_OPCODEKINDS_H
#define URASANDESU_CPPANONYM_METADATA_OPCODEKINDS_H

#ifndef URASANDESU_CPPANONYM_METADATA_OPCODEKIND_H
#include <Urasandesu/CppAnonym/Metadata/OpCodeKind.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    struct OpCodeKinds
    {
        static const OpCodeKind IInternal;
        static const OpCodeKind IMacro;
        static const OpCodeKind IObjModel;
        static const OpCodeKind IPrefix;
        static const OpCodeKind IPrimitive;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_OPCODEKINDS_H