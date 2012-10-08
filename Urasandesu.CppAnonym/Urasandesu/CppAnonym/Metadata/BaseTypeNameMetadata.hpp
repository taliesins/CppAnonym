#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_BASETYPENAMEMETADATA_HPP
#define URASANDESU_CPPANONYM_METADATA_BASETYPENAMEMETADATA_HPP

#ifndef URASANDESU_CPPANONYM_TRAITS_CARTRIDGEAPISYSTEM_HPP
#include <Urasandesu/CppAnonym/Traits/CartridgeApiSystem.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_TYPENAMEMETADATAAPIHOLDERLABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/TypeNameMetadataApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_SIMPLEHEAPPROVIDER_HPP
#include <Urasandesu/CppAnonym/SimpleHeapProvider.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_OBJECTTAG_HPP
#include <Urasandesu/CppAnonym/ObjectTag.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_METHODNAMEMETADATALABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/MethodNameMetadataLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_ASSEMBLYMETADATALABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/AssemblyMetadataLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_ASSEMBLYNAMEMETADATALABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/AssemblyNameMetadataLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_TYPEMETADATALABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/TypeMetadataLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_MODULENAMEMETADATALABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/ModuleNameMetadataLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_MODULEMETADATALABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/ModuleMetadataLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_TYPEKINDS_H
#include <Urasandesu/CppAnonym/Metadata/TypeKinds.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_CALLINGCONVENTIONS_H
#include <Urasandesu/CppAnonym/Metadata/CallingConventions.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASETYPENAMEMETADATAFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseTypeNameMetadataFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    template<class ApiCartridgesHolder, class ApiLabel>
    struct TypeNameMetadataApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::TypeNameMetadataApiHolderLabel, ApiLabel>
    {
    };

    template<
        class TypeNameMetadataApiHolder
    >
    class BaseTypeNameMetadata : 
        public TypeNameMetadataApiAt<TypeNameMetadataApiHolder, Interfaces::ITypeNameMetadataLabel>::type,
        public SimpleHeapProvider<
            boost::mpl::vector<
                ObjectTag<typename TypeNameMetadataApiAt<TypeNameMetadataApiHolder, Interfaces::MethodNameMetadataLabel>::type, QuickHeap>
            >
        >
    {
    public:
        typedef BaseTypeNameMetadata<TypeNameMetadataApiHolder> this_type;
        typedef typename TypeNameMetadataApiAt<TypeNameMetadataApiHolder, Interfaces::ITypeNameMetadataLabel>::type base_type;

        typedef typename TypeNameMetadataApiAt<TypeNameMetadataApiHolder, Interfaces::AssemblyMetadataLabel>::type assembly_metadata_type;
        typedef typename TypeNameMetadataApiAt<TypeNameMetadataApiHolder, Interfaces::AssemblyNameMetadataLabel>::type assembly_name_metadata_type;
        typedef typename TypeNameMetadataApiAt<TypeNameMetadataApiHolder, Interfaces::ModuleMetadataLabel>::type module_metadata_type;
        typedef typename TypeNameMetadataApiAt<TypeNameMetadataApiHolder, Interfaces::ModuleNameMetadataLabel>::type module_name_metadata_type;
        typedef typename TypeNameMetadataApiAt<TypeNameMetadataApiHolder, Interfaces::TypeMetadataLabel>::type type_metadata_type;
        typedef typename TypeNameMetadataApiAt<TypeNameMetadataApiHolder, Interfaces::MethodNameMetadataLabel>::type method_name_metadata_type;
        typedef typename TypeNameMetadataApiAt<TypeNameMetadataApiHolder, IMetaDataImport2>::type com_meta_data_import_type;

        typedef ObjectTag<method_name_metadata_type, QuickHeap> method_name_metadata_obj_tag_type;
        typedef typename type_decided_by<method_name_metadata_obj_tag_type>::type method_name_metadata_heap_type;

        BaseTypeNameMetadata() : 
            m_nameInitialized(false),
            m_asmNameAsScopeInitialized(false),
            m_asmAsScopeInitialized(false),
            m_tokenInitialized(false),
            m_pResolvedType(NULL), 
            m_mdt(mdTokenNil), 
            m_pBaseTypeName(NULL), 
            m_kind(TypeKinds::TK_END),
            m_kindInitialized(false),
            m_filled(false), 
            m_pModNameAsScope(NULL), 
            m_pModAsScope(NULL)
        { }

        void Init(module_name_metadata_type &modNameAsScope) const
        {
            _ASSERTE(m_pModNameAsScope == NULL && m_pModAsScope == NULL);
            m_pModNameAsScope = &modNameAsScope;
        }

        void Init(module_metadata_type &modAsScope) const
        {
            _ASSERTE(m_pModNameAsScope == NULL && m_pModAsScope == NULL);
            m_pModAsScope = &modAsScope;
        }

        template<class T>
        T const &Map() const { return const_cast<this_type *>(this)->Map<T>(); }

        template<class T>
        T &Map() 
        { 
            _ASSERTE(m_pModNameAsScope != NULL || m_pModAsScope != NULL);
            if (m_pModNameAsScope != NULL)
                return m_pModNameAsScope->Map<T>();
            else
                return m_pModAsScope->GetModuleNameCore().Map<T>();
        }
      
        template<>
        this_type const &Map<this_type>() const { return const_cast<this_type *>(this)->Map<this_type>(); }
      
        template<>
        this_type &Map<this_type>() { return *this; }

        std::wstring const &GetName() const
        {
            if (!m_nameInitialized)
            {
                FillPropertiesIfNecessary();
                m_nameInitialized = true;
            }
            return m_name;
        }

        typename base_type::this_type const *GetBaseTypeName() const
        {
            FillPropertiesIfNecessary();
            return m_pBaseTypeName;
        }

        typename base_type::i_module_name_metadata_type const &GetResolutionScope() const
        {
            return Map<module_name_metadata_type>();
        }

        typename base_type::i_type_metadata_type const &Resolve() const
        {
            return ResolveCore();
        }

        std::vector<COR_SIGNATURE> const &GetSignatures() const
        {
            if (m_sigs.empty())
                PushBackSignatures(m_sigs, *this);

            return m_sigs;
        }

        method_name_metadata_type *NewMethodName(std::wstring const &name, 
                                                 CallingConventions const &callingConvention, 
                                                 base_type const &retTypeName, 
                                                 std::vector<base_type const *> const &paramTypeNames) const
        {
            this_type *pMutableThis = const_cast<this_type *>(this);

            method_name_metadata_type *pMethodNameMeta = NULL;
            pMethodNameMeta = pMutableThis->MethodNameMetadataHeap().New();
            pMethodNameMeta->Init(*pMutableThis);
            pMethodNameMeta->SetName(name);
            pMethodNameMeta->SetCallingConvention(callingConvention);
            pMethodNameMeta->SetReturnTypeName(retTypeName);
            pMethodNameMeta->SetParameterTypeNames(paramTypeNames);
            return pMethodNameMeta;
        }

    private:
        friend typename module_name_metadata_type;
        friend typename type_metadata_type;
        friend typename method_name_metadata_type;

        method_name_metadata_heap_type &MethodNameMetadataHeap()
        {
            return Of<method_name_metadata_obj_tag_type>();
        }
        
        method_name_metadata_heap_type const &MethodNameMetadataHeap() const
        {
            return Of<method_name_metadata_obj_tag_type>();
        }

        void SetName(std::wstring const &name)
        {
            _ASSERTE(!m_nameInitialized);
            m_name = name;
            m_nameInitialized = true;
        }

        mdToken GetResolvedToken() const
        {
            _ASSERTE(m_tokenInitialized || m_pResolvedType != NULL || m_nameInitialized);
            return m_tokenInitialized ? 
                        m_mdt : 
                        m_pResolvedType != NULL ? 
                            m_pResolvedType->GetToken() : 
                            ResolveCore().GetToken();
        }

        void SetResolvedToken(mdToken mdt)
        {
            _ASSERTE(!m_tokenInitialized);
            m_mdt = mdt;
            m_tokenInitialized = true;
        }

        type_metadata_type const &ResolveCore() const
        {
            this_type *pMutableThis = const_cast<this_type *>(this);
            return pMutableThis->ResolveCore();
        }

        type_metadata_type &ResolveCore()
        {
            if (m_pModAsScope == NULL)
                m_pModAsScope = &Map<module_name_metadata_type>().ResolveCore();
            
            if (m_pResolvedType == NULL)
                m_pResolvedType = m_pModAsScope->GetTypeCore(*this);
            //{
            //    if (m_mdt != mdTokenNil)
            //    {
            //        m_pResolvedType = m_pModAsScope->GetTypeCore(m_mdt);
            //    }
            //    else
            //    {
            //        m_pResolvedType = m_pModAsScope->GetTypeCore(m_name);
            //    }
            //}
            return *m_pResolvedType;
        }

        void SetResolvedType(type_metadata_type &resolvedType)
        {
            _ASSERTE(m_pResolvedType == NULL);
            m_pResolvedType = &resolvedType;
        }

        // そもそも、これがこっちにあることがまずいのか・・・。
        void FillPropertiesIfNecessary() const
        {
            if (m_filled)
                return;

            this_type *pMutableThis = const_cast<this_type *>(this);

            module_metadata_type &modMeta = pMutableThis->Map<module_name_metadata_type>().ResolveCore();
            assembly_metadata_type &asmMeta = modMeta.Map<assembly_metadata_type>();

            com_meta_data_import_type &comMetaImp = asmMeta.GetCOMMetaDataImport();

            mdToken mdt = GetResolvedToken();
            if (TypeFromToken(mdt) == mdtTypeRef)
            {
                BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
            }
            else if (TypeFromToken(mdt) == mdtTypeDef)
            {
                WCHAR name[MAX_SYM_NAME] = { 0 };
                ULONG nameSize = sizeof(name);
                DWORD attr = 0;
                mdToken mdtExt = mdTokenNil;
                HRESULT hr = comMetaImp.GetTypeDefProps(mdt, name, nameSize, 
                                                        &nameSize, &attr, &mdtExt);
                if (FAILED(hr))
                    BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

                m_name = name;
                if (mdtExt != mdTokenNil)
                {
                    m_pBaseTypeName = modMeta.TypeNameMetadataHeap().New();
                    m_pBaseTypeName->Init(modMeta);
                    m_pBaseTypeName->SetResolvedToken(mdtExt);
                }
            }
            else
            {
                BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
            }


            m_filled = true;
        }

        TypeKinds const &GetKind() const
        {
            using Interfaces::MetadataSpecialValues;

            if (!m_kindInitialized)
            {
                std::wstring const &name = GetName();
                if (name == MetadataSpecialValues::TYPE_NAME_OF_VOID) m_kind = TypeKinds::TK_VOID;
                else if (name == MetadataSpecialValues::TYPE_NAME_OF_BOOLEAN) m_kind = TypeKinds::TK_BOOLEAN;
                else if (name == MetadataSpecialValues::TYPE_NAME_OF_CHAR) m_kind = TypeKinds::TK_CHAR;
                else if (name == MetadataSpecialValues::TYPE_NAME_OF_SBYTE) m_kind = TypeKinds::TK_I1;
                else if (name == MetadataSpecialValues::TYPE_NAME_OF_BYTE) m_kind = TypeKinds::TK_U1;
                else if (name == MetadataSpecialValues::TYPE_NAME_OF_INT16) m_kind = TypeKinds::TK_I2;
                else if (name == MetadataSpecialValues::TYPE_NAME_OF_UINT16) m_kind = TypeKinds::TK_U2;
                else if (name == MetadataSpecialValues::TYPE_NAME_OF_INT32) m_kind = TypeKinds::TK_I4;
                else if (name == MetadataSpecialValues::TYPE_NAME_OF_UINT32) m_kind = TypeKinds::TK_U4;
                else if (name == MetadataSpecialValues::TYPE_NAME_OF_INT64) m_kind = TypeKinds::TK_I8;
                else if (name == MetadataSpecialValues::TYPE_NAME_OF_UINT64) m_kind = TypeKinds::TK_U8;
                else if (name == MetadataSpecialValues::TYPE_NAME_OF_SINGLE) m_kind = TypeKinds::TK_R4;
                else if (name == MetadataSpecialValues::TYPE_NAME_OF_DOUBLE) m_kind = TypeKinds::TK_R8;
                else if (name == MetadataSpecialValues::TYPE_NAME_OF_STRING) m_kind = TypeKinds::TK_STRING;
                else if (name == MetadataSpecialValues::TYPE_NAME_OF_INTPTR) m_kind = TypeKinds::TK_I;
                else if (name == MetadataSpecialValues::TYPE_NAME_OF_OBJECT) m_kind = TypeKinds::TK_OBJECT;
                else
                {
                    if (name.find(MetadataSpecialValues::GENERIC_TYPE_IDENTIFIER) != std::wstring::npos)
                    {
                        m_kind = TypeKinds::TK_GENERICINST;
                    }
                    else
                    {
                        typename base_type::this_type const *pBaseTypeName = NULL;
                        pBaseTypeName = GetBaseTypeName();
                        if (pBaseTypeName != NULL && pBaseTypeName->GetName() == MetadataSpecialValues::TYPE_NAME_OF_VALUETYPE)
                        {
                            m_kind = TypeKinds::TK_VALUETYPE;
                        }
                        else
                        {
                            BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
                        }
                    }
                }

                m_kindInitialized = true;
            }
            return m_kind;
        }

        static void PushBackSignatures(std::vector<COR_SIGNATURE> &sigs, this_type const &this_)
        {
            TypeKinds const &typeKind = this_.GetKind();
            switch (typeKind.Value())
            {
                case TypeKinds::TK_VOID:
                case TypeKinds::TK_I:
                case TypeKinds::TK_OBJECT:
                case TypeKinds::TK_STRING:
                    sigs.push_back(typeKind.Value());
                    break;

                case TypeKinds::TK_VALUETYPE:
                    sigs.push_back(typeKind.Value());
                    {
                        BYTE pData[4] = { 0 };
                        ULONG length = ::CorSigCompressToken(this_.Resolve().GetToken(), pData);
                        for (BYTE const *i = pData, *i_end = i + length; i != i_end; ++i)
                            sigs.push_back(*i);
                    }
                    break;

                case TypeKinds::TK_GENERICINST:
                    sigs.push_back(typeKind.Value());
                    {
                    }
                    BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
                    break;

                default:
                    BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
                    break;
            }
        }

        mutable bool m_nameInitialized;
        mutable bool m_asmNameAsScopeInitialized;
        mutable bool m_asmAsScopeInitialized;
        mutable bool m_tokenInitialized;
        mutable bool m_kindInitialized;
        mutable std::wstring m_name;
        mutable module_metadata_type *m_pModAsScope;
        mutable module_name_metadata_type *m_pModNameAsScope;
        mutable mdToken m_mdt;
        mutable TypeKinds m_kind;
        mutable type_metadata_type *m_pResolvedType;
        mutable this_type *m_pBaseTypeName;
        mutable std::vector<COR_SIGNATURE> m_sigs;
        mutable bool m_filled;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASETYPENAMEMETADATA_HPP