
#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_CPPANONYMOBJECTDISPOSEDEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymObjectDisposedException.h>
#endif

namespace Urasandesu { namespace CppAnonym {

    CppAnonymObjectDisposedException::CppAnonymObjectDisposedException() : 
        CppAnonymException("Cannot access a Disposed object.")
    { }

    CppAnonymObjectDisposedException::CppAnonymObjectDisposedException(std::string const &what) : 
        CppAnonymException(what)
    { }

    CppAnonymObjectDisposedException::CppAnonymObjectDisposedException(std::wstring const &what) : 
        CppAnonymException(what)
    { }

    CppAnonymObjectDisposedException::CppAnonymObjectDisposedException(std::string const &what, CppAnonymException &innerException) : 
        CppAnonymException(what, innerException)
    { }

    CppAnonymObjectDisposedException::CppAnonymObjectDisposedException(std::wstring const &what, CppAnonymException &innerException) : 
        CppAnonymException(what, innerException)
    { }
        
}}  // namespace Urasandesu { namespace CppAnonym {
