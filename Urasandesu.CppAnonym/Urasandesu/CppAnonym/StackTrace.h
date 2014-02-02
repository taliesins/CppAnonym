/* 
 * File: StackTrace.h
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
#ifndef URASANDESU_CPPANONYM_STACKTRACE_H
#define URASANDESU_CPPANONYM_STACKTRACE_H

#ifndef URASANDESU_CPPANONYM_STACKFRAME_H
#include <Urasandesu/CppAnonym/StackFrame.h>
#endif

#ifndef URASANDESU_CPPANONYM_STACKTRACEFWD_H
#include <Urasandesu/CppAnonym/StackTraceFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym {

    class StackTrace
    {
    public:
        StackTrace();
        ~StackTrace();
        void Capture(INT skipCount = 1,
                     HANDLE hProcess = ::GetCurrentProcess(), 
                     HANDLE hThread = ::GetCurrentThread(), 
                     LPCWSTR userSearchPath = L".\\", 
                     LPCONTEXT pContext = NULL);

        boost::ptr_vector<StackFrame> *GetStackFrames();
        
    private:
        HANDLE m_hProcess;
        boost::ptr_vector<StackFrame> m_frames;
    };

}}  // namespace Urasandesu { namespace CppAnonym {

#endif  // URASANDESU_CPPANONYM_STACKTRACE_H
