#pragma once
#ifndef URASANDESU_CPPANONYM_SMARTPTRCHAININFOFWD_HPP
#define URASANDESU_CPPANONYM_SMARTPTRCHAININFOFWD_HPP

#ifndef URASANDESU_CPPANONYM_SMARTPTRCHAINMAPPERFWD_HPP
#include <Urasandesu/CppAnonym/SmartPtrChainMapperFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_SMARTPTRCHAINCONSTRUCTORFWD_H
#include <Urasandesu/CppAnonym/SmartPtrChainConstructorFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym {

    template<
        class Previous, 
        class Mapper = SmartPtrChainMapper,
        class Constructor = SmartPtrChainConstructor
    >
    struct SmartPtrChainInfo;

}}   // namespace Urasandesu { namespace CppAnonym {

#endif  // #ifndef URASANDESU_CPPANONYM_SMARTPTRCHAININFOFWD_HPP