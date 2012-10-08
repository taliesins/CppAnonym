#pragma once
#ifndef URASANDESU_CPPANONYM_FUSION_APIHOLDERS_DEFAULTFUSIONINFOAPIHOLDER_H
#define URASANDESU_CPPANONYM_FUSION_APIHOLDERS_DEFAULTFUSIONINFOAPIHOLDER_H

#ifndef URASANDESU_CPPANONYM_HOSTING_INTERFACES_RUNTIMEHOSTLABEL_HPP
#include <Urasandesu/CppAnonym/Hosting/Interfaces/RuntimeHostLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_HOSTING_BASERUNTIMEHOSTFWD_HPP
#include <Urasandesu/CppAnonym/Hosting/BaseRuntimeHostFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_FUSION_INTERFACES_ASSEMBLYINFOLABEL_HPP
#include <Urasandesu/CppAnonym/Fusion/Interfaces/AssemblyInfoLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_FUSION_BASEASSEMBLYINFOFWD_HPP
#include <Urasandesu/CppAnonym/Fusion/BaseAssemblyInfoFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_FUSION_APIHOLDERS_DEFAULTFUSIONINFOAPIHOLDERFWD_H
#include <Urasandesu/CppAnonym/Fusion/ApiHolders/DefaultFusionInfoApiHolderFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Fusion { namespace ApiHolders {
    
    namespace Detail {
        
        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Hosting::Interfaces;
        using namespace Urasandesu::CppAnonym::Hosting;
        using namespace Urasandesu::CppAnonym::Fusion::Interfaces;

        struct DefaultFusionInfoApiHolderImpl
        {
            typedef map<
                pair<IAssemblyCache, IAssemblyCache>,
                pair<RuntimeHostLabel, RuntimeHost>,
                pair<FusionInfoLabel, FusionInfo>,
                pair<AssemblyInfoLabel, AssemblyInfo>
            > api_cartridges;
        };

    }   // namespace Detail {

    struct DefaultFusionInfoApiHolder : 
        Detail::DefaultFusionInfoApiHolderImpl
    {
    };
        
}}}}  // namespace Urasandesu { namespace CppAnonym { namespace Fusion { namespace ApiHolders {

#endif  // URASANDESU_CPPANONYM_FUSION_APIHOLDERS_DEFAULTFUSIONINFOAPIHOLDER_H