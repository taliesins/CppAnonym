#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYNAMEMETADATA_HPP
#define URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYNAMEMETADATA_HPP

//#ifndef URASANDESU_CPPANONYM_IHEAPCONTENT_H
//#include <Urasandesu/CppAnonym/IHeapContent.h>
//#endif

#ifndef URASANDESU_CPPANONYM_SIMPLEHEAPPROVIDERFWD_HPP
#include <Urasandesu/CppAnonym/SimpleHeapProviderFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_OBJECTTAGFWD_HPP
#include <Urasandesu/CppAnonym/ObjectTagFwd.hpp>
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
        public SimpleHeapProvider<
            boost::mpl::vector<
                ObjectTag<typename AssemblyNameMetadataApiAt<AssemblyNameMetadataApiHolder, Interfaces::TypeNameMetadataLabel>::type, QuickHeap>
            >
        >
    {
    public:
        typedef BaseAssemblyNameMetadata<AssemblyNameMetadataApiHolder> this_type;

        typedef typename AssemblyNameMetadataApiAt<AssemblyNameMetadataApiHolder, Interfaces::MetadataDispenserLabel>::type metadata_dispenser_type;
        typedef typename AssemblyNameMetadataApiAt<AssemblyNameMetadataApiHolder, Interfaces::TypeNameMetadataLabel>::type type_name_metadata_type;
        typedef typename AssemblyNameMetadataApiAt<AssemblyNameMetadataApiHolder, Fusion::Interfaces::FusionInfoLabel>::type fusion_info_type;
        typedef typename AssemblyNameMetadataApiAt<AssemblyNameMetadataApiHolder, Interfaces::AssemblyMetadataLabel>::type assembly_metadata_type;
        typedef typename AssemblyNameMetadataApiAt<AssemblyNameMetadataApiHolder, IMetaDataAssemblyImport>::type metadata_assembly_import_api_type;
        typedef typename AssemblyNameMetadataApiAt<AssemblyNameMetadataApiHolder, StrongNaming::Interfaces::StrongNameInfoLabel>::type strong_name_info_type;
        typedef typename AssemblyNameMetadataApiAt<AssemblyNameMetadataApiHolder, StrongNaming::Interfaces::StrongNameKeyLabel>::type strong_name_key_type;

        typedef ObjectTag<type_name_metadata_type, QuickHeap> type_name_metadata_obj_tag_type;
        typedef typename type_decided_by<type_name_metadata_obj_tag_type>::type type_name_metadata_heap_type;

        BaseAssemblyNameMetadata() : 
            m_pDispAsScope(NULL), 
            m_pAsmResolved(NULL),
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

        //template<class T>
        //T const *FindType() const { return static_cast<assembly_metadata_type const *>(m_pAsmMeta)->FindType<T>(); }
        template<class T>
        T const *FindType() const { return GetResolutionScope().FindType<T>(); }

        //template<class T>
        //T *FindType() { return m_pAsmMeta->FindType<T>(); }
        template<class T>
        T *FindType() { return const_cast<metadata_dispenser_type &>(GetResolutionScope()).FindType<T>(); }
      
        template<>
        this_type const *FindType<this_type>() const { return this; }
      
        template<>
        this_type *FindType<this_type>() { return this; }

        std::wstring const &GetName() const
        {
            // This method implementation is temporary.
            if (m_name.empty())
            {
                m_name = L"mscorlib, Version=2.0.0.0, Culture=neutral, " 
                         L"PublicKeyToken=b77a5c561934e089, processorArchitecture=x86";
            }
            return m_name;
            //FillPropertiesIfNecessary();
            //return m_name;
        }

        void SetName(std::wstring const &name)
        {
            // Should be immutable...
            m_name = name;
        }

        metadata_dispenser_type const &GetResolutionScope() const
        {
            _ASSERTE(m_pDispAsScope != NULL);
            return *m_pDispAsScope;
        }

        void SetResolutionScope(metadata_dispenser_type &metaDispAsScope)
        {
            m_pDispAsScope = &metaDispAsScope;
        }

        type_name_metadata_type *NewTypeName(std::wstring const &name, TypeKinds const &kind) const
        {
            this_type *mutableThis = const_cast<this_type *>(this);

            type_name_metadata_type *pTypeNameMeta = NULL;
            pTypeNameMeta = mutableThis->TypeNameMetadataHeap().New();
            pTypeNameMeta->SetName(name);
            pTypeNameMeta->SetKind(kind);
            pTypeNameMeta->SetResolutionScope(*mutableThis);
            return pTypeNameMeta;
        }
        
        assembly_metadata_type const *Resolve() const
        {
            using namespace boost;
            using namespace Urasandesu::CppAnonym::Fusion;

            if (m_pAsmResolved == NULL)
            {
                fusion_info_type const *pFuInfo = FindType<fusion_info_type>();
                shared_ptr<AssemblyInfo> pAsmInfo = pFuInfo->QueryAssemblyInfo(AssemblyQueryTypes::AQT_DEFAULT, GetName());

                m_pAsmResolved = GetResolutionScope().LoadAssemblyFromFile(pAsmInfo->GetAssemblyPath());
            }

            return m_pAsmResolved;
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

            //HRESULT hr = E_FAIL;

            //std::auto_ptr<WCHAR> name;
            //ULONG nameSize = 0;
            //ASSEMBLYMETADATA amd;
            //::ZeroMemory(&amd, sizeof(ASSEMBLYMETADATA));
            //DWORD asmFlags = 0;
            //DWORD asmFlagsTmp = 0;
            //hr = m_pMetaAsmImpApi->GetAssemblyProps(GetKey(), NULL, NULL, NULL, NULL, 0, 
            //                                        &nameSize, &amd, 
            //                                        &asmFlagsTmp);
            //if (FAILED(hr))
            //    BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

            //name = std::auto_ptr<WCHAR>(new WCHAR[nameSize]);
            //amd.szLocale = amd.cbLocale ? new WCHAR[amd.cbLocale] : NULL;           // TODO: Use ::_malloca instead of new.
            //amd.rOS = amd.ulOS ? new OSINFO[amd.ulOS] : NULL;                       // TODO: Use ::_malloca instead of new.
            //amd.rProcessor = amd.ulProcessor ? new ULONG[amd.ulProcessor] : NULL;   // TODO: Use ::_malloca instead of new.
            //
            //void const *pPubKey = NULL;
            //DWORD pubKeySize = 0;
            //hr = m_pMetaAsmImpApi->GetAssemblyProps(GetKey(), &pPubKey, &pubKeySize, NULL, 
            //                                        name.get(), nameSize, NULL, 
            //                                        &amd, NULL);
            //if (FAILED(hr))
            //    BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

            //m_name = std::wstring(name.get(), nameSize);
            //strong_name_info_type const *pSnInfo = FindType<strong_name_info_type>();
            //m_pSnKey = pSnInfo->CreateKey(reinterpret_cast<PublicKeyBlob const *>(pPubKey), pubKeySize);

            //m_asmPropsInitialized = true;
        }

    private:
        template<
            class AssemblyMetadataApiHolder
        >
        friend class BaseAssemblyMetadata;

        type_name_metadata_heap_type &TypeNameMetadataHeap()
        {
            return Of<type_name_metadata_obj_tag_type>();
        }
        
        type_name_metadata_heap_type const &TypeNameMetadataHeap() const
        {
            return Of<type_name_metadata_obj_tag_type>();
        }

        void SetToken(mdAssembly mda)
        {
            m_mda = mda;
        }

        metadata_dispenser_type *m_pDispAsScope;
        mutable assembly_metadata_type const *m_pAsmResolved;
        mdAssembly m_mda;

        mutable assembly_metadata_type *m_pAsmMeta;
        mutable ATL::CComPtr<IMetaDataAssemblyImport> m_pMetaAsmImpApi;
        mutable bool m_asmPropsInitialized;
        mutable std::wstring m_name;
        mutable boost::shared_ptr<strong_name_key_type const> m_pSnKey;
    };

    typedef BaseAssemblyNameMetadata<> AssemblyNameMetadata;

    template<
        class AssemblyNameMetadataApiHolder = ApiHolders::DefaultAssemblyNameMetadataApiHolder
    >    
    struct BaseAssemblyNameMetadataEqualTo;

    typedef BaseAssemblyNameMetadataEqualTo<> AssemblyNameMetadataEqualTo;

    template<
        class AssemblyNameMetadataApiHolder = ApiHolders::DefaultAssemblyNameMetadataApiHolder
    >    
    struct BaseAssemblyNameMetadataHash;

    typedef BaseAssemblyNameMetadataHash<> AssemblyNameMetadataHash;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYNAMEMETADATA_HPP