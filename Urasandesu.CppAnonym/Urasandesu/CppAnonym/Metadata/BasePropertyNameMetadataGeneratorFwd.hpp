#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_BASEPROPERTYNAMEMETADATAGENERATORFWD_HPP
#define URASANDESU_CPPANONYM_METADATA_BASEPROPERTYNAMEMETADATAGENERATORFWD_HPP

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTPROPERTYNAMEMETADATAGENERATORAPIHOLDERFWD_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultPropertyNameMetadataGeneratorApiHolderFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    template<
        class PropertyNameMetadataGeneratorApiHolder = ApiHolders::DefaultPropertyNameMetadataGeneratorApiHolder
    >
    class BasePropertyNameMetadataGenerator;

    typedef BasePropertyNameMetadataGenerator<> PropertyNameMetadataGenerator;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASEPROPERTYNAMEMETADATAGENERATORFWD_HPP