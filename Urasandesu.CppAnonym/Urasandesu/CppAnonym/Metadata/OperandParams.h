#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_OPERANDPARAMS_H
#define URASANDESU_CPPANONYM_METADATA_OPERANDPARAMS_H

#ifndef URASANDESU_CPPANONYM_METADATA_OPERANDPARAM_H
#include <Urasandesu/CppAnonym/Metadata/OperandParam.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    struct OperandParams
    {
        static const OperandParam InlineBrTarget;
        static const OperandParam InlineField;
        static const OperandParam InlineI;
        static const OperandParam InlineI8;
        static const OperandParam InlineMethod;
        static const OperandParam InlineNone;
        static const OperandParam InlineR;
        static const OperandParam InlineSig;
        static const OperandParam InlineString;
        static const OperandParam InlineSwitch;
        static const OperandParam InlineTok;
        static const OperandParam InlineType;
        static const OperandParam InlineVar;
        static const OperandParam ShortInlineBrTarget;
        static const OperandParam ShortInlineI;
        static const OperandParam ShortInlineR;
        static const OperandParam ShortInlineVar;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_OPERANDPARAMS_H