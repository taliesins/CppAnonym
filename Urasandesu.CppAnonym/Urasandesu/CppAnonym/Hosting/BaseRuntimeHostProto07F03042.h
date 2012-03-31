#pragma once
#ifndef URASANDESU_CPPANONYM_FUSION_BASERUNTIMEHOSTPROTO07F03042_H
#define URASANDESU_CPPANONYM_FUSION_BASERUNTIMEHOSTPROTO07F03042_H

#ifndef URASANDESU_CPPANONYM_IHEAPCONTENT_H
#include <Urasandesu/CppAnonym/IHeapContent.h>
#endif

namespace Urasandesu { namespace CppAnonym {

    template<class Key, class Sequence>
    class ATL_NO_VTABLE HeapProvider;

}}   // namespace Urasandesu { namespace CppAnonym {

namespace Urasandesu { namespace CppAnonym { namespace StrongNaming {

    struct IStrongNameInfoApi;

    template<
        class StrongNameInfoApiType
    >    
    class BaseStrongNameInfoProto4236D495; 

}}}   // namespace Urasandesu { namespace CppAnonym { namespace StrongNaming {

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    struct IMetadataInfoApi;

    template<
        class MetadataInfoApiType
    >    
    class BaseMetadataInfoProtoB8DF5A21;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

namespace Urasandesu { namespace CppAnonym { namespace Fusion {

    struct IFusionInfoApi;

    template<
        class FusionInfoApiType
    >    
    class BaseFusionInfoProto3CBCB74B;

}}}  // namespace Urasandesu { namespace CppAnonym { namespace Fusion {

namespace Urasandesu { namespace CppAnonym { namespace Hosting {

    struct DefaultRuntimeHostApiProto07F03042;

    
    template<
        class RuntimeHostApiType = DefaultRuntimeHostApiProto07F03042
    >
    class BaseRuntimeHostProto07F03042 : 
        public IHeapContent<std::wstring>, 
        public HeapProvider<
            std::wstring, 
            boost::mpl::vector<
                StrongNaming::BaseStrongNameInfoProto4236D495<typename Traits::ChildApiOrDefault<RuntimeHostApiType, StrongNaming::IStrongNameInfoApi>::type>, 
                Metadata::BaseMetadataInfoProtoB8DF5A21<typename Traits::ChildApiOrDefault<RuntimeHostApiType, Metadata::IMetadataInfoApi>::type>, 
                Fusion::BaseFusionInfoProto3CBCB74B<typename Traits::ChildApiOrDefault<RuntimeHostApiType, Fusion::IFusionInfoApi>::type>
            >
        >
    {
    public:
        typedef BaseRuntimeHostProto07F03042<RuntimeHostApiType> this_type;
        
        typedef typename Traits::ChildApiOrDefault<RuntimeHostApiType, StrongNaming::IStrongNameInfoApi>::type strong_naming_info_api_type;
        typedef StrongNaming::BaseStrongNameInfoProto4236D495<strong_naming_info_api_type> strong_name_info_type;

        typedef typename Traits::ChildApiOrDefault<RuntimeHostApiType, Metadata::IMetadataInfoApi>::type metadata_info_api_type;
        typedef Metadata::BaseMetadataInfoProtoB8DF5A21<metadata_info_api_type> metadata_info_type;
        
        typedef typename Traits::ChildApiOrDefault<RuntimeHostApiType, Fusion::IFusionInfoApi>::type fusion_info_api_type;
        typedef Fusion::BaseFusionInfoProto3CBCB74B<fusion_info_api_type> fusion_info_type;

        BaseRuntimeHostProto07F03042() : 
            m_corVersionInitialized(false), 
            m_corSystemDirectoryPathInitialized(false)
        { }

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

    typedef BaseRuntimeHostProto07F03042<> RuntimeHostProto07F03042;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting {

#endif  // URASANDESU_CPPANONYM_FUSION_BASERUNTIMEHOSTPROTO07F03042_H