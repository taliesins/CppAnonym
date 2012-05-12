#pragma once
#ifndef URASANDESU_CPPANONYM_HEAPPROVIDERFWD_HPP
#define URASANDESU_CPPANONYM_HEAPPROVIDERFWD_HPP

namespace Urasandesu { namespace CppAnonym {
    
    namespace Detail {
        
        template<
            class Key, 
            class Sequence, 
            class I, 
            class IEnd,
            class Hash = boost::hash<Key>,
            class EqualTo = std::equal_to<Key>,
            class Allocator = std::allocator<std::pair<const Key, SIZE_T>>
        >
        class ATL_NO_VTABLE HeapProviderImpl;

    }   // namespace Detail


    template<
        class Key, 
        class Sequence,
        class Hash = boost::hash<Key>,
        class EqualTo = std::equal_to<Key>,
        class Allocator = std::allocator<std::pair<const Key, SIZE_T>>
    >
    class ATL_NO_VTABLE HeapProvider;

}}   // namespace Urasandesu { namespace CppAnonym {

#endif  // #ifndef URASANDESU_CPPANONYM_HEAPPROVIDERFWD_HPP