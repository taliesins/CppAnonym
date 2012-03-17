#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYMETADATAPROTOB8DF5A21_H
#define URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYMETADATAPROTOB8DF5A21_H

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    template<
        class AssemblyMetadataApiType = DefaultAssemblyMetadataApiProtoB8DF5A21
    >    
    class BaseAssemblyMetadataProtoB8DF5A21 :
        public IHeapContent<mdToken>
    {
    public:
        typedef BaseMetadataDispenserProtoB8DF5A21<
                    typename AssemblyMetadataApiType::metadata_dispenser_api_type> metadata_dispenser_type;
        //typedef ATL::CComPtr<AssemblyMetadataApiType::metadata_import_api_type> metadata_import_type;
        typedef typename AssemblyMetadataApiType::metadata_import_api_type metadata_import_api_type;

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

    private:
        mutable metadata_dispenser_type *m_pMetaDisp;
        mutable ATL::CComPtr<metadata_import_api_type> m_pMetaImpApi;
        mutable ATL::CComPtr<IMetaDataAssemblyImport> m_pMetaAsmImpApi;
        mutable mdAssembly m_token;
    };

    typedef BaseAssemblyMetadataProtoB8DF5A21<> AssemblyMetadataProtoB8DF5A21;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYMETADATAPROTOB8DF5A21_H