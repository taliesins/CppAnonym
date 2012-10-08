#pragma once
#ifndef URASANDESU_CPPANONYM_SIMPLEBLOB_HPP
#define URASANDESU_CPPANONYM_SIMPLEBLOB_HPP

#ifndef URASANDESU_CPPANONYM_COLLECTIONS_RAPIDVECTOR_HPP
#include <Urasandesu/CppAnonym/Collections/RapidVector.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_SIMPLEBLOBFWD_HPP
#include <Urasandesu/CppAnonym/SimpleBlobFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym {
    
    class SimpleBlob
    {
        typedef Collections::RapidVector<BYTE> ByteVector;        
        ByteVector m_buffer;

    public:
        inline SimpleBlob() { }

        template<class T>
        inline HRESULT Put(typename boost::call_traits<T>::param_type val)
        {
            using namespace boost;            
            using namespace boost::mpl;
            
            BOOST_MPL_ASSERT((or_<is_arithmetic<T>, is_pod<T>>));

            return Put(&val, sizeof(T));
        }
        
        inline HRESULT Put(void const *p, SIZE_T size)
        {
            _ASSERT(0 <= size);
            size_t lastSize = m_buffer.size();
            m_buffer.resize(lastSize + size);
            ::memcpy_s(&m_buffer[0] + lastSize, size, p, size);
            return S_OK;
        }
        
        inline BYTE *Ptr()
        {
            return &m_buffer[0];
        }
        
        inline BYTE const *Ptr() const
        {
            return &m_buffer[0];
        }
        
        inline SIZE_T Size() const
        { 
            return m_buffer.size();
        }

        inline SIZE_T Capacity() const
        { 
            return m_buffer.capacity();
        }

        inline BYTE& operator[] (SIZE_T ix)
        { 
            return m_buffer[ix];
        }

        inline BYTE const& operator[] (SIZE_T ix) const
        { 
            return m_buffer[ix];
        }
    };
    
}}  // namespace Urasandesu { namespace CppAnonym {

#endif  // URASANDESU_CPPANONYM_SIMPLEBLOB_HPP