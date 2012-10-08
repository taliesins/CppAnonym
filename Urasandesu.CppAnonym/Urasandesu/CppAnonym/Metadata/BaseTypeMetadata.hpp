#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_BASETYPEMETADATA_HPP
#define URASANDESU_CPPANONYM_METADATA_BASETYPEMETADATA_HPP

#ifndef URASANDESU_CPPANONYM_IHEAPCONTENT_H
#include <Urasandesu/CppAnonym/IHeapContent.h>
#endif

#ifndef URASANDESU_CPPANONYM_SIMPLEBLOBFWD_HPP
#include <Urasandesu/CppAnonym/SimpleBlobFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_TYPEKINDS_H
#include <Urasandesu/CppAnonym/Metadata/TypeKinds.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_CALLINGCONVENTIONS_H
#include <Urasandesu/CppAnonym/Metadata/CallingConventions.h>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_CARTRIDGEAPISYSTEMFWD_HPP
#include <Urasandesu/CppAnonym/Traits/CartridgeApiSystemFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_ASSEMBLYMETADATALABELFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/AssemblyMetadataLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_TYPEMETADATAAPIHOLDERLABELFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/TypeMetadataApiHolderLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_HASHFWD_HPP
#include <Urasandesu/CppAnonym/Utilities/HashFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_EQUALTOFWD_HPP
#include <Urasandesu/CppAnonym/Utilities/EqualToFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_METHODNAMEMETADATALABELFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/MethodNameMetadataLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_METHODMETADATALABELFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/MethodMetadataLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASETYPEMETADATAFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseTypeMetadataFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_TYPENAMEMETADATALABELFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/TypeNameMetadataLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_HASMEMBERTYPE_HPP
#include <Urasandesu/CppAnonym/Traits/HasMemberType.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_GETMEMBERTYPE_HPP
#include <Urasandesu/CppAnonym/Traits/GetMemberType.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    template<class ApiCartridgesHolder, class ApiLabel>
    struct TypeMetadataApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::TypeMetadataApiHolderLabel, ApiLabel>
    {
    };
    
    template<
        class TypeMetadataApiHolder
    >    
    class BaseTypeMetadata : 
        public IHeapContent<mdToken>, 
        public HeapProvider<
            mdToken, 
            boost::mpl::vector<
                typename TypeMetadataApiAt<TypeMetadataApiHolder, Interfaces::MethodMetadataLabel>::type
            >
        >
    {
    public:
        typedef BaseTypeMetadata<TypeMetadataApiHolder> this_type;
        
        typedef typename TypeMetadataApiAt<TypeMetadataApiHolder, Interfaces::AssemblyMetadataLabel>::type assembly_metadata_type;
        typedef typename TypeMetadataApiAt<TypeMetadataApiHolder, IMetaDataImport2>::type metadata_import_api_type;
        typedef typename TypeMetadataApiAt<TypeMetadataApiHolder, Interfaces::TypeNameMetadataLabel>::type type_name_metadata_type;
        typedef typename TypeMetadataApiAt<TypeMetadataApiHolder, Interfaces::MethodNameMetadataLabel>::type method_name_metadata_type;
        typedef typename TypeMetadataApiAt<TypeMetadataApiHolder, Interfaces::MethodMetadataLabel>::type method_metadata_type;

        typedef HeapProvider<mdToken, boost::mpl::vector<method_metadata_type> > heap_provider_type;
        typedef typename heap_provider_type::type_decided_by<method_metadata_type>::type method_metadata_heap_type;

        CPP_ANONYM_DECLARE_HAS_MEMBER_TYPE(type_name_metadata_type, method_name_metadata_heap_type);
        CPP_ANONYM_DECLARE_GET_MEMBER_TYPE(type_name_metadata_type, method_name_metadata_heap_type);
        typedef typename boost::mpl::eval_if<
            CPP_ANONYM_HAS_MEMBER_TYPE(type_name_metadata_type, method_name_metadata_heap_type), 
            CPP_ANONYM_GET_MEMBER_TYPE(type_name_metadata_type, method_name_metadata_heap_type), 
            boost::mpl::void_
        >::type method_name_metadata_heap_type;

        BaseTypeMetadata() : 
            IHeapContent(), 
            m_pAsmMeta(NULL), 
            m_kind(TypeKinds::TK_END),
            m_pTypeNameMeta(NULL)
        { }

        BaseTypeMetadata(TypeKinds const &kind) : 
            IHeapContent(), 
            m_pAsmMeta(NULL), 
            m_kind(kind),
            m_pTypeNameMeta(NULL)
        { }

        __declspec(deprecated("This method is temporarily deprecated."))
        void Init(assembly_metadata_type &asmMeta, metadata_import_api_type &metaImpApi) const
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
        T const *FindType() const { return static_cast<assembly_metadata_type const *>(m_pAsmMeta)->FindType<T>(); }

        template<class T>
        T *FindType() { return m_pAsmMeta->FindType<T>(); }
      
        template<>
        this_type const *FindType<this_type>() const { return this; }
      
        template<>
        this_type *FindType<this_type>() { return this; }

        inline TypeKinds const &GetKind() const
        {
            return m_kind;
        }

        inline void SetKind(TypeKinds const &kind)
        {
            m_kind = kind;
        }

        inline mdToken GetToken() const
        {
            return GetKey();
        }

        inline std::wstring const &GetName() const
        {
            return m_name;
        }

        inline void SetName(std::wstring const &name)
        {
            m_name = name;
        }


        method_metadata_type const *GetMethod(std::wstring const &name, 
                                              CallingConventions const &callingConvention, 
                                              this_type const &retType, 
                                              std::vector<this_type const *> const &paramTypes) const
        {
            // This method implementation is temporary.
            this_type *mutableThis = const_cast<this_type *>(this);

            method_metadata_type *pMethodMeta = NULL;
            pMethodMeta = mutableThis->MethodMetadataHeap().New(0x06000001);
            pMethodMeta->Init(*mutableThis);
            return pMethodMeta;
            //// TODO: これ、なんとかして遅延評価版にしないとね。
            //method_name_metadata_type key;
            //key.m_name = name;
            //key.m_callConvention = callConvention;
            //key.m_pRetType = pRetType;
            //key.m_paramTypes = paramTypes;
            //
            //return GetMethodFromMethodKey(key);
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
            _ASSERTE(m_pAsmMeta != NULL);

            if (m_pTypeNameMeta == NULL)
            {
                m_pTypeNameMeta = m_pAsmMeta->TypeNameMetadataHeap().New();
                m_pTypeNameMeta->SetResolutionScope(*m_pAsmMeta);
                m_pTypeNameMeta->SetToken(GetKey());
            }
            return m_pTypeNameMeta;
        }

        std::vector<COR_SIGNATURE> const &GetSignatures() const
        {
            if (m_sigs.size() == 0)
                PushBackSignatures(m_sigs, *this);

            return m_sigs;
        }

    private: 
        template<
            class MethodMetadataApiHolder
        >
        friend class BaseMethodMetadata;

        method_metadata_heap_type &MethodMetadataHeap()
        {
            return heap_provider_type::Of<method_metadata_type>();
        }
        
        method_metadata_heap_type const &MethodMetadataHeap() const
        {
            return heap_provider_type::Of<method_metadata_type>();
        }

        method_name_metadata_heap_type &MethodNameMetadataHeap()
        {
            return const_cast<type_name_metadata_type *>(GetTypeName())->MethodNameMetadataHeap();
        }
        
        method_name_metadata_heap_type const &MethodNameMetadataHeap() const
        {
            return GetTypeName()->MethodNameMetadataHeap();
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

        method_metadata_type const *GetMethodFromTokenCore(mdMethodDef mdmd) const
        {
            typedef typename type_decided_by<method_metadata_type>::type MethodMetadataHeap;
            MethodMetadataHeap const &heap = Of<method_metadata_type>();
            return heap.Get(mdmd);
        }

        static void PutSignatures(SimpleBlob &sb, this_type const &typeMeta)
        {
            typedef std::vector<COR_SIGNATURE>::const_iterator SigConstIterator;
            std::vector<COR_SIGNATURE> const &sigs = typeMeta.GetSignatures();
            for (SigConstIterator i = sigs.begin(), i_end = sigs.end(); i != i_end; ++i)
            {
                sb.Put<COR_SIGNATURE>(*i);
            }
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

        mutable assembly_metadata_type *m_pAsmMeta;
        mutable type_name_metadata_type *m_pTypeNameMeta;
        mutable ATL::CComPtr<metadata_import_api_type> m_pMetaImpApi;
        TypeKinds m_kind;
        mutable std::wstring m_name;
        //typedef Utilities::Hash<method_name_metadata_type> method_key_hash;
        //typedef Utilities::EqualTo<method_name_metadata_type, method_name_metadata_type> method_key_equal_to;
        //mutable boost::unordered_map<method_name_metadata_type, mdMethodDef, method_key_hash, method_key_equal_to> m_methodMetas;
        mutable std::vector<COR_SIGNATURE> m_sigs;
    };

    typedef BaseTypeMetadata<> TypeMetadata;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASETYPEMETADATA_HPP