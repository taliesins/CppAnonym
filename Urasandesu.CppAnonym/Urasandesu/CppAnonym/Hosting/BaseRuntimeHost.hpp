#pragma once
#ifndef URASANDESU_CPPANONYM_HOSTING_BASERUNTIMEHOST_HPP
#define URASANDESU_CPPANONYM_HOSTING_BASERUNTIMEHOST_HPP

#ifndef URASANDESU_CPPANONYM_IHEAPCONTENT_H
#include <Urasandesu/CppAnonym/IHeapContent.h>
#endif

#ifndef URASANDESU_CPPANONYM_HEAPPROVIDERFWD_HPP
#include <Urasandesu/CppAnonym/HeapProviderFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_CARTRIDGEAPISYSTEMFWD_HPP
#include <Urasandesu/CppAnonym/Traits/CartridgeApiSystemFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_HOSTING_BASERUNTIMEHOSTFWD_HPP
#include <Urasandesu/CppAnonym/Hosting/BaseRuntimeHostFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_HOSTING_APIHOLDERS_DEFAULTRUNTIMEHOSTAPIHOLDERFWD_H
#include <Urasandesu/CppAnonym/Hosting/ApiHolders/DefaultRuntimeHostApiHolderFwd.h>
#endif

#ifndef URASANDESU_CPPANONYM_FUSION_BASEFUSIONINFOFWD_HPP
#include <Urasandesu/CppAnonym/Fusion/BaseFusionInfoFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_FUSION_INTERFACES_FUSIONINFOAPIHOLDERLABELFWD_HPP
#include <Urasandesu/CppAnonym/Fusion/Interfaces/FusionInfoApiHolderLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_INTERFACES_STRONGNAMEINFOAPIHOLDERLABELFWD_HPP
#include <Urasandesu/CppAnonym/StrongNaming/Interfaces/StrongNameInfoApiHolderLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_BASESTRONGNAMEINFOFWD_HPP
#include <Urasandesu/CppAnonym/StrongNaming/BaseStrongNameInfoFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATAINFOFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseMetadataInfoFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_METADATAINFOAPIHOLDERLABELFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/MetadataInfoApiHolderLabelFwd.hpp>
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
        T const *FindType() const { return GetInfo<T>(); }

        template<class T>
        T *FindType() { return GetInfo<T>(); }
      
        template<>
        this_type const *FindType<this_type>() const { return this; }
      
        template<>
        this_type *FindType<this_type>() { return this; }

        template<class InfoType>
        InfoType const *GetInfo() const
        {
            namespace mpl = boost::mpl;
            using namespace boost;
            
            typedef mpl::find<sequence_type, InfoType>::type I;
            typedef mpl::end<sequence_type>::type IEnd;
            BOOST_MPL_ASSERT((mpl::not_<boost::is_same<I, IEnd> >));

            LPCSTR infoTypeName = typeid(InfoType).name();
            if (m_infos.find(infoTypeName) == m_infos.end())
            {
                m_infos[infoTypeName] = NULL;
            }

            InfoType const *pInfo = static_cast<InfoType const *>(m_infos[infoTypeName]);
            if (pInfo == NULL)
            {
                this_type *mutableThis = const_cast<this_type *>(this);
                typedef typename type_decided_by<InfoType>::type InfoHeap;
                InfoHeap &heap = mutableThis->Of<InfoType>();
                pInfo = heap.New(GetCORVersion());
                pInfo->Init(*mutableThis);
                m_infos[infoTypeName] = pInfo;
            }

            return pInfo;
        }
        
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
        mutable boost::unordered_map<std::string, void const *> m_infos;
        mutable bool m_corVersionInitialized;
        mutable std::wstring m_corVersion;
        mutable bool m_corSystemDirectoryPathInitialized;
        mutable boost::filesystem::path m_corSystemDirectoryPath;
    };

    typedef BaseRuntimeHost<> RuntimeHost;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting {

#endif  // URASANDESU_CPPANONYM_HOSTING_BASERUNTIMEHOST_HPP