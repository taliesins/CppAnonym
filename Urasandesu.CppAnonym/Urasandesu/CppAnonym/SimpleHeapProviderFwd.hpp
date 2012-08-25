#pragma once
#ifndef URASANDESU_CPPANONYM_SIMPLEHEAPPROVIDERFWD_HPP
#define URASANDESU_CPPANONYM_SIMPLEHEAPPROVIDERFWD_HPP

namespace Urasandesu { namespace CppAnonym {

    namespace Detail {
        
        template<class ObjectTagSequence, class I, class IEnd>
        class ATL_NO_VTABLE SimpleHeapProviderImpl;

    }   // namespace Detail


    template<class ObjectTagSequence>
    class ATL_NO_VTABLE SimpleHeapProvider;

}}   // namespace Urasandesu { namespace CppAnonym {

#endif  // #ifndef URASANDESU_CPPANONYM_SIMPLEHEAPPROVIDERFWD_HPP