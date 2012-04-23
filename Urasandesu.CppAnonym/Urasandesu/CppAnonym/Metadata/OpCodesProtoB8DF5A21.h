#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_OPCODESPROTOB8DF5A21_H
#define URASANDESU_CPPANONYM_METADATA_OPCODESPROTOB8DF5A21_H

#ifndef URASANDESU_CPPANONYM_METADATA_OPCODEPROTOB8DF5A21_H
#include <Urasandesu/CppAnonym/Metadata/OpCodeProtoB8DF5A21.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    class OpCodesProtoB8DF5A21
    {
    public:
#define OPDEF_EX(canonicalName, canonicalNameEx) \
        static const Detail::OpCode_<OpCodeTypes::canonicalName> canonicalNameEx;
#include <Urasandesu/CppAnonym/Metadata/OpCodeEx.def>
#undef OPDEF_EX
    private:
        OpCodesProtoB8DF5A21() { }
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_OPCODESPROTOB8DF5A21_H