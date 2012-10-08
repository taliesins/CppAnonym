#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATAINFO_HPP
#define URASANDESU_CPPANONYM_METADATA_BASEMETADATAINFO_HPP

#ifndef URASANDESU_CPPANONYM_IHEAPCONTENT_H
#include <Urasandesu/CppAnonym/IHeapContent.h>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_CARTRIDGEAPISYSTEM_HPP
#include <Urasandesu/CppAnonym/Traits/CartridgeApiSystem.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_SIMPLEHEAPPROVIDER_HPP
#include <Urasandesu/CppAnonym/SimpleHeapProvider.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_HOSTING_INTERFACES_RUNTIMEHOSTLABEL_HPP
#include <Urasandesu/CppAnonym/Hosting/Interfaces/RuntimeHostLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_HOSTING_INTERFACES_RUNTIMEHOSTAPIHOLDERLABEL_HPP
#include <Urasandesu/CppAnonym/Hosting/Interfaces/RuntimeHostApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_METADATAINFOAPIHOLDERLABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/MetadataInfoApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_METADATADISPENSERAPIHOLDERLABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/MetadataDispenserApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_METADATADISPENSERLABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/MetadataDispenserLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATAINFOFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseMetadataInfoFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    template<class ApiCartridgesHolder, class ApiLabel>
    struct MetadataInfoApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::MetadataInfoApiHolderLabel, ApiLabel>
    {
    };

    template<
        class MetadataInfoApiHolder
    >    
    class BaseMetadataInfo :
        public IHeapContent<std::wstring>,
        public SimpleHeapProvider<
            boost::mpl::vector<
                ObjectTag<typename MetadataInfoApiAt<MetadataInfoApiHolder, Interfaces::MetadataDispenserLabel>::type, QuickHeap>
            >
        >
    {
    public:
        typedef BaseMetadataInfo<MetadataInfoApiHolder> this_type;

        typedef typename MetadataInfoApiAt<MetadataInfoApiHolder, Hosting::Interfaces::RuntimeHostLabel>::type runtime_host_type;
        typedef typename MetadataInfoApiAt<MetadataInfoApiHolder, Interfaces::MetadataDispenserLabel>::type metadata_dispenser_type;

        typedef ObjectTag<metadata_dispenser_type, QuickHeap> metadata_dispenser_obj_tag_type;
        typedef SimpleHeapProvider<boost::mpl::vector<metadata_dispenser_obj_tag_type> > simple_heap_provider_type;
        typedef typename simple_heap_provider_type::type_decided_by<metadata_dispenser_obj_tag_type>::type metadata_dispenser_heap_type;
        
        BaseMetadataInfo() : 
            m_pRuntimeHost(NULL)
        { }

        void Init(runtime_host_type &runtimeHost) const
        {
            _ASSERTE(m_pRuntimeHost == NULL);
                
            m_pRuntimeHost = &runtimeHost;
        }

        template<class T>
        T const &Map() const { return static_cast<runtime_host_type const *>(m_pRuntimeHost)->Map<T>(); }

        template<class T>
        T &Map() { return m_pRuntimeHost->Map<T>(); }
      
        template<>
        this_type const &Map<this_type>() const { return this; }
      
        template<>
        this_type &Map<this_type>() { return this; }

        // このレベルに ICeeFileGen をハンドリングするオブジェクトを生成する層を作ったほうが良さそうね。
        metadata_dispenser_type *CreateDispenser() const
        {
            this_type *pMutableThis = const_cast<this_type *>(this);
            metadata_dispenser_type *pMetaDisp = NULL;
            pMetaDisp = pMutableThis->MetadataDispenserHeap().New();
            pMetaDisp->Init(*pMutableThis);

            return pMetaDisp;
        }

    private:
        metadata_dispenser_heap_type &MetadataDispenserHeap()
        {
            return simple_heap_provider_type::Of<metadata_dispenser_obj_tag_type>();
        }
        
        metadata_dispenser_heap_type const &MetadataDispenserHeap() const
        {
            return simple_heap_provider_type::Of<metadata_dispenser_obj_tag_type>();
        }

        mutable runtime_host_type *m_pRuntimeHost;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATAINFO_HPP