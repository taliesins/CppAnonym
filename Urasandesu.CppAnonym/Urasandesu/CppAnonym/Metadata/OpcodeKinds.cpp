
#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_METADATA_OPCODEKIND_H
#include <Urasandesu/CppAnonym/Metadata/OpcodeKind.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_OPCODEKINDS_H
#include <Urasandesu/CppAnonym/Metadata/OpcodeKinds.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    const OpcodeKind OpcodeKinds::IInternal = OpcodeKind(OpcodeKindTypes::OKT_I_INTERNAL);
    const OpcodeKind OpcodeKinds::IMacro = OpcodeKind(OpcodeKindTypes::OKT_I_MACRO);
    const OpcodeKind OpcodeKinds::IObjModel = OpcodeKind(OpcodeKindTypes::OKT_I_OBJ_MODEL);
    const OpcodeKind OpcodeKinds::IPrefix = OpcodeKind(OpcodeKindTypes::OKT_I_PREFIX);
    const OpcodeKind OpcodeKinds::IPrimitive = OpcodeKind(OpcodeKindTypes::OKT_I_PRIMITIVE);

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {
