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

    namespace Detail {

        template<
            class TypeMetadataApiType
        >    
        struct MethodKey;

    }   // namespace Detail

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    template<class X, class Y>
    struct DefaultEqualTo;

    template<class TypeMetadataApiType>
    struct DefaultEqualTo<
                    Metadata::Detail::MethodKey<TypeMetadataApiType>, 
                    Metadata::Detail::MethodKey<TypeMetadataApiType>> : 
        std::binary_function<
                    Metadata::Detail::MethodKey<TypeMetadataApiType>, 
                    Metadata::Detail::MethodKey<TypeMetadataApiType>, 
                    bool>
    {
        typedef Metadata::Detail::MethodKey<TypeMetadataApiType> method_key_type;
        
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
    struct DefaultHash<Metadata::Detail::MethodKey<TypeMetadataApiType>> : 
        std::unary_function<Metadata::Detail::MethodKey<TypeMetadataApiType>, std::size_t>
    {
        typedef Metadata::Detail::MethodKey<TypeMetadataApiType> method_key_type;
        
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

    namespace Detail {

        template<
            class TypeMetadataApiType = DefaultTypeMetadataApiProtoB8DF5A21
        >    
        struct MethodKey
        {
            typedef BaseTypeMetadataProtoB8DF5A21<TypeMetadataApiType> type_metadata_type;
            typedef typename std::vector<type_metadata_type const *>::iterator param_types_iterator;
            typedef typename std::vector<type_metadata_type const *>::const_iterator param_types_const_iterator;

            std::wstring m_name;
            CallingConventions m_callConvention;
            type_metadata_type const *m_pRetType;
            std::vector<type_metadata_type const *> m_paramTypes;
        };

    }   // namespace Detail

    struct ITypeMetadataApi;
    
    template<
        class TypeMetadataApiType = DefaultTypeMetadataApiProtoB8DF5A21
    >    
    class BaseTypeMetadataProtoB8DF5A21 : 
        public IHeapContent<mdToken>, 
        public HeapProvider<
            mdToken, 
            boost::mpl::vector<
                BaseMethodMetadataProtoB8DF5A21<typename Traits::ExternalApiOrDefault<TypeMetadataApiType, ITypeMetadataApi, IMethodMetadataApi>::type> 
            >
        >
    {
    public:
        typedef BaseTypeMetadataProtoB8DF5A21<TypeMetadataApiType> this_type;
        
        typedef Detail::MethodKey<TypeMetadataApiType> method_key_type;
        
        typedef typename Traits::ExternalApiOrDefault<TypeMetadataApiType, ITypeMetadataApi, IAssemblyMetadataApi>::type assembly_metadata_api_type;
        typedef BaseAssemblyMetadataProtoB8DF5A21<assembly_metadata_api_type> assembly_metadata_type;
        
        typedef typename Traits::ExternalApiOrDefault<TypeMetadataApiType, ITypeMetadataApi, IMetaDataImport2>::type metadata_import_api_type;
        
        typedef typename Traits::ExternalApiOrDefault<TypeMetadataApiType, ITypeMetadataApi, IMethodMetadataApi>::type method_metadata_api_type;
        typedef BaseMethodMetadataProtoB8DF5A21<method_metadata_api_type> method_metadata_type;

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

        method_metadata_type const *GetMethod(std::wstring const &name, 
                                              CallingConventions const &callConvention, 
                                              this_type const *pRetType, 
                                              std::vector<this_type const *> const &paramTypes) const
        {
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
            _ASSERTE(m_pMetaImpApi.p != NULL);

            if (m_methodMetas.find(methodKey) == m_methodMetas.end())
            {
                m_methodMetas[methodKey] = mdMethodDefNil;
            }

            mdMethodDef mdmd = m_methodMetas[methodKey];
            if (mdmd == mdMethodDefNil)
            {
                SimpleBlob sb;

                // Call Convention
                switch (methodKey.m_callConvention.Value())
                {
                    case CallingConventions::CC_STANDARD:
                        sb.Put<COR_SIGNATURE>(IMAGE_CEE_CS_CALLCONV_DEFAULT);
                        break;

                    case CallingConventions::CC_HAS_THIS:
                        sb.Put<COR_SIGNATURE>(IMAGE_CEE_CS_CALLCONV_HASTHIS);
                        break;

                    default:
                        BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
                        break;
                }

                // ParamCount
                sb.Put<COR_SIGNATURE>(methodKey.m_paramTypes.size());

                typedef std::vector<COR_SIGNATURE>::const_iterator SigConstIterator;
                
                // RetType
                PutSignatures(sb, *methodKey.m_pRetType);

                // ParamType
                typedef std::vector<this_type const *>::const_iterator ParamTypesConstIterator;
                for (ParamTypesConstIterator i = methodKey.m_paramTypes.begin(), 
                                             i_end = methodKey.m_paramTypes.end(); 
                     i != i_end; 
                     ++i)
                {
                    PutSignatures(sb, **i);
                }

                HRESULT hr = m_pMetaImpApi->FindMethod(GetToken(), methodKey.m_name.c_str(), 
                                                       sb.Ptr(), sb.Size(), &mdmd);
                if (FAILED(hr))
                    BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

                this_type *mutableThis = const_cast<this_type *>(this);
                typedef typename type_decided_by<method_metadata_type>::type MethodMetadataHeap;
                MethodMetadataHeap &heap = mutableThis->Of<method_metadata_type>();
                method_metadata_type *pMethodMeta = heap.New(mdmd);
                pMethodMeta->Init(*mutableThis, *m_pMetaImpApi);

                m_methodMetas[methodKey] = mdmd;

                return pMethodMeta;
            }
            else
            {
                return GetMethodFromTokenCore(mdmd);
            }
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
        typedef Utilities::DefaultHash<method_key_type> method_key_hash;
        typedef Utilities::DefaultEqualTo<method_key_type, method_key_type> method_key_equal_to;
        mutable boost::unordered_map<method_key_type, mdMethodDef, method_key_hash, method_key_equal_to> m_methodMetas;
        mutable std::vector<COR_SIGNATURE> m_sigs;
    };

    typedef BaseTypeMetadataProtoB8DF5A21<> TypeMetadataProtoB8DF5A21;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASETYPEMETADATAPROTOB8DF5A21_H