#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETHODMETADATAPROTOB8DF5A21_H
#define URASANDESU_CPPANONYM_METADATA_BASEMETHODMETADATAPROTOB8DF5A21_H

#ifndef URASANDESU_CPPANONYM_IHEAPCONTENT_H
#include <Urasandesu/CppAnonym/IHeapContent.h>
#endif

#ifndef URASANDESU_CPPANONYM_SAFEENUM_H
#include <Urasandesu/CppAnonym/SafeEnum.h>
#endif

namespace Urasandesu { namespace CppAnonym {

    class SimpleBlob;

}}  // namespace Urasandesu { namespace CppAnonym {

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    namespace Detail {

        struct OpCodeTypesDef
        {
            enum type
            {
#define OPDEF(canonicalName, stringName, stackBehaviour0, stackBehaviour1, \
                operandParams, opcodeKind, length, byte1, byte2, controlFlow) \
                canonicalName,
#include "opcode.def"
#undef OPDEF
                CEE_UNREACHED
            };
        };

        struct StackBehaviourTypesDef
        {
            enum type
            {
                SBT_POP0, 
                SBT_POP1, 
                SBT_POP_I, 
                SBT_POP_I8, 
                SBT_POP_R4, 
                SBT_POP_R8, 
                SBT_POP_REF, 
                SBT_PUSH0, 
                SBT_PUSH1, 
                SBT_PUSH_I, 
                SBT_PUSH_I8, 
                SBT_PUSH_R4, 
                SBT_PUSH_R8, 
                SBT_PUSH_REF, 
                SBT_VAR_POP, 
                SBT_VAR_PUSH, 
                SBT_UNREACHED
            };
        };

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

        struct OpcodeKindTypesDef
        {
            enum type
            {
                OKT_I_INTERNAL, 
                OKT_I_MACRO, 
                OKT_I_OBJ_MODEL, 
                OKT_I_PREFIX, 
                OKT_I_PRIMITIVE, 
                OKT_UNREACHED
            };
        };

        struct ControlFlowTypesDef
        {
            enum type
            {
                CFT_BRANCH, 
                CFT_BREAK, 
                CFT_CALL, 
                CFT_COND_BRANCH, 
                CFT_META, 
                CFT_NEXT, 
                CFT_RETURN, 
                CFT_THROW, 
                CFT_UNREACHED
            };
        };

    }   // Detail

    typedef SafeEnum<Detail::OpCodeTypesDef> OpCodeTypes;
    typedef SafeEnum<Detail::StackBehaviourTypesDef> StackBehaviourTypes;
    typedef SafeEnum<Detail::OperandParamTypesDef> OperandParamTypes;
    typedef SafeEnum<Detail::OpcodeKindTypesDef> OpcodeKindTypes;
    typedef SafeEnum<Detail::ControlFlowTypesDef> ControlFlowTypes;

    struct StackBehaviour
    {
        StackBehaviour(StackBehaviourTypes const &type)
        { }

        StackBehaviour operator +(StackBehaviour const &other) const
        {
            return StackBehaviour(StackBehaviourTypes::SBT_POP0);
        }
    };

    struct StackBehaviours
    {
        static const StackBehaviour Pop0;
        static const StackBehaviour Pop1;
        static const StackBehaviour PopI;
        static const StackBehaviour PopI8;
        static const StackBehaviour PopR4;
        static const StackBehaviour PopR8;
        static const StackBehaviour PopRef;
        static const StackBehaviour Push0;
        static const StackBehaviour Push1;
        static const StackBehaviour PushI;
        static const StackBehaviour PushI8;
        static const StackBehaviour PushR4;
        static const StackBehaviour PushR8;
        static const StackBehaviour PushRef;
        static const StackBehaviour VarPop;
        static const StackBehaviour VarPush;
    };

    const StackBehaviour StackBehaviours::Pop0 = StackBehaviour(StackBehaviourTypes::SBT_POP0);
    const StackBehaviour StackBehaviours::Pop1 = StackBehaviour(StackBehaviourTypes::SBT_POP1);
    const StackBehaviour StackBehaviours::PopI = StackBehaviour(StackBehaviourTypes::SBT_POP_I);
    const StackBehaviour StackBehaviours::PopI8 = StackBehaviour(StackBehaviourTypes::SBT_POP_I8);
    const StackBehaviour StackBehaviours::PopR4 = StackBehaviour(StackBehaviourTypes::SBT_POP_R4);
    const StackBehaviour StackBehaviours::PopR8 = StackBehaviour(StackBehaviourTypes::SBT_POP_R8);
    const StackBehaviour StackBehaviours::PopRef = StackBehaviour(StackBehaviourTypes::SBT_POP_REF);
    const StackBehaviour StackBehaviours::Push0 = StackBehaviour(StackBehaviourTypes::SBT_PUSH0);
    const StackBehaviour StackBehaviours::Push1 = StackBehaviour(StackBehaviourTypes::SBT_PUSH1);
    const StackBehaviour StackBehaviours::PushI = StackBehaviour(StackBehaviourTypes::SBT_PUSH_I);
    const StackBehaviour StackBehaviours::PushI8 = StackBehaviour(StackBehaviourTypes::SBT_PUSH_I8);
    const StackBehaviour StackBehaviours::PushR4 = StackBehaviour(StackBehaviourTypes::SBT_PUSH_R4);
    const StackBehaviour StackBehaviours::PushR8 = StackBehaviour(StackBehaviourTypes::SBT_PUSH_R8);
    const StackBehaviour StackBehaviours::PushRef = StackBehaviour(StackBehaviourTypes::SBT_PUSH_REF);
    const StackBehaviour StackBehaviours::VarPop = StackBehaviour(StackBehaviourTypes::SBT_VAR_POP);
    const StackBehaviour StackBehaviours::VarPush = StackBehaviour(StackBehaviourTypes::SBT_VAR_PUSH);

    struct OperandParam
    {
        OperandParam(OperandParamTypes const &type)
        { }
    };

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

    const OperandParam OperandParams::InlineBrTarget = OperandParam(OperandParamTypes::OPT_INLINE_BR_TARGET);
    const OperandParam OperandParams::InlineField = OperandParam(OperandParamTypes::OPT_INLINE_FIELD);
    const OperandParam OperandParams::InlineI = OperandParam(OperandParamTypes::OPT_INLINE_I);
    const OperandParam OperandParams::InlineI8 = OperandParam(OperandParamTypes::OPT_INLINE_I8);
    const OperandParam OperandParams::InlineMethod = OperandParam(OperandParamTypes::OPT_INLINE_METHOD);
    const OperandParam OperandParams::InlineNone = OperandParam(OperandParamTypes::OPT_INLINE_NONE);
    const OperandParam OperandParams::InlineR = OperandParam(OperandParamTypes::OPT_INLINE_R);
    const OperandParam OperandParams::InlineSig = OperandParam(OperandParamTypes::OPT_INLINE_SIG);
    const OperandParam OperandParams::InlineString = OperandParam(OperandParamTypes::OPT_INLINE_STRING);
    const OperandParam OperandParams::InlineSwitch = OperandParam(OperandParamTypes::OPT_INLINE_SWITCH);
    const OperandParam OperandParams::InlineTok = OperandParam(OperandParamTypes::OPT_INLINE_TOK);
    const OperandParam OperandParams::InlineType = OperandParam(OperandParamTypes::OPT_INLINE_TYPE);
    const OperandParam OperandParams::InlineVar = OperandParam(OperandParamTypes::OPT_INLINE_VAR);
    const OperandParam OperandParams::ShortInlineBrTarget = OperandParam(OperandParamTypes::OPT_SHORT_INLINE_BR_TARGET);
    const OperandParam OperandParams::ShortInlineI = OperandParam(OperandParamTypes::OPT_SHORT_INLINE_I);
    const OperandParam OperandParams::ShortInlineR = OperandParam(OperandParamTypes::OPT_SHORT_INLINE_R);
    const OperandParam OperandParams::ShortInlineVar = OperandParam(OperandParamTypes::OPT_SHORT_INLINE_VAR);

    struct OpcodeKind
    {
        OpcodeKind(OpcodeKindTypes const &type)
        { }
    };

    struct OpcodeKinds
    {
        static const OpcodeKind IInternal;
        static const OpcodeKind IMacro;
        static const OpcodeKind IObjModel;
        static const OpcodeKind IPrefix;
        static const OpcodeKind IPrimitive;
    };

    const OpcodeKind OpcodeKinds::IInternal = OpcodeKind(OpcodeKindTypes::OKT_I_INTERNAL);
    const OpcodeKind OpcodeKinds::IMacro = OpcodeKind(OpcodeKindTypes::OKT_I_MACRO);
    const OpcodeKind OpcodeKinds::IObjModel = OpcodeKind(OpcodeKindTypes::OKT_I_OBJ_MODEL);
    const OpcodeKind OpcodeKinds::IPrefix = OpcodeKind(OpcodeKindTypes::OKT_I_PREFIX);
    const OpcodeKind OpcodeKinds::IPrimitive = OpcodeKind(OpcodeKindTypes::OKT_I_PRIMITIVE);

    struct ControlFlow
    {
        ControlFlow(ControlFlowTypes const &type)
        { }
    };

    struct ControlFlows
    {
        static const ControlFlow Branch;
        static const ControlFlow Break;
        static const ControlFlow Call;
        static const ControlFlow CondBranch;
        static const ControlFlow Meta;
        static const ControlFlow Next;
        static const ControlFlow Return;
        static const ControlFlow Throw;
    };

    const ControlFlow ControlFlows::Branch = ControlFlow(ControlFlowTypes::CFT_BRANCH);
    const ControlFlow ControlFlows::Break = ControlFlow(ControlFlowTypes::CFT_BREAK);
    const ControlFlow ControlFlows::Call = ControlFlow(ControlFlowTypes::CFT_CALL);
    const ControlFlow ControlFlows::CondBranch = ControlFlow(ControlFlowTypes::CFT_COND_BRANCH);
    const ControlFlow ControlFlows::Meta = ControlFlow(ControlFlowTypes::CFT_META);
    const ControlFlow ControlFlows::Next = ControlFlow(ControlFlowTypes::CFT_NEXT);
    const ControlFlow ControlFlows::Return = ControlFlow(ControlFlowTypes::CFT_RETURN);
    const ControlFlow ControlFlows::Throw = ControlFlow(ControlFlowTypes::CFT_THROW);

    class OpCodeProtoB8DF5A21 : 
        boost::noncopyable
    {
    public:
        OpCodeProtoB8DF5A21(OpCodeTypes const &type, 
                            std::wstring const &name, 
                            StackBehaviour const &behaviour0, 
                            StackBehaviour const &behaviour1, 
                            OperandParam const &operandParam, 
                            OpcodeKind const &opcodeKind, 
                            BYTE length, 
                            BYTE byte1,
                            BYTE byte2, 
                            ControlFlow const &controlFlow)
        { }

        wchar_t const *CStr() const
        {
            return m_cstr.c_str();
        }

    private:
        std::wstring m_cstr;
    };

    template<int type>
    class OpCode_ProtoB8DF5A21;
#define Pop0 StackBehaviours::Pop0
#define Pop1 StackBehaviours::Pop1
#define PopI StackBehaviours::PopI
#define PopI8 StackBehaviours::PopI8
#define PopR4 StackBehaviours::PopR4
#define PopR8 StackBehaviours::PopR8
#define PopRef StackBehaviours::PopRef
#define Push0 StackBehaviours::Push0
#define Push1 StackBehaviours::Push1
#define PushI StackBehaviours::PushI
#define PushI8 StackBehaviours::PushI8
#define PushR4 StackBehaviours::PushR4
#define PushR8 StackBehaviours::PushR8
#define PushRef StackBehaviours::PushRef
#define VarPop StackBehaviours::VarPop
#define VarPush StackBehaviours::VarPush
#define InlineBrTarget OperandParams::InlineBrTarget
#define InlineField OperandParams::InlineField
#define InlineI OperandParams::InlineI
#define InlineI8 OperandParams::InlineI8
#define InlineMethod OperandParams::InlineMethod
#define InlineNone OperandParams::InlineNone
#define InlineR OperandParams::InlineR
#define InlineSig OperandParams::InlineSig
#define InlineString OperandParams::InlineString
#define InlineSwitch OperandParams::InlineSwitch
#define InlineTok OperandParams::InlineTok
#define InlineType OperandParams::InlineType
#define InlineVar OperandParams::InlineVar
#define ShortInlineBrTarget OperandParams::ShortInlineBrTarget
#define ShortInlineI OperandParams::ShortInlineI
#define ShortInlineR OperandParams::ShortInlineR
#define ShortInlineVar OperandParams::ShortInlineVar
#define IInternal OpcodeKinds::IInternal
#define IMacro OpcodeKinds::IMacro
#define IObjModel OpcodeKinds::IObjModel
#define IPrefix OpcodeKinds::IPrefix
#define IPrimitive OpcodeKinds::IPrimitive
#define BRANCH ControlFlows::Branch
#define BREAK ControlFlows::Break
#define CALL ControlFlows::Call
#define COND_BRANCH ControlFlows::CondBranch
#define META ControlFlows::Meta
#define NEXT ControlFlows::Next
#define RETURN ControlFlows::Return
#define THROW ControlFlows::Throw
#define OPDEF(canonicalName, stringName, stackBehaviour0, stackBehaviour1, \
                operandParam, opcodeKind, length, byte1, byte2, controlFlow) \
    template<> \
    class OpCode_ProtoB8DF5A21<OpCodeTypes::canonicalName> : public OpCodeProtoB8DF5A21 \
    { \
    public: \
        OpCode_ProtoB8DF5A21() : \
            OpCodeProtoB8DF5A21(OpCodeTypes::canonicalName, L"" L##stringName L"", \
                                stackBehaviour0, stackBehaviour1, \
                                operandParam, opcodeKind, length, byte1, byte2, controlFlow) \
        { } \
    };
#include "opcode.def"
#undef THROW
#undef RETURN
#undef NEXT
#undef META
#undef COND_BRANCH
#undef CALL
#undef BREAK
#undef BRANCH
#undef OPDEF
#undef IPrimitive
#undef IPrefix
#undef IObjModel
#undef IMacro
#undef IInternal
#undef ShortInlineVar
#undef ShortInlineR
#undef ShortInlineI
#undef ShortInlineBrTarget
#undef InlineVar
#undef InlineType
#undef InlineTok
#undef InlineSwitch
#undef InlineString
#undef InlineSig
#undef InlineR
#undef InlineNone
#undef InlineMethod
#undef InlineI8
#undef InlineI
#undef InlineField
#undef InlineBrTarget
#undef VarPush
#undef VarPop
#undef PushRef
#undef PushR8
#undef PushR4
#undef PushI8
#undef PushI
#undef Push1
#undef Push0
#undef PopRef
#undef PopR8
#undef PopR4
#undef PopI8
#undef PopI
#undef Pop1
#undef Pop0

    struct OpCodesProtoB8DF5A21
    {
#define OPDEF_EX(canonicalName, canonicalNameEx) \
        static OpCode_ProtoB8DF5A21<OpCodeTypes::canonicalName> canonicalNameEx;
#include <Urasandesu/CppAnonym/Metadata/OpCodeEx.def>
#undef OPDEF_EX
    };

#define OPDEF_EX(canonicalName, canonicalNameEx) \
    OpCode_ProtoB8DF5A21<OpCodeTypes::canonicalName> OpCodesProtoB8DF5A21::canonicalNameEx = OpCode_ProtoB8DF5A21<OpCodeTypes::canonicalName>();
#include <Urasandesu/CppAnonym/Metadata/OpCodeEx.def>
#undef OPDEF_EX




    struct DefaultMethodMetadataApiProtoB8DF5A21;

    struct ITypeMetadataApi;

    template<
        class TypeMetadataApiType
    >    
    class BaseTypeMetadataProtoB8DF5A21;


    template<
        class MethodMetadataApiType = DefaultMethodMetadataApiProtoB8DF5A21
    >    
    class BaseMethodMetadataProtoB8DF5A21 : 
        public IHeapContent<mdToken>
    {
    public:
        typedef BaseMethodMetadataProtoB8DF5A21<MethodMetadataApiType> this_type;
        typedef typename Traits::ParentApiOrDefault<MethodMetadataApiType, ITypeMetadataApi>::type type_metadata_api_type;
        typedef BaseTypeMetadataProtoB8DF5A21<type_metadata_api_type> type_metadata_type;
        typedef typename Traits::ChildApiOrDefault<MethodMetadataApiType, IMetaDataImport2>::type metadata_import_api_type;
        
        void Init(type_metadata_type &typeMeta, metadata_import_api_type &metaImpApi) const
        {
        }

        mdToken GetToken() const
        {
            return GetKey();
        }
    };

    typedef BaseMethodMetadataProtoB8DF5A21<> MethodMetadataProtoB8DF5A21;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASEMETHODMETADATAPROTOB8DF5A21_H