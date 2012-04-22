#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_OPCODESPROTOB8DF5A21_H
#define URASANDESU_CPPANONYM_METADATA_OPCODEPROTOB8DF5A21_H

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    struct OpCodesProtoB8DF5A21
    {
#define OPDEF_EX(canonicalName, canonicalNameEx) \
        static Detail::OpCode_<OpCodeTypes::canonicalName> canonicalNameEx;
#include <Urasandesu/CppAnonym/Metadata/OpCodeEx.def>
#undef OPDEF_EX
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_OPCODEPROTOB8DF5A21_H