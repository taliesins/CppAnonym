/* 
 * File: Version.cpp
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



#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_VERSION_H
#include <Urasandesu/CppAnonym/Version.h>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMARGUMENTEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymArgumentException.h>
#endif

namespace Urasandesu { namespace CppAnonym {

    namespace VersionDetail {
        
        Version::Version() : 
            m_majorVersion(0), 
            m_minorVersion(0), 
            m_buildNumber(-1), 
            m_revisionNumber(-1)
        { }
            
        
        
        Version::Version(INT majorVersion, INT minorVersion, INT buildNumber, INT revisionNumber) : 
            m_majorVersion(Guard(majorVersion, L"majorVersion")), 
            m_minorVersion(Guard(minorVersion, L"minorVersion")), 
            m_buildNumber(Guard(buildNumber, L"buildNumber")), 
            m_revisionNumber(Guard(revisionNumber, L"revisionNumber"))
        { }
            
        
        
        INT Version::Guard(INT number, wstring const &paramName)
        {
            using Urasandesu::CppAnonym::CppAnonymArgumentException;

            if (0 <= number)
                return number;
                
            BOOST_THROW_EXCEPTION(CppAnonymArgumentException(L"Version's parameters must be greater than or equal to zero.", paramName));
        }
            
        
        
        void Version::AppendNumberIfNecessary(wostream::pos_type firstPos, INT number, wostream &os)
        {
            if (number < 0)
                return;
                
            if (firstPos != os.tellp())
                os << L".";
                
            os << number;
        }

    }   // namespace VersionDetail {
        
}}  // namespace Urasandesu { namespace CppAnonym {
