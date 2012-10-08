﻿#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTTYPEMETADATAAPIHOLDER_H
#define URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTTYPEMETADATAAPIHOLDER_H

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_IMETHODMETADATALABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/IMethodMetadataLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEIMETHODMETADATAFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseIMethodMetadataFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTTYPEMETADATAAPIHOLDERFWD_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultTypeMetadataApiHolderFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

    namespace DefaultTypeMetadataApiHolderDetail {
        
        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Metadata::Interfaces;

        struct DefaultTypeMetadataApiHolderImpl
        {
            typedef map<
                pair<MetadataDispenserLabel, MetadataDispenser>,
                pair<AssemblyMetadataLabel, AssemblyMetadata>,
                pair<ModuleMetadataLabel, ModuleMetadata>,
                pair<TypeMetadataLabel, TypeMetadata>,
                pair<ITypeMetadataLabel, ITypeMetadata>,
                pair<ITypeMetadataHashLabel, ITypeMetadataHash>,
                pair<ITypeMetadataEqualToLabel, ITypeMetadataEqualTo>,
                pair<NestedTypeMetadataPersistedHandlerLabel, NestedTypeMetadataPersistedHandler>,
                pair<MethodMetadataLabel, MethodMetadata>,
                pair<IMethodMetadataHashLabel, IMethodMetadataHash>,
                pair<IMethodMetadataEqualToLabel, IMethodMetadataEqualTo>,
                pair<IMetaDataImport2, IMetaDataImport2>
            > api_cartridges;
        };

    }   // namespace DefaultTypeMetadataApiHolderDetail {
    
    struct DefaultTypeMetadataApiHolder : 
        DefaultTypeMetadataApiHolderDetail::DefaultTypeMetadataApiHolderImpl
    {
    };

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTTYPEMETADATAAPIHOLDER_H