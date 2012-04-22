
#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_METADATA_OPCODEPROTOB8DF5A21_H
#include <Urasandesu/CppAnonym/Metadata/OpCodeProtoB8DF5A21.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_OPCODESPROTOB8DF5A21_H
#include <Urasandesu/CppAnonym/Metadata/OpCodesProtoB8DF5A21.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#define OPDEF_EX(canonicalName, canonicalNameEx) \
    Detail::OpCode_<OpCodeTypes::canonicalName> OpCodesProtoB8DF5A21::canonicalNameEx = Detail::OpCode_<OpCodeTypes::canonicalName>();
#include <Urasandesu/CppAnonym/Metadata/OpCodeEx.def>
#undef OPDEF_EX

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {
