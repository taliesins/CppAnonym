#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_BASEMODULENAMEMETADATA_HPP
#define URASANDESU_CPPANONYM_METADATA_BASEMODULENAMEMETADATA_HPP

#ifndef URASANDESU_CPPANONYM_TRAITS_CARTRIDGEAPISYSTEM_HPP
#include <Urasandesu/CppAnonym/Traits/CartridgeApiSystem.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_SIMPLEHEAPPROVIDER_HPP
#include <Urasandesu/CppAnonym/SimpleHeapProvider.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_OBJECTTAG_HPP
#include <Urasandesu/CppAnonym/ObjectTag.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_MODULENAMEMETADATAAPIHOLDERLABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/ModuleNameMetadataApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMODULENAMEMETADATAFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseModuleNameMetadataFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    template<class ApiCartridgesHolder, class ApiLabel>
    struct ModuleNameMetadataApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::ModuleNameMetadataApiHolderLabel, ApiLabel>
    {
    };

    template<
        class ModuleNameMetadataApiHolder
    >    
    class BaseModuleNameMetadata :
        public ModuleNameMetadataApiAt<ModuleNameMetadataApiHolder, Interfaces::IModuleNameMetadataLabel>::type,
        public SimpleHeapProvider<
            boost::mpl::vector<
                ObjectTag<typename ModuleNameMetadataApiAt<ModuleNameMetadataApiHolder, Interfaces::TypeNameMetadataLabel>::type, QuickHeap>
            >
        >
    {
    public:
        typedef BaseModuleNameMetadata<ModuleNameMetadataApiHolder> this_type;
        typedef typename ModuleNameMetadataApiAt<ModuleNameMetadataApiHolder, Interfaces::IModuleNameMetadataLabel>::type base_type;

        typedef typename ModuleNameMetadataApiAt<ModuleNameMetadataApiHolder, Interfaces::AssemblyMetadataLabel>::type assembly_metadata_type;
        typedef typename ModuleNameMetadataApiAt<ModuleNameMetadataApiHolder, Interfaces::AssemblyNameMetadataLabel>::type assembly_name_metadata_type;
        typedef typename ModuleNameMetadataApiAt<ModuleNameMetadataApiHolder, Interfaces::ModuleMetadataLabel>::type module_metadata_type;
        typedef typename ModuleNameMetadataApiAt<ModuleNameMetadataApiHolder, Interfaces::TypeNameMetadataLabel>::type type_name_metadata_type;
        typedef typename ModuleNameMetadataApiAt<ModuleNameMetadataApiHolder, IMetaDataImport2>::type com_meta_data_import_type;        

        typedef ObjectTag<type_name_metadata_type, QuickHeap> type_name_metadata_obj_tag_type;
        typedef typename type_decided_by<type_name_metadata_obj_tag_type>::type type_name_metadata_heap_type;

        BaseModuleNameMetadata() : 
            m_nameInitialized(false), 
            m_pAsmNameAsScope(NULL),
            m_pAsmAsScope(NULL),
            m_pResolvedMod(NULL), 
            m_mdm(mdModuleNil),
            m_tokenInitialized(false),
            m_filled(false)
        { }

        void Init(assembly_name_metadata_type &asmNameAsScope) const
        {
            _ASSERTE(m_pAsmNameAsScope == NULL && m_pAsmAsScope == NULL);
            m_pAsmNameAsScope = &asmNameAsScope;
        }

        void Init(assembly_metadata_type &asmAsScope) const
        {
            _ASSERTE(m_pAsmNameAsScope == NULL && m_pAsmAsScope == NULL);
            m_pAsmAsScope = &asmAsScope;
        }

        template<class T>
        T const &Map() const { return const_cast<this_type *>(this)->Map<T>(); }

        template<class T>
        T &Map() 
        { 
            _ASSERTE(m_pAsmNameAsScope != NULL || m_pAsmAsScope != NULL); 
            
            if (m_pAsmNameAsScope != NULL)
                return m_pAsmNameAsScope->Map<T>();
            else
                return m_pAsmAsScope->GetAssemblyNameCore().Map<T>();
        }
      
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

        typename base_type::i_assembly_name_metadata_type const &GetResolutionScope() const
        {
            return Map<assembly_name_metadata_type>();
        }

        typename base_type::i_module_metadata_type const &Resolve() const
        {
            return ResolveCore();
        }

        type_name_metadata_type *NewTypeName(std::wstring const &name) const
        {
            this_type *pMutableThis = const_cast<this_type *>(this);

            type_name_metadata_type *pTypeNameMeta = NULL;
            pTypeNameMeta = pMutableThis->TypeNameMetadataHeap().New();
            pTypeNameMeta->Init(*pMutableThis);
            pTypeNameMeta->SetName(name);
            return pTypeNameMeta;
        }

    private:
        friend typename assembly_name_metadata_type;
        friend typename assembly_metadata_type;
        friend typename module_metadata_type;
        friend typename type_name_metadata_type;

        type_name_metadata_heap_type &TypeNameMetadataHeap()
        {
            return Of<type_name_metadata_obj_tag_type>();
        }
        
        type_name_metadata_heap_type const &TypeNameMetadataHeap() const
        {
            return Of<type_name_metadata_obj_tag_type>();
        }

        module_metadata_type const &ResolveCore() const
        {
            this_type *pMutableThis = const_cast<this_type *>(this);
            return pMutableThis->ResolveCore();
        }
         
        module_metadata_type &ResolveCore() 
        {
            if (m_pAsmAsScope == NULL)
                m_pAsmAsScope = &Map<assembly_name_metadata_type>().ResolveCore();
            
            if (m_pResolvedMod == NULL)
            {
                com_meta_data_import_type &comMetaImp = m_pAsmAsScope->GetCOMMetaDataImport();
                std::wstring name;
                GetScopeProps(comMetaImp, name);

                if (m_name != name)
                {
                    BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
                }

                m_pResolvedMod = m_pAsmAsScope->ModuleMetadataHeap().New();
                m_pResolvedMod->Init(*m_pAsmAsScope);         
            }
            
            return *m_pResolvedMod;
        }

        // TODO: AssemblyMetadata に、GetModule みたいなメソッド名として移動。
        static void GetScopeProps(com_meta_data_import_type &comMetaImp, std::wstring &name)
        {
            GUID mvid;
            GetScopeProps(comMetaImp, name, mvid);
        }

        static void GetScopeProps(com_meta_data_import_type &comMetaImp, std::wstring &name, GUID &rMvid)
        {
            WCHAR tmp[MAX_SYM_NAME] = { 0 };
            ULONG tmpSize = sizeof(tmp);
            ::ZeroMemory(&rMvid, sizeof(GUID));
            HRESULT hr = comMetaImp.GetScopeProps(tmp, tmpSize, &tmpSize, &rMvid);
            if (FAILED(hr))
                BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
            
            name = tmp;
        }

        mdModule GetToken() const
        {
            _ASSERTE(m_tokenInitialized);
            return m_mdm;
        }

        void SetToken(mdModule mdm)
        {
            _ASSERTE(!m_tokenInitialized);
            m_mdm = mdm;
            m_tokenInitialized = true;
        }
        
        void SetName(std::wstring const &name)
        {
            _ASSERTE(!m_nameInitialized);
            m_name = name;
            m_nameInitialized = true;
        }

        module_metadata_type &GetResolvedModule()
        {
            _ASSERTE(m_pResolvedMod != NULL);
            return *m_pResolvedMod;
        }

        void SetResolvedModule(module_metadata_type &resolvedMod)
        {
            _ASSERTE(m_pResolvedMod == NULL);
            m_pResolvedMod = &resolvedMod;
        }

        void FillPropertiesIfNecessary() const
        {
            if (m_filled)
                return;

            this_type *pMutableThis = const_cast<this_type *>(this);
            
            module_metadata_type &resolvedMod = pMutableThis->ResolveCore();
            assembly_metadata_type &asmMeta = resolvedMod.Map<assembly_metadata_type>();
            com_meta_data_import_type &comMetaImp = asmMeta.GetCOMMetaDataImport();
            
            GetScopeProps(comMetaImp, m_name, m_mvid);

            m_filled = true;
        }

        mutable bool m_nameInitialized;
        mutable std::wstring m_name;
        mutable GUID m_mvid;
        mutable mdModule m_mdm;
        mutable bool m_tokenInitialized;
        mutable assembly_name_metadata_type *m_pAsmNameAsScope;
        mutable assembly_metadata_type *m_pAsmAsScope;
        mutable module_metadata_type *m_pResolvedMod;
        mutable bool m_filled;
    };




    
    template<
        class ModuleNameMetadataApiHolder
    >    
    class BaseModuleNameMetadataHash : 
        Traits::HashComputable<BaseModuleNameMetadata<ModuleNameMetadataApiHolder> const *>
    {
    public:
        typedef typename ModuleNameMetadataApiAt<ModuleNameMetadataApiHolder, Interfaces::AssemblyNameMetadataLabel>::type assembly_name_metadata_type;
        typedef typename ModuleNameMetadataApiAt<ModuleNameMetadataApiHolder, Interfaces::AssemblyNameMetadataHashLabel>::type assembly_name_metadata_hash_type;

        result_type operator()(param_type v) const
        {
            using namespace boost;

            _ASSERTE(v != NULL);

            std::size_t seed = 0;
            hash_combine(seed, hash_value(v->GetName()));
            hash_combine(seed, assembly_name_metadata_hash_type()(&v->Map<assembly_name_metadata_type>()));
            return seed;
        }
    };

    
    
    
    
    template<
        class ModuleNameMetadataApiHolder
    >    
    class BaseModuleNameMetadataEqualTo : 
        Traits::EqualityComparable<BaseModuleNameMetadata<ModuleNameMetadataApiHolder> const *>
    {
    public:
        typedef typename ModuleNameMetadataApiAt<ModuleNameMetadataApiHolder, Interfaces::AssemblyNameMetadataLabel>::type assembly_name_metadata_type;
        typedef typename ModuleNameMetadataApiAt<ModuleNameMetadataApiHolder, Interfaces::AssemblyNameMetadataEqualToLabel>::type assembly_name_metadata_equal_to_type;

        result_type operator()(param_type x, param_type y) const
        {
            _ASSERTE(x != NULL && y != NULL);

            return x->GetName() == y->GetName() &&
                   assembly_name_metadata_equal_to_type()(&x->Map<assembly_name_metadata_type>(), &y->Map<assembly_name_metadata_type>());
        }
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASEMODULENAMEMETADATA_HPP