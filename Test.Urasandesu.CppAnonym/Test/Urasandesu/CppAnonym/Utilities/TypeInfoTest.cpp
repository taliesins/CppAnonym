#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_UTILITIES_TYPEINFO_H
#include <Urasandesu/CppAnonym/Utilities/TypeInfo.h>
#endif

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_Utilities_TypeInfoTest.*
namespace {

    TEST(Urasandesu_CppAnonym_Utilities_TypeInfoTest, EmptyTest_01)
    {
        using namespace Urasandesu::CppAnonym::Utilities;

        TypeInfo p;
        ASSERT_TRUE(p.IsEmpty());
    }





    TEST(Urasandesu_CppAnonym_Utilities_TypeInfoTest, Test_01)
    {
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym::Utilities;
        using mpl::identity;


        TypeInfo p = identity<int>();
        ASSERT_FALSE(p.IsEmpty());
        ASSERT_TRUE(p.Is<int>());
        ASSERT_FALSE(p.Is<char>());
        ASSERT_STREQ(typeid(int).raw_name(), p.GetRawName().c_str());
    }





    TEST(Urasandesu_CppAnonym_Utilities_TypeInfoTest, Test_02)
    {
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym::Utilities;
        using mpl::identity;


        TypeInfo p1 = identity<int>();
        TypeInfo p2 = identity<int>();
        TypeInfo p3 = identity<char>();
        ASSERT_EQ(p1, p2);
        ASSERT_NE(p2, p3);
    }





    TEST(Urasandesu_CppAnonym_Utilities_TypeInfoTest, Test_03)
    {
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym::Utilities;
        using boost::unordered_map;
        using mpl::identity;

        typedef unordered_map<TypeInfo, SIZE_T, TypeInfoHash, TypeInfoEqualTo> TypeInfoToIndexMap;

        TypeInfo p1 = identity<int>();
        TypeInfo p2 = identity<int>();
        TypeInfo p3 = identity<char>();
        TypeInfoToIndexMap infoToIndex;

        TypeInfoToIndexMap::iterator i, i_end = infoToIndex.end();

        i = infoToIndex.find(p1);
        ASSERT_TRUE(i == i_end);
        
        infoToIndex[p1] = 42;
        i = infoToIndex.find(p1);
        ASSERT_FALSE(i == i_end);
        ASSERT_EQ(42, (*i).second);

        i = infoToIndex.find(p2);
        ASSERT_FALSE(i == i_end);
        ASSERT_EQ(42, (*i).second);

        i = infoToIndex.find(p3);
        ASSERT_TRUE(i == i_end);
    }
}
