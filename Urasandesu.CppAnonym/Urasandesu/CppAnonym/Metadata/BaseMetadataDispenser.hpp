#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATADISPENSER_HPP
#define URASANDESU_CPPANONYM_METADATA_BASEMETADATADISPENSER_HPP

#ifndef URASANDESU_CPPANONYM_UTILITIES_HASH_HPP
#include <Urasandesu/CppAnonym/Utilities/Hash.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_EQUALTO_HPP
#include <Urasandesu/CppAnonym/Utilities/EqualTo.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_HEAPPROVIDERFWD_HPP
#include <Urasandesu/CppAnonym/HeapProviderFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_CARTRIDGEAPISYSTEMFWD_HPP
#include <Urasandesu/CppAnonym/Traits/CartridgeApiSystemFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATAINFOFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseMetadataInfoFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_METADATAINFOAPIHOLDERLABELFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/MetadataInfoApiHolderLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_METADATAINFOLABELFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/MetadataInfoLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_DEFAULTMETADATADISPENSERAPIHOLDERFWD_H
#include <Urasandesu/CppAnonym/Metadata/DefaultMetadataDispenserApiHolderFwd.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATADISPENSERFWD_H
#include <Urasandesu/CppAnonym/Metadata/BaseMetadataDispenserFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_METADATADISPENSERAPIHOLDERLABELFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/MetadataDispenserApiHolderLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYMETADATAFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseAssemblyMetadataFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_ASSEMBLYMETADATALABELFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/AssemblyMetadataLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_ASSEMBLYMETADATAAPIHOLDERLABELFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/AssemblyMetadataApiHolderLabelFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    template<class ApiCartridgesHolder, class ApiLabel>
    struct MetadataDispenserApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, MetadataDispenserApiHolderLabel, ApiLabel>
    {
    };

    template<
        class MetadataDispenserApiHolder
    >    
    class BaseMetadataDispenser :
        public HeapProvider<
            mdAssembly, 
            boost::mpl::vector<
                typename MetadataDispenserApiAt<MetadataDispenserApiHolder, AssemblyMetadataLabel>::type
            >
        >
    {
    public:
        typedef BaseMetadataDispenser<MetadataDispenserApiHolder> this_type;

        typedef typename MetadataDispenserApiAt<MetadataDispenserApiHolder, MetadataInfoLabel>::type metadata_info_type;
        typedef typename MetadataDispenserApiAt<MetadataDispenserApiHolder, AssemblyMetadataLabel>::type assembly_metadata_type;

        BaseMetadataDispenser() : 
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
        typedef Utilities::Hash<path> path_hash;
        typedef Utilities::EqualTo<path, path> path_equal_to;
        mutable boost::unordered_map<path, mdAssembly, path_hash, path_equal_to> m_assemblyMetas;
        mutable ATL::CComPtr<IMetaDataDispenserEx> m_pMetaDispApi;
    };

    typedef BaseMetadataDispenser<> MetadataDispenser;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATADISPENSER_HPP