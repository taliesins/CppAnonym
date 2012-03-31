
#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_CPPANONYMEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymException.h>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMNOTIMPLEMENTEDEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymNotImplementedException.h>
#endif

namespace Urasandesu { namespace CppAnonym {

    CppAnonymNotImplementedException::CppAnonymNotImplementedException() : 
        CppAnonymException("This process is not implemented.")
    { }

    CppAnonymNotImplementedException::CppAnonymNotImplementedException(std::string const &what) : 
        CppAnonymException(what)
    { }

    CppAnonymNotImplementedException::CppAnonymNotImplementedException(std::wstring const &what) : 
        CppAnonymException(what)
    { }

    CppAnonymNotImplementedException::CppAnonymNotImplementedException(std::string const &what, CppAnonymException &innerException) : 
        CppAnonymException(what, innerException)
    { }

    CppAnonymNotImplementedException::CppAnonymNotImplementedException(std::wstring const &what, CppAnonymException &innerException) : 
        CppAnonymException(what, innerException)
    { }
        
}}  // namespace Urasandesu { namespace CppAnonym {
