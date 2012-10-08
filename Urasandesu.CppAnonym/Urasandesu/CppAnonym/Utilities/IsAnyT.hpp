#pragma once
#ifndef URASANDESU_CPPANONYM_UTILITIES_ISANYT_HPP
#define URASANDESU_CPPANONYM_UTILITIES_ISANYT_HPP

#ifndef URASANDESU_CPPANONYM_TRAITS_PREDICATABLE_HPP
#include <Urasandesu/CppAnonym/Traits/Predicatable.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_ISANYTFWD_HPP
#include <Urasandesu/CppAnonym/Utilities/IsAnyTFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    template<class T>
    struct IsAnyT : 
        Traits::Predicatable<boost::any>
    {
        result_type operator()(param_type v) const
        {
            return !v.empty() && v.type() == typeid(T);
        }
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_ISANYT_HPP