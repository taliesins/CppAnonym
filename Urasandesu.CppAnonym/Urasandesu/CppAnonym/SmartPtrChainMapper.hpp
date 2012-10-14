#pragma once
#ifndef URASANDESU_CPPANONYM_SMARTPTRCHAINMAPPER_HPP
#define URASANDESU_CPPANONYM_SMARTPTRCHAINMAPPER_HPP

#ifndef URASANDESU_CPPANONYM_SMARTPTRCHAINMAPPER_H
#include <Urasandesu/CppAnonym/SmartPtrChainMapper.h>
#endif

namespace Urasandesu { namespace CppAnonym {

    template<
        class T,
        class Previous,
        class Current
    >
    static T *SmartPtrChainMapper::MapFirstAncestor(Current &current) 
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
    static T *SmartPtrChainMapper::MapAncestor(Current &current) 
    { 
        Previous *pPrevious = NULL;
        pPrevious = current.ChainFrom<Previous>().GetPrevious();
        return pPrevious == NULL ? NULL : pPrevious->Map<T>();
    }

    template<
        class Current
    >
    static Current *SmartPtrChainMapper::MapFirst(Current &current) 
    {
        return &current; 
    }

    template<
        class Current
    >
    static Current *SmartPtrChainMapper::Map(Current &current) 
    { 
        return &current;
    }
    
}}  // namespace Urasandesu { namespace CppAnonym {

#endif  // URASANDESU_CPPANONYM_SMARTPTRCHAINMAPPER_HPP