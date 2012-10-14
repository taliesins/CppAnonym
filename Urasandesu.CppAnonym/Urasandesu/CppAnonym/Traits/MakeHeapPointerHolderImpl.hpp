#pragma once
#ifndef URASANDESU_CPPANONYM_TRAITS_MAKEHEAPPOINTERHOLDERIMPL_HPP
#define URASANDESU_CPPANONYM_TRAITS_MAKEHEAPPOINTERHOLDERIMPL_HPP

#ifndef URASANDESU_CPPANONYM_SIMPLEHEAP_H
#include <Urasandesu/CppAnonym/SimpleHeap.h>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_HEAPDELETER_HPP
#include <Urasandesu/CppAnonym/Utilities/HeapDeleter.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_MAKEHEAPPOINTERHOLDERIMPLFWD_HPP
#include <Urasandesu/CppAnonym/Traits/MakeHeapPointerHolderImplFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Traits {

    template<
        class T, 
        template<class, class, class> class PointerHolderImpl,
        class Tag
    >
    struct MakeHeapPointerHolderImpl
    {
        typedef SimpleHeap<T, Tag> object_heap_type;
        typedef Utilities::HeapDeleter<object_heap_type> object_deleter_type;
        struct deleter_type;
        typedef PointerHolderImpl<T, object_deleter_type, deleter_type> type;
        typedef SimpleHeap<type, Tag> heap_type;
        struct deleter_type : 
            Utilities::HeapDeleter<heap_type>
        {
            typedef Utilities::HeapDeleter<heap_type> base_type;
                
            deleter_type(heap_type &heap) : 
                base_type(heap)
            { }

            template<class T>
            void operator()(T *p) 
            { 
                base_type::operator()(p);
            }
        };
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Traits {

#endif  // #ifndef URASANDESU_CPPANONYM_TRAITS_MAKEHEAPPOINTERHOLDERIMPL_HPP