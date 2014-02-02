/* 
 * File: CppAnonymArgumentException.cpp
 * 
 * Author: Akira Sugiura (urasandesu@gmail.com)
 * 
 * 
 * Copyright (c) 2014 Akira Sugiura
 *  
 *  This software is MIT License.
 *  
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *  
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 *  
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 *  THE SOFTWARE.
 */



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
