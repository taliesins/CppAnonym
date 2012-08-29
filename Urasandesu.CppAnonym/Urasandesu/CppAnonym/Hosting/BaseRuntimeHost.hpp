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
        static bool CanMapFirstAncestor(Current const &current)
        {
            return current.GetInfo<T>();
        }

        template<
            class T,
            class Previous,
            class Current
        >
        static boost::shared_ptr<T> MapFirstAncestor(Current const &current) 
        { 
            return current.GetInfo<T>();
        }

        template<
            class T,
            class Previous,
            class Current
        >
        static bool CanMapAncestor(Current const &current)
        {
            return current.GetInfo<T>();
        }

        template<
            class T,
            class Previous,
            class Current
        >
        static boost::shared_ptr<T> MapAncestor(Current const &current) 
        { 
            return current.GetInfo<T>();
        }
    };

    template<class ApiCartridgesHolder, class ApiLabel>
    struct RuntimeHostApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::RuntimeHostApiHolderLabel, ApiLabel>
    {
    };

    template<
        class RuntimeHostApiHolder
    >    
    class BaseRuntimeHost : 
        public SmartPtrChain<
            BaseRuntimeHost<RuntimeHostApiHolder>,
            boost::mpl::vector<
                SmartPtrChainInfo<typename RuntimeHostApiAt<RuntimeHostApiHolder, Interfaces::HostInfoLabel>::type, RuntimeHostChainMapper>
            >
        >,
        //public DisposableHeapProvider<
        //    boost::mpl::vector<
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

        typedef typename RuntimeHostApiAt<RuntimeHostApiHolder, Interfaces::HostInfoLabel>::type host_info_type;

        typedef typename chain_from<host_info_type>::type runtime_host_chain_type; 

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
        boost::shared_ptr<Info> GetInfo() const
        {
            namespace mpl = boost::mpl;
            using namespace boost;
            
            typedef mpl::find<sequence_type, Info>::type I;
            typedef mpl::end<sequence_type>::type IEnd;
            BOOST_MPL_ASSERT((mpl::not_<boost::is_same<I, IEnd> >));

            boost::shared_ptr<Info> pExistingInfo;
            if (!TryGetInfo<Info>(pExistingInfo))
            {
                boost::shared_ptr<Info> pNewInfo;
                pNewInfo = NewInfo<Info>();
                
                typedef typename provider_of<Info>::type InfoProvider;
                InfoProvider &provider = ProviderOf<Info>();
                Utilities::TypeInfo key = mpl::identity<Info>();
                m_infoToIndex[key] = provider.Register(pNewInfo);
                return pNewInfo;
            }
            else
            {
                return pExistingInfo;
            }
        }

    private:
        friend typename host_info_type;

        template<class Info>
        boost::shared_ptr<Info> NewInfo() const
        {
            namespace mpl = boost::mpl;
            using namespace boost;
            
            typedef mpl::find<sequence_type, Info>::type I;
            typedef mpl::end<sequence_type>::type IEnd;
            BOOST_MPL_ASSERT((mpl::not_<boost::is_same<I, IEnd> >));

            typedef typename provider_of<Info>::type InfoProvider;
            InfoProvider &provider = ProviderOf<Info>();
            runtime_host_chain_type &chain = ChainFrom<host_info_type>();
            return chain.NewObject<Info>(provider);
        }

        template<class Info>
        bool TryGetInfo(boost::shared_ptr<Info> &pExistingInfo) const
        {
            namespace mpl = boost::mpl;
            using namespace boost;
            
            typedef mpl::find<sequence_type, Info>::type I;
            typedef mpl::end<sequence_type>::type IEnd;
            BOOST_MPL_ASSERT((mpl::not_<boost::is_same<I, IEnd> >));

            Utilities::TypeInfo key = mpl::identity<Info>();
            if (m_infoToIndex.find(key) == m_infoToIndex.end())
            {
                return false;
            }
            else
            {
                size_t index = m_infoToIndex[key];
                typedef typename provider_of<Info>::type InfoProvider;
                InfoProvider &provider = ProviderOf<Info>();
                pExistingInfo = provider[index];
                return true;
            }
        }

        mutable bool m_corVersionInitialized;
        mutable std::wstring m_corVersion;
        mutable bool m_corSysDirPathInitialized;
        mutable boost::filesystem::path m_corSysDirPath;
        mutable boost::unordered_map<Utilities::TypeInfo, size_t, Utilities::TypeInfoHash, Utilities::TypeInfoEqualTo> m_infoToIndex;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting {

#endif  // URASANDESU_CPPANONYM_HOSTING_BASERUNTIMEHOST_HPP