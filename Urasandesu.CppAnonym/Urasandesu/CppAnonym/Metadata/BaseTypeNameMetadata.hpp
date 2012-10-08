#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_BASETYPENAMEMETADATA_HPP
#define URASANDESU_CPPANONYM_METADATA_BASETYPENAMEMETADATA_HPP

#ifndef URASANDESU_CPPANONYM_TRAITS_CARTRIDGEAPISYSTEM_HPP
#include <Urasandesu/CppAnonym/Traits/CartridgeApiSystem.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_TYPENAMEMETADATAAPIHOLDERLABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/TypeNameMetadataApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_SIMPLEHEAPPROVIDER_HPP
#include <Urasandesu/CppAnonym/SimpleHeapProvider.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_OBJECTTAG_HPP
#include <Urasandesu/CppAnonym/ObjectTag.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_METHODNAMEMETADATALABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/MethodNameMetadataLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_ASSEMBLYMETADATALABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/AssemblyMetadataLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_ASSEMBLYNAMEMETADATALABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/AssemblyNameMetadataLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_TYPEMETADATALABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/TypeMetadataLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_MODULENAMEMETADATALABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/ModuleNameMetadataLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_MODULEMETADATALABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/ModuleMetadataLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_TYPEKINDS_H
#include <Urasandesu/CppAnonym/Metadata/TypeKinds.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_CALLINGCONVENTIONS_H
#include <Urasandesu/CppAnonym/Metadata/CallingConventions.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASETYPENAMEMETADATAFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseTypeNameMetadataFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    template<class ApiCartridgesHolder, class ApiLabel>
    struct TypeNameMetadataApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::TypeNameMetadataApiHolderLabel, ApiLabel>
    {
    };

    template<
        class TypeNameMetadataApiHolder
    >
    class BaseTypeNameMetadata : 
        public SimpleHeapProvider<
            boost::mpl::vector<
                ObjectTag<typename TypeNameMetadataApiAt<TypeNameMetadataApiHolder, Interfaces::MethodNameMetadataLabel>::type, QuickHeap>
            >
        >
    {
    public:
        typedef BaseTypeNameMetadata<TypeNameMetadataApiHolder> this_type;

        typedef typename TypeNameMetadataApiAt<TypeNameMetadataApiHolder, Interfaces::AssemblyMetadataLabel>::type assembly_metadata_type;
        typedef typename TypeNameMetadataApiAt<TypeNameMetadataApiHolder, Interfaces::AssemblyNameMetadataLabel>::type assembly_name_metadata_type;
        typedef typename TypeNameMetadataApiAt<TypeNameMetadataApiHolder, Interfaces::ModuleMetadataLabel>::type module_metadata_type;
        typedef typename TypeNameMetadataApiAt<TypeNameMetadataApiHolder, Interfaces::ModuleNameMetadataLabel>::type module_name_metadata_type;
        typedef typename TypeNameMetadataApiAt<TypeNameMetadataApiHolder, Interfaces::TypeMetadataLabel>::type type_metadata_type;
        typedef typename TypeNameMetadataApiAt<TypeNameMetadataApiHolder, Interfaces::MethodNameMetadataLabel>::type method_name_metadata_type;
        typedef typename TypeNameMetadataApiAt<TypeNameMetadataApiHolder, IMetaDataImport2>::type com_meta_data_import_type;

        typedef ObjectTag<method_name_metadata_type, QuickHeap> method_name_metadata_obj_tag_type;
        typedef typename type_decided_by<method_name_metadata_obj_tag_type>::type method_name_metadata_heap_type;

        BaseTypeNameMetadata() : 
            m_nameInitialized(false),
            m_asmNameAsScopeInitialized(false),
            m_asmAsScopeInitialized(false),
            m_tokenInitialized(false),
            m_pResolvedType(NULL), 
            m_mdt(mdTokenNil), 
            m_pBaseTypeName(NULL), 
            m_filled(false), 
            m_pModNameAsScope(NULL), 
            m_pModAsScope(NULL)
        { }

        void Init(module_name_metadata_type &modNameAsScope) const
        {
            _ASSERTE(m_pModNameAsScope == NULL && m_pModAsScope == NULL);
            m_pModNameAsScope = &modNameAsScope;
        }

        void Init(module_metadata_type &modAsScope) const
        {
            _ASSERTE(m_pModNameAsScope == NULL && m_pModAsScope == NULL);
            m_pModAsScope = &modAsScope;
        }

        template<class T>
        T const &Map() const { return const_cast<this_type *>(this)->Map<T>(); }

        template<class T>
        T &Map() 
        { 
            _ASSERTE(m_pModNameAsScope != NULL || m_pModAsScope != NULL);
            if (m_pModNameAsScope != NULL)
                return m_pModNameAsScope->Map<T>();
            else
                return m_pModAsScope->GetModuleNameCore()->Map<T>();
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

        this_type const *GetBaseTypeName() const
        {
            FillPropertiesIfNecessary();
            return m_pBaseTypeName;
        }

        method_name_metadata_type *NewMethodName(std::wstring const &name, 
                                                 CallingConventions const &callingConvention, 
                                                 this_type const &retTypeName, 
                                                 std::vector<this_type const *> const &paramTypeNames) const
        {
            this_type *pMutableThis = const_cast<this_type *>(this);

            method_name_metadata_type *pMethodNameMeta = NULL;
            pMethodNameMeta = pMutableThis->MethodNameMetadataHeap().New();
            pMethodNameMeta->SetName(name);
            pMethodNameMeta->SetCallingConvention(callingConvention);
            pMethodNameMeta->SetReturnTypeName(retTypeName);
            pMethodNameMeta->SetParameterTypeNames(paramTypeNames);
            pMethodNameMeta->SetResolutionScope(*pMutableThis);
            return pMethodNameMeta;
        }

        type_metadata_type const *Resolve() const
        {
            return ResolveCore();
        }

    private:
        friend typename module_name_metadata_type;
        friend typename type_metadata_type;

        method_name_metadata_heap_type &MethodNameMetadataHeap()
        {
            return Of<method_name_metadata_obj_tag_type>();
        }
        
        method_name_metadata_heap_type const &MethodNameMetadataHeap() const
        {
            return Of<method_name_metadata_obj_tag_type>();
        }

        void SetName(std::wstring const &name)
        {
            _ASSERTE(!m_nameInitialized);
            m_name = name;
            m_nameInitialized = true;
        }

        mdToken GetToken() const
        {
            _ASSERTE(m_tokenInitialized);
            return m_mdt;
        }

        void SetToken(mdToken mdt)
        {
            _ASSERTE(!m_tokenInitialized);
            m_mdt = mdt;
            m_tokenInitialized = true;
        }

        type_metadata_type const *ResolveCore() const
        {
            this_type *pMutableThis = const_cast<this_type *>(this);
            return pMutableThis->ResolveCore();
        }

        type_metadata_type *ResolveCore()
        {
            if (m_pModAsScope == NULL)
                m_pModAsScope = Map<module_name_metadata_type>().ResolveCore();
            
            if (m_pResolvedType == NULL)
            {
                if (m_mdt != mdTokenNil)
                {
                    m_pResolvedType = m_pModAsScope->GetTypeCore(m_mdt);
                }
                else
                {
                    m_pResolvedType = m_pModAsScope->GetTypeCore(m_name);
                }
            }
            return m_pResolvedType;
        }

        void SetResolvedType(type_metadata_type &resolvedType)
        {
            _ASSERTE(m_pResolvedType == NULL);
            m_pResolvedType = &resolvedType;
        }

        void FillPropertiesIfNecessary() const
        {
            if (m_filled)
                return;

            this_type *pMutableThis = const_cast<this_type *>(this);

            type_metadata_type *pResolvedType = pMutableThis->ResolveCore();
            module_metadata_type &modMeta = pResolvedType->Map<module_metadata_type>();
            assembly_metadata_type &asmMeta = pResolvedType->Map<assembly_metadata_type>();

            com_meta_data_import_type &comMetaImp = asmMeta.GetCOMMetaDataImport();

            mdToken mdt = GetToken();
            if (TypeFromToken(mdt) == mdtTypeRef)
            {
                BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
            }
            else if (TypeFromToken(mdt) == mdtTypeDef)
            {
                WCHAR name[MAX_SYM_NAME] = { 0 };
                ULONG nameSize = sizeof(name);
                DWORD attr = 0;
                mdToken mdtExt = mdTokenNil;
                HRESULT hr = comMetaImp.GetTypeDefProps(mdt, name, nameSize, 
                                                        &nameSize, &attr, &mdtExt);
                if (FAILED(hr))
                    BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

                m_name = name;
                if (mdtExt != mdTokenNil)
                {
                    m_pBaseTypeName = modMeta.TypeNameMetadataHeap().New();
                    m_pBaseTypeName->Init(modMeta);
                    m_pBaseTypeName->SetToken(mdtExt);
                }
            }
            else
            {
                BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
            }


            m_filled = true;
        }

        mutable bool m_nameInitialized;
        mutable bool m_asmNameAsScopeInitialized;
        mutable bool m_asmAsScopeInitialized;
        mutable bool m_tokenInitialized;
        mutable std::wstring m_name;
        mutable module_metadata_type *m_pModAsScope;
        mutable module_name_metadata_type *m_pModNameAsScope;
        mutable mdToken m_mdt;
        mutable type_metadata_type *m_pResolvedType;
        mutable this_type *m_pBaseTypeName;
        mutable std::vector<COR_SIGNATURE> m_sigs;
        mutable bool m_filled;
    };




    
    template<
        class TypeNameMetadataApiHolder
    >    
    class BaseTypeNameMetadataHash : 
        Traits::HashComputable<BaseTypeNameMetadata<TypeNameMetadataApiHolder> const *>
    {
    public:
        typedef typename TypeNameMetadataApiAt<TypeNameMetadataApiHolder, Interfaces::ModuleNameMetadataLabel>::type module_name_metadata_type;
        typedef typename TypeNameMetadataApiAt<TypeNameMetadataApiHolder, Interfaces::ModuleNameMetadataHashLabel>::type module_name_metadata_hash_type;

        result_type operator()(param_type v) const
        {
            using namespace boost;

            _ASSERTE(v != NULL);

            std::size_t seed = 0;
            hash_combine(seed, hash_value(v->GetName()));
            hash_combine(seed, module_name_metadata_hash_type()(&v->Map<module_name_metadata_type>()));
            return seed;
        }
    };

    
    
    
    
    template<
        class TypeNameMetadataApiHolder
    >    
    class BaseTypeNameMetadataEqualTo : 
        Traits::EqualityComparable<BaseTypeNameMetadata<TypeNameMetadataApiHolder> const *>
    {
    public:
        typedef typename TypeNameMetadataApiAt<TypeNameMetadataApiHolder, Interfaces::ModuleNameMetadataLabel>::type module_name_metadata_type;
        typedef typename TypeNameMetadataApiAt<TypeNameMetadataApiHolder, Interfaces::ModuleNameMetadataEqualToLabel>::type module_name_metadata_equal_to_type;

        result_type operator()(param_type x, param_type y) const
        {
            _ASSERTE(x != NULL && y != NULL);

            return x->GetName() == y->GetName() &&
                   module_name_metadata_equal_to_type()(&x->Map<module_name_metadata_type>(), &y->Map<module_name_metadata_type>());
        }
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASETYPENAMEMETADATA_HPP