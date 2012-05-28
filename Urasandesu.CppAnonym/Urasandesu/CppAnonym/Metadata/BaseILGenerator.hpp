#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_BASEILGENERATOR_HPP
#define URASANDESU_CPPANONYM_METADATA_BASEILGENERATOR_HPP

#ifndef URASANDESU_CPPANONYM_TRAITS_CARTRIDGEAPISYSTEMFWD_HPP
#include <Urasandesu/CppAnonym/Traits/CartridgeApiSystemFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_ILGENERATORAPIHOLDERLABELFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/ILGeneratorApiHolderLabelFwd.hpp>
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
        typedef typename ILGeneratorApiAt<ILGeneratorApiHolder, Interfaces::TypeMetadataLabel>::type type_metadata_type;
        typedef typename ILGeneratorApiAt<ILGeneratorApiHolder, Interfaces::AssemblyMetadataLabel>::type assembly_metadata_type;
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

        void EmitWriteLine(LPCWSTR s)
        {
            typedef OpCodes OpCodes;
            {
                Instruction *pInst = InstructionHeap().New();
                pInst->SetOpCode(OpCodes::Ldstr);
                pInst->SetOprand(std::wstring(s));
            }
            {
                Instruction *pInst = InstructionHeap().New();
                pInst->SetOpCode(OpCodes::Call);

                this_type const *immutableThis = this;

                metadata_dispenser_type const *pMetaDisp = immutableThis->FindType<metadata_dispenser_type>();
                
                std::wstring const msCorLibName(L"mscorlib, Version=2.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089");
                assembly_metadata_type const *pMSCorLib = pMetaDisp->LoadAssembly(msCorLibName);
                
                std::wstring const consoleName(L"System.Console");
                type_metadata_type const *pConsole = pMSCorLib->GetType(consoleName, TypeKinds::TK_CLASS);
                
                std::wstring const writeLineName(L"WriteLine");
                CallingConventions cc = CallingConventions::CC_STANDARD;
                type_metadata_type const *pRetType = pMSCorLib->GetType(L"System.Void", TypeKinds::TK_VOID);
                std::vector<type_metadata_type const *> paramTypes;
                paramTypes.push_back(pMSCorLib->GetType(L"System.String", TypeKinds::TK_STRING));
                method_metadata_type const *pWriteLine = pConsole->GetMethod(writeLineName, cc, pRetType, paramTypes);

                pInst->SetOprand(pWriteLine);
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