﻿/* 
 * File: CppAnonymException.h
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
#ifndef URASANDESU_CPPANONYM_CPPANONYMEXCEPTION_H
#define URASANDESU_CPPANONYM_CPPANONYMEXCEPTION_H

#ifndef URASANDESU_CPPANONYM_STACKTRACEFWD_H
#include <Urasandesu/CppAnonym/StackTraceFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym {

    typedef boost::error_info<struct tag_stack_trace, StackTrace *> ThrowStackTrace;

    class CppAnonymException : 
        public virtual boost::exception, 
        public virtual std::exception
    {
    public:
        CppAnonymException();
        CppAnonymException(std::string const &what);
        CppAnonymException(std::wstring const &what);
        CppAnonymException(std::string const &what, CppAnonymException &innerException);
        CppAnonymException(std::wstring const &what, CppAnonymException &innerException);
        virtual const char *__CLR_OR_THIS_CALL what() const;
        
    protected:
        std::string m_what;
        boost::shared_ptr<StackTrace> m_pStackTrace;
    
    private:
        void CaptureStackTrace(CppAnonymException *this_);

    };

}}  // namespace Urasandesu { namespace CppAnonym {

#endif  // URASANDESU_CPPANONYM_CPPANONYMEXCEPTION_H
