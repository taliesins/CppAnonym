#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_UTILITIES_ISANYT_H
#include <Urasandesu/CppAnonym/Utilities/IsAnyT.h>
#endif

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_Utilities_IsAnyTTest.*
namespace {

    TEST(Urasandesu_CppAnonym_Utilities_IsAnyTTest, Test_01)
    {
        using namespace Urasandesu::CppAnonym::Utilities;
        using boost::any_cast;
        using boost::shared_ptr;
        using std::find_if;

        typedef std::vector<boost::any> AnyVector;

        AnyVector v;
        v.push_back(shared_ptr<int>(new int(10)));
        v.push_back(shared_ptr<char>(new char('a')));
        v.push_back(shared_ptr<double>(new double(20.)));
        v.push_back(shared_ptr<float>(new float(30.f)));
        
        AnyVector::iterator i, i_end = v.end();
        i = find_if(v.begin(), v.end(), IsAnyT<shared_ptr<char> >()); 
        ASSERT_TRUE(i != i_end);
        ASSERT_EQ('a', *any_cast<shared_ptr<char> >(*i));
    }
}
