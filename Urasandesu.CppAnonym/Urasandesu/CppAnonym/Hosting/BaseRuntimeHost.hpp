#pragma once
#ifndef URASANDESU_CPPANONYM_HOSTING_BASERUNTIMEHOST_HPP
#define URASANDESU_CPPANONYM_HOSTING_BASERUNTIMEHOST_HPP

#ifndef URASANDESU_CPPANONYM_IHEAPCONTENT_H
#include <Urasandesu/CppAnonym/IHeapContent.h>
#endif

#ifndef URASANDESU_CPPANONYM_HEAPPROVIDER_HPP
#include <Urasandesu/CppAnonym/HeapProvider.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_CARTRIDGEAPISYSTEM_HPP
#include <Urasandesu/CppAnonym/Traits/CartridgeApiSystem.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_HOSTING_APIHOLDERS_DEFAULTRUNTIMEHOSTAPIHOLDER_H
#include <Urasandesu/CppAnonym/Hosting/ApiHolders/DefaultRuntimeHostApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_FUSION_INTERFACES_FUSIONINFOAPIHOLDERLABEL_HPP
#include <Urasandesu/CppAnonym/Fusion/Interfaces/FusionInfoApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_INTERFACES_STRONGNAMEINFOAPIHOLDERLABEL_HPP
#include <Urasandesu/CppAnonym/StrongNaming/Interfaces/StrongNameInfoApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_METADATAINFOAPIHOLDERLABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/MetadataInfoApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMCOMEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymCOMException.h>
#endif

#ifndef URASANDESU_CPPANONYM_HOSTING_BASERUNTIMEHOSTFWD_HPP
#include <Urasandesu/CppAnonym/Hosting/BaseRuntimeHostFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Hosting {

    template<class ApiCartridgesHolder, class ApiLabel>
    struct RuntimeHostApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::RuntimeHostApiHolderLabel, ApiLabel>
    {
    };

    template<
        class RuntimeHostApiHolder
    >
    class BaseRuntimeHost : 
        public IHeapContent<std::wstring>, 
        public HeapProvider<
            std::wstring, 
            boost::mpl::vector<
                typename RuntimeHostApiAt<RuntimeHostApiHolder, StrongNaming::Interfaces::StrongNameInfoLabel>::type, 
                typename RuntimeHostApiAt<RuntimeHostApiHolder, Metadata::Interfaces::MetadataInfoLabel>::type, 
                typename RuntimeHostApiAt<RuntimeHostApiHolder, Fusion::Interfaces::FusionInfoLabel>::type
            >
        >
    {
    public:
        typedef BaseRuntimeHost<RuntimeHostApiHolder> this_type;
        
        typedef typename RuntimeHostApiAt<RuntimeHostApiHolder, StrongNaming::Interfaces::StrongNameInfoLabel>::type strong_name_info_type;
        typedef typename RuntimeHostApiAt<RuntimeHostApiHolder, Metadata::Interfaces::MetadataInfoLabel>::type metadata_info_type;
        typedef typename RuntimeHostApiAt<RuntimeHostApiHolder, Fusion::Interfaces::FusionInfoLabel>::type fusion_info_type;

        BaseRuntimeHost() : 
            m_corVersionInitialized(false), 
            m_corSystemDirectoryPathInitialized(false)
        { }

        template<class T>
        T const &Map() const { return GetInfo<T>(); }

        template<class T>
        T &Map() { return const_cast<T &>(GetInfo<T>()); }
      
        template<>
        this_type const &Map<this_type>() const { return this; }
      
        template<>
        this_type &Map<this_type>() { return this; }
        
        std::wstring const &GetCORVersion() const
        {
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
            using namespace boost::filesystem;

            if (!m_corSystemDirectoryPathInitialized)
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

                m_corSystemDirectoryPath = buffer;
                
                m_corSystemDirectoryPathInitialized = true;
            }
            return m_corSystemDirectoryPath;
        }
    
    private:
        template<class InfoType>
        InfoType const &GetInfo() const
        {
            namespace mpl = boost::mpl;
            using namespace boost;
            
            typedef mpl::find<sequence_type, InfoType>::type I;
            typedef mpl::end<sequence_type>::type IEnd;
            BOOST_MPL_ASSERT((mpl::not_<boost::is_same<I, IEnd> >));

            Utilities::TypeInfo infoType = mpl::identity<InfoType>();
            if (m_infos.find(infoType) == m_infos.end())
            {
                m_infos[infoType] = NULL;
            }

            InfoType const *pInfo = static_cast<InfoType const *>(m_infos[infoType]);
            if (pInfo == NULL)
            {
                this_type *pMutableThis = const_cast<this_type *>(this);
                typedef typename type_decided_by<InfoType>::type InfoHeap;
                InfoHeap &heap = pMutableThis->Of<InfoType>();
                pInfo = heap.New(GetCORVersion());
                pInfo->Init(*pMutableThis);
                m_infos[infoType] = pInfo;
            }

            return *pInfo;
        }

        mutable boost::unordered_map<Utilities::TypeInfo, void const *, Utilities::TypeInfoHash, Utilities::TypeInfoEqualTo> m_infos;
        mutable bool m_corVersionInitialized;
        mutable std::wstring m_corVersion;
        mutable bool m_corSystemDirectoryPathInitialized;
        mutable boost::filesystem::path m_corSystemDirectoryPath;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting {

#endif  // URASANDESU_CPPANONYM_HOSTING_BASERUNTIMEHOST_HPP