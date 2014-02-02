/* 
 * File: EqualTo.h
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
#ifndef URASANDESU_CPPANONYM_UTILITIES_EQUALTO_H
#define URASANDESU_CPPANONYM_UTILITIES_EQUALTO_H

#ifndef URASANDESU_CPPANONYM_TRAITS_EQUALITYCOMPARABLE_H
#include <Urasandesu/CppAnonym/Traits/EqualityComparable.h>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_EQUALTOFWD_H
#include <Urasandesu/CppAnonym/Utilities/EqualToFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Utilities {
    
    template<class T>
    struct EqualTo : 
        Traits::EqualityComparable<T>
    {
        inline result_type operator()(param_type x, param_type y) const
        {
            return x == y;
        }
    };


    
    
    
    namespace EqualToDetail {

        using boost::algorithm::iequals;
        using boost::filesystem::path;

        template<class T>
        struct EqualToImpl;

        template<>
        struct EqualToImpl<path> : 
            Traits::EqualityComparable<path>
        {
            result_type operator()(param_type x, param_type y) const
            {
                return iequals(x.native(), y.native());
            }
        };

    }   // namespace EqualToDetail {

    template<>
    struct EqualTo<boost::filesystem::path> : 
        EqualToDetail::EqualToImpl<boost::filesystem::path>
    {
    };

    
    
    
    
    template<class T>
    struct EqualTo<T const *> : 
        Traits::EqualityComparable<T const *>
    {
        inline result_type operator()(param_type x, param_type y) const
        {
            return x == y;
        }
    };

    
    
    
    
    template<class T>
    typename EqualToDecidedBy<T>::type CreateEqualTo(T const &)
    {
        return typename EqualToDecidedBy<T>::type();
    }

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_EQUALTO_H
