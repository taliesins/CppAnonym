#pragma once
#ifndef URASANDESU_CPPANONYM_UTILITIES_DEFAULTDELETER_HPP
#define URASANDESU_CPPANONYM_UTILITIES_DEFAULTDELETER_HPP

#ifndef URASANDESU_CPPANONYM_UTILITIES_DEFAULTDELETERFWD_HPP
#include <Urasandesu/CppAnonym/Utilities/DefaultDeleterFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    struct DefaultDeleter
    {
        template<class T>
        void operator()(T *p)
        {
            delete p;
        }
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_DEFAULTDELETER_HPP