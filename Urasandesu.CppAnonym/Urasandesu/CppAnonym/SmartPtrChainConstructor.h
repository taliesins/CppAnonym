#pragma once
#ifndef URASANDESU_CPPANONYM_SMARTPTRCHAINCONSTRUCTOR_H
#define URASANDESU_CPPANONYM_SMARTPTRCHAINCONSTRUCTOR_H

#ifndef URASANDESU_CPPANONYM_UTILITIES_TEMPPTR_HPP
#include <Urasandesu/CppAnonym/Utilities/TempPtr.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_SMARTPTRCHAINCONSTRUCTORFWD_H
#include <Urasandesu/CppAnonym/SmartPtrChainConstructorFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym {

    struct SmartPtrChainConstructor
    {
        template<
            class T,
            class PersistableHeapProvider
        >
        static Utilities::TempPtr<T> NewRootObject(PersistableHeapProvider &provider)
        {
            return provider.NewObject();
        }

        template<
            class T,
            class Current,
            class PersistableHeapProvider
        >
        static Utilities::TempPtr<T> NewObject(Current &current, PersistableHeapProvider &provider)
        {
            typedef typename Current::current_type previous_type;
            Utilities::TempPtr<T> pObj(provider.NewObject());
            pObj->ChainFrom<previous_type>().SetPrevious(current);
            return pObj;
        }
    };

}}   // namespace Urasandesu { namespace CppAnonym {

#endif  // #ifndef URASANDESU_CPPANONYM_SMARTPTRCHAINCONSTRUCTOR_H