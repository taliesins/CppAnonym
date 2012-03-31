#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYMETADATAPROTOB8DF5A21_H
#define URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYMETADATAPROTOB8DF5A21_H

#ifndef URASANDESU_CPPANONYM_IHEAPCONTENT_H
#include <Urasandesu/CppAnonym/IHeapContent.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

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
                BaseTypeMetadataProtoB8DF5A21<typename Traits::ChildApiOrDefault<AssemblyMetadataApiType, ITypeMetadataApi>::type> 
            >
        >
    {
    public:
        typedef BaseAssemblyMetadataProtoB8DF5A21<AssemblyMetadataApiType> this_type;
        typedef typename Traits::ParentApiOrDefault<AssemblyMetadataApiType, IMetadataDispenserApi>::type metadata_dispenser_api_type;
        typedef BaseMetadataDispenserProtoB8DF5A21<metadata_dispenser_api_type> metadata_dispenser_type;
        typedef typename Traits::ChildApiOrDefault<AssemblyMetadataApiType, IMetaDataImport2>::type metadata_import_api_type;
        typedef typename Traits::ChildApiOrDefault<AssemblyMetadataApiType, ITypeMetadataApi>::type type_metadata_api_type;
        typedef BaseTypeMetadataProtoB8DF5A21<type_metadata_api_type> type_metadata_type;

        BaseAssemblyMetadataProtoB8DF5A21() : 
            m_pMetaDisp(NULL), 
            m_token(mdAssemblyNil)
        { }

        void Init(metadata_dispenser_type &metaDisp, metadata_import_api_type *metaImpApi) const
        {
            _ASSERTE(m_pMetaDisp == NULL);
            _ASSERTE(m_pMetaImpApi.p == NULL);
            _ASSERTE(metaImpApi != NULL);
            
            m_pMetaDisp = &metaDisp;
            m_pMetaImpApi = metaImpApi;
        }

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
                pTypeMeta->Init(*mutableThis, m_pMetaImpApi);

                m_typeMetas[name] = mdtd;

                return pTypeMeta;
            }
            else
            {
                return GetTypeFromTokenCore(mdt);
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