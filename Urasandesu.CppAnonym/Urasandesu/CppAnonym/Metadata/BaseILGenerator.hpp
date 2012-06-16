#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_BASEILGENERATOR_HPP
#define URASANDESU_CPPANONYM_METADATA_BASEILGENERATOR_HPP

#ifndef URASANDESU_CPPANONYM_TRAITS_CARTRIDGEAPISYSTEM_HPP
#include <Urasandesu/CppAnonym/Traits/CartridgeApiSystem.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_ILGENERATORAPIHOLDERLABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/ILGeneratorApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_SIMPLEHEAPPROVIDER_HPP
#include <Urasandesu/CppAnonym/SimpleHeapProvider.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INSTRUCTION_H
#include <Urasandesu/CppAnonym/Metadata/Instruction.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_METHODMETADATALABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/MethodMetadataLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_METHODNAMEMETADATALABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/MethodNameMetadataLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_TYPEMETADATALABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/TypeMetadataLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_ASSEMBLYMETADATALABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/AssemblyMetadataLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_ASSEMBLYNAMEMETADATALABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/AssemblyNameMetadataLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_TYPENAMEMETADATALABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/TypeNameMetadataLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_METADATADISPENSERLABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/MetadataDispenserLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_TYPEKINDS_H
#include <Urasandesu/CppAnonym/Metadata/TypeKinds.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_CALLINGCONVENTIONS_H
#include <Urasandesu/CppAnonym/Metadata/CallingConventions.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEILGENERATORFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseILGeneratorFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    template<class ApiCartridgesHolder, class ApiLabel>
    struct ILGeneratorApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::ILGeneratorApiHolderLabel, ApiLabel>
    {
    };

    template<
        class ILGeneratorApiHolder
    >
    class BaseILGenerator :
        public SimpleHeapProvider<
            boost::mpl::vector<
                ObjectTag<Instruction, VeryQuickHeapButMustUseSubscriptOperator>
            >
        >
    {
    public:
        typedef BaseILGenerator<ILGeneratorApiHolder> this_type;

        typedef typename ILGeneratorApiAt<ILGeneratorApiHolder, Interfaces::MethodMetadataLabel>::type method_metadata_type;
        typedef typename ILGeneratorApiAt<ILGeneratorApiHolder, Interfaces::MethodNameMetadataLabel>::type method_name_metadata_type;
        typedef typename ILGeneratorApiAt<ILGeneratorApiHolder, Interfaces::TypeMetadataLabel>::type type_metadata_type;
        typedef typename ILGeneratorApiAt<ILGeneratorApiHolder, Interfaces::AssemblyMetadataLabel>::type assembly_metadata_type;
        typedef typename ILGeneratorApiAt<ILGeneratorApiHolder, Interfaces::AssemblyNameMetadataLabel>::type assembly_name_metadata_type;
        typedef typename ILGeneratorApiAt<ILGeneratorApiHolder, Interfaces::TypeNameMetadataLabel>::type type_name_metadata_type;
        typedef typename ILGeneratorApiAt<ILGeneratorApiHolder, Interfaces::MetadataDispenserLabel>::type metadata_dispenser_type;

        typedef ObjectTag<Instruction, VeryQuickHeapButMustUseSubscriptOperator> instruction_obj_tag_type;
        typedef typename type_decided_by<instruction_obj_tag_type>::type instruction_heap_type;

        BaseILGenerator() : 
            m_pMethodMeta(NULL),
            m_instructionsInitialized(false)
        { }
        
        void Init(method_metadata_type &methodMeta) const
        {
            _ASSERTE(m_pMethodMeta == NULL);
            
            m_pMethodMeta = &methodMeta;
        }

        template<class T>
        T const *FindType() const { return static_cast<method_metadata_type const *>(m_pMethodMeta)->FindType<T>(); }

        template<class T>
        T *FindType() { return m_pMethodMeta->FindType<T>(); }
      
        template<>
        this_type const *FindType<this_type>() const { return this; }
      
        template<>
        this_type *FindType<this_type>() { return this; }

        void EmitWriteLine(std::wstring const &s)
        {
            typedef OpCodes OpCodes;
            {
                Instruction *pInst = InstructionHeap().New();
                pInst->SetOpCode(OpCodes::Ldstr);
                pInst->SetOprand(s);
            }
            {
                Instruction *pInst = InstructionHeap().New();
                pInst->SetOpCode(OpCodes::Call);

                this_type const *immutableThis = this;

                metadata_dispenser_type const *pMetaDisp = immutableThis->FindType<metadata_dispenser_type>();

                assembly_name_metadata_type const *pMSCorLibName = NULL;
                {
                    std::wstring name(L"mscorlib, Version=2.0.0.0, Culture=neutral, " 
                                      L"PublicKeyToken=b77a5c561934e089, processorArchitecture=x86");
                    pMSCorLibName = pMetaDisp->NewAssemblyName(name);
                }

                type_name_metadata_type const *pConsoleName = NULL;
                {
                    std::wstring name(L"System.Console");
                    TypeKinds kind(TypeKinds::TK_CLASS);
                    pConsoleName = pMSCorLibName->NewTypeName(name, kind);
                }

                method_name_metadata_type const *pWriteLineName = NULL;
                {
                    std::wstring name(L"WriteLine");
                    CallingConventions callingConvention(CallingConventions::CC_STANDARD);
                    type_name_metadata_type const *pRetTypeName = NULL;
                    pRetTypeName = pMSCorLibName->NewTypeName(L"System.Void", TypeKinds::TK_VOID);
                    std::vector<type_name_metadata_type const *> paramTypeNames;
                    paramTypeNames.push_back(pMSCorLibName->NewTypeName(L"System.String", TypeKinds::TK_STRING));
                    pWriteLineName = pConsoleName->NewMethodName(name, callingConvention, *pRetTypeName, paramTypeNames);
                }

                pInst->SetOprand(pWriteLineName);
            }
            m_instructionsInitialized = false;
        }

        void Emit(OpCode const &op)
        {
            Instruction *pInst = InstructionHeap().New();
            pInst->SetOpCode(op);
            m_instructionsInitialized = false;
        }

        std::vector<Instruction const *> const &GetInstructions() const
        {
            if (!m_instructionsInitialized)
            {
                SIZE_T size = InstructionHeap().Size();
                std::vector<Instruction const *> instructions(size);
                for (SIZE_T i = 0; i < size; ++i)
                    instructions[i] = InstructionHeap()[i];
                instructions.swap(m_instructions);
                m_instructionsInitialized = true;
            }
            return m_instructions;
        }

    private:
        instruction_heap_type &InstructionHeap()
        {
            return Of<instruction_obj_tag_type>();
        }
        
        instruction_heap_type const &InstructionHeap() const
        {
            return Of<instruction_obj_tag_type>();
        }

        mutable method_metadata_type *m_pMethodMeta;
        mutable bool m_instructionsInitialized;
        mutable std::vector<Instruction const *> m_instructions;
    };

    typedef BaseILGenerator<> ILGenerator;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASEILGENERATOR_HPP