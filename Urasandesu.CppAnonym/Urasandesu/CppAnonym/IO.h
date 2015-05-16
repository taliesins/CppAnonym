/* 
 * File: IO.h
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
#ifndef URASANDESU_CPPANONYM_IO_H
#define URASANDESU_CPPANONYM_IO_H

#ifndef URASANDESU_CPPANONYM_IO_IODEPENDSON_H
#include <Urasandesu/CppAnonym/IO/IODependsOn.h>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMARGUMENTEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymArgumentException.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace IO {

    namespace IODetail {

        using boost::filesystem::path;
        using boost::shared_ptr;
        using std::wostream;
        using std::wistream;
        
        shared_ptr<wistream> FromUTF8(path const &p, bool encoderShouldEmitUTF8Identifier = true);
        shared_ptr<wostream> ToUTF8(path const &p, bool encoderShouldEmitUTF8Identifier = true);
        
    }   // namespace IODetail {

    using IODetail::FromUTF8;
    using IODetail::ToUTF8;

}}}  // namespace Urasandesu { namespace CppAnonym { namespace IO {

#endif  // #ifndef URASANDESU_CPPANONYM_IO_H
