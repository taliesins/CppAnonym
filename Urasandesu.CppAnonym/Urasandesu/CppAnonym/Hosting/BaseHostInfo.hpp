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

    template<
        class HostInfoApiHolder
    >    
    class BaseHostInfo : 
        public SmartPtrChain<
            BaseHostInfo<HostInfoApiHolder>,
            boost::mpl::vector<
                SmartPtrChainInfo<boost::mpl::void_>
            >
        >,
        public DisposableHeapProvider<
            boost::mpl::vector<
                typename HostInfoApiAt<HostInfoApiHolder, Interfaces::HostInfoLabel>::type
            >
        >,
        //public DisposableHeapProvider<
        //    boost::mpl::vector<
        //        typename HostInfoApiAt<HostInfoApiHolder, Interfaces::HostInfoLabel>::type,
        //        typename HostInfoApiAt<HostInfoApiHolder, Interfaces::RuntimeHostLabel>::type
        //    >
        //>,
        public SimpleDisposable
    {
    public:
        typedef BaseHostInfo<HostInfoApiHolder> this_type;
        
        typedef typename providing_type_at<0>::type host_info_type;
        //typedef typename providing_type_at<1>::type runtime_host_type;
        typedef int runtime_host_type;

        typedef typename provider_of<host_info_type>::type host_info_provider_type;
        typedef typename provider_of<runtime_host_type>::type runtime_host_provider_type;        

        typedef typename chaining_previous_type_at<0>::type host_info_previous_type;        
        typedef typename chain_from<host_info_previous_type>::type host_info_chain_type; 

        //typedef typename HostInfoApiAt<HostInfoApiHolder, Utilities::Interfaces::InfrastructureFactoryLabel>::type factory_type;

        static host_info_type *CreateHost()
        {
            TempPtr<host_info_type> pHost = NewHost();
            pHost.Persist();
            return pHost.Get();
        }

        runtime_host_type const *GetRuntime(std::wstring const &version) const
        {
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
        static Utilities::TempPtr<host_info_type> NewHost()
        {
            using namespace Urasandesu::CppAnonym::Utilities;

            TempPtr<host_info_type> pHost = host_info_chain_type::NewRootObject<this_type, host_info_provider_type>();
            struct pHost_Persisted
            {
                typedef TempPtr<host_info_type> sender_type;

                void operator()(sender_type *pSender, void *pArg)
                {
                    sender_type &pHost = *pSender;
                    host_info_provider_type::RegisterStaticObject(pHost);
                }
            };
            pHost.AddPersistedHandler(pHost_Persisted());
            return pHost;
        }

        Utilities::TempPtr<runtime_host_type> NewRuntime(std::wstring const &version) const
        {
            using namespace Urasandesu::CppAnonym::Utilities;

            runtime_host_provider_type &provider = ProviderOf<runtime_host_type>();
            host_info_chain_type &chain = ChainFrom<host_info_previous_type>();
            TempPtr<runtime_host_type> pRuntime = chain.NewObject<runtime_host_type>(provider);
            struct pRuntime_Persisted
            {
                typedef TempPtr<runtime_host_type> sender_type;

                pRuntime_Persisted(this_type &this_, std::wstring const &version) : 
                    m_pThis(&this_),
                    m_version(version)
                { }
                
                void operator()(sender_type *pSender, void *pArg)
                {
                    sender_type &pRuntime = *pSender;
                    runtime_host_provider_type &provider = m_pThis->ProviderOf<runtime_host_type>();
                    m_pThis->m_versionToIndex[m_version] = provider.RegisterObject(pRuntime);
                }
                
                this_type *m_pThis;
                std::wstring m_version;
            };
            pRuntime.AddPersistedHandler(pRuntime_Persisted(const_cast<this_type &>(*this), version));
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

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting {

#endif  // URASANDESU_CPPANONYM_HOSTING_BASEHOSTINFO_HPP