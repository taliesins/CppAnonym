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
        static typename PersistableHeapProvider::static_object_temp_ptr_type NewRootObject()
        {
            return PersistableHeapProvider::NewStaticObject();
        }

        template<
            class T,
            class Current,
            class PersistableHeapProvider
        >
        static typename PersistableHeapProvider::object_temp_ptr_type NewObject(Current &current, PersistableHeapProvider &provider)
        {
            typedef typename Current::current_type previous_type;
            typename PersistableHeapProvider::object_temp_ptr_type pObj(provider.NewObject());
            pObj->ChainFrom<previous_type>().SetPrevious(current);
            return pObj;
        }
    };

}}   // namespace Urasandesu { namespace CppAnonym {

#endif  // #ifndef URASANDESU_CPPANONYM_SMARTPTRCHAINCONSTRUCTOR_HPP