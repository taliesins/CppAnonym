#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYNAMEMETADATA_HPP
#define URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYNAMEMETADATA_HPP

#ifndef URASANDESU_CPPANONYM_IHEAPCONTENT_H
#include <Urasandesu/CppAnonym/IHeapContent.h>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_CARTRIDGEAPISYSTEMFWD_HPP
#include <Urasandesu/CppAnonym/Traits/CartridgeApiSystemFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_INTERFACES_STRONGNAMEINFOLABELFWD_HPP
#include <Urasandesu/CppAnonym/StrongNaming/Interfaces/StrongNameInfoLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_INTERFACES_STRONGNAMEKEYLABELFWD_HPP
#include <Urasandesu/CppAnonym/StrongNaming/Interfaces/StrongNameKeyLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_ASSEMBLYMETADATALABELFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/AssemblyMetadataLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_ASSEMBLYNAMEMETADATAAPIHOLDERLABELFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/AssemblyNameMetadataApiHolderLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYNAMEMETADATAFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseAssemblyNameMetadataFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    template<class ApiCartridgesHolder, class ApiLabel>
    struct AssemblyNameMetadataApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::AssemblyNameMetadataApiHolderLabel, ApiLabel>
    {
    };

    template<
        class AssemblyNameMetadataApiHolder
    >    
    class BaseAssemblyNameMetadata :
        public IHeapContent<mdAssembly>
    {
    public:
        typedef BaseAssemblyNameMetadata<AssemblyNameMetadataApiHolder> this_type;

        typedef typename AssemblyNameMetadataApiAt<AssemblyNameMetadataApiHolder, Interfaces::AssemblyMetadataLabel>::type assembly_metadata_type;
        typedef typename AssemblyNameMetadataApiAt<AssemblyNameMetadataApiHolder, IMetaDataAssemblyImport>::type metadata_assembly_import_api_type;
        typedef typename AssemblyNameMetadataApiAt<AssemblyNameMetadataApiHolder, StrongNaming::Interfaces::StrongNameInfoLabel>::type strong_name_info_type;
        typedef typename AssemblyNameMetadataApiAt<AssemblyNameMetadataApiHolder, StrongNaming::Interfaces::StrongNameKeyLabel>::type strong_name_key_type;

        BaseAssemblyNameMetadata() : 
            m_pAsmMeta(NULL), 
            m_asmPropsInitialized(false)
        { }

        void Init(assembly_metadata_type &asmMeta, metadata_assembly_import_api_type &metaAsmImpApi) const
        {
            _ASSERTE(m_pAsmMeta == NULL);
            _ASSERTE(m_pMetaAsmImpApi.p == NULL);
            
            m_pAsmMeta = &asmMeta;
            m_pMetaAsmImpApi = &metaAsmImpApi;
        }

        template<class T>
        T const *FindType() const { return static_cast<assembly_metadata_type const *>(m_pAsmMeta)->FindType<T>(); }

        template<class T>
        T *FindType() { return m_pAsmMeta->FindType<T>(); }
      
        template<>
        this_type const *FindType<this_type>() const { return this; }
      
        template<>
        this_type *FindType<this_type>() { return this; }

        std::wstring const &GetName() const
        {
            FillPropertiesIfNecessary();
            return m_name;
        }

        strong_name_key_type const *GetStrongNameKey() const
        {
            FillPropertiesIfNecessary();
            return m_pSnKey.get();
        }

        void FillPropertiesIfNecessary() const
        {
            if (m_asmPropsInitialized)
                return;

            HRESULT hr = E_FAIL;

            std::auto_ptr<WCHAR> name;
            ULONG nameSize = 0;
            ASSEMBLYMETADATA amd;
            ::ZeroMemory(&amd, sizeof(ASSEMBLYMETADATA));
            DWORD asmFlags = 0;
            DWORD asmFlagsTmp = 0;
            hr = m_pMetaAsmImpApi->GetAssemblyProps(GetKey(), NULL, NULL, NULL, NULL, 0, 
                                                    &nameSize, &amd, 
                                                    &asmFlagsTmp);
            if (FAILED(hr))
                BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

            name = std::auto_ptr<WCHAR>(new WCHAR[nameSize]);
            amd.szLocale = amd.cbLocale ? new WCHAR[amd.cbLocale] : NULL;           // TODO: Use ::_malloca instead of new.
            amd.rOS = amd.ulOS ? new OSINFO[amd.ulOS] : NULL;                       // TODO: Use ::_malloca instead of new.
            amd.rProcessor = amd.ulProcessor ? new ULONG[amd.ulProcessor] : NULL;   // TODO: Use ::_malloca instead of new.
            
            void const *pPubKey = NULL;
            DWORD pubKeySize = 0;
            hr = m_pMetaAsmImpApi->GetAssemblyProps(GetKey(), &pPubKey, &pubKeySize, NULL, 
                                                    name.get(), nameSize, NULL, 
                                                    &amd, NULL);
            if (FAILED(hr))
                BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

            m_name = std::wstring(name.get(), nameSize);
            strong_name_info_type const *pSnInfo = FindType<strong_name_info_type>();
            m_pSnKey = pSnInfo->CreateKey(reinterpret_cast<PublicKeyBlob const *>(pPubKey), pubKeySize);

            m_asmPropsInitialized = true;
        }

    private:
        mutable assembly_metadata_type *m_pAsmMeta;
        mutable ATL::CComPtr<IMetaDataAssemblyImport> m_pMetaAsmImpApi;
        mutable bool m_asmPropsInitialized;
        mutable std::wstring m_name;
        mutable boost::shared_ptr<strong_name_key_type const> m_pSnKey;
    };

    typedef BaseAssemblyNameMetadata<> AssemblyNameMetadata;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYNAMEMETADATA_HPP