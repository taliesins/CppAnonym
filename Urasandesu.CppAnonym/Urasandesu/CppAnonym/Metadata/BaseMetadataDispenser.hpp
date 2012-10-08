#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATADISPENSER_HPP
#define URASANDESU_CPPANONYM_METADATA_BASEMETADATADISPENSER_HPP

#ifndef URASANDESU_CPPANONYM_UTILITIES_HASH_HPP
#include <Urasandesu/CppAnonym/Utilities/Hash.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_EQUALTO_HPP
#include <Urasandesu/CppAnonym/Utilities/EqualTo.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_HEAPPROVIDER_HPP
#include <Urasandesu/CppAnonym/HeapProvider.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_SIMPLEHEAPPROVIDER_HPP
#include <Urasandesu/CppAnonym/SimpleHeapProvider.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_OBJECTTAG_HPP
#include <Urasandesu/CppAnonym/ObjectTag.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_CARTRIDGEAPISYSTEM_HPP
#include <Urasandesu/CppAnonym/Traits/CartridgeApiSystem.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_METADATAINFOAPIHOLDERLABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/MetadataInfoApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_METADATAINFOLABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/MetadataInfoLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_METADATADISPENSERAPIHOLDERLABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/MetadataDispenserApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_ASSEMBLYMETADATALABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/AssemblyMetadataLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_ASSEMBLYMETADATAAPIHOLDERLABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/AssemblyMetadataApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_ASSEMBLYNAMEMETADATALABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/AssemblyNameMetadataLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_INTERFACES_STRONGNAMEKEYLABEL_HPP
#include <Urasandesu/CppAnonym/StrongNaming/Interfaces/StrongNameKeyLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATADISPENSERFWD_H
#include <Urasandesu/CppAnonym/Metadata/BaseMetadataDispenserFwd.hpp>
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
        public SimpleHeapProvider<
            boost::mpl::vector<
                ObjectTag<typename MetadataDispenserApiAt<MetadataDispenserApiHolder, Interfaces::AssemblyMetadataLabel>::type, QuickHeap>,
                ObjectTag<typename MetadataDispenserApiAt<MetadataDispenserApiHolder, Interfaces::AssemblyNameMetadataLabel>::type, QuickHeap>,
                ObjectTag<typename MetadataDispenserApiAt<MetadataDispenserApiHolder, Interfaces::AssemblyNameMetadataGeneratorLabel>::type, QuickHeap>
            >
        >
    {
    public:
        typedef BaseMetadataDispenser<MetadataDispenserApiHolder> this_type;

        typedef typename MetadataDispenserApiAt<MetadataDispenserApiHolder, Interfaces::MetadataInfoLabel>::type metadata_info_type;
        typedef typename MetadataDispenserApiAt<MetadataDispenserApiHolder, Interfaces::AssemblyNameMetadataLabel>::type assembly_name_metadata_type;
        typedef typename MetadataDispenserApiAt<MetadataDispenserApiHolder, Interfaces::AssemblyMetadataLabel>::type assembly_metadata_type;
        typedef typename MetadataDispenserApiAt<MetadataDispenserApiHolder, IMetaDataDispenserEx>::type com_meta_data_dispenser_type;        
        typedef typename MetadataDispenserApiAt<MetadataDispenserApiHolder, Interfaces::AssemblyNameMetadataGeneratorLabel>::type assembly_name_metadata_generator_type;        
        typedef typename MetadataDispenserApiAt<MetadataDispenserApiHolder, StrongNaming::Interfaces::StrongNameKeyLabel>::type strong_name_key_type;
        typedef typename MetadataDispenserApiAt<MetadataDispenserApiHolder, Interfaces::AssemblyMetadataGeneratorLabel>::type assembly_metadata_generator_type;        

        typedef ObjectTag<assembly_metadata_type, QuickHeap> assembly_metadata_obj_tag_type;
        typedef typename type_decided_by<assembly_metadata_obj_tag_type>::type assembly_metadata_heap_type;
        typedef ObjectTag<assembly_name_metadata_type, QuickHeap> assembly_name_metadata_obj_tag_type;
        typedef typename type_decided_by<assembly_name_metadata_obj_tag_type>::type assembly_name_metadata_heap_type;
        typedef ObjectTag<assembly_name_metadata_generator_type, QuickHeap> assembly_name_metadata_generator_obj_tag_type;
        typedef typename type_decided_by<assembly_name_metadata_generator_obj_tag_type>::type assembly_name_metadata_generator_heap_type;

        BaseMetadataDispenser() : 
            m_pMetaInfo(NULL)
        { }

        void Init(metadata_info_type &metaInfo) const
        {
            _ASSERTE(m_pMetaInfo == NULL);
            m_pMetaInfo = &metaInfo;
        }

        template<class T>
        T const &Map() const { _ASSERTE(m_pMetaInfo != NULL); return static_cast<metadata_info_type const *>(m_pMetaInfo)->Map<T>(); }

        template<class T>
        T &Map() { _ASSERTE(m_pMetaInfo != NULL); return m_pMetaInfo->Map<T>(); }
      
        template<>
        this_type const &Map<this_type>() const { return *this; }
      
        template<>
        this_type &Map<this_type>() { return *this; }

        assembly_name_metadata_type *NewAssemblyName(std::wstring const &name) const
        {
            this_type *pMutableThis = const_cast<this_type *>(this);

            assembly_name_metadata_type *pAsmNameMeta = NULL;
            pAsmNameMeta = pMutableThis->AssemblyNameMetadataHeap().New();
            pAsmNameMeta->Init(*pMutableThis);
            pAsmNameMeta->SetName(name);
            //pAsmNameMeta->SetName(name);
            //pAsmNameMeta->SetResolutionScope(*pMutableThis);
            return pAsmNameMeta;
        }

        assembly_metadata_type const *LoadAssembly(std::wstring const &name) const
        {
            if (m_asmStrNameToIndex.find(name) == m_asmStrNameToIndex.end())
            {
                m_asmStrNameToIndex[name] = MAXULONG_PTR;
            }

            SIZE_T index = m_asmStrNameToIndex[name];
            if (index == MAXULONG_PTR)
            {
                assembly_name_metadata_type *pAsmNameMeta = NULL;
                pAsmNameMeta = NewAssemblyName(name);

                assembly_metadata_type const *pAsmMeta = NULL;
                pAsmMeta = pAsmNameMeta->Resolve(); // Internally, LoadAssemblyFromFile is dispatched. 
                m_asmStrNameToIndex[name] = AssemblyMetadataHeap().Size() - 1;

                return pAsmMeta;
            }
            else
            {
                return AssemblyMetadataHeap()[index];
            }
        }

        assembly_metadata_type const *LoadAssemblyFromFile(boost::filesystem::path const &asmPath) const
        {
            if (m_asmPathToToIndex.find(asmPath) == m_asmPathToToIndex.end())
            {
                m_asmPathToToIndex[asmPath] = MAXULONG_PTR;
            }

            SIZE_T index = m_asmPathToToIndex[asmPath];
            if (index == MAXULONG_PTR)
            {
                this_type *pMutableThis = const_cast<this_type *>(this);

                assembly_metadata_type *pAsmMeta = NULL;
                pAsmMeta = pMutableThis->AssemblyMetadataHeap().New();
                pAsmMeta->Init(*pMutableThis);
                pAsmMeta->SetAssemblyFilePath(asmPath);

                m_asmPathToToIndex[asmPath] = pMutableThis->AssemblyMetadataHeap().Size() - 1;

                return pAsmMeta;
            }
            else
            {
                return AssemblyMetadataHeap()[index];
            }
        }

        assembly_name_metadata_generator_type *NewAssemblyNameGenerator(std::wstring const &name)
        {
            this_type *pMutableThis = const_cast<this_type *>(this);

            assembly_name_metadata_generator_type *pAsmNameMetaGen = NULL;
            pAsmNameMetaGen = pMutableThis->AssemblyNameMetadataGeneratorHeap().New();
            pAsmNameMetaGen->Init(*pMutableThis);
            pAsmNameMetaGen->SetName(name);
            return pAsmNameMetaGen;
        }

        assembly_metadata_generator_type *DefineAssembly(std::wstring const &name, strong_name_key_type const &snKey)
        {
            BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
        }

    private:
        friend typename assembly_metadata_type;

        assembly_name_metadata_heap_type &AssemblyNameMetadataHeap()
        {
            return Of<assembly_name_metadata_obj_tag_type>();
        }
        
        assembly_name_metadata_heap_type const &AssemblyNameMetadataHeap() const
        {
            return Of<assembly_name_metadata_obj_tag_type>();
        }

        assembly_metadata_heap_type &AssemblyMetadataHeap()
        {
            return Of<assembly_metadata_obj_tag_type>();
        }
        
        assembly_metadata_heap_type const &AssemblyMetadataHeap() const
        {
            return Of<assembly_metadata_obj_tag_type>();
        }

        assembly_name_metadata_generator_heap_type &AssemblyNameMetadataGeneratorHeap()
        {
            return Of<assembly_name_metadata_generator_obj_tag_type>();
        }
        
        assembly_name_metadata_generator_heap_type const &AssemblyNameMetadataGeneratorHeap() const
        {
            return Of<assembly_name_metadata_generator_obj_tag_type>();
        }

        com_meta_data_dispenser_type &GetCOMMetaDataDispenser()
        {
            if (m_pComMetaDisp.p == NULL)
            {
                HRESULT hr = ::CoCreateInstance(CLSID_CorMetaDataDispenser, NULL, CLSCTX_INPROC_SERVER, 
                                                IID_IMetaDataDispenserEx, 
                                                reinterpret_cast<void **>(&m_pComMetaDisp));
                if (FAILED(hr))
                    BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
            }
            return *m_pComMetaDisp;
        }

        mutable metadata_info_type *m_pMetaInfo;
        typedef boost::filesystem::path path;
        typedef Utilities::Hash<path> path_hash;
        typedef Utilities::EqualTo<path> path_equal_to;
        mutable boost::unordered_map<std::wstring, mdToken> m_asmStrNameToIndex;
        mutable boost::unordered_map<path, mdToken, path_hash, path_equal_to> m_asmPathToToIndex;
        mutable ATL::CComPtr<com_meta_data_dispenser_type> m_pComMetaDisp;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATADISPENSER_HPP