#pragma once
#ifndef URASANDESU_CPPANONYM_UTILITIES_TYPEINFOFWD_H
#define URASANDESU_CPPANONYM_UTILITIES_TYPEINFOFWD_H

#ifndef URASANDESU_CPPANONYM_SIMPLEHEAPFWD_H
#include <Urasandesu/CppAnonym/SimpleHeapFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    namespace TypeInfoDetail {

        struct TypeInfoHolder;

        template<class Type, class ImplD>
        struct TypeInfoHolderImpl;

        template<class Type, class ImplD>
        struct MakeHolderImpl;

        template<
            class Type, 
            class Tag = QuickHeapWithoutSubscriptOperator
        >
        struct MakeHeapHolderImpl;

        class TypeInfoImpl;

    }   // namespace TypeInfoDetail {

    struct TypeInfo;

    struct TypeInfoHash;

    struct TypeInfoEqualTo;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_TYPEINFOFWD_H