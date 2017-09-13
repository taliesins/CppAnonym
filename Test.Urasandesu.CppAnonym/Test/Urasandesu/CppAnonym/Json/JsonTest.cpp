/* 
 * File: JsonTest.cpp
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

#ifndef URASANDESU_CPPANONYM_JSON_H
#include <Urasandesu/CppAnonym/Json.h>
#endif

#ifndef URASANDESU_CPPANONYM_IO_H
#include <Urasandesu/CppAnonym/IO.h>
#endif

#ifndef URASANDESU_CPPANONYM_DIAGNOSTICS_PROCESS_H
#include <Urasandesu/CppAnonym/Diagnostics/Process.h>
#endif

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_JsonTest.*
namespace {
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_JsonTest, LoadingPropertyTreeApis_should_load_the_json_which_is_made_by_dot_net_api)
    {
        using boost::filesystem::unique_path;
        using boost::property_tree::wptree;
        using std::wstring;
        using namespace Urasandesu::CppAnonym::Diagnostics;
        using namespace Urasandesu::CppAnonym::IO;
        using namespace Urasandesu::CppAnonym::Json;

        // Arrange
        auto fileName = wstring(L"powershell");
        auto resultName = unique_path().native() + L".txt";
        auto arguments = wstring(L"-NoLogo -NoProfile -File ..\\..\\..\\Test\\Urasandesu\\CppAnonym\\Json\\Export-TestJson.ps1 -PropertyTree -ResultName ") + resultName;
        ASSERT_EQ(0, Process::StartAndWaitForExit(fileName, arguments));

        
        // Act
        auto pt = wptree();
        FromUTF8(resultName) >> pt;

        // Assert
        auto str = pt.get<wstring>(L"root.str");
        ASSERT_EQ(wstring(L"PowerShell から書き換え！"), str);
        auto i = 0;
        BOOST_FOREACH (auto const& child, pt.get_child(L"root.values")) 
            ASSERT_EQ(++i, child.second.get<int>(L"value"));
    }



    CPPANONYM_TEST(Urasandesu_CppAnonym_JsonTest, SavingPropertyTreeApis_should_save_the_json_which_can_be_opened_by_dot_net_api)
    {
        using boost::filesystem::unique_path;
        using boost::property_tree::wptree;
        using std::wstring;
        using namespace Urasandesu::CppAnonym::Diagnostics;
        using namespace Urasandesu::CppAnonym::IO;
        using namespace Urasandesu::CppAnonym::Json;

        // Arrange
        auto resultName = unique_path().native() + L".txt";
        auto pt = wptree();
        pt.put(L"root.str", L"C++ から書き換え！");
        {
            auto valuespt = wptree();
            { auto valuept = wptree(); valuept.put(L"value", L"1"); valuespt.push_back(make_pair(L"", valuept)); }
            { auto valuept = wptree(); valuept.put(L"value", L"2"); valuespt.push_back(make_pair(L"", valuept)); }
            { auto valuept = wptree(); valuept.put(L"value", L"3"); valuespt.push_back(make_pair(L"", valuept)); }
            pt.add_child(L"root.values", valuespt); 
        }

        
        // Act
        ToUTF8(resultName) << pt;


        // Assert
        auto fileName = wstring(L"powershell");
        auto arguments = wstring(L"-NoLogo -NoProfile -File ..\\..\\..\\Test\\Urasandesu\\CppAnonym\\Json\\Import-TestJson.ps1 -PropertyTree -ResultName ") + resultName;
        ASSERT_EQ(0, Process::StartAndWaitForExit(fileName, arguments));
    }
}
