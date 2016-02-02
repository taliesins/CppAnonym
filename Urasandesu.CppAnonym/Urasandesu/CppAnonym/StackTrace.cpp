/* 
 * File: StackTrace.cpp
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

#ifndef URASANDESU_CPPANONYM_STACKFRAME_H
#include <Urasandesu/CppAnonym/StackFrame.h>
#endif

#ifndef URASANDESU_CPPANONYM_STACKTRACE_H
#include <Urasandesu/CppAnonym/StackTrace.h>
#endif

namespace Urasandesu { namespace CppAnonym {

    StackTrace::StackTrace() : 
        m_hProcess(nullptr)
    { }
    
    StackTrace::~StackTrace()
    {
        ::SymCleanup(m_hProcess);
    }

    void StackTrace::Capture(INT skipCount,
                 HANDLE hProcess, 
                 HANDLE hThread, 
                 LPCWSTR userSearchPath, 
                 LPCONTEXT pContext)
    {
        using boost::filesystem::path;
        using boost::filesystem::absolute;
        using boost::filesystem::exists;

        m_hProcess = hProcess;
        
        std::string absoluteSearchPath = absolute(userSearchPath).string();
        PSTR userSearchPath_ = exists(absoluteSearchPath) ? 
                                 const_cast<PSTR>(absoluteSearchPath.c_str()) : nullptr;

        DWORD options = ::SymGetOptions();
        options |= SYMOPT_LOAD_LINES;
        options &= ~SYMOPT_UNDNAME;
        ::SymSetOptions(options); 

        ::SymInitialize(m_hProcess, userSearchPath_, TRUE);

        STACKFRAME sf; 
        ::ZeroMemory(&sf, sizeof(STACKFRAME));
        DWORD MachineType;
#ifdef _M_IX86
        MachineType = IMAGE_FILE_MACHINE_I386;
        if (!pContext)
        {
            unsigned long instPtr;
            unsigned long stackPtr;
            unsigned long basePtr; 

            __asm call(x)
            __asm x: pop eax
            __asm mov [instPtr], eax
            __asm mov [stackPtr], esp
            __asm mov [basePtr], ebp

            sf.AddrPC.Offset = instPtr;
            sf.AddrPC.Mode = AddrModeFlat;
            sf.AddrStack.Offset = stackPtr;
            sf.AddrStack.Mode = AddrModeFlat;
            sf.AddrFrame.Offset = basePtr;
            sf.AddrFrame.Mode = AddrModeFlat;
        }
        else
        {
            sf.AddrPC.Offset = pContext->Eip;
            sf.AddrPC.Mode = AddrModeFlat;
            sf.AddrStack.Offset = pContext->Esp;
            sf.AddrStack.Mode = AddrModeFlat;
            sf.AddrFrame.Offset = pContext->Ebp;
            sf.AddrFrame.Mode = AddrModeFlat;
        }
        auto *pContext_ = static_cast<PVOID>(nullptr);
#else
        MachineType = IMAGE_FILE_MACHINE_AMD64;
        CONTEXT context;
        ::ZeroMemory(&context, sizeof(CONTEXT));
        context.ContextFlags = CONTEXT_CONTROL;
        if (!pContext)
        {
            ::RtlCaptureContext(&context);
            pContext = &context;

            sf.AddrPC.Offset = context.Rip;
            sf.AddrPC.Mode = AddrModeFlat;
            sf.AddrStack.Offset = context.Rsp;
            sf.AddrStack.Mode = AddrModeFlat;
            sf.AddrFrame.Offset = context.Rsp;
            sf.AddrFrame.Mode = AddrModeFlat;
        }
        else
        {
            sf.AddrPC.Offset = pContext->Rip;
            sf.AddrPC.Mode = AddrModeFlat;
            sf.AddrStack.Offset = pContext->Rsp;
            sf.AddrStack.Mode = AddrModeFlat;
            sf.AddrFrame.Offset = pContext->Rsp;
            sf.AddrFrame.Mode = AddrModeFlat;
        }
        auto *pContext_ = pContext;
#endif

        while (::StackWalk(MachineType, m_hProcess, hThread, &sf, pContext_, nullptr, ::SymFunctionTableAccess, ::SymGetModuleBase, nullptr) == TRUE) 
        {
            if (sf.AddrFrame.Offset == 0) 
                break;

            if (sf.AddrPC.Offset == 0) 
                continue;

            if (sf.AddrPC.Offset == sf.AddrReturn.Offset) 
                continue;

            if (0 < skipCount) 
            {
                --skipCount;
                continue;
            }

            StackFrame *pFrame = new StackFrame();
            pFrame->Init(m_hProcess, sf.AddrPC.Offset);
            m_frames.push_back(pFrame);
        }
    }

    boost::ptr_vector<StackFrame> *StackTrace::GetStackFrames()
    {
        return &m_frames;
    }

}}  // namespace Urasandesu { namespace CppAnonym {
