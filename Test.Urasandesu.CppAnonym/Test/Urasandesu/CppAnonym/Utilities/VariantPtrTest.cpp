#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_UTILITIES_VARIANTPTR_HPP
#include <Urasandesu/CppAnonym/Utilities/VariantPtr.hpp>
#endif

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_Utilities_VariantPtrTest.*
namespace {

    namespace _AE9B0ABB {

        namespace mpl = boost::mpl;
        using namespace boost;
        
        struct Hoge
        {
            typedef Hoge this_type;

            Hoge() : m_useCount(0), m_value(0) { }
            Hoge(INT value) : m_useCount(0), m_value(value) { }

            inline friend void intrusive_ptr_add_ref(this_type *p)
            {
                ++p->m_useCount;
            }

            inline friend void intrusive_ptr_release(this_type *p)
            {
                if(--p->m_useCount == 0) 
                    delete p;
            }
            
            LONG m_useCount;
            INT m_value;
        };
    
    }   // namespace _AE9B0ABB {

    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_VariantPtrTest, SizeTest_01)
    {
        namespace mpl = boost::mpl;
        using namespace boost;
        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Utilities;
        using namespace _AE9B0ABB;

        typedef VariantPtr<Hoge *, intrusive_ptr<Hoge> > MyVariantPtr;
#ifdef _DEBUG
        BOOST_MPL_ASSERT_RELATION(sizeof(MyVariantPtr), ==, sizeof(intrusive_ptr<Hoge>) + sizeof(INT));
#else
        BOOST_MPL_ASSERT_RELATION(sizeof(MyVariantPtr), ==, sizeof(intrusive_ptr<Hoge>));
#endif
    }




    
    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_VariantPtrTest, Test_01)
    {
        namespace mpl = boost::mpl;
        using namespace boost;
        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Utilities;
        using namespace _AE9B0ABB;

        typedef VariantPtr<Hoge *, intrusive_ptr<Hoge> > MyVariantPtr;
        
        MyVariantPtr p;
        ASSERT_FALSE(p);
    }





    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_VariantPtrTest, Test_02)
    {
        namespace mpl = boost::mpl;
        using namespace boost;
        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Utilities;
        using namespace _AE9B0ABB;

        typedef VariantPtr<Hoge *, intrusive_ptr<Hoge> > MyVariantPtr;
        
        Hoge *pHoge = new Hoge();
        ASSERT_EQ(0, pHoge->m_useCount);
        {
            MyVariantPtr p(pHoge);
            ASSERT_EQ(0, pHoge->m_useCount);
            ASSERT_TRUE(p);
            p.Clear<Hoge *>();
        }
        ASSERT_EQ(0, pHoge->m_useCount);
        
        delete pHoge;
    }





    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_VariantPtrTest, Test_03)
    {
        namespace mpl = boost::mpl;
        using namespace boost;
        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Utilities;
        using namespace _AE9B0ABB;

        typedef VariantPtr<Hoge *, intrusive_ptr<Hoge> > MyVariantPtr;
        
        intrusive_ptr<Hoge> pHoge(new Hoge());
        ASSERT_EQ(1, pHoge->m_useCount);
        {
            MyVariantPtr p(pHoge);
            ASSERT_EQ(2, pHoge->m_useCount);
            ASSERT_TRUE(p);
            p.Clear<intrusive_ptr<Hoge> >();
        }
        ASSERT_EQ(1, pHoge->m_useCount);
    }





    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_VariantPtrTest, Test_04)
    {
        namespace mpl = boost::mpl;
        using namespace boost;
        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Utilities;
        using namespace _AE9B0ABB;

        typedef VariantPtr<Hoge *, intrusive_ptr<Hoge> > MyVariantPtr;
        
        Hoge *pHoge = new Hoge(42);
        ASSERT_EQ(0, pHoge->m_useCount);

        MyVariantPtr p1(pHoge);
        ASSERT_EQ(0, pHoge->m_useCount);
        
        MyVariantPtr p2;
        p2.Assign<Hoge *>(p1);
        ASSERT_EQ(0, pHoge->m_useCount);

        Hoge *&pHoge_ = p2.Get<Hoge *>();
        ASSERT_EQ(0, pHoge->m_useCount);
        ASSERT_EQ(42, pHoge_->m_value);

        p2.Clear<Hoge *>();
        ASSERT_EQ(0, pHoge->m_useCount);

        p1.Clear<Hoge *>();
        ASSERT_EQ(0, pHoge->m_useCount);

        delete pHoge;
    }





    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_VariantPtrTest, Test_05)
    {
        namespace mpl = boost::mpl;
        using namespace boost;
        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Utilities;
        using namespace _AE9B0ABB;

        typedef VariantPtr<Hoge *, intrusive_ptr<Hoge> > MyVariantPtr;
        
        intrusive_ptr<Hoge> pHoge(new Hoge(42));
        ASSERT_EQ(1, pHoge->m_useCount);

        MyVariantPtr p1(pHoge);
        ASSERT_EQ(2, pHoge->m_useCount);
        
        MyVariantPtr p2;
        p2.Assign<intrusive_ptr<Hoge> >(p1);
        ASSERT_EQ(3, pHoge->m_useCount);

        intrusive_ptr<Hoge> &pHoge_ = p2.Get<intrusive_ptr<Hoge> >();
        ASSERT_EQ(3, pHoge->m_useCount);
        ASSERT_EQ(42, pHoge_->m_value);

        p2.Clear<intrusive_ptr<Hoge> >();
        ASSERT_EQ(2, pHoge->m_useCount);

        p1.Clear<intrusive_ptr<Hoge> >();
        ASSERT_EQ(1, pHoge->m_useCount);
    }





    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_VariantPtrTest, Test_06)
    {
        namespace mpl = boost::mpl;
        using namespace boost;
        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Utilities;
        using namespace _AE9B0ABB;

        typedef VariantPtr<Hoge *, intrusive_ptr<Hoge> > MyVariantPtr;
        
        Hoge *pHoge = new Hoge(42);
        ASSERT_EQ(0, pHoge->m_useCount);

        MyVariantPtr p(pHoge);
        ASSERT_EQ(0, pHoge->m_useCount);

        Hoge *pHoge_ = p.Detach<Hoge *>();
        ASSERT_EQ(0, pHoge->m_useCount);
        ASSERT_EQ(42, pHoge_->m_value);

        p.Clear<Hoge *>();
        ASSERT_EQ(0, pHoge->m_useCount);    // no effect

        delete pHoge;
    }





    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_VariantPtrTest, Test_07)
    {
        namespace mpl = boost::mpl;
        using namespace boost;
        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Utilities;
        using namespace _AE9B0ABB;

        typedef VariantPtr<Hoge *, intrusive_ptr<Hoge> > MyVariantPtr;
        
        intrusive_ptr<Hoge> pHoge(new Hoge(42));
        ASSERT_EQ(1, pHoge->m_useCount);

        MyVariantPtr p(pHoge);
        ASSERT_EQ(2, pHoge->m_useCount);

        intrusive_ptr<Hoge> pHoge_ = p.Detach<intrusive_ptr<Hoge> >();
        ASSERT_EQ(2, pHoge->m_useCount);
        ASSERT_EQ(42, pHoge_->m_value);

        p.Clear<intrusive_ptr<Hoge> >();    // no effect
        ASSERT_EQ(2, pHoge->m_useCount);
    }

    
    
    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_VariantPtrTest, CarryStateTest_01)
    {
        namespace mpl = boost::mpl;
        using namespace boost;
        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Traits;
        using namespace Urasandesu::CppAnonym::Utilities;
        using namespace _AE9B0ABB;

        typedef VariantPtr<Hoge *, intrusive_ptr<Hoge> > MyVariantPtr;

        bool carriesState = true;
        
        Hoge *pHoge = new Hoge(42);

        MyVariantPtr p1;
        if (!carriesState)
            p1.Set<intrusive_ptr<Hoge> >(pHoge);
        else
            p1.Set<Hoge *>(pHoge);
        ASSERT_EQ(0, pHoge->m_useCount);
        ASSERT_EQ(42, pHoge->m_value);

        MyVariantPtr p2;
        if (!carriesState)
            p2.Assign<intrusive_ptr<Hoge> >(p1);
        else
            p2.Assign<Hoge *>(p1);
        ASSERT_EQ(0, pHoge->m_useCount);
        ASSERT_EQ(42, pHoge->m_value);

        if (!carriesState)
            p2.Clear<intrusive_ptr<Hoge> >();
        else
            p2.Clear<Hoge *>();

        if (!carriesState)
            p1.Clear<intrusive_ptr<Hoge> >();
        else
            p1.Clear<Hoge *>();

        ASSERT_EQ(42, pHoge->m_value);  // VariantPtr gives no effect against an raw pointer.
        delete pHoge;                   // Therefore, the state is carried to next and the heap area shall be deleted manually.
    }

    
    
    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_VariantPtrTest, CarryStateTest_02)
    {
        namespace mpl = boost::mpl;
        using namespace boost;
        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Traits;
        using namespace Urasandesu::CppAnonym::Utilities;
        using namespace _AE9B0ABB;

        typedef VariantPtr<Hoge *, intrusive_ptr<Hoge> > MyVariantPtr;

        bool carriesState = false;
        
        Hoge *pHoge = new Hoge(42);

        MyVariantPtr p1;
        if (!carriesState)
            p1.Set<intrusive_ptr<Hoge> >(pHoge);
        else
            p1.Set<Hoge *>(pHoge);
        ASSERT_EQ(1, pHoge->m_useCount);
        ASSERT_EQ(42, pHoge->m_value);

        MyVariantPtr p2;
        if (!carriesState)
            p2.Assign<intrusive_ptr<Hoge> >(p1);
        else
            p2.Assign<Hoge *>(p1);
        ASSERT_EQ(2, pHoge->m_useCount);
        ASSERT_EQ(42, pHoge->m_value);

        if (!carriesState)
            p2.Clear<intrusive_ptr<Hoge> >();
        else
            p2.Clear<Hoge *>();

        if (!carriesState)
            p1.Clear<intrusive_ptr<Hoge> >();
        else
            p1.Clear<Hoge *>();
        
#ifdef _DEBUG                           // VariantPtr invokes its constructor/destructor against an smart pointer. 
        ASSERT_NE(42, pHoge->m_value);  // In this case, the runtime probably indicates an invalid value because the pointer is filled with the debugging value.
#else
        ASSERT_EQ(42, pHoge->m_value);  // In this case, the runtime probably doesn't give any effect.
#endif
    }
}
