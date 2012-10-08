#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTASSEMBLYNAMEMETADATAAPIHOLDER_H
#define URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTASSEMBLYNAMEMETADATAAPIHOLDER_H

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_METADATADISPENSERLABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/MetadataDispenserLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATADISPENSERFWD_H
#include <Urasandesu/CppAnonym/Metadata/BaseMetadataDispenserFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_ASSEMBLYMETADATALABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/AssemblyMetadataLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYMETADATAFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseAssemblyMetadataFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_MODULENAMEMETADATALABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/ModuleNameMetadataLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMODULENAMEMETADATAFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseModuleNameMetadataFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_INTERFACES_STRONGNAMEINFOLABEL_HPP
#include <Urasandesu/CppAnonym/StrongNaming/Interfaces/StrongNameInfoLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_BASESTRONGNAMEINFOFWD_HPP
#include <Urasandesu/CppAnonym/StrongNaming/BaseStrongNameInfoFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_INTERFACES_STRONGNAMEKEYLABEL_HPP
#include <Urasandesu/CppAnonym/StrongNaming/Interfaces/StrongNameKeyLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_TYPENAMEMETADATALABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/TypeNameMetadataLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASETYPENAMEMETADATAFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseTypeNameMetadataFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_BASESTRONGNAMEKEYFWD_HPP
#include <Urasandesu/CppAnonym/StrongNaming/BaseStrongNameKeyFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_FUSION_INTERFACES_FUSIONINFOLABEL_HPP
#include <Urasandesu/CppAnonym/Fusion/Interfaces/FusionInfoLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_FUSION_BASEFUSIONINFOFWD_HPP
#include <Urasandesu/CppAnonym/Fusion/BaseFusionInfoFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTASSEMBLYNAMEMETADATAAPIHOLDERFWD_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultAssemblyNameMetadataApiHolderFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

    namespace Detail {
        
        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Metadata::Interfaces;
        using namespace Urasandesu::CppAnonym::StrongNaming;
        using namespace Urasandesu::CppAnonym::StrongNaming::Interfaces;
        using namespace Urasandesu::CppAnonym::Fusion;
        using namespace Urasandesu::CppAnonym::Fusion::Interfaces;


        struct DefaultAssemblyNameMetadataApiHolderImpl
        {
            typedef map<
                pair<MetadataDispenserLabel, MetadataDispenser>, 
                pair<AssemblyMetadataLabel, AssemblyMetadata>,
                pair<ModuleNameMetadataLabel, ModuleNameMetadata>, 
                pair<TypeNameMetadataLabel, TypeNameMetadata>, 
                pair<FusionInfoLabel, FusionInfo>, 
                pair<StrongNameKeyLabel, StrongNameKey>, 
                pair<StrongNameInfoLabel, StrongNameInfo>, 
                pair<IMetaDataAssemblyImport, IMetaDataAssemblyImport> 
            > api_cartridges;
        };

    }   // namespace Detail {

    struct DefaultAssemblyNameMetadataApiHolder : 
        Detail::DefaultAssemblyNameMetadataApiHolderImpl
    { 
    };

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTASSEMBLYNAMEMETADATAAPIHOLDER_H