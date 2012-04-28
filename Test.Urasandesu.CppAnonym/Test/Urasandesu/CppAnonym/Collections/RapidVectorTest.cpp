#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_COLLECTIONS_RAPIDVECTOR_H
#include <Urasandesu/CppAnonym/Collections/RapidVector.h>
#endif

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_Collections_RapidVectorTest.*
namespace {

    struct MyPOD1
    {
        BYTE byte1;
        BYTE byte2;
        BYTE byte3;
        BYTE byte4;
        BYTE byte5;
        BYTE byte6;
        BYTE byte7;
        BYTE byte8;
    };
    
    struct MyPOD2
    {
        INT int1;
        MyPOD1 pod1;
        PVOID pv;
        
        MyPOD2 *prev;
        MyPOD2 *next;
    };

    
    TEST(Urasandesu_CppAnonym_Collections_RapidVectorTest, IterationTest_LessThan512_01)
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


    TEST(Urasandesu_CppAnonym_Collections_RapidVectorTest, IterationTest_EqualsOrGreaterThan512_01)
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


    TEST(Urasandesu_CppAnonym_Collections_RapidVectorTest, RandomAccessOperatorTest_LessThan512_01)
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


    TEST(Urasandesu_CppAnonym_Collections_RapidVectorTest, RandomAccessOperatorTest_EqualsOrGreaterThan512_01)
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


    TEST(Urasandesu_CppAnonym_Collections_RapidVectorTest, RemoveTest_LessThan512_01)
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


    TEST(Urasandesu_CppAnonym_Collections_RapidVectorTest, RemoveTest_EqualsOrGreaterThan512_01)
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


    TEST(Urasandesu_CppAnonym_Collections_RapidVectorTest, EraseTest_LessThan512_ToEnd_01)
    {
        using namespace std;
        using namespace boost::lambda;
        using namespace Urasandesu::CppAnonym::Collections;
        
        RapidVector<BYTE> vec;
        for (INT i = 0; i < 512; ++i)
            vec.push_back(static_cast<BYTE>(i & 0xFF));
        ASSERT_EQ(512, vec.size());

        boost::remove_erase_if(vec, _1 == 0xFF);

        ASSERT_EQ(510, vec.size());
        ASSERT_EQ(0x00, vec[0]);
        ASSERT_EQ(0xFE, vec[vec.size() - 1]);
    }


    TEST(Urasandesu_CppAnonym_Collections_RapidVectorTest, EraseTest_LessThan512_InBetween_01)
    {
        using namespace std;
        using namespace boost::lambda;
        using namespace Urasandesu::CppAnonym::Collections;
        
        RapidVector<BYTE> vec;
        for (INT i = 0; i < 512; ++i)
            vec.push_back(static_cast<BYTE>(i & 0xFF));
        ASSERT_EQ(512, vec.size());

        typedef RapidVector<BYTE>::iterator ByteIterator;
        ByteIterator i_ = std::find_if(vec.begin(), vec.end(), _1 == 0xFF);
        ByteIterator i_end_ = std::find_if(i_, vec.end(), _1 == 0x03);
        vec.erase(i_, i_end_);

        ASSERT_EQ(508, vec.size());
        ASSERT_EQ(0x00, vec[0]);
        ASSERT_EQ(0xFF, vec[vec.size() - 1]);
    }


    TEST(Urasandesu_CppAnonym_Collections_RapidVectorTest, EraseTest_EqualsOrGreaterThan512_ToEnd_01)
    {
        using namespace std;
        using namespace boost::lambda;
        using namespace Urasandesu::CppAnonym::Collections;
        
        RapidVector<BYTE> vec;
        for (INT i = 0; i < 520; ++i)
            vec.push_back(static_cast<BYTE>(i & 0xFF));
        ASSERT_EQ(520, vec.size());

        boost::remove_erase_if(vec, _1 == 0x00);

        ASSERT_EQ(517, vec.size());
        ASSERT_EQ(0x01, vec[0]);
        ASSERT_EQ(0x07, vec[vec.size() - 1]);
    }


    TEST(Urasandesu_CppAnonym_Collections_RapidVectorTest, EraseTest_EqualsOrGreaterThan512_InBetween_01)
    {
        using namespace std;
        using namespace boost::lambda;
        using namespace Urasandesu::CppAnonym::Collections;
        
        RapidVector<BYTE> vec;
        for (INT i = 0; i < 520; ++i)
            vec.push_back(static_cast<BYTE>(i & 0xFF));
        ASSERT_EQ(520, vec.size());

        typedef RapidVector<BYTE>::iterator ByteIterator;
        ByteIterator i_ = std::find_if(vec.begin(), vec.end(), _1 == 0x80);
        ByteIterator i_end_ = std::find_if(i_, vec.end(), _1 == 0x7F);
        vec.erase(i_, i_end_);

        ASSERT_EQ(265, vec.size());
        ASSERT_EQ(0x00, vec[0]);
        ASSERT_EQ(0x07, vec[vec.size() - 1]);
    }
}
