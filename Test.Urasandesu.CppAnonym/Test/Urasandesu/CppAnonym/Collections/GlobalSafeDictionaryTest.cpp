/* 
 * File: GlobalSafeDictionaryTest.cpp
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

#ifndef URASANDESU_CPPANONYM_CPPANONYMNOTIMPLEMENTEDEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymNotImplementedException.h>
#endif

#ifndef URASANDESU_CPPANONYM_COLLECTIONS_GLOBALSAFEDICTIONARY_H
#include <Urasandesu/CppAnonym/Collections/GlobalSafeDictionary.h>
#endif

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_Collections_GlobalSafeDictionaryTest.*
namespace {

    CPPANONYM_TEST(Urasandesu_CppAnonym_Collections_GlobalSafeDictionaryTest, Test_01)
    {
        using namespace Urasandesu::CppAnonym::Collections;
        using namespace std;

        typedef GlobalSafeDictionary<std::wstring, void const *> MyGlobalSafeDictionary;
        
        auto &instance = MyGlobalSafeDictionary::GetInstance();

        auto i = 42;

        instance.Clear();
        ASSERT_TRUE(instance.TryAdd(L"Test", &i) == TRUE);
        ASSERT_FALSE(instance.TryAdd(L"Test", &i) == TRUE);

        {
            auto *p = static_cast<int *>(nullptr);
            ASSERT_TRUE(instance.TryGet(L"Test", *const_cast<void const **>(reinterpret_cast<void **>(&p))) == TRUE);
            ASSERT_EQ(i, *p);
        }

        {
            auto *p = static_cast<int *>(nullptr);
            ASSERT_TRUE(instance.TryRemove(L"Test", *const_cast<void const **>(reinterpret_cast<void **>(&p))) == TRUE);
            ASSERT_EQ(i, *p);
        }

        {
            auto *p = static_cast<int *>(nullptr);
            ASSERT_FALSE(instance.TryGet(L"Test", *const_cast<void const **>(reinterpret_cast<void **>(&p))) == TRUE);
        }

        {
            auto *p = static_cast<int *>(nullptr);
            ASSERT_FALSE(instance.TryRemove(L"Test", *const_cast<void const **>(reinterpret_cast<void **>(&p))) == TRUE);
        }
    }



    CPPANONYM_TEST(Urasandesu_CppAnonym_Collections_GlobalSafeDictionaryTest, Test_02)
    {
        using namespace Urasandesu::CppAnonym::Collections;
        using namespace std;

        typedef GlobalSafeDictionary<std::wstring, void const *> MyGlobalSafeDictionary;
        
        auto &instance = MyGlobalSafeDictionary::GetInstance();

        auto i = 42;

        instance.Clear();

        instance.EnterDisabledProcessing();
        // DisabledProcessing mode shall NOT prohibit modifying GlobalSafeDictionary.
        ASSERT_TRUE(instance.TryAdd(L"Test", &i) == TRUE);
        ASSERT_TRUE(instance.ExitDisabledProcessing() == TRUE);

        instance.EnterDisabledProcessing();
        {
            auto *p = static_cast<int *>(nullptr);
            ASSERT_FALSE(instance.TryGet(L"Test", *const_cast<void const **>(reinterpret_cast<void **>(&p))) == TRUE);
        }
        ASSERT_TRUE(instance.ExitDisabledProcessing() == TRUE);
        {
            auto *p = static_cast<int *>(nullptr);
            ASSERT_TRUE(instance.TryGet(L"Test", *const_cast<void const **>(reinterpret_cast<void **>(&p))) == TRUE);
            ASSERT_EQ(i, *p);
        }

        instance.EnterDisabledProcessing();
        {
            // DisabledProcessing mode shall NOT prohibit modifying GlobalSafeDictionary.
            auto *p = static_cast<int *>(nullptr);
            ASSERT_TRUE(instance.TryRemove(L"Test", *const_cast<void const **>(reinterpret_cast<void **>(&p))) == TRUE);
            ASSERT_EQ(i, *p);
        }
        ASSERT_TRUE(instance.ExitDisabledProcessing() == TRUE);

        ASSERT_FALSE(instance.ExitDisabledProcessing() == TRUE);
    }



    CPPANONYM_TEST(Urasandesu_CppAnonym_Collections_GlobalSafeDictionaryTest, Test_03)
    {
        using namespace Urasandesu::CppAnonym::Collections;
        using namespace std;

        typedef GlobalSafeDictionary<std::wstring, void const *> MyGlobalSafeDictionary;
        
        auto &instance = MyGlobalSafeDictionary::GetInstance();

        ASSERT_FALSE(instance.IsDisabledProcessing() == TRUE);
        instance.EnterDisabledProcessing();
        {
            ASSERT_TRUE(instance.IsDisabledProcessing() == TRUE);
            instance.EnterDisabledProcessing();
            {
                ASSERT_TRUE(instance.IsDisabledProcessing() == TRUE);
                ASSERT_TRUE(instance.IsDisabledProcessing() == TRUE);
            }
            ASSERT_TRUE(instance.ExitDisabledProcessing() == TRUE);
            ASSERT_TRUE(instance.IsDisabledProcessing() == TRUE);
        }
        ASSERT_TRUE(instance.ExitDisabledProcessing() == TRUE);
        ASSERT_FALSE(instance.IsDisabledProcessing() == TRUE);

        ASSERT_FALSE(instance.ExitDisabledProcessing() == TRUE);
    }
}
