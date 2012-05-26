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

#ifndef URASANDESU_CPPANONYM_METADATA_ASSEMBLYMETADATALABELFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/AssemblyMetadataLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_TYPEMETADATAAPIHOLDERLABELFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/TypeMetadataApiHolderLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_HASHFWD_HPP
#include <Urasandesu/CppAnonym/Utilities/HashFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_EQUALTOFWD_HPP
#include <Urasandesu/CppAnonym/Utilities/EqualToFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_METHODNAMEMETADATALABELFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/MethodNameMetadataLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_METHODMETADATALABELFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/MethodMetadataLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASETYPEMETADATAFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseTypeMetadataFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    template<class ApiCartridgesHolder, class ApiLabel>
    struct TypeMetadataApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, TypeMetadataApiHolderLabel, ApiLabel>
    {
    };
    
    template<
        class TypeMetadataApiHolder
    >    
    class BaseTypeMetadata : 
        public IHeapContent<mdToken>, 
        public HeapProvider<
            typename TypeMetadataApiAt<TypeMetadataApiHolder, MethodNameMetadataLabel>::type,
            boost::mpl::vector<
                typename TypeMetadataApiAt<TypeMetadataApiHolder, MethodMetadataLabel>::type
            >,
            Utilities::Hash<typename TypeMetadataApiAt<TypeMetadataApiHolder, MethodNameMetadataLabel>::type>,
            Utilities::EqualTo<
                typename TypeMetadataApiAt<TypeMetadataApiHolder, MethodNameMetadataLabel>::type, 
                typename TypeMetadataApiAt<TypeMetadataApiHolder, MethodNameMetadataLabel>::type
            >
        >
    {
    public:
        typedef BaseTypeMetadata<TypeMetadataApiHolder> this_type;
        
        typedef typename TypeMetadataApiAt<TypeMetadataApiHolder, AssemblyMetadataLabel>::type assembly_metadata_type;
        typedef typename TypeMetadataApiAt<TypeMetadataApiHolder, IMetaDataImport2>::type metadata_import_api_type;
        typedef typename TypeMetadataApiAt<TypeMetadataApiHolder, MethodMetadataLabel>::type method_metadata_type;
        typedef typename TypeMetadataApiAt<TypeMetadataApiHolder, MethodNameMetadataLabel>::type method_key_type;

        BaseTypeMetadata() : 
            IHeapContent(), 
            m_pAsmMeta(NULL), 
            m_kind(TypeKinds::TK_END)
        { }

        BaseTypeMetadata(TypeKinds const &kind) : 
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
        mutable ATL::CComPtr<metadata_import_api_type> m_pMetaImpApi;
        TypeKinds m_kind;
        mutable std::wstring m_name;
        //typedef Utilities::Hash<method_key_type> method_key_hash;
        //typedef Utilities::EqualTo<method_key_type, method_key_type> method_key_equal_to;
        //mutable boost::unordered_map<method_key_type, mdMethodDef, method_key_hash, method_key_equal_to> m_methodMetas;
        mutable std::vector<COR_SIGNATURE> m_sigs;
    };

    typedef BaseTypeMetadata<> TypeMetadata;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASETYPEMETADATA_HPP