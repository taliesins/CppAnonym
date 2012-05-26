#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETHODMETADATA_HPP
#define URASANDESU_CPPANONYM_METADATA_BASEMETHODMETADATA_HPP

#ifndef URASANDESU_CPPANONYM_IHEAPCONTENT_H
#include <Urasandesu/CppAnonym/IHeapContent.h>
#endif

#ifndef URASANDESU_CPPANONYM_SAFEENUM_HPP
#include <Urasandesu/CppAnonym/SafeEnum.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_OPCODE_H
#include <Urasandesu/CppAnonym/Metadata/OpCode.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_OPCODES_H
#include <Urasandesu/CppAnonym/Metadata/OpCodes.h>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_CARTRIDGEAPISYSTEMFWD_HPP
#include <Urasandesu/CppAnonym/Traits/CartridgeApiSystemFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_SIMPLEBLOBFWD_HPP
#include <Urasandesu/CppAnonym/SimpleBlobFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_METHODNAMEMETADATALABELFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/MethodNameMetadataLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_TYPEMETADATALABELFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/TypeMetadataLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_METHODMETADATAAPIHOLDERLABELFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/MethodMetadataApiHolderLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETHODMETADATAFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseMethodMetadataFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    template<class ApiCartridgesHolder, class ApiLabel>
    struct MethodMetadataApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, MethodMetadataApiHolderLabel, ApiLabel>
    {
    };

    template<
        class MethodMetadataApiHolder
    >    
    class BaseMethodMetadata : 
        public IHeapContent<typename MethodMetadataApiAt<MethodMetadataApiHolder, MethodNameMetadataLabel>::type>
    {
    public:
        typedef BaseMethodMetadata<MethodMetadataApiHolder> this_type;

        typedef typename MethodMetadataApiAt<MethodMetadataApiHolder, TypeMetadataLabel>::type type_metadata_type;
        typedef typename MethodMetadataApiAt<MethodMetadataApiHolder, IMetaDataImport2>::type metadata_import_api_type;
        typedef typename MethodMetadataApiAt<MethodMetadataApiHolder, MethodNameMetadataLabel>::type method_name_metadata_type;

        BaseMethodMetadata() : 
            m_pTypeMeta(NULL)
        { }

        void Init(type_metadata_type &typeMeta, metadata_import_api_type &metaImpApi) const
        {
            _ASSERTE(m_pTypeMeta == NULL);

            m_pTypeMeta = &typeMeta;
        }

        void Init(type_metadata_type &typeMeta, metadata_import_api_type &metaImpApi, method_name_metadata_type const &methodName) const
        {
            _ASSERTE(m_pTypeMeta == NULL);

            m_pTypeMeta = &typeMeta;
            m_pMetaImpApi = &metaImpApi;
            m_methodName = methodName;
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
        mutable method_name_metadata_type m_methodName;
        mutable std::wstring m_name;
    };

    typedef BaseMethodMetadata<> MethodMetadata;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASEMETHODMETADATA_HPP