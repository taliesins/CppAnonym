#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTASSEMBLYMETADATAAPIHOLDER_H
#define URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTASSEMBLYMETADATAAPIHOLDER_H

#ifndef URASANDESU_CPPANONYM_FUSION_INTERFACES_ASSEMBLYINFOLABEL_HPP
#include <Urasandesu/CppAnonym/Fusion/Interfaces/AssemblyInfoLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_FUSION_BASEASSEMBLYINFOFWD_HPP
#include <Urasandesu/CppAnonym/Fusion/BaseAssemblyInfoFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTASSEMBLYMETADATAAPIHOLDERFWD_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultAssemblyMetadataApiHolderFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

    namespace Detail {
        
        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Metadata::Interfaces;
        using namespace Urasandesu::CppAnonym::Fusion::Interfaces;
        using namespace Urasandesu::CppAnonym::Fusion;

        struct DefaultAssemblyMetadataApiHolderImpl
        {
            typedef map<
                pair<IAssemblyMetadataLabel, IAssemblyMetadata>,
                pair<MetadataDispenserLabel, MetadataDispenser>,
                pair<FusionInfoLabel, FusionInfo>,
                pair<AssemblyInfoLabel, AssemblyInfo>,
                pair<IMetaDataAssemblyImport, IMetaDataAssemblyImport>,
                pair<IMetaDataImport2, IMetaDataImport2>,
                pair<IMetaDataDispenserEx, IMetaDataDispenserEx>,
                pair<ModuleMetadataLabel, ModuleMetadata>,
                pair<IModuleMetadataHashLabel, IModuleMetadataHash>,
                pair<IModuleMetadataEqualToLabel, IModuleMetadataEqualTo>,
                pair<TypeMetadataLabel, TypeMetadata>,
                pair<MethodMetadataLabel, MethodMetadata>
            > api_cartridges;
        };

    }   // namespace Detail {
    
    struct DefaultAssemblyMetadataApiHolder : 
        Detail::DefaultAssemblyMetadataApiHolderImpl
    {
    };

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTASSEMBLYMETADATAAPIHOLDER_H