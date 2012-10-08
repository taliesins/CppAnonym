#pragma once
#ifndef URASANDESU_CPPANONYM_IDISPOSABLE_HPP
#define URASANDESU_CPPANONYM_IDISPOSABLE_HPP

#ifndef URASANDESU_CPPANONYM_IDISPOSABLEFWD_HPP
#include <Urasandesu/CppAnonym/IDisposableFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym {
    
    struct IDisposable
    {
        virtual void Dispose() = 0;
    };
    
}}  // namespace Urasandesu { namespace CppAnonym {

#endif  // URASANDESU_CPPANONYM_IDISPOSABLE_HPP