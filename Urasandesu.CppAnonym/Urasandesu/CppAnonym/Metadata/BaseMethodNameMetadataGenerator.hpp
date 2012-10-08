#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETHODNAMEMETADATAGENERATOR_HPP
#define URASANDESU_CPPANONYM_METADATA_BASEMETHODNAMEMETADATAGENERATOR_HPP

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

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_METHODNAMEMETADATAGENERATORAPIHOLDERLABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/MethodNameMetadataGeneratorApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETHODNAMEMETADATAGENERATORFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseMethodNameMetadataGeneratorFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    template<class ApiCartridgesHolder, class ApiLabel>
    struct MethodNameMetadataGeneratorApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::MethodNameMetadataGeneratorApiHolderLabel, ApiLabel>
    {
    };

    template<
        class MethodNameMetadataGeneratorApiHolder
    >
    class BaseMethodNameMetadataGenerator
    {
    public:
        typedef BaseMethodNameMetadataGenerator<MethodNameMetadataGeneratorApiHolder> this_type;

        typedef typename MethodNameMetadataGeneratorApiAt<MethodNameMetadataGeneratorApiHolder, Interfaces::TypeNameMetadataGeneratorLabel>::type type_name_metadata_generator_type;
        typedef typename MethodNameMetadataGeneratorApiAt<MethodNameMetadataGeneratorApiHolder, Interfaces::TypeMetadataLabel>::type type_metadata_type;
        typedef typename MethodNameMetadataGeneratorApiAt<MethodNameMetadataGeneratorApiHolder, Interfaces::ILGeneratorLabel>::type il_generator_type;

        BaseMethodNameMetadataGenerator() : 
            m_pTypeNameGenAsScope(NULL), 
            m_nameInitialized(false), 
            m_callingConventionInitialized(false), 
            m_pRetType(NULL), 
            m_paramTypesInitialized(false), 
            m_attrInitialized(false),
            m_attr(MethodAttributes::MA_PRIVATE_SCOPE), 
            m_genInitialized(false)
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

        CallingConventions const &GetCallingConvention() const
        {
            if (!m_callingConventionInitialized)
            {
                BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
            }
            return m_callingConvention;
        }

        type_metadata_type const &GetReturnType() const
        {
            if (m_pRetType == NULL)
            {
                BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
            }
            return *m_pRetType;
        }

        std::vector<type_metadata_type const *> const &GetParameterTypes() const
        {
            if (!m_paramTypesInitialized)
            {
                BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
            }
            return m_paramTypes;
        }

        MethodAttributes const &GetAttribute() const
        {
            if (!m_attrInitialized)
            {
                BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
            }
            return m_attr;
        }

        il_generator_type &GetILGenerator()
        {
            if (!m_genInitialized)
            {
                this_type *pMutableThis = const_cast<this_type *>(this);
                m_gen.Init(*pMutableThis);
                m_genInitialized = true;
            }
            return m_gen;
        }

    private:
        friend typename type_name_metadata_generator_type;

        void SetName(std::wstring const &name)
        {
            _ASSERTE(!m_nameInitialized);
            m_name = name;
            m_nameInitialized = true;
        }

        void SetCallingConvention(CallingConventions const &callingConvention)
        {
            _ASSERTE(!m_callingConventionInitialized);
            m_callingConvention = callingConvention;
            m_callingConventionInitialized = true;
        }

        void SetReturnType(type_metadata_type const &retType)
        {
            _ASSERTE(m_pRetType == NULL);
            m_pRetType = &retType;
        }

        void SetParameterTypes(std::vector<type_metadata_type const *> const &paramTypes)
        {
            _ASSERTE(!m_paramTypesInitialized);
            m_paramTypes = paramTypes;
            m_paramTypesInitialized = true;
        }

        void SetAttribute(MethodAttributes const &attr)
        {
            _ASSERTE(!m_attrInitialized);
            m_attr = attr;
            m_attrInitialized = true;
        }
        
        mutable type_name_metadata_generator_type *m_pTypeNameGenAsScope;
        bool m_nameInitialized;
        std::wstring m_name;
        bool m_callingConventionInitialized;
        CallingConventions m_callingConvention;
        type_metadata_type const *m_pRetType;
        bool m_paramTypesInitialized;
        std::vector<type_metadata_type const *> m_paramTypes;
        bool m_attrInitialized;
        MethodAttributes m_attr;
        bool m_genInitialized;
        il_generator_type m_gen;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASEMETHODNAMEMETADATAGENERATOR_HPP