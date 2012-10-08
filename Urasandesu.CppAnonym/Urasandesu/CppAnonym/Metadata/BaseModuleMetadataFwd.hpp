#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_BASEMODULEMETADATAFWD_HPP
#define URASANDESU_CPPANONYM_METADATA_BASEMODULEMETADATAFWD_HPP

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMODULEMETADATAAPIHOLDERFWD_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultModuleMetadataApiHolderFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {
    
    template<
        class ModuleMetadataApiHolder = ApiHolders::DefaultModuleMetadataApiHolder
    >    
    class BaseModuleMetadata;

    typedef BaseModuleMetadata<> ModuleMetadata;

    
    
    
    
    template<
        class ModuleMetadataApiHolder = ApiHolders::DefaultModuleMetadataApiHolder
    >    
    class BaseModuleMetadataPersistedHandler;

    typedef BaseModuleMetadataPersistedHandler<> ModuleMetadataPersistedHandler;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASEMODULEMETADATAFWD_HPP