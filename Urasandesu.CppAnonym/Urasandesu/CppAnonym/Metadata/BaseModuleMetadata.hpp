#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_BASEMODULEMETADATA_HPP
#define URASANDESU_CPPANONYM_METADATA_BASEMODULEMETADATA_HPP

#ifndef URASANDESU_CPPANONYM_SIMPLEHEAPPROVIDER_HPP
#include <Urasandesu/CppAnonym/SimpleHeapProvider.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_SIMPLEBLOB_HPP
#include <Urasandesu/CppAnonym/SimpleBlob.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_TYPEKINDS_H
#include <Urasandesu/CppAnonym/Metadata/TypeKinds.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_CALLINGCONVENTIONS_H
#include <Urasandesu/CppAnonym/Metadata/CallingConventions.h>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_CARTRIDGEAPISYSTEM_HPP
#include <Urasandesu/CppAnonym/Traits/CartridgeApiSystem.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_MODULEMETADATAAPIHOLDERLABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/ModuleMetadataApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMODULEMETADATAFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseModuleMetadataFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    template<class ApiCartridgesHolder, class ApiLabel>
    struct ModuleMetadataApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::ModuleMetadataApiHolderLabel, ApiLabel>
    {
    };

    template<
        class ModuleMetadataApiHolder
    >    
    class BaseModuleMetadata :
        public SimpleHeapProvider<
            boost::mpl::vector<
                ObjectTag<typename ModuleMetadataApiAt<ModuleMetadataApiHolder, Interfaces::TypeMetadataLabel>::type, QuickHeap>
            >
        >
    {
    public:
        typedef BaseModuleMetadata<ModuleMetadataApiHolder> this_type;

        typedef typename ModuleMetadataApiAt<ModuleMetadataApiHolder, Interfaces::AssemblyMetadataLabel>::type assembly_metadata_type;    
        typedef typename ModuleMetadataApiAt<ModuleMetadataApiHolder, Interfaces::ModuleNameMetadataLabel>::type module_name_metadata_type;
        typedef typename ModuleMetadataApiAt<ModuleMetadataApiHolder, Interfaces::TypeNameMetadataLabel>::type type_name_metadata_type;
        typedef typename ModuleMetadataApiAt<ModuleMetadataApiHolder, Interfaces::TypeMetadataLabel>::type type_metadata_type;
        typedef typename ModuleMetadataApiAt<ModuleMetadataApiHolder, IMetaDataImport2>::type com_meta_data_import_type;                

        typedef ObjectTag<type_metadata_type, QuickHeap> type_metadata_obj_tag_type;
        typedef typename type_decided_by<type_metadata_obj_tag_type>::type type_metadata_heap_type;

        CPP_ANONYM_DECLARE_HAS_MEMBER_TYPE(ModNameMeta, type_name_metadata_heap_type);
        CPP_ANONYM_DECLARE_GET_MEMBER_TYPE(ModNameMeta, type_name_metadata_heap_type);
        typedef typename boost::mpl::eval_if<
            CPP_ANONYM_HAS_MEMBER_TYPE(ModNameMeta, type_name_metadata_heap_type, module_name_metadata_type), 
            CPP_ANONYM_GET_MEMBER_TYPE(ModNameMeta, type_name_metadata_heap_type, module_name_metadata_type), 
            boost::mpl::void_
        >::type type_name_metadata_heap_type;

        BaseModuleMetadata() : 
            m_pAsmAsScope(NULL),
            m_pModNameMeta(NULL),
            m_mdm(mdModuleNil)
        { }        

        void Init(assembly_metadata_type &asmMeta) const
        {
            _ASSERTE(m_pAsmAsScope == NULL);
            m_pAsmAsScope = &asmMeta;
        }

        template<class T>
        T const &Map() const { return const_cast<this_type *>(this)->Map<T>(); }

        template<class T>
        T &Map() { _ASSERTE(m_pAsmAsScope != NULL); return m_pAsmAsScope->Map<T>(); }
      
        template<>
        this_type const &Map<this_type>() const { return const_cast<this_type *>(this)->Map<this_type>(); }
      
        template<>
        this_type &Map<this_type>() { return *this; }

        type_name_metadata_type *NewTypeName(std::wstring const &name) const
        {
            return GetModuleName()->NewTypeName(name);
        }

        mdModule GetToken() const
        {
            if (m_mdm == mdModuleNil)
            {
                this_type *pMutableThis = const_cast<this_type *>(this);
                assembly_metadata_type &asmMeta = pMutableThis->Map<assembly_metadata_type>();

                com_meta_data_import_type &comMetaImp = asmMeta.GetCOMMetaDataImport();

                HRESULT hr = comMetaImp.GetModuleFromScope(&m_mdm);
                if (FAILED(hr))
                    BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
            }
            return m_mdm;
        }

        type_metadata_type const *GetType(std::wstring const &name) const
        {
            return GetTypeCore(name);
        }

        type_metadata_type const *GetType(mdToken mdtType) const
        {
            return GetTypeCore(mdtType);
        }

        module_name_metadata_type const *GetModuleName() const
        {
            return GetModuleNameCore();
        }

    private:
        friend typename type_name_metadata_type;
        friend typename type_metadata_type;

        type_metadata_heap_type &TypeMetadataHeap()
        {
            return Of<type_metadata_obj_tag_type>();
        }
        
        type_metadata_heap_type const &TypeMetadataHeap() const
        {
            return Of<type_metadata_obj_tag_type>();
        }

        type_name_metadata_heap_type &TypeNameMetadataHeap()
        {
            return GetModuleNameCore()->TypeNameMetadataHeap();
        }
        
        type_name_metadata_heap_type const &TypeNameMetadataHeap() const
        {
            return GetModuleNameCore()->TypeNameMetadataHeap();
        }

        type_metadata_type const *GetTypeCore(std::wstring const &name) const
        {
            this_type *pMutableThis = const_cast<this_type *>(this);
            return pMutableThis->GetTypeCore(name);
        }

        type_metadata_type *GetTypeCore(std::wstring const &name)
        {
            if (m_typeStrNameToIndex.find(name) == m_typeStrNameToIndex.end())
            {
                m_typeStrNameToIndex[name] = MAXULONG_PTR;
            }

            SIZE_T index = m_typeStrNameToIndex[name];
            if (index == MAXULONG_PTR)
            {
                assembly_metadata_type &asmMeta = Map<assembly_metadata_type>();
                
                com_meta_data_import_type &comMetaImp = asmMeta.GetCOMMetaDataImport();

                mdTypeDef mdtd = mdTypeDefNil;
                HRESULT hr = comMetaImp.FindTypeDefByName(name.c_str(), NULL, &mdtd);
                if (FAILED(hr))
                    BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

                type_metadata_type *pTypeMeta = TypeMetadataHeap().New();
                pTypeMeta->Init(*this);
                pTypeMeta->SetToken(mdtd);

                m_typeStrNameToIndex[name] = TypeMetadataHeap().Size() - 1;
                m_typeTokenToIndex[mdtd] = TypeMetadataHeap().Size() - 1;

                return pTypeMeta;
            }
            else
            {
                return TypeMetadataHeap()[index];
            }
        }

        type_metadata_type const *GetTypeCore(mdToken mdtType) const
        {
            this_type *pMutableThis = const_cast<this_type *>(this);
            return pMutableThis->GetTypeCore(mdtType);
        }

        type_metadata_type *GetTypeCore(mdToken mdtType)
        {
            if (TypeFromToken(mdtType) == mdtTypeRef)
            {
                BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
            }
            else if (TypeFromToken(mdtType) == mdtTypeDef)
            {
                if (m_typeTokenToIndex.find(mdtType) == m_typeTokenToIndex.end())
                {
                    m_typeTokenToIndex[mdtType] = MAXULONG_PTR;
                }

                SIZE_T index = m_typeTokenToIndex[mdtType];
                if (index == MAXULONG_PTR)
                {
                    type_metadata_type *pTypeMeta = TypeMetadataHeap().New();
                    pTypeMeta->Init(*this);
                    pTypeMeta->SetToken(mdtType);

                    std::wstring name = pTypeMeta->GetTypeName()->GetName();
                    m_typeStrNameToIndex[name] = TypeMetadataHeap().Size() - 1;

                    return pTypeMeta;
                }
                else
                {
                    return TypeMetadataHeap()[index];
                }
            }
            else
            {
                BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
            }
        }

        module_name_metadata_type const *GetModuleNameCore() const
        {
            this_type *pMutableThis = const_cast<this_type *>(this);
            return pMutableThis->GetModuleNameCore();
        }

        module_name_metadata_type *GetModuleNameCore()
        {
            if (m_pModNameMeta == NULL)
            {
                assembly_metadata_type &asmMeta = Map<assembly_metadata_type>();

                m_pModNameMeta = asmMeta.ModuleNameMetadataHeap().New();
                m_pModNameMeta->Init(asmMeta);
                m_pModNameMeta->SetToken(GetToken());
                m_pModNameMeta->SetResolvedModule(*this);
            }
            return m_pModNameMeta;
        }

        mutable assembly_metadata_type *m_pAsmAsScope;
        mutable module_name_metadata_type *m_pModNameMeta;
        mutable mdModule m_mdm;
        mutable boost::unordered_map<std::wstring, SIZE_T> m_typeStrNameToIndex;
        mutable boost::unordered_map<mdToken, SIZE_T>  m_typeTokenToIndex;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASEMODULEMETADATA_HPP