#pragma once
#ifndef URASANDESU_CPPANONYM_TRAITS_HASHCOMPUTABLE_H
#define URASANDESU_CPPANONYM_TRAITS_HASHCOMPUTABLE_H

#ifndef URASANDESU_CPPANONYM_TRAITS_HASHCOMPUTABLEFWD_H
#include <Urasandesu/CppAnonym/Traits/HashComputableFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Traits {

    namespace HashComputableDetail {

        using boost::call_traits;
        using std::unary_function;

        template<class T>
        struct HashComputableImpl : 
            unary_function<T, std::size_t>
        {
            typedef typename call_traits<T>::value_type value_type;
            typedef typename call_traits<T>::param_type param_type;
        };

    }   // namespace HashComputableDetail {

    template<class T>
    struct HashComputable : 
        HashComputableDetail::HashComputableImpl<T>
    {
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Traits {

#endif  // #ifndef URASANDESU_CPPANONYM_TRAITS_HASHCOMPUTABLE_H