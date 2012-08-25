#pragma once
#ifndef URASANDESU_CPPANONYM_CPPANONYMOBJECTDISPOSEDEXCEPTION_H
#define URASANDESU_CPPANONYM_CPPANONYMOBJECTDISPOSEDEXCEPTION_H

#ifndef URASANDESU_CPPANONYM_CPPANONYMEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymException.h>
#endif

namespace Urasandesu { namespace CppAnonym {

    struct CppAnonymObjectDisposedException : CppAnonymException
    {
        CppAnonymObjectDisposedException();
        CppAnonymObjectDisposedException(std::string const &what);
        CppAnonymObjectDisposedException(std::wstring const &what);
        CppAnonymObjectDisposedException(std::string const &what, CppAnonymException &innerException);
        CppAnonymObjectDisposedException(std::wstring const &what, CppAnonymException &innerException);
    };
        
}}  // namespace Urasandesu { namespace CppAnonym {

#endif  // URASANDESU_CPPANONYM_CPPANONYMOBJECTDISPOSEDEXCEPTION_H