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
        public SimpleHeapProvider<
            boost::mpl::vector<
                ObjectTag<typename TypeNameMetadataApiAt<TypeNameMetadataApiHolder, Interfaces::MethodNameMetadataLabel>::type, QuickHeap>
            >
        >
    {
    public:
        typedef BaseTypeNameMetadata<TypeNameMetadataApiHolder> this_type;

        typedef typename TypeNameMetadataApiAt<TypeNameMetadataApiHolder, Interfaces::AssemblyMetadataLabel>::type assembly_metadata_type;
        typedef typename TypeNameMetadataApiAt<TypeNameMetadataApiHolder, Interfaces::AssemblyNameMetadataLabel>::type assembly_name_metadata_type;
        typedef typename TypeNameMetadataApiAt<TypeNameMetadataApiHolder, Interfaces::TypeMetadataLabel>::type type_metadata_type;
        typedef typename TypeNameMetadataApiAt<TypeNameMetadataApiHolder, Interfaces::MethodNameMetadataLabel>::type method_name_metadata_type;
        typedef typename TypeNameMetadataApiAt<TypeNameMetadataApiHolder, IMetaDataImport2>::type com_meta_data_import_type;

        typedef ObjectTag<method_name_metadata_type, QuickHeap> method_name_metadata_obj_tag_type;
        typedef typename type_decided_by<method_name_metadata_obj_tag_type>::type method_name_metadata_heap_type;

        BaseTypeNameMetadata() : 
            m_kindInitialized(false),
            m_pAsmNameAsScope(NULL), 
            m_pAsmAsScope(NULL), 
            m_pResolvedType(NULL), 
            m_mdt(mdTokenNil), 
            m_pBaseTypeName(NULL), 
            m_initialized(false), 
            m_filled(false)
        { }

        void Init(std::wstring const &name, TypeKinds const &kind, assembly_name_metadata_type &asmNameAsScope) const
        {
            _ASSERTE(!m_initialized);
            m_name = name;
            m_kind = kind;
            m_pAsmNameAsScope = &asmNameAsScope;
            m_initialized = true;
        }

        void Init(assembly_metadata_type &asmAsScope, mdToken mdt) const
        {
            _ASSERTE(!m_initialized);
            m_pAsmAsScope = &asmAsScope;
            m_mdt = mdt;
            m_initialized = true;
        }

        template<class T>
        T const *FindType() const { return GetResolutionScope().FindType<T>(); }

        template<class T>
        T *FindType() { return const_cast<assembly_name_metadata_type &>(GetResolutionScope()).FindType<T>(); }
      
        template<>
        this_type const *FindType<this_type>() const { return this; }
      
        template<>
        this_type *FindType<this_type>() { return this; }

        std::wstring const &GetName() const
        {
            FillPropertiesIfNecessary();
            //if (m_name.empty())
            //{
            //    this_type *mutableThis = const_cast<this_type *>(this);

            //    type_metadata_type &resolvedType = mutableThis->GetResolvedType();
            //    assembly_metadata_type *pAsmMeta = NULL;
            //    pAsmMeta = resolvedType.FindType<assembly_metadata_type>();

            //    com_meta_data_import_type &comMetaImp = pAsmMeta->GetCOMMetaDataImport();

            //    WCHAR name[MAX_SYM_NAME] = { 0 };
            //    ULONG nameSize = sizeof(name);
            //    DWORD attr = 0;
            //    mdToken mdtExt = mdTokenNil;
            //    HRESULT hr = comMetaImp.GetTypeDefProps(GetToken(), name, nameSize, 
            //                                            &nameSize, &attr, &mdtExt);
            //    if (FAILED(hr))
            //        BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

            //    m_name = name;
            //}
            return m_name;
        }

        //void SetName(std::wstring const &name)
        //{
        //    _ASSERTE(!m_initialized);
        //    //_ASSERTE(m_name.empty());
        //    //_ASSERTE(!name.empty());
        //    m_name = name;
        //    m_initialized = true;
        //}

        mdToken GetToken() const
        {
            return m_mdt;
        }

        TypeKinds const &GetKind() const
        {
            if (!m_kindInitialized)
            {
                std::wstring const &name = GetName();
                if (name == L"System.Void") m_kind = TypeKinds::TK_VOID;
                else if (name == L"System.Boolean") m_kind = TypeKinds::TK_BOOLEAN;
                else if (name == L"System.Char") m_kind = TypeKinds::TK_CHAR;
                else if (name == L"System.SByte") m_kind = TypeKinds::TK_I1;
                else if (name == L"System.Byte") m_kind = TypeKinds::TK_U1;
                else if (name == L"System.Int16") m_kind = TypeKinds::TK_I2;
                else if (name == L"System.UInt16") m_kind = TypeKinds::TK_U2;
                else if (name == L"System.Int32") m_kind = TypeKinds::TK_I4;
                else if (name == L"System.UInt32") m_kind = TypeKinds::TK_U4;
                else if (name == L"System.Int64") m_kind = TypeKinds::TK_I8;
                else if (name == L"System.UInt64") m_kind = TypeKinds::TK_U8;
                else if (name == L"System.Single") m_kind = TypeKinds::TK_R4;
                else if (name == L"System.Double") m_kind = TypeKinds::TK_R8;
                else if (name == L"System.String") m_kind = TypeKinds::TK_STRING;
                else if (name == L"System.IntPtr") m_kind = TypeKinds::TK_I;
                else if (name == L"System.Object") m_kind = TypeKinds::TK_OBJECT;
                else
                {
                    if (name.find(L"`") != std::wstring::npos)
                    {
                        m_kind = TypeKinds::TK_GENERICINST;
                    }
                    else
                    {
                        type_metadata_type const *pBaseType = NULL;
                        pBaseType = Resolve()->GetBaseType();
                        if (pBaseType != NULL && pBaseType->GetTypeName()->GetName() == L"System.ValueType")
                        {
                            m_kind = TypeKinds::TK_VALUETYPE;
                        }
                        else
                        {
                            //TK_PTR = ELEMENT_TYPE_PTR, 
                            //TK_BYREF = ELEMENT_TYPE_BYREF, 
                            //TK_CLASS = ELEMENT_TYPE_CLASS, 
                            //TK_VAR = ELEMENT_TYPE_VAR, 
                            //TK_ARRAY = ELEMENT_TYPE_ARRAY, 
                            //TK_TYPEDBYREF = ELEMENT_TYPE_TYPEDBYREF, 
                            //TK_U = ELEMENT_TYPE_U, 
                            //TK_FNPTR = ELEMENT_TYPE_FNPTR, 
                            //TK_SZARRAY = ELEMENT_TYPE_SZARRAY, 
                            //TK_MVAR = ELEMENT_TYPE_MVAR, 
                            //TK_CMOD_REQD = ELEMENT_TYPE_CMOD_REQD, 
                            //TK_CMOD_OPT = ELEMENT_TYPE_CMOD_OPT, 
                            //TK_INTERNAL = ELEMENT_TYPE_INTERNAL, 
                            //TK_MAX = ELEMENT_TYPE_MAX, 
                            //TK_MODIFIER = ELEMENT_TYPE_MODIFIER, 
                            //TK_SENTINEL = ELEMENT_TYPE_SENTINEL, 
                            //TK_PINNED = ELEMENT_TYPE_PINNED, 
                            //TK_R4_HFA = ELEMENT_TYPE_R4_HFA, 
                            //TK_R8_HFA = ELEMENT_TYPE_R8_HFA, 
                            BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
                        }
                    }
                }

                m_kindInitialized = true;
            }
            return m_kind;
        }

        //void SetKind(TypeKinds const &kind)
        //{
        //    _ASSERTE(!m_kindInitialized);
        //    m_kind = kind;
        //    m_kindInitialized = true;
        //}

        assembly_name_metadata_type const &GetResolutionScope() const
        {
            _ASSERTE(m_pAsmNameAsScope != NULL || m_pAsmAsScope != NULL);
            
            if (m_pAsmNameAsScope != NULL)
            {
                return *m_pAsmNameAsScope;
            }
            else
            {
                return *m_pAsmAsScope->GetAssemblyName();
            }
        }

        //void SetResolutionScope(assembly_name_metadata_type &asmNameAsScope)
        //{
        //    m_pAsmNameAsScope = &asmNameAsScope;
        //}

        //void SetResolutionScope(assembly_metadata_type &asmAsScope)
        //{
        //    m_pAsmAsScope = &asmAsScope;
        //}

        std::vector<COR_SIGNATURE> const &GetSignatures() const
        {
            if (m_sigs.empty())
                PushBackSignatures(m_sigs, *this);

            return m_sigs;
        }

        this_type const *GetBaseTypeName() const
        {
            FillPropertiesIfNecessary();
            return m_pBaseTypeName;
        }

        method_name_metadata_type *NewMethodName(std::wstring const &name, 
                                                 CallingConventions const &callingConvention, 
                                                 this_type const &retTypeName, 
                                                 std::vector<this_type const *> const &paramTypeNames) const
        {
            this_type *mutableThis = const_cast<this_type *>(this);

            method_name_metadata_type *pMethodNameMeta = NULL;
            pMethodNameMeta = mutableThis->MethodNameMetadataHeap().New();
            pMethodNameMeta->SetName(name);
            pMethodNameMeta->SetCallingConvention(callingConvention);
            pMethodNameMeta->SetReturnTypeName(retTypeName);
            pMethodNameMeta->SetParameterTypeNames(paramTypeNames);
            pMethodNameMeta->SetResolutionScope(*mutableThis);
            return pMethodNameMeta;
        }

        type_metadata_type const *Resolve() const
        {
            // This method implementation is temporary.
            if (m_pAsmAsScope == NULL)
                m_pAsmAsScope = GetResolutionScope().Resolve();
            
            if (m_pResolvedType == NULL)
            {
                if (m_mdt != mdTokenNil)
                {
                    m_pResolvedType = m_pAsmAsScope->GetType(m_mdt);
                }
                else
                {
                    m_pResolvedType = m_pAsmAsScope->GetType(m_name);
                }
            }
            return m_pResolvedType;
        }

    private:
        template<
            class TypeMetadataApiHolder
        >    
        friend class BaseTypeMetadata;

        method_name_metadata_heap_type &MethodNameMetadataHeap()
        {
            return Of<method_name_metadata_obj_tag_type>();
        }
        
        method_name_metadata_heap_type const &MethodNameMetadataHeap() const
        {
            return Of<method_name_metadata_obj_tag_type>();
        }

        void SetToken(mdToken mdt)
        {
            m_mdt = mdt;
        }

        type_metadata_type *Resolve()
        {
            this_type const *immutableThis = static_cast<this_type const *>(this);
            return const_cast<type_metadata_type *>(immutableThis->Resolve());
            //// This method implementation is temporary.
            //if (m_pAsmAsScope == NULL)
            //    m_pAsmAsScope = GetResolutionScope().Resolve();
            //
            //if (m_pResolvedType == NULL)
            //    m_pResolvedType = m_pAsmAsScope->GetType(m_name);
            //return m_pResolvedType;
        }

        //type_metadata_type const &GetResolvedType() const
        //{
        //    _ASSERTE(m_pResolvedType != NULL);
        //    return *m_pResolvedType;
        //}

        //type_metadata_type &GetResolvedType()
        //{
        //    this_type const *immutableThis = static_cast<this_type const *>(this);
        //    type_metadata_type const &typeMeta = immutableThis->GetResolvedType();
        //    return const_cast<type_metadata_type &>(typeMeta);
        //}

        void SetResolvedType(type_metadata_type &resolvedType)
        {
            _ASSERTE(m_pResolvedType == NULL);
            m_pResolvedType = &resolvedType;
        }

        static void PushBackSignatures(std::vector<COR_SIGNATURE> &sigs, this_type const &this_)
        {
            TypeKinds const &typeKind = this_.GetKind();
            switch (typeKind.Value())
            {
                case TypeKinds::TK_VOID:
                case TypeKinds::TK_I:
                case TypeKinds::TK_OBJECT:
                    sigs.push_back(typeKind.Value());
                    break;

                case TypeKinds::TK_VALUETYPE:
                    sigs.push_back(typeKind.Value());
                    {
                        BYTE pData[4] = { 0 };
                        ULONG length = ::CorSigCompressToken(this_.GetToken(), pData);
                        for (BYTE const *i = pData, *i_end = i + length; i != i_end; ++i)
                            sigs.push_back(*i);
                    }
                    break;
                
                default:
                    BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
                    break;
            }
        }

        void FillPropertiesIfNecessary() const
        {
            if (m_filled)
                return;

            this_type *mutableThis = const_cast<this_type *>(this);

            type_metadata_type *pResolvedType = mutableThis->Resolve();
            assembly_metadata_type *pAsmMeta = NULL;
            pAsmMeta = pResolvedType->FindType<assembly_metadata_type>();

            com_meta_data_import_type &comMetaImp = pAsmMeta->GetCOMMetaDataImport();

            mdToken mdt = GetToken();
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
                    m_pBaseTypeName = pAsmMeta->TypeNameMetadataHeap().New();
                    m_pBaseTypeName->Init(*pAsmMeta, mdtExt);
                }
            }
            else
            {
                BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
            }


            m_filled = true;
        }

        mutable std::wstring m_name;
        mutable TypeKinds m_kind;
        mutable bool m_kindInitialized;
        mutable assembly_name_metadata_type *m_pAsmNameAsScope;
        mutable mdToken m_mdt;
        mutable assembly_metadata_type const *m_pAsmAsScope;
        mutable type_metadata_type const *m_pResolvedType;
        mutable this_type *m_pBaseTypeName;
        mutable std::vector<COR_SIGNATURE> m_sigs;
        mutable bool m_initialized;
        mutable bool m_filled;
    };




    
    template<
        class TypeNameMetadataApiHolder
    >    
    class BaseTypeNameMetadataHash : 
        Traits::HashComputable<BaseTypeNameMetadata<TypeNameMetadataApiHolder> const *>
    {
    public:
        typedef typename TypeNameMetadataApiAt<TypeNameMetadataApiHolder, Interfaces::AssemblyNameMetadataHashLabel>::type assembly_name_metadata_hash_type;

        result_type operator()(param_type v) const
        {
            using namespace boost;

            _ASSERTE(v != NULL);

            std::size_t seed = 0;
            hash_combine(seed, hash_value(v->GetName()));
            hash_combine(seed, v->GetKind().Value());
            hash_combine(seed, assembly_name_metadata_hash_type()(&v->GetResolutionScope()));
            return seed;
        }
    };

    
    
    
    
    template<
        class TypeNameMetadataApiHolder
    >    
    class BaseTypeNameMetadataEqualTo : 
        Traits::EqualityComparable<BaseTypeNameMetadata<TypeNameMetadataApiHolder> const *>
    {
    public:
        typedef typename TypeNameMetadataApiAt<TypeNameMetadataApiHolder, Interfaces::AssemblyNameMetadataEqualToLabel>::type assembly_name_metadata_equal_to_type;

        result_type operator()(param_type x, param_type y) const
        {
            _ASSERTE(x != NULL && y != NULL);

            return x->GetName() == y->GetName() &&
                   x->GetKind() == y->GetKind() &&
                   assembly_name_metadata_equal_to_type()(&x->GetResolutionScope(), &y->GetResolutionScope());
        }
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASETYPENAMEMETADATA_HPP