#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_BASEIMODULEMETADATAFWD_HPP
#define URASANDESU_CPPANONYM_METADATA_BASEIMODULEMETADATAFWD_HPP

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTIMODULEMETADATAAPIHOLDERFWD_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultIModuleMetadataApiHolderFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    template<
        class IModuleMetadataApiHolder = ApiHolders::DefaultIModuleMetadataApiHolder
    >    
    class BaseIModuleMetadata;

    typedef BaseIModuleMetadata<> IModuleMetadata;




    
    template<
        class IModuleMetadataApiHolder = ApiHolders::DefaultIModuleMetadataApiHolder
    >    
    class BaseIModuleMetadataHash;

    typedef BaseIModuleMetadataHash<> IModuleMetadataHash;

    
    
    
    
    template<
        class IModuleMetadataApiHolder = ApiHolders::DefaultIModuleMetadataApiHolder
    >    
    class BaseIModuleMetadataEqualTo;

    typedef BaseIModuleMetadataEqualTo<> IModuleMetadataEqualTo;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASEIMODULEMETADATAFWD_HPP