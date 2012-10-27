#pragma once
#ifndef URASANDESU_CPPANONYM_UTILITIES_DEFAULTDELETER_H
#define URASANDESU_CPPANONYM_UTILITIES_DEFAULTDELETER_H

#ifndef URASANDESU_CPPANONYM_UTILITIES_DEFAULTDELETERFWD_H
#include <Urasandesu/CppAnonym/Utilities/DefaultDeleterFwd.h>
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

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_DEFAULTDELETER_H