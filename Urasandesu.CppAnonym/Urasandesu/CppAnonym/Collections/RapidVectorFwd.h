#pragma once
#ifndef URASANDESU_CPPANONYM_COLLECTIONS_RAPIDVECTORFWD_H
#define URASANDESU_CPPANONYM_COLLECTIONS_RAPIDVECTORFWD_H

namespace Urasandesu { namespace CppAnonym { namespace Collections {

    namespace Detail {

        template<
            class Value, 
            class T, 
            class Alloc = std::allocator<T>, 
            DWORD RAPID_SIZE = 512
        >
        class RapidVectorIterator;

    }   // namespace Detail

    template<class T, class Alloc = std::allocator<T>, DWORD RAPID_SIZE = 512>
    class RapidVector;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Collections {

#endif  // URASANDESU_CPPANONYM_COLLECTIONS_RAPIDVECTORFWD_H