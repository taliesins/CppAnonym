#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_BASETYPENAMEMETADATAGENERATOR_HPP
#define URASANDESU_CPPANONYM_METADATA_BASETYPENAMEMETADATAGENERATOR_HPP

//#ifndef URASANDESU_CPPANONYM_TRAITS_CARTRIDGEAPISYSTEM_HPP
//#include <Urasandesu/CppAnonym/Traits/CartridgeApiSystem.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_TYPENAMEMETADATAAPIHOLDERLABEL_HPP
//#include <Urasandesu/CppAnonym/Metadata/Interfaces/TypeNameMetadataApiHolderLabel.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_SIMPLEHEAPPROVIDER_HPP
//#include <Urasandesu/CppAnonym/SimpleHeapProvider.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_OBJECTTAG_HPP
//#include <Urasandesu/CppAnonym/ObjectTag.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_METHODNAMEMETADATALABEL_HPP
//#include <Urasandesu/CppAnonym/Metadata/Interfaces/MethodNameMetadataLabel.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_ASSEMBLYMETADATALABEL_HPP
//#include <Urasandesu/CppAnonym/Metadata/Interfaces/AssemblyMetadataLabel.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_ASSEMBLYNAMEMETADATALABEL_HPP
//#include <Urasandesu/CppAnonym/Metadata/Interfaces/AssemblyNameMetadataLabel.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_TYPEMETADATALABEL_HPP
//#include <Urasandesu/CppAnonym/Metadata/Interfaces/TypeMetadataLabel.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_MODULENAMEMETADATALABEL_HPP
//#include <Urasandesu/CppAnonym/Metadata/Interfaces/ModuleNameMetadataLabel.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_MODULEMETADATALABEL_HPP
//#include <Urasandesu/CppAnonym/Metadata/Interfaces/ModuleMetadataLabel.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_METADATA_TYPEKINDS_H
//#include <Urasandesu/CppAnonym/Metadata/TypeKinds.h>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_METADATA_CALLINGCONVENTIONS_H
//#include <Urasandesu/CppAnonym/Metadata/CallingConventions.h>
//#endif

#ifndef URASANDESU_CPPANONYM_METADATA_TYPEATTRIBUTES_HPP
#include <Urasandesu/CppAnonym/Metadata/TypeAttributes.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_FIELDATTRIBUTES_HPP
#include <Urasandesu/CppAnonym/Metadata/FieldAttributes.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_METHODATTRIBUTES_HPP
#include <Urasandesu/CppAnonym/Metadata/MethodAttributes.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_PROPERTYATTRIBUTES_HPP
#include <Urasandesu/CppAnonym/Metadata/PropertyAttributes.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_TYPENAMEMETADATAGENERATORAPIHOLDERLABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/TypeNameMetadataGeneratorApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASETYPENAMEMETADATAGENERATORFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseTypeNameMetadataGeneratorFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    template<class ApiCartridgesHolder, class ApiLabel>
    struct TypeNameMetadataGeneratorApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::TypeNameMetadataGeneratorApiHolderLabel, ApiLabel>
    {
    };

    template<
        class TypeNameMetadataGeneratorApiHolder
    >
    class BaseTypeNameMetadataGenerator : 
        public SimpleHeapProvider<
            boost::mpl::vector<
                ObjectTag<typename TypeNameMetadataGeneratorApiAt<TypeNameMetadataGeneratorApiHolder, Interfaces::FieldNameMetadataGeneratorLabel>::type, QuickHeap>,
                ObjectTag<typename TypeNameMetadataGeneratorApiAt<TypeNameMetadataGeneratorApiHolder, Interfaces::MethodNameMetadataGeneratorLabel>::type, QuickHeap>,
                ObjectTag<typename TypeNameMetadataGeneratorApiAt<TypeNameMetadataGeneratorApiHolder, Interfaces::PropertyNameMetadataGeneratorLabel>::type, QuickHeap>
            >
        >
    {
    public:
        typedef BaseTypeNameMetadataGenerator<TypeNameMetadataGeneratorApiHolder> this_type;

        typedef typename TypeNameMetadataGeneratorApiAt<TypeNameMetadataGeneratorApiHolder, Interfaces::ModuleNameMetadataGeneratorLabel>::type module_name_metadata_generator_type;
        typedef typename TypeNameMetadataGeneratorApiAt<TypeNameMetadataGeneratorApiHolder, Interfaces::FieldNameMetadataGeneratorLabel>::type field_name_metadata_generator_type;
        typedef typename TypeNameMetadataGeneratorApiAt<TypeNameMetadataGeneratorApiHolder, Interfaces::TypeMetadataLabel>::type type_metadata_type;
        typedef typename TypeNameMetadataGeneratorApiAt<TypeNameMetadataGeneratorApiHolder, Interfaces::MethodNameMetadataGeneratorLabel>::type method_name_metadata_generator_type;
        typedef typename TypeNameMetadataGeneratorApiAt<TypeNameMetadataGeneratorApiHolder, Interfaces::PropertyNameMetadataGeneratorLabel>::type property_name_metadata_generator_type;

        typedef ObjectTag<field_name_metadata_generator_type, QuickHeap> field_name_metadata_generator_obj_tag_type;
        typedef typename type_decided_by<field_name_metadata_generator_obj_tag_type>::type field_name_metadata_generator_heap_type;

        typedef ObjectTag<method_name_metadata_generator_type, QuickHeap> method_name_metadata_generator_obj_tag_type;
        typedef typename type_decided_by<method_name_metadata_generator_obj_tag_type>::type method_name_metadata_generator_heap_type;

        typedef ObjectTag<property_name_metadata_generator_type, QuickHeap> property_name_metadata_generator_obj_tag_type;
        typedef typename type_decided_by<property_name_metadata_generator_obj_tag_type>::type property_name_metadata_generator_heap_type;

        BaseTypeNameMetadataGenerator() : 
            m_pModNameGenAsScope(NULL), 
            m_nameInitialized(false), 
            m_attrInitialized(false)
        { }

        void Init(module_name_metadata_generator_type &modNameGenAsScope) const
        {
            _ASSERTE(m_pModNameGenAsScope == NULL);
            m_pModNameGenAsScope = &modNameGenAsScope;
        }

        template<class T>
        T const &Map() const { return const_cast<this_type *>(this)->Map<T>(); }

        template<class T>
        T &Map() 
        { 
            //_ASSERTE(m_pModNameAsScope != NULL || m_pModAsScope != NULL);
            //if (m_pModNameAsScope != NULL)
            //    return m_pModNameAsScope->Map<T>();
            //else
            //    return m_pModAsScope->GetModuleNameCore()->Map<T>();
            _ASSERTE(m_pModNameGenAsScope != NULL);
            return m_pModNameGenAsScope->Map<T>();
        }
      
        template<>
        this_type const &Map<this_type>() const { return const_cast<this_type *>(this)->Map<this_type>(); }
      
        template<>
        this_type &Map<this_type>() { return *this; }

        std::wstring const &GetName() const
        {
            if (!m_nameInitialized)
            {
                BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
            }
            return m_name;
        }

        TypeAttributes const &GetAttribute() const
        {
            if (!m_attrInitialized)
            {
                BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
            }
            return m_attr;
        }

        this_type *NewNestedTypeNameGenerator(std::wstring const &name, TypeAttributes const &attr) const
        {
            this_type *pMutableThis = const_cast<this_type *>(this);
            module_name_metadata_generator_type &modNameMetaGen = 
                                pMutableThis->Map<module_name_metadata_generator_type>();
            return modNameMetaGen.NewTypeNameGenerator(name, attr);
        }

        field_name_metadata_generator_type *NewFieldNameGenerator(std::wstring const &name, 
                                                                  type_metadata_type const &fieldType, 
                                                                  FieldAttributes const &attr) const
        {
            this_type *pMutableThis = const_cast<this_type *>(this);

            field_name_metadata_generator_type *pFieldNameMetaGen = NULL;
            pFieldNameMetaGen = pMutableThis->FieldNameMetadataGeneratorHeap().New();
            pFieldNameMetaGen->Init(*pMutableThis);
            pFieldNameMetaGen->SetName(name);
            pFieldNameMetaGen->SetFieldType(fieldType);
            pFieldNameMetaGen->SetAttribute(attr);
            return pFieldNameMetaGen;
        }

        method_name_metadata_generator_type *NewMethodNameGenerator(std::wstring const &name, 
                                                                    CallingConventions const &callingConvention, 
                                                                    type_metadata_type const &retType, 
                                                                    std::vector<type_metadata_type const *> const &paramTypes,
                                                                    MethodAttributes const &attr) const
        {
            this_type *pMutableThis = const_cast<this_type *>(this);

            method_name_metadata_generator_type *pMethodNameMetaGen = NULL;
            pMethodNameMetaGen = pMutableThis->MethodNameMetadataGeneratorHeap().New();
            pMethodNameMetaGen->Init(*pMutableThis);
            pMethodNameMetaGen->SetName(name);
            pMethodNameMetaGen->SetCallingConvention(callingConvention);
            pMethodNameMetaGen->SetReturnType(retType);
            pMethodNameMetaGen->SetParameterTypes(paramTypes);
            pMethodNameMetaGen->SetAttribute(attr);
            return pMethodNameMetaGen;
        }

        property_name_metadata_generator_type *NewPropertyNameGenerator(std::wstring const &name, 
                                                                        type_metadata_type const &propType,
                                                                        std::vector<type_metadata_type const *> const &paramTypes,
                                                                        PropertyAttributes const &attr) const
        {
            this_type *pMutableThis = const_cast<this_type *>(this);

            property_name_metadata_generator_type *pPropertyNameMetaGen = NULL;
            pPropertyNameMetaGen = pMutableThis->PropertyNameMetadataGeneratorHeap().New();
            pPropertyNameMetaGen->Init(*pMutableThis);
            pPropertyNameMetaGen->SetName(name);
            pPropertyNameMetaGen->SetPropertyType(propType);
            pPropertyNameMetaGen->SetParameterTypes(paramTypes);
            pPropertyNameMetaGen->SetAttribute(attr);
            return pPropertyNameMetaGen;
        }

    private:
        friend typename module_name_metadata_generator_type;

        field_name_metadata_generator_heap_type &FieldNameMetadataGeneratorHeap()
        {
            return Of<field_name_metadata_generator_obj_tag_type>();
        }
        
        field_name_metadata_generator_heap_type const &FieldNameMetadataGeneratorHeap() const
        {
            return Of<field_name_metadata_generator_obj_tag_type>();
        }

        method_name_metadata_generator_heap_type &MethodNameMetadataGeneratorHeap()
        {
            return Of<method_name_metadata_generator_obj_tag_type>();
        }
        
        method_name_metadata_generator_heap_type const &MethodNameMetadataGeneratorHeap() const
        {
            return Of<method_name_metadata_generator_obj_tag_type>();
        }

        property_name_metadata_generator_heap_type &PropertyNameMetadataGeneratorHeap()
        {
            return Of<property_name_metadata_generator_obj_tag_type>();
        }
        
        property_name_metadata_generator_heap_type const &PropertyNameMetadataGeneratorHeap() const
        {
            return Of<property_name_metadata_generator_obj_tag_type>();
        }

        void SetName(std::wstring const &name)
        {
            _ASSERTE(!m_nameInitialized);
            m_name = name;
            m_nameInitialized = true;
        }

        void SetAttribute(TypeAttributes const &attr)
        {
            _ASSERTE(!m_attrInitialized);
            m_attr = attr;
            m_attrInitialized = true;
        }

        mutable module_name_metadata_generator_type *m_pModNameGenAsScope;
        bool m_nameInitialized;
        std::wstring m_name;
        bool m_attrInitialized;
        TypeAttributes m_attr;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASETYPENAMEMETADATAGENERATOR_HPP