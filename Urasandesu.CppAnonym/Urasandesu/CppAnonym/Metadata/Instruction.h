#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_INSTRUCTION_H
#define URASANDESU_CPPANONYM_METADATA_INSTRUCTION_H

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    class OpCode;

    class Instruction
    {
    public:
        inline Instruction() { }
    
        inline OpCode const &GetOpCode() const
        {
            //_ASSERTE(reinterpret_cast<size_t>(m_pOpCode) != 0xCCCCCCCC);
            return *m_pOpCode;
        }
        
        inline void SetOpCode(OpCode const &opCode)
        {
            m_pOpCode = &opCode;
        }

        inline boost::any const &GetOprand() const
        {
            return m_oprand;
        }

        inline void SetOprand(boost::any const &oprand)
        {
            m_oprand = oprand;
        }

    private:
        OpCode const *m_pOpCode;
        boost::any m_oprand;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_INSTRUCTION_H