#pragma once
#ifndef URASANDESU_CPPANONYM_TRAITS_EQUALITYCOMPARABLE_HPP
#define URASANDESU_CPPANONYM_TRAITS_EQUALITYCOMPARABLE_HPP

#ifndef URASANDESU_CPPANONYM_TRAITS_EQUALITYCOMPARABLEFWD_HPP
#include <Urasandesu/CppAnonym/Traits/EqualityComparableFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Traits {

    template<class T>
    struct EqualityComparable : 
        std::binary_function<T, T, bool>
    {
        typedef typename boost::call_traits<T>::param_type param_type;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Traits {

#endif  // #ifndef URASANDESU_CPPANONYM_TRAITS_EQUALITYCOMPARABLE_HPP