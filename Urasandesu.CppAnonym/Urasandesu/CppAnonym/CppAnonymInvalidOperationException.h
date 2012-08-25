#pragma once
#ifndef URASANDESU_CPPANONYM_CPPANONYMINVALIDOPERATIONEXCEPTION_H
#define URASANDESU_CPPANONYM_CPPANONYMINVALIDOPERATIONEXCEPTION_H

#ifndef URASANDESU_CPPANONYM_CPPANONYMEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymException.h>
#endif

namespace Urasandesu { namespace CppAnonym {

    struct CppAnonymInvalidOperationException : CppAnonymException
    {
        CppAnonymInvalidOperationException();
        CppAnonymInvalidOperationException(std::string const &what);
        CppAnonymInvalidOperationException(std::wstring const &what);
        CppAnonymInvalidOperationException(std::string const &what, CppAnonymException &innerException);
        CppAnonymInvalidOperationException(std::wstring const &what, CppAnonymException &innerException);
    };
        
}}  // namespace Urasandesu { namespace CppAnonym {

#endif  // URASANDESU_CPPANONYM_CPPANONYMINVALIDOPERATIONEXCEPTION_H