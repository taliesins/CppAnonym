#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_BASETYPEMETADATA_HPP
#define URASANDESU_CPPANONYM_METADATA_BASETYPEMETADATA_HPP

#ifndef URASANDESU_CPPANONYM_SIMPLEHEAPPROVIDER_HPP
#include <Urasandesu/CppAnonym/SimpleHeapProvider.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_SIMPLEBLOB_HPP
#include <Urasandesu/CppAnonym/SimpleBlob.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_TYPEKINDS_H
#include <Urasandesu/CppAnonym/Metadata/TypeKinds.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_CALLINGCONVENTIONS_H
#include <Urasandesu/CppAnonym/Metadata/CallingConventions.h>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_CARTRIDGEAPISYSTEM_HPP
#include <Urasandesu/CppAnonym/Traits/CartridgeApiSystem.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_ASSEMBLYMETADATALABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/AssemblyMetadataLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_TYPEMETADATAAPIHOLDERLABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/TypeMetadataApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_METHODNAMEMETADATALABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/MethodNameMetadataLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_METHODMETADATALABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/MethodMetadataLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_TYPENAMEMETADATALABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/TypeNameMetadataLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_HASMEMBERTYPE_HPP
#include <Urasandesu/CppAnonym/Traits/HasMemberType.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_GETMEMBERTYPE_HPP
#include <Urasandesu/CppAnonym/Traits/GetMemberType.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_EQUALITYCOMPARABLE_HPP
#include <Urasandesu/CppAnonym/Traits/EqualityComparable.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_HASHCOMPUTABLE_HPP
#include <Urasandesu/CppAnonym/Traits/HashComputable.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_COLLECTIONS_ITERABLE_H
#include <Urasandesu/CppAnonym/Collections/Iterable.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASETYPEMETADATAFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseTypeMetadataFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    struct SignatureUtil
    {
        template<class SignatureHolder>
        static void PutSignatures(SimpleBlob &sb, SignatureHolder const &sigHolder)
        {
            typedef std::vector<COR_SIGNATURE>::const_iterator Iterator;
            std::vector<COR_SIGNATURE> const &sigs = sigHolder.GetSignatures();
            for (Iterator i = sigs.cbegin(), i_end = sigs.cend(); i != i_end; ++i)
                sb.Put<COR_SIGNATURE>(*i);
        }
    };

    template<class ApiCartridgesHolder, class ApiLabel>
    struct TypeMetadataApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::TypeMetadataApiHolderLabel, ApiLabel>
    {
    };
    
    template<
        class TypeMetadataApiHolder
    >    
    class BaseTypeMetadata : 
        public SimpleHeapProvider<
            boost::mpl::vector<
                ObjectTag<typename TypeMetadataApiAt<TypeMetadataApiHolder, Interfaces::MethodMetadataLabel>::type, QuickHeap>
            >
        >
    {
    public:
        typedef BaseTypeMetadata<TypeMetadataApiHolder> this_type;
        
        typedef typename TypeMetadataApiAt<TypeMetadataApiHolder, Interfaces::AssemblyMetadataLabel>::type assembly_metadata_type;
        typedef typename TypeMetadataApiAt<TypeMetadataApiHolder, IMetaDataImport2>::type com_meta_data_import_type;
        typedef typename TypeMetadataApiAt<TypeMetadataApiHolder, Interfaces::TypeNameMetadataLabel>::type type_name_metadata_type;
        typedef typename TypeMetadataApiAt<TypeMetadataApiHolder, Interfaces::MethodMetadataLabel>::type method_metadata_type;
        typedef typename TypeMetadataApiAt<TypeMetadataApiHolder, Interfaces::MethodNameMetadataLabel>::type method_name_metadata_type;
        typedef typename TypeMetadataApiAt<TypeMetadataApiHolder, Interfaces::MethodNameMetadataHashLabel>::type method_name_metadata_hash_type;
        typedef typename TypeMetadataApiAt<TypeMetadataApiHolder, Interfaces::MethodNameMetadataEqualToLabel>::type method_name_metadata_equal_to_type;

        typedef ObjectTag<method_metadata_type, QuickHeap> method_metadata_obj_tag_type;
        typedef typename type_decided_by<method_metadata_obj_tag_type>::type method_metadata_heap_type;

        CPP_ANONYM_DECLARE_HAS_MEMBER_TYPE(TypeNameMeta, method_name_metadata_heap_type);
        CPP_ANONYM_DECLARE_GET_MEMBER_TYPE(TypeNameMeta, method_name_metadata_heap_type);
        typedef typename boost::mpl::eval_if<
            CPP_ANONYM_HAS_MEMBER_TYPE(TypeNameMeta, method_name_metadata_heap_type, type_name_metadata_type), 
            CPP_ANONYM_GET_MEMBER_TYPE(TypeNameMeta, method_name_metadata_heap_type, type_name_metadata_type), 
            boost::mpl::void_
        >::type method_name_metadata_heap_type;

        typedef BaseTypeMetadataVectorHash<TypeMetadataApiHolder> type_vector_hash_type;
        typedef BaseTypeMetadataVectorEqualTo<TypeMetadataApiHolder> type_vector_equal_to_type;

        BaseTypeMetadata() : 
            m_mdt(mdTokenNil),
            m_genericArgsInit(false),
            m_pGenericTypeDef(NULL),
            m_pAsmMeta(NULL), 
            m_kind(TypeKinds::TK_END),
            m_pTypeNameMeta(NULL)
        { }

        BaseTypeMetadata(TypeKinds const &kind) : 
            m_mdt(mdTokenNil),
            m_genericArgsInit(false),
            m_pGenericTypeDef(NULL),
            m_pAsmMeta(NULL), 
            m_kind(kind),
            m_pTypeNameMeta(NULL)
        { }

        __declspec(deprecated("This method is temporarily deprecated."))
        void Init(assembly_metadata_type &asmMeta, com_meta_data_import_type &metaImpApi) const
        {
            _ASSERTE(m_pAsmMeta == NULL);
            _ASSERTE(m_pMetaImpApi.p == NULL);
            
            m_pAsmMeta = &asmMeta;
            m_pMetaImpApi = &metaImpApi;
        }

        void Init(assembly_metadata_type &asmMeta) const
        {
            // This method implementation is temporary.
            _ASSERTE(m_pAsmMeta == NULL);

            m_pAsmMeta = &asmMeta;
        }

        template<class T>
        T const *FindType() const { _ASSERTE(m_pAsmMeta != NULL); return static_cast<assembly_metadata_type const *>(m_pAsmMeta)->FindType<T>(); }

        template<class T>
        T *FindType() { _ASSERTE(m_pAsmMeta != NULL); return m_pAsmMeta->FindType<T>(); }
      
        template<>
        this_type const *FindType<this_type>() const { return this; }
      
        template<>
        this_type *FindType<this_type>() { return this; }

#if 0
        inline TypeKinds const &GetKind() const
        {
            if (!m_kindInitialized)
            {
                std::wstring const &name = GetName();
                if (name == std::wstring(L"System.Void"))
                {
                    m_kind = TypeKinds::TK_VOID;
                }
                else if (name == std::wstring(L"System.Boolean"))
                {
                    m_kind = TypeKinds::TK_BOOLEAN;
                }
                else if (name == std::wstring(L"System.Char"))
                {
                    m_kind = TypeKinds::TK_CHAR;
                }
                else if (name == std::wstring(L"System.SByte"))
                {
                    m_kind = TypeKinds::TK_I1;
                }
                else if (name == std::wstring(L"System.Byte"))
                {
                    m_kind = TypeKinds::TK_U1;
                }
                else if (name == std::wstring(L"System.Int16"))
                {
                    m_kind = TypeKinds::TK_I2;
                }
                else if (name == std::wstring(L"System.UInt16"))
                {
                    m_kind = TypeKinds::TK_U2;
                }
                //TK_I4 = ELEMENT_TYPE_I4, 
                //TK_U4 = ELEMENT_TYPE_U4, 
                //TK_I8 = ELEMENT_TYPE_I8, 
                //TK_U8 = ELEMENT_TYPE_U8, 
                //TK_R4 = ELEMENT_TYPE_R4, 
                //TK_R8 = ELEMENT_TYPE_R8, 
                //TK_STRING = ELEMENT_TYPE_STRING, 
                //TK_PTR = ELEMENT_TYPE_PTR, 
                //TK_BYREF = ELEMENT_TYPE_BYREF, 
                //TK_VALUETYPE = ELEMENT_TYPE_VALUETYPE, 
                //TK_CLASS = ELEMENT_TYPE_CLASS, 
                //TK_VAR = ELEMENT_TYPE_VAR, 
                //TK_ARRAY = ELEMENT_TYPE_ARRAY, 
                //TK_GENERICINST = ELEMENT_TYPE_GENERICINST, 
                //TK_TYPEDBYREF = ELEMENT_TYPE_TYPEDBYREF, 
                //TK_I = ELEMENT_TYPE_I, 
                //TK_U = ELEMENT_TYPE_U, 
                //TK_FNPTR = ELEMENT_TYPE_FNPTR, 
                //TK_OBJECT = ELEMENT_TYPE_OBJECT, 
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
                //TK_UNREACHED
                }
                m_kindInitialized = true;
            }
            return m_kind;
        }

        inline void SetKind(TypeKinds const &kind)
        {
            _ASSERTE(!m_kindInitialized);
            m_kind = kind;
            m_kindInitialized = true;
        }
#endif

        inline mdToken GetToken() const
        {
            if (IsGenericType() && !IsGenericTypeDefinition())
            {
                _ASSERTE(m_pGenericTypeDef != NULL);
                return m_pGenericTypeDef->GetToken();
            }
            else
            {
                return m_mdt;
            }
        }

#if 0
        inline std::wstring const &GetName() const
        {
            return m_name;
        }

        inline void SetName(std::wstring const &name)
        {
            m_name = name;
        }
#endif

        method_metadata_type const *GetMethod(std::wstring const &name, 
                                              CallingConventions const &callingConvention, 
                                              this_type const &retType, 
                                              std::vector<this_type const *> const &paramTypes) const
        {
            typedef std::vector<this_type const *>::const_iterator TypeIterator;

            type_name_metadata_type const *pRetTypeName = NULL;
            pRetTypeName = retType.GetTypeName();
            std::vector<type_name_metadata_type const *> paramTypeNames;
            paramTypeNames.reserve(paramTypes.size());
            for (TypeIterator i = paramTypes.cbegin(), i_end = paramTypes.cend(); i != i_end; ++i)
                paramTypeNames.push_back((*i)->GetTypeName());
            method_name_metadata_type *pMethodName = NULL;
            pMethodName = NewMethodName(name, callingConvention, *pRetTypeName, paramTypeNames);

            if (m_methodNameToIndex.find(pMethodName) == m_methodNameToIndex.end())
            {
                m_methodNameToIndex[pMethodName] = MAXULONG_PTR;
            }
            
            SIZE_T index = m_methodNameToIndex[pMethodName];
            if (index == MAXULONG_PTR)
            {
                SimpleBlob sb;
                SignatureUtil::PutSignatures(sb, callingConvention);
                sb.Put<COR_SIGNATURE>(paramTypes.size());
                SignatureUtil::PutSignatures(sb, retType);
                for (TypeIterator i = paramTypes.cbegin(), i_end = paramTypes.cend(); i != i_end; ++i)
                    SignatureUtil::PutSignatures(sb, **i);

                //// Call Convention
                //switch (callingConvention.Value())
                //{
                //    case CallingConventions::CC_STANDARD:
                //        sb.Put<COR_SIGNATURE>(IMAGE_CEE_CS_CALLCONV_DEFAULT);
                //        break;

                //    case CallingConventions::CC_HAS_THIS:
                //        sb.Put<COR_SIGNATURE>(IMAGE_CEE_CS_CALLCONV_HASTHIS);
                //        break;

                //    default:
                //        BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
                //        break;
                //}

                //// ParamCount
                //sb.Put<COR_SIGNATURE>(paramTypeNames.size());
                
                //// RetType
                //PutSignatures(sb, retType);

                //// ParamType
                //for (TypeIterator i = paramTypes.cbegin(), i_end = paramTypes.cend(); i != i_end; ++i)
                //    PutSignatures(sb, **i);

                this_type *mutableThis = const_cast<this_type *>(this);

                assembly_metadata_type *pAsmMeta = NULL;
                pAsmMeta = mutableThis->FindType<assembly_metadata_type>();
                
                com_meta_data_import_type &comMetaImp = pAsmMeta->GetCOMMetaDataImport();

                mdMethodDef mdmd = mdMethodDefNil;
                HRESULT hr = comMetaImp.FindMethod(GetToken(), name.c_str(), 
                                                   sb.Ptr(), sb.Size(), &mdmd);
                if (FAILED(hr))
                    BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

                method_metadata_type *pMethodMeta = NULL;
                pMethodMeta = mutableThis->MethodMetadataHeap().New();
                pMethodMeta->Init(*mutableThis);
                pMethodMeta->SetToken(mdmd);

                m_methodNameToIndex[pMethodName] = mutableThis->MethodMetadataHeap().Size() - 1;

                return pMethodMeta;
            }
            else
            {
                this_type *mutableThis = const_cast<this_type *>(this);
                
                BOOST_SCOPE_EXIT((&pMethodName)(&mutableThis))
                {
                    type_name_metadata_type *pTypeName = NULL;
                    pTypeName = const_cast<type_name_metadata_type *>(mutableThis->GetTypeName());
                    pTypeName->MethodNameMetadataHeap().DeleteLast();
                }
                BOOST_SCOPE_EXIT_END

                return MethodMetadataHeap()[index];
            }
        }

        method_name_metadata_type *NewMethodName(std::wstring const &name, 
                                                 CallingConventions const &callingConvention, 
                                                 type_name_metadata_type const &retTypeName, 
                                                 std::vector<type_name_metadata_type const *> const &paramTypeNames) const
        {
            return GetTypeName()->NewMethodName(name, callingConvention, retTypeName, paramTypeNames);
        }

        type_name_metadata_type const *GetTypeName() const
        {
            if (m_pTypeNameMeta == NULL)
            {
                this_type *mutableThis = const_cast<this_type *>(this);

                assembly_metadata_type *pAsmMeta = NULL;
                pAsmMeta = mutableThis->FindType<assembly_metadata_type>();

                m_pTypeNameMeta = pAsmMeta->TypeNameMetadataHeap().New();
                m_pTypeNameMeta->Init(*pAsmMeta, GetToken());
                m_pTypeNameMeta->SetResolvedType(*mutableThis);
            }
            return m_pTypeNameMeta;
        }

        std::vector<this_type const *> const &GetGenericArguments() const
        {
            if (!m_genericArgsInit)
            {
                this_type *mutableThis = const_cast<this_type *>(this);

                assembly_metadata_type *pAsmMeta = NULL;
                pAsmMeta = mutableThis->FindType<assembly_metadata_type>();
                
                com_meta_data_import_type &comMetaImp = pAsmMeta->GetCOMMetaDataImport();

                HCORENUM hEnum = NULL;
                    BOOST_SCOPE_EXIT((&hEnum)(&comMetaImp))
                    {
                        if (hEnum)
                            comMetaImp.CloseEnum(hEnum);
                    }
                    BOOST_SCOPE_EXIT_END
                boost::array<mdGenericParam, 16> m_mdgps;
                ULONG count = 0;
                HRESULT hr = E_FAIL;
                do
                {
                    hr = comMetaImp.EnumGenericParams(&hEnum, m_mdt, m_mdgps.c_array(), m_mdgps.size(), &count);
                    if (FAILED(hr))
                        BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

                    m_genericArgs.reserve(m_genericArgs.size() + count);
                    for (UINT i = 0; i < count; ++i)
                    {
                        this_type *pTypeMeta = pAsmMeta->TypeMetadataHeap().New();
                        pTypeMeta->Init(*pAsmMeta);
                        pTypeMeta->SetGenericTypeDefinition(*mutableThis);
                        pTypeMeta->SetToken(m_mdgps[i]);
                        m_genericArgs.push_back(pTypeMeta);
                    }
                } while (0 < count);

                m_genericArgsInit = true;
            }
            return m_genericArgs;
        }

        bool IsGenericParameter() const
        {
            return TypeFromToken(GetToken()) == mdtGenericParam;
        }

        bool IsGenericType() const
        {
            return !GetGenericArguments().empty();
        }

        bool IsGenericTypeDefinition() const
        {
            return IsGenericType() && m_pGenericTypeDef == NULL;
        }

        this_type const *MakeGenericType(std::vector<this_type const *> const &genericArgs) const
        {
            if (m_genericArgsToIndex.find(genericArgs) == m_genericArgsToIndex.end())
            {
                m_genericArgsToIndex[genericArgs] = MAXULONG_PTR;
            }

            SIZE_T index = m_genericArgsToIndex[genericArgs];
            if (index == MAXULONG_PTR)
            {
                _ASSERTE(GetGenericArguments().size() == genericArgs.size());

                this_type *mutableThis = const_cast<this_type *>(this);

                assembly_metadata_type *pAsmMeta = NULL;
                pAsmMeta = mutableThis->FindType<assembly_metadata_type>();
                this_type *pTypeMeta = pAsmMeta->TypeMetadataHeap().New();
                pTypeMeta->Init(*pAsmMeta);
                pTypeMeta->SetGenericTypeDefinition(*mutableThis);
                pTypeMeta->SetGenericArguments(genericArgs);

                return pTypeMeta;
            }
            else
            {
                assembly_metadata_type const *pAsmMeta = NULL;
                pAsmMeta = FindType<assembly_metadata_type>();
                return pAsmMeta->TypeMetadataHeap()[index];
            }
        }

        this_type const *GetBaseType() const
        {
            return GetTypeName()->GetBaseTypeName()->Resolve();
        }

        std::vector<COR_SIGNATURE> const &GetSignatures() const
        {
            return GetTypeName()->GetSignatures();
    //        if (m_sigs.empty())
    //        {
    //            if (IsGenericType() && !IsGenericTypeDefinition())
    //            {
    //                BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
    //            }
    //            else
    //            {
    //                this_type *mutableThis = const_cast<this_type *>(this);

    //                assembly_metadata_type *pAsmMeta = NULL;
    //                pAsmMeta = mutableThis->FindType<assembly_metadata_type>();

    //                com_meta_data_import_type &comMetaImp = pAsmMeta->GetCOMMetaDataImport();

    //                PCCOR_SIGNATURE sig = NULL;
    //                ULONG sigSize = 0;
    //                HRESULT hr = comMetaImp.GetSigFromToken(m_mdt, &sig, &sigSize);
    //                if (FAILED(hr))
    //                    BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
    //                
    //                m_sigs.reserve(sigSize);
    //                for (PCCOR_SIGNATURE i = sig, i_end = sig + sigSize; i != i_end; ++i)
    //                    m_sigs.push_back(*i);        
    //            }

    ////STDMETHOD(GetSigFromToken)(             // S_OK or error.
    ////    mdSignature mdSig,                  // [IN] Signature token.
    ////    PCCOR_SIGNATURE *ppvSig,            // [OUT] return pointer to token.
    ////    ULONG       *pcbSig) PURE;          // [OUT] return size of signature.
    //        }

    //        return m_sigs;
        }

    private: 
        template<
            class AssemblyMetadataApiHolder
        >    
        friend class BaseAssemblyMetadata;

        template<
            class MethodMetadataApiHolder
        >
        friend class BaseMethodMetadata;

        method_metadata_heap_type &MethodMetadataHeap()
        {
            return Of<method_metadata_obj_tag_type>();
        }
        
        method_metadata_heap_type const &MethodMetadataHeap() const
        {
            return Of<method_metadata_obj_tag_type>();
        }

        method_name_metadata_heap_type &MethodNameMetadataHeap()
        {
            return const_cast<type_name_metadata_type *>(GetTypeName())->MethodNameMetadataHeap();
        }
        
        method_name_metadata_heap_type const &MethodNameMetadataHeap() const
        {
            return GetTypeName()->MethodNameMetadataHeap();
        }

        void SetToken(mdToken mdt)
        {
            _ASSERTE(m_mdt == mdTokenNil);
            _ASSERTE(mdt != mdTokenNil);

            m_mdt = mdt;
        }

        void SetGenericTypeDefinition(this_type &genericTypeDef)
        {
            _ASSERTE(m_pGenericTypeDef == NULL);
            
            m_pGenericTypeDef = &genericTypeDef;
        }

        void SetGenericArguments(std::vector<this_type const *> const &genericArgs)
        {
            m_genericArgs = genericArgs;
            m_genericArgsInit = true;
        }

        method_metadata_type const *GetMethodFromMethodKey(method_name_metadata_type const &methodKey) const
        {
            typedef typename type_decided_by<method_metadata_type>::type MethodMetadataHeap;
            MethodMetadataHeap const &heap = Of<method_metadata_type>();
            if (heap.Exists(methodKey))
            {
                return heap.Get(methodKey);
            }
            else
            {
                MethodMetadataHeap &mutableHeap = const_cast<MethodMetadataHeap &>(heap);
                method_metadata_type *pMethodMeta = mutableHeap.New(methodKey);

                this_type *mutableThis = const_cast<this_type *>(this);
                pMethodMeta->Init(*mutableThis, *m_pMetaImpApi, methodKey);

                return pMethodMeta;
            }
#if 0
            //_ASSERTE(m_pMetaImpApi.p != NULL);

            if (m_methodMetas.find(methodKey) == m_methodMetas.end())
            {
                m_methodMetas[methodKey] = mdMethodDefNil;
            }

            mdMethodDef mdmd = m_methodMetas[methodKey];
            if (mdmd == mdMethodDefNil)
            {
                //SimpleBlob sb;

                //// Call Convention
                //switch (methodKey.m_callConvention.Value())
                //{
                //    case CallingConventions::CC_STANDARD:
                //        sb.Put<COR_SIGNATURE>(IMAGE_CEE_CS_CALLCONV_DEFAULT);
                //        break;

                //    case CallingConventions::CC_HAS_THIS:
                //        sb.Put<COR_SIGNATURE>(IMAGE_CEE_CS_CALLCONV_HASTHIS);
                //        break;

                //    default:
                //        BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
                //        break;
                //}

                //// ParamCount
                //sb.Put<COR_SIGNATURE>(methodKey.m_paramTypes.size());

                //typedef std::vector<COR_SIGNATURE>::const_iterator SigConstIterator;
                //
                //// RetType
                //PutSignatures(sb, *methodKey.m_pRetType);

                //// ParamType
                //typedef std::vector<this_type const *>::const_iterator ParamTypesConstIterator;
                //for (ParamTypesConstIterator i = methodKey.m_paramTypes.begin(), 
                //                             i_end = methodKey.m_paramTypes.end(); 
                //     i != i_end; 
                //     ++i)
                //{
                //    PutSignatures(sb, **i);
                //}

                //HRESULT hr = m_pMetaImpApi->FindMethod(GetToken(), methodKey.m_name.c_str(), 
                //                                       sb.Ptr(), sb.Size(), &mdmd);
                //if (FAILED(hr))
                //    BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

                this_type *mutableThis = const_cast<this_type *>(this);
                typedef typename type_decided_by<method_metadata_type>::type MethodMetadataHeap;
                MethodMetadataHeap &heap = mutableThis->Of<method_metadata_type>();
                // HeapProvider に BaseMethodNameMetadata 指定できないと成り立たない・・・。
                method_metadata_type *pMethodMeta = heap.New(mdmd);
                pMethodMeta->Init(*mutableThis, *m_pMetaImpApi);

                m_methodMetas[methodKey] = mdmd;

                return pMethodMeta;
            }
            else
            {
                return GetMethodFromTokenCore(mdmd);
            }
#endif
        }

        //method_metadata_type const *GetMethodFromTokenCore(mdMethodDef mdmd) const
        //{
        //    typedef typename type_decided_by<method_metadata_type>::type MethodMetadataHeap;
        //    MethodMetadataHeap const &heap = Of<method_metadata_type>();
        //    return heap.Get(mdmd);
        //}

        //static void PutSignatures(SimpleBlob &sb, this_type const &typeMeta)
        //{
        //    typedef std::vector<COR_SIGNATURE>::const_iterator SigIterator;
        //    std::vector<COR_SIGNATURE> const &sigs = typeMeta.GetSignatures();
        //    for (SigIterator i = sigs.cbegin(), i_end = sigs.cend(); i != i_end; ++i)
        //    {
        //        sb.Put<COR_SIGNATURE>(*i);
        //    }
        //}

        //static void PushBackSignatures(std::vector<COR_SIGNATURE> &sigs, this_type const &this_)
        //{
        //    TypeKinds const &typeKind = this_.GetKind();
        //    switch (typeKind.Value())
        //    {
        //        case TypeKinds::TK_VOID:
        //        case TypeKinds::TK_I:
        //        case TypeKinds::TK_OBJECT:
        //            sigs.push_back(typeKind.Value());
        //            break;

        //        case TypeKinds::TK_VALUETYPE:
        //            sigs.push_back(typeKind.Value());
        //            {
        //                BYTE pData[4] = { 0 };
        //                ULONG length = ::CorSigCompressToken(this_.GetToken(), pData);
        //                for (BYTE const *i = pData, *i_end = i + length; i != i_end; ++i)
        //                    sigs.push_back(*i);
        //            }
        //            break;
        //        
        //        default:
        //            BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
        //            break;
        //    }
        //}

        mdToken m_mdt;
        mutable bool m_genericArgsInit;
        mutable std::vector<this_type const *> m_genericArgs;
        this_type *m_pGenericTypeDef;
        mutable boost::unordered_map<std::vector<this_type const *>, SIZE_T, type_vector_hash_type, type_vector_equal_to_type> m_genericArgsToIndex;
        mutable boost::unordered_map<method_name_metadata_type const *, SIZE_T, method_name_metadata_hash_type, method_name_metadata_equal_to_type> m_methodNameToIndex;
        
        mutable assembly_metadata_type *m_pAsmMeta;
        mutable type_name_metadata_type *m_pTypeNameMeta;
        mutable ATL::CComPtr<com_meta_data_import_type> m_pMetaImpApi;
        TypeKinds m_kind;
        mutable std::wstring m_name;
        //typedef Utilities::Hash<method_name_metadata_type> method_key_hash;
        //typedef Utilities::EqualTo<method_name_metadata_type, method_name_metadata_type> method_key_equal_to;
        //mutable boost::unordered_map<method_name_metadata_type, mdMethodDef, method_key_hash, method_key_equal_to> m_methodMetas;
        mutable std::vector<COR_SIGNATURE> m_sigs;
    };

    
    
    
    
    template<
        class TypeMetadataApiHolder
    >    
    class BaseTypeMetadataVectorHash : 
        Traits::HashComputable<std::vector<BaseTypeMetadata<TypeMetadataApiHolder> const *> >
    {
    public:
        result_type operator()(param_type v) const
        {
            return Collections::SequenceHashValue(v.cbegin(), v.cend());
        }
    };

    
    
    
    
    template<
        class TypeMetadataApiHolder
    >    
    class BaseTypeMetadataVectorEqualTo : 
        Traits::EqualityComparable<std::vector<BaseTypeMetadata<TypeMetadataApiHolder> const *> >
    {
    public:
        result_type operator()(param_type x, param_type y) const
        {
            return Collections::SequenceEqual(x.cbegin(), x.cend(), y.cbegin(), y.cend());
        }
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASETYPEMETADATA_HPP