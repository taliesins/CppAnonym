#pragma once
#ifndef URASANDESU_CPPANONYM_FUSION_BASEHOSTINFOPROTO07F03042_H
#define URASANDESU_CPPANONYM_FUSION_BASEHOSTINFOPROTO07F03042_H

namespace Urasandesu { namespace CppAnonym {

    template<class Key, class Sequence>
    class ATL_NO_VTABLE HeapProvider;

}}   // namespace Urasandesu { namespace CppAnonym {

namespace Urasandesu { namespace CppAnonym { namespace Hosting {

    template<
        class RuntimeHostApiType
    >
    class BaseRuntimeHostProto07F03042;

    struct DefaultHostInfoApiProto07F03042;
    
    struct IRuntimeHostApi; 

    
    template<
        class HostInfoApiType = DefaultHostInfoApiProto07F03042
    >    
    class BaseHostInfoProto07F03042 : 
        public HeapProvider<
            std::wstring, 
            boost::mpl::vector<
                BaseRuntimeHostProto07F03042<typename Traits::ChildApiOrDefault<HostInfoApiType, IRuntimeHostApi>::type> 
            > 
        >
    {
    public:
        typedef BaseHostInfoProto07F03042<HostInfoApiType> this_type;
        typedef typename Traits::ChildApiOrDefault<HostInfoApiType, IRuntimeHostApi>::type runtime_host_api_type;
        typedef BaseRuntimeHostProto07F03042<runtime_host_api_type> runtime_host_type;

        runtime_host_type const *GetRuntime(std::wstring const &version) const
        {
            if (version.empty())
                BOOST_THROW_EXCEPTION(CppAnonymArgumentException(L"The parameter must be non-empty.", L"version"));

            typedef typename type_decided_by<runtime_host_type>::type runtime_host_heap_type;
            runtime_host_heap_type const &heap = Of<runtime_host_type>();
            if (heap.Exists(version))
            {
                return heap.Get(version);
            }
            else
            {
                runtime_host_heap_type *pHeap = const_cast<runtime_host_heap_type *>(&heap);
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

    typedef BaseHostInfoProto07F03042<> HostInfoProto07F03042;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting {

#endif  // URASANDESU_CPPANONYM_FUSION_BASEHOSTINFOPROTO07F03042_H