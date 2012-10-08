#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYNAMEMETADATAGENERATORFWD_HPP
#define URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYNAMEMETADATAGENERATORFWD_HPP

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTASSEMBLYNAMEMETADATAGENERATORAPIHOLDERFWD_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultAssemblyNameMetadataGeneratorApiHolderFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    template<
        class AssemblyNameMetadataGeneratorApiHolder = ApiHolders::DefaultAssemblyNameMetadataGeneratorApiHolder
    >    
    class BaseAssemblyNameMetadataGenerator;

    typedef BaseAssemblyNameMetadataGenerator<> AssemblyNameMetadataGenerator;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYNAMEMETADATAGENERATORFWD_HPP