// Test.Urasandesu.CppAnonym.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_CPPANONYMEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymException.h>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMNOTIMPLEMENTEDEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymNotImplementedException.h>
#endif

#ifndef URASANDESU_CPPANONYM_SAFEENUM_HPP
#include <Urasandesu/CppAnonym/SafeEnum.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_STACKALLOCATOR_HPP
#include <Urasandesu/CppAnonym/Utilities/StackAllocator.hpp>
#endif


// foward declarations
namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    template <class T, class Heap>
    class SimpleHeapProviderAllocator
    {
    public:
        typedef size_t size_type;
        typedef ptrdiff_t difference_type;
        typedef T *pointer;
        typedef T const *const_pointer;
        typedef T &reference;
        typedef T const &const_reference;
        typedef T value_type;

        template <class U>
        struct rebind
        {
	        typedef SimpleHeapProviderAllocator<U, Heap> other;
        };

        SimpleHeapProviderAllocator(Heap &heap) throw() : m_pHeap(&heap) { }
        template <class U> SimpleHeapProviderAllocator(SimpleHeapProviderAllocator<U, Heap> const &other) throw() : m_pHeap(other.m_pHeap) { }
        ~SimpleHeapProviderAllocator() throw() { }

        pointer allocate(size_type num, void const *hint = NULL)
        {
            return reinterpret_cast<pointer>(m_pHeap->Alloc(num));  // [2012/08/14 12:40:48] あかん・・・サイズが合ってないっぽ。
        }

        void construct(pointer p, T const &value)
        {
            m_pHeap->Construct(p);
        }

        void destroy(pointer p)
        {
            m_pHeap->Destroy(p);
        }

        void deallocate(pointer p, size_type num)
        {
            m_pHeap->Deallocate(p, num);
        }

        pointer address(reference value) const { return &value; }
        const_pointer address(const_reference value) const { return &value; }

        size_type max_size() const throw()
        {
	        return std::numeric_limits<size_t>::max() / sizeof(T);
        }

        Heap *m_pHeap;
    };

    template <class T1, class T2, class Heap>
    bool operator==(SimpleHeapProviderAllocator<T1, Heap> const&, SimpleHeapProviderAllocator<T2, Heap> const&) throw() { return true; }

    template <class T1, class T2, class Heap>
    bool operator!=(SimpleHeapProviderAllocator<T1, Heap> const&, SimpleHeapProviderAllocator<T2, Heap> const&) throw() { return false; }

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {


#ifndef URASANDESU_CPPANONYM_FUSION_APIHOLDERS_DEFAULTFUSIONINFOAPIHOLDER_H
#include <Urasandesu/CppAnonym/Fusion/ApiHolders/DefaultFusionInfoApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_FUSION_BASEFUSIONINFO_HPP
#include <Urasandesu/CppAnonym/Fusion/BaseFusionInfo.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_APIHOLDERS_DEFAULTSTRONGNAMEINFOAPIHOLDER_H
#include <Urasandesu/CppAnonym/StrongNaming/ApiHolders/DefaultStrongNameInfoApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_BASESTRONGNAMEINFO_HPP
#include <Urasandesu/CppAnonym/StrongNaming/BaseStrongNameInfo.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_APIHOLDERS_DEFAULTSTRONGNAMEKEYAPIHOLDER_H
#include <Urasandesu/CppAnonym/StrongNaming/ApiHolders/DefaultStrongNameKeyApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_BASESTRONGNAMEKEY_HPP
#include <Urasandesu/CppAnonym/StrongNaming/BaseStrongNameKey.hpp>
#endif

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_Test2.*
namespace {

    struct Hoge
    {
        Hoge() :
            a(1),
            b(2),
            c(3)
        { std::cout << "Construct Hoge!!" << std::endl; }
        ~Hoge() { std::cout << "Destruct Hoge!!" << std::endl; }
        int a;
        int b;
        int c;
    };

    struct Piyo : 
        public Urasandesu::CppAnonym::SimpleHeapProvider<
            boost::mpl::vector<
                Urasandesu::CppAnonym::ObjectTag<Hoge, Urasandesu::CppAnonym::QuickHeap2>
            >
        >
    {
        typedef Urasandesu::CppAnonym::ObjectTag<Hoge, Urasandesu::CppAnonym::QuickHeap2> hoge_obj_tag_type;
        typedef type_decided_by<hoge_obj_tag_type>::type hoge_heap_type;

        Hoge *Allocate(SIZE_T num)
        {
            using namespace Urasandesu::CppAnonym::Utilities;
            return SimpleHeapProviderAllocator<Hoge, hoge_heap_type>(Of<hoge_obj_tag_type>()).allocate(num);
        }

        void Construct(Hoge *pHoge)
        {
            using namespace Urasandesu::CppAnonym::Utilities;
            return SimpleHeapProviderAllocator<Hoge, hoge_heap_type>(Of<hoge_obj_tag_type>()).construct(pHoge, *pHoge);
        }

        void Destroy(Hoge *pHoge)
        {
            using namespace Urasandesu::CppAnonym::Utilities;
            return SimpleHeapProviderAllocator<Hoge, hoge_heap_type>(Of<hoge_obj_tag_type>()).destroy(pHoge);
        }

        void Deallocate(Hoge *pHoge, SIZE_T num)
        {
            using namespace Urasandesu::CppAnonym::Utilities;
            return SimpleHeapProviderAllocator<Hoge, hoge_heap_type>(Of<hoge_obj_tag_type>()).deallocate(pHoge, num);
        }

        boost::shared_ptr<Hoge> NewHoge()
        {
            using namespace Urasandesu::CppAnonym::Utilities;
            return boost::allocate_shared<Hoge>(boost::pool_allocator<Hoge>());
        }
    };

    CPPANONYM_TEST(Urasandesu_CppAnonym_Test2, Test_01)
    {
        Piyo piyo;
        //Hoge *pHoge = piyo.Allocate(1);
        //piyo.Construct(pHoge);
        //std::cout << "a, b, c = " << pHoge->a << ", " << pHoge->b << ", " << pHoge->c << std::endl;
        //piyo.Destroy(pHoge);
        //piyo.Deallocate(pHoge, 1);
        {
            boost::shared_ptr<Hoge> pHoge1 = piyo.NewHoge();
            boost::shared_ptr<Hoge> pHoge2 = pHoge1;
            std::cout << "a, b, c = " << pHoge2->a << ", " << pHoge2->b << ", " << pHoge2->c << std::endl;
        }
        {
            boost::shared_ptr<Hoge> pHoge1 = piyo.NewHoge();
            boost::shared_ptr<Hoge> pHoge2 = pHoge1;
            std::cout << "a, b, c = " << pHoge2->a << ", " << pHoge2->b << ", " << pHoge2->c << std::endl;
        }
    }

}
