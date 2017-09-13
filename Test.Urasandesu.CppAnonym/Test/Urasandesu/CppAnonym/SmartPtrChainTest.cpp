/* 
 * File: SmartPtrChainTest.cpp
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

#ifndef URASANDESU_CPPANONYM_SMARTPTRCHAINMAPPER_H
#include <Urasandesu/CppAnonym/SmartPtrChainMapper.h>
#endif

#ifndef URASANDESU_CPPANONYM_SMARTPTRCHAINCONSTRUCTOR_H
#include <Urasandesu/CppAnonym/SmartPtrChainConstructor.h>
#endif

#ifndef URASANDESU_CPPANONYM_SMARTPTRCHAININFO_HPP
#include <Urasandesu/CppAnonym/SmartPtrChainInfo.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_SMARTPTRCHAIN_HPP
#include <Urasandesu/CppAnonym/SmartPtrChain.hpp>
#endif

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_SmartPtrChainTest.*
namespace {

    namespace _F74DEBBE {

        struct Dummy;   // incomplete type is ignored if it is not designated explicitly.
        struct Root;    // manages a root object and the specialized initialization. 
        struct Node1;
        struct Node2;   // manages nested same types.
        struct Node3;   // manages the specialized initialization.

    }   // namespace _F74DEBBE {

    namespace _F74DEBBE {

        namespace mpl = boost::mpl;
        using namespace boost;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Utilities;        

        template<class T>
        struct MyProvider
        {
            TempPtr<T> NewObject() { return TempPtr<T>(new T()); }
        };

        
        
        
        
        struct RootFacade
        {
            typedef Root root_type;
            typedef Node1 node1_type;
            typedef Dummy root_previous_type;
            typedef mpl::vector<SmartPtrChainInfo<root_previous_type> > chain_info_types;
            typedef SmartPtrChain<root_type, chain_info_types> base_ptr_chain_type;
            typedef base_ptr_chain_type::chain_from<root_previous_type>::type root_chain_type;
        };

        struct Root : // manages a root object and the specialized initialization. 
            RootFacade::base_ptr_chain_type
        {
            typedef RootFacade facade;
            typedef facade::root_type root_type;
            typedef facade::node1_type node1_type;
            typedef facade::root_previous_type root_previous_type;
            typedef facade::chain_info_types chain_info_types;
            typedef facade::base_ptr_chain_type base_ptr_chain_type;
            typedef facade::root_chain_type root_chain_type;

            Root();
            void Initialized();
            static TempPtr<root_type> NewRoot(int value);
            TempPtr<node1_type> NewNode1(std::wstring const &version) const;

            bool m_initialized;
            int m_value;
        };

        
        
        
        
        struct Node1Facade
        {
            typedef Root root_type;
            typedef Node1 node1_type;
            typedef Node2 node2_type;
            typedef root_type node1_previous_type;
            typedef mpl::vector<SmartPtrChainInfo<node1_previous_type> > chain_info_types;
            typedef SmartPtrChain<node1_type, chain_info_types> base_ptr_chain_type;
            typedef base_ptr_chain_type::chain_from<node1_previous_type>::type node1_chain_type;
        };

        struct Node1 : 
            Node1Facade::base_ptr_chain_type
        {
            typedef Node1Facade facade;
            typedef facade::root_type root_type;
            typedef facade::node1_type node1_type;
            typedef facade::node2_type node2_type;
            typedef facade::node1_previous_type node1_previous_type;
            typedef facade::chain_info_types chain_info_types;
            typedef facade::base_ptr_chain_type base_ptr_chain_type;
            typedef facade::node1_chain_type node1_chain_type;

            Node1();
            TempPtr<node2_type> NewNode2(double ratio) const;

            std::wstring m_version;
        };

        
        
        
        
        struct Node2Facade
        {
            typedef Node1 node1_type;
            typedef Node2 node2_type;
            typedef Node3 node3_type;
            typedef node1_type node2_previous_type;
            typedef node2_type nested_node2_previous_type;
            typedef mpl::vector<
                SmartPtrChainInfo<nested_node2_previous_type>, 
                SmartPtrChainInfo<node2_previous_type>
            > chain_info_types;
            typedef SmartPtrChain<node2_type, chain_info_types> base_ptr_chain_type;
            typedef base_ptr_chain_type::chain_from<nested_node2_previous_type>::type nested_node2_chain_type;
            typedef base_ptr_chain_type::chain_from<node2_previous_type>::type node2_chain_type;
        };
        
        struct Node2 : // manages nested same types.
            Node2Facade::base_ptr_chain_type
        {
            typedef Node2Facade facade;
            typedef facade::node1_type node1_type;
            typedef facade::node2_type node2_type;
            typedef facade::node3_type node3_type;
            typedef facade::node2_previous_type node2_previous_type;
            typedef facade::nested_node2_previous_type nested_node2_previous_type;
            typedef facade::chain_info_types chain_info_types;
            typedef facade::base_ptr_chain_type base_ptr_chain_type;
            typedef facade::nested_node2_chain_type nested_node2_chain_type;
            typedef facade::node2_chain_type node2_chain_type;

            Node2();
            TempPtr<node2_type> NewNestedNode2(double ratio) const;
            TempPtr<node3_type> NewNode3(char id) const;

            double m_ratio;
        };

        
        
        
        
        struct Node3Facade
        {
            typedef Node2 node2_type;
            typedef Node3 node3_type;
            typedef node2_type node3_previous_type;
            typedef mpl::vector<SmartPtrChainInfo<node3_previous_type> > chain_info_types;
            typedef SmartPtrChain<node3_type, chain_info_types> base_ptr_chain_type;
            typedef base_ptr_chain_type::chain_from<node3_previous_type>::type node3_chain_type;
        };

        struct Node3 : // manages the specialized initialization.
            Node3Facade::base_ptr_chain_type
        {
            typedef Node3Facade facade;
            typedef facade::node2_type node2_type;
            typedef facade::node3_type node3_type;
            typedef facade::node3_previous_type node3_previous_type;
            typedef facade::chain_info_types chain_info_types;
            typedef facade::base_ptr_chain_type base_ptr_chain_type;
            typedef facade::node3_chain_type node3_chain_type;

            Node3();
            void Initialized();

            bool m_initialized;
            char m_id;
        };

        
        
        
        
        Root::Root() : 
            m_initialized(false),
            m_value(0)
        { }

        void Root::Initialized()
        {
            m_initialized = true;
        }

        TempPtr<Root::root_type> Root::NewRoot(int value)
        {
            TempPtr<root_type> pRoot = root_chain_type::NewRootObject<root_type>(MyProvider<root_type>());
            pRoot->m_value = value;
            return pRoot;
        }

        TempPtr<Root::node1_type> Root::NewNode1(std::wstring const &version) const
        {
            root_chain_type &chain = ChainFrom<root_previous_type>();
            TempPtr<node1_type> pNode1 = chain.NewObject<node1_type>(MyProvider<node1_type>());
            pNode1->m_version = version;
            return pNode1;
        }





        Node1::Node1()
        { }
        
        TempPtr<Node1::node2_type> Node1::NewNode2(double ratio) const
        {
            node1_chain_type &chain = ChainFrom<node1_previous_type>();
            TempPtr<node2_type> pNode2 = chain.NewObject<node2_type>(MyProvider<node2_type>());
            pNode2->m_ratio = ratio;
            return pNode2;
        }





        Node2::Node2() : 
            m_ratio(0.0)
        { }

        TempPtr<Node2::node2_type> Node2::NewNestedNode2(double ratio) const
        {
            nested_node2_chain_type &chain = ChainFrom<nested_node2_previous_type>();
            TempPtr<node2_type> pNestedNode2 = chain.NewObject<node2_type>(MyProvider<node2_type>());
            pNestedNode2->m_ratio = ratio;
            return pNestedNode2;
        }

        TempPtr<Node2::node3_type> Node2::NewNode3(char id) const
        {
            node2_chain_type &chain = ChainFrom<node2_previous_type>();
            TempPtr<node3_type> pNode3 = chain.NewObject<node3_type>(MyProvider<node3_type>());
            pNode3->m_id = id;
            return pNode3;
        }





        Node3::Node3() : 
            m_initialized(false),
            m_id('\0')
        { }

        void Node3::Initialized()
        {
            m_initialized = true;
        }

    }   // namespace _F74DEBBE {

    CPPANONYM_TEST(Urasandesu_CppAnonym_SmartPtrChainTest, Test_01)
    {
        using namespace _F74DEBBE;

        auto pRoot = Root::NewRoot(42);
        ASSERT_TRUE(pRoot);
        ASSERT_TRUE(pRoot->m_initialized);
        ASSERT_EQ(42, pRoot->m_value);
        
        auto pNode1 = pRoot->NewNode1(L"aiueo");
        ASSERT_TRUE(pNode1);
        ASSERT_STREQ(L"aiueo", pNode1->m_version.c_str());
        {
            auto *pRoot_ = pNode1->Map<Root>();
            ASSERT_EQ(pRoot.Get(), pRoot_);

            //auto *pDummy_ = pNode1->Map<Dummy>(); // C2027
        }

        auto pNode2 = pNode1->NewNode2(2.2);
        ASSERT_TRUE(pNode2);
        ASSERT_EQ(2.2, pNode2->m_ratio);
        {
            auto *pRoot_ = pNode2->MapFirst<Root>();
            ASSERT_EQ(pRoot.Get(), pRoot_);

            auto *pNode1_ = pNode2->MapFirst<Node1>();
            ASSERT_EQ(pNode1.Get(), pNode1_);
        }

        auto pNode3_1 = pNode2->NewNode3('!');
        ASSERT_TRUE(pNode3_1);
        ASSERT_TRUE(pNode3_1->m_initialized);
        ASSERT_EQ('!', pNode3_1->m_id);
        {
            auto *pRoot_ = pNode3_1->MapFirst<Root>();
            ASSERT_EQ(pRoot.Get(), pRoot_);

            auto *pNode1_ = pNode3_1->MapFirst<Node1>();
            ASSERT_EQ(pNode1.Get(), pNode1_);

            auto *pNode2_ = pNode3_1->MapFirst<Node2>();
            ASSERT_EQ(pNode2.Get(), pNode2_);
        }

        auto pNestedNode2 = pNode2->NewNestedNode2(3.5);
        ASSERT_TRUE(pNestedNode2);
        ASSERT_EQ(3.5, pNestedNode2->m_ratio);
        {
            auto *pRoot_ = pNestedNode2->MapFirst<Root>();
            ASSERT_EQ(pRoot.Get(), pRoot_);

            auto *pNode1_ = pNestedNode2->MapFirst<Node1>();
            ASSERT_EQ(pNode1.Get(), pNode1_);
        }

        auto pNode3_2 = pNestedNode2->NewNode3('?');
        ASSERT_TRUE(pNode3_2);
        ASSERT_TRUE(pNode3_2->m_initialized);
        ASSERT_EQ('?', pNode3_2->m_id);
        {
            auto *pRoot_ = pNode3_2->MapFirst<Root>();
            ASSERT_EQ(pRoot.Get(), pRoot_);

            auto *pNode1_ = pNode3_2->MapFirst<Node1>();
            ASSERT_EQ(pNode1.Get(), pNode1_);

            auto *pNestedNode2_ = pNode3_2->MapFirst<Node2>();
            ASSERT_EQ(pNestedNode2.Get(), pNestedNode2_);
        }

    }

}
