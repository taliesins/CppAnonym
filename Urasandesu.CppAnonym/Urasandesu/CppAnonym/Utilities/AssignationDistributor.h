/* 
 * File: AssignationDistributor.h
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
#ifndef URASANDESU_CPPANONYM_UTILITIES_ASSIGNATIONDISTRIBUTOR_H
#define URASANDESU_CPPANONYM_UTILITIES_ASSIGNATIONDISTRIBUTOR_H

#ifndef URASANDESU_CPPANONYM_UTILITIES_ASSIGNATIONDISTRIBUTORFWD_H
#include <Urasandesu/CppAnonym/Utilities/AssignationDistributorFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    namespace AssignationDistributorDetail {

        using boost::has_trivial_assign;
        using boost::integral_constant;
        using boost::is_pointer;

        typedef integral_constant<bool, false> False;

        template<class T, class IsPointer, class HasTrivialAssign>
        struct AssignImpl
        {
            static void Assign(void *pDst, void *pSrc)
            {
                if (pDst != pSrc)
                    ::memcpy_s(pDst, sizeof(T), pSrc, sizeof(T));
            }
        };

        template<class T>
        struct AssignImpl<T, False, False>
        {
            static void Assign(void *pDst, void *pSrc)
            {
                if (pDst != pSrc)
                    *reinterpret_cast<T *>(pDst) = *reinterpret_cast<T *>(pSrc);
            }
        };

        template<class T>
        struct AssignationDistributorImpl
        {
            typedef typename is_pointer<T>::type is_pointer_type;
            typedef typename has_trivial_assign<T>::type has_trivial_assign_type;
            typedef AssignImpl<T, is_pointer_type, has_trivial_assign_type> impl_type;
            
            static void Assign(void *pDst, void *pSrc)
            {
                impl_type::Assign(pDst, pSrc);
            }
        };

    }   // namespace AssignationDistributorDetail {

    template<class T>
    struct AssignationDistributor : 
        AssignationDistributorDetail::AssignationDistributorImpl<T>
    {
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_ASSIGNATIONDISTRIBUTOR_H
