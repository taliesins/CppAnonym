#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_BASEMODULENAMEMETADATAFWD_HPP
#define URASANDESU_CPPANONYM_METADATA_BASEMODULENAMEMETADATAFWD_HPP

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMODULENAMEMETADATAAPIHOLDERFWD_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultModuleNameMetadataApiHolderFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    template<
        class ModuleNameMetadataApiHolder = ApiHolders::DefaultModuleNameMetadataApiHolder
    >    
    class BaseModuleNameMetadata;

    typedef BaseModuleNameMetadata<> ModuleNameMetadata;




    
    template<
        class ModuleNameMetadataApiHolder = ApiHolders::DefaultModuleNameMetadataApiHolder
    >    
    class BaseModuleNameMetadataHash;

    typedef BaseModuleNameMetadataHash<> ModuleNameMetadataHash;

    
    
    
    
    template<
        class ModuleNameMetadataApiHolder = ApiHolders::DefaultModuleNameMetadataApiHolder
    >    
    class BaseModuleNameMetadataEqualTo;

    typedef BaseModuleNameMetadataEqualTo<> ModuleNameMetadataEqualTo;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASEMODULENAMEMETADATAFWD_HPP