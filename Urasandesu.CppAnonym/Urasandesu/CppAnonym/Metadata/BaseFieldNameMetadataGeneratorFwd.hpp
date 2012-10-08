#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_BASEFIELDNAMEMETADATAGENERATORFWD_HPP
#define URASANDESU_CPPANONYM_METADATA_BASEFIELDNAMEMETADATAGENERATORFWD_HPP

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTFIELDNAMEMETADATAGENERATORAPIHOLDERFWD_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultFieldNameMetadataGeneratorApiHolderFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    template<
        class FieldNameMetadataGeneratorApiHolder = ApiHolders::DefaultFieldNameMetadataGeneratorApiHolder
    >
    class BaseFieldNameMetadataGenerator;

    typedef BaseFieldNameMetadataGenerator<> FieldNameMetadataGenerator;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASEFIELDNAMEMETADATAGENERATORFWD_HPP