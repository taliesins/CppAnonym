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

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_HEAPDELETER_HPP