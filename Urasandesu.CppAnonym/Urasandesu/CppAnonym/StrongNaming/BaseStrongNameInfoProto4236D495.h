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

    struct IStrongNameInfoApi;

    template<
        class StrongNameInfoApiType
    >    
    class BaseStrongNameInfoProto4236D495;


    struct IStrongNameKeyApi { };
    struct DefaultStrongNameKeyApiProto4236D495 : IStrongNameKeyApi { };

    template<
        class StrongNameKeyApiType = DefaultStrongNameKeyApiProto4236D495
    >    
    class BaseStrongNameKeyProto4236D495
    {
    public:
        typedef BaseStrongNameKeyProto4236D495<StrongNameKeyApiType> this_type;
        typedef typename Traits::ParentApiOrDefault<StrongNameKeyApiType, IStrongNameInfoApi>::type strong_name_info_api_type;
        typedef BaseStrongNameInfoProto4236D495<strong_name_info_api_type> strong_name_info_type;
        
        BaseStrongNameKeyProto4236D495() : 
            m_pSnInfo(NULL), 
            m_pubKeyBlobSize(0), 
            m_publicKeyInitialized(false), 
            m_publicKeyTokenInitialized(false)
        { }

        void Init(strong_name_info_type &snInfo, PublicKeyBlob const *pPubKeyBlob, DWORD pubKeyBlobSize) const
        {
            //using namespace boost::filesystem;
            _ASSERTE(m_pSnInfo == NULL);

            m_pSnInfo = &snInfo;

            m_pPubKeyBlob = std::auto_ptr<PublicKeyBlob>(reinterpret_cast<PublicKeyBlob *>(new BYTE[pubKeyBlobSize]));
            ::memcpy_s(m_pPubKeyBlob.get(), pubKeyBlobSize, pPubKeyBlob, pubKeyBlobSize);
            m_pubKeyBlobSize = pubKeyBlobSize;
        }

        std::vector<BYTE> const &GetPublicKey() const
        {
            if (!m_publicKeyInitialized)
            {
                if (m_pubKeyBlobSize)
                {
                    m_publicKey.reserve(m_pPubKeyBlob->cbPublicKey);
                    BYTE const *pPubKey = reinterpret_cast<BYTE const *>(m_pPubKeyBlob->PublicKey);
                    m_publicKey.assign(pPubKey, pPubKey + m_pPubKeyBlob->cbPublicKey);
                }
                m_publicKeyInitialized = true;
            }
            return m_publicKey;
        }

        std::vector<BYTE> const &GetPublicKeyToken() const
        {
            if (!m_publicKeyTokenInitialized)
            {
                if (m_pubKeyBlobSize)
                {
                    BYTE *pPubKeyToken = NULL;
                    DWORD pubKeyTokenSize = 0;
                    if (!::StrongNameTokenFromPublicKey(reinterpret_cast<BYTE *>(m_pPubKeyBlob.get()), 
                                                        m_pubKeyBlobSize, 
                                                        &pPubKeyToken, 
                                                        &pubKeyTokenSize))
                        BOOST_THROW_EXCEPTION(CppAnonymCOMException(::StrongNameErrorInfo()));
                    BOOST_SCOPE_EXIT((pPubKeyToken))
                    {
                        ::StrongNameFreeBuffer(pPubKeyToken);
                    }
                    BOOST_SCOPE_EXIT_END
                    
                    m_publicKeyToken.reserve(pubKeyTokenSize);
                    m_publicKeyToken.assign(pPubKeyToken, pPubKeyToken + pubKeyTokenSize);
                }
                m_publicKeyTokenInitialized = true;
            }
            return m_publicKeyToken;
        }

    private:
        mutable strong_name_info_type *m_pSnInfo;
        mutable std::auto_ptr<PublicKeyBlob> m_pPubKeyBlob;
        mutable DWORD m_pubKeyBlobSize;
        mutable bool m_publicKeyInitialized;
        mutable std::vector<BYTE> m_publicKey;
        mutable bool m_publicKeyTokenInitialized;
        mutable std::vector<BYTE> m_publicKeyToken;
    };

    typedef BaseStrongNameKeyProto4236D495<> StrongNameKeyProto4236D495;

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