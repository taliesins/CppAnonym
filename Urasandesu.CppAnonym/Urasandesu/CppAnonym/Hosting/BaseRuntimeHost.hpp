#pragma once
#ifndef URASANDESU_CPPANONYM_HOSTING_BASERUNTIMEHOST_HPP
#define URASANDESU_CPPANONYM_HOSTING_BASERUNTIMEHOST_HPP

#ifndef URASANDESU_CPPANONYM_SMARTPTRCHAINMAPPER_HPP
#include <Urasandesu/CppAnonym/SmartPtrChainMapper.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_CARTRIDGEAPISYSTEM_HPP
#include <Urasandesu/CppAnonym/Traits/CartridgeApiSystem.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_HOSTING_INTERFACES_RUNTIMEHOSTAPIHOLDERLABEL_HPP
#include <Urasandesu/CppAnonym/Hosting/Interfaces/RuntimeHostApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_SMARTPTRCHAIN_HPP
#include <Urasandesu/CppAnonym/SmartPtrChain.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_DISPOSABLEHEAPPROVIDER_HPP
#include <Urasandesu/CppAnonym/DisposableHeapProvider.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_SIMPLEDISPOSABLE_H
#include <Urasandesu/CppAnonym/SimpleDisposable.h>
#endif

#ifndef URASANDESU_CPPANONYM_HOSTING_BASERUNTIMEHOSTFWD_HPP
#include <Urasandesu/CppAnonym/Hosting/BaseRuntimeHostFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Hosting {

    struct RuntimeHostChainMapper : 
        SmartPtrChainMapper
    {
        template<
            class T,
            class Previous,
            class Current
        >
        static T *MapFirstAncestor(Current &current) 
        { 
            return current.GetInfo<T>();
        }

        template<
            class T,
            class Previous,
            class Current
        >
        static T *MapAncestor(Current &current) 
        { 
            return current.GetInfo<T>();
        }
    };

    template<class ApiCartridgesHolder, class ApiLabel>
    struct RuntimeHostApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::RuntimeHostApiHolderLabel, ApiLabel>
    {
    };

    namespace RuntimeHostDetail {

        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym::Fusion::Interfaces;
        using namespace Urasandesu::CppAnonym::Hosting::Interfaces;
        using namespace Urasandesu::CppAnonym::Metadata::Interfaces;

        template<
            class RuntimeHostApiHolder
        >    
        struct RuntimeHostFacade
        {
            typedef typename RuntimeHostApiAt<RuntimeHostApiHolder, HostInfoLabel>::type host_info_type;
            typedef typename RuntimeHostApiAt<RuntimeHostApiHolder, RuntimeHostLabel>::type runtime_host_type;
            //typedef typename RuntimeHostApiAt<RuntimeHostApiHolder, RuntimeHostPersistedHandlerLabel>::type runtime_host_persisted_handler_type;
            typedef typename RuntimeHostApiAt<RuntimeHostApiHolder, MetadataInfoLabel>::type metadata_info_type;
            typedef typename RuntimeHostApiAt<RuntimeHostApiHolder, MetadataInfoPersistedHandlerLabel>::type metadata_info_persisted_handler_type;
            typedef typename RuntimeHostApiAt<RuntimeHostApiHolder, FusionInfoLabel>::type fusion_info_type;
            typedef typename RuntimeHostApiAt<RuntimeHostApiHolder, FusionInfoPersistedHandlerLabel>::type fusion_info_persisted_handler_type;

            
            typedef mpl::vector<
                DisposingInfo<metadata_info_type, metadata_info_persisted_handler_type>,
                DisposingInfo<fusion_info_type, fusion_info_persisted_handler_type>
            > disposing_info_types;
            typedef DisposableHeapProvider<disposing_info_types> base_heap_provider_type;


            typedef typename base_heap_provider_type::provider_of<metadata_info_type>::type metadata_info_provider_type;
            typedef typename base_heap_provider_type::provider_of<fusion_info_type>::type fusion_info_provider_type;
            //CPP_ANONYM_DECLARE_HAS_MEMBER_TYPE(RuntimeHostProvider, runtime_host_provider_type);
            //CPP_ANONYM_DECLARE_GET_MEMBER_TYPE(RuntimeHostProvider, runtime_host_provider_type);
            //typedef typename boost::mpl::eval_if<
            //    CPP_ANONYM_HAS_MEMBER_TYPE(RuntimeHostProvider, host_info_type), 
            //    CPP_ANONYM_GET_MEMBER_TYPE(RuntimeHostProvider, host_info_type), 
            //    boost::mpl::void_
            //>::type runtime_host_provider_type;

            
            typedef host_info_type runtime_host_previous_type;
            
            
            typedef mpl::vector<
                SmartPtrChainInfo<runtime_host_previous_type, RuntimeHostChainMapper>
            > chain_info_types;
            typedef SmartPtrChain<runtime_host_type, chain_info_types> base_ptr_chain_type;
            
            
            typedef typename base_ptr_chain_type::chain_from<runtime_host_previous_type>::type runtime_host_chain_type;
        };

    }   // namespace RuntimeHostDetail {

    template<
        class RuntimeHostApiHolder
    >    
    class BaseRuntimeHost : 
        public RuntimeHostDetail::RuntimeHostFacade<RuntimeHostApiHolder>::base_ptr_chain_type, 
        public RuntimeHostDetail::RuntimeHostFacade<RuntimeHostApiHolder>::base_heap_provider_type,
        //public SmartPtrChain<
        //    BaseRuntimeHost<RuntimeHostApiHolder>,
        //    boost::mpl::vector<
        //        SmartPtrChainInfo<typename RuntimeHostApiAt<RuntimeHostApiHolder, Interfaces::HostInfoLabel>::type, RuntimeHostChainMapper>
        //    >
        //>,
        //public DisposableHeapProvider<
        //    boost::mpl::vector<
        //        typename RuntimeHostApiAt<RuntimeHostApiHolder, Metadata::Interfaces::MetadataInfoLabel>::type,
        //        typename RuntimeHostApiAt<RuntimeHostApiHolder, Fusion::Interfaces::FusionInfoLabel>::type
        //    >
        //>,
        //public DisposableHeapProvider<
        //    boost::mpl::vector<
        //        typename RuntimeHostApiAt<RuntimeHostApiHolder, StrongNaming::Interfaces::StrongNameInfoLabel>::type,
        //        typename RuntimeHostApiAt<RuntimeHostApiHolder, Metadata::Interfaces::MetadataInfoLabel>::type,
        //        typename RuntimeHostApiAt<RuntimeHostApiHolder, Fusion::Interfaces::FusionInfoLabel>::type
        //    >
        //>,
        public SimpleDisposable
    {
    public:
        typedef BaseRuntimeHost<RuntimeHostApiHolder> this_type;

        typedef RuntimeHostDetail::RuntimeHostFacade<RuntimeHostApiHolder> facade;
        typedef typename facade::runtime_host_type runtime_host_type;
        typedef typename facade::metadata_info_type metadata_info_type;
        typedef typename facade::metadata_info_persisted_handler_type metadata_info_persisted_handler_type;
        typedef typename facade::fusion_info_type fusion_info_type;
        typedef typename facade::fusion_info_persisted_handler_type fusion_info_persisted_handler_type;
        typedef typename facade::metadata_info_provider_type metadata_info_provider_type;
        typedef typename facade::fusion_info_provider_type fusion_info_provider_type;
        //typedef typename facade::runtime_host_provider_type runtime_host_provider_type;
        typedef typename facade::runtime_host_previous_type runtime_host_previous_type;
        typedef typename facade::runtime_host_chain_type runtime_host_chain_type;
        //typedef typename chaining_previous_type_at<0>::type runtime_host_previous_type;
        //typedef typename chain_from<runtime_host_previous_type>::type runtime_host_chain_type; 
        //typedef runtime_host_previous_type host_info_type;

        BaseRuntimeHost() : 
            m_corVersionInitialized(false),
            m_corSysDirPathInitialized(false)
        { }

        std::wstring const &GetCORVersion() const
        {
            CheckDisposed();

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
            CheckDisposed();

            using namespace boost::filesystem;

            if (!m_corSysDirPathInitialized)
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

                m_corSysDirPath = buffer;
                
                m_corSysDirPathInitialized = true;
            }
            return m_corSysDirPath;
        }

        template<class Info>
        Info *GetInfo() const
        {
            namespace mpl = boost::mpl;
            using namespace boost;
            using namespace Urasandesu::CppAnonym::Utilities;
            
            //typedef mpl::find<providing_types, Info>::type I;
            //typedef mpl::end<providing_types>::type IEnd;
            //BOOST_MPL_ASSERT((mpl::not_<boost::is_same<I, IEnd> >));
            BOOST_MPL_ASSERT((is_provided<Info>));

            typedef typename provider_of<Info>::type InfoProvider;

            Info *pExistingInfo = NULL;
            if (!TryGetInfo<Info>(pExistingInfo))
            {
                TempPtr<Info> pNewInfo = NewInfo<Info>();
                pNewInfo.Persist();
                return pNewInfo.Get();
            }
            else
            {
                return pExistingInfo;
            }
        }

    private:
        friend typename runtime_host_previous_type;
        friend typename metadata_info_persisted_handler_type;
        friend typename fusion_info_persisted_handler_type;

        template<class Info>
        Utilities::TempPtr<Info> NewInfo() const
        {
            namespace mpl = boost::mpl;
            using namespace boost;
            using namespace Urasandesu::CppAnonym::Utilities;
            
            //typedef mpl::find<providing_types, Info>::type I;
            //typedef mpl::end<providing_types>::type IEnd;
            //BOOST_MPL_ASSERT((mpl::not_<boost::is_same<I, IEnd> >));
            BOOST_MPL_ASSERT((is_provided<Info>));

            typedef typename providing_persisted_handler_type_at<Info>::type InfoPersistedHandler;
            typedef typename provider_of<Info>::type InfoProvider;

            InfoProvider &provider = ProviderOf<Info>();
            runtime_host_chain_type &chain = ChainFrom<runtime_host_previous_type>();
            TempPtr<Info> pInfo = chain.NewObject<Info>(provider);
            InfoPersistedHandler handler(const_cast<this_type *>(this));
            provider.AddPersistedHandler(pInfo, handler);
            //struct pInfo_Persisted
            //{
            //    typedef TempPtr<Info> sender_type;

            //    pInfo_Persisted(this_type &this_) : 
            //        m_pThis(&this_)
            //    { }
            //    
            //    void operator()(sender_type *pSender, void *pArg)
            //    {
            //        sender_type &pInfo = *pSender;
            //        InfoProvider &provider = m_pThis->ProviderOf<Info>();
            //        TypeInfo key = mpl::identity<Info>();
            //        m_pThis->m_infoToIndex[key] = provider.RegisterObject(pInfo);
            //    }
            //    
            //    this_type *m_pThis;
            //};
            //pInfo.AddPersistedHandler(pInfo_Persisted(const_cast<this_type &>(*this)));
            return pInfo;
        }

        template<class Info>
        bool TryGetInfo(Info *&pExistingInfo) const
        {
            namespace mpl = boost::mpl;
            using namespace boost;
            using namespace Urasandesu::CppAnonym::Utilities;
            
            //typedef mpl::find<providing_types, Info>::type I;
            //typedef mpl::end<providing_types>::type IEnd;
            //BOOST_MPL_ASSERT((mpl::not_<boost::is_same<I, IEnd> >));
            BOOST_MPL_ASSERT((is_provided<Info>));

            typedef typename provider_of<Info>::type InfoProvider;

            TypeInfo key = mpl::identity<Info>();
            if (m_infoToIndex.find(key) == m_infoToIndex.end())
            {
                return false;
            }
            else
            {
                size_t index = m_infoToIndex[key];
                InfoProvider &provider = ProviderOf<Info>();
                pExistingInfo = provider.GetObject(index);
                return true;
            }
        }

        mutable bool m_corVersionInitialized;
        mutable std::wstring m_corVersion;
        mutable bool m_corSysDirPathInitialized;
        mutable boost::filesystem::path m_corSysDirPath;
        mutable boost::unordered_map<Utilities::TypeInfo, size_t, Utilities::TypeInfoHash, Utilities::TypeInfoEqualTo> m_infoToIndex;
    };

    
    
    
    
    namespace RuntimeHostDetail {

        template<
            class RuntimeHostApiHolder
        >    
        struct RuntimeHostPersistedHandlerFacade : 
            RuntimeHostFacade<RuntimeHostApiHolder>
        {
            CPP_ANONYM_DECLARE_HAS_MEMBER_TYPE(RuntimeHostProvider, runtime_host_provider_type);
            CPP_ANONYM_DECLARE_GET_MEMBER_TYPE(RuntimeHostProvider, runtime_host_provider_type);
            typedef typename mpl::eval_if<
                CPP_ANONYM_HAS_MEMBER_TYPE(RuntimeHostProvider, host_info_type), 
                CPP_ANONYM_GET_MEMBER_TYPE(RuntimeHostProvider, host_info_type), 
                mpl::void_
            >::type runtime_host_provider_type;
        };

    }   // namespace RuntimeHostDetail {

    template<
        class RuntimeHostApiHolder
    >    
    class BaseRuntimeHostPersistedHandler
    {
    public:
        typedef RuntimeHostDetail::RuntimeHostPersistedHandlerFacade<RuntimeHostApiHolder> facade;
        typedef typename facade::host_info_type host_info_type;
        typedef typename facade::runtime_host_type runtime_host_type;
        typedef typename facade::runtime_host_provider_type runtime_host_provider_type;

        typedef Utilities::TempPtr<runtime_host_type> sender_type;

        BaseRuntimeHostPersistedHandler(host_info_type *pHostInfo, std::wstring const &version) : 
            m_pHostInfo(pHostInfo),
            m_version(version)
        { }
                
        void operator()(sender_type *pSender, void *pArg)
        {
            sender_type &pRuntime = *pSender;
            runtime_host_provider_type &provider = m_pHostInfo->ProviderOf<runtime_host_type>();
            m_pHostInfo->m_versionToIndex[m_version] = provider.RegisterObject(pRuntime);
        }

    private:                
        host_info_type *m_pHostInfo;
        std::wstring m_version;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting {

#endif  // URASANDESU_CPPANONYM_HOSTING_BASERUNTIMEHOST_HPP