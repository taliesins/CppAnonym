#pragma once
#ifndef URASANDESU_CPPANONYM_STRONGNAMING_BASESTRONGNAMEINFO_HPP
#define URASANDESU_CPPANONYM_STRONGNAMING_BASESTRONGNAMEINFO_HPP

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

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_APIHOLDERS_DEFAULTSTRONGNAMEINFOAPIHOLDERFWD_H
#include <Urasandesu/CppAnonym/StrongNaming/ApiHolders/DefaultStrongNameInfoApiHolderFwd.h>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_INTERFACES_STRONGNAMEINFOAPIHOLDERLABELFWD_HPP
#include <Urasandesu/CppAnonym/StrongNaming/Interfaces/StrongNameInfoApiHolderLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_BASESTRONGNAMEINFOFWD_HPP
#include <Urasandesu/CppAnonym/StrongNaming/BaseStrongNameInfoFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_INTERFACES_STRONGNAMEKEYLABELFWD_HPP
#include <Urasandesu/CppAnonym/StrongNaming/Interfaces/StrongNameKeyLabelFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace StrongNaming {

    template<class ApiCartridgesHolder, class ApiLabel>
    struct StrongNameInfoApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::StrongNameInfoApiHolderLabel, ApiLabel>
    {
    };

    template<
        class StrongNameInfoApiHolder
    >    
    class BaseStrongNameInfo : 
        public IHeapContent<std::wstring>
    {
    public:
        typedef BaseStrongNameInfo<StrongNameInfoApiHolder> this_type;

        typedef typename StrongNameInfoApiAt<StrongNameInfoApiHolder, Hosting::Interfaces::RuntimeHostLabel>::type runtime_host_type;
        typedef typename StrongNameInfoApiAt<StrongNameInfoApiHolder, Interfaces::StrongNameKeyLabel>::type strong_name_key_type;

        BaseStrongNameInfo() : 
            m_pRuntimeHost(NULL)
        { }

        void Init(runtime_host_type &runtimeHost) const
        {
            _ASSERTE(m_pRuntimeHost == NULL);
                
            m_pRuntimeHost = &runtimeHost;
        }

        boost::shared_ptr<strong_name_key_type const> CreateKey(PublicKeyBlob const *pPubKeyBlob, DWORD pubKeyBlobSize) const
        {
            boost::shared_ptr<strong_name_key_type const> pSnKey;
            pSnKey = boost::make_shared<strong_name_key_type const>();
            this_type *mutableThis = const_cast<this_type *>(this);
            pSnKey->Init(*mutableThis, pPubKeyBlob, pubKeyBlobSize);
            return pSnKey; 
        }
    
    private:
        mutable runtime_host_type *m_pRuntimeHost;
    };

    typedef BaseStrongNameInfo<> StrongNameInfo;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace StrongNaming {

#endif  // #ifndef URASANDESU_CPPANONYM_STRONGNAMING_BASESTRONGNAMEINFO_HPP