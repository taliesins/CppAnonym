#pragma once
#ifndef URASANDESU_CPPANONYM_HOSTING_BASERUNTIMEHOST_HPP
#define URASANDESU_CPPANONYM_HOSTING_BASERUNTIMEHOST_HPP

#ifndef URASANDESU_CPPANONYM_IHEAPCONTENT_H
#include <Urasandesu/CppAnonym/IHeapContent.h>
#endif

#ifndef URASANDESU_CPPANONYM_HEAPPROVIDER_HPP
#include <Urasandesu/CppAnonym/HeapProvider.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_SIMPLEHEAPPROVIDER_HPP
#include <Urasandesu/CppAnonym/SimpleHeapProvider.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_CARTRIDGEAPISYSTEM_HPP
#include <Urasandesu/CppAnonym/Traits/CartridgeApiSystem.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_TYPEINFO_HPP
#include <Urasandesu/CppAnonym/Utilities/TypeInfo.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_HOSTING_PORTABLEEXECUTABLEKINDS_HPP
#include <Urasandesu/CppAnonym/Hosting/PortableExecutableKinds.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_HOSTING_IMAGEFILEMACHINE_HPP
#include <Urasandesu/CppAnonym/Hosting/ImageFileMachine.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_HOSTING_INTERFACES_RUNTIMEHOSTAPIHOLDERLABEL_HPP
#include <Urasandesu/CppAnonym/Hosting/Interfaces/RuntimeHostApiHolderLabel.hpp>
#endif
//
//#ifndef URASANDESU_CPPANONYM_HOSTING_APIHOLDERS_DEFAULTRUNTIMEHOSTAPIHOLDER_H
//#include <Urasandesu/CppAnonym/Hosting/ApiHolders/DefaultRuntimeHostApiHolder.h>
//#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_INTERFACES_STRONGNAMEINFOLABEL_HPP
#include <Urasandesu/CppAnonym/StrongNaming/Interfaces/StrongNameInfoLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_METADATAINFOLABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/MetadataInfoLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_FUSION_INTERFACES_FUSIONINFOLABEL_HPP
#include <Urasandesu/CppAnonym/Fusion/Interfaces/FusionInfoLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMCOMEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymCOMException.h>
#endif

#ifndef URASANDESU_CPPANONYM_HOSTING_BASERUNTIMEHOSTFWD_HPP
#include <Urasandesu/CppAnonym/Hosting/BaseRuntimeHostFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Hosting {

    template<class ApiCartridgesHolder, class ApiLabel>
    struct RuntimeHostApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::RuntimeHostApiHolderLabel, ApiLabel>
    {
    };

    template<
        class RuntimeHostApiHolder
    >
    class BaseRuntimeHost : 
        public IHeapContent<std::wstring>, 
        public HeapProvider<
            std::wstring, 
            boost::mpl::vector<
                typename RuntimeHostApiAt<RuntimeHostApiHolder, StrongNaming::Interfaces::StrongNameInfoLabel>::type, 
                typename RuntimeHostApiAt<RuntimeHostApiHolder, Metadata::Interfaces::MetadataInfoLabel>::type, 
                typename RuntimeHostApiAt<RuntimeHostApiHolder, Fusion::Interfaces::FusionInfoLabel>::type
            >
        >,
        public SimpleHeapProvider<
            boost::mpl::vector<
                ObjectTag<typename RuntimeHostApiAt<RuntimeHostApiHolder, Interfaces::PEWriterHostLabel>::type, QuickHeap>
            >
        >
    {
    public:
        typedef BaseRuntimeHost<RuntimeHostApiHolder> this_type;
        
        typedef typename RuntimeHostApiAt<RuntimeHostApiHolder, StrongNaming::Interfaces::StrongNameInfoLabel>::type strong_name_info_type;
        typedef typename RuntimeHostApiAt<RuntimeHostApiHolder, Metadata::Interfaces::MetadataInfoLabel>::type metadata_info_type;
        typedef typename RuntimeHostApiAt<RuntimeHostApiHolder, Fusion::Interfaces::FusionInfoLabel>::type fusion_info_type;
        typedef typename RuntimeHostApiAt<RuntimeHostApiHolder, Interfaces::PEWriterHostLabel>::type pe_writer_host_type;        

        typedef HeapProvider<std::wstring, boost::mpl::vector<strong_name_info_type, metadata_info_type, fusion_info_type> > heap_provider_type;

        typedef ObjectTag<pe_writer_host_type, QuickHeap> pe_writer_host_obj_tag_type;
        typedef SimpleHeapProvider<boost::mpl::vector<pe_writer_host_obj_tag_type> > simple_heap_provider_type;
        typedef typename simple_heap_provider_type::type_decided_by<pe_writer_host_obj_tag_type>::type pe_writer_host_heap_type;

        BaseRuntimeHost() : 
            m_corVersionInitialized(false), 
            m_corSystemDirectoryPathInitialized(false)
        { }

        template<class T>
        T const &Map() const { return const_cast<this_type *>(this)->Map<T>(); }

        template<class T>
        T &Map() { return GetInfo<T>(); }
      
        template<>
        this_type const &Map<this_type>() const { return *this; }
      
        template<>
        this_type &Map<this_type>() { return *this; }
        
        std::wstring const &GetCORVersion() const
        {
            if (!m_corVersionInitialized)
            {
                WCHAR buffer[MAX_PATH] = { 0 };
                DWORD bufferSize = MAX_PATH - 1;
                DWORD length = 0;

#pragma warning(push)
#pragma warning(disable: 4996)
                HRESULT hr = ::GetCORVersion(buffer, bufferSize, &length);
#pragma warning(pop)
                if (FAILED(hr))
                    BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
                
                m_corVersion = buffer;

                m_corVersionInitialized = true;
            }
            return m_corVersion;
        }

        boost::filesystem::path const &GetCORSystemDirectoryPath() const
        {
            using namespace boost::filesystem;

            if (!m_corSystemDirectoryPathInitialized)
            {
                WCHAR buffer[MAX_PATH] = { 0 };
                DWORD bufferSize = MAX_PATH - 1;
                DWORD length = 0;

#pragma warning(push)
#pragma warning(disable: 4996)
                HRESULT hr = ::GetCORSystemDirectory(buffer, bufferSize, &length);
#pragma warning(pop)
                if (FAILED(hr))
                    BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

                m_corSystemDirectoryPath = buffer;
                
                m_corSystemDirectoryPathInitialized = true;
            }
            return m_corSystemDirectoryPath;
        }

        pe_writer_host_type *NewPEWriter(std::wstring const &name, 
                                         PortableExecutableKinds const &portableExecutableKind, 
                                         ImageFileMachine const &imageFileMachine) const
        {
            this_type *pMutableThis = const_cast<this_type *>(this);

            pe_writer_host_type *pPEWriterHost = NULL;
            pPEWriterHost = pMutableThis->PEWriterHostHeap().New();
            pPEWriterHost->Init(*pMutableThis);
            pPEWriterHost->SetName(name);
            pPEWriterHost->SetPortableExecutableKind(portableExecutableKind);
            pPEWriterHost->SetImageFileMachine(imageFileMachine);
            return pPEWriterHost;
        }
    
    private:

        pe_writer_host_heap_type &PEWriterHostHeap()
        {
            return simple_heap_provider_type::Of<pe_writer_host_obj_tag_type>();
        }
        
        pe_writer_host_heap_type const &PEWriterHostHeap() const
        {
            return simple_heap_provider_type::Of<pe_writer_host_obj_tag_type>();
        }

        template<class InfoType>
        InfoType &GetInfo()
        {
            namespace mpl = boost::mpl;
            using namespace boost;
            
            typedef mpl::find<sequence_type, InfoType>::type I;
            typedef mpl::end<sequence_type>::type IEnd;
            BOOST_MPL_ASSERT((mpl::not_<boost::is_same<I, IEnd> >));

            Utilities::TypeInfo info = mpl::identity<InfoType>();
            if (m_infos.find(info) == m_infos.end())
            {
                m_infos[info] = NULL;
            }

            InfoType *pInfo = static_cast<InfoType *>(m_infos[info]);
            if (pInfo == NULL)
            {
                typedef typename heap_provider_type::type_decided_by<InfoType>::type InfoHeap;
                InfoHeap &heap = heap_provider_type::Of<InfoType>();
                pInfo = heap.New(GetCORVersion());
                pInfo->Init(*this);
                m_infos[info] = pInfo;
            }

            return *pInfo;
        }

        mutable boost::unordered_map<Utilities::TypeInfo, void *, Utilities::TypeInfoHash, Utilities::TypeInfoEqualTo> m_infos;
        mutable bool m_corVersionInitialized;
        mutable std::wstring m_corVersion;
        mutable bool m_corSystemDirectoryPathInitialized;
        mutable boost::filesystem::path m_corSystemDirectoryPath;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting {

#endif  // URASANDESU_CPPANONYM_HOSTING_BASERUNTIMEHOST_HPP