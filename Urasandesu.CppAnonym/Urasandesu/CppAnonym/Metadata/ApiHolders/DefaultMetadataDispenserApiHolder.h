#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMETADATADISPENSERAPIHOLDER_H
#define URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMETADATADISPENSERAPIHOLDER_H

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_METADATAINFOLABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/MetadataInfoLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATAINFOFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseMetadataInfoFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_METADATADISPENSERLABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/MetadataDispenserLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATADISPENSERFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseMetadataDispenserFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMETADATADISPENSERAPIHOLDERFWD_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultMetadataDispenserApiHolderFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

    namespace DefaultMetadataDispenserApiHolderDetail {
        
        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Metadata::Interfaces;

        struct DefaultMetadataDispenserApiHolderImpl
        {
            typedef map<
                pair<MetadataInfoLabel, MetadataInfo>,
                pair<MetadataDispenserLabel, MetadataDispenser>,
                pair<MetadataDispenserPersistedHandlerLabel, MetadataDispenserPersistedHandler>
            > api_cartridges;
        };

    }   // namespace DefaultMetadataDispenserApiHolderDetail {

    struct DefaultMetadataDispenserApiHolder : 
        DefaultMetadataDispenserApiHolderDetail::DefaultMetadataDispenserApiHolderImpl
    {
    };

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMETADATADISPENSERAPIHOLDER_H