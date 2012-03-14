#pragma once
#ifndef URASANDESU_CPPANONYM_FUSION_BASERUNTIMEHOSTPROTO07F03042_H
#define URASANDESU_CPPANONYM_FUSION_BASERUNTIMEHOSTPROTO07F03042_H

namespace Urasandesu { namespace CppAnonym { namespace StrongNaming {

    template<
        class StrongNameInfoApiType
    >    
    class BaseStrongNameInfoProto4236D495; 

}}}   // namespace Urasandesu { namespace CppAnonym { namespace StrongNaming {

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    template<
        class MetadataInfoApiType
    >    
    class BaseMetadataInfoProtoB8DF5A21;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

namespace Urasandesu { namespace CppAnonym { namespace Fusion {

    template<
        class FusionInfoApiType
    >    
    class BaseFusionInfoProto3CBCB74B;

}}}  // namespace Urasandesu { namespace CppAnonym { namespace Fusion {

namespace Urasandesu { namespace CppAnonym { namespace Hosting {

    template<
        class RuntimeHostApiType = DefaultRuntimeHostApiProto07F03042
    >
    class BaseRuntimeHostProto07F03042 : 
        public IHeapContent<std::wstring>, 
        public HeapProvider<
            std::wstring, 
            boost::mpl::vector<
                StrongNaming::BaseStrongNameInfoProto4236D495<typename RuntimeHostApiType::info_strong_naming_api_type>, 
                Metadata::BaseMetadataInfoProtoB8DF5A21<typename RuntimeHostApiType::info_metadata_api_type>, 
                Fusion::BaseFusionInfoProto3CBCB74B<typename RuntimeHostApiType::info_fusion_api_type>
            >
        >
    {
    public:
        typedef BaseRuntimeHostProto07F03042<RuntimeHostApiType> this_type;
        typedef StrongNaming::BaseStrongNameInfoProto4236D495<typename RuntimeHostApiType::info_strong_naming_api_type> strong_name_info_type;
        typedef typename type_decided_by<strong_name_info_type>::type strong_name_info_heap_type;
        typedef Fusion::BaseFusionInfoProto3CBCB74B<typename RuntimeHostApiType::info_fusion_api_type> fusion_info_type;
        typedef typename type_decided_by<fusion_info_type>::type fusion_info_heap_type;

        BaseRuntimeHostProto07F03042() : 
            m_infosInitialized(false),
            m_corVersionInitialized(false), 
            m_corSystemDirectoryPathInitialized(false)
        { }

        template<class InfoType>
        InfoType const *GetInfo() const
        {
            namespace mpl = boost::mpl;
            using namespace boost;
            
            typedef mpl::find<sequence_type, InfoType>::type i;
            typedef mpl::end<sequence_type>::type i_end;
            BOOST_MPL_ASSERT((mpl::not_<boost::is_same<i, i_end> >));

            if (!m_infosInitialized)
            {
                mpl::for_each<sequence_type>(m_infosInitializer(m_infos));
                m_infosInitialized = true;
            }

            typedef typename type_decided_by<InfoType>::type info_heap_type;
            LPCSTR infoTypeName = typeid(InfoType).name();
            InfoType *pInfo = static_cast<InfoType *>(m_infos[infoTypeName]);
            if (pInfo == NULL)
            {
                info_heap_type &infoHeap = const_cast<this_type *>(this)->Of<InfoType>();
                pInfo = infoHeap.New(GetCORVersion());
                pInfo->Init(*this);
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
        mutable bool m_infosInitialized;
        mutable boost::unordered_map<std::string, void *> m_infos;
        
        class m_infosInitializer
        {
        public:
            m_infosInitializer(boost::unordered_map<std::string, void *> &infos) : 
                m_pInfos(&infos)
            { }

            template<typename T> 
            void operator()(T _)
            {
                (*m_pInfos)[typeid(T).name()] = NULL;
            }

        private:
            boost::unordered_map<std::string, void *> *m_pInfos;
        };

        mutable bool m_corVersionInitialized;
        mutable std::wstring m_corVersion;
        mutable bool m_corSystemDirectoryPathInitialized;
        mutable boost::filesystem::path m_corSystemDirectoryPath;
    };

    typedef BaseRuntimeHostProto07F03042<> RuntimeHostProto07F03042;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting {

#endif  // URASANDESU_CPPANONYM_FUSION_BASERUNTIMEHOSTPROTO07F03042_H