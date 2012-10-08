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
                ObjectTag<Instruction, VeryQuickHeapButMustUseSubscriptOperator>, 
                ObjectTag<typename ILGeneratorApiAt<ILGeneratorApiHolder, Interfaces::LocalNameMetadataGeneratorLabel>::type, QuickHeap>
            >
        >
    {
    public:
        typedef BaseILGenerator<ILGeneratorApiHolder> this_type;

        typedef typename ILGeneratorApiAt<ILGeneratorApiHolder, Interfaces::MethodMetadataLabel>::type method_metadata_type;
        typedef typename ILGeneratorApiAt<ILGeneratorApiHolder, Interfaces::MethodNameMetadataGeneratorLabel>::type method_name_metadata_generator_type;
        typedef typename ILGeneratorApiAt<ILGeneratorApiHolder, Interfaces::MethodNameMetadataLabel>::type method_name_metadata_type;
        typedef typename ILGeneratorApiAt<ILGeneratorApiHolder, Interfaces::TypeMetadataLabel>::type type_metadata_type;
        //typedef typename ILGeneratorApiAt<ILGeneratorApiHolder, Interfaces::AssemblyMetadataLabel>::type assembly_metadata_type;
        typedef typename ILGeneratorApiAt<ILGeneratorApiHolder, Interfaces::AssemblyNameMetadataLabel>::type assembly_name_metadata_type;
        typedef typename ILGeneratorApiAt<ILGeneratorApiHolder, Interfaces::TypeNameMetadataLabel>::type type_name_metadata_type;
        typedef typename ILGeneratorApiAt<ILGeneratorApiHolder, Interfaces::MetadataDispenserLabel>::type metadata_dispenser_type;
        typedef typename ILGeneratorApiAt<ILGeneratorApiHolder, Interfaces::FieldNameMetadataGeneratorLabel>::type field_name_metadata_generator_type;
        typedef typename ILGeneratorApiAt<ILGeneratorApiHolder, Interfaces::LocalNameMetadataGeneratorLabel>::type local_name_metadata_generator_type;

        typedef ObjectTag<Instruction, VeryQuickHeapButMustUseSubscriptOperator> instruction_obj_tag_type;
        typedef typename type_decided_by<instruction_obj_tag_type>::type instruction_heap_type;

        typedef ObjectTag<local_name_metadata_generator_type, QuickHeap> local_name_metadata_generator_obj_tag_type;
        typedef typename type_decided_by<local_name_metadata_generator_obj_tag_type>::type local_name_metadata_generator_heap_type;

        BaseILGenerator() : 
            m_pMethodNameGenAsScope(NULL),
            m_instructionsInitialized(false)
        { }
        
        void Init(method_name_metadata_generator_type &methodNameGenAsScope) const
        {
            _ASSERTE(m_pMethodNameGenAsScope == NULL);
            m_pMethodNameGenAsScope = &methodNameGenAsScope;
        }

        template<class T>
        T const &Map() const 
        { 
            //_ASSERTE(m_pModNameAsScope != NULL || m_pModAsScope != NULL);
            //if (m_pModNameAsScope != NULL)
            //    return m_pModNameAsScope->Map<T>();
            //else
            //    return m_pModAsScope->GetModuleNameCore()->Map<T>();
            _ASSERTE(m_pMethodNameGenAsScope != NULL);
            return m_pMethodNameGenAsScope->Map<T>();
        }

        template<class T>
        T &Map() { return m_pMethodMeta->Map<T>(); }
      
        template<>
        this_type const &Map<this_type>() const { return this; }
      
        template<>
        this_type &Map<this_type>() { return this; }

        local_name_metadata_generator_type *NewLocalNameMetadataGenerator(type_metadata_type const &localType)
        {
            this_type *pMutableThis = const_cast<this_type *>(this);

            local_name_metadata_generator_type *pLocalNameMetaGen = NULL;
            pLocalNameMetaGen = pMutableThis->LocalNameMetadataGeneratorHeap().New();
            pLocalNameMetaGen->Init(*pMutableThis);
            pLocalNameMetaGen->SetLocalType(localType);
            return pLocalNameMetaGen;
        }

        void EmitWriteLine(std::wstring const &s)
        {
            typedef OpCodes OpCodes;
            {
                Instruction *pInst = NewInstruction();
                pInst->SetOpCode(OpCodes::Ldstr);
                pInst->SetOprand(s);
            }
            {
                Instruction *pInst = NewInstruction();
                pInst->SetOpCode(OpCodes::Call);

                this_type const *immutableThis = this;

                metadata_dispenser_type const *pMetaDisp = immutableThis->Map<metadata_dispenser_type>();

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
        }

        void Emit(OpCode const &op)
        {
            Instruction *pInst = NewInstruction();
            pInst->SetOpCode(op);
        }

        void Emit(OpCode const &op, int val)
        {
            if (&op != &OpCodes::Ldloca)
            {
                BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
            }
            Instruction *pInst = NewInstruction();
            pInst->SetOpCode(op);
            pInst->SetOprand(val);
        }

        void Emit(OpCode const &op, field_name_metadata_generator_type const &fieldNameGen)
        {
            if (&op != &OpCodes::Ldsfld && 
                &op != &OpCodes::Stsfld)
            {
                BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
            }
            Instruction *pInst = NewInstruction();
            pInst->SetOpCode(op);
            pInst->SetOprand(&fieldNameGen);
        }

        void Emit(OpCode const &op, method_name_metadata_generator_type const &methodNameGen)
        {
            if (&op != &OpCodes::Ldftn)
            {
                BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
            }
            Instruction *pInst = NewInstruction();
            pInst->SetOpCode(op);
            pInst->SetOprand(&methodNameGen);
        }

        void Emit(OpCode const &op, method_metadata_type const &method)
        {
            if (&op != &OpCodes::Newobj && 
                &op != &OpCodes::Call)
            {
                BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
            }
            Instruction *pInst = NewInstruction();
            pInst->SetOpCode(op);
            pInst->SetOprand(&method);
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
        Instruction *NewInstruction()
        {
            m_instructionsInitialized = false;
            return InstructionHeap().New();
        }

        instruction_heap_type &InstructionHeap()
        {
            return Of<instruction_obj_tag_type>();
        }
        
        instruction_heap_type const &InstructionHeap() const
        {
            return Of<instruction_obj_tag_type>();
        }

        local_name_metadata_generator_heap_type &LocalNameMetadataGeneratorHeap()
        {
            return Of<local_name_metadata_generator_obj_tag_type>();
        }
        
        local_name_metadata_generator_heap_type const &LocalNameMetadataGeneratorHeap() const
        {
            return Of<local_name_metadata_generator_obj_tag_type>();
        }

        mutable method_name_metadata_generator_type *m_pMethodNameGenAsScope;
        mutable bool m_instructionsInitialized;
        mutable std::vector<Instruction const *> m_instructions;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASEILGENERATOR_HPP