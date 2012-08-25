#pragma once
#ifndef URASANDESU_CPPANONYM_SMARTPTRCHAINMAPPER_HPP
#define URASANDESU_CPPANONYM_SMARTPTRCHAINMAPPER_HPP

#ifndef URASANDESU_CPPANONYM_SMARTPTRCHAINMAPPERFWD_HPP
#include <Urasandesu/CppAnonym/SmartPtrChainMapperFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym {

    struct SmartPtrChainMapper
    {
        template<
            class T,
            class Previous,
            class Current
        >
        static boost::shared_ptr<T> MapFirstAncestor(Current const &current) 
        { 
            boost::shared_ptr<Previous> pPrevious;
            pPrevious = current.ChainFrom<Previous>().GetPrevious().lock();
            return pPrevious ? pPrevious->MapFirst<T>() : boost::shared_ptr<T>();
        }

        template<
            class T,
            class Previous,
            class Current
        >
        static boost::shared_ptr<T> MapAncestor(Current const &current) 
        { 
            boost::shared_ptr<Previous> pPrevious;
            pPrevious = current.ChainFrom<Previous>().GetPrevious().lock();
            return pPrevious ? pPrevious->Map<T>() : boost::shared_ptr<T>();
        }

        template<
            class Current
        >
        static boost::shared_ptr<Current> MapFirst(Current const &current) 
        { 
            boost::shared_ptr<Current> pCurrent;
            pCurrent = current.GetCurrent().lock();
            return pCurrent;
        }

        template<
            class Current
        >
        static boost::shared_ptr<Current> Map(Current const &current) 
        { 
            boost::shared_ptr<Current> pCurrent;
            pCurrent = current.GetCurrent().lock();
            return pCurrent;
        }
    };
    
}}  // namespace Urasandesu { namespace CppAnonym {

#endif  // URASANDESU_CPPANONYM_SMARTPTRCHAINMAPPER_HPP