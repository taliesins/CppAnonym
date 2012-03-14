#pragma once
#ifndef URASANDESU_CPPANONYM_CPPANONYMNOTSUPPORTEDEXCEPTION_H
#define URASANDESU_CPPANONYM_CPPANONYMNOTSUPPORTEDEXCEPTION_H

#ifndef URASANDESU_CPPANONYM_CPPANONYMEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymException.h>
#endif

namespace Urasandesu { namespace CppAnonym {

    struct CppAnonymNotSupportedException : CppAnonymException
    {
        CppAnonymNotSupportedException();
        CppAnonymNotSupportedException(std::string const &what);
        CppAnonymNotSupportedException(std::wstring const &what);
        CppAnonymNotSupportedException(std::string const &what, CppAnonymException &innerException);
        CppAnonymNotSupportedException(std::wstring const &what, CppAnonymException &innerException);
    };
        
}}  // namespace Urasandesu { namespace CppAnonym {

#endif  // URASANDESU_CPPANONYM_CPPANONYMNOTSUPPORTEDEXCEPTION_H