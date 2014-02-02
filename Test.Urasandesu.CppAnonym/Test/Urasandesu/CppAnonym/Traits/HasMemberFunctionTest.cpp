/* 
 * File: HasMemberFunctionTest.cpp
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

#ifndef URASANDESU_CPPANONYM_TRAITS_HASMEMBERFUNCTION_H
#include <Urasandesu/CppAnonym/Traits/HasMemberFunction.h>
#endif

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_Traits_HasMemberFunctionTest.*
namespace {

    namespace _4FE4E388 {

        struct WithInitialized { void Initialized() { } };
        struct WithoutInitialized { };

        CPP_ANONYM_DECLARE_HAS_MEMBER_FUNCTION(Test, Initialized, void, ());

    }   // namespace _4FE4E388 {

    TEST(Urasandesu_CppAnonym_Traits_HasMemberFunctionTest, Test_01)
    {
        using namespace _4FE4E388;
        using namespace boost;
        using boost::mpl::not_;

        BOOST_MPL_ASSERT((CPP_ANONYM_HAS_MEMBER_FUNCTION(Test, WithInitialized)));
        BOOST_MPL_ASSERT((not_<CPP_ANONYM_HAS_MEMBER_FUNCTION(Test, WithoutInitialized)>));
    }



#if 0
    namespace _693497BC {

        struct WithChainFrom { template<class T> T *ChainFrom() { throw 1; } };
        struct WithoutChainFrom { };

        template<class T>
        struct Chain
        {
            CPP_ANONYM_DECLARE_HAS_MEMBER_FUNCTION(Test, template ChainFrom<T>, T *, ());
#if 0
            template<class HasMemberFunctionT, class Tag = boost::mpl::void_>
            struct Has_Test
            {
                typedef boost::mpl::false_ type;
                enum { value = false };
            };
            
            template<class HasMemberFunctionT>
            struct Has_Test<
                HasMemberFunctionT,
                typename boost::mpl::apply<
                    boost::mpl::always<boost::mpl::void_>,
                    Urasandesu::CppAnonym::Traits::HasMemberFunctionIdentify<
                        T *(HasMemberFunctionT::*)(),
                        static_cast<T *(HasMemberFunctionT::*)()>(&HasMemberFunctionT::template ChainFrom<T>)
                    >
                >::type
            >
            {
                typedef boost::mpl::true_ type;
                enum { value = true };
            };
#endif
        };

    }   // namespace _693497BC {

    TEST(Urasandesu_CppAnonym_Traits_HasMemberFunctionTest, Test_02)
    {
        using namespace _693497BC;
        using namespace boost;
        using boost::mpl::not_;

        BOOST_MPL_ASSERT((Chain<int>::CPP_ANONYM_HAS_MEMBER_FUNCTION(Test, WithChainFrom)));
        //BOOST_MPL_ASSERT((Chain<int>::Has_Test<WithChainFrom>));
        BOOST_MPL_ASSERT((not_<Chain<int>::CPP_ANONYM_HAS_MEMBER_FUNCTION(Test, WithoutChainFrom)>));
        typedef int *(WithChainFrom::*ChainFromPtr)();
        Urasandesu::CppAnonym::Traits::HasMemberFunctionIdentify<ChainFromPtr, &WithChainFrom::ChainFrom<int> > a;

        //ChainFromPtr p = &WithChainFrom::ChainFrom<int>;
        //BOOST_MPL_ASSERT((boost::is_same<boost::mpl::identity<decltype(&WithChainFrom::ChainFrom<int>)>::type, int>));
    }



    namespace _9B8B1B56 {

        struct CompleteType { template<class T> T *ChainFrom() { throw 1; } };
        struct IncompleteType;

        template<class T>
        struct Chain
        {
            CPP_ANONYM_DECLARE_HAS_MEMBER_FUNCTION(Test, ChainFrom<T>, T *, ());
        };

    }   // namespace _9B8B1B56 {

    TEST(Urasandesu_CppAnonym_Traits_HasMemberFunctionTest, Test_03)
    {
        using namespace _9B8B1B56;
        using namespace boost;
        using boost::mpl::not_;

        BOOST_MPL_ASSERT((Chain<int>::CPP_ANONYM_HAS_MEMBER_FUNCTION(Test, CompleteType)));
        BOOST_MPL_ASSERT((not_<Chain<int>::CPP_ANONYM_HAS_MEMBER_FUNCTION(Test, IncompleteType)>));
    }
#endif
}
