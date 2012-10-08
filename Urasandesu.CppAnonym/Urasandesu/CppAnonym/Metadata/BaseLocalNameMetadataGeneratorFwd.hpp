#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_BASELOCALNAMEMETADATAGENERATORFWD_HPP
#define URASANDESU_CPPANONYM_METADATA_BASELOCALNAMEMETADATAGENERATORFWD_HPP

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTLOCALNAMEMETADATAGENERATORAPIHOLDERFWD_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultLocalNameMetadataGeneratorApiHolderFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    template<
        class LocalNameMetadataGeneratorApiHolder = ApiHolders::DefaultLocalNameMetadataGeneratorApiHolder
    >
    class BaseLocalNameMetadataGenerator;

    typedef BaseLocalNameMetadataGenerator<> LocalNameMetadataGenerator;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASELOCALNAMEMETADATAGENERATORFWD_HPP