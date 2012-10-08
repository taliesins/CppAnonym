#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_BASELOCALNAMEMETADATAGENERATOR_HPP
#define URASANDESU_CPPANONYM_METADATA_BASELOCALNAMEMETADATAGENERATOR_HPP

//#ifndef URASANDESU_CPPANONYM_TRAITS_CARTRIDGEAPISYSTEM_HPP
//#include <Urasandesu/CppAnonym/Traits/CartridgeApiSystem.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_ILGENERATORAPIHOLDERLABEL_HPP
//#include <Urasandesu/CppAnonym/Metadata/Interfaces/ILGeneratorApiHolderLabel.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_SIMPLEHEAPPROVIDER_HPP
//#include <Urasandesu/CppAnonym/SimpleHeapProvider.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_METADATA_INSTRUCTION_H
//#include <Urasandesu/CppAnonym/Metadata/Instruction.h>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_METHODMETADATALABEL_HPP
//#include <Urasandesu/CppAnonym/Metadata/Interfaces/MethodMetadataLabel.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_METHODNAMEMETADATALABEL_HPP
//#include <Urasandesu/CppAnonym/Metadata/Interfaces/MethodNameMetadataLabel.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_TYPEMETADATALABEL_HPP
//#include <Urasandesu/CppAnonym/Metadata/Interfaces/TypeMetadataLabel.hpp>
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
//#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_TYPENAMEMETADATALABEL_HPP
//#include <Urasandesu/CppAnonym/Metadata/Interfaces/TypeNameMetadataLabel.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_METADATADISPENSERLABEL_HPP
//#include <Urasandesu/CppAnonym/Metadata/Interfaces/MetadataDispenserLabel.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_METADATA_TYPEKINDS_H
//#include <Urasandesu/CppAnonym/Metadata/TypeKinds.h>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_METADATA_CALLINGCONVENTIONS_H
//#include <Urasandesu/CppAnonym/Metadata/CallingConventions.h>
//#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_LOCALNAMEMETADATAGENERATORAPIHOLDERLABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/LocalNameMetadataGeneratorApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASELOCALNAMEMETADATAGENERATORFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseLocalNameMetadataGeneratorFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    template<class ApiCartridgesHolder, class ApiLabel>
    struct LocalNameMetadataGeneratorApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::LocalNameMetadataGeneratorApiHolderLabel, ApiLabel>
    {
    };

    template<
        class LocalNameMetadataGeneratorApiHolder
    >
    class BaseLocalNameMetadataGenerator
    {
    public:
        typedef BaseLocalNameMetadataGenerator<LocalNameMetadataGeneratorApiHolder> this_type;

        typedef typename LocalNameMetadataGeneratorApiAt<LocalNameMetadataGeneratorApiHolder, Interfaces::ILGeneratorLabel>::type il_generator_type;
        typedef typename LocalNameMetadataGeneratorApiAt<LocalNameMetadataGeneratorApiHolder, Interfaces::TypeMetadataLabel>::type type_metadata_type;

        BaseLocalNameMetadataGenerator() : 
            m_pGenAsScope(NULL),
            m_pLocalType(NULL)
        { }

        void Init(il_generator_type &genAsScope) const
        {
            _ASSERTE(m_pGenAsScope == NULL);
            m_pGenAsScope = &genAsScope;
        }

    private:
        friend typename il_generator_type;

        void SetLocalType(type_metadata_type const &localType)
        {
            _ASSERTE(m_pLocalType == NULL);
            m_pLocalType = &localType;
        }

        mutable il_generator_type *m_pGenAsScope;
        type_metadata_type const *m_pLocalType;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASELOCALNAMEMETADATAGENERATOR_HPP