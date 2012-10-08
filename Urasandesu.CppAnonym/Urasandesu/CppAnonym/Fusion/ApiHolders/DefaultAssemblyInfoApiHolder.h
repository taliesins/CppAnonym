#pragma once
#ifndef URASANDESU_CPPANONYM_FUSION_APIHOLDERS_DEFAULTASSEMBLYINFOAPIHOLDER_H
#define URASANDESU_CPPANONYM_FUSION_APIHOLDERS_DEFAULTASSEMBLYINFOAPIHOLDER_H

#ifndef URASANDESU_CPPANONYM_FUSION_APIHOLDERS_DEFAULTASSEMBLYINFOAPIHOLDERFWD_H
#include <Urasandesu/CppAnonym/Fusion/ApiHolders/DefaultAssemblyInfoApiHolderFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Fusion { namespace ApiHolders {
    
    namespace Detail {
        
        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Fusion::Interfaces;

        struct DefaultAssemblyInfoApiHolderImpl
        {
            typedef map<
                pair<FusionInfoLabel, FusionInfo>
            > api_cartridges;
        };

    }   // namespace Detail {

    struct DefaultAssemblyInfoApiHolder : 
        Detail::DefaultAssemblyInfoApiHolderImpl
    {
    };
        
}}}}  // namespace Urasandesu { namespace CppAnonym { namespace Fusion { namespace ApiHolders {

#endif  // URASANDESU_CPPANONYM_FUSION_APIHOLDERS_DEFAULTASSEMBLYINFOAPIHOLDER_H