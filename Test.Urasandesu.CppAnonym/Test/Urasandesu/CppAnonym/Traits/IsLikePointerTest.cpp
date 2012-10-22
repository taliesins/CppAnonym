#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_TRAITS_ISLIKEPOINTER_H
#include <Urasandesu/CppAnonym/Traits/IsLikePointer.h>
#endif

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_Traits_IsLikePointerTest.*
namespace {

    namespace _FFBD97C5 {

        struct Hoge 
        { 
            Hoge() { }
            Hoge(Hoge const &other) { }
            Hoge &operator=(Hoge const &other) { throw 1; }
            ~Hoge() { }
            Hoge &operator*() const { throw 1; }
            Hoge *operator->() const { throw 1; }
        };

        template<class T>
        struct MyPtr
        {
            MyPtr() { }
            MyPtr(MyPtr<T> const &other) { }
            MyPtr<T> &operator=(MyPtr<T> const &other) { throw 1; }
            ~MyPtr() { }
            T &operator*() const { throw 1; }
            T *operator->() const { throw 1; }
        };

    }   // namespace _FFBD97C5 {

    TEST(Urasandesu_CppAnonym_Traits_IsLikePointerTest, Test_01)
    {
        namespace mpl = boost::mpl;
        using mpl::not_;
        using namespace boost;
        using namespace Urasandesu::CppAnonym::Traits;
        using namespace _FFBD97C5;

        BOOST_MPL_ASSERT((not_<IsLikePointer<int> >));
        BOOST_MPL_ASSERT((IsLikePointer<int *>));
        BOOST_MPL_ASSERT((IsLikePointer<intrusive_ptr<Hoge> >));
        BOOST_MPL_ASSERT((IsLikePointer<shared_ptr<Hoge> >));
        BOOST_MPL_ASSERT((not_<IsLikePointer<Hoge> >));
        BOOST_MPL_ASSERT((IsLikePointer<MyPtr<Hoge> >));
    }
}
