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

        typedef typename HostInfoApiAt<HostInfoApiHolder, Interfaces::RuntimeHostLabel>::type runtime_host_type;

        typedef typename provider_of<this_type>::type host_info_provider_type;
        typedef typename provider_of<runtime_host_type>::type runtime_host_provider_type;
        typedef typename chain_from<boost::mpl::void_>::type host_info_chain_type; 

        static this_type *NewHost()
        {
            return host_info_chain_type::NewRootObject<this_type, host_info_provider_type>();
        }

        runtime_host_type const *GetRuntime(std::wstring const &version) const
        {
            if (version.empty())
                BOOST_THROW_EXCEPTION(CppAnonymArgumentException(L"The parameter must be non-empty.", L"version"));

            runtime_host_type *pExistingRuntime = NULL;
            if (!TryGetRuntime(version, pExistingRuntime))
            {
                runtime_host_type *pNewRuntime = NewRuntime();

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

                runtime_host_provider_type &provider = ProviderOf<runtime_host_type>();
                m_versionToIndex[version] = provider.Register(*pNewRuntime);    // [2012/08/29 08:01:08] この辺実装中。。。Register しないと memory leak するし。
                return pNewRuntime;
            }
            else
            {
                return pExistingRuntime;
            }
        }

    private:
        
        //void SetThis(boost::weak_ptr<this_type> const &pThis) const
        //{
        //    _ASSERTE(m_pThis.use_count() == 0);
        //    m_pThis = pThis;
        //}

        runtime_host_type *NewRuntime() const
        {
            runtime_host_provider_type &provider = ProviderOf<runtime_host_type>();
            host_info_chain_type &chain = ChainFrom<boost::mpl::void_>();
            return chain.NewObject<runtime_host_type>(provider);
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
                pExistingRuntime = provider[index];
                return true;
            }
        }

        mutable boost::unordered_map<std::wstring, size_t> m_versionToIndex;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting {

#endif  // URASANDESU_CPPANONYM_HOSTING_BASEHOSTINFO_HPP