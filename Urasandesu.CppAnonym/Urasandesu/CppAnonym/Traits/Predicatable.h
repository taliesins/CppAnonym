#pragma once
#ifndef URASANDESU_CPPANONYM_TRAITS_PREDICATABLE_H
#define URASANDESU_CPPANONYM_TRAITS_PREDICATABLE_H

#ifndef URASANDESU_CPPANONYM_TRAITS_PREDICATABLEFWD_H
#include <Urasandesu/CppAnonym/Traits/PredicatableFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Traits {

    namespace PredicatableDetail {

        using boost::call_traits;
        using std::unary_function;

        template<class T>
        struct PredicatableImpl : 
            unary_function<T, bool>
        {
            typedef typename call_traits<T>::param_type param_type;
        };

    }   // namespace PredicatableDetail {

    template<class T>
    struct Predicatable : 
        PredicatableDetail::PredicatableImpl<T>
    {
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Traits {

#endif  // #ifndef URASANDESU_CPPANONYM_TRAITS_PREDICATABLE_H