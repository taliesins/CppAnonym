
#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_CPPANONYMNOTSUPPORTEDEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymNotSupportedException.h>
#endif

namespace Urasandesu { namespace CppAnonym {

    CppAnonymNotSupportedException::CppAnonymNotSupportedException() : 
        CppAnonymException()
    { }

    CppAnonymNotSupportedException::CppAnonymNotSupportedException(std::string const &what) : 
        CppAnonymException(what)
    { }

    CppAnonymNotSupportedException::CppAnonymNotSupportedException(std::wstring const &what) : 
        CppAnonymException(what)
    { }

    CppAnonymNotSupportedException::CppAnonymNotSupportedException(std::string const &what, CppAnonymException &innerException) : 
        CppAnonymException(what, innerException)
    { }

    CppAnonymNotSupportedException::CppAnonymNotSupportedException(std::wstring const &what, CppAnonymException &innerException) : 
        CppAnonymException(what, innerException)
    { }
        
}}  // namespace Urasandesu { namespace CppAnonym {
