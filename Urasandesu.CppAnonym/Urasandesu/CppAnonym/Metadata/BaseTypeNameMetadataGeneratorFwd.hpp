#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_BASETYPENAMEMETADATAGENERATORFWD_HPP
#define URASANDESU_CPPANONYM_METADATA_BASETYPENAMEMETADATAGENERATORFWD_HPP

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTTYPENAMEMETADATAGENERATORAPIHOLDERFWD_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultTypeNameMetadataGeneratorApiHolderFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    template<
        class TypeNameMetadataGeneratorApiHolder = ApiHolders::DefaultTypeNameMetadataGeneratorApiHolder
    >
    class BaseTypeNameMetadataGenerator;

    typedef BaseTypeNameMetadataGenerator<> TypeNameMetadataGenerator;




    
    //template<
    //    class TypeNameMetadataGeneratorApiHolder = ApiHolders::DefaultTypeNameMetadataGeneratorApiHolder
    //>    
    //class BaseTypeNameMetadataGeneratorHash;

    //typedef BaseTypeNameMetadataGeneratorHash<> TypeNameMetadataGeneratorHash;

    //
    //
    //
    //
    //template<
    //    class TypeNameMetadataGeneratorApiHolder = ApiHolders::DefaultTypeNameMetadataGeneratorApiHolder
    //>    
    //class BaseTypeNameMetadataGeneratorEqualTo;

    //typedef BaseTypeNameMetadataGeneratorEqualTo<> TypeNameMetadataGeneratorEqualTo;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASETYPENAMEMETADATAGENERATORFWD_HPP