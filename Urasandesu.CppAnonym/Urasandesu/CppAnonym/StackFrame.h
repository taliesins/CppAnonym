/* 
 * File: StackFrame.h
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
#ifndef URASANDESU_CPPANONYM_STACKFRAME_H
#define URASANDESU_CPPANONYM_STACKFRAME_H

#ifndef URASANDESU_CPPANONYM_STACKFRAMEFWD_H
#include <Urasandesu/CppAnonym/StackFrameFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym {

    class StackFrame
    {
    public:
        StackFrame();
        void Init(HANDLE hProcess, DWORD offset);
        DWORD GetOffset();
        std::string const &GetModuleName();
        std::string const &GetSymbolName();
        DWORD GetSymbolDisplacement();
        std::string const &GetFileName();
        DWORD GetFileLineNumber();
        DWORD GetFileColumnNumber();

    private:        
        void FillSymbolInfoIfNecessary();
        bool HasGotSymbolInfo();
        void FillSymbolInfo();
        void FillFileLineInfoIfNecessary();
        bool HasGotFileLineInfo();
        void FillFileLineInfo();

        HANDLE m_hProcess;
        DWORD m_offset;

        std::string m_modName;
        std::string m_symName;
        DWORD m_symDisp;
        std::string m_fileName;
        DWORD m_fileLineNum;
        DWORD m_fileColumnNum;
    };

}}  // namespace Urasandesu { namespace CppAnonym {

#endif  // URASANDESU_CPPANONYM_STACKFRAME_H
