/* 
 * File: RapidVectorFwd.h
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
#ifndef URASANDESU_CPPANONYM_COLLECTIONS_RAPIDVECTORFWD_H
#define URASANDESU_CPPANONYM_COLLECTIONS_RAPIDVECTORFWD_H

namespace Urasandesu { namespace CppAnonym { namespace Collections {

    namespace RapidVectorDetail {

        template<
            class Value, 
            class T, 
#ifdef _M_IX86
            DWORD RAPID_SIZE = 512,
#else
            DWORD RAPID_SIZE = 1024,
#endif
            class Alloc = std::allocator<T>
        >
        class RapidVectorIterator;

        template<class T, DWORD RAPID_SIZE, class Alloc>
        class RapidVectorImpl;

    }   // namespace RapidVectorDetail

    template<
        class T, 
#ifdef _M_IX86
        DWORD RAPID_SIZE = 512, 
#else
        DWORD RAPID_SIZE = 1024, 
#endif
        class Alloc = std::allocator<T>
    >
    struct RapidVector;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Collections {

#endif  // URASANDESU_CPPANONYM_COLLECTIONS_RAPIDVECTORFWD_H
