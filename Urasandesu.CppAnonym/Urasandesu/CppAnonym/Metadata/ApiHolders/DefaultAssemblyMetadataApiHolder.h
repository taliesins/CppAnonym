#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTASSEMBLYMETADATAAPIHOLDER_H
#define URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTASSEMBLYMETADATAAPIHOLDER_H

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_METADATADISPENSERLABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/MetadataDispenserLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATADISPENSERFWD_H
#include <Urasandesu/CppAnonym/Metadata/BaseMetadataDispenserFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_ASSEMBLYNAMEMETADATALABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/AssemblyNameMetadataLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYNAMEMETADATAFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseAssemblyNameMetadataFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_MODULEMETADATALABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/ModuleMetadataLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMODULEMETADATAFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseModuleMetadataFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_MODULENAMEMETADATALABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/ModuleNameMetadataLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMODULENAMEMETADATAFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseModuleNameMetadataFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_TYPEMETADATALABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/TypeMetadataLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASETYPEMETADATAFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseTypeMetadataFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_TYPENAMEMETADATALABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/TypeNameMetadataLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASETYPENAMEMETADATAFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseTypeNameMetadataFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTASSEMBLYMETADATAAPIHOLDERFWD_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultAssemblyMetadataApiHolderFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

    namespace Detail {

        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Metadata::Interfaces;

        struct DefaultAssemblyMetadataApiHolderImpl
        {
            typedef map<
                pair<MetadataDispenserLabel, MetadataDispenser>, 
                pair<AssemblyNameMetadataLabel, AssemblyNameMetadata>,
                pair<ModuleMetadataLabel, ModuleMetadata>, 
                pair<ModuleNameMetadataLabel, ModuleNameMetadata>, 
                pair<TypeMetadataLabel, TypeMetadata>, 
                pair<TypeNameMetadataLabel, TypeNameMetadata>, 
                pair<IMetaDataDispenserEx, IMetaDataDispenserEx>, 
                pair<IMetaDataAssemblyImport, IMetaDataAssemblyImport>, 
                pair<IMetaDataImport2, IMetaDataImport2> 
            > api_cartridges;
        };

    }   // namespace Detail {

    struct DefaultAssemblyMetadataApiHolder : 
        Detail::DefaultAssemblyMetadataApiHolderImpl
    {
    };

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTASSEMBLYMETADATAAPIHOLDER_H