#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_STATICDEPENDENTOBJECTSSTORAGE_HPP
#include <Urasandesu/CppAnonym/StaticDependentObjectsStorage.hpp>
#endif

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_StaticDependentObjectsStorageTest.*
namespace {

    TEST(Urasandesu_CppAnonym_StaticDependentObjectsStorageTest, Test_01)
    {
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym;

        typedef StaticDependentObjectsStorage<mpl::vector<int, long, float, double> > MyStorage;

        MyStorage::Object<int>() = 10;
        MyStorage::Object<long>() = 20L;
        MyStorage::Object<float>() = 30.f;
        MyStorage::Object<double>() = 40.;

        ASSERT_EQ(10, MyStorage::Object<int>());
        ASSERT_EQ(20L, MyStorage::Object<long>());
        ASSERT_EQ(30.f, MyStorage::Object<float>());
        ASSERT_EQ(40., MyStorage::Object<double>());
    }
}
