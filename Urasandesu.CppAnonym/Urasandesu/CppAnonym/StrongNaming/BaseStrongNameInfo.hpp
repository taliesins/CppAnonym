#pragma once
#ifndef URASANDESU_CPPANONYM_STRONGNAMING_BASESTRONGNAMEINFO_HPP
#define URASANDESU_CPPANONYM_STRONGNAMING_BASESTRONGNAMEINFO_HPP

#ifndef URASANDESU_CPPANONYM_IHEAPCONTENT_H
#include <Urasandesu/CppAnonym/IHeapContent.h>
#endif

#ifndef URASANDESU_CPPANONYM_SIMPLEHEAPPROVIDER_HPP
#include <Urasandesu/CppAnonym/SimpleHeapProvider.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_OBJECTTAG_HPP
#include <Urasandesu/CppAnonym/ObjectTag.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_CARTRIDGEAPISYSTEM_HPP
#include <Urasandesu/CppAnonym/Traits/CartridgeApiSystem.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_HOSTING_INTERFACES_RUNTIMEHOSTLABEL_HPP
#include <Urasandesu/CppAnonym/Hosting/Interfaces/RuntimeHostLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_HOSTING_INTERFACES_RUNTIMEHOSTAPIHOLDERLABEL_HPP
#include <Urasandesu/CppAnonym/Hosting/Interfaces/RuntimeHostApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_INTERFACES_STRONGNAMEINFOAPIHOLDERLABEL_HPP
#include <Urasandesu/CppAnonym/StrongNaming/Interfaces/StrongNameInfoApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_INTERFACES_STRONGNAMEKEYLABEL_HPP
#include <Urasandesu/CppAnonym/StrongNaming/Interfaces/StrongNameKeyLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_BASESTRONGNAMEINFOFWD_HPP
#include <Urasandesu/CppAnonym/StrongNaming/BaseStrongNameInfoFwd.hpp>
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
        public IHeapContent<std::wstring>,
        public SimpleHeapProvider<
            boost::mpl::vector<
                ObjectTag<typename StrongNameInfoApiAt<StrongNameInfoApiHolder, Interfaces::StrongNameKeyLabel>::type, QuickHeap>
            >
        >
    {
    public:
        typedef BaseStrongNameInfo<StrongNameInfoApiHolder> this_type;

        typedef typename StrongNameInfoApiAt<StrongNameInfoApiHolder, Hosting::Interfaces::RuntimeHostLabel>::type runtime_host_type;
        typedef typename StrongNameInfoApiAt<StrongNameInfoApiHolder, Interfaces::StrongNameKeyLabel>::type strong_name_key_type;

        typedef ObjectTag<strong_name_key_type, QuickHeap> strong_name_key_obj_tag_type;
        typedef typename type_decided_by<strong_name_key_obj_tag_type>::type strong_name_key_heap_type;

        BaseStrongNameInfo() : 
            m_pRuntimeHost(NULL)
        { }

        void Init(runtime_host_type &runtimeHost) const
        {
            _ASSERTE(m_pRuntimeHost == NULL);
                
            m_pRuntimeHost = &runtimeHost;
        }

        //boost::shared_ptr<strong_name_key_type const> CreateKey(PublicKeyBlob const *pPubKeyBlob, DWORD pubKeyBlobSize) const
        //{
        //    boost::shared_ptr<strong_name_key_type const> pSnKey;
        //    pSnKey = boost::make_shared<strong_name_key_type const>();
        //    this_type *pMutableThis = const_cast<this_type *>(this);
        //    pSnKey->Init(*pMutableThis, pPubKeyBlob, pubKeyBlobSize);
        //    return pSnKey; 
        //}

        strong_name_key_type const *GetStrongNameKey(PublicKeyBlob const &pubKeyBlob, DWORD pubKeyBlobSize) const
        {
            this_type *pMutableThis = const_cast<this_type *>(this);

            strong_name_key_type *pSnKey = NULL;
            pSnKey = pMutableThis->StrongNameKeyHeap().New();
            pSnKey->Init(*pMutableThis);
            pSnKey->SetPublicKeyBlob(pubKeyBlob, pubKeyBlobSize);
            return pSnKey;
        }

        strong_name_key_type const *GetStrongNameKey(std::wstring const &snkFilePath) const
        {
            typedef std::vector<BYTE, Utilities::StackAllocator<BYTE> > ByteVector;
            ByteVector keyPair;
            DWORD keyPairSize = 0;
            PublicKeyBlob *pPubKeyBlob = NULL;
            DWORD pubKeyBlobSize = 0;
            HANDLE hSnk = NULL;
            hSnk = ::CreateFileW(snkFilePath.c_str(), GENERIC_READ, FILE_SHARE_READ, NULL, 
                                    OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL | FILE_FLAG_SEQUENTIAL_SCAN, NULL);
            if (hSnk == INVALID_HANDLE_VALUE)
                BOOST_THROW_EXCEPTION(CppAnonymSystemException(::GetLastError()));
            BOOST_SCOPE_EXIT((&hSnk))
            {
                ::CloseHandle(hSnk);
            }
            BOOST_SCOPE_EXIT_END
            
            keyPairSize = ::GetFileSize(hSnk, NULL);
            if (keyPairSize == -1)
                BOOST_THROW_EXCEPTION(CppAnonymSystemException(::GetLastError()));

            if (keyPairSize == 0)
                return NULL;
            
            keyPair.resize(keyPairSize);
            if (::ReadFile(hSnk, &keyPair[0], keyPairSize, &keyPairSize, NULL) == FALSE)
                BOOST_THROW_EXCEPTION(CppAnonymSystemException(::GetLastError()));

            if (!::StrongNameGetPublicKey(NULL, &keyPair[0], keyPairSize, reinterpret_cast<BYTE **>(&pPubKeyBlob), &pubKeyBlobSize))
                BOOST_THROW_EXCEPTION(CppAnonymCOMException(::StrongNameErrorInfo()));
            BOOST_SCOPE_EXIT((&pubKeyBlobSize)(&pPubKeyBlob))
            {
                if (pubKeyBlobSize)
                    ::StrongNameFreeBuffer(reinterpret_cast<BYTE *>(pPubKeyBlob));
            }
            BOOST_SCOPE_EXIT_END

            if (pubKeyBlobSize == 0)
                return NULL;

            return GetStrongNameKey(*pPubKeyBlob, pubKeyBlobSize);
        }

    private:
        strong_name_key_heap_type &StrongNameKeyHeap()
        {
            return Of<strong_name_key_obj_tag_type>();
        }
        
        strong_name_key_heap_type const &StrongNameKeyHeap() const
        {
            return Of<strong_name_key_obj_tag_type>();
        }

        mutable runtime_host_type *m_pRuntimeHost;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace StrongNaming {

#endif  // #ifndef URASANDESU_CPPANONYM_STRONGNAMING_BASESTRONGNAMEINFO_HPP