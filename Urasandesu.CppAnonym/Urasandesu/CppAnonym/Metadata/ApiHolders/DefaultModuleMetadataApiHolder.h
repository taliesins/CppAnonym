#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMODULEMETADATAAPIHOLDER_H
#define URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMODULEMETADATAAPIHOLDER_H

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

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_TYPENAMEMETADATALABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/TypeNameMetadataLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASETYPENAMEMETADATAFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseTypeNameMetadataFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_TYPEMETADATALABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/TypeMetadataLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASETYPEMETADATAFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseTypeMetadataFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMODULEMETADATAAPIHOLDERFWD_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultModuleMetadataApiHolderFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

    namespace Detail {
        
        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Metadata::Interfaces;

        struct DefaultModuleMetadataApiHolderImpl
        {
            typedef map<
                pair<AssemblyMetadataLabel, AssemblyMetadata>,
                pair<ModuleNameMetadataLabel, ModuleNameMetadata>,
                pair<TypeNameMetadataLabel, TypeNameMetadata>,
                pair<TypeMetadataLabel, TypeMetadata>,
                pair<IMetaDataImport2, IMetaDataImport2>
            > api_cartridges;
        };

    }   // namespace Detail {

    struct DefaultModuleMetadataApiHolder : 
        Detail::DefaultModuleMetadataApiHolderImpl
    {
    };

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMODULEMETADATAAPIHOLDER_H