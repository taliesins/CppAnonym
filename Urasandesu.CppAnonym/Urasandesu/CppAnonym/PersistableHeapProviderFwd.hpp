#pragma once
#ifndef URASANDESU_CPPANONYM_PERSISTABLEHEAPPROVIDERFWD_HPP
#define URASANDESU_CPPANONYM_PERSISTABLEHEAPPROVIDERFWD_HPP

namespace Urasandesu { namespace CppAnonym {

    namespace Detail {
        
        template<class Sequence, class I, class IEnd>
        class PersistableHeapProviderImpl;

    }   // namespace Detail


    template<class Sequence>
    class PersistableHeapProvider;

}}   // namespace Urasandesu { namespace CppAnonym {

#endif  // #ifndef URASANDESU_CPPANONYM_PERSISTABLEHEAPPROVIDERFWD_HPP