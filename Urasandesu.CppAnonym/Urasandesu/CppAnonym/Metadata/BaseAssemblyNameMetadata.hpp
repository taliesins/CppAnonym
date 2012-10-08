#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYNAMEMETADATA_HPP
#define URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYNAMEMETADATA_HPP

#ifndef URASANDESU_CPPANONYM_SIMPLEHEAPPROVIDER_HPP
#include <Urasandesu/CppAnonym/SimpleHeapProvider.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_OBJECTTAG_HPP
#include <Urasandesu/CppAnonym/ObjectTag.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_CARTRIDGEAPISYSTEM_HPP
#include <Urasandesu/CppAnonym/Traits/CartridgeApiSystem.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_STACKALLOCATOR_HPP
#include <Urasandesu/CppAnonym/Utilities/StackAllocator.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_INTERFACES_STRONGNAMEINFOLABEL_HPP
#include <Urasandesu/CppAnonym/StrongNaming/Interfaces/StrongNameInfoLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_INTERFACES_STRONGNAMEKEYLABEL_HPP
#include <Urasandesu/CppAnonym/StrongNaming/Interfaces/StrongNameKeyLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_ASSEMBLYMETADATALABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/AssemblyMetadataLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_ASSEMBLYNAMEMETADATAAPIHOLDERLABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/AssemblyNameMetadataApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_FUSION_ASSEMBLYINFO_H
#include <Urasandesu/CppAnonym/Fusion/AssemblyInfo.h>
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
        typedef typename AssemblyNameMetadataApiAt<AssemblyNameMetadataApiHolder, IMetaDataAssemblyImport>::type com_meta_data_assembly_import_type;
        typedef typename AssemblyNameMetadataApiAt<AssemblyNameMetadataApiHolder, StrongNaming::Interfaces::StrongNameInfoLabel>::type strong_name_info_type;
        typedef typename AssemblyNameMetadataApiAt<AssemblyNameMetadataApiHolder, StrongNaming::Interfaces::StrongNameKeyLabel>::type strong_name_key_type;

        typedef ObjectTag<type_name_metadata_type, QuickHeap> type_name_metadata_obj_tag_type;
        typedef typename type_decided_by<type_name_metadata_obj_tag_type>::type type_name_metadata_heap_type;

        BaseAssemblyNameMetadata() : 
            m_nameInitialized(false),
            m_pDispAsScope(NULL), 
            m_pResolvedAsm(NULL),
            m_asmPropsInitialized(false)
        { }

        template<class T>
        T const *FindType() const { return GetResolutionScope().FindType<T>(); }

        template<class T>
        T *FindType() { return const_cast<metadata_dispenser_type &>(GetResolutionScope()).FindType<T>(); }
      
        template<>
        this_type const *FindType<this_type>() const { return this; }
      
        template<>
        this_type *FindType<this_type>() { return this; }

        std::wstring const &GetName() const
        {
            if (!m_nameInitialized)
            {
                FillPropertiesIfNecessary();
                m_nameInitialized = true;
            }
            return m_name;
        }

        void SetName(std::wstring const &name)
        {
            _ASSERTE(!m_nameInitialized);
            m_name = name;
            m_nameInitialized = true;
        }

        mdAssembly GetToken() const
        {
            return m_mda;
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
            pTypeNameMeta->Init(name, kind, *mutableThis);
            //pTypeNameMeta->SetName(name);
            //pTypeNameMeta->SetKind(kind);
            //pTypeNameMeta->SetResolutionScope(*mutableThis);
            return pTypeNameMeta;
        }
        
        assembly_metadata_type const *Resolve() const
        {
            using namespace boost;
            using namespace Urasandesu::CppAnonym::Fusion;

            if (m_pResolvedAsm == NULL)
            {
                fusion_info_type const *pFuInfo = FindType<fusion_info_type>();
                shared_ptr<AssemblyInfo> pAsmInfo = pFuInfo->QueryAssemblyInfo(AssemblyQueryTypes::AQT_DEFAULT, GetName());

                assembly_metadata_type const *pAsmMeta = NULL;
                pAsmMeta = GetResolutionScope().LoadAssemblyFromFile(pAsmInfo->GetAssemblyPath());
                m_pResolvedAsm = const_cast<assembly_metadata_type *>(pAsmMeta);
            }

            return m_pResolvedAsm;
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
            
            this_type *mutableThis = const_cast<this_type *>(this);
            assembly_metadata_type &resolvedAsm = mutableThis->GetResolvedAssembly();
            com_meta_data_assembly_import_type &comMetaAsmImp = resolvedAsm.GetCOMMetaDataAssemblyImport();
            
            HRESULT hr = E_FAIL;

            ULONG nameSize = 0;
            ASSEMBLYMETADATA amd;
            ::ZeroMemory(&amd, sizeof(ASSEMBLYMETADATA));
            DWORD asmFlags = 0;
            DWORD asmFlagsTmp = 0;
            hr = comMetaAsmImp.GetAssemblyProps(GetToken(), NULL, NULL, NULL, NULL, 0, 
                                                &nameSize, &amd, 
                                                &asmFlagsTmp);
            if (FAILED(hr))
                BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

            
            
            typedef std::vector<WCHAR, Utilities::StackAllocator<WCHAR> > WCharVector;
            typedef std::vector<OSINFO, Utilities::StackAllocator<OSINFO> > OSInfoVector;
            typedef std::vector<ULONG, Utilities::StackAllocator<ULONG> > ULongVector;
            WCharVector name(nameSize);
            WCharVector locale;
            if (amd.cbLocale)
            {
                locale.resize(amd.cbLocale);
                amd.szLocale = &locale[0];
            }
            OSInfoVector os;
            if (amd.ulOS)
            {
                os.resize(amd.ulOS);
                amd.rOS = &os[0];
            }
            ULongVector processor;
            if (amd.ulProcessor)
            {
                processor.resize(amd.ulProcessor);
                amd.rProcessor = &processor[0];
            }

            void const *pPubKey = NULL;
            DWORD pubKeySize = 0;
            hr = comMetaAsmImp.GetAssemblyProps(GetToken(), &pPubKey, &pubKeySize, NULL, 
                                                &name[0], nameSize, NULL, 
                                                &amd, NULL);
            if (FAILED(hr))
                BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

            m_name = std::wstring(&name[0], nameSize);
            strong_name_info_type const *pSnInfo = FindType<strong_name_info_type>();
            m_pSnKey = pSnInfo->CreateKey(reinterpret_cast<PublicKeyBlob const *>(pPubKey), pubKeySize);

            m_asmPropsInitialized = true;
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

        assembly_metadata_type &GetResolvedAssembly()
        {
            _ASSERTE(m_pResolvedAsm != NULL);
            return *m_pResolvedAsm;
        }

        void SetResolvedAssembly(assembly_metadata_type &resolvedAsm)
        {
            _ASSERTE(m_pResolvedAsm == NULL);
            m_pResolvedAsm = &resolvedAsm;
        }

        metadata_dispenser_type *m_pDispAsScope;
        mutable assembly_metadata_type *m_pResolvedAsm;
        mdAssembly m_mda;

        //mutable assembly_metadata_type *m_pAsmMeta;
        //mutable ATL::CComPtr<IMetaDataAssemblyImport> m_pMetaAsmImpApi;
        mutable bool m_asmPropsInitialized;
        mutable std::wstring m_name;
        mutable bool m_nameInitialized;
        mutable boost::shared_ptr<strong_name_key_type const> m_pSnKey;
    };

    
    
    
    
    template<
        class AssemblyNameMetadataApiHolder
    >    
    class BaseAssemblyNameMetadataHash : 
        Traits::HashComputable<BaseAssemblyNameMetadata<AssemblyNameMetadataApiHolder> const *>
    {
    public:
        result_type operator()(param_type v) const
        {
            using namespace boost;
            using namespace Urasandesu::CppAnonym::Collections;
            using namespace Urasandesu::CppAnonym::Utilities;

            _ASSERTE(v != NULL);

            std::size_t seed = 0;
            hash_combine(seed, hash_value(v->GetName()));
            hash_combine(seed, HashValue(&v->GetResolutionScope()));
            return seed;
        }
    };

    
    
    
    
    template<
        class AssemblyNameMetadataApiHolder
    >    
    class BaseAssemblyNameMetadataEqualTo : 
        Traits::EqualityComparable<BaseAssemblyNameMetadata<AssemblyNameMetadataApiHolder> const *>
    {
    public:
        result_type operator()(param_type x, param_type y) const
        {
            _ASSERTE(x != NULL && y != NULL);

            return x->GetName() == y->GetName() &&
                   &x->GetResolutionScope() == &y->GetResolutionScope();
        }
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYNAMEMETADATA_HPP