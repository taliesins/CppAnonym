
#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_METADATA_OPCODEKIND_H
#include <Urasandesu/CppAnonym/Metadata/OpCodeKind.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_OPCODEKINDS_H
#include <Urasandesu/CppAnonym/Metadata/OpCodeKinds.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    const OpCodeKind OpCodeKinds::IInternal = OpCodeKind(OpCodeKindTypes::OKT_I_INTERNAL);
    const OpCodeKind OpCodeKinds::IMacro = OpCodeKind(OpCodeKindTypes::OKT_I_MACRO);
    const OpCodeKind OpCodeKinds::IObjModel = OpCodeKind(OpCodeKindTypes::OKT_I_OBJ_MODEL);
    const OpCodeKind OpCodeKinds::IPrefix = OpCodeKind(OpCodeKindTypes::OKT_I_PREFIX);
    const OpCodeKind OpCodeKinds::IPrimitive = OpCodeKind(OpCodeKindTypes::OKT_I_PRIMITIVE);

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {
