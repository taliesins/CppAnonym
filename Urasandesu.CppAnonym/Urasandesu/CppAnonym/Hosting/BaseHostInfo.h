#pragma once
#ifndef URASANDESU_CPPANONYM_HOSTING_BASEHOSTINFO_H
#define URASANDESU_CPPANONYM_HOSTING_BASEHOSTINFO_H

#ifndef URASANDESU_CPPANONYM_HEAPPROVIDERFWD_HPP
#include <Urasandesu/CppAnonym/HeapProviderFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_CARTRIDGEAPISYSTEMFWD_HPP
#include <Urasandesu/CppAnonym/Traits/CartridgeApiSystemFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_HOSTING_BASERUNTIMEHOSTFWD_HPP
#include <Urasandesu/CppAnonym/Hosting/BaseRuntimeHostFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_HOSTING_RUNTIMEHOSTAPIHOLDERLABELFWD_HPP
#include <Urasandesu/CppAnonym/Hosting/RuntimeHostApiHolderLabelFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Hosting {

    struct DefaultHostInfoApiHolder;

    
    template<
        class HostInfoApiHolder = DefaultHostInfoApiHolder
    >    
    class BaseHostInfo : 
        public HeapProvider<
            std::wstring, 
            boost::mpl::vector<
                typename Traits::ApiAt<HostInfoApiHolder, HostInfoApiHolderLabel, RuntimeHostLabel>::type
            > 
        >
    {
    public:
        typedef BaseHostInfo<HostInfoApiHolder> this_type;

        typedef typename Traits::ApiAt<HostInfoApiHolder, HostInfoApiHolderLabel, RuntimeHostLabel>::type runtime_host_type;

        runtime_host_type const *GetRuntime(std::wstring const &version) const
        {
            if (version.empty())
                BOOST_THROW_EXCEPTION(CppAnonymArgumentException(L"The parameter must be non-empty.", L"version"));

            typedef typename type_decided_by<runtime_host_type>::type RuntimeHostHeap;
            RuntimeHostHeap const &heap = Of<runtime_host_type>();
            if (heap.Exists(version))
            {
                return heap.Get(version);
            }
            else
            {
                RuntimeHostHeap *pHeap = const_cast<RuntimeHostHeap *>(&heap);
                runtime_host_type const *pRuntimeHost = pHeap->NewPseudo();

                std::wstring const &corVersion = pRuntimeHost->GetCORVersion();
                if (corVersion != version)
                {
                    BOOST_SCOPE_EXIT((pHeap))
                    {
                        pHeap->DeleteLast();
                    }
                    BOOST_SCOPE_EXIT_END

                    std::wstring what;
                    what += L"The version '";
                    what += version;
                    what += L"' is not supported. For your information, this process runs at version '";
                    what += corVersion;
                    what += L"'.";
                    BOOST_THROW_EXCEPTION(CppAnonymNotSupportedException(what));
                }

                pHeap->SetToLast(version);
                return pRuntimeHost;
            }
        }
    };

    typedef BaseHostInfo<> HostInfo;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting {

#endif  // URASANDESU_CPPANONYM_HOSTING_BASEHOSTINFO_H