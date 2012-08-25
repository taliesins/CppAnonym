#pragma once
#ifndef URASANDESU_CPPANONYM_UTILITIES_NULLDELETER_HPP
#define URASANDESU_CPPANONYM_UTILITIES_NULLDELETER_HPP

#ifndef URASANDESU_CPPANONYM_UTILITIES_NULLDELETERFWD_HPP
#include <Urasandesu/CppAnonym/Utilities/NullDeleterFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    template<class T>
    NullDeleter<T> MakeNullDeleter(T)
    {
        return NullDeleter<T>();
    }

    template<class T>
    struct NullDeleter
    {
        void operator()(T *p) { }
    };

    template<class T>
    struct NullDeleter<T const *>
    {
        void operator()(T const *p) { }
    };

    template<class T>
    struct NullDeleter<T *>
    {
        void operator()(T const *p) { }
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_NULLDELETER_HPP