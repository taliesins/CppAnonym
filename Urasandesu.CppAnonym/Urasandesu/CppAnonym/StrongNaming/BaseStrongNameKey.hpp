#pragma once
#ifndef URASANDESU_CPPANONYM_STRONGNAMING_BASESTRONGNAMEKEY_HPP
#define URASANDESU_CPPANONYM_STRONGNAMING_BASESTRONGNAMEKEY_HPP

#ifndef URASANDESU_CPPANONYM_IHEAPCONTENT_H
#include <Urasandesu/CppAnonym/IHeapContent.h>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_CARTRIDGEAPISYSTEMFWD_HPP
#include <Urasandesu/CppAnonym/Traits/CartridgeApiSystemFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_STRONGNAMEINFOAPIHOLDERLABELFWD_HPP
#include <Urasandesu/CppAnonym/StrongNaming/StrongNameInfoApiHolderLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_STRONGNAMEINFOLABELFWD_HPP
#include <Urasandesu/CppAnonym/StrongNaming/StrongNameInfoLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_BASESTRONGNAMEKEYFWD_HPP
#include <Urasandesu/CppAnonym/StrongNaming/BaseStrongNameKeyFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_STRONGNAMEKEYAPIHOLDERLABELFWD_HPP
#include <Urasandesu/CppAnonym/StrongNaming/StrongNameKeyApiHolderLabelFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace StrongNaming {

    template<
        class StrongNameKeyApiHolder
    >    
    class BaseStrongNameKey
    {
    public:
        typedef BaseStrongNameKey<StrongNameKeyApiHolder> this_type;
        
        typedef typename Traits::ApiAt<StrongNameKeyApiHolder, StrongNameKeyApiHolderLabel, StrongNameInfoLabel>::type strong_name_info_type;
        
        BaseStrongNameKey() : 
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

    typedef BaseStrongNameKey<> StrongNameKey;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace StrongNaming {

#endif  // #ifndef URASANDESU_CPPANONYM_STRONGNAMING_BASESTRONGNAMEKEY_HPP