
#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_CPPANONYMARGUMENTEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymArgumentException.h>
#endif

namespace Urasandesu { namespace CppAnonym {

    CppAnonymArgumentException::CppAnonymArgumentException() : 
        CppAnonymException()
    {
    }

    CppAnonymArgumentException::CppAnonymArgumentException(std::string const &what) : 
        CppAnonymException(what)
    {
    }

    CppAnonymArgumentException::CppAnonymArgumentException(std::wstring const &what) : 
        CppAnonymException(what)
    {
    }

    CppAnonymArgumentException::CppAnonymArgumentException(std::string const &what, std::string const &paramName) : 
        CppAnonymException(what)
    {
        AppendMessage(m_what, paramName);
    }

    CppAnonymArgumentException::CppAnonymArgumentException(std::wstring const &what, std::wstring const &paramName) : 
        CppAnonymException(what)
    {
        AppendMessage(m_what, paramName);
    }

    CppAnonymArgumentException::CppAnonymArgumentException(std::string const &what, CppAnonymException &innerException) : 
        CppAnonymException(what, innerException)
    {
    }

    CppAnonymArgumentException::CppAnonymArgumentException(std::wstring const &what, CppAnonymException &innerException) : 
        CppAnonymException(what, innerException)
    {
    }

    CppAnonymArgumentException::CppAnonymArgumentException(std::string const &what, std::string const &paramName, CppAnonymException &innerException) : 
        CppAnonymException(what, innerException)
    {
        AppendMessage(m_what, paramName);
    }

    CppAnonymArgumentException::CppAnonymArgumentException(std::wstring const &what, std::wstring const &paramName, CppAnonymException &innerException) : 
        CppAnonymException(what, innerException)
    {
        AppendMessage(m_what, paramName);
    }

    void CppAnonymArgumentException::AppendMessage(std::string &what, std::wstring const &paramName)
    {
        AppendMessage(what, std::string(ATL::CW2A(paramName.c_str())));
    }

    void CppAnonymArgumentException::AppendMessage(std::string &what, std::string const &paramName)
    {
        what += "\r\n";
        what += "Parameter Name: ";
        what += paramName;
    }
        
}}  // namespace Urasandesu { namespace CppAnonym {
