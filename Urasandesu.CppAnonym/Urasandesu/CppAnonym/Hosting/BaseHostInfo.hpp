#pragma once
#ifndef URASANDESU_CPPANONYM_HOSTING_BASEHOSTINFO_HPP
#define URASANDESU_CPPANONYM_HOSTING_BASEHOSTINFO_HPP

#ifndef URASANDESU_CPPANONYM_HOSTING_INTERFACES_HOSTINFOAPIHOLDERLABEL_HPP
#include <Urasandesu/CppAnonym/Hosting/Interfaces/HostInfoApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_CARTRIDGEAPISYSTEM_HPP
#include <Urasandesu/CppAnonym/Traits/CartridgeApiSystem.hpp>
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
                typename HostInfoApiAt<HostInfoApiHolder, Interfaces::HostInfoLabel>::type,
                typename HostInfoApiAt<HostInfoApiHolder, Interfaces::RuntimeHostLabel>::type
            >
        >,
        public SimpleDisposable
    {
    public:
        typedef BaseHostInfo<HostInfoApiHolder> this_type;
        
        typedef typename providing_type_at<0>::type host_info_type;
        typedef typename providing_type_at<1>::type runtime_host_type;

        typedef typename provider_of<host_info_type>::type host_info_provider_type;
        typedef typename provider_of<runtime_host_type>::type runtime_host_provider_type;        

        typedef typename chaining_previous_type_at<0>::type host_info_previous_type;        
        typedef typename chain_from<host_info_previous_type>::type host_info_chain_type; 

        static host_info_type *NewHost()
        {
            TempPtr<host_info_type> pHost = host_info_chain_type::NewRootObject<this_type, host_info_provider_type>();
            host_info_provider_type::RegisterStaticObject(pHost);
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

                //runtime_host_provider_type &provider = ProviderOf<runtime_host_type>();
                //m_versionToIndex[version] = provider.RegisterObject(pNewRuntime);
                pNewRuntime.Persist();
                return pNewRuntime.Get();
            }
            else
            {
                return pExistingRuntime;
            }
        }

    private:

        Utilities::TempPtr<runtime_host_type> NewRuntime(std::wstring const &version) const
        {
            runtime_host_provider_type &provider = ProviderOf<runtime_host_type>();
            host_info_chain_type &chain = ChainFrom<host_info_previous_type>();
            Utilities::TempPtr<runtime_host_type> pRuntime = chain.NewObject<runtime_host_type>(provider);
            struct RuntimePersister
            {
                RuntimePersister(this_type &this_, std::wstring const &version) : 
                    m_pThis(&this_),
                    m_version(version)
                { }
                
                void operator()(void *p)
                {
                    Utilities::TempPtr<runtime_host_type> &pRuntime = *static_cast<Utilities::TempPtr<runtime_host_type> *>(p);
                    runtime_host_provider_type &provider = m_pThis->ProviderOf<runtime_host_type>();
                    m_pThis->m_versionToIndex[m_version] = provider.RegisterObject(pRuntime);
                }
                
                this_type *m_pThis;
                std::wstring m_version;
            };
            pRuntime.SetPersister(RuntimePersister(const_cast<this_type &>(*this), version));
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