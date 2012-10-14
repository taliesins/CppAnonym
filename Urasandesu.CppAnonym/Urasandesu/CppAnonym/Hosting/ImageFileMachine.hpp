#pragma once
#ifndef URASANDESU_CPPANONYM_HOSTING_IMAGEFILEMACHINE_HPP
#define URASANDESU_CPPANONYM_HOSTING_IMAGEFILEMACHINE_HPP

#ifndef URASANDESU_CPPANONYM_SAFEENUM_H
#include <Urasandesu/CppAnonym/SafeEnum.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Hosting {

    namespace ImageFileMachineDetail {

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

    }   // namespace ImageFileMachineDetail {

    typedef SafeEnum<ImageFileMachineDetail::ImageFileMachineDef> ImageFileMachine;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting {

#endif  // #ifndef URASANDESU_CPPANONYM_HOSTING_IMAGEFILEMACHINE_HPP