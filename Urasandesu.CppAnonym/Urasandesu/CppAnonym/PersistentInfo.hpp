#pragma once
#ifndef URASANDESU_CPPANONYM_PERSISTENTINFO_HPP
#define URASANDESU_CPPANONYM_PERSISTENTINFO_HPP

#ifndef URASANDESU_CPPANONYM_PERSISTENTINFOFWD_HPP
#include <Urasandesu/CppAnonym/PersistentInfoFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym {
    
    template<
        class T,
        class PersistedHandler
    >
    struct PersistentInfo
    {
        typedef T object_type;
        typedef PersistedHandler persisted_handler_type;
    };

}}   // namespace Urasandesu { namespace CppAnonym {

#endif  // #ifndef URASANDESU_CPPANONYM_PERSISTENTINFO_HPP