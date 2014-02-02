/* 
 * File: DestructionDistributor.h
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
#ifndef URASANDESU_CPPANONYM_UTILITIES_DESTRUCTIONDISTRIBUTOR_H
#define URASANDESU_CPPANONYM_UTILITIES_DESTRUCTIONDISTRIBUTOR_H

#ifndef URASANDESU_CPPANONYM_UTILITIES_DESTRUCTIONDISTRIBUTORFWD_H
#include <Urasandesu/CppAnonym/Utilities/DestructionDistributorFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    namespace DestructionDistributorDetail {

        using boost::has_trivial_destructor;
        using boost::integral_constant;
        using boost::is_pointer;

        typedef integral_constant<bool, false> False;

        template<class T, class IsPointer, class HasTrivialDestructor>
        struct DestructImpl
        {
            static void Destruct(void *p)
            {
                // nop
            }
        };

        template<class T>
        struct DestructImpl<T, False, False>
        {
            static void Destruct(void *p)
            {
                T *temp = reinterpret_cast<T *>(p);
                temp->~T();
            }
        };

        template<class T>
        struct DestructionDistributorImpl
        {
            typedef typename is_pointer<T>::type is_pointer_type;
            typedef typename has_trivial_destructor<T>::type has_trivial_destructor_type;
            typedef DestructImpl<T, is_pointer_type, has_trivial_destructor_type> impl_type;
            
            static void Destruct(void *p)
            {
                impl_type::Destruct(p);
            }
        };

    }   // namespace DestructionDistributorDetail {

    template<class T>
    struct DestructionDistributor : 
        DestructionDistributorDetail::DestructionDistributorImpl<T>
    {
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_DESTRUCTIONDISTRIBUTOR_H
