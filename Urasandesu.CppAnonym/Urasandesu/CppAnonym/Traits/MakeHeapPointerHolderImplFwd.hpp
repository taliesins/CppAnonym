#pragma once
#ifndef URASANDESU_CPPANONYM_TRAITS_MAKEHEAPPOINTERHOLDERIMPLFWD_HPP
#define URASANDESU_CPPANONYM_TRAITS_MAKEHEAPPOINTERHOLDERIMPLFWD_HPP

#ifndef URASANDESU_CPPANONYM_SIMPLEHEAPFWD_H
#include <Urasandesu/CppAnonym/SimpleHeapFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Traits {

    template<
        class T, 
        template<class, class, class> class PointerHolderImpl,
        class Tag = QuickHeapWithoutSubscriptOperator
    >
    struct MakeHeapPointerHolderImpl;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Traits {

#endif  // #ifndef URASANDESU_CPPANONYM_TRAITS_MAKEHEAPPOINTERHOLDERIMPLFWD_HPP