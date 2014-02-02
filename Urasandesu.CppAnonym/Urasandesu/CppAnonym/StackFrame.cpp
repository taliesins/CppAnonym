/* 
 * File: StackFrame.cpp
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

namespace Urasandesu { namespace CppAnonym {

    StackFrame::StackFrame() :
        m_hProcess(NULL),
        m_offset(0),
        m_symDisp(0),
        m_fileLineNum(0),
        m_fileColumnNum(0)
    { }
    
    void StackFrame::Init(HANDLE hProcess, DWORD offset)
    {
        m_hProcess = hProcess;
        m_offset = offset;
    }
    
    DWORD StackFrame::GetOffset()
    {
        return m_offset;
    }
    
    std::string const &StackFrame::GetModuleName()
    {
        if (m_modName == "")
        {
            IMAGEHLP_MODULE mod;
            ::ZeroMemory(&mod, sizeof(IMAGEHLP_MODULE));
            mod.SizeOfStruct = sizeof(IMAGEHLP_MODULE);

            m_modName = ::SymGetModuleInfo(m_hProcess, m_offset, &mod) == TRUE ? 
                                                   mod.ImageName : "<Unknown Module>";
        }
        return m_modName;    
    }
    
    std::string const &StackFrame::GetSymbolName()
    {
        FillSymbolInfoIfNecessary();
        return m_symName;
    }
    
    DWORD StackFrame::GetSymbolDisplacement()
    {
        FillSymbolInfoIfNecessary();
        return m_symDisp;
    }
    
    std::string const &StackFrame::GetFileName()
    {
        FillFileLineInfoIfNecessary();
        return m_fileName;
    }
    
    DWORD StackFrame::GetFileLineNumber()
    {
        FillFileLineInfoIfNecessary();
        return m_fileLineNum;
    }
    
    DWORD StackFrame::GetFileColumnNumber()
    {
        FillFileLineInfoIfNecessary();
        return m_fileColumnNum;
    }

    void StackFrame::FillSymbolInfoIfNecessary()
    {
        if (!HasGotSymbolInfo())
            FillSymbolInfo();
    }
    
    bool StackFrame::HasGotSymbolInfo()
    {
        return m_symName != "";
    }
    
    void StackFrame::FillSymbolInfo()
    {
        BYTE pBuf[MAX_SYM_NAME + sizeof(IMAGEHLP_SYMBOL)];
        PIMAGEHLP_SYMBOL pSym = reinterpret_cast<PIMAGEHLP_SYMBOL>(pBuf);
        ::ZeroMemory(pSym, sizeof(pBuf)); 

        pSym->SizeOfStruct = sizeof(IMAGEHLP_SYMBOL);
        pSym->MaxNameLength = MAX_SYM_NAME;

        m_symName = ::SymGetSymFromAddr(m_hProcess, m_offset, &m_symDisp, pSym) == TRUE ? 
                                                            pSym->Name : "<Unknown Symbol>";
    }

    void StackFrame::FillFileLineInfoIfNecessary()
    {
        if (!HasGotFileLineInfo())
            FillFileLineInfo();
    }
    
    bool StackFrame::HasGotFileLineInfo()
    {
        return m_fileName != "";
    }
    
    void StackFrame::FillFileLineInfo()
    {
        IMAGEHLP_LINE line;
        ::ZeroMemory(&line, sizeof(IMAGEHLP_LINE)); 
        line.SizeOfStruct = sizeof(IMAGEHLP_LINE);

        m_fileName = ::SymGetLineFromAddr(m_hProcess, m_offset, &m_fileColumnNum, &line) == TRUE ? 
                                                                    line.FileName : "<Unknown Line>";
        m_fileLineNum = line.LineNumber;
    }

}}  // namespace Urasandesu { namespace CppAnonym {
