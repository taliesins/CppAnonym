#pragma once
#ifndef URASANDESU_CPPANONYM_SMARTPTRCHAINCONSTRUCTOR_HPP
#define URASANDESU_CPPANONYM_SMARTPTRCHAINCONSTRUCTOR_HPP

#ifndef URASANDESU_CPPANONYM_SMARTPTRCHAINCONSTRUCTOR_H
#include <Urasandesu/CppAnonym/SmartPtrChainConstructor.h>
#endif

namespace Urasandesu { namespace CppAnonym {

    template<
        class T,
        class PersistableHeapProvider
    >
    static Utilities::TempPtr<T> SmartPtrChainConstructor::NewRootObject(PersistableHeapProvider &provider)
    {
        return provider.NewObject();
    }

    template<
        class T,
        class Current,
        class PersistableHeapProvider
    >
    static Utilities::TempPtr<T> SmartPtrChainConstructor::NewObject(Current &current, PersistableHeapProvider &provider)
    {
        typedef typename Current::current_type previous_type;
        Utilities::TempPtr<T> pObj(provider.NewObject());
        pObj->ChainFrom<previous_type>().SetPrevious(current);
        return pObj;
    }

}}   // namespace Urasandesu { namespace CppAnonym {

#endif  // #ifndef URASANDESU_CPPANONYM_SMARTPTRCHAINCONSTRUCTOR_HPP