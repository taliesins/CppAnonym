#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_COLLECTIONS_ITERABLE_H
#include <Urasandesu/CppAnonym/Collections/Iterable.h>
#endif

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_Collections_IterableTest.*
namespace {

    CPPANONYM_TEST(Urasandesu_CppAnonym_Collections_IterableTest, SequenceEqualTest_SameValueSameSize_01)
    {
        using namespace Urasandesu::CppAnonym::Collections;
        using boost::assign::operator +=;
        using std::vector;

        vector<int> v1;
        v1 += 1, 2, 3;

        vector<int> v2;
        v2 += 1, 2, 3;
        
        ASSERT_TRUE(SequenceEqual(v1.begin(), v1.end(), v2.begin(), v2.end())); 
    }

    
    
    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_Collections_IterableTest, SequenceEqualTest_SameValueSameSizeDifferentContainer_01)
    {
        using namespace Urasandesu::CppAnonym::Collections;
        using boost::assign::operator +=;
        using std::vector;
        using std::list;

        vector<int> v1;
        v1 += 1, 2, 3;

        list<int> v2;
        v2 += 1, 2, 3;
        
        ASSERT_TRUE(SequenceEqual(v1.begin(), v1.end(), v2.begin(), v2.end())); 
    }

    
    
    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_Collections_IterableTest, SequenceEqualTest_DifferentSize_01)
    {
        using namespace Urasandesu::CppAnonym::Collections;
        using boost::assign::operator +=;
        using std::vector;

        vector<int> v1;
        v1 += 1, 2, 3;

        vector<int> v2;
        v2 += 1, 2;
        
        ASSERT_FALSE(SequenceEqual(v1.begin(), v1.end(), v2.begin(), v2.end())); 
    }

    
    
    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_Collections_IterableTest, SequenceEqualTest_DifferentSize_02)
    {
        using namespace Urasandesu::CppAnonym::Collections;
        using boost::assign::operator +=;
        using std::vector;

        vector<int> v1;
        v1 += 1, 2;

        vector<int> v2;
        v2 += 1, 2, 3;
        
        ASSERT_FALSE(SequenceEqual(v1.begin(), v1.end(), v2.begin(), v2.end())); 
    }





    CPPANONYM_TEST(Urasandesu_CppAnonym_Collections_IterableTest, SequenceEqualTest_DifferentValue_01)
    {
        using namespace Urasandesu::CppAnonym::Collections;
        using boost::assign::operator +=;
        using std::vector;

        vector<int> v1;
        v1 += 1, 3, 2;

        vector<int> v2;
        v2 += 1, 2, 3;
        
        ASSERT_FALSE(SequenceEqual(v1.begin(), v1.end(), v2.begin(), v2.end())); 
    }





    CPPANONYM_TEST(Urasandesu_CppAnonym_Collections_IterableTest, SequenceHashValueTest_01)
    {
        using namespace Urasandesu::CppAnonym::Collections;
        using std::vector;

        vector<int const *> v;
        v.push_back(reinterpret_cast<int const *>(1));
        v.push_back(reinterpret_cast<int const *>(2));
        v.push_back(reinterpret_cast<int const *>(3));

        ASSERT_EQ(4216901971, SequenceHashValue(v.begin(), v.end())); 
    }
}
