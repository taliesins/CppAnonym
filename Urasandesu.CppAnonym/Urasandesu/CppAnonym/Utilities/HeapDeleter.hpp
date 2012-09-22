#pragma once
#ifndef URASANDESU_CPPANONYM_UTILITIES_HEAPDELETER_HPP
#define URASANDESU_CPPANONYM_UTILITIES_HEAPDELETER_HPP

#ifndef URASANDESU_CPPANONYM_UTILITIES_HEAPDELETERFWD_HPP
#include <Urasandesu/CppAnonym/Utilities/HeapDeleterFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    template<class Heap>
    class HeapDeleter
    {
    public:
        typedef HeapDeleter<Heap> this_type;
        
        HeapDeleter(Heap &heap) : 
            m_pHeap(&heap) 
        { }

        template<class T>
        void operator()(T *p) 
        { 
            m_pHeap->Delete(p);
        }
    private:
        Heap *m_pHeap;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#ifndef URASANDESU_CPPANONYM_SIMPLEHEAP_HPP
#include <Urasandesu/CppAnonym/SimpleHeap.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Traits {

    //template<
    //    class T, 
    //    class TD, 
    //    class ImplD, 
    //    template<class, class, class> class PointerHolderImpl
    //>
    //struct MakePointerHolderImpl
    //{
    //    typedef PointerHolderImpl<T, TD, ImplD> type;
    //};

    //template<
    //    class T, 
    //    template<class, class, class> class PointerHolderImpl,
    //    class Tag = QuickHeapWithoutSubscriptOperator
    //>
    //struct MakeHeapPointerHolderImpl
    //{
    //    typedef SimpleHeap<T, Tag> object_heap_type;
    //    typedef Utilities::HeapDeleter<object_heap_type> object_deleter_type;
    //    struct deleter_type;
    //    typedef PointerHolderImpl<T, object_deleter_type, deleter_type> type;
    //    typedef SimpleHeap<type, Tag> heap_type;
    //    struct deleter_type : 
    //        Utilities::HeapDeleter<heap_type>
    //    {
    //        typedef Utilities::HeapDeleter<heap_type> base_type;
    //            
    //        deleter_type(heap_type &heap) : 
    //            base_type(heap)
    //        { }

    //        template<class T>
    //        void operator()(T *p) 
    //        { 
    //            base_type::operator()(p);
    //        }
    //    };
    //};

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Traits {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_HEAPDELETER_HPP