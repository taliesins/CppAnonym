#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATADISPENSERPROTOB8DF5A21_H
#define URASANDESU_CPPANONYM_METADATA_BASEMETADATADISPENSERPROTOB8DF5A21_H

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
                typedef typename type_decided_by<assembly_metadata_type>::type assembly_metadata_heap_type;
                assembly_metadata_heap_type &asmHeap = mutableThis->Of<assembly_metadata_type>();
                assembly_metadata_type *pAsmMeta = asmHeap.NewPseudo();
                pAsmMeta->Init(*mutableThis, pMetaImpApi);

                mda = pAsmMeta->GetToken();
                m_assemblyMetas[asmPath] = mda;

                asmHeap.SetToLast(mda);
                return pAsmMeta;
            }
            else
            {
                return LoadAssemblyFromTokenCore(mda);
            }
        }

        //assembly_metadata_type const *LoadAssemblyFromToken(mdAssembly mda) const
        //{
        //    return NULL;
        //}

    private:
        assembly_metadata_type const *LoadAssemblyFromTokenCore(mdAssembly mda) const
        {
            typedef typename type_decided_by<assembly_metadata_type>::type assembly_metadata_heap_type;
            assembly_metadata_heap_type const &asmHeap = Of<assembly_metadata_type>();
            return asmHeap.Get(mda);
        }

        struct IgnoreCaseHash
            : std::unary_function<boost::filesystem::path, std::size_t>
        {
            std::size_t operator()(boost::filesystem::path const &x) const
            {
                typedef boost::filesystem::path::string_type string_type;
                std::size_t seed = 0;

                string_type const &native = x.native();
                for (string_type::const_iterator i = native.begin(), i_end = native.end(); i != i_end; ++i)
                {
                    boost::hash_combine(seed, std::toupper(*i, std::locale()));
                }

                return seed;
            }
        };

        struct IgnoreCaseEqualTo
            : std::binary_function<boost::filesystem::path, boost::filesystem::path, bool>
        {
            bool operator()(boost::filesystem::path const &x, boost::filesystem::path const &y) const
            {
                return boost::algorithm::iequals(x.native(), y.native());
            }
        };

        mutable boost::unordered_map<boost::filesystem::path, mdAssembly, IgnoreCaseHash, IgnoreCaseEqualTo> m_assemblyMetas;
        mutable CComPtr<IMetaDataDispenserEx> m_pMetaDispApi;
    };

    typedef BaseMetadataDispenserProtoB8DF5A21<> MetadataDispenserProtoB8DF5A21;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATADISPENSERPROTOB8DF5A21_H