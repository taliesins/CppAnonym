#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATADISPENSERPROTOB8DF5A21_H
#define URASANDESU_CPPANONYM_METADATA_BASEMETADATADISPENSERPROTOB8DF5A21_H

#ifndef URASANDESU_CPPANONYM_UTILITIES_DEFAULTHASH_H
#include <Urasandesu/CppAnonym/Utilities/DefaultHash.h>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_DEFAULTEQUALTO_H
#include <Urasandesu/CppAnonym/Utilities/DefaultEqualTo.h>
#endif

namespace Urasandesu { namespace CppAnonym {

    template<class Key, class Sequence>
    class ATL_NO_VTABLE HeapProvider;

}}   // namespace Urasandesu { namespace CppAnonym {

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


    template<
        class MetadataDispenserApiType = DefaultMetadataDispenserApiProtoB8DF5A21
    >    
    class BaseMetadataDispenserProtoB8DF5A21 :
        public HeapProvider<
            mdAssembly, 
            boost::mpl::vector<
                BaseAssemblyMetadataProtoB8DF5A21<typename Traits::ChildApiOrDefault<MetadataDispenserApiType, IAssemblyMetadataApi>::type> 
            >
        >
    {
    public:
        typedef BaseMetadataDispenserProtoB8DF5A21<MetadataDispenserApiType> this_type;
        typedef typename Traits::ParentApiOrDefault<MetadataDispenserApiType, IMetadataInfoApi>::type metadata_info_api_type;
        typedef BaseMetadataInfoProtoB8DF5A21<metadata_info_api_type> metadata_info_type;
        typedef typename Traits::ChildApiOrDefault<MetadataDispenserApiType, IAssemblyMetadataApi>::type assembly_metadata_api_type;
        typedef BaseAssemblyMetadataProtoB8DF5A21<assembly_metadata_api_type> assembly_metadata_type;

        void Init(metadata_info_type &metaInfo) const
        {
            _ASSERTE(m_pMetaDispApi.p == NULL);

            HRESULT hr = ::CoCreateInstance(CLSID_CorMetaDataDispenser, NULL, CLSCTX_INPROC_SERVER, 
                                            IID_IMetaDataDispenserEx, 
                                            reinterpret_cast<void **>(&m_pMetaDispApi));
            if (FAILED(hr))
                BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
        }

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
                CComPtr<IMetaDataImport2> pMetaImpApi;
                HRESULT hr = m_pMetaDispApi->OpenScope(asmPath.c_str(), ofRead, 
                                                    IID_IMetaDataImport2, 
                                                    reinterpret_cast<IUnknown **>(&pMetaImpApi));
                if (FAILED(hr))
                    BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

                this_type *mutableThis = const_cast<this_type *>(this);
                typedef typename type_decided_by<assembly_metadata_type>::type AssemblyMetadataHeap;
                AssemblyMetadataHeap &heap = mutableThis->Of<assembly_metadata_type>();
                assembly_metadata_type *pAsmMeta = heap.NewPseudo();
                pAsmMeta->Init(*mutableThis, pMetaImpApi);

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

        typedef boost::filesystem::path path;
        mutable boost::unordered_map<path, mdAssembly, Utilities::DefaultHash<path>, Utilities::DefaultEqualTo<path, path>> m_assemblyMetas;
        mutable CComPtr<IMetaDataDispenserEx> m_pMetaDispApi;
    };

    typedef BaseMetadataDispenserProtoB8DF5A21<> MetadataDispenserProtoB8DF5A21;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATADISPENSERPROTOB8DF5A21_H