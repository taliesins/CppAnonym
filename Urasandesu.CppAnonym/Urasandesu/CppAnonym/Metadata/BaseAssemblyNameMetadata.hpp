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

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_MODULENAMEMETADATALABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/ModuleNameMetadataLabel.hpp>
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
        public AssemblyNameMetadataApiAt<AssemblyNameMetadataApiHolder, Interfaces::IAssemblyNameMetadataLabel>::type,
        public SimpleHeapProvider<
            boost::mpl::vector<
                ObjectTag<typename AssemblyNameMetadataApiAt<AssemblyNameMetadataApiHolder, Interfaces::ModuleNameMetadataLabel>::type, QuickHeap>
            >
        >
    {
    public:
        typedef BaseAssemblyNameMetadata<AssemblyNameMetadataApiHolder> this_type;
        typedef typename AssemblyNameMetadataApiAt<AssemblyNameMetadataApiHolder, Interfaces::IAssemblyNameMetadataLabel>::type base_type;

        typedef typename AssemblyNameMetadataApiAt<AssemblyNameMetadataApiHolder, Interfaces::ModuleNameMetadataLabel>::type module_name_metadata_type;
        typedef typename AssemblyNameMetadataApiAt<AssemblyNameMetadataApiHolder, Interfaces::TypeNameMetadataLabel>::type type_name_metadata_type;
        typedef typename AssemblyNameMetadataApiAt<AssemblyNameMetadataApiHolder, Fusion::Interfaces::FusionInfoLabel>::type fusion_info_type;
        typedef typename AssemblyNameMetadataApiAt<AssemblyNameMetadataApiHolder, Interfaces::AssemblyMetadataLabel>::type assembly_metadata_type;
        typedef typename AssemblyNameMetadataApiAt<AssemblyNameMetadataApiHolder, IMetaDataAssemblyImport>::type com_meta_data_assembly_import_type;
        typedef typename AssemblyNameMetadataApiAt<AssemblyNameMetadataApiHolder, StrongNaming::Interfaces::StrongNameInfoLabel>::type strong_name_info_type;

        typedef ObjectTag<module_name_metadata_type, QuickHeap> module_name_metadata_obj_tag_type;
        typedef typename type_decided_by<module_name_metadata_obj_tag_type>::type module_name_metadata_heap_type;

        BaseAssemblyNameMetadata() : 
            m_nameInitialized(false),
            m_dispAsScopeInitialized(false),
            m_tokenInitialized(false),
            m_pDispAsScope(NULL), 
            m_pResolvedAsm(NULL),
            m_filled(false),
            m_pSnKey(NULL)
        { }

        void Init(typename base_type::metadata_dispenser_type &dispAsScope) const
        {
            _ASSERTE(m_pDispAsScope == NULL);
            m_pDispAsScope = &dispAsScope;
        }

        template<class T>
        T const &Map() const { return const_cast<this_type *>(this)->Map<T>(); }

        template<class T>
        T &Map() { _ASSERTE(m_pDispAsScope != NULL); return m_pDispAsScope->Map<T>(); }
      
        template<>
        this_type const &Map<this_type>() const { return const_cast<this_type *>(this)->Map<this_type>(); }
      
        template<>
        this_type &Map<this_type>() { return *this; }

        std::wstring const &GetName() const
        {
            if (!m_nameInitialized)
            {
                FillPropertiesIfNecessary();
                m_nameInitialized = true;
            }
            return m_name;
        }

        typename base_type::strong_name_key_type const *GetStrongNameKey() const
        {
            FillPropertiesIfNecessary();
            return m_pSnKey;
        }

        typename base_type::metadata_dispenser_type const &GetResolutionScope() const
        {
            return Map<metadata_dispenser_type>();
        }

        typename base_type::i_assembly_metadata_type const &Resolve() const
        {
            return ResolveCore();
        }

        module_name_metadata_type *NewModuleName(std::wstring const &name) const
        {
            this_type *pMutableThis = const_cast<this_type *>(this);

            module_name_metadata_type *pModNameMeta = NULL;
            pModNameMeta = pMutableThis->ModuleNameMetadataHeap().New();
            pModNameMeta->Init(*pMutableThis);
            pModNameMeta->SetName(name);
            return pModNameMeta;
        }

    private:
        friend typename base_type::metadata_dispenser_type;
        friend typename assembly_metadata_type;
        friend typename module_name_metadata_type;
        friend typename type_name_metadata_type;

        module_name_metadata_heap_type &ModuleNameMetadataHeap()
        {
            return Of<module_name_metadata_obj_tag_type>();
        }
        
        module_name_metadata_heap_type const &ModuleNameMetadataHeap() const
        {
            return Of<module_name_metadata_obj_tag_type>();
        }

        void SetName(std::wstring const &name)
        {
            _ASSERTE(!m_nameInitialized);
            m_name = name;
            m_nameInitialized = true;
        }

        mdAssembly GetToken() const
        {
            _ASSERTE(m_tokenInitialized);
            return m_mda;
        }

        void SetToken(mdAssembly mda)
        {
            _ASSERTE(!m_tokenInitialized);
            m_mda = mda;
            m_tokenInitialized = true;
        }

        assembly_metadata_type const &ResolveCore() const
        {
            this_type *pMutableThis = const_cast<this_type *>(this);
            return pMutableThis->ResolveCore();
        }
        
        assembly_metadata_type &ResolveCore()
        {
            using namespace boost;
            using namespace Urasandesu::CppAnonym::Fusion;

            if (m_pResolvedAsm == NULL)
            {
                fusion_info_type const &fuInfo = Map<fusion_info_type>();
                shared_ptr<AssemblyInfo> pAsmInfo = fuInfo.QueryAssemblyInfo(AssemblyQueryTypes::AQT_DEFAULT, GetName());

                assembly_metadata_type const *pAsmMeta = NULL;
                pAsmMeta = Map<metadata_dispenser_type>().LoadAssemblyFromFile(pAsmInfo->GetAssemblyPath());
                m_pResolvedAsm = const_cast<assembly_metadata_type *>(pAsmMeta);
            }

            return *m_pResolvedAsm;
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

        void FillPropertiesIfNecessary() const
        {
            if (m_filled)
                return;
            
            this_type *pMutableThis = const_cast<this_type *>(this);
            assembly_metadata_type &resolvedAsm = pMutableThis->ResolveCore();
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
            strong_name_info_type const &snInfo = Map<strong_name_info_type>();
            m_pSnKey = snInfo.GetStrongNameKey(*reinterpret_cast<PublicKeyBlob const *>(pPubKey), pubKeySize);

            m_filled = true;
        }

        mutable bool m_nameInitialized;
        mutable bool m_dispAsScopeInitialized;
        mutable bool m_tokenInitialized;
        mutable typename base_type::metadata_dispenser_type *m_pDispAsScope;
        mutable assembly_metadata_type *m_pResolvedAsm;
        mutable mdAssembly m_mda;
        mutable bool m_filled;
        mutable std::wstring m_name;
        mutable typename base_type::strong_name_key_type const *m_pSnKey;
    };

    
    
    
    
    //template<
    //    class AssemblyNameMetadataApiHolder
    //>    
    //class BaseAssemblyNameMetadataHash : 
    //    Traits::HashComputable<BaseAssemblyNameMetadata<AssemblyNameMetadataApiHolder> const *>
    //{
    //public:
    //    typedef typename AssemblyNameMetadataApiAt<AssemblyNameMetadataApiHolder, Interfaces::MetadataDispenserLabel>::type metadata_dispenser_type;

    //    result_type operator()(param_type v) const
    //    {
    //        using namespace boost;
    //        using namespace Urasandesu::CppAnonym::Collections;
    //        using namespace Urasandesu::CppAnonym::Utilities;

    //        _ASSERTE(v != NULL);

    //        std::size_t seed = 0;
    //        hash_combine(seed, hash_value(v->GetName()));
    //        hash_combine(seed, HashValue(&v->Map<metadata_dispenser_type>()));
    //        return seed;
    //    }
    //};

    //
    //
    //
    //
    //template<
    //    class AssemblyNameMetadataApiHolder
    //>    
    //class BaseAssemblyNameMetadataEqualTo : 
    //    Traits::EqualityComparable<BaseAssemblyNameMetadata<AssemblyNameMetadataApiHolder> const *>
    //{
    //public:
    //    typedef typename AssemblyNameMetadataApiAt<AssemblyNameMetadataApiHolder, Interfaces::MetadataDispenserLabel>::type metadata_dispenser_type;
    //    
    //    result_type operator()(param_type x, param_type y) const
    //    {
    //        _ASSERTE(x != NULL && y != NULL);

    //        return x->GetName() == y->GetName() &&
    //               &x->Map<metadata_dispenser_type>() == &y->Map<metadata_dispenser_type>();
    //    }
    //};

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYNAMEMETADATA_HPP