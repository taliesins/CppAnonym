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

#ifndef URASANDESU_CPPANONYM_TRAITS_CARTRIDGEAPISYSTEM_HPP
#include <Urasandesu/CppAnonym/Traits/CartridgeApiSystem.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_SIMPLEBLOB_HPP
#include <Urasandesu/CppAnonym/SimpleBlob.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_METHODNAMEMETADATALABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/MethodNameMetadataLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_TYPEMETADATALABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/TypeMetadataLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_METHODMETADATAAPIHOLDERLABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/MethodMetadataApiHolderLabel.hpp>
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
    class BaseMethodMetadata
    {
    public:
        typedef BaseMethodMetadata<MethodMetadataApiHolder> this_type;

        typedef typename MethodMetadataApiAt<MethodMetadataApiHolder, Interfaces::TypeMetadataLabel>::type type_metadata_type;
        typedef typename MethodMetadataApiAt<MethodMetadataApiHolder, IMetaDataImport2>::type metadata_import_api_type;
        typedef typename MethodMetadataApiAt<MethodMetadataApiHolder, Interfaces::MethodNameMetadataLabel>::type method_name_metadata_type;

        BaseMethodMetadata() : 
            m_pTypeMeta(NULL),
            m_pMethodNameMeta(NULL), 
            m_mdt(mdTokenNil)
        { }

        //__declspec(deprecated("This method is temporarily deprecated."))
        //void Init(type_metadata_type &typeMeta, metadata_import_api_type &metaImpApi) const
        //{
        //    _ASSERTE(m_pTypeMeta == NULL);

        //    m_pTypeMeta = &typeMeta;
        //}

        //__declspec(deprecated("This method is temporarily deprecated."))
        //void Init(type_metadata_type &typeMeta, metadata_import_api_type &metaImpApi, method_name_metadata_type const &methodName) const
        //{
        //    _ASSERTE(m_pTypeMeta == NULL);

        //    m_pTypeMeta = &typeMeta;
        //    m_pMetaImpApi = &metaImpApi;
        //    m_methodName = methodName;
        //}
        
        void Init(type_metadata_type &typeMeta) const
        {
            // This method implementation is temporary.
            _ASSERTE(m_pTypeMeta == NULL);

            m_pTypeMeta = &typeMeta;
        }

        template<class T>
        T const *FindType() const { _ASSERTE(m_pTypeMeta != NULL); return static_cast<type_metadata_type const *>(m_pTypeMeta)->FindType<T>(); }

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
                this_type *mutableThis = const_cast<this_type *>(this);
                type_metadata_type *pTypeMeta = mutableThis->FindType<type_metadata_type>();

                m_pMethodNameMeta = pTypeMeta->MethodNameMetadataHeap().New();
                m_pMethodNameMeta->SetResolutionScope(*pTypeMeta);
                m_pMethodNameMeta->SetToken(GetToken());
                m_pMethodNameMeta->SetResolvedMethod(*mutableThis);
            }
            return m_pMethodNameMeta;
        }

        mdToken GetToken() const
        {
            return m_mdt;
        }

        //std::wstring const &GetName() const
        //{
        //    return m_name;
        //}

    private:
        template<
            class TypeMetadataApiHolder
        >    
        friend class BaseTypeMetadata;

        void SetToken(mdToken mdt)
        {
            _ASSERTE(m_mdt == mdTokenNil);
            _ASSERTE(mdt != mdTokenNil);

            m_mdt = mdt;
        }


        mutable type_metadata_type *m_pTypeMeta;
        mutable method_name_metadata_type *m_pMethodNameMeta;
        //mutable ATL::CComPtr<metadata_import_api_type> m_pMetaImpApi;
        //mutable method_name_metadata_type m_methodName;
        //mutable std::wstring m_name;
        mdToken m_mdt;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASEMETHODMETADATA_HPP