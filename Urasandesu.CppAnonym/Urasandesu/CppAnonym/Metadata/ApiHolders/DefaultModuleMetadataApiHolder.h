#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMODULEMETADATAAPIHOLDER_H
#define URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMODULEMETADATAAPIHOLDER_H

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_ITYPEMETADATALABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/ITypeMetadataLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEITYPEMETADATAFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseITypeMetadataFwd.hpp>
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
                pair<IModuleMetadataLabel, IModuleMetadata>,
                pair<AssemblyMetadataLabel, AssemblyMetadata>,
                pair<IMetaDataImport2, IMetaDataImport2>,
                pair<ITypeMetadataLabel, ITypeMetadata>,
                pair<TypeMetadataLabel, TypeMetadata>,
                pair<ITypeMetadataHashLabel, ITypeMetadataHash>,
                pair<ITypeMetadataEqualToLabel, ITypeMetadataEqualTo>,
                pair<MetadataDispenserLabel, MetadataDispenser>
            > api_cartridges;
        };

    }   // namespace Detail {
    
    struct DefaultModuleMetadataApiHolder : 
        Detail::DefaultModuleMetadataApiHolderImpl
    {
    };

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMODULEMETADATAAPIHOLDER_H