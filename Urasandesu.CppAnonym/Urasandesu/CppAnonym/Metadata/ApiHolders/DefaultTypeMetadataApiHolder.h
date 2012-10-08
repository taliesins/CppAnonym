#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTTYPEMETADATAAPIHOLDER_H
#define URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTTYPEMETADATAAPIHOLDER_H

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_ASSEMBLYMETADATALABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/AssemblyMetadataLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYMETADATAFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseAssemblyMetadataFwd.hpp>
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

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_METHODMETADATALABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/MethodMetadataLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETHODMETADATAFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseMethodMetadataFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_METHODNAMEMETADATALABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/MethodNameMetadataLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETHODNAMEMETADATAFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseMethodNameMetadataFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

    namespace Detail {
        
        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Metadata::Interfaces;

        struct DefaultTypeMetadataApiHolderImpl
        {
            typedef map<
                pair<IMetaDataImport2, IMetaDataImport2>, 
                pair<AssemblyMetadataLabel, AssemblyMetadata>,
                pair<ModuleMetadataLabel, ModuleMetadata>, 
                pair<TypeNameMetadataLabel, TypeNameMetadata>, 
                pair<MethodNameMetadataLabel, MethodNameMetadata>, 
                pair<MethodNameMetadataHashLabel, MethodNameMetadataHash>, 
                pair<MethodNameMetadataEqualToLabel, MethodNameMetadataEqualTo>, 
                pair<MethodMetadataLabel, MethodMetadata> 
            > api_cartridges;
        };

    }   // namespace Detail {

    struct DefaultTypeMetadataApiHolder : 
        Detail::DefaultTypeMetadataApiHolderImpl
    {
    };

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTTYPEMETADATAAPIHOLDER_H