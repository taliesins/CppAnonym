#pragma once
#ifndef URASANDESU_CPPANONYM_SIMPLEBLOB_H
#define URASANDESU_CPPANONYM_SIMPLEBLOB_H

#ifndef URASANDESU_CPPANONYM_COLLECTIONS_RAPIDVECTOR_H
#include <Urasandesu/CppAnonym/Collections/RapidVector.h>
#endif

#ifndef URASANDESU_CPPANONYM_SIMPLEBLOBFWD_H
#include <Urasandesu/CppAnonym/SimpleBlobFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym {
    
    class SimpleBlob
    {
    public:
        SimpleBlob()
        { }

        template<class T>
        HRESULT Put(typename boost::call_traits<T>::param_type val)
        {
            namespace mpl = boost::mpl;
            using mpl::or_;
            using namespace boost;            
            
            BOOST_MPL_ASSERT((or_<is_arithmetic<T>, is_pod<T>>));

            return Put(&val, sizeof(T));
        }
        
        HRESULT Put(void const *p, SIZE_T size)
        {
            _ASSERT(0 <= size);
            size_t lastSize = m_buffer.size();
            m_buffer.resize(lastSize + size);
            ::memcpy_s(&m_buffer[0] + lastSize, size, p, size);
            return S_OK;
        }
        
        BYTE *Ptr()
        {
            return &m_buffer[0];
        }
        
        BYTE const *Ptr() const
        {
            return &m_buffer[0];
        }
        
        SIZE_T Size() const
        {
            return m_buffer.size();
        }
        
        SIZE_T Capacity() const
        {
            return m_buffer.capacity();
        }
        
        BYTE& operator[] (SIZE_T ix)
        {
            return m_buffer[ix];
        }
        
        BYTE const& operator[] (SIZE_T ix) const
        {
            return m_buffer[ix];
        }
        
    private:
        typedef Collections::RapidVector<BYTE> ByteVector;        
        ByteVector m_buffer;
    };
    
}}  // namespace Urasandesu { namespace CppAnonym {

#endif  // URASANDESU_CPPANONYM_SIMPLEBLOB_H