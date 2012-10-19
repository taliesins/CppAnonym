#pragma once
#ifndef URASANDESU_CPPANONYM_COLLECTIONS_RAPIDVECTORFWD_H
#define URASANDESU_CPPANONYM_COLLECTIONS_RAPIDVECTORFWD_H

namespace Urasandesu { namespace CppAnonym { namespace Collections {

    namespace RapidVectorDetail {

        template<
            class Value, 
            class T, 
            DWORD RAPID_SIZE = 512,
            class Alloc = std::allocator<T>
        >
        class RapidVectorIterator;

        template<class T, DWORD RAPID_SIZE, class Alloc>
        class RapidVectorImpl;

    }   // namespace RapidVectorDetail

    template<class T, DWORD RAPID_SIZE = 512, class Alloc = std::allocator<T>>
    struct RapidVector;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Collections {

#endif  // URASANDESU_CPPANONYM_COLLECTIONS_RAPIDVECTORFWD_H