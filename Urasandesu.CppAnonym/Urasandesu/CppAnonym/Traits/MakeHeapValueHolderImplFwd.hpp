#pragma once
#ifndef URASANDESU_CPPANONYM_TRAITS_MAKEHEAPVALUEHOLDERIMPLFWD_HPP
#define URASANDESU_CPPANONYM_TRAITS_MAKEHEAPVALUEHOLDERIMPLFWD_HPP

namespace Urasandesu { namespace CppAnonym { namespace Traits {

    template<
        class T, 
        template<class, class> class ValueHolderImpl,
        class Tag = QuickHeapWithoutSubscriptOperator
    >
    struct MakeHeapValueHolderImpl;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Traits {

#endif  // #ifndef URASANDESU_CPPANONYM_TRAITS_MAKEHEAPVALUEHOLDERIMPLFWD_HPP