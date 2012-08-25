#pragma once
#ifndef URASANDESU_CPPANONYM_SMARTPTRCHAININFO_HPP
#define URASANDESU_CPPANONYM_SMARTPTRCHAININFO_HPP

#ifndef URASANDESU_CPPANONYM_SMARTPTRCHAININFOFWD_HPP
#include <Urasandesu/CppAnonym/SmartPtrChainInfoFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym {

    template<
        class Previous, 
        class Mapper,
        class Constructor
    >
    struct SmartPtrChainInfo
    {
        typedef Previous previous_type;
        typedef Mapper mapper_type;
        typedef Constructor constructor_type;
    };

}}   // namespace Urasandesu { namespace CppAnonym {

#endif  // #ifndef URASANDESU_CPPANONYM_SMARTPTRCHAININFO_HPP