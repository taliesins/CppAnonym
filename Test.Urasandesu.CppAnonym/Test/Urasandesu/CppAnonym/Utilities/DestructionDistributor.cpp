#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_UTILITIES_DESTRUCTIONDISTRIBUTOR_HPP
#include <Urasandesu/CppAnonym/Utilities/DestructionDistributor.hpp>
#endif

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_Utilities_DestructionDistributorTest.*
namespace {

    TEST(Urasandesu_CppAnonym_Utilities_DestructionDistributorTest, DestructTest_Int_01)
    {
        using namespace Urasandesu::CppAnonym;

        // Arrange
        typedef Utilities::DestructionDistributor<int> IntDestructor;
        int i = 10;


        // Act
        IntDestructor::Destruct(i);


        // Assert
        // If this test case fails, SEHException will occur.
    }

    
    struct POD
    {
        int i;
    };

    TEST(Urasandesu_CppAnonym_Utilities_DestructionDistributorTest, DestructTest_POD_01)
    {
        using namespace Urasandesu::CppAnonym;

        // Arrange
        typedef Utilities::DestructionDistributor<POD> PODDestructor;
        POD pod;
        pod.i = 20;


        // Act
        PODDestructor::Destruct(pod);


        // Assert
        // If this test case fails, SEHException will occur.
    }


    TEST(Urasandesu_CppAnonym_Utilities_DestructionDistributorTest, DestructTest_POD_02)
    {
        using namespace Urasandesu::CppAnonym;

        // Arrange
        typedef Utilities::DestructionDistributor<POD *> PODPointerDestructor;
        BYTE b[sizeof(POD)];
        POD *pPod = reinterpret_cast<POD *>(b);
#pragma warning(push)
#pragma warning(disable: 4345)
        new(pPod)POD();
#pragma warning(pop)


        // Act
        PODPointerDestructor::Destruct(pPod);


        // Assert
        // If this test case fails, SEHException will occur.
    }


    struct DestructionChecker
    {
        DestructionChecker() : Destructed(false) { }
        static DestructionChecker &Instance() { static DestructionChecker c; return c; }
        bool Destructed;
    };
    struct NotPOD
    {
        NotPOD() { DestructionChecker::Instance().Destructed = false; }
        ~NotPOD() { DestructionChecker::Instance().Destructed = true; }
        int i;
    };

    TEST(Urasandesu_CppAnonym_Utilities_DestructionDistributorTest, DestructTest_NotPOD_01)
    {
        using namespace Urasandesu::CppAnonym;

        // Arrange
        typedef Utilities::DestructionDistributor<NotPOD> NotPODDestructor;
        BYTE b[sizeof(NotPOD)];
        NotPOD *pNotPod = reinterpret_cast<NotPOD *>(b);
        new(pNotPod)NotPOD();
        ASSERT_FALSE(DestructionChecker::Instance().Destructed);


        // Act
        NotPODDestructor::Destruct(*pNotPod);


        // Assert
        ASSERT_TRUE(DestructionChecker::Instance().Destructed);
    }


    TEST(Urasandesu_CppAnonym_Utilities_DestructionDistributorTest, DestructTest_NotPOD_02)
    {
        using namespace Urasandesu::CppAnonym;

        // Arrange
        typedef Utilities::DestructionDistributor<NotPOD *> NotPODPointerDestructor;
        BYTE b[sizeof(NotPOD)];
        NotPOD *pNotPod = reinterpret_cast<NotPOD *>(b);
        new(pNotPod)NotPOD();
        ASSERT_FALSE(DestructionChecker::Instance().Destructed);


        // Act
        NotPODPointerDestructor::Destruct(pNotPod);


        // Assert
        ASSERT_TRUE(DestructionChecker::Instance().Destructed);
    }
}
