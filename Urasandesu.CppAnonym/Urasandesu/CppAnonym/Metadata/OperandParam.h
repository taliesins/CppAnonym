#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_OPERANDPARAM_H
#define URASANDESU_CPPANONYM_METADATA_OPERANDPARAM_H

#ifndef URASANDESU_CPPANONYM_METADATA_OPERANDPARAMTYPES_H
#include "Urasandesu/CppAnonym/Metadata/OperandParamTypes.h"
#endif

#ifndef URASANDESU_CPPANONYM_SAFEENUM_HPP
#include <Urasandesu/CppAnonym/SafeEnum.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    class OperandParam
    {
    public:
        inline OperandParam(OperandParamTypes const &type) : 
            m_type(type)
        { }

        inline OperandParamTypes const &GetType() const { return m_type; }

    private:
        OperandParamTypes m_type;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_OPERANDPARAM_H