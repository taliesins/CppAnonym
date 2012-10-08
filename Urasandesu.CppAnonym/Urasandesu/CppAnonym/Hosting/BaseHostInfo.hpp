#pragma once
#ifndef URASANDESU_CPPANONYM_HOSTING_BASEHOSTINFO_HPP
#define URASANDESU_CPPANONYM_HOSTING_BASEHOSTINFO_HPP

#ifndef URASANDESU_CPPANONYM_HOSTING_INTERFACES_HOSTINFOAPIHOLDERLABEL_HPP
#include <Urasandesu/CppAnonym/Hosting/Interfaces/HostInfoApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_CARTRIDGEAPISYSTEM_HPP
#include <Urasandesu/CppAnonym/Traits/CartridgeApiSystem.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_SMARTPTRCHAININFO_HPP
#include <Urasandesu/CppAnonym/SmartPtrChainInfo.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_SMARTPTRCHAIN_HPP
#include <Urasandesu/CppAnonym/SmartPtrChain.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_DISPOSINGINFO_HPP
#include <Urasandesu/CppAnonym/DisposingInfo.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_DISPOSABLEHEAPPROVIDER_HPP
#include <Urasandesu/CppAnonym/DisposableHeapProvider.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_SIMPLEDISPOSABLE_H
#include <Urasandesu/CppAnonym/SimpleDisposable.h>
#endif

#ifndef URASANDESU_CPPANONYM_HOSTING_BASEHOSTINFOFWD_HPP
#include <Urasandesu/CppAnonym/Hosting/BaseHostInfoFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Hosting {

    template<class ApiCartridgesHolder, class ApiLabel>
    struct HostInfoApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::HostInfoApiHolderLabel, ApiLabel>
    {
    };

    namespace HostInfoDetail {

        namespace mpl = boost::mpl;

        template<
            class HostInfoApiHolder
        >    
        struct HostInfoFacade
        {
            typedef typename HostInfoApiAt<HostInfoApiHolder, Interfaces::HostInfoLabel>::type host_info_type;
            typedef typename HostInfoApiAt<HostInfoApiHolder, Interfaces::HostInfoPersistedHandlerLabel>::type host_info_persisted_handler_type;
            typedef typename HostInfoApiAt<HostInfoApiHolder, Interfaces::RuntimeHostLabel>::type runtime_host_type;
            typedef typename HostInfoApiAt<HostInfoApiHolder, Interfaces::RuntimeHostPersistedHandlerLabel>::type runtime_host_persisted_handler_type;
            
            
            typedef mpl::vector<
                DisposingInfo<host_info_type, host_info_persisted_handler_type>,
                DisposingInfo<runtime_host_type, runtime_host_persisted_handler_type>
            > disposing_info_types;
            typedef DisposableHeapProvider<disposing_info_types> base_heap_provider_type;
            
            
            typedef typename base_heap_provider_type::provider_of<host_info_type>::type host_info_provider_type;
            typedef typename base_heap_provider_type::provider_of<runtime_host_type>::type runtime_host_provider_type;

            
            typedef mpl::void_ host_info_previous_type;
            
            
            typedef mpl::vector<
                SmartPtrChainInfo<host_info_previous_type>
            > chain_info_types;
            typedef SmartPtrChain<host_info_type, chain_info_types> base_ptr_chain_type;
            
            
            typedef typename base_ptr_chain_type::chain_from<host_info_previous_type>::type host_info_chain_type;
        }; 
    
    }   // namespace HostInfoDetail {


    template<
        class HostInfoApiHolder
    >    
    class BaseHostInfo : 
        public HostInfoDetail::HostInfoFacade<HostInfoApiHolder>::base_ptr_chain_type, 
        public HostInfoDetail::HostInfoFacade<HostInfoApiHolder>::base_heap_provider_type,
        public SimpleDisposable
    {
    public:
        typedef BaseHostInfo<HostInfoApiHolder> this_type;
        
        typedef HostInfoDetail::HostInfoFacade<HostInfoApiHolder> facade;
        typedef typename facade::host_info_type host_info_type;
        typedef typename facade::runtime_host_type runtime_host_type;
        typedef typename facade::runtime_host_persisted_handler_type runtime_host_persisted_handler_type;
        typedef typename facade::host_info_provider_type host_info_provider_type;
        typedef typename facade::runtime_host_provider_type runtime_host_provider_type;
        typedef typename facade::host_info_previous_type host_info_previous_type;
        typedef typename facade::host_info_chain_type host_info_chain_type;

        static host_info_type *CreateHost()
        {
            using namespace Urasandesu::CppAnonym::Utilities;
            
            TempPtr<host_info_type> pHost = NewHost();
            pHost.Persist();
            return pHost.Get();
        }

        runtime_host_type const *GetRuntime(std::wstring const &version) const
        {
            using namespace Urasandesu::CppAnonym::Utilities;
            
            if (version.empty())
                BOOST_THROW_EXCEPTION(CppAnonymArgumentException(L"The parameter must be non-empty.", L"version"));

            runtime_host_type *pExistingRuntime = NULL;
            if (!TryGetRuntime(version, pExistingRuntime))
            {
                TempPtr<runtime_host_type> pNewRuntime = NewRuntime(version);

                std::wstring const &corVersion = pNewRuntime->GetCORVersion();
                if (corVersion != version)
                {
                    std::wstring what;
                    what += L"The version '";
                    what += version;
                    what += L"' is not supported. For your information, this process runs at version '";
                    what += corVersion;
                    what += L"'.";
                    BOOST_THROW_EXCEPTION(CppAnonymNotSupportedException(what));
                }

                pNewRuntime.Persist();
                return pNewRuntime.Get();
            }
            else
            {
                return pExistingRuntime;
            }
        }

    private:
        friend typename runtime_host_persisted_handler_type;

        static Utilities::TempPtr<host_info_type> NewHost()
        {
            using namespace Urasandesu::CppAnonym::Utilities;

            host_info_type &hostInfo = CppAnonymStorage::Object<host_info_type>();
            host_info_provider_type &provider = hostInfo.ProviderOf<host_info_type>();
            TempPtr<host_info_type> pHostInfo = host_info_chain_type::NewRootObject<host_info_type>(provider);
            provider.AddPersistedHandler(pHostInfo, &hostInfo);
            return pHostInfo;
        }

        Utilities::TempPtr<runtime_host_type> NewRuntime(std::wstring const &version) const
        {
            using namespace Urasandesu::CppAnonym::Utilities;

            runtime_host_provider_type &provider = ProviderOf<runtime_host_type>();
            host_info_chain_type &chain = ChainFrom<host_info_previous_type>();
            TempPtr<runtime_host_type> pRuntime = chain.NewObject<runtime_host_type>(provider);
            runtime_host_persisted_handler_type handler(const_cast<this_type *>(this), version);
            provider.AddPersistedHandler(pRuntime, handler);
            return pRuntime;
        }

        bool TryGetRuntime(std::wstring const &version, runtime_host_type *&pExistingRuntime) const
        {
            if (m_versionToIndex.find(version) == m_versionToIndex.end())
            {
                return false;
            }
            else
            {
                size_t index = m_versionToIndex[version];
                runtime_host_provider_type &provider = ProviderOf<runtime_host_type>();
                pExistingRuntime = provider.GetObject(index);
                return true;
            }
        }

        mutable boost::unordered_map<std::wstring, size_t> m_versionToIndex;
    };





    template<
        class HostInfoApiHolder
    >    
    class BaseHostInfoPersistedHandler
    {
    public:
        typedef HostInfoDetail::HostInfoFacade<HostInfoApiHolder> facade;
        typedef typename facade::host_info_type host_info_type;
        typedef typename facade::host_info_provider_type host_info_provider_type;
        
        typedef Utilities::TempPtr<host_info_type> sender_type;

        BaseHostInfoPersistedHandler(host_info_type *pHostInfo) : 
            m_pHostInfo(pHostInfo)
        { }

        void operator()(sender_type *pSender, void *pArg)
        {
            sender_type &pHostInfo = *pSender;

            host_info_provider_type &provider = m_pHostInfo->ProviderOf<host_info_type>();
            provider.RegisterObject(pHostInfo);
        }

    private:
        host_info_type *m_pHostInfo;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting {

#endif  // URASANDESU_CPPANONYM_HOSTING_BASEHOSTINFO_HPP