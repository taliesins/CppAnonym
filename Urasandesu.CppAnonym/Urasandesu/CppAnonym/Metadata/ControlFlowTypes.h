﻿#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_CONTROLFLOWTYPES_H
#define URASANDESU_CPPANONYM_METADATA_CONTROLFLOWTYPES_H

#ifndef URASANDESU_CPPANONYM_SAFEENUMFWD_HPP
#include <Urasandesu/CppAnonym/SafeEnumFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    namespace Detail {

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

    typedef SafeEnum<Detail::ControlFlowTypesDef> ControlFlowTypes;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_CONTROLFLOWTYPES_H