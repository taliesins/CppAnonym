#pragma once
#ifndef URASANDESU_CPPANONYM_HOSTING_BASEHOSTINFO_HPP
#define URASANDESU_CPPANONYM_HOSTING_BASEHOSTINFO_HPP

#ifndef URASANDESU_CPPANONYM_HEAPPROVIDER_HPP
#include <Urasandesu/CppAnonym/HeapProvider.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_CARTRIDGEAPISYSTEM_HPP
#include <Urasandesu/CppAnonym/Traits/CartridgeApiSystem.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_HOSTING_INTERFACES_HOSTINFOAPIHOLDERLABEL_HPP
#include <Urasandesu/CppAnonym/Hosting/Interfaces/HostInfoApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_HOSTING_INTERFACES_RUNTIMEHOSTLABEL_HPP
#include <Urasandesu/CppAnonym/Hosting/Interfaces/RuntimeHostLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMARGUMENTEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymArgumentException.h>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMNOTSUPPORTEDEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymNotSupportedException.h>
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
        public HeapProvider<
            std::wstring, 
            boost::mpl::vector<
                typename HostInfoApiAt<HostInfoApiHolder, Interfaces::RuntimeHostLabel>::type
            > 
        >
    {
    public:
        typedef BaseHostInfo<HostInfoApiHolder> this_type;

        typedef typename HostInfoApiAt<HostInfoApiHolder, Interfaces::RuntimeHostLabel>::type runtime_host_type;

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

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting {

#endif  // URASANDESU_CPPANONYM_HOSTING_BASEHOSTINFO_HPP