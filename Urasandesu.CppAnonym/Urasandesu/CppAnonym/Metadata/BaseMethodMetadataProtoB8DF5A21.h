#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETHODMETADATAPROTOB8DF5A21_H
#define URASANDESU_CPPANONYM_METADATA_BASEMETHODMETADATAPROTOB8DF5A21_H

#ifndef URASANDESU_CPPANONYM_IHEAPCONTENT_H
#include <Urasandesu/CppAnonym/IHeapContent.h>
#endif

#ifndef URASANDESU_CPPANONYM_SAFEENUM_HPP
#include <Urasandesu/CppAnonym/SafeEnum.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_OPCODEPROTOB8DF5A21_H
#include <Urasandesu/CppAnonym/Metadata/OpCodeProtoB8DF5A21.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_OPCODESPROTOB8DF5A21_H
#include <Urasandesu/CppAnonym/Metadata/OpCodesProtoB8DF5A21.h>
#endif

namespace Urasandesu { namespace CppAnonym {

    class SimpleBlob;

}}  // namespace Urasandesu { namespace CppAnonym {

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    struct DefaultMethodMetadataApiProtoB8DF5A21;

    struct ITypeMetadataApi;

    template<
        class TypeMetadataApiType
    >    
    class BaseTypeMetadataProtoB8DF5A21;


    template<
        class MethodMetadataApiType = DefaultMethodMetadataApiProtoB8DF5A21
    >    
    class BaseMethodMetadataProtoB8DF5A21 : 
        public IHeapContent<mdToken>
    {
    public:
        typedef BaseMethodMetadataProtoB8DF5A21<MethodMetadataApiType> this_type;
        typedef typename Traits::ParentApiOrDefault<MethodMetadataApiType, ITypeMetadataApi>::type type_metadata_api_type;
        typedef BaseTypeMetadataProtoB8DF5A21<type_metadata_api_type> type_metadata_type;
        typedef typename Traits::ChildApiOrDefault<MethodMetadataApiType, IMetaDataImport2>::type metadata_import_api_type;
        
        void Init(type_metadata_type &typeMeta, metadata_import_api_type &metaImpApi) const
        {
        }

        mdToken GetToken() const
        {
            return GetKey();
        }
    };

    typedef BaseMethodMetadataProtoB8DF5A21<> MethodMetadataProtoB8DF5A21;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASEMETHODMETADATAPROTOB8DF5A21_H