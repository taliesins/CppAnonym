#pragma once
#ifndef URASANDESU_CPPANONYM_TRAITS_MAKEVALUEHOLDERIMPLFWD_H
#define URASANDESU_CPPANONYM_TRAITS_MAKEVALUEHOLDERIMPLFWD_H

namespace Urasandesu { namespace CppAnonym { namespace Traits {

    template<
        class T, 
        class ImplD, 
        template<class, class> class ValueHolderImpl
    >
    struct MakeValueHolderImpl;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Traits {

#endif  // #ifndef URASANDESU_CPPANONYM_TRAITS_MAKEVALUEHOLDERIMPLFWD_H