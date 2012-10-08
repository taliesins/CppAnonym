#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_OPERANDPARAMTYPES_H
#define URASANDESU_CPPANONYM_METADATA_OPERANDPARAMTYPES_H

#ifndef URASANDESU_CPPANONYM_SAFEENUM_HPP
#include <Urasandesu/CppAnonym/SafeEnum.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    namespace OperandParamTypesDetail {

        struct OperandParamTypesDef
        {
            enum type
            {
                OPT_INLINE_BR_TARGET, 
                OPT_INLINE_FIELD, 
                OPT_INLINE_I, 
                OPT_INLINE_I8, 
                OPT_INLINE_METHOD, 
                OPT_INLINE_NONE, 
                OPT_INLINE_R, 
                OPT_INLINE_SIG, 
                OPT_INLINE_STRING, 
                OPT_INLINE_SWITCH, 
                OPT_INLINE_TOK, 
                OPT_INLINE_TYPE, 
                OPT_INLINE_VAR, 
                OPT_SHORT_INLINE_BR_TARGET, 
                OPT_SHORT_INLINE_I, 
                OPT_SHORT_INLINE_R, 
                OPT_SHORT_INLINE_VAR, 
                OPT_UNREACHED
            };
        };

    }   // namespace OperandParamTypesDetail {

    typedef SafeEnum<OperandParamTypesDetail::OperandParamTypesDef> OperandParamTypes;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_OPERANDPARAMTYPES_H