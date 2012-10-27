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
        static T *MapFirstAncestor(Current &current)
        { 
            Previous *pPrevious = NULL;
            pPrevious = current.ChainFrom<Previous>().GetPrevious();
            return pPrevious == NULL ? NULL : pPrevious->MapFirst<T>();
        }

        template<
            class T,
            class Previous,
            class Current
        >
        static T *MapAncestor(Current &current)
        { 
            Previous *pPrevious = NULL;
            pPrevious = current.ChainFrom<Previous>().GetPrevious();
            return pPrevious == NULL ? NULL : pPrevious->Map<T>();
        }

        template<
            class Current
        >
        static Current *MapFirst(Current &current)
        {
            return &current; 
        }

        template<
            class Current
        >
        static Current *Map(Current &current)
        { 
            return &current;
        }
    };
    
}}  // namespace Urasandesu { namespace CppAnonym {

#endif  // URASANDESU_CPPANONYM_SMARTPTRCHAINMAPPER_H