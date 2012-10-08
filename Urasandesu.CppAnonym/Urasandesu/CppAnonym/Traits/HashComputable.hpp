#pragma once
#ifndef URASANDESU_CPPANONYM_TRAITS_HASHCOMPUTABLE_HPP
#define URASANDESU_CPPANONYM_TRAITS_HASHCOMPUTABLE_HPP

#ifndef URASANDESU_CPPANONYM_TRAITS_HASHCOMPUTABLEFWD_HPP
#include <Urasandesu/CppAnonym/Traits/HashComputableFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Traits {

    template<class T>
    struct HashComputable : 
        std::unary_function<T, std::size_t>
    {
        typedef typename boost::call_traits<T>::value_type value_type;
        typedef typename boost::call_traits<T>::param_type param_type;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Traits {

#endif  // #ifndef URASANDESU_CPPANONYM_TRAITS_HASHCOMPUTABLE_HPP