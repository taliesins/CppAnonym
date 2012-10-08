#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_BASETYPEMETADATAFWD_HPP
#define URASANDESU_CPPANONYM_METADATA_BASETYPEMETADATAFWD_HPP

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTTYPEMETADATAAPIHOLDERFWD_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultTypeMetadataApiHolderFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {
    
    template<
        class TypeMetadataApiHolder = ApiHolders::DefaultTypeMetadataApiHolder
    >    
    class BaseTypeMetadata;

    typedef BaseTypeMetadata<> TypeMetadata;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASETYPEMETADATAFWD_HPP