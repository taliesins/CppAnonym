#pragma once
#ifndef URASANDESU_CPPANONYM_SMARTPTRCHAINMAPPER_H
#define URASANDESU_CPPANONYM_SMARTPTRCHAINMAPPER_H

#ifndef URASANDESU_CPPANONYM_SMARTPTRCHAINMAPPERFWD_H
#include <Urasandesu/CppAnonym/SmartPtrChainMapperFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym {

    struct SmartPtrChainMapper
    {
        template<
            class T,
            class Previous,
            class Current
        >
        static T *MapFirstAncestor(Current &current);

        template<
            class T,
            class Previous,
            class Current
        >
        static T *MapAncestor(Current &current);

        template<
            class Current
        >
        static Current *MapFirst(Current &current);

        template<
            class Current
        >
        static Current *Map(Current &current);
    };
    
}}  // namespace Urasandesu { namespace CppAnonym {

#endif  // URASANDESU_CPPANONYM_SMARTPTRCHAINMAPPER_H