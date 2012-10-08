#pragma once
#ifndef URASANDESU_CPPANONYM_SMARTPTRCHAINCONSTRUCTOR_HPP
#define URASANDESU_CPPANONYM_SMARTPTRCHAINCONSTRUCTOR_HPP

#ifndef URASANDESU_CPPANONYM_SMARTPTRCHAINCONSTRUCTORFWD_HPP
#include <Urasandesu/CppAnonym/SmartPtrChainConstructorFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym {

    struct SmartPtrChainConstructor
    {
        template<
            class T,
            class PersistableHeapProvider
        >
        static typename PersistableHeapProvider::sp_object_type NewRootObject()
        {
            return PersistableHeapProvider::NewStaticObject();
        }

        template<
            class T,
            class Current,
            class HeapProvider
        >
        static T *NewObject(Current &current, HeapProvider &provider)
        {
            typedef typename Current::current_type previous_type;
            T *pObj = provider.NewObject();
            pObj->ChainFrom<previous_type>().SetPrevious(current);
            return pObj;
        }
    };

}}   // namespace Urasandesu { namespace CppAnonym {

#endif  // #ifndef URASANDESU_CPPANONYM_SMARTPTRCHAINCONSTRUCTOR_HPP