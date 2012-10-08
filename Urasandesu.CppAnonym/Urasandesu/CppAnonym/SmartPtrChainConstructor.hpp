﻿#pragma once
#ifndef URASANDESU_CPPANONYM_SMARTPTRCHAINCONSTRUCTOR_HPP
#define URASANDESU_CPPANONYM_SMARTPTRCHAINCONSTRUCTOR_HPP

#ifndef URASANDESU_CPPANONYM_UTILITIES_AUTO_PTR_HPP
#include <Urasandesu/CppAnonym/Utilities/AutoPtr.hpp>
#endif

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
        static Utilities::TempPtr<T> NewRootObject()
        {
            return PersistableHeapProvider::NewStaticObject();
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

#endif  // #ifndef URASANDESU_CPPANONYM_SMARTPTRCHAINCONSTRUCTOR_HPP