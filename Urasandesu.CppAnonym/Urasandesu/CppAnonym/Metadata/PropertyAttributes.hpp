#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_PROPERTYATTRIBUTES_HPP
#define URASANDESU_CPPANONYM_METADATA_PROPERTYATTRIBUTES_HPP

#ifndef URASANDESU_CPPANONYM_SAFEENUM_HPP
#include <Urasandesu/CppAnonym/SafeEnum.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    namespace Detail {

        struct PropertyAttributesDef
        {
            enum type
            {
                PA_NONE = 0,
                PA_SPECIAL_NAME = prSpecialName, 
                PA_RESERVED_MASK = prReservedMask, 
                PA_RT_SPECIAL_NAME = prRTSpecialName, 
                PA_HAS_DEFAULT = prHasDefault, 
                PA_UNUSED = prUnused, 
                PA_UNREACHED
            };

            friend type operator |(type lhs, type rhs)
            {
                return static_cast<type>(+lhs | +rhs);
            }
        };

    }   // Detail

    typedef SafeEnum<Detail::PropertyAttributesDef> PropertyAttributes;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_PROPERTYATTRIBUTES_HPP