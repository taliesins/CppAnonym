/* 
 * File: ConstructionDistributor.h
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
#ifndef URASANDESU_CPPANONYM_UTILITIES_CONSTRUCTIONDISTRIBUTOR_H
#define URASANDESU_CPPANONYM_UTILITIES_CONSTRUCTIONDISTRIBUTOR_H

#ifndef URASANDESU_CPPANONYM_TRAITS_REMOVECONST_H
#include <Urasandesu/CppAnonym/Traits/RemoveConst.h>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_CONSTRUCTIONDISTRIBUTORFWD_H
#include <Urasandesu/CppAnonym/Utilities/ConstructionDistributorFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    namespace ConstructionDistributorDetail {

        using namespace Urasandesu::CppAnonym::Traits;
        using boost::has_trivial_constructor;
        using boost::integral_constant;
        using boost::is_pointer;
        using boost::is_same;
        using boost::remove_reference;

        typedef integral_constant<bool, false> False;

        template<class T, class IsPointer, class HasTrivialConstructor>
        struct ConstructImpl
        {
            static void Construct(void *p)
            {
                ::ZeroMemory(p, sizeof(T));
            }
            
            template<class A1>
            static void Construct(void *p, A1 arg1)
            {
                BOOST_MPL_ASSERT((is_same<T, typename RemoveConst<typename remove_reference<A1>::type>::type>));
                ::memcpy_s(p, sizeof(T), &arg1, sizeof(T));
            }
        };

        template<class T>
        struct ConstructImpl<T, False, False>
        {
            static void Construct(void *p)
            {
                new(p)T();
            }

            template<class A1>
            static void Construct(void *p, A1 arg1)
            {
                new(p)T(arg1);
            }
        };

        template<class T>
        struct ConstructionDistributorImpl
        {
            typedef typename is_pointer<T>::type is_pointer_type;
            typedef typename has_trivial_constructor<T>::type has_trivial_constructor_type;
            typedef ConstructImpl<T, is_pointer_type, has_trivial_constructor_type> impl_type;
            
            static void Construct(void *p)
            {
                impl_type::Construct(p);
            }
            
            template<class A1>
            static void Construct(void *p, A1 arg1)
            {
                impl_type::Construct<A1>(p, arg1);
            }
        };

    }   // namespace ConstructionDistributorDetail {

    template<class T>
    struct ConstructionDistributor : 
        ConstructionDistributorDetail::ConstructionDistributorImpl<T>
    {
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_CONSTRUCTIONDISTRIBUTOR_H
