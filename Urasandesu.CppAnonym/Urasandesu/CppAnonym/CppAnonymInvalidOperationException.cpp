
#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_CPPANONYMINVALIDOPERATIONEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymInvalidOperationException.h>
#endif

namespace Urasandesu { namespace CppAnonym {

    CppAnonymInvalidOperationException::CppAnonymInvalidOperationException() : 
        CppAnonymException("Operation is not valid due to the current state of the object.")
    { }

    CppAnonymInvalidOperationException::CppAnonymInvalidOperationException(std::string const &what) : 
        CppAnonymException(what)
    { }

    CppAnonymInvalidOperationException::CppAnonymInvalidOperationException(std::wstring const &what) : 
        CppAnonymException(what)
    { }

    CppAnonymInvalidOperationException::CppAnonymInvalidOperationException(std::string const &what, CppAnonymException &innerException) : 
        CppAnonymException(what, innerException)
    { }

    CppAnonymInvalidOperationException::CppAnonymInvalidOperationException(std::wstring const &what, CppAnonymException &innerException) : 
        CppAnonymException(what, innerException)
    { }
        
}}  // namespace Urasandesu { namespace CppAnonym {
