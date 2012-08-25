#pragma once
#ifndef URASANDESU_CPPANONYM_SIMPLEDISPOSABLE_H
#define URASANDESU_CPPANONYM_SIMPLEDISPOSABLE_H

namespace Urasandesu { namespace CppAnonym {

    class ATL_NO_VTABLE SimpleDisposable
    {
    public:
        void Dispose();
        bool Disposed() const;
        void CheckDisposed() const;
    
    protected:
        SimpleDisposable();
    
    private:
        bool m_disposed;
    };
        
}}  // namespace Urasandesu { namespace CppAnonym {

#endif  // URASANDESU_CPPANONYM_SIMPLEDISPOSABLE_H