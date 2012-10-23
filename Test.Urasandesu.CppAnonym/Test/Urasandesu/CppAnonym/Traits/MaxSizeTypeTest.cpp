#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_TRAITS_MAXSIZETYPE_H
#include <Urasandesu/CppAnonym/Traits/MaxSizeType.h>
#endif

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_Traits_MaxSizeTypeTest.*
namespace {

    CPPANONYM_TEST(Urasandesu_CppAnonym_Traits_MaxSizeTypeTest, Test_01)
    {
        namespace mpl = boost::mpl;
        using mpl::vector;
        using namespace boost;
        using namespace Urasandesu::CppAnonym::Traits;

        BOOST_MPL_ASSERT((is_same<MaxSizeType<vector<int, double> >::type, double>)); 
        BOOST_MPL_ASSERT((is_same<MaxSizeType<vector<double, int> >::type, double>)); 
    }
}
