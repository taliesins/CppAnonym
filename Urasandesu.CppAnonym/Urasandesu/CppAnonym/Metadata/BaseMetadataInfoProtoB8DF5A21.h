﻿#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATAINFOPROTOB8DF5A21_H
#define URASANDESU_CPPANONYM_METADATA_BASEMETADATAINFOPROTOB8DF5A21_H

#ifndef URASANDESU_CPPANONYM_IHEAPCONTENT_H
#include <Urasandesu/CppAnonym/IHeapContent.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Hosting {

    template<
        class HostInfoApiType
    >
    class BaseRuntimeHostProto07F03042;

    struct DefaultRuntimeHostApiProto07F03042;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting {

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    template<
        class MetadataDispenserApiType
    >    
    class BaseMetadataDispenserProtoB8DF5A21;

    struct DefaultMetadataInfoApiProtoB8DF5A21;


    template<
        class MetadataInfoApiType = DefaultMetadataInfoApiProtoB8DF5A21
    >    
    class BaseMetadataInfoProtoB8DF5A21 :
        public IHeapContent<std::wstring>
    {
    public:
        typedef BaseMetadataInfoProtoB8DF5A21<MetadataInfoApiType> this_type;
        typedef Hosting::BaseRuntimeHostProto07F03042<
                    typename MetadataInfoApiType::runtime_host_api_type> runtime_host_type;
        typedef BaseMetadataDispenserProtoB8DF5A21<
                    typename MetadataInfoApiType::metadata_dispenser_api_type> metadata_dispenser_type;
        
        BaseMetadataInfoProtoB8DF5A21() : 
            m_pRuntimeHost(NULL)
        { }

        void Init(runtime_host_type &runtimeHost) const
        {
            _ASSERTE(m_pRuntimeHost == NULL);
                
            m_pRuntimeHost = &runtimeHost;
        }

        boost::shared_ptr<metadata_dispenser_type const> CreateDispenser() const
        {
            using namespace boost;
            _ASSERTE(m_pRuntimeHost != NULL);

            this_type *mutableThis = const_cast<this_type *>(this);
            shared_ptr<metadata_dispenser_type const> pMetaDisp;
            pMetaDisp = make_shared<metadata_dispenser_type const>();
            pMetaDisp->Init(*mutableThis);

            return pMetaDisp;
        }

    private:
        mutable runtime_host_type *m_pRuntimeHost;
    };

    typedef BaseMetadataInfoProtoB8DF5A21<> MetadataInfoProtoB8DF5A21;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATAINFOPROTOB8DF5A21_H