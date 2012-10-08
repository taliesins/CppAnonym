#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_BASEITYPEMETADATAFWD_HPP
#define URASANDESU_CPPANONYM_METADATA_BASEITYPEMETADATAFWD_HPP

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTITYPEMETADATAAPIHOLDERFWD_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultITypeMetadataApiHolderFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    template<
        class ITypeMetadataApiHolder = ApiHolders::DefaultITypeMetadataApiHolder
    >    
    class BaseITypeMetadata;

    typedef BaseITypeMetadata<> ITypeMetadata;




    
    template<
        class ITypeMetadataApiHolder = ApiHolders::DefaultITypeMetadataApiHolder
    >    
    class BaseITypeMetadataHash;

    typedef BaseITypeMetadataHash<> ITypeMetadataHash;

    
    
    
    
    template<
        class ITypeMetadataApiHolder = ApiHolders::DefaultITypeMetadataApiHolder
    >    
    class BaseITypeMetadataEqualTo;

    typedef BaseITypeMetadataEqualTo<> ITypeMetadataEqualTo;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASEITYPEMETADATAFWD_HPP