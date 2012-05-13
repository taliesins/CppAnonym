#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATADISPENSERPROTOB8DF5A21_H
#define URASANDESU_CPPANONYM_METADATA_BASEMETADATADISPENSERPROTOB8DF5A21_H

#ifndef URASANDESU_CPPANONYM_UTILITIES_DEFAULTHASH_H
#include <Urasandesu/CppAnonym/Utilities/DefaultHash.h>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_DEFAULTEQUALTO_H
#include <Urasandesu/CppAnonym/Utilities/DefaultEqualTo.h>
#endif

#ifndef URASANDESU_CPPANONYM_HEAPPROVIDERFWD_HPP
#include <Urasandesu/CppAnonym/HeapProviderFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    template<
        class AssemblyMetadataApiType
    >    
    class BaseAssemblyMetadataProtoB8DF5A21;

    template<
        class MetadataInfoApiType
    >    
    class BaseMetadataInfoProtoB8DF5A21;

    struct DefaultMetadataDispenserApiProtoB8DF5A21;

    struct IMetadataInfoApi;

    struct IAssemblyMetadataApi;

    struct IMetadataDispenserApi;

    template<
        class MetadataDispenserApiType = DefaultMetadataDispenserApiProtoB8DF5A21
    >    
    class BaseMetadataDispenserProtoB8DF5A21 :
        public HeapProvider<
            mdAssembly, 
            boost::mpl::vector<
                BaseAssemblyMetadataProtoB8DF5A21<typename Traits::ExternalApiOrDefault<MetadataDispenserApiType, IMetadataDispenserApi, IAssemblyMetadataApi>::type> 
            >
        >
    {
    public:
        typedef BaseMetadataDispenserProtoB8DF5A21<MetadataDispenserApiType> this_type;

        typedef typename Traits::ExternalApiOrDefault<MetadataDispenserApiType, IMetadataDispenserApi, IMetadataInfoApi>::type metadata_info_api_type;
        typedef BaseMetadataInfoProtoB8DF5A21<metadata_info_api_type> metadata_info_type;
        
        typedef typename Traits::ExternalApiOrDefault<MetadataDispenserApiType, IMetadataDispenserApi, IAssemblyMetadataApi>::type assembly_metadata_api_type;
        typedef BaseAssemblyMetadataProtoB8DF5A21<assembly_metadata_api_type> assembly_metadata_type;

        BaseMetadataDispenserProtoB8DF5A21() : 
            m_pMetaInfo(NULL)
        { }

        void Init(metadata_info_type &metaInfo) const
        {
            _ASSERTE(m_pMetaInfo == NULL);
            _ASSERTE(m_pMetaDispApi.p == NULL);

            m_pMetaInfo = &metaInfo;

            HRESULT hr = ::CoCreateInstance(CLSID_CorMetaDataDispenser, NULL, CLSCTX_INPROC_SERVER, 
                                            IID_IMetaDataDispenserEx, 
                                            reinterpret_cast<void **>(&m_pMetaDispApi));
            if (FAILED(hr))
                BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
        }

        template<class T>
        T const *FindType() const { return static_cast<metadata_info_type const *>(m_pMetaInfo)->FindType<T>(); }

        template<class T>
        T *FindType() { return m_pMetaInfo->FindType<T>(); }
      
        template<>
        this_type const *FindType<this_type>() const { return this; }
      
        template<>
        this_type *FindType<this_type>() { return this; }

        assembly_metadata_type const *LoadAssemblyFromFile(boost::filesystem::path const &asmPath) const
        {
            _ASSERTE(m_pMetaDispApi.p != NULL);

            if (m_assemblyMetas.find(asmPath) == m_assemblyMetas.end())
            {
                m_assemblyMetas[asmPath] = mdAssemblyNil;
            }

            mdAssembly mda = m_assemblyMetas[asmPath];
            if (mda == mdAssemblyNil)
            {
                ATL::CComPtr<IMetaDataImport2> pMetaImpApi;
                HRESULT hr = m_pMetaDispApi->OpenScope(asmPath.c_str(), ofRead, 
                                                    IID_IMetaDataImport2, 
                                                    reinterpret_cast<IUnknown **>(&pMetaImpApi));
                if (FAILED(hr))
                    BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

                this_type *mutableThis = const_cast<this_type *>(this);
                typedef typename type_decided_by<assembly_metadata_type>::type AssemblyMetadataHeap;
                AssemblyMetadataHeap &heap = mutableThis->Of<assembly_metadata_type>();
                assembly_metadata_type *pAsmMeta = heap.NewPseudo();
                pAsmMeta->Init(*mutableThis, *pMetaImpApi);

                mda = pAsmMeta->GetToken();
                m_assemblyMetas[asmPath] = mda;

                heap.SetToLast(mda);
                return pAsmMeta;
            }
            else
            {
                return LoadAssemblyFromTokenCore(mda);
            }
        }

    private:
        assembly_metadata_type const *LoadAssemblyFromTokenCore(mdAssembly mda) const
        {
            typedef typename type_decided_by<assembly_metadata_type>::type AssemblyMetadataHeap;
            AssemblyMetadataHeap const &heap = Of<assembly_metadata_type>();
            return heap.Get(mda);
        }

        mutable metadata_info_type *m_pMetaInfo;
        typedef boost::filesystem::path path;
        typedef Utilities::DefaultHash<path> path_hash;
        typedef Utilities::DefaultEqualTo<path, path> path_equal_to;
        mutable boost::unordered_map<path, mdAssembly, path_hash, path_equal_to> m_assemblyMetas;
        mutable ATL::CComPtr<IMetaDataDispenserEx> m_pMetaDispApi;
    };

    typedef BaseMetadataDispenserProtoB8DF5A21<> MetadataDispenserProtoB8DF5A21;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATADISPENSERPROTOB8DF5A21_H