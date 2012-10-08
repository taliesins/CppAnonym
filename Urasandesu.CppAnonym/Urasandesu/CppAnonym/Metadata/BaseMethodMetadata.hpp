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

        void Init(type_metadata_type &typeMeta) const
        {
            // This method implementation is temporary.
            _ASSERTE(m_pTypeMeta == NULL);

            m_pTypeMeta = &typeMeta;
        }

        template<class T>
        T const &Map() const { _ASSERTE(m_pTypeMeta != NULL); return static_cast<type_metadata_type const *>(m_pTypeMeta)->Map<T>(); }

        template<class T>
        T &Map() { return m_pTypeMeta->Map<T>(); }
      
        template<>
        this_type const &Map<this_type>() const { return this; }
      
        template<>
        this_type &Map<this_type>() { return this; }

        method_name_metadata_type const *GetMethodName() const
        {
            _ASSERTE(m_pTypeMeta != NULL);

            if (m_pMethodNameMeta == NULL)
            {
                this_type *pMutableThis = const_cast<this_type *>(this);
                type_metadata_type &typeMeta = pMutableThis->Map<type_metadata_type>();

                m_pMethodNameMeta = typeMeta.MethodNameMetadataHeap().New();
                m_pMethodNameMeta->SetResolutionScope(typeMeta);
                m_pMethodNameMeta->SetToken(GetToken());
                m_pMethodNameMeta->SetResolvedMethod(*pMutableThis);
            }
            return m_pMethodNameMeta;
        }

        mdToken GetToken() const
        {
            return m_mdt;
        }

    private:
        friend typename type_metadata_type;

        void SetToken(mdToken mdt)
        {
            _ASSERTE(m_mdt == mdTokenNil);
            _ASSERTE(mdt != mdTokenNil);

            m_mdt = mdt;
        }


        mutable type_metadata_type *m_pTypeMeta;
        mutable method_name_metadata_type *m_pMethodNameMeta;
        mdToken m_mdt;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASEMETHODMETADATA_HPP