/* 
 * File: EmptinessVisitor.h
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
#ifndef URASANDESU_CPPANONYM_UTILITIES_EMPTINESSVISITOR_H
#define URASANDESU_CPPANONYM_UTILITIES_EMPTINESSVISITOR_H

#ifndef URASANDESU_CPPANONYM_UTILITIES_EMPTINESSVISITORFWD_H
#include <Urasandesu/CppAnonym/Utilities/EmptinessVisitorFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    struct EmptinessVisitor : 
        boost::static_visitor<bool>
    {
        template<class T>
        bool operator ()(T const &) const
        {
            return false;
        }

        template<>
        bool operator ()<boost::blank>(boost::blank const &) const
        {
            return true;
        }
    };

    template<class Visitable>
    bool Empty(Visitable &visitable)
    {
        return boost::apply_visitor(EmptinessVisitor(), visitable);
    }

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_EMPTINESSVISITOR_H
