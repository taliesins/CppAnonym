#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATAINFO_HPP
#define URASANDESU_CPPANONYM_METADATA_BASEMETADATAINFO_HPP

#ifndef URASANDESU_CPPANONYM_IHEAPCONTENT_H
#include <Urasandesu/CppAnonym/IHeapContent.h>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_CARTRIDGEAPISYSTEMFWD_HPP
#include <Urasandesu/CppAnonym/Traits/CartridgeApiSystemFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_HOSTING_BASERUNTIMEHOSTFWD_HPP
#include <Urasandesu/CppAnonym/Hosting/BaseRuntimeHostFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_HOSTING_INTERFACES_RUNTIMEHOSTLABELFWD_HPP
#include <Urasandesu/CppAnonym/Hosting/Interfaces/RuntimeHostLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_HOSTING_APIHOLDERS_DEFAULTRUNTIMEHOSTAPIHOLDERFWD_H
#include <Urasandesu/CppAnonym/Hosting/ApiHolders/DefaultRuntimeHostApiHolderFwd.h>
#endif

#ifndef URASANDESU_CPPANONYM_HOSTING_INTERFACES_RUNTIMEHOSTAPIHOLDERLABELFWD_HPP
#include <Urasandesu/CppAnonym/Hosting/Interfaces/RuntimeHostApiHolderLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATAINFOFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseMetadataInfoFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_METADATAINFOAPIHOLDERLABELFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/MetadataInfoApiHolderLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMETADATAINFOAPIHOLDERFWD_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultMetadataInfoApiHolderFwd.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_METADATADISPENSERAPIHOLDERLABELFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/MetadataDispenserApiHolderLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_METADATADISPENSERLABELFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/MetadataDispenserLabelFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    template<class ApiCartridgesHolder, class ApiLabel>
    struct MetadataInfoApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::MetadataInfoApiHolderLabel, ApiLabel>
    {
    };

    template<
        class MetadataInfoApiHolder
    >    
    class BaseMetadataInfo :
        public IHeapContent<std::wstring>
    {
    public:
        typedef BaseMetadataInfo<MetadataInfoApiHolder> this_type;

        typedef typename MetadataInfoApiAt<MetadataInfoApiHolder, Hosting::Interfaces::RuntimeHostLabel>::type runtime_host_type;
        typedef typename MetadataInfoApiAt<MetadataInfoApiHolder, Interfaces::MetadataDispenserLabel>::type metadata_dispenser_type;
        
        BaseMetadataInfo() : 
            m_pRuntimeHost(NULL)
        { }

        void Init(runtime_host_type &runtimeHost) const
        {
            _ASSERTE(m_pRuntimeHost == NULL);
                
            m_pRuntimeHost = &runtimeHost;
        }

        template<class T>
        T const *FindType() const { return static_cast<runtime_host_type const *>(m_pRuntimeHost)->FindType<T>(); }

        template<class T>
        T *FindType() { return m_pRuntimeHost->FindType<T>(); }
      
        template<>
        this_type const *FindType<this_type>() const { return this; }
      
        template<>
        this_type *FindType<this_type>() { return this; }

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

    typedef BaseMetadataInfo<> MetadataInfo;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATAINFO_HPP