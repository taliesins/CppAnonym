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

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_METHODNAMEMETADATALABELFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/MethodNameMetadataLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_TYPEMETADATALABELFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/TypeMetadataLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_METHODMETADATAAPIHOLDERLABELFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/MethodMetadataApiHolderLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETHODMETADATAFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseMethodMetadataFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    template<class ApiCartridgesHolder, class ApiLabel>
    struct MethodMetadataApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::MethodMetadataApiHolderLabel, ApiLabel>
    {
    };

    template<
        class MethodMetadataApiHolder
    >    
    class BaseMethodMetadata : 
        public IHeapContent<mdToken>
    {
    public:
        typedef BaseMethodMetadata<MethodMetadataApiHolder> this_type;

        typedef typename MethodMetadataApiAt<MethodMetadataApiHolder, Interfaces::TypeMetadataLabel>::type type_metadata_type;
        typedef typename MethodMetadataApiAt<MethodMetadataApiHolder, IMetaDataImport2>::type metadata_import_api_type;
        typedef typename MethodMetadataApiAt<MethodMetadataApiHolder, Interfaces::MethodNameMetadataLabel>::type method_name_metadata_type;

        BaseMethodMetadata() : 
            m_pTypeMeta(NULL),
            m_pMethodNameMeta(NULL)
        { }

        __declspec(deprecated("This method is temporarily deprecated."))
        void Init(type_metadata_type &typeMeta, metadata_import_api_type &metaImpApi) const
        {
            _ASSERTE(m_pTypeMeta == NULL);

            m_pTypeMeta = &typeMeta;
        }

        __declspec(deprecated("This method is temporarily deprecated."))
        void Init(type_metadata_type &typeMeta, metadata_import_api_type &metaImpApi, method_name_metadata_type const &methodName) const
        {
            _ASSERTE(m_pTypeMeta == NULL);

            m_pTypeMeta = &typeMeta;
            m_pMetaImpApi = &metaImpApi;
            m_methodName = methodName;
        }
        
        void Init(type_metadata_type &typeMeta) const
        {
            // This method implementation is temporary.
            _ASSERTE(m_pTypeMeta == NULL);

            m_pTypeMeta = &typeMeta;
        }

        template<class T>
        T const *FindType() const { return static_cast<type_metadata_type const *>(m_pTypeMeta)->FindType<T>(); }

        template<class T>
        T *FindType() { return m_pTypeMeta->FindType<T>(); }
      
        template<>
        this_type const *FindType<this_type>() const { return this; }
      
        template<>
        this_type *FindType<this_type>() { return this; }

        method_name_metadata_type const *GetMethodName() const
        {
            _ASSERTE(m_pTypeMeta != NULL);

            if (m_pMethodNameMeta == NULL)
            {
                m_pMethodNameMeta = m_pTypeMeta->MethodNameMetadataHeap().New();
                m_pMethodNameMeta->SetResolutionScope(*m_pTypeMeta);
                m_pMethodNameMeta->SetToken(GetKey());
            }
            return m_pMethodNameMeta;
        }

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
        mutable method_name_metadata_type *m_pMethodNameMeta;
        mutable ATL::CComPtr<metadata_import_api_type> m_pMetaImpApi;
        mutable method_name_metadata_type m_methodName;
        mutable std::wstring m_name;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASEMETHODMETADATA_HPP