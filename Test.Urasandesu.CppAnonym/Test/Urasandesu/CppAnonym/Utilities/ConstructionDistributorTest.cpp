#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_UTILITIES_CONSTRUCTIONDISTRIBUTOR_HPP
#include <Urasandesu/CppAnonym/Utilities/ConstructionDistributor.hpp>
#endif

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_Utilities_ConstructionDistributorTest.*
namespace {

    TEST(Urasandesu_CppAnonym_Utilities_ConstructionDistributorTest, RawPointerTest_01)
    {
        using namespace Urasandesu::CppAnonym::Traits;
        using namespace Urasandesu::CppAnonym::Utilities;
        
        BYTE buf[sizeof(int *)];

        ConstructionDistributor<int *>::Construct(buf);

        int *&p = reinterpret_cast<int *&>(buf);
        ASSERT_FALSE(p);
    }





    TEST(Urasandesu_CppAnonym_Utilities_ConstructionDistributorTest, RawPointerTest_02)
    {
        using namespace Urasandesu::CppAnonym::Traits;
        using namespace Urasandesu::CppAnonym::Utilities;
        
        BYTE buf[sizeof(int *)];

        ConstructionDistributor<int *>::Construct(buf, new int(10));

        int *&p = reinterpret_cast<int *&>(buf);
        ASSERT_TRUE(p != NULL);
        ASSERT_EQ(10, *p);

        delete p;
    }





    TEST(Urasandesu_CppAnonym_Utilities_ConstructionDistributorTest, SmartPointerTest_01)
    {
        using namespace boost;
        using namespace Urasandesu::CppAnonym::Traits;
        using namespace Urasandesu::CppAnonym::Utilities;
        
        BYTE buf[sizeof(shared_ptr<int>)];

        ConstructionDistributor<shared_ptr<int> >::Construct(buf);

        shared_ptr<int> &p = reinterpret_cast<shared_ptr<int> &>(buf);
        ASSERT_FALSE(p);
    }





    TEST(Urasandesu_CppAnonym_Utilities_ConstructionDistributorTest, SmartPointerTest_02)
    {
        using namespace boost;
        using namespace Urasandesu::CppAnonym::Traits;
        using namespace Urasandesu::CppAnonym::Utilities;
        
        BYTE buf[sizeof(shared_ptr<int>)];

        ConstructionDistributor<shared_ptr<int> >::Construct(buf, new int(10));

        shared_ptr<int> &p = reinterpret_cast<shared_ptr<int> &>(buf);
        ASSERT_TRUE(p);
        ASSERT_EQ(10, *p);

        p.~shared_ptr<int>();
    }

}
