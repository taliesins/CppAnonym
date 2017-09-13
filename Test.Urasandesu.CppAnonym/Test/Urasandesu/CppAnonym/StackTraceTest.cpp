/* 
 * File: StackTraceTest.cpp
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
#include <gtest/gtest.h>

#ifndef URASANDESU_CPPANONYM_STACKFRAME_H
#include "Urasandesu/CppAnonym/StackFrame.h"
#endif

#ifndef URASANDESU_CPPANONYM_STACKTRACE_H
#include "Urasandesu/CppAnonym/StackTrace.h"
#endif

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_StackTraceTest.*
namespace {

    TEST(Urasandesu_CppAnonym_StackTraceTest, CaptureTest_Default_01)
    {
        using namespace std;
        using namespace boost;
        using namespace Urasandesu::CppAnonym;

        StackTrace stackTrace;
        stackTrace.Capture();
        ptr_vector<StackFrame> *pFrames = stackTrace.GetStackFrames();
        ASSERT_LT(0U, pFrames->size());
        for (ptr_vector<StackFrame>::iterator i = pFrames->begin(), i_end = pFrames->end(); i != i_end; ++i)
        {
            cout << format("Offset: 0x%|1|") % reinterpret_cast<void *>(i->GetOffset()) << endl;
            cout << format("Module Name: %|1|") % i->GetModuleName() << endl;
            EXPECT_STRNE("", i->GetModuleName().c_str());
            cout << format("Symbol Name: %|1|") % i->GetSymbolName() << endl;
            EXPECT_STRNE("", i->GetSymbolName().c_str());
            cout << format("File Name: %|1|") % i->GetFileName() << endl;
            EXPECT_STRNE("", i->GetFileName().c_str());
            cout << format("File Line Number: %|1|") % i->GetFileLineNumber() << endl;
            cout << format("File Column Number: %|1|") % i->GetFileColumnNumber() << endl;
        }
    }

    TEST(Urasandesu_CppAnonym_StackTraceTest, CaptureTest_Explicit_01)
    {
        using namespace std;
        using namespace boost;
        using namespace Urasandesu::CppAnonym;
        
        HANDLE hProcess = ::GetCurrentProcess();
        cout << format("Current Process Pseudo Handle: 0x%|1|") % reinterpret_cast<void *>(hProcess) << endl;
        
        HANDLE hThread = ::GetCurrentThread();
        cout << format("Current Thread Pseudo Handle: 0x%|1|") % reinterpret_cast<void *>(hThread) << endl;

        CONTEXT context;
        ::ZeroMemory(&context, sizeof(CONTEXT));

#ifdef _M_IX86
        context.ContextFlags = CONTEXT_FULL;

        unsigned long instPtr;
        unsigned long stackPtr;
        unsigned long basePtr; 

        __asm call(x)
        __asm x: pop eax
        __asm mov [instPtr], eax
        __asm mov [stackPtr], esp
        __asm mov [basePtr], ebp

        context.Eip = instPtr; 
        context.Esp = stackPtr;
        context.Ebp = basePtr;
        cout << format("Current Thread Context Eip: 0x%|1|, Ebp: 0x%|2|, Esp: 0x%|3|") % 
                    reinterpret_cast<void *>(context.Eip) % 
                    reinterpret_cast<void *>(context.Ebp) % 
                    reinterpret_cast<void *>(context.Esp) << endl;
#else
        context.ContextFlags = CONTEXT_CONTROL;

        ::RtlCaptureContext(&context);
        cout << format("Current Thread Context Rip: 0x%|1|, Rsp: 0x%|2|, Rsp: 0x%|3|") % 
                    reinterpret_cast<void *>(context.Rip) % 
                    reinterpret_cast<void *>(context.Rsp) % 
                    reinterpret_cast<void *>(context.Rsp) << endl;
#endif
        
        LPCWSTR userSearchPath = L".\\";
        boost::filesystem::path p(userSearchPath);
        cout << boost::filesystem::absolute(p) << endl;

        StackTrace stackTrace;
        stackTrace.Capture(0, hProcess, hThread, userSearchPath, &context);
        ptr_vector<StackFrame> *pFrames = stackTrace.GetStackFrames();
        ASSERT_LT(0U, pFrames->size());
        for (ptr_vector<StackFrame>::iterator i = pFrames->begin(), i_end = pFrames->end(); i != i_end; ++i)
        {
            cout << format("Offset: 0x%|1|") % reinterpret_cast<void *>(i->GetOffset()) << endl;
            cout << format("Module Name: %|1|") % i->GetModuleName() << endl;
            EXPECT_STRNE("", i->GetModuleName().c_str());
            cout << format("Symbol Name: %|1|") % i->GetSymbolName() << endl;
            EXPECT_STRNE("", i->GetSymbolName().c_str());
            cout << format("File Name: %|1|") % i->GetFileName() << endl;
            EXPECT_STRNE("", i->GetFileName().c_str());
            cout << format("File Line Number: %|1|") % i->GetFileLineNumber() << endl;
            cout << format("File Column Number: %|1|") % i->GetFileColumnNumber() << endl;
        }
    }
}
