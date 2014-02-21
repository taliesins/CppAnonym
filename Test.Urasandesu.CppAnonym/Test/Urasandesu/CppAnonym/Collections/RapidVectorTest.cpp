/* 
 * File: RapidVectorTest.cpp
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

#ifndef URASANDESU_CPPANONYM_COLLECTIONS_RAPIDVECTOR_HPP
#include <Urasandesu/CppAnonym/Collections/RapidVector.hpp>
#endif

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_Collections_RapidVectorTest.*
namespace {

    CPPANONYM_TEST(Urasandesu_CppAnonym_Collections_RapidVectorTest, IterationTest_LessThan512_01)
    {
        using namespace std;
        using namespace Urasandesu::CppAnonym::Collections;
        
        RapidVector<BYTE> vec;
        for (INT i = 0; i < 512; ++i)
        {
            vec.push_back(static_cast<BYTE>(i & 0xFF));
        }
        ASSERT_EQ(512, vec.size());
        
        {
            RapidVector<BYTE>::iterator i = vec.begin();
            ASSERT_EQ(0x00, *i);
            ASSERT_EQ(0xFF, *(i += vec.size() - 1));
        }
    }


    
    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_Collections_RapidVectorTest, IterationTest_EqualsOrGreaterThan512_01)
    {
        using namespace std;
        using namespace Urasandesu::CppAnonym::Collections;
        
        RapidVector<BYTE> vec;
        for (INT i = 0; i <= 512; ++i)
        {
            vec.push_back(static_cast<BYTE>(i & 0xFF));
        }
        ASSERT_EQ(513, vec.size());
        
        {
            RapidVector<BYTE>::iterator i = vec.begin();
            ASSERT_EQ(0x00, *i);
            ASSERT_EQ(0xFF, i[vec.size() - 2]);
            ASSERT_EQ(0x00, i[vec.size() - 1]);
        }
    }


    
    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_Collections_RapidVectorTest, RandomAccessOperatorTest_LessThan512_01)
    {
        using namespace std;
        using namespace Urasandesu::CppAnonym::Collections;
        
        RapidVector<BYTE> vec;
        for (INT i = 0; i < 512; ++i)
        {
            vec.push_back(static_cast<BYTE>(i & 0xFF));
        }
        ASSERT_EQ(512, vec.size());
        
        ASSERT_EQ(0x00, vec[0]);
        ASSERT_EQ(0xFF, vec[vec.size() - 1]);
    }


    
    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_Collections_RapidVectorTest, RandomAccessOperatorTest_EqualsOrGreaterThan512_01)
    {
        using namespace std;
        using namespace Urasandesu::CppAnonym::Collections;
        
        RapidVector<BYTE> vec;
        for (INT i = 0; i <= 512; ++i)
        {
            vec.push_back(static_cast<BYTE>(i & 0xFF));
        }
        ASSERT_EQ(513, vec.size());
        
        ASSERT_EQ(0x00, vec[0]);
        ASSERT_EQ(0xFF, vec[vec.size() - 2]);
        ASSERT_EQ(0x00, vec[vec.size() - 1]);
    }


    
    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_Collections_RapidVectorTest, RemoveTest_LessThan512_01)
    {
        using namespace std;
        using namespace Urasandesu::CppAnonym::Collections;
        
        RapidVector<BYTE> vec;
        for (INT i = 0; i < 512; ++i)
        {
            vec.push_back(static_cast<BYTE>(i & 0xFF));
        }
        ASSERT_EQ(512, vec.size());

        vec.pop_back();
        ASSERT_EQ(511, vec.size());

        ASSERT_EQ(0x00, vec[0]);
        ASSERT_EQ(0xFD, vec[vec.size() - 2]);
        ASSERT_EQ(0xFE, vec[vec.size() - 1]);
    }


    
    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_Collections_RapidVectorTest, RemoveTest_EqualsOrGreaterThan512_01)
    {
        using namespace std;
        using namespace Urasandesu::CppAnonym::Collections;
        
        RapidVector<BYTE> vec;
        for (INT i = 0; i <= 512; ++i)
        {
            vec.push_back(static_cast<BYTE>(i & 0xFF));
        }
        ASSERT_EQ(513, vec.size());

        vec.pop_back();
        ASSERT_EQ(512, vec.size());

        ASSERT_EQ(0x00, vec[0]);
        ASSERT_EQ(0xFE, vec[vec.size() - 2]);
        ASSERT_EQ(0xFF, vec[vec.size() - 1]);
    }


    
    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_Collections_RapidVectorTest, EraseTest_LessThan512_ToEnd_01)
    {
        using namespace std;
        using namespace Urasandesu::CppAnonym::Collections;
        
        RapidVector<BYTE> vec;
        for (INT i = 0; i < 512; ++i)
            vec.push_back(static_cast<BYTE>(i & 0xFF));
        ASSERT_EQ(512, vec.size());

        boost::remove_erase_if(vec, [](BYTE b) { return b == 0xFF; });

        ASSERT_EQ(510, vec.size());
        ASSERT_EQ(0x00, vec[0]);
        ASSERT_EQ(0xFE, vec[vec.size() - 1]);
    }


    
    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_Collections_RapidVectorTest, EraseTest_LessThan512_InBetween_01)
    {
        using namespace std;
        using namespace Urasandesu::CppAnonym::Collections;
        
        RapidVector<BYTE> vec;
        for (INT i = 0; i < 512; ++i)
            vec.push_back(static_cast<BYTE>(i & 0xFF));
        ASSERT_EQ(512, vec.size());

        typedef RapidVector<BYTE>::iterator ByteIterator;
        ByteIterator i_ = std::find_if(vec.begin(), vec.end(), [](BYTE b) { return b == 0xFF; });
        ByteIterator i_end_ = std::find_if(i_, vec.end(), [](BYTE b) { return b == 0x03; });
        vec.erase(i_, i_end_);

        ASSERT_EQ(508, vec.size());
        ASSERT_EQ(0x00, vec[0]);
        ASSERT_EQ(0xFF, vec[vec.size() - 1]);
    }


    
    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_Collections_RapidVectorTest, EraseTest_EqualsOrGreaterThan512_ToEnd_01)
    {
        using namespace std;
        using namespace boost::lambda;
        using namespace Urasandesu::CppAnonym::Collections;
        
        RapidVector<BYTE> vec;
        for (INT i = 0; i < 520; ++i)
            vec.push_back(static_cast<BYTE>(i & 0xFF));
        ASSERT_EQ(520, vec.size());

        boost::remove_erase_if(vec, [](BYTE b) { return b == 0x00; });

        ASSERT_EQ(517, vec.size());
        ASSERT_EQ(0x01, vec[0]);
        ASSERT_EQ(0x07, vec[vec.size() - 1]);
    }


    
    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_Collections_RapidVectorTest, EraseTest_EqualsOrGreaterThan512_InBetween_01)
    {
        using namespace std;
        using namespace boost::lambda;
        using namespace Urasandesu::CppAnonym::Collections;
        
        RapidVector<BYTE> vec;
        for (INT i = 0; i < 520; ++i)
            vec.push_back(static_cast<BYTE>(i & 0xFF));
        ASSERT_EQ(520, vec.size());

        typedef RapidVector<BYTE>::iterator ByteIterator;
        ByteIterator i_ = std::find_if(vec.begin(), vec.end(), [](BYTE b) { return b == 0x80; });
        ByteIterator i_end_ = std::find_if(i_, vec.end(), [](BYTE b) { return b == 0x7F; });
        vec.erase(i_, i_end_);

        ASSERT_EQ(265, vec.size());
        ASSERT_EQ(0x00, vec[0]);
        ASSERT_EQ(0x07, vec[vec.size() - 1]);
    }





    namespace _0B268749 {

        struct ReferenceTester
        {
            typedef ReferenceTester this_type;

            ReferenceTester() : m_useCount(0) { }
            ~ReferenceTester() { };

            inline friend void intrusive_ptr_add_ref(this_type *p)
            {
                ++p->m_useCount;
            }

            inline friend void intrusive_ptr_release(this_type *p)
            {
                --p->m_useCount;
            }

            LONG m_useCount;
        };

    }   // namespace _0B268749 {
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_Collections_RapidVectorTest, AddReferenceTest_01)
    {
        using namespace boost;
        using namespace Urasandesu::CppAnonym::Collections;
        using namespace _0B268749;

        typedef RapidVector<intrusive_ptr<ReferenceTester>, 1 > Vector;

        ReferenceTester *pTester = new ReferenceTester();
        {
            Vector v;
            v.push_back(pTester);
            ASSERT_EQ(1, pTester->m_useCount);
        }
        ASSERT_EQ(0, pTester->m_useCount);

        delete pTester;
    }
    
    
    
    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_Collections_RapidVectorTest, AddReferenceTest_02)
    {
        using namespace boost;
        using namespace Urasandesu::CppAnonym::Collections;
        using namespace _0B268749;

        typedef RapidVector<intrusive_ptr<ReferenceTester>, 1 > Vector;

        ReferenceTester *pTester = new ReferenceTester();
        {
            Vector v;
            v.push_back(pTester);
            v.push_back(pTester);
            ASSERT_EQ(2, pTester->m_useCount);
        }
        ASSERT_EQ(0, pTester->m_useCount);

        delete pTester;
    }
    
    
    
    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_Collections_RapidVectorTest, RemoveReferenceTest_01)
    {
        using namespace boost;
        using namespace Urasandesu::CppAnonym::Collections;
        using namespace _0B268749;

        typedef RapidVector<intrusive_ptr<ReferenceTester>, 1 > Vector;

        ReferenceTester *pTester = new ReferenceTester();
        {
            Vector v;
            v.push_back(pTester);
            v.pop_back();
            ASSERT_EQ(0, pTester->m_useCount);
        }
        ASSERT_EQ(0, pTester->m_useCount);

        delete pTester;
    }
    
    
    
    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_Collections_RapidVectorTest, RemoveReferenceTest_02)
    {
        using namespace boost;
        using namespace Urasandesu::CppAnonym::Collections;
        using namespace _0B268749;

        typedef RapidVector<intrusive_ptr<ReferenceTester>, 1 > Vector;

        ReferenceTester *pTester = new ReferenceTester();
        {
            Vector v;
            v.push_back(pTester);
            v.push_back(pTester);
            v.pop_back();
            v.pop_back();
            ASSERT_EQ(0, pTester->m_useCount);
        }
        ASSERT_EQ(0, pTester->m_useCount);

        delete pTester;
    }
    
    
    
    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_Collections_RapidVectorTest, EraseReferenceTest_01)
    {
        using namespace boost;
        using namespace Urasandesu::CppAnonym::Collections;
        using namespace _0B268749;

        typedef RapidVector<intrusive_ptr<ReferenceTester>, 2 > Vector;

        ReferenceTester *pTester = new ReferenceTester();
        {
            Vector v;
            v.push_back(pTester);
            v.push_back(pTester);
            v.erase(v.begin() + 1, v.end());
            ASSERT_EQ(1, pTester->m_useCount);
        }
        ASSERT_EQ(0, pTester->m_useCount);

        delete pTester;
    }
    
    
    
    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_Collections_RapidVectorTest, EraseReferenceTest_02)
    {
        using namespace boost;
        using namespace Urasandesu::CppAnonym::Collections;
        using namespace _0B268749;

        typedef RapidVector<intrusive_ptr<ReferenceTester>, 2 > Vector;

        ReferenceTester *pTester = new ReferenceTester();
        {
            Vector v;
            v.push_back(pTester);
            v.push_back(pTester);
            v.erase(v.begin(), v.begin() + 1);
            ASSERT_EQ(1, pTester->m_useCount);
        }
        ASSERT_EQ(0, pTester->m_useCount);

        delete pTester;
    }





    namespace _FE50F05F {

        struct Hoge
        {
            Hoge(int hogeValue) : m_hogeValue(hogeValue) { }
            virtual ~Hoge() { }
            int m_hogeValue;
        };

        struct Piyo : 
            Hoge
        {
            Piyo(int hogeValue, int piyoValue) : Hoge(hogeValue), m_piyoValue(piyoValue) { }
            virtual ~Piyo() { }
            int m_piyoValue;
        };

    }   // namespace _FE50F05F {

    CPPANONYM_TEST(Urasandesu_CppAnonym_Collections_RapidVectorTest, ReserveAndAssignTest_01)
    {
        using namespace Urasandesu::CppAnonym::Collections;
        using namespace _FE50F05F;

        typedef RapidVector<Hoge *, 1> HogeVector;
        typedef RapidVector<Piyo *, 1> PiyoVector;

        HogeVector hoges;
        PiyoVector piyos;

        {
            Piyo *p = new Piyo(10, 20);
            piyos.push_back(p);
        }

        hoges.reserve(piyos.size());
        hoges.assign(piyos.begin(), piyos.end());

        ASSERT_EQ(1, hoges.size());
        {
            Piyo *p = static_cast<Piyo *>(hoges[0]);
            ASSERT_EQ(10, p->m_hogeValue);
            ASSERT_EQ(20, p->m_piyoValue);
        }

        typedef HogeVector::iterator Iterator;
        for (Iterator i = hoges.begin(), i_end = hoges.end(); i != i_end; ++i)
            delete *i;
    }

    
    
    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_Collections_RapidVectorTest, ReserveAndAssignTest_02)
    {
        using namespace Urasandesu::CppAnonym::Collections;
        using namespace _FE50F05F;

        typedef RapidVector<Hoge *, 1> HogeVector;
        typedef RapidVector<Piyo *, 2> PiyoVector;

        HogeVector hoges;
        PiyoVector piyos;

        {
            Piyo *p = new Piyo(10, 20);
            piyos.push_back(p);
        }

        {
            Piyo *p = new Piyo(30, 40);
            piyos.push_back(p);
        }

        hoges.reserve(piyos.size());
        hoges.assign(piyos.begin(), piyos.end());

        ASSERT_EQ(2, hoges.size());
        {
            Piyo *p = static_cast<Piyo *>(hoges[0]);
            ASSERT_EQ(10, p->m_hogeValue);
            ASSERT_EQ(20, p->m_piyoValue);
        }

        {
            Piyo *p = static_cast<Piyo *>(hoges[1]);
            ASSERT_EQ(30, p->m_hogeValue);
            ASSERT_EQ(40, p->m_piyoValue);
        }

        typedef HogeVector::iterator Iterator;
        for (Iterator i = hoges.begin(), i_end = hoges.end(); i != i_end; ++i)
            delete *i;
    }
}
