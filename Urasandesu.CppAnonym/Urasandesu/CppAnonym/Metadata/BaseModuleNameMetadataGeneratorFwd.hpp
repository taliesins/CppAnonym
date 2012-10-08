#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_BASEMODULENAMEMETADATAGENERATORFWD_HPP
#define URASANDESU_CPPANONYM_METADATA_BASEMODULENAMEMETADATAGENERATORFWD_HPP

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMODULENAMEMETADATAGENERATORAPIHOLDERFWD_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultModuleNameMetadataGeneratorApiHolderFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    template<
        class ModuleNameMetadataGeneratorApiHolder = ApiHolders::DefaultModuleNameMetadataGeneratorApiHolder
    >    
    class BaseModuleNameMetadataGenerator;

    typedef BaseModuleNameMetadataGenerator<> ModuleNameMetadataGenerator;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASEMODULENAMEMETADATAGENERATORFWD_HPP