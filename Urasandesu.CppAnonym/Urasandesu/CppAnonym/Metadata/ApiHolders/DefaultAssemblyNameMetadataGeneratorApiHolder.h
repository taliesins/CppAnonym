#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTASSEMBLYNAMEMETADATAGENERATORAPIHOLDER_H
#define URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTASSEMBLYNAMEMETADATAGENERATORAPIHOLDER_H

//#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_METADATADISPENSERLABEL_HPP
//#include <Urasandesu/CppAnonym/Metadata/Interfaces/MetadataDispenserLabel.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATADISPENSERFWD_H
//#include <Urasandesu/CppAnonym/Metadata/BaseMetadataDispenserFwd.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_ASSEMBLYMETADATALABEL_HPP
//#include <Urasandesu/CppAnonym/Metadata/Interfaces/AssemblyMetadataLabel.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYMETADATAFWD_HPP
//#include <Urasandesu/CppAnonym/Metadata/BaseAssemblyMetadataFwd.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_MODULENAMEMETADATALABEL_HPP
//#include <Urasandesu/CppAnonym/Metadata/Interfaces/ModuleNameMetadataLabel.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_METADATA_BASEMODULENAMEMETADATAFWD_HPP
//#include <Urasandesu/CppAnonym/Metadata/BaseModuleNameMetadataFwd.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_STRONGNAMING_INTERFACES_STRONGNAMEINFOLABEL_HPP
//#include <Urasandesu/CppAnonym/StrongNaming/Interfaces/StrongNameInfoLabel.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_STRONGNAMING_BASESTRONGNAMEINFOFWD_HPP
//#include <Urasandesu/CppAnonym/StrongNaming/BaseStrongNameInfoFwd.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_STRONGNAMING_INTERFACES_STRONGNAMEKEYLABEL_HPP
//#include <Urasandesu/CppAnonym/StrongNaming/Interfaces/StrongNameKeyLabel.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_TYPENAMEMETADATALABEL_HPP
//#include <Urasandesu/CppAnonym/Metadata/Interfaces/TypeNameMetadataLabel.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_METADATA_BASETYPENAMEMETADATAFWD_HPP
//#include <Urasandesu/CppAnonym/Metadata/BaseTypeNameMetadataFwd.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_STRONGNAMING_BASESTRONGNAMEKEYFWD_HPP
//#include <Urasandesu/CppAnonym/StrongNaming/BaseStrongNameKeyFwd.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_FUSION_INTERFACES_FUSIONINFOLABEL_HPP
//#include <Urasandesu/CppAnonym/Fusion/Interfaces/FusionInfoLabel.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_FUSION_BASEFUSIONINFOFWD_HPP
//#include <Urasandesu/CppAnonym/Fusion/BaseFusionInfoFwd.hpp>
//#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_MODULENAMEMETADATAGENERATORLABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/ModuleNameMetadataGeneratorLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMODULENAMEMETADATAGENERATORFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseModuleNameMetadataGeneratorFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_INTERFACES_STRONGNAMEKEYLABEL_HPP
#include <Urasandesu/CppAnonym/StrongNaming/Interfaces/StrongNameKeyLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_BASESTRONGNAMEKEYFWD_HPP
#include <Urasandesu/CppAnonym/StrongNaming/BaseStrongNameKeyFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTASSEMBLYNAMEMETADATAGENERATORAPIHOLDERFWD_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultAssemblyNameMetadataGeneratorApiHolderFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

    namespace Detail {

        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Metadata::Interfaces;
        
        struct DefaultAssemblyNameMetadataGeneratorApiHolderImpl
        {
            //typedef map<
            //    pair<MetadataInfoLabel, MetadataInfo>, 
            //    pair<AssemblyNameMetadataLabel, AssemblyNameMetadata>, 
            //    pair<AssemblyMetadataLabel, AssemblyMetadata>, 
            //    pair<IMetaDataDispenserEx, IMetaDataDispenserEx>,
            //    pair<AssemblyNameMetadataGeneratorLabel, AssemblyNameMetadataGenerator> 
            //> api_cartridges;
            typedef map<
                pair<MetadataDispenserLabel, MetadataDispenser>,
                pair<AssemblyMetadataGeneratorLabel, AssemblyMetadataGenerator>,
                pair<ModuleNameMetadataGeneratorLabel, ModuleNameMetadataGenerator>,
                pair<StrongNameKeyLabel, StrongNameKey>
            > api_cartridges;
        };

    }   // namespace Detail {

    struct DefaultAssemblyNameMetadataGeneratorApiHolder : 
        Detail::DefaultAssemblyNameMetadataGeneratorApiHolderImpl
    {
    };

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTASSEMBLYNAMEMETADATAGENERATORAPIHOLDER_H