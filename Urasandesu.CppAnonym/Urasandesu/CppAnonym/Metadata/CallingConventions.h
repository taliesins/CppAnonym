#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_CALLINGCONVENTIONS_H
#define URASANDESU_CPPANONYM_METADATA_CALLINGCONVENTIONS_H

#ifndef URASANDESU_CPPANONYM_SAFEENUM_H
#include <Urasandesu/CppAnonym/SafeEnum.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    namespace Detail {

        struct CallingConventionsDef
        {
            enum type
            {
                CC_STANDARD, 
                CC_VAR_ARGS, 
                CC_ANY, 
                CC_HAS_THIS, 
                CC_EXPLICIT_THIS, 
                CC_UNREACHED
            };
        };

    }   // Detail

    typedef SafeEnum<Detail::CallingConventionsDef> CallingConventions;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_CALLINGCONVENTIONS_H