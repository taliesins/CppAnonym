#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_BASEIMETHODMETADATAFWD_HPP
#define URASANDESU_CPPANONYM_METADATA_BASEIMETHODMETADATAFWD_HPP

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTIMETHODMETADATAAPIHOLDERFWD_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultIMethodMetadataApiHolderFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    template<
        class IMethodMetadataApiHolder = ApiHolders::DefaultIMethodMetadataApiHolder
    >    
    class BaseIMethodMetadata;

    typedef BaseIMethodMetadata<> IMethodMetadata;




    
    template<
        class IMethodMetadataApiHolder = ApiHolders::DefaultIMethodMetadataApiHolder
    >    
    class BaseIMethodMetadataHash;

    typedef BaseIMethodMetadataHash<> IMethodMetadataHash;

    
    
    
    
    template<
        class IMethodMetadataApiHolder = ApiHolders::DefaultIMethodMetadataApiHolder
    >    
    class BaseIMethodMetadataEqualTo;

    typedef BaseIMethodMetadataEqualTo<> IMethodMetadataEqualTo;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASEIMETHODMETADATAFWD_HPP