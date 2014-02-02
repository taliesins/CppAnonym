/* 
 * File: StackAllocator.h
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
#ifndef URASANDESU_CPPANONYM_UTILITIES_STACKALLOCATOR_H
#define URASANDESU_CPPANONYM_UTILITIES_STACKALLOCATOR_H

#ifndef URASANDESU_CPPANONYM_UTILITIES_STACKALLOCATORFWD_H
#include <Urasandesu/CppAnonym/Utilities/StackAllocatorFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    template<class T>
    class StackAllocator
    {
    public:
        typedef size_t size_type;
        typedef ptrdiff_t difference_type;
        typedef T *pointer;
        typedef T const *const_pointer;
        typedef T &reference;
        typedef T const &const_reference;
        typedef T value_type;

        template<class U>
        struct rebind
        {
	        typedef StackAllocator<U> other;
        };

        StackAllocator() throw() { }
        template<class U> StackAllocator(StackAllocator<U> const &) throw() { }
        ~StackAllocator() throw() { }

        pointer allocate(size_type num, void const *hint = NULL)
        {
            return reinterpret_cast<pointer>(_malloca(num * sizeof(T)));
        }

        void construct(pointer p, T const &value)
        {
	        new(p)T(value);
        }

        void deallocate(pointer p, size_type num)
        {
            _freea(p);
        }

        void destroy(pointer p)
        {
	        p->~T();
        }

        pointer address(reference value) const { return &value; }
        const_pointer address(const_reference value) const { return &value; }

        size_type max_size() const throw()
        {
	        return std::numeric_limits<size_t>::max() / sizeof(T);
        }
    };

    template<class T1, class T2>
    bool operator ==(StackAllocator<T1> const &, StackAllocator<T2> const &) throw() { return true; }

    template<class T1, class T2>
    bool operator !=(StackAllocator<T1> const &, StackAllocator<T2> const &) throw() { return false; }

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_STACKALLOCATOR_H
