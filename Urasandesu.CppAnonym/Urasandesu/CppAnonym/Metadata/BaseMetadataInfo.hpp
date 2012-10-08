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

#ifndef URASANDESU_CPPANONYM_HOSTING_PORTABLEEXECUTABLEKINDS_HPP
#include <Urasandesu/CppAnonym/Hosting/PortableExecutableKinds.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_HOSTING_IMAGEFILEMACHINE_HPP
#include <Urasandesu/CppAnonym/Hosting/ImageFileMachine.hpp>
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
                //ObjectTag<typename MetadataInfoApiAt<MetadataInfoApiHolder, Hosting::Interfaces::PEWriterHostLabel>::type, QuickHeap>
            >
        >
    {
    public:
        typedef BaseMetadataInfo<MetadataInfoApiHolder> this_type;

        typedef typename MetadataInfoApiAt<MetadataInfoApiHolder, Hosting::Interfaces::RuntimeHostLabel>::type runtime_host_type;
        typedef typename MetadataInfoApiAt<MetadataInfoApiHolder, Interfaces::MetadataDispenserLabel>::type metadata_dispenser_type;
        //typedef typename MetadataInfoApiAt<MetadataInfoApiHolder, Hosting::Interfaces::PEWriterHostLabel>::type pe_writer_host_type;

        typedef ObjectTag<metadata_dispenser_type, QuickHeap> metadata_dispenser_obj_tag_type;
        typedef typename type_decided_by<metadata_dispenser_obj_tag_type>::type metadata_dispenser_heap_type;
        //typedef ObjectTag<pe_writer_host_type, QuickHeap> pe_writer_host_obj_tag_type;
        //typedef typename type_decided_by<pe_writer_host_obj_tag_type>::type pe_writer_host_heap_type;
        
        BaseMetadataInfo() : 
            m_pRuntimeHost(NULL)
        { }

        void Init(runtime_host_type &runtimeHost) const
        {
            _ASSERTE(m_pRuntimeHost == NULL);
                
            m_pRuntimeHost = &runtimeHost;
        }

        template<class T>
        T const &Map() const { return const_cast<this_type *>(this)->Map<T>(); }

        template<class T>
        T &Map() { _ASSERTE(m_pRuntimeHost != NULL); return m_pRuntimeHost->Map<T>(); }
      
        template<>
        this_type const &Map<this_type>() const { return *this; }
      
        template<>
        this_type &Map<this_type>() { return *this; }

        // このレベルに ICeeFileGen をハンドリングするオブジェクトを生成する層を作ったほうが良さそうね。
        // TODO: 名前合わせ
        metadata_dispenser_type *CreateDispenser() const
        {
            this_type *pMutableThis = const_cast<this_type *>(this);
            metadata_dispenser_type *pMetaDisp = NULL;
            pMetaDisp = pMutableThis->MetadataDispenserHeap().New();
            pMetaDisp->Init(*pMutableThis);

            return pMetaDisp;
        }

        //pe_writer_host_type *NewPortableExecutableFile(std::wstring const &name, 
        //                                                         PortableExecutableKinds const &portableExecutableKind, 
        //                                                         ImageFileMachine const &imageFileMachine) const
        //{
        //    this_type *pMutableThis = const_cast<this_type *>(this);

        //    pe_writer_host_type *pPEFile = NULL;
        //    pPEFile = pMutableThis->PortableExecutableFileHeap().New();
        //    pPEFile->Init(*pMutableThis);
        //    pPEFile->SetName(name);
        //    pPEFile->SetPortableExecutableKind(portableExecutableKind);
        //    pPEFile->SetImageFileMachine(imageFileMachine);
        //    return pPEFile;
        //}

    private:
        metadata_dispenser_heap_type &MetadataDispenserHeap()
        {
            return Of<metadata_dispenser_obj_tag_type>();
        }
        
        metadata_dispenser_heap_type const &MetadataDispenserHeap() const
        {
            return Of<metadata_dispenser_obj_tag_type>();
        }

        //pe_writer_host_heap_type &PortableExecutableFileHeap()
        //{
        //    return Of<pe_writer_host_obj_tag_type>();
        //}
        //
        //pe_writer_host_heap_type const &PortableExecutableFileHeap() const
        //{
        //    return Of<pe_writer_host_obj_tag_type>();
        //}

        mutable runtime_host_type *m_pRuntimeHost;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATAINFO_HPP