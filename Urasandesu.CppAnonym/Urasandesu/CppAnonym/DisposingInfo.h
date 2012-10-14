#pragma once
#ifndef URASANDESU_CPPANONYM_DISPOSINGINFO_H
#define URASANDESU_CPPANONYM_DISPOSINGINFO_H

#ifndef URASANDESU_CPPANONYM_PERSISTENTINFO_HPP
#include <Urasandesu/CppAnonym/PersistentInfo.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_DISPOSINGINFOFWD_H
#include <Urasandesu/CppAnonym/DisposingInfoFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym {
    
    template<
        class T,
        class Handler
    >
    struct DisposingInfo : 
        PersistentInfo<T, Handler>
    {
    };

}}   // namespace Urasandesu { namespace CppAnonym {

#endif  // #ifndef URASANDESU_CPPANONYM_DISPOSINGINFO_H