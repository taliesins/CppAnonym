#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETHODNAMEMETADATAFWD_HPP
#define URASANDESU_CPPANONYM_METADATA_BASEMETHODNAMEMETADATAFWD_HPP

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMETHODNAMEMETADATAAPIHOLDERFWD_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultMethodNameMetadataApiHolderFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    template<
        class MethodNameMetadataApiHolder = ApiHolders::DefaultMethodNameMetadataApiHolder
    >    
    class BaseMethodNameMetadata;

    typedef BaseMethodNameMetadata<> MethodNameMetadata;

    
    
    
    
    template<
        class MethodNameMetadataApiHolder = ApiHolders::DefaultMethodNameMetadataApiHolder
    >    
    struct BaseMethodNameMetadataHash;

    typedef BaseMethodNameMetadataHash<> MethodNameMetadataHash;

    
    
    
    
    template<
        class MethodNameMetadataApiHolder = ApiHolders::DefaultMethodNameMetadataApiHolder
    >    
    struct BaseMethodNameMetadataEqualTo;

    typedef BaseMethodNameMetadataEqualTo<> MethodNameMetadataEqualTo;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASEMETHODNAMEMETADATAFWD_HPP