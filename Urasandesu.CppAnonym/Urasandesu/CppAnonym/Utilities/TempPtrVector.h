/* 
 * File: TempPtrVector.h
 * 
 * Author: Akira Sugiura (urasandesu@gmail.com)
 * 
 * 
 * Copyright (c) 2014 Akira Sugiura
 *  
 *  This software is MIT License.
 *  
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *  
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 *  
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 *  THE SOFTWARE.
 */


#pragma once
#ifndef URASANDESU_CPPANONYM_UTILITIES_TEMPPTRVECTOR_H
#define URASANDESU_CPPANONYM_UTILITIES_TEMPPTRVECTOR_H

#ifndef URASANDESU_CPPANONYM_UTILITIES_TEMPPTR_H
#include <Urasandesu/CppAnonym/Utilities/TempPtr.h>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_TEMPPTRVECTORFWD_H
#include <Urasandesu/CppAnonym/Utilities/TempPtrVectorFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    template<class T>
    class TempPtrVector
    {
    public:
        typedef TempPtrVector<T> this_type;

        typedef std::vector<TempPtr<T> > temp_ptr_vector_type;
        typedef typename temp_ptr_vector_type::size_type size_type;
        typedef T *pointer;
        typedef T const *const_pointer;
        typedef T const *&const_reference;
        typedef T *&reference;
        typedef typename temp_ptr_vector_type::value_type value_type;

	    void reserve(size_type size)
        {
            m_vec.reserve(size);
        }

        void push_back(typename boost::call_traits<value_type>::param_type val)
        {
            m_vec.push_back(val);
        };

        const_pointer operator [](size_type pos) const
        {
            TempPtr<T> &p = const_cast<TempPtr<T> &>(m_vec[pos]);
            if (!p.IsPersisted())
                p.Persist();
            return p.Get();
        }

        pointer operator [](size_type pos)
        {
            BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
        }

        size_type size() const
        {
            return m_vec.size();
        }

	    bool empty() const
        {
            return m_vec.empty();
        }

    private:
        temp_ptr_vector_type m_vec;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_TEMPPTRVECTOR_H
