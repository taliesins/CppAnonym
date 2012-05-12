#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYMETADATAPROTOB8DF5A21_H
#define URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYMETADATAPROTOB8DF5A21_H

#ifndef URASANDESU_CPPANONYM_IHEAPCONTENT_H
#include <Urasandesu/CppAnonym/IHeapContent.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace StrongNaming {

    struct IStrongNameKeyApi;

    template<
        class StrongNameKeyApiType
    >    
    class BaseStrongNameKeyProto4236D495;

    struct IStrongNameInfoApi;

    struct DefaultStrongNameInfoApiProto4236D495;

    template<
        class StrongNameInfoApiType
    >    
    class BaseStrongNameInfoProto4236D495;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace StrongNaming {

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    struct IAssemblyNameMetadataApi { };

    struct DefaultAssemblyMetadataApiProtoB8DF5A21;

    struct DefaultAssemblyNameMetadataApiProtoB8DF5A21 : 
        IAssemblyNameMetadataApi 
    { 
        typedef boost::mpl::vector<DefaultAssemblyMetadataApiProtoB8DF5A21, 
                                   IMetaDataAssemblyImport, 
                                   StrongNaming::DefaultStrongNameInfoApiProto4236D495> external_api_types;
    };


    struct IAssemblyMetadataApi;

    template<
        class AssemblyMetadataApiType
    >    
    class BaseAssemblyMetadataProtoB8DF5A21;

    
    template<
        class AssemblyNameMetadataApiType = DefaultAssemblyNameMetadataApiProtoB8DF5A21
    >    
    class BaseAssemblyNameMetadataProtoB8DF5A21 :
        public IHeapContent<mdAssembly>
    {
    public:
        typedef BaseAssemblyNameMetadataProtoB8DF5A21<AssemblyNameMetadataApiType> this_type;

        typedef typename Traits::ExternalApiOrDefault<AssemblyNameMetadataApiType, IAssemblyNameMetadataApi, IAssemblyMetadataApi>::type assembly_metadata_api_type;
        typedef BaseAssemblyMetadataProtoB8DF5A21<assembly_metadata_api_type> assembly_metadata_type;

        typedef typename Traits::ExternalApiOrDefault<AssemblyNameMetadataApiType, IAssemblyNameMetadataApi, IMetaDataAssemblyImport>::type metadata_assembly_import_api_type;

        typedef typename Traits::ExternalApiOrDefault<AssemblyNameMetadataApiType, IAssemblyNameMetadataApi, StrongNaming::IStrongNameInfoApi>::type strong_name_info_api_type;
        typedef StrongNaming::BaseStrongNameInfoProto4236D495<strong_name_info_api_type> strong_name_info_type;

        typedef typename Traits::ExternalApiOrDefault<strong_name_info_api_type, StrongNaming::IStrongNameInfoApi, StrongNaming::IStrongNameKeyApi>::type strong_name_key_api_type;
        typedef StrongNaming::BaseStrongNameKeyProto4236D495<strong_name_key_api_type> strong_name_key_type;

        BaseAssemblyNameMetadataProtoB8DF5A21() : 
            m_pAsmMeta(NULL), 
            m_asmPropsInitialized(false)
        { }

        void Init(assembly_metadata_type &asmMeta, metadata_assembly_import_api_type &metaAsmImpApi) const
        {
            _ASSERTE(m_pAsmMeta == NULL);
            _ASSERTE(m_pMetaAsmImpApi.p == NULL);
            
            m_pAsmMeta = &asmMeta;
            m_pMetaAsmImpApi = &metaAsmImpApi;
        }

        template<class T>
        T const *FindType() const { return static_cast<assembly_metadata_type const *>(m_pAsmMeta)->FindType<T>(); }

        template<class T>
        T *FindType() { return m_pAsmMeta->FindType<T>(); }
      
        template<>
        this_type const *FindType<this_type>() const { return this; }
      
        template<>
        this_type *FindType<this_type>() { return this; }

        std::wstring const &GetName() const
        {
            FillPropertiesIfNecessary();
            return m_name;
        }

        strong_name_key_type const *GetStrongNameKey() const
        {
            FillPropertiesIfNecessary();
            return m_pSnKey.get();
        }

        void FillPropertiesIfNecessary() const
        {
            if (m_asmPropsInitialized)
                return;

            HRESULT hr = E_FAIL;

            std::auto_ptr<WCHAR> name;
            ULONG nameSize = 0;
            ASSEMBLYMETADATA amd;
            ::ZeroMemory(&amd, sizeof(ASSEMBLYMETADATA));
            DWORD asmFlags = 0;
            DWORD asmFlagsTmp = 0;
            hr = m_pMetaAsmImpApi->GetAssemblyProps(GetKey(), NULL, NULL, NULL, NULL, 0, 
                                                    &nameSize, &amd, 
                                                    &asmFlagsTmp);
            if (FAILED(hr))
                BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

            name = std::auto_ptr<WCHAR>(new WCHAR[nameSize]);
            amd.szLocale = amd.cbLocale ? new WCHAR[amd.cbLocale] : NULL;
            amd.rOS = amd.ulOS ? new OSINFO[amd.ulOS] : NULL;
            amd.rProcessor = amd.ulProcessor ? new ULONG[amd.ulProcessor] : NULL;
            
            void const *pPubKey = NULL;
            DWORD pubKeySize = 0;
            hr = m_pMetaAsmImpApi->GetAssemblyProps(GetKey(), &pPubKey, &pubKeySize, NULL, 
                                                    name.get(), nameSize, NULL, 
                                                    &amd, NULL);
            if (FAILED(hr))
                BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

            m_name = std::wstring(name.get(), nameSize);
            strong_name_info_type const *pSnInfo = FindType<strong_name_info_type>();
            m_pSnKey = pSnInfo->CreateKey(reinterpret_cast<PublicKeyBlob const *>(pPubKey), pubKeySize);

            m_asmPropsInitialized = true;
        }

    private:
        mutable assembly_metadata_type *m_pAsmMeta;
        mutable ATL::CComPtr<IMetaDataAssemblyImport> m_pMetaAsmImpApi;
        mutable bool m_asmPropsInitialized;
        mutable std::wstring m_name;
        mutable boost::shared_ptr<strong_name_key_type const> m_pSnKey;
    };


    template<
        class TypeMetadataApiType
    >    
    class BaseTypeMetadataProtoB8DF5A21;

    template<
        class MetadataDispenserApiType
    >    
    class BaseMetadataDispenserProtoB8DF5A21;

    struct DefaultAssemblyMetadataApiProtoB8DF5A21;

    struct ITypeMetadataApi;

    struct IMetadataDispenserApi;


    template<
        class AssemblyMetadataApiType = DefaultAssemblyMetadataApiProtoB8DF5A21
    >    
    class BaseAssemblyMetadataProtoB8DF5A21 :
        public IHeapContent<mdAssembly>,
        public HeapProvider<
            mdToken, 
            boost::mpl::vector<
                BaseTypeMetadataProtoB8DF5A21<typename Traits::ExternalApiOrDefault<AssemblyMetadataApiType, IAssemblyMetadataApi, ITypeMetadataApi>::type>, 
                BaseAssemblyNameMetadataProtoB8DF5A21<typename Traits::ExternalApiOrDefault<AssemblyMetadataApiType, IAssemblyMetadataApi, IAssemblyNameMetadataApi>::type> 
            >
        >
    {
    public:
        typedef BaseAssemblyMetadataProtoB8DF5A21<AssemblyMetadataApiType> this_type;
        
        typedef typename Traits::ExternalApiOrDefault<AssemblyMetadataApiType, IAssemblyMetadataApi, IMetadataDispenserApi>::type metadata_dispenser_api_type;
        typedef BaseMetadataDispenserProtoB8DF5A21<metadata_dispenser_api_type> metadata_dispenser_type;
        
        typedef typename Traits::ExternalApiOrDefault<AssemblyMetadataApiType, IAssemblyMetadataApi, IMetaDataImport2>::type metadata_import_api_type;
        
        typedef typename Traits::ExternalApiOrDefault<AssemblyMetadataApiType, IAssemblyMetadataApi, ITypeMetadataApi>::type type_metadata_api_type;
        typedef BaseTypeMetadataProtoB8DF5A21<type_metadata_api_type> type_metadata_type;
        
        typedef typename Traits::ExternalApiOrDefault<AssemblyMetadataApiType, IAssemblyMetadataApi, IAssemblyNameMetadataApi>::type assembly_name_metadata_api_type;
        typedef BaseAssemblyNameMetadataProtoB8DF5A21<assembly_name_metadata_api_type> assembly_name_metadata_type;

        BaseAssemblyMetadataProtoB8DF5A21() : 
            m_pMetaDisp(NULL), 
            m_token(mdAssemblyNil)
        { }

        void Init(metadata_dispenser_type &metaDisp, metadata_import_api_type &metaImpApi) const
        {
            _ASSERTE(m_pMetaDisp == NULL);
            _ASSERTE(m_pMetaImpApi.p == NULL);
            
            m_pMetaDisp = &metaDisp;
            m_pMetaImpApi = &metaImpApi;
        }

        template<class T>
        T const *FindType() const { return static_cast<metadata_dispenser_type const *>(m_pMetaDisp)->FindType<T>(); }

        template<class T>
        T *FindType() { return m_pMetaDisp->FindType<T>(); }
      
        template<>
        this_type const *FindType<this_type>() const { return this; }
      
        template<>
        this_type *FindType<this_type>() { return this; }

        mdAssembly GetToken() const
        {
            _ASSERTE(m_pMetaImpApi.p != NULL);

            if (m_token == mdAssemblyNil)
            {
                HRESULT hr = E_FAIL;

                if (m_pMetaAsmImpApi.p == NULL)
                {
                    hr = m_pMetaImpApi->QueryInterface(IID_IMetaDataAssemblyImport, 
                                                       reinterpret_cast<void **>(&m_pMetaAsmImpApi));
                    if (FAILED(hr))
                        BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
                }

                hr = m_pMetaAsmImpApi->GetAssemblyFromScope(&m_token);
                if (FAILED(hr))
                    BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
            }

            return m_token;
        }

        type_metadata_type const *GetType(std::wstring const &name) const
        {
            _ASSERTE(m_pMetaImpApi.p != NULL);

            if (m_typeMetas.find(name) == m_typeMetas.end())
            {
                m_typeMetas[name] = mdTokenNil;
            }

            mdToken mdt = m_typeMetas[name];
            if (mdt == mdTokenNil)
            {
                mdTypeDef mdtd = mdTypeDefNil;
                HRESULT hr = m_pMetaImpApi->FindTypeDefByName(name.c_str(), NULL, &mdtd);
                if (FAILED(hr))
                    BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

                this_type *mutableThis = const_cast<this_type *>(this);
                typedef typename type_decided_by<type_metadata_type>::type TypeMetadataHeap;
                TypeMetadataHeap &heap = mutableThis->Of<type_metadata_type>();
                type_metadata_type *pTypeMeta = heap.New(mdtd);
                pTypeMeta->Init(*mutableThis, *m_pMetaImpApi);

                m_typeMetas[name] = mdtd;

                return pTypeMeta;
            }
            else
            {
                return GetTypeFromTokenCore(mdt);
            }
        }

        assembly_name_metadata_type const *GetAssemblyName() const
        {
            typedef typename type_decided_by<assembly_name_metadata_type>::type AssemblyNameMetadataHeap;
            AssemblyNameMetadataHeap const &heap = Of<assembly_name_metadata_type>();
            if (heap.Exists(GetToken()))
            {
                return heap.Get(GetToken());
            }
            else
            {
                AssemblyNameMetadataHeap *pHeap = const_cast<AssemblyNameMetadataHeap *>(&heap);
                assembly_name_metadata_type const *pAsmNameMeta = pHeap->New(GetToken());
                this_type *mutableThis = const_cast<this_type *>(this);
                pAsmNameMeta->Init(*mutableThis, *m_pMetaAsmImpApi);
                return pAsmNameMeta;
            }
        }

    private:
        type_metadata_type const *GetTypeFromTokenCore(mdToken mdt) const
        {
            typedef typename type_decided_by<type_metadata_type>::type TypeMetadataHeap;
            TypeMetadataHeap const &heap = Of<type_metadata_type>();
            return heap.Get(mdt);
        }

        mutable metadata_dispenser_type *m_pMetaDisp;
        mutable ATL::CComPtr<metadata_import_api_type> m_pMetaImpApi;
        mutable ATL::CComPtr<IMetaDataAssemblyImport> m_pMetaAsmImpApi;
        mutable mdAssembly m_token;
        mutable boost::unordered_map<std::wstring, mdToken> m_typeMetas;
    };

    typedef BaseAssemblyMetadataProtoB8DF5A21<> AssemblyMetadataProtoB8DF5A21;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYMETADATAPROTOB8DF5A21_H