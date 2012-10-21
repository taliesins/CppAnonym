#pragma once
#ifndef URASANDESU_CPPANONYM_TRAITS_EQUALITYCOMPARABLE_H
#define URASANDESU_CPPANONYM_TRAITS_EQUALITYCOMPARABLE_H

#ifndef URASANDESU_CPPANONYM_TRAITS_EQUALITYCOMPARABLEFWD_H
#include <Urasandesu/CppAnonym/Traits/EqualityComparableFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Traits {

    namespace EqualityComparableDetail {

        using boost::call_traits;
        using std::binary_function;

        template<class T>
        struct EqualityComparableImpl : 
            binary_function<T, T, bool>
        {
            typedef typename call_traits<T>::value_type value_type;
            typedef typename call_traits<T>::param_type param_type;
        };

    }   // namespace EqualityComparableDetail {

    template<class T>
    struct EqualityComparable : 
        EqualityComparableDetail::EqualityComparableImpl<T>
    {
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Traits {

#endif  // #ifndef URASANDESU_CPPANONYM_TRAITS_EQUALITYCOMPARABLE_H