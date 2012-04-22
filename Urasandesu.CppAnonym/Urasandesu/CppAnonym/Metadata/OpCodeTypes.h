#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_OPCODETYPES_H
#define URASANDESU_CPPANONYM_METADATA_OPCODETYPES_H

#ifndef URASANDESU_CPPANONYM_SAFEENUMFWD_HPP
#include <Urasandesu/CppAnonym/SafeEnumFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    namespace Detail {

        struct OpCodeTypesDef
        {
            enum type
            {
#define OPDEF(canonicalName, stringName, stackBehaviour0, stackBehaviour1, \
                operandParams, opcodeKind, length, byte1, byte2, controlFlow) \
                canonicalName,
#include "opcode.def"
#undef OPDEF
                CEE_UNREACHED
            };
        };

    }   // Detail

    typedef SafeEnum<Detail::OpCodeTypesDef> OpCodeTypes;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_OPCODETYPES_H