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
        public TypeMetadataApiAt<TypeMetadataApiHolder, Interfaces::ITypeMetadataLabel>::type,
        public SimpleHeapProvider<
            boost::mpl::vector<
                ObjectTag<typename TypeMetadataApiAt<TypeMetadataApiHolder, Interfaces::MethodMetadataLabel>::type, QuickHeap>
            >
        >
    {
    public:
        typedef BaseTypeMetadata<TypeMetadataApiHolder> this_type;
        typedef typename TypeMetadataApiAt<TypeMetadataApiHolder, Interfaces::ITypeMetadataLabel>::type base_type;
        
        typedef typename TypeMetadataApiAt<TypeMetadataApiHolder, Interfaces::AssemblyMetadataLabel>::type assembly_metadata_type;
        typedef typename TypeMetadataApiAt<TypeMetadataApiHolder, Interfaces::ModuleMetadataLabel>::type module_metadata_type;
        typedef typename TypeMetadataApiAt<TypeMetadataApiHolder, IMetaDataImport2>::type com_meta_data_import_type;
        typedef typename TypeMetadataApiAt<TypeMetadataApiHolder, Interfaces::TypeNameMetadataLabel>::type type_name_metadata_type;
        typedef typename TypeMetadataApiAt<TypeMetadataApiHolder, Interfaces::MethodMetadataLabel>::type method_metadata_type;
        typedef typename TypeMetadataApiAt<TypeMetadataApiHolder, Interfaces::MethodNameMetadataLabel>::type method_name_metadata_type;
        typedef typename TypeMetadataApiAt<TypeMetadataApiHolder, Interfaces::IMethodNameMetadataHashLabel>::type i_method_name_metadata_hash_type;
        typedef typename TypeMetadataApiAt<TypeMetadataApiHolder, Interfaces::IMethodNameMetadataEqualToLabel>::type i_method_name_metadata_equal_to_type;

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
            m_pTypeName(NULL)
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

        mdToken GetToken() const
        {
            if (IsGenericType() && !IsGenericTypeDefinition())
            {
                _ASSERTE(m_pGenericTypeDef != NULL);
                return m_pGenericTypeDef->GetToken();
            }
            else
            {
                return GetDefToken();
                //if (m_mdt == mdTokenNil)
                //{
                //    this_type *pMutableThis = const_cast<this_type *>(this);

                //    assembly_metadata_type &asmMeta = pMutableThis->Map<assembly_metadata_type>();
                //
                //    com_meta_data_import_type &comMetaImp = asmMeta.GetCOMMetaDataImport();

                //    HRESULT hr = comMetaImp.FindTypeDefByName(GetTypeNameCore().GetName().c_str(), NULL, &m_mdt);
                //    if (FAILED(hr))
                //        BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
                //}
                //return m_mdt;
            }
        }

        typename base_type::i_type_name_metadata_type const &GetTypeName() const
        {
            return GetTypeNameCore();
        }

        typename base_type::this_type const *GetBaseType() const
        {
            typename base_type::i_type_name_metadata_type const *pBaseTypeName = NULL;
            pBaseTypeName = GetTypeNameCore().GetBaseTypeName();
            return pBaseTypeName == NULL ? NULL : &pBaseTypeName->Resolve();
        }

        method_metadata_type const *GetMethod(std::wstring const &name, 
                                              CallingConventions const &callingConvention, 
                                              base_type const &retType, 
                                              std::vector<base_type const *> const &paramTypes) const
        {
            typename base_type::i_type_name_metadata_type const &retTypeName = retType.GetTypeName();

            typedef std::vector<base_type const *>::const_iterator ConstIterator;
            std::vector<typename base_type::i_type_name_metadata_type const *> paramTypeNames;
            paramTypeNames.reserve(paramTypes.size());
            for (ConstIterator ci = paramTypes.cbegin(), ci_end = paramTypes.cend(); ci != ci_end; ++ci)
                paramTypeNames.push_back(&(*ci)->GetTypeName());
            
            method_name_metadata_type *pMethodName = NULL;
            pMethodName = NewMethodName(name, callingConvention, retTypeName, paramTypeNames);

            
            bool alreadyExists = false;
            method_metadata_type const *pMethod = NULL;
            pMethod = GetMethodCore(*pMethodName, alreadyExists);
            if (alreadyExists)
            {
                this_type *pMutableThis = const_cast<this_type *>(this);
                type_name_metadata_type &typeName = pMutableThis->GetTypeNameCore();
                typeName.MethodNameMetadataHeap().DeleteLast();
            }

            return pMethod;
        }

        method_metadata_type const *GetMethod(method_name_metadata_type const &methodName) const
        {
            return GetMethodCore(methodName);
        }

        method_name_metadata_type *NewMethodName(std::wstring const &name, 
                                                 CallingConventions const &callingConvention, 
                                                 typename base_type::i_type_name_metadata_type const &retTypeName, 
                                                 std::vector<typename base_type::i_type_name_metadata_type const *> const &paramTypeNames) const
        {
            return GetTypeNameCore().NewMethodName(name, callingConvention, retTypeName, paramTypeNames);
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
                    hr = comMetaImp.EnumGenericParams(&hEnum, GetDefToken(), m_mdgps.c_array(), m_mdgps.size(), &count);
                    if (FAILED(hr))
                        BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

                    m_genericArgs.reserve(m_genericArgs.size() + count);
                    for (UINT i = 0; i < count; ++i)
                    {
                        this_type *pTypeMeta = modMeta.TypeMetadataHeap().New();    // [2012/08/13 20:17:11] この辺実装中。。。TypeNameMeta でやらんとだめでごわす。
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

    private: 
        friend typename assembly_metadata_type;
        friend typename module_metadata_type;
        friend typename type_name_metadata_type;
        friend typename method_metadata_type;
        friend typename method_name_metadata_type;

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
            return GetTypeNameCore().MethodNameMetadataHeap();
        }
        
        method_name_metadata_heap_type const &MethodNameMetadataHeap() const
        {
            return GetTypeNameCore().MethodNameMetadataHeap();
        }

        mdToken GetDefToken() const
        {
            if (m_mdt == mdTokenNil)
            {
                this_type *pMutableThis = const_cast<this_type *>(this);

                assembly_metadata_type &asmMeta = pMutableThis->Map<assembly_metadata_type>();
                
                com_meta_data_import_type &comMetaImp = asmMeta.GetCOMMetaDataImport();

                HRESULT hr = comMetaImp.FindTypeDefByName(GetTypeNameCore().GetName().c_str(), NULL, &m_mdt);
                if (FAILED(hr))
                    BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
            }
            return m_mdt;
        }
        
        type_name_metadata_type const &GetTypeNameCore() const
        {
            this_type *pMutableThis = const_cast<this_type *>(this);
            return pMutableThis->GetTypeNameCore();
        }
        
        type_name_metadata_type &GetTypeNameCore()
        {
            if (m_pTypeName == NULL)
            {
                module_metadata_type &modMeta = Map<module_metadata_type>();

                m_pTypeName = modMeta.TypeNameMetadataHeap().New();
                m_pTypeName->Init(modMeta);
                //m_pTypeName->SetToken(GetToken());
                m_pTypeName->SetResolvedType(*this);
            }
            return *m_pTypeName;
        }

        method_metadata_type const *GetMethodCore(method_name_metadata_type const &methodName) const
        {
            this_type *pMutableThis = const_cast<this_type *>(this);
            return pMutableThis->GetMethodCore(methodName);
        }

        method_metadata_type *GetMethodCore(method_name_metadata_type const &methodName)
        {
            bool alreadyExists = false;
            return GetMethodCore(methodName, alreadyExists);
        }

        method_metadata_type const *GetMethodCore(method_name_metadata_type const &methodName, bool &alreadyExists) const
        {
            this_type *pMutableThis = const_cast<this_type *>(this);
            return pMutableThis->GetMethodCore(methodName, alreadyExists);
        }

        method_metadata_type *GetMethodCore(method_name_metadata_type const &methodName, bool &alreadyExists)
        {
            if (m_methodNameToIndex.find(&methodName) == m_methodNameToIndex.end())
            {
                m_methodNameToIndex[&methodName] = MAXULONG_PTR;
            }

            SIZE_T index = m_methodNameToIndex[&methodName];
            if (index == MAXULONG_PTR)
            {
                method_metadata_type *pMethodMeta = NULL;
                pMethodMeta= MethodMetadataHeap().New();
                pMethodMeta->Init(*this);
                pMethodMeta->SetMethodName(const_cast<method_name_metadata_type &>(methodName));

                m_methodNameToIndex[&methodName] = MethodMetadataHeap().Size() - 1;

                alreadyExists = false;
                return pMethodMeta;
            }
            else
            {
                alreadyExists = true;
                return MethodMetadataHeap()[index];
            }
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

        void SetTypeName(type_name_metadata_type &typeName)
        {
            if (m_pTypeName != NULL)
            {
                BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException("The heap of current object has to merge from the designated object!!"));
            }
            m_pTypeName = &typeName;
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

        mutable mdToken m_mdt;
        mutable bool m_genericArgsInit;
        mutable std::vector<this_type const *> m_genericArgs;
        this_type *m_pGenericTypeDef;
        mutable boost::unordered_map<std::vector<this_type const *>, SIZE_T, type_vector_hash_type, type_vector_equal_to_type> m_genericArgsToIndex;
        mutable boost::unordered_map<method_name_metadata_type const *, 
                                     SIZE_T, 
                                     i_method_name_metadata_hash_type, 
                                     i_method_name_metadata_equal_to_type> m_methodNameToIndex;
        mutable module_metadata_type *m_pModAsScope;
        type_name_metadata_type *m_pTypeName;
        mutable ATL::CComPtr<com_meta_data_import_type> m_pMetaImpApi;
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