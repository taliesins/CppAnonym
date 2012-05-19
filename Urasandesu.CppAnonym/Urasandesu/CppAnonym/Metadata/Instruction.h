#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_INSTRUCTION_H
#define URASANDESU_CPPANONYM_METADATA_INSTRUCTION_H

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    class Instruction
    {
    public:
        inline Instruction() { }
    
        inline OpCodeProtoB8DF5A21 const &GetOpCode() const
        {
            //_ASSERTE(reinterpret_cast<size_t>(m_pOpCode) != 0xCCCCCCCC);
            return *m_pOpCode;
        }
        
        inline void SetOpCode(OpCodeProtoB8DF5A21 const &opCode)
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
        OpCodeProtoB8DF5A21 const *m_pOpCode;
        boost::any m_oprand;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_INSTRUCTION_H