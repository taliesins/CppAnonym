#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_IMAGEFILEMACHINE_HPP
#define URASANDESU_CPPANONYM_METADATA_IMAGEFILEMACHINE_HPP

#ifndef URASANDESU_CPPANONYM_SAFEENUM_HPP
#include <Urasandesu/CppAnonym/SafeEnum.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    namespace Detail {

        struct ImageFileMachineDef
        {
            enum type
            {
                IFM_I386, 
                IFM_IA64, 
                IFM_AMD64, 
                IFM_UNREACHED
            };
        };

    }   // Detail

    typedef SafeEnum<Detail::ImageFileMachineDef> ImageFileMachine;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_IMAGEFILEMACHINE_HPP