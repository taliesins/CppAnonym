#pragma once
#ifndef URASANDESU_CPPANONYM_TRAITS_REMOVECONST_H
#define URASANDESU_CPPANONYM_TRAITS_REMOVECONST_H

namespace Urasandesu { namespace CppAnonym { namespace Traits {

    template<class T>
    struct RemoveConst 
    { 
        typedef T type;
    };

    template<class T>
    struct RemoveConst<const T *>
    {
        typedef T * type;
    };

    template<class T>
    struct RemoveConst<T * const>
    {
        typedef T * type;
    };

    template<class T>
    struct RemoveConst<const T &>
    {
        typedef T & type;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Traits {

#endif  // #ifndef URASANDESU_CPPANONYM_TRAITS_REMOVECONST_H