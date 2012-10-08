#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETHODNAMEMETADATAGENERATORFWD_HPP
#define URASANDESU_CPPANONYM_METADATA_BASEMETHODNAMEMETADATAGENERATORFWD_HPP

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMETHODNAMEMETADATAGENERATORAPIHOLDERFWD_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultMethodNameMetadataGeneratorApiHolderFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    template<
        class MethodNameMetadataGeneratorApiHolder = ApiHolders::DefaultMethodNameMetadataGeneratorApiHolder
    >
    class BaseMethodNameMetadataGenerator;

    typedef BaseMethodNameMetadataGenerator<> MethodNameMetadataGenerator;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASEMETHODNAMEMETADATAGENERATORFWD_HPP