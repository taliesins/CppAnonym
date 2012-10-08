#pragma once
#ifndef URASANDESU_CPPANONYM_SIMPLEDISPOSABLE_H
#define URASANDESU_CPPANONYM_SIMPLEDISPOSABLE_H

#ifndef URASANDESU_CPPANONYM_IDISPOSABLE_HPP
#include <Urasandesu/CppAnonym/IDisposable.hpp>
#endif

namespace Urasandesu { namespace CppAnonym {

    class ATL_NO_VTABLE SimpleDisposable : 
        IDisposable
    {
    public:
        virtual void Dispose();
        bool Disposed() const;
        void CheckDisposed() const;
    
    protected:
        SimpleDisposable();
    
    private:
        bool m_disposed;
    };
        
}}  // namespace Urasandesu { namespace CppAnonym {

#endif  // URASANDESU_CPPANONYM_SIMPLEDISPOSABLE_H