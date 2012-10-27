#pragma once
#ifndef URASANDESU_CPPANONYM_TRAITS_MAKEHEAPVALUEHOLDERIMPL_H
#define URASANDESU_CPPANONYM_TRAITS_MAKEHEAPVALUEHOLDERIMPL_H

#ifndef URASANDESU_CPPANONYM_SIMPLEHEAP_H
#include <Urasandesu/CppAnonym/SimpleHeap.h>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_HEAPDELETER_H
#include <Urasandesu/CppAnonym/Utilities/HeapDeleter.h>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_MAKEHEAPVALUEHOLDERIMPLFWD_H
#include <Urasandesu/CppAnonym/Traits/MakeHeapValueHolderImplFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Traits {

    template<
        class T, 
        template<class, class> class ValueHolderImpl,
        class Tag
    >
    struct MakeHeapValueHolderImpl
    {
        struct deleter_type;
        typedef ValueHolderImpl<T, deleter_type> type;
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

#endif  // #ifndef URASANDESU_CPPANONYM_TRAITS_MAKEHEAPVALUEHOLDERIMPL_H