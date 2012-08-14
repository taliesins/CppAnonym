#pragma once
#ifndef URASANDESU_CPPANONYM_SIMPLEHEAPFWD_HPP
#define URASANDESU_CPPANONYM_SIMPLEHEAPFWD_HPP

namespace Urasandesu { namespace CppAnonym {
    
    struct DefaultHeap;
    struct QuickHeap;
    struct QuickHeap2;
    struct VeryQuickHeapButMustUseSubscriptOperator;    // Very quick version for small objects allocation.
                                                        // In particular, the size is less than between 32 to 40, and when they are performed a lot of allocation and free.
                                                        // Although must use the subscript operator [] if access the allocated object after a while, 
                                                        // because the allocated objects are moved when the heap is over a threshold size.
    
    namespace Detail {
    
        template<class T, class Tag>
        struct SimpleHeapImpl;

    }   // namespace Detail
    
    template<
        class T, 
        class Tag = DefaultHeap
    >
    class SimpleHeap;

}}  // namespace Urasandesu { namespace CppAnonym {

#endif  // URASANDESU_CPPANONYM_SIMPLEHEAPFWD_HPP