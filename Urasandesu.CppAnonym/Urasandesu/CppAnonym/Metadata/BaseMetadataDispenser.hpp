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

#ifndef URASANDESU_CPPANONYM_SIMPLEHEAPPROVIDERFWD_HPP
#include <Urasandesu/CppAnonym/SimpleHeapProviderFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_OBJECTTAG_HPP
#include <Urasandesu/CppAnonym/ObjectTag.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_CARTRIDGEAPISYSTEMFWD_HPP
#include <Urasandesu/CppAnonym/Traits/CartridgeApiSystemFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATAINFOFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseMetadataInfoFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_METADATAINFOAPIHOLDERLABELFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/MetadataInfoApiHolderLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_METADATAINFOLABELFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/MetadataInfoLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMETADATADISPENSERAPIHOLDERFWD_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultMetadataDispenserApiHolderFwd.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATADISPENSERFWD_H
#include <Urasandesu/CppAnonym/Metadata/BaseMetadataDispenserFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_METADATADISPENSERAPIHOLDERLABELFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/MetadataDispenserApiHolderLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYMETADATAFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseAssemblyMetadataFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_ASSEMBLYMETADATALABELFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/AssemblyMetadataLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_ASSEMBLYMETADATAAPIHOLDERLABELFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/AssemblyMetadataApiHolderLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_ASSEMBLYNAMEMETADATALABELFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/AssemblyNameMetadataLabelFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    template<class ApiCartridgesHolder, class ApiLabel>
    struct MetadataDispenserApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::MetadataDispenserApiHolderLabel, ApiLabel>
    {
    };

    template<
        class MetadataDispenserApiHolder
    >    
    class BaseMetadataDispenser :
        public HeapProvider<
            mdAssembly, 
            boost::mpl::vector<
                typename MetadataDispenserApiAt<MetadataDispenserApiHolder, Interfaces::AssemblyMetadataLabel>::type
            >
        >,
        public SimpleHeapProvider<
            boost::mpl::vector<
                ObjectTag<typename MetadataDispenserApiAt<MetadataDispenserApiHolder, Interfaces::AssemblyNameMetadataLabel>::type, QuickHeap>
            >
        >
    {
    public:
        typedef BaseMetadataDispenser<MetadataDispenserApiHolder> this_type;

        typedef typename MetadataDispenserApiAt<MetadataDispenserApiHolder, Interfaces::MetadataInfoLabel>::type metadata_info_type;
        typedef typename MetadataDispenserApiAt<MetadataDispenserApiHolder, Interfaces::AssemblyNameMetadataLabel>::type assembly_name_metadata_type;
        typedef typename MetadataDispenserApiAt<MetadataDispenserApiHolder, Interfaces::AssemblyMetadataLabel>::type assembly_metadata_type;

        typedef ObjectTag<assembly_name_metadata_type, QuickHeap> assembly_name_metadata_obj_tag_type;
        typedef SimpleHeapProvider<boost::mpl::vector<assembly_name_metadata_obj_tag_type> > simple_heap_provider_type;
        typedef typename simple_heap_provider_type::type_decided_by<assembly_name_metadata_obj_tag_type>::type assembly_name_metadata_heap_type;

        typedef HeapProvider<mdAssembly, boost::mpl::vector<assembly_metadata_type> > heap_provider_type;
        typedef typename heap_provider_type::type_decided_by<assembly_metadata_type>::type assembly_metadata_heap_type;

        BaseMetadataDispenser() : 
            m_pMetaInfo(NULL)
        { }

        void Init(metadata_info_type &metaInfo) const
        {
            // This method implementation is temporary.
            _ASSERTE(m_pMetaInfo == NULL);
            //_ASSERTE(m_pMetaDispApi.p == NULL);

            m_pMetaInfo = &metaInfo;

            //HRESULT hr = ::CoCreateInstance(CLSID_CorMetaDataDispenser, NULL, CLSCTX_INPROC_SERVER, 
            //                                IID_IMetaDataDispenserEx, 
            //                                reinterpret_cast<void **>(&m_pMetaDispApi));
            //if (FAILED(hr))
            //    BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
        }

        template<class T>
        T const *FindType() const { return static_cast<metadata_info_type const *>(m_pMetaInfo)->FindType<T>(); }

        template<class T>
        T *FindType() { return m_pMetaInfo->FindType<T>(); }
      
        template<>
        this_type const *FindType<this_type>() const { return this; }
      
        template<>
        this_type *FindType<this_type>() { return this; }

        assembly_name_metadata_type *NewAssemblyName(std::wstring const &name) const
        {
            this_type *mutableThis = const_cast<this_type *>(this);

            assembly_name_metadata_type *pAsmNameMeta = NULL;
            pAsmNameMeta = mutableThis->AssemblyNameMetadataHeap().New();
            pAsmNameMeta->SetName(name);
            pAsmNameMeta->SetResolutionScope(*mutableThis);
            return pAsmNameMeta;
        }

        assembly_metadata_type const *LoadAssemblyFromFile(boost::filesystem::path const &asmPath) const
        {
            // This method implementation is temporary.
            this_type *mutableThis = const_cast<this_type *>(this);

            assembly_metadata_type *pAsmMeta = NULL;
            pAsmMeta = mutableThis->AssemblyMetadataHeap().New(0x20000001);
            pAsmMeta->Init(*mutableThis);
            return pAsmMeta;
            //_ASSERTE(m_pMetaDispApi.p != NULL);

            //if (m_assemblyMetas.find(asmPath) == m_assemblyMetas.end())
            //{
            //    m_assemblyMetas[asmPath] = mdAssemblyNil;
            //}

            //mdAssembly mda = m_assemblyMetas[asmPath];
            //if (mda == mdAssemblyNil)
            //{
            //    ATL::CComPtr<IMetaDataImport2> pMetaImpApi;
            //    HRESULT hr = m_pMetaDispApi->OpenScope(asmPath.c_str(), ofRead, 
            //                                        IID_IMetaDataImport2, 
            //                                        reinterpret_cast<IUnknown **>(&pMetaImpApi));
            //    if (FAILED(hr))
            //        BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

            //    this_type *mutableThis = const_cast<this_type *>(this);
            //    typedef typename type_decided_by<assembly_metadata_type>::type AssemblyMetadataHeap;
            //    AssemblyMetadataHeap &heap = mutableThis->Of<assembly_metadata_type>();
            //    assembly_metadata_type *pAsmMeta = heap.NewPseudo();
            //    pAsmMeta->Init(*mutableThis, *pMetaImpApi);

            //    mda = pAsmMeta->GetToken();
            //    m_assemblyMetas[asmPath] = mda;

            //    heap.SetToLast(mda);
            //    return pAsmMeta;
            //}
            //else
            //{
            //    return LoadAssemblyFromTokenCore(mda);
            //}
        }

    private:
        template<
            class AssemblyMetadataApiHolder
        >
        friend class BaseAssemblyMetadata;
        
        assembly_name_metadata_heap_type &AssemblyNameMetadataHeap()
        {
            return simple_heap_provider_type::Of<assembly_name_metadata_obj_tag_type>();
        }
        
        assembly_name_metadata_heap_type const &AssemblyNameMetadataHeap() const
        {
            return simple_heap_provider_type::Of<assembly_name_metadata_obj_tag_type>();
        }

        assembly_metadata_heap_type &AssemblyMetadataHeap()
        {
            return heap_provider_type::Of<assembly_metadata_type>();
        }
        
        assembly_metadata_heap_type const &AssemblyMetadataHeap() const
        {
            return heap_provider_type::Of<assembly_metadata_type>();
        }

        assembly_metadata_type const *LoadAssemblyFromTokenCore(mdAssembly mda) const
        {
            typedef typename type_decided_by<assembly_metadata_type>::type AssemblyMetadataHeap;
            AssemblyMetadataHeap const &heap = Of<assembly_metadata_type>();
            return heap.Get(mda);
        }

        mutable metadata_info_type *m_pMetaInfo;
        typedef boost::filesystem::path path;
        typedef Utilities::Hash<path> path_hash;
        typedef Utilities::EqualTo<path> path_equal_to;
        mutable boost::unordered_map<path, mdAssembly, path_hash, path_equal_to> m_assemblyMetas;
        mutable ATL::CComPtr<IMetaDataDispenserEx> m_pMetaDispApi;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATADISPENSER_HPP