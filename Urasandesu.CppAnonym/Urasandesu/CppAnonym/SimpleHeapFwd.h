/* 
 * File: SimpleHeapFwd.h
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
#ifndef URASANDESU_CPPANONYM_SIMPLEHEAPFWD_H
#define URASANDESU_CPPANONYM_SIMPLEHEAPFWD_H

namespace Urasandesu { namespace CppAnonym {
    
    struct DefaultHeap;
    struct DefaultHeapWithoutRandomAccess;
    struct QuickHeap;
    struct QuickHeapWithoutRandomAccess;
    struct VeryQuickHeapButMustAccessThroughEachMethod; // Very quick version for small objects allocation.
                                                        // In particular, the size is less than between 32 to 40, and when they are performed a lot of allocation and free.
                                                        // Although must access through the each method if access the allocated object after a while, 
                                                        // because the allocated objects are moved when the heap is over a threshold size.
    
    namespace SimpleHeapDetail {
    
        template<class T, class Tag>
        struct SimpleHeapImpl;

    }   // namespace SimpleHeapDetail

    template<class T, class Tag = DefaultHeap>
    struct SimpleHeap;

}}  // namespace Urasandesu { namespace CppAnonym {

#endif  // URASANDESU_CPPANONYM_SIMPLEHEAPFWD_H
