#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATAINFOFWD_HPP
#define URASANDESU_CPPANONYM_METADATA_BASEMETADATAINFOFWD_HPP

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMETADATAINFOAPIHOLDERFWD_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultMetadataInfoApiHolderFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    template<
        class MetadataInfoApiHolder = ApiHolders::DefaultMetadataInfoApiHolder
    >    
    class BaseMetadataInfo;

    typedef BaseMetadataInfo<> MetadataInfo;

    
    
    
    
    template<
        class MetadataInfoApiHolder = ApiHolders::DefaultMetadataInfoApiHolder
    >    
    class BaseMetadataInfoPersistedHandler;

    typedef BaseMetadataInfoPersistedHandler<> MetadataInfoPersistedHandler;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATAINFOFWD_HPP