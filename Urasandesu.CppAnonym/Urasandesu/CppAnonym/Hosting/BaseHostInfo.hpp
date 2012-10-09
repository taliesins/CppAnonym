#pragma once
#ifndef URASANDESU_CPPANONYM_HOSTING_BASEHOSTINFO_HPP
#define URASANDESU_CPPANONYM_HOSTING_BASEHOSTINFO_HPP

#ifndef URASANDESU_CPPANONYM_HOSTING_INTERFACES_HOSTINFOAPIHOLDERLABEL_HPP
#include <Urasandesu/CppAnonym/Hosting/Interfaces/HostInfoApiHolderLabel.hpp>
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
        using namespace Urasandesu::CppAnonym::Hosting::Interfaces;
        
        template<
            class HostInfoApiHolder
        >    
        struct HostInfoFacade
        {
            typedef typename HostInfoApiAt<HostInfoApiHolder, HostInfoLabel>::type host_info_type;
            typedef typename HostInfoApiAt<HostInfoApiHolder, HostInfoPersistedHandlerLabel>::type host_info_persisted_handler_type;
            typedef DisposingInfo<host_info_type, host_info_persisted_handler_type> host_info_disposing_info_type;


            typedef DisposableHeapProvider<
                host_info_disposing_info_type 
            > base_heap_provider_type;


            typedef typename base_heap_provider_type::provider_of<host_info_disposing_info_type>::type host_info_provider_type;


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
        typedef typename facade::host_info_persisted_handler_type host_info_persisted_handler_type;
        typedef typename facade::host_info_disposing_info_type host_info_disposing_info_type;
        typedef typename facade::base_heap_provider_type base_heap_provider_type;
        typedef typename facade::host_info_provider_type host_info_provider_type;
        typedef typename facade::host_info_previous_type host_info_previous_type;
        typedef typename facade::chain_info_types chain_info_types;
        typedef typename facade::base_ptr_chain_type base_ptr_chain_type;
        typedef typename facade::host_info_chain_type host_info_chain_type;

        BaseHostInfo()
        { }

        static host_info_type *CreateHost()
        {
            using namespace Urasandesu::CppAnonym::Utilities;
            
            TempPtr<host_info_type> pHost = NewHost();
            pHost.Persist();
            return pHost.Get();
        }
    
    private:
        static Utilities::TempPtr<host_info_type> NewHost()
        {
            using namespace Urasandesu::CppAnonym::Utilities;

            host_info_type &hostInfo = CppAnonymStorage::Object<host_info_type>();
            host_info_provider_type &provider = hostInfo.ProviderOf<host_info_disposing_info_type>();
            TempPtr<host_info_type> pHostInfo = host_info_chain_type::NewRootObject<host_info_type>(provider);
            host_info_persisted_handler_type handler(&hostInfo);
            provider.AddPersistedHandler(pHostInfo, handler);
            return pHostInfo;
        }
    };





    namespace HostInfoDetail {

        template<
            class HostInfoApiHolder
        >    
        struct HostInfoPersistedHandlerFacade : 
            HostInfoFacade<HostInfoApiHolder>
        {
        };

    }   // namespace HostInfoDetail {
    
    template<
        class HostInfoApiHolder
    >    
    class BaseHostInfoPersistedHandler
    {
    public:
        typedef HostInfoDetail::HostInfoPersistedHandlerFacade<HostInfoApiHolder> facade;
        typedef typename facade::host_info_type host_info_type;
        typedef typename facade::host_info_persisted_handler_type host_info_persisted_handler_type;
        typedef typename facade::host_info_disposing_info_type host_info_disposing_info_type;
        typedef typename facade::base_heap_provider_type base_heap_provider_type;
        typedef typename facade::host_info_provider_type host_info_provider_type;
        typedef typename facade::host_info_previous_type host_info_previous_type;
        typedef typename facade::chain_info_types chain_info_types;
        typedef typename facade::base_ptr_chain_type base_ptr_chain_type;
        typedef typename facade::host_info_chain_type host_info_chain_type;
        
        typedef Utilities::TempPtr<host_info_type> sender_type;

        BaseHostInfoPersistedHandler(host_info_type *pHostInfo) : 
            m_pHostInfo(pHostInfo)
        { }

        void operator()(sender_type *pSender, void *pArg)
        {
            sender_type &pHostInfo = *pSender;

            host_info_provider_type &provider = m_pHostInfo->ProviderOf<host_info_disposing_info_type>();
            provider.RegisterObject(pHostInfo);
        }

    private:
        host_info_type *m_pHostInfo;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting {

#endif  // URASANDESU_CPPANONYM_HOSTING_BASEHOSTINFO_HPP