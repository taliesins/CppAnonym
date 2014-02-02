/* 
 * File: IsLikePointerTest.cpp
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

#ifndef URASANDESU_CPPANONYM_TRAITS_ISLIKEPOINTER_H
#include <Urasandesu/CppAnonym/Traits/IsLikePointer.h>
#endif

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_Traits_IsLikePointerTest.*
namespace {

    namespace _FFBD97C5 {

        struct Hoge 
        { 
            Hoge() { }
            Hoge(Hoge const &other) { }
            Hoge &operator=(Hoge const &other) { throw 1; }
            ~Hoge() { }
            Hoge &operator*() const { throw 1; }
            Hoge *operator->() const { throw 1; }
        };

        template<class T>
        struct MyPtr
        {
            MyPtr() { }
            MyPtr(MyPtr<T> const &other) { }
            MyPtr<T> &operator=(MyPtr<T> const &other) { throw 1; }
            ~MyPtr() { }
            T &operator*() const { throw 1; }
            T *operator->() const { throw 1; }
        };

    }   // namespace _FFBD97C5 {

    TEST(Urasandesu_CppAnonym_Traits_IsLikePointerTest, Test_01)
    {
        namespace mpl = boost::mpl;
        using mpl::not_;
        using namespace boost;
        using namespace Urasandesu::CppAnonym::Traits;
        using namespace _FFBD97C5;

        BOOST_MPL_ASSERT((not_<IsLikePointer<int> >));
        BOOST_MPL_ASSERT((IsLikePointer<int *>));
        BOOST_MPL_ASSERT((IsLikePointer<intrusive_ptr<Hoge> >));
        BOOST_MPL_ASSERT((IsLikePointer<shared_ptr<Hoge> >));
        BOOST_MPL_ASSERT((not_<IsLikePointer<Hoge> >));
        BOOST_MPL_ASSERT((IsLikePointer<MyPtr<Hoge> >));
    }
}
