#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMODULENAMEMETADATAAPIHOLDER_H
#define URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMODULENAMEMETADATAAPIHOLDER_H

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_ASSEMBLYMETADATALABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/AssemblyMetadataLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYMETADATAFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseAssemblyMetadataFwd.hpp>
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

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_TYPENAMEMETADATALABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/TypeNameMetadataLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASETYPENAMEMETADATAFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseTypeNameMetadataFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMODULENAMEMETADATAAPIHOLDERFWD_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultModuleNameMetadataApiHolderFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

    namespace Detail {
        
        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Metadata::Interfaces;

        struct DefaultModuleNameMetadataApiHolderImpl
        {
            typedef map<
                pair<AssemblyMetadataLabel, AssemblyMetadata>, 
                pair<AssemblyNameMetadataLabel, AssemblyNameMetadata>, 
                pair<AssemblyNameMetadataHashLabel, AssemblyNameMetadataHash>, 
                pair<AssemblyNameMetadataEqualToLabel, AssemblyNameMetadataEqualTo>, 
                pair<ModuleMetadataLabel, ModuleMetadata>, 
                pair<TypeNameMetadataLabel, TypeNameMetadata>, 
                pair<IMetaDataImport2, IMetaDataImport2> 
            > api_cartridges;
        };

    }   // namespace Detail {

    struct DefaultModuleNameMetadataApiHolder : 
        Detail::DefaultModuleNameMetadataApiHolderImpl
    {
    };

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMODULENAMEMETADATAAPIHOLDER_H