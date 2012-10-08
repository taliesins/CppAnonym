#pragma once
#ifndef URASANDESU_CPPANONYM_COLLECTIONS_RAPIDVECTORFWD_HPP
#define URASANDESU_CPPANONYM_COLLECTIONS_RAPIDVECTORFWD_HPP

namespace Urasandesu { namespace CppAnonym { namespace Collections {

    namespace RapidVectorDetail {

        template<
            class Value, 
            class T, 
            DWORD RAPID_SIZE = 512,
            class Alloc = std::allocator<T>
        >
        class RapidVectorIterator;

    }   // namespace RapidVectorDetail

    template<class T, DWORD RAPID_SIZE = 512, class Alloc = std::allocator<T>>
    class RapidVector;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Collections {

#endif  // URASANDESU_CPPANONYM_COLLECTIONS_RAPIDVECTORFWD_HPP