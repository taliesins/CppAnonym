#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_BASETYPENAMEMETADATA_HPP
#define URASANDESU_CPPANONYM_METADATA_BASETYPENAMEMETADATA_HPP

#ifndef URASANDESU_CPPANONYM_TRAITS_CARTRIDGEAPISYSTEMFWD_HPP
#include <Urasandesu/CppAnonym/Traits/CartridgeApiSystemFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_TYPENAMEMETADATAAPIHOLDERLABELFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/TypeNameMetadataApiHolderLabelFwd.hpp>
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

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_ASSEMBLYMETADATALABELFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/AssemblyMetadataLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_ASSEMBLYNAMEMETADATALABELFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/AssemblyNameMetadataLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_TYPEMETADATALABELFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/TypeMetadataLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_TYPEKINDS_H
#include <Urasandesu/CppAnonym/Metadata/TypeKinds.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_CALLINGCONVENTIONS_H
#include <Urasandesu/CppAnonym/Metadata/CallingConventions.h>
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
        typedef typename TypeNameMetadataApiAt<TypeNameMetadataApiHolder, Interfaces::TypeMetadataLabel>::type type_metadata_type;
        typedef typename TypeNameMetadataApiAt<TypeNameMetadataApiHolder, Interfaces::MethodNameMetadataLabel>::type method_name_metadata_type;

        typedef ObjectTag<method_name_metadata_type, QuickHeap> method_name_metadata_obj_tag_type;
        typedef typename type_decided_by<method_name_metadata_obj_tag_type>::type method_name_metadata_heap_type;

        BaseTypeNameMetadata() : 
            m_pAsmNameAsScope(NULL), 
            m_pAsmAsScope(NULL), 
            m_pTypeResolved(NULL), 
            m_mdt(mdTokenNil)
        { }

        std::wstring const &GetName() const
        {
            // This method implementation is temporary.
            if (m_name.empty())
            {
                m_name = L"System.Console";
            }
            return m_name;
        }

        void SetName(std::wstring const &name)
        {
            // Should be immutable...
            m_name = name;
        }

        TypeKinds const &GetKind() const
        {
            return m_kind;
        }

        void SetKind(TypeKinds const &kind)
        {
            m_kind = kind;
        }

        assembly_name_metadata_type const &GetResolutionScope() const
        {
            _ASSERTE(m_pAsmNameAsScope != NULL);
            return *m_pAsmNameAsScope;
        }

        void SetResolutionScope(assembly_name_metadata_type &asmNameAsScope)
        {
            m_pAsmNameAsScope = &asmNameAsScope;
        }

        void SetResolutionScope(assembly_metadata_type &asmAsScope)
        {
            m_pAsmAsScope = &asmAsScope;
        }

        method_name_metadata_type *NewMethodName(std::wstring const &name, 
                                                 CallingConventions const &callingConvention, 
                                                 this_type const &retTypeName, 
                                                 std::vector<this_type const *> const &paramTypeNames) const
        {
            this_type *mutableThis = const_cast<this_type *>(this);

            method_name_metadata_type *pMethodNameMeta = NULL;
            pMethodNameMeta = mutableThis->MethodNameMetadataHeap().New();
            pMethodNameMeta->SetName(name);
            pMethodNameMeta->SetCallingConvention(callingConvention);
            pMethodNameMeta->SetReturnTypeName(retTypeName);
            pMethodNameMeta->SetParameterTypeNames(paramTypeNames);
            pMethodNameMeta->SetResolutionScope(*mutableThis);
            return pMethodNameMeta;
        }

        type_metadata_type const *Resolve() const
        {
            // This method implementation is temporary.
            if (m_pAsmAsScope == NULL)
                m_pAsmAsScope = GetResolutionScope().Resolve();
            
            if (m_pTypeResolved == NULL)
                m_pTypeResolved = m_pAsmAsScope->GetType(m_name);
            return m_pTypeResolved;
        }

    private:
        template<
            class TypeMetadataApiHolder
        >    
        friend class BaseTypeMetadata;

        method_name_metadata_heap_type &MethodNameMetadataHeap()
        {
            return Of<method_name_metadata_obj_tag_type>();
        }
        
        method_name_metadata_heap_type const &MethodNameMetadataHeap() const
        {
            return Of<method_name_metadata_obj_tag_type>();
        }

        void SetToken(mdToken mdt)
        {
            m_mdt = mdt;
        }

        mutable std::wstring m_name;
        TypeKinds m_kind;
        assembly_name_metadata_type *m_pAsmNameAsScope;
        mdToken m_mdt;
        mutable assembly_metadata_type const *m_pAsmAsScope;
        mutable type_metadata_type const *m_pTypeResolved;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASETYPENAMEMETADATA_HPP