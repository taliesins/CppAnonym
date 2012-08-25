#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_BASEIASSEMBLYMETADATAFWD_HPP
#define URASANDESU_CPPANONYM_METADATA_BASEIASSEMBLYMETADATAFWD_HPP

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTIASSEMBLYMETADATAAPIHOLDERFWD_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultIAssemblyMetadataApiHolderFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    template<
        class IAssemblyMetadataApiHolder = ApiHolders::DefaultIAssemblyMetadataApiHolder
    >    
    class BaseIAssemblyMetadata;

    typedef BaseIAssemblyMetadata<> IAssemblyMetadata;




    
    template<
        class IAssemblyMetadataApiHolder = ApiHolders::DefaultIAssemblyMetadataApiHolder
    >    
    class BaseIAssemblyMetadataHash;

    typedef BaseIAssemblyMetadataHash<> IAssemblyMetadataHash;

    
    
    
    
    template<
        class IAssemblyMetadataApiHolder = ApiHolders::DefaultIAssemblyMetadataApiHolder
    >    
    class BaseIAssemblyMetadataEqualTo;

    typedef BaseIAssemblyMetadataEqualTo<> IAssemblyMetadataEqualTo;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASEIASSEMBLYMETADATAFWD_HPP