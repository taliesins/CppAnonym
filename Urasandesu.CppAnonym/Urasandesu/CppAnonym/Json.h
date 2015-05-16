/* 
 * File: Json.h
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
#ifndef URASANDESU_CPPANONYM_JSON_H
#define URASANDESU_CPPANONYM_JSON_H

#ifndef URASANDESU_CPPANONYM_JSON_JSONDEPENDSON_H
#include <Urasandesu/CppAnonym/Json/JsonDependsOn.h>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMARGUMENTEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymArgumentException.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Json {

    namespace JsonDetail {

        using boost::filesystem::path;
        using boost::property_tree::wptree;
        using boost::shared_ptr;
        using std::wostream;
        using std::wistream;

        wistream &operator >>(wistream &is, wptree &pt);

        template<class T>
        wistream &operator >>(shared_ptr<wistream> const &pIs, T &v)
        {
            return *pIs.get() >> v;
        }

        wostream &operator <<(wostream &os, wptree const &pt);

        template<class T>
        wostream &operator <<(shared_ptr<wostream> const &pOs, T const &v)
        {
            return *pOs.get() << v;
        }
        
    }   // namespace JsonDetail {

    using JsonDetail::operator >>;
    using JsonDetail::operator <<;

}}}  // namespace Urasandesu { namespace CppAnonym { namespace Json {

#endif  // #ifndef URASANDESU_CPPANONYM_JSON_H
