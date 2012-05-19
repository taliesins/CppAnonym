#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_BASETYPEMETADATAPROTOB8DF5A21_H
#define URASANDESU_CPPANONYM_METADATA_BASETYPEMETADATAPROTOB8DF5A21_H

#ifndef URASANDESU_CPPANONYM_IHEAPCONTENT_H
#include <Urasandesu/CppAnonym/IHeapContent.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_TYPEKINDS_H
#include <Urasandesu/CppAnonym/Metadata/TypeKinds.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_CALLINGCONVENTIONS_H
#include <Urasandesu/CppAnonym/Metadata/CallingConventions.h>
#endif

namespace Urasandesu { namespace CppAnonym {

    class SimpleBlob;

}}  // namespace Urasandesu { namespace CppAnonym {

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    template<
        class TypeMetadataApiType
    >    
    class BaseTypeMetadataProtoB8DF5A21;

    //namespace Detail {

    //    template<
    //        class TypeMetadataApiType
    //    >    
    //    struct MethodKey;

    //}   // namespace Detail
    
    template<
        class TypeMetadataApiType
    >    
    struct MethodKey;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    template<class X, class Y>
    struct DefaultEqualTo;

    template<class TypeMetadataApiType>
    struct DefaultEqualTo<
                    Metadata::MethodKey<TypeMetadataApiType>, 
                    Metadata::MethodKey<TypeMetadataApiType>> : 
        std::binary_function<
                    Metadata::MethodKey<TypeMetadataApiType>, 
                    Metadata::MethodKey<TypeMetadataApiType>, 
                    bool>
    {
        typedef Metadata::MethodKey<TypeMetadataApiType> method_key_type;
        
        bool operator()(method_key_type const &x, method_key_type const &y) const
        {
            using namespace Urasandesu::CppAnonym::Collections;
            using namespace Urasandesu::CppAnonym::Utilities;

            return x.m_name == y.m_name &&
                   x.m_callConvention == y.m_callConvention &&
                   x.m_pRetType == y.m_pRetType &&
                   SequenceEqual(x.m_paramTypes.begin(), x.m_paramTypes.end(), 
                                 y.m_paramTypes.begin(), y.m_paramTypes.end());
        }
    };

    

    template<class T>
    struct DefaultHash;
    
    template<class TypeMetadataApiType>
    struct DefaultHash<Metadata::MethodKey<TypeMetadataApiType>> : 
        std::unary_function<Metadata::MethodKey<TypeMetadataApiType>, std::size_t>
    {
        typedef Metadata::MethodKey<TypeMetadataApiType> method_key_type;
        
        std::size_t operator()(method_key_type const &x) const
        {
            using namespace Urasandesu::CppAnonym::Collections;
            using namespace Urasandesu::CppAnonym::Utilities;

            std::size_t seed = 0;
            boost::hash_combine(seed, boost::hash_value(x.m_name));
            boost::hash_combine(seed, x.m_callConvention.Value());
            boost::hash_combine(seed, HashValue(x.m_pRetType));
            boost::hash_combine(seed, SequenceHashValue(x.m_paramTypes.begin(), x.m_paramTypes.end()));
            return seed;
        }
    };
}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    struct IAssemblyMetadata { };

    struct ITypeMetadata { };

    template<
        class AssemblyMetadataApiType
    >    
    class BaseAssemblyMetadataProtoB8DF5A21;

    template<
        class MethodMetadataApiType
    >    
    class BaseMethodMetadataProtoB8DF5A21;

    struct DefaultTypeMetadataApiProtoB8DF5A21;

    struct IAssemblyMetadataApi;

    struct IMethodMetadataApi;

    template<
        class TypeMetadataApiType
    >    
    class BaseTypeMetadataProtoB8DF5A21;

#if 0
    namespace Detail {

        // TODO: public な型に昇格させる。名前についても **Key ではなく、**Id に。
        //       →イカンイカン。Profiler API の識別子と名前が被る (-_-;)
        template<
            class TypeMetadataApiType = DefaultTypeMetadataApiProtoB8DF5A21
        >    
        struct MethodKey
        {
            typedef BaseTypeMetadataProtoB8DF5A21<TypeMetadataApiType> type_metadata_type;
            typedef typename std::vector<type_metadata_type const *>::iterator param_types_iterator;
            typedef typename std::vector<type_metadata_type const *>::const_iterator param_types_const_iterator;

            MethodKey() { }
            std::wstring m_name;
            CallingConventions m_callConvention;
            type_metadata_type const *m_pRetType;
            std::vector<type_metadata_type const *> m_paramTypes;
        };

    }   // namespace Detail
#endif

    //struct IMethodKey { };

    struct IMethodMetadata { };

    struct ITypeMetadataApi;

    template<
        class TypeMetadataType
    >    
    struct MethodKey;
    
    template<
        class TypeMetadataApiType = DefaultTypeMetadataApiProtoB8DF5A21
    >    
    class BaseTypeMetadataProtoB8DF5A21 : 
        public IHeapContent<mdToken>, 
        public HeapProvider<
            MethodKey<BaseTypeMetadataProtoB8DF5A21<TypeMetadataApiType>>,
            boost::mpl::vector<
                typename Traits::ExternalApiOrDefault<TypeMetadataApiType, ITypeMetadataApi, IMethodMetadata>::type // ううううううううううううううううううううううううううううううううううううう
                // 直接見せるのいや・・・。
                // is_same は incompleted な型でも判定できるみたい。いや・・・でもそれって直接見えるってことですよね・・・？
                // もっとがっつり仕組み変えること考える？
                // 利用する型を index や ID で取り出す、とか。
            >,
            Utilities::DefaultHash<MethodKey<BaseTypeMetadataProtoB8DF5A21<TypeMetadataApiType>>>,
            Utilities::DefaultEqualTo<
                MethodKey<BaseTypeMetadataProtoB8DF5A21<TypeMetadataApiType>>, 
                MethodKey<BaseTypeMetadataProtoB8DF5A21<TypeMetadataApiType>>
            >
        >, 
        public ITypeMetadata
    {
    public:
        typedef BaseTypeMetadataProtoB8DF5A21<TypeMetadataApiType> this_type;
        
        //typedef typename Traits::ExternalApiOrDefault<TypeMetadataApiType, ITypeMetadataApi, IAssemblyMetadataApi>::type assembly_metadata_api_type;
        //typedef BaseAssemblyMetadataProtoB8DF5A21<assembly_metadata_api_type> assembly_metadata_type;
        typedef typename Traits::ExternalApiOrDefault<TypeMetadataApiType, ITypeMetadataApi, IAssemblyMetadata>::type assembly_metadata_type;

        typedef typename Traits::ExternalApiOrDefault<TypeMetadataApiType, ITypeMetadataApi, IMetaDataImport2>::type metadata_import_api_type;
        
        typedef typename Traits::ExternalApiOrDefault<TypeMetadataApiType, ITypeMetadataApi, IMethodMetadata>::type method_metadata_type;
        
        typedef MethodKey<this_type> method_key_type;

        BaseTypeMetadataProtoB8DF5A21() : 
            IHeapContent(), 
            m_pAsmMeta(NULL), 
            m_kind(TypeKinds::TK_END)
        { }

        BaseTypeMetadataProtoB8DF5A21(TypeKinds const &kind) : 
            IHeapContent(), 
            m_pAsmMeta(NULL), 
            m_kind(kind)
        { }

        void Init(assembly_metadata_type &asmMeta, metadata_import_api_type &metaImpApi) const
        {
            _ASSERTE(m_pAsmMeta == NULL);
            _ASSERTE(m_pMetaImpApi.p == NULL);
            
            m_pAsmMeta = &asmMeta;
            m_pMetaImpApi = &metaImpApi;
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
                                              CallingConventions const &callConvention, 
                                              this_type const *pRetType, 
                                              std::vector<this_type const *> const &paramTypes) const
        {
            // TODO: これ、なんとかして遅延評価版にしないとね。
            method_key_type key;
            key.m_name = name;
            key.m_callConvention = callConvention;
            key.m_pRetType = pRetType;
            key.m_paramTypes = paramTypes;
            
            return GetMethodFromMethodKey(key);
        }

        std::vector<COR_SIGNATURE> const &GetSignatures() const
        {
            if (m_sigs.size() == 0)
                PushBackSignatures(m_sigs, *this);

            return m_sigs;
        }

    private: 
        method_metadata_type const *GetMethodFromMethodKey(method_key_type const &methodKey) const
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
                // HeapProvider に MethodKey 指定できないと成り立たない・・・。
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
        mutable ATL::CComPtr<metadata_import_api_type> m_pMetaImpApi;
        TypeKinds m_kind;
        mutable std::wstring m_name;
        //typedef Utilities::DefaultHash<method_key_type> method_key_hash;
        //typedef Utilities::DefaultEqualTo<method_key_type, method_key_type> method_key_equal_to;
        //mutable boost::unordered_map<method_key_type, mdMethodDef, method_key_hash, method_key_equal_to> m_methodMetas;
        mutable std::vector<COR_SIGNATURE> m_sigs;
    };

    typedef BaseTypeMetadataProtoB8DF5A21<> TypeMetadataProtoB8DF5A21;


    template<
        class TypeMetadataType
    >    
    struct MethodKey
    {
        typedef MethodKey<TypeMetadataType> this_type;

        //typedef typename Traits::ExternalApiOrDefault<MethodMetadataApiType, IMethodMetadataApi, ITypeMetadata>::type type_metadata_type;
        typedef TypeMetadataType type_metadata_type;

        typedef typename std::vector<type_metadata_type const *>::iterator param_types_iterator;
        typedef typename std::vector<type_metadata_type const *>::const_iterator param_types_const_iterator;

        MethodKey() { }
        std::wstring m_name;
        CallingConventions m_callConvention;
        type_metadata_type const *m_pRetType;
        std::vector<type_metadata_type const *> m_paramTypes;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASETYPEMETADATAPROTOB8DF5A21_H