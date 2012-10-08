#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYMETADATA_HPP
#define URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYMETADATA_HPP

#ifndef URASANDESU_CPPANONYM_TRAITS_CARTRIDGEAPISYSTEM_HPP
#include <Urasandesu/CppAnonym/Traits/CartridgeApiSystem.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_HASMEMBERTYPE_HPP
#include <Urasandesu/CppAnonym/Traits/HasMemberType.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_GETMEMBERTYPE_HPP
#include <Urasandesu/CppAnonym/Traits/GetMemberType.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_MODULEMETADATALABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/ModuleMetadataLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_MODULENAMEMETADATALABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/ModuleNameMetadataLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_INTERFACES_STRONGNAMEINFOAPIHOLDERLABEL_HPP
#include <Urasandesu/CppAnonym/StrongNaming/Interfaces/StrongNameInfoApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_INTERFACES_STRONGNAMEINFOLABEL_HPP
#include <Urasandesu/CppAnonym/StrongNaming/Interfaces/StrongNameInfoLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_INTERFACES_STRONGNAMEKEYAPIHOLDERLABEL_HPP
#include <Urasandesu/CppAnonym/StrongNaming/Interfaces/StrongNameKeyApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_INTERFACES_STRONGNAMEKEYLABEL_HPP
#include <Urasandesu/CppAnonym/StrongNaming/Interfaces/StrongNameKeyLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_METADATADISPENSERLABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/MetadataDispenserLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_ASSEMBLYMETADATALABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/AssemblyMetadataLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_ASSEMBLYMETADATAAPIHOLDERLABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/AssemblyMetadataApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_TYPEMETADATALABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/TypeMetadataLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_ASSEMBLYNAMEMETADATALABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/AssemblyNameMetadataLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_TYPENAMEMETADATALABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/TypeNameMetadataLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_MODULEMETADATALABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/ModuleMetadataLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_TYPEKINDS_H
#include <Urasandesu/CppAnonym/Metadata/TypeKinds.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYMETADATAFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseAssemblyMetadataFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    template<class ApiCartridgesHolder, class ApiLabel>
    struct AssemblyMetadataApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::AssemblyMetadataApiHolderLabel, ApiLabel>
    {
    };

    template<
        class AssemblyMetadataApiHolder
    >    
    class BaseAssemblyMetadata :
        public AssemblyMetadataApiAt<AssemblyMetadataApiHolder, Interfaces::IAssemblyMetadataLabel>::type,
        public SimpleHeapProvider<
            boost::mpl::vector<
                ObjectTag<typename AssemblyMetadataApiAt<AssemblyMetadataApiHolder, Interfaces::ModuleMetadataLabel>::type, QuickHeap>
            >
        >
    {
    public:
        typedef BaseAssemblyMetadata<AssemblyMetadataApiHolder> this_type;
        typedef typename AssemblyMetadataApiAt<AssemblyMetadataApiHolder, Interfaces::IAssemblyMetadataLabel>::type base_type;
        
        typedef typename AssemblyMetadataApiAt<AssemblyMetadataApiHolder, Interfaces::MetadataDispenserLabel>::type metadata_dispenser_type;
        typedef typename AssemblyMetadataApiAt<AssemblyMetadataApiHolder, Interfaces::AssemblyNameMetadataLabel>::type assembly_name_metadata_type;
        typedef typename AssemblyMetadataApiAt<AssemblyMetadataApiHolder, Interfaces::ModuleMetadataLabel>::type module_metadata_type;
        typedef typename AssemblyMetadataApiAt<AssemblyMetadataApiHolder, Interfaces::ModuleNameMetadataLabel>::type module_name_metadata_type;
        typedef typename AssemblyMetadataApiAt<AssemblyMetadataApiHolder, Interfaces::TypeMetadataLabel>::type type_metadata_type;
        typedef typename AssemblyMetadataApiAt<AssemblyMetadataApiHolder, Interfaces::TypeNameMetadataLabel>::type type_name_metadata_type;
        typedef typename AssemblyMetadataApiAt<AssemblyMetadataApiHolder, Interfaces::MethodMetadataLabel>::type methoe_metadata_type;
        typedef typename AssemblyMetadataApiAt<AssemblyMetadataApiHolder, IMetaDataDispenserEx>::type com_meta_data_dispenser_type;
        typedef typename AssemblyMetadataApiAt<AssemblyMetadataApiHolder, IMetaDataAssemblyImport>::type com_meta_data_assembly_import_type;
        typedef typename AssemblyMetadataApiAt<AssemblyMetadataApiHolder, IMetaDataImport2>::type com_meta_data_import_type;

        typedef ObjectTag<module_metadata_type, QuickHeap> module_metadata_obj_tag_type;
        typedef typename type_decided_by<module_metadata_obj_tag_type>::type module_metadata_heap_type;

        CPP_ANONYM_DECLARE_HAS_MEMBER_TYPE(AsmNameMeta, module_name_metadata_heap_type);
        CPP_ANONYM_DECLARE_GET_MEMBER_TYPE(AsmNameMeta, module_name_metadata_heap_type);
        typedef typename boost::mpl::eval_if<
            CPP_ANONYM_HAS_MEMBER_TYPE(AsmNameMeta, module_name_metadata_heap_type, assembly_name_metadata_type), 
            CPP_ANONYM_GET_MEMBER_TYPE(AsmNameMeta, module_name_metadata_heap_type, assembly_name_metadata_type), 
            boost::mpl::void_
        >::type module_name_metadata_heap_type;

        BaseAssemblyMetadata() : 
            m_mda(mdAssemblyNil),
            m_pMetaDisp(NULL), 
            m_pAsmNameMeta(NULL), 
            m_openFlags(ofRead)
        { }

        void Init(metadata_dispenser_type &metaDisp) const
        {
            _ASSERTE(m_pMetaDisp == NULL);
            m_pMetaDisp = &metaDisp;
        }

        template<class T>
        T const &Map() const { return const_cast<this_type *>(this)->Map<T>(); }

        template<class T>
        T &Map() { _ASSERTE(m_pMetaDisp != NULL); return m_pMetaDisp->Map<T>(); }
      
        template<>
        this_type const &Map<this_type>() const { return *this; }
      
        template<>
        this_type &Map<this_type>() { return *this; }

        mdAssembly GetToken() const
        {
            if (m_mda == mdAssemblyNil)
            {
                this_type *pMutableThis = const_cast<this_type *>(this);
                com_meta_data_assembly_import_type &comMetaAsmImp = pMutableThis->GetCOMMetaDataAssemblyImport();
                mdAssembly mda = mdAssemblyNil;
                HRESULT hr = comMetaAsmImp.GetAssemblyFromScope(&mda);
                if (FAILED(hr))
                    BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

                m_mda = mda;
            }

            return m_mda;
        }

        typename base_type::i_assembly_name_metadata_type const &GetAssemblyName() const
        {
            return GetAssemblyNameCore();
        }

        module_name_metadata_type *NewModuleName(std::wstring const &name) const
        {
            return GetAssemblyNameCore().NewModuleName(name);
        }

        module_metadata_type const *GetModule(std::wstring const &name) const
        {
            return GetModuleCore(name);
        }

    private:
        friend typename module_name_metadata_type;
        friend typename module_metadata_type;
        friend typename type_name_metadata_type;
        friend typename type_metadata_type;
        friend typename metadata_dispenser_type;
        friend typename assembly_name_metadata_type;
        friend typename methoe_metadata_type;

        module_metadata_heap_type &ModuleMetadataHeap()
        {
            return Of<module_metadata_obj_tag_type>();
        }
        
        module_metadata_heap_type const &ModuleMetadataHeap() const
        {
            return Of<module_metadata_obj_tag_type>();
        }

        module_name_metadata_heap_type &ModuleNameMetadataHeap()
        {
            return GetAssemblyNameCore().ModuleNameMetadataHeap();
        }
        
        module_name_metadata_heap_type const &ModuleNameMetadataHeap() const
        {
            return GetAssemblyNameCore().ModuleNameMetadataHeap();
        }

        com_meta_data_assembly_import_type &GetCOMMetaDataAssemblyImport()
        {
            if (m_pComMetaAsmImp.p == NULL)
            {
                this_type *pMutableThis = const_cast<this_type *>(this);
                
                com_meta_data_import_type &comMetaImp = pMutableThis->GetCOMMetaDataImport();
                HRESULT hr = comMetaImp.QueryInterface(IID_IMetaDataAssemblyImport, 
                                               reinterpret_cast<void **>(&m_pComMetaAsmImp));
                if (FAILED(hr))
                    BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
            }
            return *m_pComMetaAsmImp;
        }

        com_meta_data_import_type &GetCOMMetaDataImport()
        {
            namespace fs = boost::filesystem;

            if (m_pComMetaImp.p == NULL)
            {
                this_type *pMutableThis = const_cast<this_type *>(this);

                metadata_dispenser_type &metaDisp = pMutableThis->Map<metadata_dispenser_type>();

                com_meta_data_dispenser_type &comMetaDisp = metaDisp.GetCOMMetaDataDispenser();

                fs::path const &asmPath = GetAssemblyFilePath();
                DWORD openFlags = GetOpenFlags();
                REFIID riid = GetCOMMetaDataImportIID();
                HRESULT hr = comMetaDisp.OpenScope(asmPath.c_str(), openFlags, 
                                                   riid, reinterpret_cast<IUnknown **>(&m_pComMetaImp));
                if (FAILED(hr))
                    BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
            }
            return *m_pComMetaImp.p;
        }

        boost::filesystem::path const &GetAssemblyFilePath() const
        {
            return m_asmPath;
        }

        void SetAssemblyFilePath(boost::filesystem::path const &asmPath)
        {
            _ASSERTE(!asmPath.empty());
            _ASSERTE(m_asmPath.empty());
            
            m_asmPath = asmPath;
        }

        DWORD GetOpenFlags() const
        {
            return m_openFlags;
        }

        void SetOpenFlags(DWORD openFlags)
        {
            _ASSERTE(openFlags != ofRead);
            _ASSERTE(m_openFlags == ofRead);

            m_openFlags = openFlags;
        }

        REFIID GetCOMMetaDataImportIID()
        {
            return IID_IMetaDataImport2;
        }

        module_metadata_type const *GetModuleCore(std::wstring const &name) const
        {
            this_type *pMutableThis = const_cast<this_type *>(this);
            return pMutableThis->GetModuleCore(name);
        }

        module_metadata_type *GetModuleCore(std::wstring const &name)
        {
            if (m_modStrNameToIndex.find(name) == m_modStrNameToIndex.end())
            {
                m_modStrNameToIndex[name] = MAXULONG_PTR;
            }

            SIZE_T index = m_modStrNameToIndex[name];
            if (index == MAXULONG_PTR)
            {
                module_name_metadata_type *pModNameMeta = NULL;
                pModNameMeta = NewModuleName(name);

                module_metadata_type &modMeta = pModNameMeta->ResolveCore();
                m_modStrNameToIndex[name] = ModuleMetadataHeap().Size() - 1;

                return &modMeta;
            }
            else
            {
                return ModuleMetadataHeap()[index];
            }
        }

        assembly_name_metadata_type const &GetAssemblyNameCore() const
        {
            this_type *pMutableThis = const_cast<this_type *>(this);
            return pMutableThis->GetAssemblyNameCore();
        }

        assembly_name_metadata_type &GetAssemblyNameCore()
        {
            if (m_pAsmNameMeta == NULL)
            {
                metadata_dispenser_type &metaDisp = Map<metadata_dispenser_type>();

                m_pAsmNameMeta = metaDisp.AssemblyNameMetadataHeap().New();
                m_pAsmNameMeta->Init(metaDisp);
                m_pAsmNameMeta->SetToken(GetToken());
                m_pAsmNameMeta->SetResolvedAssembly(*this);
            }
            return *m_pAsmNameMeta;
        }

        mutable mdAssembly m_mda;

        boost::filesystem::path m_asmPath;
        DWORD m_openFlags;

        mutable metadata_dispenser_type *m_pMetaDisp;
        mutable assembly_name_metadata_type *m_pAsmNameMeta;
        mutable ATL::CComPtr<com_meta_data_import_type> m_pComMetaImp;
        mutable ATL::CComPtr<com_meta_data_assembly_import_type> m_pComMetaAsmImp;
        mutable boost::unordered_map<std::wstring, SIZE_T> m_modStrNameToIndex;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYMETADATA_HPP