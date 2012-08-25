#pragma once
#ifndef URASANDESU_CPPANONYM_DISPOSABLEHEAPPROVIDERFWD_HPP
#define URASANDESU_CPPANONYM_DISPOSABLEHEAPPROVIDERFWD_HPP

namespace Urasandesu { namespace CppAnonym {

    namespace Detail {
        
        template<class Sequence, class I, class IEnd>
        class DisposableHeapProviderImpl;

    }   // namespace Detail


    template<class Sequence>
    class DisposableHeapProvider;

}}   // namespace Urasandesu { namespace CppAnonym {

#endif  // #ifndef URASANDESU_CPPANONYM_DISPOSABLEHEAPPROVIDERFWD_HPP