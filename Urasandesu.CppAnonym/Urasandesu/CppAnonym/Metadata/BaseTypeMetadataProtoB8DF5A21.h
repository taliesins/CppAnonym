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
        class TypeMetadataApiType = DefaultTypeMetadataApiProtoB8DF5A21
    >    
    class BaseTypeMetadataProtoB8DF5A21 : 
        public IHeapContent<mdToken>, 
        public HeapProvider<
            mdToken, 
            boost::mpl::vector<
                BaseMethodMetadataProtoB8DF5A21<typename Traits::ChildApiOrDefault<TypeMetadataApiType, IMethodMetadataApi>::type> 
            >
        >
    {
    public:
        typedef BaseTypeMetadataProtoB8DF5A21<TypeMetadataApiType> this_type;
        typedef typename Traits::ParentApiOrDefault<TypeMetadataApiType, IAssemblyMetadataApi>::type assembly_metadata_api_type;
        typedef BaseAssemblyMetadataProtoB8DF5A21<assembly_metadata_api_type> assembly_metadata_type;
        typedef typename Traits::ChildApiOrDefault<TypeMetadataApiType, IMetaDataImport2>::type metadata_import_api_type;
        typedef typename Traits::ChildApiOrDefault<TypeMetadataApiType, IMethodMetadataApi>::type method_metadata_api_type;
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

        void Init(assembly_metadata_type &asmMeta, metadata_import_api_type *metaImpApi) const
        {
            _ASSERTE(m_pAsmMeta == NULL);
            _ASSERTE(m_pMetaImpApi.p == NULL);
            _ASSERTE(metaImpApi != NULL);
            
            m_pAsmMeta = &asmMeta;
            m_pMetaImpApi = metaImpApi;
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

        struct MethodKey
        {
            std::wstring m_name;
            CallingConventions m_callConvention;
            this_type const *m_pRetType;
            std::vector<this_type const *> m_paramTypes;
        };

        method_metadata_type const *GetMethod(std::wstring const &name, 
                                              CallingConventions const &callConvention, 
                                              this_type const *pRetType, 
                                              std::vector<this_type const *> const &paramTypes) const
        {
            MethodKey key;
            key.m_name = name;
            key.m_callConvention = callConvention;
            key.m_pRetType = pRetType;
            key.m_paramTypes = paramTypes;
            
            return GetMethodFromMethodKey(key);
        }

        std::vector<COR_SIGNATURE> const &GetSignatures() const
        {
            if (m_sigs.size() == 0)
            {
                TypeKinds const &typeKind = GetKind();
                switch (typeKind.Value())
                {
                    case TypeKinds::TK_VOID:
                    case TypeKinds::TK_I:
                    case TypeKinds::TK_OBJECT:
                        m_sigs.push_back(typeKind.Value());
                        break;

                    default:
                        BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
                        break;
                }
            }

            return m_sigs;
        }

    private: 
        method_metadata_type const *GetMethodFromMethodKey(MethodKey const &methodKey) const
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
                pMethodMeta->Init(*mutableThis, m_pMetaImpApi);

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

        struct Hash
            : std::unary_function<MethodKey, std::size_t>
        {
            std::size_t operator()(MethodKey const &x) const
            {
                std::size_t seed = 0;

                boost::hash_combine(seed, boost::hash_value(x.m_name));
                //string_type const &native = x.native();
                //for (string_type::const_iterator i = native.begin(), i_end = native.end(); i != i_end; ++i)
                //{
                //    boost::hash_combine(seed, std::toupper(*i, std::locale()));
                //}

                return seed;
            }
        };

        struct EqualTo
            : std::binary_function<MethodKey, MethodKey, bool>
        {
            bool operator()(MethodKey const &x, MethodKey const &y) const
            {
                return x.m_name == y.m_name;
            }
        };

        mutable assembly_metadata_type *m_pAsmMeta;
        mutable ATL::CComPtr<metadata_import_api_type> m_pMetaImpApi;
        TypeKinds m_kind;
        mutable boost::unordered_map<MethodKey, mdMethodDef, Hash, EqualTo> m_methodMetas;
        mutable std::vector<COR_SIGNATURE> m_sigs;
    };

    typedef BaseTypeMetadataProtoB8DF5A21<> TypeMetadataProtoB8DF5A21;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASETYPEMETADATAPROTOB8DF5A21_H