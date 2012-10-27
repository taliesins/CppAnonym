#pragma once
#ifndef URASANDESU_CPPANONYM_UTILITIES_ISANYT_H
#define URASANDESU_CPPANONYM_UTILITIES_ISANYT_H

#ifndef URASANDESU_CPPANONYM_TRAITS_PREDICATABLE_H
#include <Urasandesu/CppAnonym/Traits/Predicatable.h>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_ISANYTFWD_H
#include <Urasandesu/CppAnonym/Utilities/IsAnyTFwd.h>
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

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_ISANYT_H