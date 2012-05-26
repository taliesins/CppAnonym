#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_OPCODES_H
#define URASANDESU_CPPANONYM_METADATA_OPCODES_H

#ifndef URASANDESU_CPPANONYM_METADATA_OPCODE_H
#include <Urasandesu/CppAnonym/Metadata/OpCode.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    class OpCodes
    {
    public:
#define OPDEF_EX(canonicalName, canonicalNameEx) \
        static const Detail::OpCode_<OpCodeTypes::canonicalName> canonicalNameEx;
#include <Urasandesu/CppAnonym/Metadata/OpCodeEx.def>
#undef OPDEF_EX
    private:
        OpCodes() { }
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_OPCODES_H