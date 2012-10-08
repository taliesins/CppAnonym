#pragma once
#ifndef URASANDESU_CPPANONYM_FUSION_ASSEMBLYQUERYTYPES_H
#define URASANDESU_CPPANONYM_FUSION_ASSEMBLYQUERYTYPES_H

#ifndef URASANDESU_CPPANONYM_SAFEENUM_HPP
#include <Urasandesu/CppAnonym/SafeEnum.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Fusion {

    namespace AssemblyQueryTypesDetail {

        struct AssemblyQueryTypesDef
        {
            enum type
            {
                AQT_DEFAULT = 0,
                AQT_VALIDATE = QUERYASMINFO_FLAG_VALIDATE, 
                AQT_GET_SIZE = QUERYASMINFO_FLAG_GETSIZE,
                AQT_UNREACHED
            };
        };

    }   // AssemblyQueryTypesDetail

    typedef SafeEnum<AssemblyQueryTypesDetail::AssemblyQueryTypesDef> AssemblyQueryTypes;

}}}  // namespace Urasandesu { namespace CppAnonym { namespace Fusion {

#endif  // URASANDESU_CPPANONYM_FUSION_ASSEMBLYQUERYTYPES_H