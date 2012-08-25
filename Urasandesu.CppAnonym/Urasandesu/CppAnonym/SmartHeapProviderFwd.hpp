#pragma once
#ifndef URASANDESU_CPPANONYM_SMARTHEAPPROVIDERFWD_HPP
#define URASANDESU_CPPANONYM_SMARTHEAPPROVIDERFWD_HPP

namespace Urasandesu { namespace CppAnonym {

    namespace Detail {
        
        template<class Sequence, class I, class IEnd>
        class SmartHeapProviderImpl;

    }   // namespace Detail


    template<class Sequence>
    class SmartHeapProvider;

}}   // namespace Urasandesu { namespace CppAnonym {

#endif  // #ifndef URASANDESU_CPPANONYM_SMARTHEAPPROVIDERFWD_HPP