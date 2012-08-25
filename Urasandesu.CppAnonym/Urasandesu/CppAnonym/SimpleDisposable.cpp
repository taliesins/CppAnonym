
#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_CPPANONYMOBJECTDISPOSEDEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymObjectDisposedException.h>
#endif

#ifndef URASANDESU_CPPANONYM_SIMPLEDISPOSABLE_H
#include <Urasandesu/CppAnonym/SimpleDisposable.h>
#endif

namespace Urasandesu { namespace CppAnonym {

    void SimpleDisposable::Dispose() 
    { 
        m_disposed = true; 
    }

    bool SimpleDisposable::Disposed() const 
    { 
        return m_disposed; 
    }
    
    void SimpleDisposable::CheckDisposed() const 
    {
        if (m_disposed)
            BOOST_THROW_EXCEPTION(CppAnonymObjectDisposedException());
    }

    SimpleDisposable::SimpleDisposable() : 
        m_disposed(false)
    { }

}}  // namespace Urasandesu { namespace CppAnonym {
