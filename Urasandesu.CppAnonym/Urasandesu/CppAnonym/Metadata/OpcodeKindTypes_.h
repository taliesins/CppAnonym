#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_OPCODEKINDTYPES_H
#define URASANDESU_CPPANONYM_METADATA_OPCODEKINDTYPES_H

#ifndef URASANDESU_CPPANONYM_SAFEENUMFWD_HPP
#include <Urasandesu/CppAnonym/SafeEnumFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    namespace Detail {

        struct OpCodeKindTypesDef
        {
            enum type
            {
                OKT_I_INTERNAL, 
                OKT_I_MACRO, 
                OKT_I_OBJ_MODEL, 
                OKT_I_PREFIX, 
                OKT_I_PRIMITIVE, 
                OKT_UNREACHED
            };
        };

    }   // Detail

    typedef SafeEnum<Detail::OpCodeKindTypesDef> OpCodeKindTypes;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_OPCODEKINDTYPES_H