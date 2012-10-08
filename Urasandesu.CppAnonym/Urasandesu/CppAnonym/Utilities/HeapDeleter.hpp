#pragma once
#ifndef URASANDESU_CPPANONYM_UTILITIES_HEAPDELETER_HPP
#define URASANDESU_CPPANONYM_UTILITIES_HEAPDELETER_HPP

#ifndef URASANDESU_CPPANONYM_UTILITIES_HEAPDELETERFWD_HPP
#include <Urasandesu/CppAnonym/Utilities/HeapDeleterFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    namespace HeapDeleterDetail {

        class HeapDeleterImpl
        {
        public:
            template<class Heap>
            HeapDeleterImpl(Heap &heap) : 
                m_pHeap(&heap)
            { }

            template<class Heap, class T>
            void operator()(T *p)
            {
                static_cast<Heap *>(m_pHeap)->Delete(p);
            }

        private:
            void *m_pHeap;
        };

    }   // namespace HeapDeleterDetail {

    template<class Heap>
    class HeapDeleter : 
        HeapDeleterDetail::HeapDeleterImpl
    {
    public:
        typedef HeapDeleter<Heap> this_type;
        typedef HeapDeleterDetail::HeapDeleterImpl base_type;
        
        HeapDeleter(Heap &heap) : 
            base_type(&heap) 
        { }
        
        template<class T>
        void operator()(T *p) 
        { 
            base_type::operator()<Heap>(p);
        }
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_HEAPDELETER_HPP