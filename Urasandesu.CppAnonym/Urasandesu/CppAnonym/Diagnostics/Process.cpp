/* 
 * File: Process.cpp
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

#ifndef URASANDESU_CPPANONYM_DIAGNOSTICS_PROCESS_H
#include <Urasandesu/CppAnonym/Diagnostics/Process.h>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMSYSTEMEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymSystemException.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Diagnostics {

    namespace ProcessDetail {

        using std::vector;

        void FillCommandLine(wstring const &fileName, wstring const &arguments, vector<WCHAR> &commandLine)
        {
            using boost::algorithm::join_if;

            auto v = vector<wstring>();
            v.push_back(L"\"" + fileName + L"\"");
            v.push_back(arguments);

            auto joined = join_if(v, L" ", [](wstring const &s) { return !s.empty(); });
            commandLine = vector<WCHAR>(joined.c_str(), joined.c_str() + joined.size() + 1u);
        }

        DWORD Process::StartAndWaitForExit(wstring const &fileName, wstring const &arguments, DWORD dwMilliseconds)
        {
            using boost::filesystem::path;

            auto processInfo = PROCESS_INFORMATION();
            ::ZeroMemory(&processInfo, sizeof(PROCESS_INFORMATION));
            BOOST_SCOPE_EXIT((&processInfo))
            {
                if (processInfo.hThread)
                    ::CloseHandle(processInfo.hThread);

                if (processInfo.hProcess)
                    ::CloseHandle(processInfo.hProcess);
            }
            BOOST_SCOPE_EXIT_END

            auto startupInfo = STARTUPINFO();
            ::ZeroMemory(&startupInfo, sizeof(STARTUPINFO));
            startupInfo.cb = sizeof(STARTUPINFO);

            auto commandLine = vector<WCHAR>();
            FillCommandLine(fileName, arguments, commandLine);

            if(!::CreateProcess(nullptr, &commandLine[0], nullptr, nullptr, FALSE, 0, nullptr, nullptr, &startupInfo, &processInfo))
                BOOST_THROW_EXCEPTION(CppAnonymSystemException(::GetLastError()));

            ::WaitForSingleObject(processInfo.hProcess, dwMilliseconds);

            auto exitCode = 0ul;
            if (!::GetExitCodeProcess(processInfo.hProcess, &exitCode))
                BOOST_THROW_EXCEPTION(CppAnonymSystemException(::GetLastError()));

            return exitCode;
        }
        
    }   // namespace ProcessDetail {

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Diagnostics {
