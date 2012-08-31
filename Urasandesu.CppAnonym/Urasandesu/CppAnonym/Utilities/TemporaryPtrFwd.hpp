#pragma once
#ifndef URASANDESU_CPPANONYM_UTILITIES_TEMPORARYPTRFWD_HPP
#define URASANDESU_CPPANONYM_UTILITIES_TEMPORARYPTRFWD_HPP

#ifndef URASANDESU_CPPANONYM_UTILITIES_DEFAULTDELETERFWD_HPP
#include <Urasandesu/CppAnonym/Utilities/DefaultDeleterFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    template<class T, class Tag, class D = DefaultDeleter>
    class TemporaryPtr;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_TEMPORARYPTRFWD_HPP