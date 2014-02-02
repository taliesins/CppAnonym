/* 
 * File: CppAnonymException.cpp
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

#ifndef URASANDESU_CPPANONYM_CPPANONYMEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymException.h>
#endif

#ifndef URASANDESU_CPPANONYM_STACKFRAME_H
#include <Urasandesu/CppAnonym/StackFrame.h>
#endif

#ifndef URASANDESU_CPPANONYM_STACKTRACE_H
#include <Urasandesu/CppAnonym/StackTrace.h>
#endif

namespace Urasandesu { namespace CppAnonym {

    CppAnonymException::CppAnonymException() : 
        m_pStackTrace(boost::make_shared<StackTrace>())
    {
        CaptureStackTrace(this);
    }
    
    CppAnonymException::CppAnonymException(std::string const &what) : 
        m_what(what),
        m_pStackTrace(boost::make_shared<StackTrace>())
    { 
        CaptureStackTrace(this);
    }
    
    CppAnonymException::CppAnonymException(std::wstring const &what) : 
        m_what(ATL::CW2A(what.c_str())),
        m_pStackTrace(boost::make_shared<StackTrace>())
    { 
        CaptureStackTrace(this);
    }
    
    CppAnonymException::CppAnonymException(std::string const &what, CppAnonymException &innerException) : 
        m_what(what),
        m_pStackTrace(boost::make_shared<StackTrace>())
    {
        CaptureStackTrace(this);
        *this << boost::errinfo_nested_exception(boost::copy_exception(innerException));
    }
    
    CppAnonymException::CppAnonymException(std::wstring const &what, CppAnonymException &innerException) : 
        m_what(ATL::CW2A(what.c_str())),
        m_pStackTrace(boost::make_shared<StackTrace>())
    {
        CaptureStackTrace(this);
        *this << boost::errinfo_nested_exception(boost::copy_exception(innerException));
    }
    
    const char *CppAnonymException::__CLR_OR_THIS_CALL what() const
    {
        return m_what.c_str();
    }

    void CppAnonymException::CaptureStackTrace(CppAnonymException *this_)
    {
        this_->m_pStackTrace->Capture(3);
        *this_ << ThrowStackTrace(this_->m_pStackTrace.get());
    }


    inline std::string to_string(StackTrace *pStackTrace)
    {
        using namespace std;
        using namespace boost;
        
        ostringstream oss;
        ptr_vector<StackFrame> *pFrames = pStackTrace->GetStackFrames();
        for (ptr_vector<StackFrame>::iterator i = pFrames->begin(), i_end = pFrames->end(); i != i_end; ++i)
        {
            oss << "at ";
            oss << i->GetSymbolName();
            oss << " in ";
            oss << i->GetModuleName();
            if (0 < i->GetFileLineNumber())
            {
                oss << "(";
                oss << i->GetFileName();
                oss << ":";
                oss << i->GetFileLineNumber();
                oss << ")";
            }
            oss << "\n";
        }
        return oss.str();
    }
        
}}  // namespace Urasandesu { namespace CppAnonym {
