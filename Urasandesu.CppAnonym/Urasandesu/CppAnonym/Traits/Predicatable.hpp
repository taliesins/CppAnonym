#pragma once
#ifndef URASANDESU_CPPANONYM_TRAITS_PREDICATABLE_HPP
#define URASANDESU_CPPANONYM_TRAITS_PREDICATABLE_HPP

#ifndef URASANDESU_CPPANONYM_TRAITS_PREDICATABLEFWD_HPP
#include <Urasandesu/CppAnonym/Traits/PredicatableFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Traits {

    template<class T>
    struct Predicatable : 
        std::unary_function<T, bool>
    {
        typedef typename boost::call_traits<T>::param_type param_type;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Traits {

#endif  // #ifndef URASANDESU_CPPANONYM_TRAITS_PREDICATABLE_HPP