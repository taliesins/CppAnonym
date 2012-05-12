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

    template<
        class TypeMetadataApiType
    >    
    struct MethodKey;

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
        public IHeapContent<MethodKey<MethodMetadataApiType>>
    {
    public:
        typedef BaseMethodMetadataProtoB8DF5A21<MethodMetadataApiType> this_type;

        typedef typename Traits::ExternalApiOrDefault<MethodMetadataApiType, IMethodMetadataApi, ITypeMetadataApi>::type type_metadata_api_type;
        typedef BaseTypeMetadataProtoB8DF5A21<type_metadata_api_type> type_metadata_type;
        
        typedef typename Traits::ExternalApiOrDefault<MethodMetadataApiType, IMethodMetadataApi, IMetaDataImport2>::type metadata_import_api_type;
        
        typedef MethodKey<MethodMetadataApiType> method_key_type;

        BaseMethodMetadataProtoB8DF5A21() : 
            m_pTypeMeta(NULL)
        { }

        void Init(type_metadata_type &typeMeta, metadata_import_api_type &metaImpApi) const
        {
            _ASSERTE(m_pTypeMeta == NULL);

            m_pTypeMeta = &typeMeta;
        }

        void Init(type_metadata_type &typeMeta, metadata_import_api_type &metaImpApi, method_key_type const &methodKey) const
        {
            _ASSERTE(m_pTypeMeta == NULL);

            m_pTypeMeta = &typeMeta;
            m_pMetaImpApi = &metaImpApi;
            m_methodKey = methodKey;
        }

        template<class T>
        T const *FindType() const { return static_cast<type_metadata_type const *>(m_pTypeMeta)->FindType<T>(); }

        template<class T>
        T *FindType() { return m_pTypeMeta->FindType<T>(); }
      
        template<>
        this_type const *FindType<this_type>() const { return this; }
      
        template<>
        this_type *FindType<this_type>() { return this; }

        mdToken GetToken() const
        {
            return mdTokenNil;
        }

        std::wstring const &GetName() const
        {
            return m_name;
        }

    private:
        mutable type_metadata_type *m_pTypeMeta;
        mutable ATL::CComPtr<metadata_import_api_type> m_pMetaImpApi;
        mutable method_key_type m_methodKey;
        mutable std::wstring m_name;
    };

    typedef BaseMethodMetadataProtoB8DF5A21<> MethodMetadataProtoB8DF5A21;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASEMETHODMETADATAPROTOB8DF5A21_H