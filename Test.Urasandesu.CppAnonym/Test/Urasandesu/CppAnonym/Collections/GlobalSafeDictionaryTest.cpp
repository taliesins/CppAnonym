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
#include <gtest/gtest.h>

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
        ASSERT_TRUE(instance.Empty() == TRUE);
        ASSERT_TRUE(instance.TryAdd(L"Test", &i) == TRUE);
        ASSERT_FALSE(instance.Empty() == TRUE);
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

        {
            auto *p = static_cast<int *>(nullptr);
            ASSERT_TRUE(instance.GetOrAdd(L"Test", &i, *const_cast<void const **>(reinterpret_cast<void **>(&p))) == TRUE);
            ASSERT_EQ(i, *p);

            auto j = 100;
            ASSERT_TRUE(instance.GetOrAdd(L"Test", &j, *const_cast<void const **>(reinterpret_cast<void **>(&p))) == TRUE);
            ASSERT_EQ(i, *p);
        }

        {
            auto *p = static_cast<int *>(nullptr);
            ASSERT_TRUE(instance.TryRemove(L"Test", *const_cast<void const **>(reinterpret_cast<void **>(&p))) == TRUE);
            ASSERT_EQ(i, *p);
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

        instance.EnterDisabledProcessing();
        {
            // DisabledProcessing mode shall NOT prohibit modifying GlobalSafeDictionary.
            auto *p = static_cast<int *>(nullptr);
            ASSERT_FALSE(instance.GetOrAdd(L"Test", &i, *const_cast<void const **>(reinterpret_cast<void **>(&p))) == TRUE);
        }
        ASSERT_TRUE(instance.ExitDisabledProcessing() == TRUE);
        {
            auto *p = static_cast<int *>(nullptr);
            ASSERT_TRUE(instance.TryGet(L"Test", *const_cast<void const **>(reinterpret_cast<void **>(&p))) == TRUE);
            ASSERT_EQ(i, *p);
        }

        ASSERT_FALSE(instance.ExitDisabledProcessing() == TRUE);
    }



    CPPANONYM_TEST(Urasandesu_CppAnonym_Collections_GlobalSafeDictionaryTest, Test_03)
    {
        using namespace Urasandesu::CppAnonym::Collections;
        using namespace std;

        typedef GlobalSafeDictionary<std::wstring, void const *> MyGlobalSafeDictionary;
        
        auto &instance = MyGlobalSafeDictionary::GetInstance();

        instance.Clear();

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



    CPPANONYM_TEST(Urasandesu_CppAnonym_Collections_GlobalSafeDictionaryTest, ForEach_should_apply_specified_function_for_all_entries)
    {
        using namespace Urasandesu::CppAnonym::Collections;
        using namespace std;

        typedef GlobalSafeDictionary<std::wstring, void const *> FunctionCollection;
        typedef GlobalSafeDictionary<UINT_PTR, boost::shared_ptr<FunctionCollection>> AppDomainFunctionCollection;

        // Arrange
        auto &adfc = AppDomainFunctionCollection::GetInstance();
        adfc.Clear();
        {
            auto pFc = boost::make_shared<FunctionCollection>();
            adfc.GetOrAdd(42, pFc, pFc);
            pFc->TryAdd(L"aiueo", nullptr);
        }
        {
            auto pFc = boost::make_shared<FunctionCollection>();
            adfc.GetOrAdd(13, pFc, pFc);
            pFc->TryAdd(L"kakikukeko", nullptr);
        }


        // Act
        typedef AppDomainFunctionCollection::entry_type Entry;
        auto clearer = function<void(Entry &)>();
        clearer = [](Entry &pair) { pair.second->Clear(); };
        adfc.ForEach(clearer);


        // Assert
        ASSERT_FALSE(adfc.Empty() == TRUE);
        {
            auto pFc = boost::shared_ptr<FunctionCollection>();
            ASSERT_TRUE(adfc.TryGet(42, pFc) == TRUE);
            ASSERT_TRUE(pFc->Empty() == TRUE);
        }
        {
            auto pFc = boost::shared_ptr<FunctionCollection>();
            ASSERT_TRUE(adfc.TryGet(13, pFc) == TRUE);
            ASSERT_TRUE(pFc->Empty() == TRUE);
        }
    }



    CPPANONYM_TEST(Urasandesu_CppAnonym_Collections_GlobalSafeDictionaryTest, AddOrUpdate_should_add_if_specified_key_does_not_exist)
    {
        using namespace Urasandesu::CppAnonym::Collections;

        typedef GlobalSafeDictionary<std::wstring, void const *> FunctionCollection;
        typedef GlobalSafeDictionary<UINT_PTR, std::pair<bool, boost::shared_ptr<FunctionCollection>>> AppDomainFunctionCollection;
        typedef AppDomainFunctionCollection::in_key_type InKey;
        typedef AppDomainFunctionCollection::in_value_type InValue;
        typedef AppDomainFunctionCollection::out_value_type OutValue;

        // Arrange
        auto &adfc = AppDomainFunctionCollection::GetInstance();
        adfc.Clear();


        // Act
        auto addValue = std::make_pair(true, boost::make_shared<FunctionCollection>());
        auto updateValueFactory = std::function<void(InKey, InValue, OutValue)>();
        updateValueFactory = [](InKey inKey, InValue inValue, OutValue outValue) { outValue = inValue; outValue.first = true; };
        auto resultValue = adfc.AddOrUpdate(42, addValue, updateValueFactory);


        // Assert
        ASSERT_FALSE(adfc.Empty() == TRUE);
        {
            auto pair = std::pair<bool, boost::shared_ptr<FunctionCollection>>();
            ASSERT_TRUE(adfc.TryGet(42, pair) == TRUE);
            ASSERT_EQ(resultValue, pair);
            ASSERT_EQ(resultValue, addValue);
        }
    }

    CPPANONYM_TEST(Urasandesu_CppAnonym_Collections_GlobalSafeDictionaryTest, AddOrUpdate_should_update_if_specified_key_exists)
    {
        using namespace Urasandesu::CppAnonym::Collections;

        typedef GlobalSafeDictionary<std::wstring, void const *> FunctionCollection;
        typedef GlobalSafeDictionary<UINT_PTR, std::pair<bool, boost::shared_ptr<FunctionCollection>>> AppDomainFunctionCollection;
        typedef AppDomainFunctionCollection::in_key_type InKey;
        typedef AppDomainFunctionCollection::in_value_type InValue;
        typedef AppDomainFunctionCollection::out_value_type OutValue;

        // Arrange
        auto &adfc = AppDomainFunctionCollection::GetInstance();
        adfc.Clear();
        adfc.TryAdd(42, std::make_pair(false, boost::make_shared<FunctionCollection>()));


        // Act
        auto addValue = std::make_pair(true, boost::make_shared<FunctionCollection>());
        auto updateValueFactory = std::function<void(InKey, InValue, OutValue)>();
        updateValueFactory = [](InKey inKey, InValue inValue, OutValue outValue) { outValue = inValue; outValue.first = true; };
        auto resultValue = adfc.AddOrUpdate(42, addValue, updateValueFactory);


        // Assert
        ASSERT_FALSE(adfc.Empty() == TRUE);
        {
            auto pair = std::pair<bool, boost::shared_ptr<FunctionCollection>>();
            ASSERT_TRUE(adfc.TryGet(42, pair) == TRUE);
            ASSERT_EQ(resultValue, pair);
            ASSERT_NE(resultValue, addValue);
        }
    }
}
