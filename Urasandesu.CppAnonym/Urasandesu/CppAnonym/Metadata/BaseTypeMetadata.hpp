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

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_MODULEMETADATALABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/ModuleMetadataLabel.hpp>
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
        typedef typename TypeMetadataApiAt<TypeMetadataApiHolder, Interfaces::ModuleMetadataLabel>::type module_metadata_type;
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
            m_pModAsScope(NULL),
            m_kind(TypeKinds::TK_END),
            m_kindInitialized(false),
            m_pTypeNameMeta(NULL)
        { }

        void Init(module_metadata_type &modAsScope) const
        {
            _ASSERTE(m_pModAsScope == NULL);
            m_pModAsScope = &modAsScope;
        }

        template<class T>
        T const &Map() const { return const_cast<this_type *>(this)->Map<T>(); }

        template<class T>
        T &Map() { _ASSERTE(m_pModAsScope != NULL); return m_pModAsScope->Map<T>(); }
      
        template<>
        this_type const &Map<this_type>() const { const_cast<this_type *>(this)->Map<this_type>(); }
      
        template<>
        this_type &Map<this_type>() { return *this; }

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

                this_type *pMutableThis = const_cast<this_type *>(this);

                assembly_metadata_type &asmMeta = pMutableThis->Map<assembly_metadata_type>();
                
                com_meta_data_import_type &comMetaImp = asmMeta.GetCOMMetaDataImport();

                mdMethodDef mdmd = mdMethodDefNil;
                HRESULT hr = comMetaImp.FindMethod(GetToken(), name.c_str(), 
                                                   sb.Ptr(), sb.Size(), &mdmd);
                if (FAILED(hr))
                    BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

                method_metadata_type *pMethodMeta = NULL;
                pMethodMeta = pMutableThis->MethodMetadataHeap().New();
                pMethodMeta->Init(*pMutableThis);
                pMethodMeta->SetToken(mdmd);

                m_methodNameToIndex[pMethodName] = pMutableThis->MethodMetadataHeap().Size() - 1;

                return pMethodMeta;
            }
            else
            {
                this_type *pMutableThis = const_cast<this_type *>(this);
                
                BOOST_SCOPE_EXIT((&pMethodName)(&pMutableThis))
                {
                    type_name_metadata_type *pTypeName = NULL;
                    pTypeName = const_cast<type_name_metadata_type *>(pMutableThis->GetTypeName());
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
                this_type *pMutableThis = const_cast<this_type *>(this);

                module_metadata_type &modMeta = pMutableThis->Map<module_metadata_type>();

                m_pTypeNameMeta = modMeta.TypeNameMetadataHeap().New();
                m_pTypeNameMeta->Init(modMeta);
                m_pTypeNameMeta->SetToken(GetToken());
                m_pTypeNameMeta->SetResolvedType(*pMutableThis);
            }
            return m_pTypeNameMeta;
        }

        std::vector<this_type const *> const &GetGenericArguments() const
        {
            if (!m_genericArgsInit)
            {
                this_type *pMutableThis = const_cast<this_type *>(this);

                assembly_metadata_type &asmMeta = pMutableThis->Map<assembly_metadata_type>();
                module_metadata_type &modMeta = pMutableThis->Map<module_metadata_type>();
                
                com_meta_data_import_type &comMetaImp = asmMeta.GetCOMMetaDataImport();

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
                        this_type *pTypeMeta = modMeta.TypeMetadataHeap().New();
                        pTypeMeta->Init(modMeta);
                        pTypeMeta->SetGenericTypeDefinition(*pMutableThis);
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

                this_type *pMutableThis = const_cast<this_type *>(this);

                module_metadata_type &modMeta = pMutableThis->Map<module_metadata_type>();
                this_type *pTypeMeta = modMeta.TypeMetadataHeap().New();
                pTypeMeta->Init(modMeta);
                pTypeMeta->SetGenericTypeDefinition(*pMutableThis);
                pTypeMeta->SetGenericArguments(genericArgs);

                return pTypeMeta;
            }
            else
            {
                module_metadata_type const &modMeta = Map<module_metadata_type>();
                return modMeta.TypeMetadataHeap()[index];
            }
        }

        this_type const *GetBaseType() const
        {
            return GetTypeName()->GetBaseTypeName()->Resolve();
        }

        std::vector<COR_SIGNATURE> const &GetSignatures() const
        {
            if (m_sigs.empty())
                PushBackSignatures(m_sigs, *this);

            return m_sigs;
        }

    private: 
        friend typename assembly_metadata_type;
        friend typename module_metadata_type;
        friend typename method_metadata_type;

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

                this_type *pMutableThis = const_cast<this_type *>(this);
                pMethodMeta->Init(*pMutableThis, *m_pMetaImpApi, methodKey);

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

                this_type *pMutableThis = const_cast<this_type *>(this);
                typedef typename type_decided_by<method_metadata_type>::type MethodMetadataHeap;
                MethodMetadataHeap &heap = pMutableThis->Of<method_metadata_type>();
                // HeapProvider に BaseMethodNameMetadata 指定できないと成り立たない・・・。
                method_metadata_type *pMethodMeta = heap.New(mdmd);
                pMethodMeta->Init(*pMutableThis, *m_pMetaImpApi);

                m_methodMetas[methodKey] = mdmd;

                return pMethodMeta;
            }
            else
            {
                return GetMethodFromTokenCore(mdmd);
            }
#endif
        }

        TypeKinds const &GetKind() const
        {
            if (!m_kindInitialized)
            {
                std::wstring const &name = GetTypeName()->GetName();
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
                        this_type const *pBaseType = NULL;
                        pBaseType = GetBaseType();
                        if (pBaseType != NULL && pBaseType->GetTypeName()->GetName() == L"System.ValueType")
                        {
                            m_kind = TypeKinds::TK_VALUETYPE;
                        }
                        else
                        {
                            // NOTE: 処理がここまで進む場合、修飾子を持つかもしれないため、
                            //       とりあえず
                            // そもそも Type Kind って公開されてる必要あるの？？
                            // →Generic Type Instance と同じ考え方。あくまで、修飾情報ですよね？
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

        static void PushBackSignatures(std::vector<COR_SIGNATURE> &sigs, this_type const &this_)
        {
            // これ Type Meta に移動したほうがいいな、やっぱり・・・。
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

        mdToken m_mdt;
        mutable bool m_genericArgsInit;
        mutable std::vector<this_type const *> m_genericArgs;
        this_type *m_pGenericTypeDef;
        mutable boost::unordered_map<std::vector<this_type const *>, SIZE_T, type_vector_hash_type, type_vector_equal_to_type> m_genericArgsToIndex;
        mutable boost::unordered_map<method_name_metadata_type const *, SIZE_T, method_name_metadata_hash_type, method_name_metadata_equal_to_type> m_methodNameToIndex;
        mutable bool m_kindInitialized;

        //mutable assembly_metadata_type *m_pAsmMeta;
        mutable module_metadata_type *m_pModAsScope;
        mutable type_name_metadata_type *m_pTypeNameMeta;
        mutable ATL::CComPtr<com_meta_data_import_type> m_pMetaImpApi;
        mutable TypeKinds m_kind;
        //mutable std::wstring m_name;
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