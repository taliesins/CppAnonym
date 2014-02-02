/* 
 * File: Hash.h
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
#ifndef URASANDESU_CPPANONYM_UTILITIES_HASH_H
#define URASANDESU_CPPANONYM_UTILITIES_HASH_H

#ifndef URASANDESU_CPPANONYM_TRAITS_HASHCOMPUTABLE_H
#include <Urasandesu/CppAnonym/Traits/HashComputable.h>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_HASHFWD_H
#include <Urasandesu/CppAnonym/Utilities/HashFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    namespace HashDetail {

        using boost::filesystem::path;

        template<>
        struct HashImpl<path> : 
            Traits::HashComputable<path>
        {
            result_type operator()(param_type v) const
            {
                using boost::hash_combine;
                using std::locale;
                using std::toupper;
                
                typedef path::string_type String;
                
                std::size_t seed = 0;

                String const &native = v.native();
                typedef String::const_iterator ConstIterator;
                for (ConstIterator ci = native.cbegin(), ci_end = native.cend(); ci != ci_end; ++ci)
                {
                    hash_combine(seed, toupper(*ci, locale()));
                }

                return seed;
            }
        };

    }   // namespace HashDetail {

    template<>
    struct Hash<boost::filesystem::path> : 
        HashDetail::HashImpl<boost::filesystem::path>
    {
    };
    
    
    
    template<class T>
    struct Hash<T const *> : 
        Traits::HashComputable<T const *>
    {
        result_type operator()(param_type v) const
        {
            return reinterpret_cast<std::size_t>(v);
        }
    };
    
    
    
    template<class T>
    std::size_t HashValue(T v)
    {
        return Hash<T>()(v);
    }
    
    
    
    template<class T>
    typename HashDecidedBy<T>::type CreateHash(T const &)
    {
        return typename HashDecidedBy<T>::type();
    }

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_HASH_H
