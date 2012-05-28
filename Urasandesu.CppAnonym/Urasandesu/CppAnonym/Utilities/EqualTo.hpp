#pragma once
#ifndef URASANDESU_CPPANONYM_UTILITIES_EQUALTO_HPP
#define URASANDESU_CPPANONYM_UTILITIES_EQUALTO_HPP

#ifndef URASANDESU_CPPANONYM_TRAITS_EQUALITYCOMPARABLE_HPP
#include <Urasandesu/CppAnonym/Traits/EqualityComparable.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_EQUALTOFWD_HPP
#include <Urasandesu/CppAnonym/Utilities/EqualToFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    template<>
    struct EqualTo<boost::filesystem::path> : 
        Traits::EqualityComparable<boost::filesystem::path>
    {
        inline result_type operator()(param_type x, param_type y) const
        {
            return boost::algorithm::iequals(x.native(), y.native());
        }
    };

    template<class T>
    struct EqualTo<T const *> : 
        Traits::EqualityComparable<T const *>
    {
        inline result_type operator()(param_type x, param_type y) const
        {
            return x == y;
        }
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_EQUALTO_HPP