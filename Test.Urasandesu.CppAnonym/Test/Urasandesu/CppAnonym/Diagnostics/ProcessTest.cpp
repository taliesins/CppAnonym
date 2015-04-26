/* 
 * File: ProcessTest.cpp
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

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_Diagnostics_ProcessTest.*
namespace {

    CPPANONYM_TEST(Urasandesu_CppAnonym_Diagnostics_ProcessTest, StartAndWaitForExit_should_start_specified_process_and_wait_for_exit)
    {
        using boost::filesystem::current_path;
        using boost::filesystem::path;
        using boost::filesystem::unique_path;
        using std::wifstream;
        using std::wstring;
        using namespace Urasandesu::CppAnonym::Diagnostics;

        // Arrange
        auto fileName = wstring(L"powershell");
        auto resultName = unique_path().native() + L".txt";
        auto arguments = wstring(L"-NoLogo -NoProfile -Command \"& { $pwd.Path | Out-File ") + resultName + L" -Encoding default }\"";


        // Act
        auto exitCode = Process::StartAndWaitForExit(fileName, arguments);


        // Assert
        ASSERT_EQ(0, exitCode);
        auto ifs = wifstream(resultName);
        auto data = path();
        ifs >> data;
        ASSERT_EQ(current_path(), data);
    }
}
