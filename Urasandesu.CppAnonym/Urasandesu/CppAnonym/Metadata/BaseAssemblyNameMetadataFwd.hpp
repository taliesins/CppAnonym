#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYNAMEMETADATAFWD_HPP
#define URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYNAMEMETADATAFWD_HPP

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTASSEMBLYNAMEMETADATAAPIHOLDERFWD_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultAssemblyNameMetadataApiHolderFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    template<
        class AssemblyNameMetadataApiHolder = ApiHolders::DefaultAssemblyNameMetadataApiHolder
    >    
    class BaseAssemblyNameMetadata;

    typedef BaseAssemblyNameMetadata<> AssemblyNameMetadata;

    
    
    
    
    template<
        class AssemblyNameMetadataApiHolder = ApiHolders::DefaultAssemblyNameMetadataApiHolder
    >    
    class BaseAssemblyNameMetadataHash;

    typedef BaseAssemblyNameMetadataHash<> AssemblyNameMetadataHash;

    
    
    
    
    template<
        class AssemblyNameMetadataApiHolder = ApiHolders::DefaultAssemblyNameMetadataApiHolder
    >    
    class BaseAssemblyNameMetadataEqualTo;

    typedef BaseAssemblyNameMetadataEqualTo<> AssemblyNameMetadataEqualTo;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYNAMEMETADATAFWD_HPP