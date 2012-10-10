#pragma once
#ifndef URASANDESU_CPPANONYM_HOSTING_BASERUNTIMEHOST_HPP
#define URASANDESU_CPPANONYM_HOSTING_BASERUNTIMEHOST_HPP

#ifndef URASANDESU_CPPANONYM_HOSTING_INTERFACES_RUNTIMEHOSTAPIHOLDERLABEL_HPP
#include <Urasandesu/CppAnonym/Hosting/Interfaces/RuntimeHostApiHolderLabel.hpp>
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
        using namespace Urasandesu::CppAnonym::Hosting::Interfaces;

        template<
            class RuntimeHostApiHolder
        >    
        struct RuntimeHostFacade
        {
            typedef typename RuntimeHostApiAt<RuntimeHostApiHolder, HostInfoLabel>::type host_info_type;
            typedef typename RuntimeHostApiAt<RuntimeHostApiHolder, RuntimeHostLabel>::type runtime_host_type;
            typedef typename RuntimeHostApiAt<RuntimeHostApiHolder, RuntimeHostPersistedHandlerLabel>::type runtime_host_persisted_handler_type;
            typedef DisposingInfo<runtime_host_type, runtime_host_persisted_handler_type> runtime_host_disposing_info_type;
            
            
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
        public SimpleDisposable
    {
    public:
        typedef RuntimeHostDetail::RuntimeHostFacade<RuntimeHostApiHolder> facade;
        typedef typename facade::host_info_type host_info_type;
        typedef typename facade::runtime_host_type runtime_host_type;
        typedef typename facade::runtime_host_previous_type runtime_host_previous_type;
        typedef typename facade::chain_info_types chain_info_types;
        typedef typename facade::base_ptr_chain_type base_ptr_chain_type;
        typedef typename facade::runtime_host_chain_type runtime_host_chain_type;

        BaseRuntimeHost() : 
            m_corVersionInitialized(false)
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

    private:
        mutable bool m_corVersionInitialized;
        mutable std::wstring m_corVersion;
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
        typedef typename facade::runtime_host_persisted_handler_type runtime_host_persisted_handler_type;
        typedef typename facade::runtime_host_disposing_info_type runtime_host_disposing_info_type;
        typedef typename facade::runtime_host_previous_type runtime_host_previous_type;
        typedef typename facade::chain_info_types chain_info_types;
        typedef typename facade::base_ptr_chain_type base_ptr_chain_type;
        typedef typename facade::runtime_host_chain_type runtime_host_chain_type;
        typedef typename facade::runtime_host_provider_type runtime_host_provider_type;

        typedef Utilities::TempPtr<runtime_host_type> sender_type;

        BaseRuntimeHostPersistedHandler(host_info_type *pHostInfo, std::wstring const &version) : 
            m_pHostInfo(pHostInfo),
            m_version(version)
        { }
                
        void operator()(sender_type *pSender, void *pArg)
        {
            sender_type &pRuntime = *pSender;
            runtime_host_provider_type &provider = m_pHostInfo->ProviderOf<runtime_host_disposing_info_type>();
            m_pHostInfo->m_versionToIndex[m_version] = provider.RegisterObject(pRuntime);
        }

    private:                
        host_info_type *m_pHostInfo;
        std::wstring m_version;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting {

#endif  // URASANDESU_CPPANONYM_HOSTING_BASERUNTIMEHOST_HPP