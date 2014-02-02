/* 
 * File: CppAnonymArgumentException.h
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


#pragma once
#ifndef URASANDESU_CPPANONYM_CPPANONYMARGUMENTEXCEPTION_H
#define URASANDESU_CPPANONYM_CPPANONYMARGUMENTEXCEPTION_H

#ifndef URASANDESU_CPPANONYM_CPPANONYMEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymException.h>
#endif

namespace Urasandesu { namespace CppAnonym {

    class CppAnonymArgumentException : 
        public CppAnonymException
    {
    public:
        CppAnonymArgumentException();
        CppAnonymArgumentException(std::string const &what);
        CppAnonymArgumentException(std::wstring const &what);
        CppAnonymArgumentException(std::string const &what, std::string const &paramName);
        CppAnonymArgumentException(std::wstring const &what, std::wstring const &paramName);
        CppAnonymArgumentException(std::string const &what, CppAnonymException &innerException);
        CppAnonymArgumentException(std::wstring const &what, CppAnonymException &innerException);
        CppAnonymArgumentException(std::string const &what, std::string const &paramName, CppAnonymException &innerException);
        CppAnonymArgumentException(std::wstring const &what, std::wstring const &paramName, CppAnonymException &innerException);

    private:
        static void AppendMessage(std::string &what, std::wstring const &paramName);
        static void AppendMessage(std::string &what, std::string const &paramName);
    };
        
}}  // namespace Urasandesu { namespace CppAnonym {

#endif  // URASANDESU_CPPANONYM_CPPANONYMARGUMENTEXCEPTION_H
