#pragma once
#ifndef URASANDESU_CPPANONYM_STRONGNAMING_BASESTRONGNAMEINFOPROTO4236D495_H
#define URASANDESU_CPPANONYM_STRONGNAMING_BASESTRONGNAMEINFOPROTO4236D495_H

#ifndef URASANDESU_CPPANONYM_IHEAPCONTENT_H
#include <Urasandesu/CppAnonym/IHeapContent.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Hosting {

    template<
        class HostInfoApiType
    >
    class BaseRuntimeHostProto07F03042;

    struct IRuntimeHostApi;

    struct DefaultRuntimeHostApiProto07F03042;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting {

namespace Urasandesu { namespace CppAnonym { namespace Traits {

    //template<class ApiType, class IParentApiType>
    //struct ParentApiOrDefault;

    //template<class ApiType, class IChildApiType>
    //struct ChildApiOrDefault;

    template<class ApiType, class ApiTypeInterface, class IExternalApiType>
    struct ExternalApiOrDefault;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Traits {

namespace Urasandesu { namespace CppAnonym { namespace StrongNaming {

    struct DefaultStrongNameKeyApiProto4236D495;

    struct IStrongNameInfoApi { };
    struct DefaultStrongNameInfoApiProto4236D495 : 
        IStrongNameInfoApi 
    { 
        //typedef Hosting::DefaultRuntimeHostApiProto07F03042 parent_api_type;
        typedef boost::mpl::vector<Hosting::DefaultRuntimeHostApiProto07F03042, 
                                   DefaultStrongNameKeyApiProto4236D495> external_api_types;
    };

    
    struct IStrongNameKeyApi;

    template<
        class StrongNameKeyApiType
    >    
    class BaseStrongNameKeyProto4236D495;

    
    template<
        class StrongNameInfoApiType = DefaultStrongNameInfoApiProto4236D495
    >    
    class BaseStrongNameInfoProto4236D495 : 
        public IHeapContent<std::wstring>
    {
    public:
        typedef BaseStrongNameInfoProto4236D495<StrongNameInfoApiType> this_type;

        typedef typename Traits::ExternalApiOrDefault<StrongNameInfoApiType, IStrongNameInfoApi, Hosting::IRuntimeHostApi>::type runtime_host_api_type;
        typedef Hosting::BaseRuntimeHostProto07F03042<runtime_host_api_type> runtime_host_type;

        typedef typename Traits::ExternalApiOrDefault<StrongNameInfoApiType, IStrongNameInfoApi, IStrongNameKeyApi>::type strong_name_key_api_type;
        typedef BaseStrongNameKeyProto4236D495<strong_name_key_api_type> strong_name_key_type;

        BaseStrongNameInfoProto4236D495() : 
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

    typedef BaseStrongNameInfoProto4236D495<> StrongNameInfoProto4236D495;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace StrongNaming {

#endif  // #ifndef URASANDESU_CPPANONYM_STRONGNAMING_BASESTRONGNAMEINFOPROTO4236D495_H