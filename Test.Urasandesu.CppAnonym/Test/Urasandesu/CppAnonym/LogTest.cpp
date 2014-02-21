/* 
 * File: LogTest.cpp
 * 
 * Author: Akira Sugiura (urasandesu@gmail.com)
 * 
 * 
 * Copyright (c) 2014 Akira Sugiura
 *  
 *  This software is MIT License.
 *  
 *  Permission is hereby granted, free of che, to any person obtaining a copy
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

#ifndef URASANDESU_CPPANONYM_LOG_H
#include "Urasandesu/CppAnonym/Log.h"
#endif

// set URASANDESU_CPPANONYM_LOGGING_TARGET=log
// set URASANDESU_CPPANONYM_LOGGING_BASE_NAME=app
// set URASANDESU_CPPANONYM_LOGGING_SEVERITY=0

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_LogTest.*
namespace {

    CPPANONYM_TEST(Urasandesu_CppAnonym_LogTest, DebugLogTest_01)
    {
        BOOST_LOG_FUNCTION();

        using boost::assign::operator +=;
        using std::wostringstream;
        using std::vector;

        CPPANONYM_D_LOG("An debug severity message.");
        CPPANONYM_D_LOG1("An debug severity message. %|1$d|", 1);
        CPPANONYM_D_LOG2("An debug severity message. %|1$d|, %|2$d|", 1, 2);
        CPPANONYM_D_LOG3("An debug severity message. %|1$d|, %|2$d|, %|3$d|", 1, 2, 3);
        CPPANONYM_D_LOG4("An debug severity message. %|1$d|, %|2$d|, %|3$d|, %|4$d|", 1, 2, 3, 4);
        CPPANONYM_D_LOG5("An debug severity message. %|1$d|, %|2$d|, %|3$d|, %|4$d|, %|5$d|", 1, 2, 3, 4, 5);
        CPPANONYM_D_LOGW(L"An debug severity message.");
        CPPANONYM_D_LOGW1(L"An debug severity message. %|1$d|", 1);
        CPPANONYM_D_LOGW2(L"An debug severity message. %|1$d|, %|2$d|", 1, 2);
        CPPANONYM_D_LOGW3(L"An debug severity message. %|1$d|, %|2$d|, %|3$d|", 1, 2, 3);
        CPPANONYM_D_LOGW4(L"An debug severity message. %|1$d|, %|2$d|, %|3$d|, %|4$d|", 1, 2, 3, 4);
        CPPANONYM_D_LOGW5(L"An debug severity message. %|1$d|, %|2$d|, %|3$d|, %|4$d|, %|5$d|", 1, 2, 3, 4, 5);
        BOOST_LOG_NAMED_SCOPE("New Scope");
        CPPANONYM_D_LOG("An debug severity message.");
        CPPANONYM_D_LOG1("An debug severity message. %|1$d|", 1);
        CPPANONYM_D_LOG2("An debug severity message. %|1$d|, %|2$d|", 1, 2);
        CPPANONYM_D_LOG3("An debug severity message. %|1$d|, %|2$d|, %|3$d|", 1, 2, 3);
        CPPANONYM_D_LOG4("An debug severity message. %|1$d|, %|2$d|, %|3$d|, %|4$d|", 1, 2, 3, 4);
        CPPANONYM_D_LOG5("An debug severity message. %|1$d|, %|2$d|, %|3$d|, %|4$d|, %|5$d|", 1, 2, 3, 4, 5);
        CPPANONYM_D_LOGW(L"An debug severity message.");
        CPPANONYM_D_LOGW1(L"An debug severity message. %|1$d|", 1);
        CPPANONYM_D_LOGW2(L"An debug severity message. %|1$d|, %|2$d|", 1, 2);
        CPPANONYM_D_LOGW3(L"An debug severity message. %|1$d|, %|2$d|, %|3$d|", 1, 2, 3);
        CPPANONYM_D_LOGW4(L"An debug severity message. %|1$d|, %|2$d|, %|3$d|, %|4$d|", 1, 2, 3, 4);
        CPPANONYM_D_LOGW5(L"An debug severity message. %|1$d|, %|2$d|, %|3$d|, %|4$d|, %|5$d|", 1, 2, 3, 4, 5);

        if (CPPANONYM_D_LOG_ENABLED())
        {
            auto data = vector<int>();
            data += 1, 2, 3;
            
            auto oss = wostringstream();
            oss << "debug:";
            BOOST_FOREACH (auto const &n, data)
                oss << boost::wformat(L" %|1$02x|") % n;

            CPPANONYM_D_LOG(oss.str());
        }
    }

    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_LogTest, VerboseLogTest_01)
    {
        BOOST_LOG_FUNCTION();

        using boost::assign::operator +=;
        using std::wostringstream;
        using std::vector;

        CPPANONYM_V_LOG("An verbose severity message.");
        CPPANONYM_V_LOG1("An verbose severity message. %|1$d|", 1);
        CPPANONYM_V_LOG2("An verbose severity message. %|1$d|, %|2$d|", 1, 2);
        CPPANONYM_V_LOG3("An verbose severity message. %|1$d|, %|2$d|, %|3$d|", 1, 2, 3);
        CPPANONYM_V_LOG4("An verbose severity message. %|1$d|, %|2$d|, %|3$d|, %|4$d|", 1, 2, 3, 4);
        CPPANONYM_V_LOG5("An verbose severity message. %|1$d|, %|2$d|, %|3$d|, %|4$d|, %|5$d|", 1, 2, 3, 4, 5);
        CPPANONYM_V_LOGW(L"An verbose severity message.");
        CPPANONYM_V_LOGW1(L"An verbose severity message. %|1$d|", 1);
        CPPANONYM_V_LOGW2(L"An verbose severity message. %|1$d|, %|2$d|", 1, 2);
        CPPANONYM_V_LOGW3(L"An verbose severity message. %|1$d|, %|2$d|, %|3$d|", 1, 2, 3);
        CPPANONYM_V_LOGW4(L"An verbose severity message. %|1$d|, %|2$d|, %|3$d|, %|4$d|", 1, 2, 3, 4);
        CPPANONYM_V_LOGW5(L"An verbose severity message. %|1$d|, %|2$d|, %|3$d|, %|4$d|, %|5$d|", 1, 2, 3, 4, 5);
        BOOST_LOG_NAMED_SCOPE("New Scope");
        CPPANONYM_V_LOG("An verbose severity message.");
        CPPANONYM_V_LOG1("An verbose severity message. %|1$d|", 1);
        CPPANONYM_V_LOG2("An verbose severity message. %|1$d|, %|2$d|", 1, 2);
        CPPANONYM_V_LOG3("An verbose severity message. %|1$d|, %|2$d|, %|3$d|", 1, 2, 3);
        CPPANONYM_V_LOG4("An verbose severity message. %|1$d|, %|2$d|, %|3$d|, %|4$d|", 1, 2, 3, 4);
        CPPANONYM_V_LOG5("An verbose severity message. %|1$d|, %|2$d|, %|3$d|, %|4$d|, %|5$d|", 1, 2, 3, 4, 5);
        CPPANONYM_V_LOGW(L"An verbose severity message.");
        CPPANONYM_V_LOGW1(L"An verbose severity message. %|1$d|", 1);
        CPPANONYM_V_LOGW2(L"An verbose severity message. %|1$d|, %|2$d|", 1, 2);
        CPPANONYM_V_LOGW3(L"An verbose severity message. %|1$d|, %|2$d|, %|3$d|", 1, 2, 3);
        CPPANONYM_V_LOGW4(L"An verbose severity message. %|1$d|, %|2$d|, %|3$d|, %|4$d|", 1, 2, 3, 4);
        CPPANONYM_V_LOGW5(L"An verbose severity message. %|1$d|, %|2$d|, %|3$d|, %|4$d|, %|5$d|", 1, 2, 3, 4, 5);

        if (CPPANONYM_V_LOG_ENABLED())
        {
            auto data = vector<int>();
            data += 1, 2, 3;
            
            auto oss = wostringstream();
            oss << "verbose:";
            BOOST_FOREACH (auto const &n, data)
                oss << boost::wformat(L" %|1$02x|") % n;

            CPPANONYM_V_LOG(oss.str());
        }
    }

    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_LogTest, InfoLogTest_01)
    {
        BOOST_LOG_FUNCTION();

        using boost::assign::operator +=;
        using std::wostringstream;
        using std::vector;

        CPPANONYM_I_LOG("An info severity message.");
        CPPANONYM_I_LOG1("An info severity message. %|1$d|", 1);
        CPPANONYM_I_LOG2("An info severity message. %|1$d|, %|2$d|", 1, 2);
        CPPANONYM_I_LOG3("An info severity message. %|1$d|, %|2$d|, %|3$d|", 1, 2, 3);
        CPPANONYM_I_LOG4("An info severity message. %|1$d|, %|2$d|, %|3$d|, %|4$d|", 1, 2, 3, 4);
        CPPANONYM_I_LOG5("An info severity message. %|1$d|, %|2$d|, %|3$d|, %|4$d|, %|5$d|", 1, 2, 3, 4, 5);
        CPPANONYM_I_LOGW(L"An info severity message.");
        CPPANONYM_I_LOGW1(L"An info severity message. %|1$d|", 1);
        CPPANONYM_I_LOGW2(L"An info severity message. %|1$d|, %|2$d|", 1, 2);
        CPPANONYM_I_LOGW3(L"An info severity message. %|1$d|, %|2$d|, %|3$d|", 1, 2, 3);
        CPPANONYM_I_LOGW4(L"An info severity message. %|1$d|, %|2$d|, %|3$d|, %|4$d|", 1, 2, 3, 4);
        CPPANONYM_I_LOGW5(L"An info severity message. %|1$d|, %|2$d|, %|3$d|, %|4$d|, %|5$d|", 1, 2, 3, 4, 5);
        BOOST_LOG_NAMED_SCOPE("New Scope");
        CPPANONYM_I_LOG("An info severity message.");
        CPPANONYM_I_LOG1("An info severity message. %|1$d|", 1);
        CPPANONYM_I_LOG2("An info severity message. %|1$d|, %|2$d|", 1, 2);
        CPPANONYM_I_LOG3("An info severity message. %|1$d|, %|2$d|, %|3$d|", 1, 2, 3);
        CPPANONYM_I_LOG4("An info severity message. %|1$d|, %|2$d|, %|3$d|, %|4$d|", 1, 2, 3, 4);
        CPPANONYM_I_LOG5("An info severity message. %|1$d|, %|2$d|, %|3$d|, %|4$d|, %|5$d|", 1, 2, 3, 4, 5);
        CPPANONYM_I_LOGW(L"An info severity message.");
        CPPANONYM_I_LOGW1(L"An info severity message. %|1$d|", 1);
        CPPANONYM_I_LOGW2(L"An info severity message. %|1$d|, %|2$d|", 1, 2);
        CPPANONYM_I_LOGW3(L"An info severity message. %|1$d|, %|2$d|, %|3$d|", 1, 2, 3);
        CPPANONYM_I_LOGW4(L"An info severity message. %|1$d|, %|2$d|, %|3$d|, %|4$d|", 1, 2, 3, 4);
        CPPANONYM_I_LOGW5(L"An info severity message. %|1$d|, %|2$d|, %|3$d|, %|4$d|, %|5$d|", 1, 2, 3, 4, 5);

        if (CPPANONYM_I_LOG_ENABLED())
        {
            auto data = vector<int>();
            data += 1, 2, 3;
            
            auto oss = wostringstream();
            oss << "info:";
            BOOST_FOREACH (auto const &n, data)
                oss << boost::wformat(L" %|1$02x|") % n;

            CPPANONYM_I_LOG(oss.str());
        }
    }

    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_LogTest, WarningLogTest_01)
    {
        BOOST_LOG_FUNCTION();

        using boost::assign::operator +=;
        using std::wostringstream;
        using std::vector;

        CPPANONYM_W_LOG("An warning severity message.");
        CPPANONYM_W_LOG1("An warning severity message. %|1$d|", 1);
        CPPANONYM_W_LOG2("An warning severity message. %|1$d|, %|2$d|", 1, 2);
        CPPANONYM_W_LOG3("An warning severity message. %|1$d|, %|2$d|, %|3$d|", 1, 2, 3);
        CPPANONYM_W_LOG4("An warning severity message. %|1$d|, %|2$d|, %|3$d|, %|4$d|", 1, 2, 3, 4);
        CPPANONYM_W_LOG5("An warning severity message. %|1$d|, %|2$d|, %|3$d|, %|4$d|, %|5$d|", 1, 2, 3, 4, 5);
        CPPANONYM_W_LOGW(L"An warning severity message.");
        CPPANONYM_W_LOGW1(L"An warning severity message. %|1$d|", 1);
        CPPANONYM_W_LOGW2(L"An warning severity message. %|1$d|, %|2$d|", 1, 2);
        CPPANONYM_W_LOGW3(L"An warning severity message. %|1$d|, %|2$d|, %|3$d|", 1, 2, 3);
        CPPANONYM_W_LOGW4(L"An warning severity message. %|1$d|, %|2$d|, %|3$d|, %|4$d|", 1, 2, 3, 4);
        CPPANONYM_W_LOGW5(L"An warning severity message. %|1$d|, %|2$d|, %|3$d|, %|4$d|, %|5$d|", 1, 2, 3, 4, 5);
        BOOST_LOG_NAMED_SCOPE("New Scope");
        CPPANONYM_W_LOG("An warning severity message.");
        CPPANONYM_W_LOG1("An warning severity message. %|1$d|", 1);
        CPPANONYM_W_LOG2("An warning severity message. %|1$d|, %|2$d|", 1, 2);
        CPPANONYM_W_LOG3("An warning severity message. %|1$d|, %|2$d|, %|3$d|", 1, 2, 3);
        CPPANONYM_W_LOG4("An warning severity message. %|1$d|, %|2$d|, %|3$d|, %|4$d|", 1, 2, 3, 4);
        CPPANONYM_W_LOG5("An warning severity message. %|1$d|, %|2$d|, %|3$d|, %|4$d|, %|5$d|", 1, 2, 3, 4, 5);
        CPPANONYM_W_LOGW(L"An warning severity message.");
        CPPANONYM_W_LOGW1(L"An warning severity message. %|1$d|", 1);
        CPPANONYM_W_LOGW2(L"An warning severity message. %|1$d|, %|2$d|", 1, 2);
        CPPANONYM_W_LOGW3(L"An warning severity message. %|1$d|, %|2$d|, %|3$d|", 1, 2, 3);
        CPPANONYM_W_LOGW4(L"An warning severity message. %|1$d|, %|2$d|, %|3$d|, %|4$d|", 1, 2, 3, 4);
        CPPANONYM_W_LOGW5(L"An warning severity message. %|1$d|, %|2$d|, %|3$d|, %|4$d|, %|5$d|", 1, 2, 3, 4, 5);

        if (CPPANONYM_W_LOG_ENABLED())
        {
            auto data = vector<int>();
            data += 1, 2, 3;
            
            auto oss = wostringstream();
            oss << "warning:";
            BOOST_FOREACH (auto const &n, data)
                oss << boost::wformat(L" %|1$02x|") % n;

            CPPANONYM_W_LOG(oss.str());
        }
    }

    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_LogTest, ErrorLogTest_01)
    {
        BOOST_LOG_FUNCTION();

        using boost::assign::operator +=;
        using std::wostringstream;
        using std::vector;

        CPPANONYM_E_LOG("An error severity message.");
        CPPANONYM_E_LOG1("An error severity message. %|1$d|", 1);
        CPPANONYM_E_LOG2("An error severity message. %|1$d|, %|2$d|", 1, 2);
        CPPANONYM_E_LOG3("An error severity message. %|1$d|, %|2$d|, %|3$d|", 1, 2, 3);
        CPPANONYM_E_LOG4("An error severity message. %|1$d|, %|2$d|, %|3$d|, %|4$d|", 1, 2, 3, 4);
        CPPANONYM_E_LOG5("An error severity message. %|1$d|, %|2$d|, %|3$d|, %|4$d|, %|5$d|", 1, 2, 3, 4, 5);
        CPPANONYM_E_LOGW(L"An error severity message.");
        CPPANONYM_E_LOGW1(L"An error severity message. %|1$d|", 1);
        CPPANONYM_E_LOGW2(L"An error severity message. %|1$d|, %|2$d|", 1, 2);
        CPPANONYM_E_LOGW3(L"An error severity message. %|1$d|, %|2$d|, %|3$d|", 1, 2, 3);
        CPPANONYM_E_LOGW4(L"An error severity message. %|1$d|, %|2$d|, %|3$d|, %|4$d|", 1, 2, 3, 4);
        CPPANONYM_E_LOGW5(L"An error severity message. %|1$d|, %|2$d|, %|3$d|, %|4$d|, %|5$d|", 1, 2, 3, 4, 5);
        BOOST_LOG_NAMED_SCOPE("New Scope");
        CPPANONYM_E_LOG("An error severity message.");
        CPPANONYM_E_LOG1("An error severity message. %|1$d|", 1);
        CPPANONYM_E_LOG2("An error severity message. %|1$d|, %|2$d|", 1, 2);
        CPPANONYM_E_LOG3("An error severity message. %|1$d|, %|2$d|, %|3$d|", 1, 2, 3);
        CPPANONYM_E_LOG4("An error severity message. %|1$d|, %|2$d|, %|3$d|, %|4$d|", 1, 2, 3, 4);
        CPPANONYM_E_LOG5("An error severity message. %|1$d|, %|2$d|, %|3$d|, %|4$d|, %|5$d|", 1, 2, 3, 4, 5);
        CPPANONYM_E_LOGW(L"An error severity message.");
        CPPANONYM_E_LOGW1(L"An error severity message. %|1$d|", 1);
        CPPANONYM_E_LOGW2(L"An error severity message. %|1$d|, %|2$d|", 1, 2);
        CPPANONYM_E_LOGW3(L"An error severity message. %|1$d|, %|2$d|, %|3$d|", 1, 2, 3);
        CPPANONYM_E_LOGW4(L"An error severity message. %|1$d|, %|2$d|, %|3$d|, %|4$d|", 1, 2, 3, 4);
        CPPANONYM_E_LOGW5(L"An error severity message. %|1$d|, %|2$d|, %|3$d|, %|4$d|, %|5$d|", 1, 2, 3, 4, 5);
        
        if (CPPANONYM_E_LOG_ENABLED())
        {
            auto data = vector<int>();
            data += 1, 2, 3;
            
            auto oss = wostringstream();
            oss << "error:";
            BOOST_FOREACH (auto const &n, data)
                oss << boost::wformat(L" %|1$02x|") % n;

            CPPANONYM_E_LOG(oss.str());
        }
    }

}
