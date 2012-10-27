#pragma once
#ifndef URASANDESU_CPPANONYM_UTILITIES_HEAPDELETER_H
#define URASANDESU_CPPANONYM_UTILITIES_HEAPDELETER_H

#ifndef URASANDESU_CPPANONYM_UTILITIES_HEAPDELETERFWD_H
#include <Urasandesu/CppAnonym/Utilities/HeapDeleterFwd.h>
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

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_HEAPDELETER_H