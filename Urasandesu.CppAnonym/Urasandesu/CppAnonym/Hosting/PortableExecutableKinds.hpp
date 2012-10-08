#pragma once
#ifndef URASANDESU_CPPANONYM_HOSTING_PORTABLEEXECUTABLEKINDS_HPP
#define URASANDESU_CPPANONYM_HOSTING_PORTABLEEXECUTABLEKINDS_HPP

#ifndef URASANDESU_CPPANONYM_SAFEENUM_HPP
#include <Urasandesu/CppAnonym/SafeEnum.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Hosting {

    namespace Detail {

        struct PortableExecutableKindsDef
        {
            enum type
            {
                PEK_NONE = 0,
                PEK_NOTA_PORTABLE_EXECUTABLE_IMAGE = 0x00000001, 
                PEK_IL_ONLY = 0x00000002, 
                PEK_REQUIRED32_BIT = 0x00000004, 
                PEK_PE32_PLUS = 0x00000008, 
                PEK_UNMANAGED32_BIT = 0x00000010, 
                PEK_UNREACHED
            };

            friend type operator |(type lhs, type rhs)
            {
                return static_cast<type>(+lhs | +rhs);
            }
        };

    }   // Detail

    typedef SafeEnum<Detail::PortableExecutableKindsDef> PortableExecutableKinds;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting {

#endif  // #ifndef URASANDESU_CPPANONYM_HOSTING_PORTABLEEXECUTABLEKINDS_HPP