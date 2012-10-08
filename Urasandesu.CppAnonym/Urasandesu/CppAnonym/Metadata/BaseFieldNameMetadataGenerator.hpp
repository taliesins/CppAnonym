#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_BASEFIELDNAMEMETADATAGENERATOR_HPP
#define URASANDESU_CPPANONYM_METADATA_BASEFIELDNAMEMETADATAGENERATOR_HPP

//#ifndef URASANDESU_CPPANONYM_IHEAPCONTENT_H
//#include <Urasandesu/CppAnonym/IHeapContent.h>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_TRAITS_CARTRIDGEAPISYSTEM_HPP
//#include <Urasandesu/CppAnonym/Traits/CartridgeApiSystem.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_METADATA_CALLINGCONVENTIONS_H
//#include <Urasandesu/CppAnonym/Metadata/CallingConventions.h>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_TYPEMETADATALABEL_HPP
//#include <Urasandesu/CppAnonym/Metadata/Interfaces/TypeMetadataLabel.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_UTILITIES_HASH_HPP
//#include <Urasandesu/CppAnonym/Utilities/Hash.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_UTILITIES_EQUALTO_HPP
//#include <Urasandesu/CppAnonym/Utilities/EqualTo.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_METHODNAMEMETADATAAPIHOLDERLABEL_HPP
//#include <Urasandesu/CppAnonym/Metadata/Interfaces/MethodNameMetadataApiHolderLabel.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_TRAITS_EQUALITYCOMPARABLE_HPP
//#include <Urasandesu/CppAnonym/Traits/EqualityComparable.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_TRAITS_HASHCOMPUTABLE_HPP
//#include <Urasandesu/CppAnonym/Traits/HashComputable.hpp>
//#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_FIELDNAMEMETADATAGENERATORAPIHOLDERLABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/FieldNameMetadataGeneratorApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEFIELDNAMEMETADATAGENERATORFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseFieldNameMetadataGeneratorFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    template<class ApiCartridgesHolder, class ApiLabel>
    struct FieldNameMetadataGeneratorApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::FieldNameMetadataGeneratorApiHolderLabel, ApiLabel>
    {
    };

    template<
        class FieldNameMetadataGeneratorApiHolder
    >
    class BaseFieldNameMetadataGenerator
    {
    public:
        typedef BaseFieldNameMetadataGenerator<FieldNameMetadataGeneratorApiHolder> this_type;

        typedef typename FieldNameMetadataGeneratorApiAt<FieldNameMetadataGeneratorApiHolder, Interfaces::TypeNameMetadataGeneratorLabel>::type type_name_metadata_generator_type;
        typedef typename FieldNameMetadataGeneratorApiAt<FieldNameMetadataGeneratorApiHolder, Interfaces::TypeMetadataLabel>::type type_metadata_type;

        BaseFieldNameMetadataGenerator() : 
            m_pTypeNameGenAsScope(NULL), 
            m_nameInitialized(false), 
            m_pFieldType(NULL), 
            m_attrInitialized(false),
            m_attr(FieldAttributes::FA_PRIVATE_SCOPE)
        { }

        void Init(type_name_metadata_generator_type &typeNameGenAsScope) const
        {
            _ASSERTE(m_pTypeNameGenAsScope == NULL);
            m_pTypeNameGenAsScope = &typeNameGenAsScope;
        }

        std::wstring const &GetName() const
        {
            if (!m_nameInitialized)
            {
                BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
            }
            return m_name;
        }

        type_metadata_type const &GetFieldType() const
        {
            if (m_pFieldType == NULL)
            {
                BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
            }
            return *m_pFieldType;
        }

        FieldAttributes const &GetAttribute() const
        {
            if (!m_attrInitialized)
            {
                BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
            }
            return m_attr;
        }

    private:
        friend typename type_name_metadata_generator_type;

        void SetName(std::wstring const &name)
        {
            _ASSERTE(!m_nameInitialized);
            m_name = name;
            m_nameInitialized = true;
        }

        void SetFieldType(type_metadata_type const &fieldType)
        {
            _ASSERTE(m_pFieldType == NULL);
            m_pFieldType = &fieldType;
        }

        void SetAttribute(FieldAttributes const &attr)
        {
            _ASSERTE(!m_attrInitialized);
            m_attr = attr;
            m_attrInitialized = true;
        }

        mutable type_name_metadata_generator_type *m_pTypeNameGenAsScope;
        bool m_nameInitialized;
        std::wstring m_name;
        type_metadata_type const *m_pFieldType;
        bool m_attrInitialized;
        FieldAttributes m_attr;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASEFIELDNAMEMETADATAGENERATOR_HPP