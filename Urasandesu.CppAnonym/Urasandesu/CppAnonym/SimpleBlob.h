#pragma once
#ifndef URASANDESU_CPPANONYM_SIMPLEBLOB_H
#define URASANDESU_CPPANONYM_SIMPLEBLOB_H

#ifndef URASANDESU_CPPANONYM_COLLECTIONS_RAPIDVECTOR_HPP
#include <Urasandesu/CppAnonym/Collections/RapidVector.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_SIMPLEBLOBFWD_H
#include <Urasandesu/CppAnonym/SimpleBlobFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym {
    
    class SimpleBlob
    {
    public:
        SimpleBlob();

        template<class T>
        HRESULT Put(typename boost::call_traits<T>::param_type val);
        
        HRESULT Put(void const *p, SIZE_T size);
        BYTE *Ptr();
        BYTE const *Ptr() const;
        SIZE_T Size() const;
        SIZE_T Capacity() const;
        BYTE& operator[] (SIZE_T ix);
        BYTE const& operator[] (SIZE_T ix) const;
        
    private:
        typedef Collections::RapidVector<BYTE> ByteVector;        
        ByteVector m_buffer;
    };
    
}}  // namespace Urasandesu { namespace CppAnonym {

#endif  // URASANDESU_CPPANONYM_SIMPLEBLOB_H