#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_STACKBEHAVIOURTYPES_H
#define URASANDESU_CPPANONYM_METADATA_STACKBEHAVIOURTYPES_H

#ifndef URASANDESU_CPPANONYM_SAFEENUM_HPP
#include <Urasandesu/CppAnonym/SafeEnum.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    namespace StackBehaviourTypesDetail {

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

    }   // namespace StackBehaviourTypesDetail {

    typedef SafeEnum<StackBehaviourTypesDetail::StackBehaviourTypesDef> StackBehaviourTypes;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_STACKBEHAVIOURTYPES_H