#pragma once
#ifndef URASANDESU_CPPANONYM_STRONGNAMING_BASESTRONGNAMEINFOPROTO4236D495_H
#define URASANDESU_CPPANONYM_STRONGNAMING_BASESTRONGNAMEINFOPROTO4236D495_H

#ifndef URASANDESU_CPPANONYM_IHEAPCONTENT_H
#include <Urasandesu/CppAnonym/IHeapContent.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Traits {

    template<class ApiType, class IParentApiType>
    struct ParentApiOrDefault;

    template<class ApiType, class IChildApiType>
    struct ChildApiOrDefault;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Traits {

namespace Urasandesu { namespace CppAnonym { namespace StrongNaming {

    struct IStrongNameKeyApi;

    template<
        class StrongNameKeyApiType
    >    
    class BaseStrongNameKeyProto4236D495;


    struct IStrongNameInfoApi { };
    struct DefaultStrongNameInfoApiProto4236D495 : IStrongNameInfoApi { };

    template<
        class StrongNameInfoApiType = DefaultStrongNameInfoApiProto4236D495
    >    
    class BaseStrongNameInfoProto4236D495 : 
        public IHeapContent<std::wstring>
    {
    public:
        typedef BaseStrongNameInfoProto4236D495<StrongNameInfoApiType> this_type;
        typedef typename Traits::ChildApiOrDefault<StrongNameInfoApiType, IStrongNameKeyApi>::type strong_name_key_api_type;
        typedef BaseStrongNameKeyProto4236D495<strong_name_key_api_type> strong_name_key_type;

        boost::shared_ptr<strong_name_key_type const> CreateKey(PublicKeyBlob const *pPubKeyBlob, DWORD pubKeyBlobSize) const
        {
            boost::shared_ptr<strong_name_key_type const> pSnKey;
            pSnKey = boost::make_shared<strong_name_key_type const>();
            this_type *mutableThis = const_cast<this_type *>(this);
            pSnKey->Init(*mutableThis, pPubKeyBlob, pubKeyBlobSize);
            return pSnKey; 
        }
    };

    typedef BaseStrongNameInfoProto4236D495<> StrongNameInfoProto4236D495;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace StrongNaming {

#endif  // #ifndef URASANDESU_CPPANONYM_STRONGNAMING_BASESTRONGNAMEINFOPROTO4236D495_H