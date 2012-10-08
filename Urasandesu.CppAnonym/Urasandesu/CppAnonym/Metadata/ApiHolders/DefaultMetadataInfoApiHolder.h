#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMETADATAINFOAPIHOLDER_H
#define URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMETADATAINFOAPIHOLDER_H

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMETADATAINFOAPIHOLDERFWD_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultMetadataInfoApiHolderFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

    namespace Detail {
        
        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Hosting::Interfaces;
        using namespace Urasandesu::CppAnonym::Hosting;
        using namespace Urasandesu::CppAnonym::Metadata::Interfaces;

        struct DefaultMetadataInfoApiHolderImpl
        {
            typedef map<
                pair<RuntimeHostLabel, RuntimeHost>,
                pair<MetadataInfoLabel, MetadataInfo>,
                pair<MetadataDispenserLabel, MetadataDispenser>,
                pair<MetadataDispenserPersistedHandlerLabel, MetadataDispenserPersistedHandler>
            > api_cartridges;
        };

    }   // namespace Detail {

    struct DefaultMetadataInfoApiHolder : 
        Detail::DefaultMetadataInfoApiHolderImpl
    {
    };

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMETADATAINFOAPIHOLDER_H