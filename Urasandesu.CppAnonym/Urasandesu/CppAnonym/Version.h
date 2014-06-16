/* 
 * File: Version.h
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
#ifndef URASANDESU_CPPANONYM_VERSION_H
#define URASANDESU_CPPANONYM_VERSION_H

namespace Urasandesu { namespace CppAnonym {

    namespace VersionDetail {
        
        using std::wostream;
        using std::wstring;
        
        class Version : 
            boost::operators<Version>
        {
        public:
            typedef Version this_type;

            Version();
            Version(INT majorVersion, INT minorVersion, INT buildNumber, INT revisionNumber);

            bool operator ==(this_type const &other) const
            {
                return 
                    m_majorVersion == other.m_majorVersion && 
                    m_minorVersion == other.m_minorVersion && 
                    m_buildNumber == other.m_buildNumber && 
                    m_revisionNumber == other.m_revisionNumber;
            }
        
            bool operator <(this_type const &other) const
            {
                auto result = 0;
                result = m_majorVersion - other.m_majorVersion; if (result != 0) return result < 0;
                result = m_minorVersion - other.m_minorVersion; if (result != 0) return result < 0;
                result = m_buildNumber - other.m_buildNumber; if (result != 0) return result < 0;
                result = m_revisionNumber - other.m_revisionNumber; if (result != 0) return result < 0;
                return false;
            }

        private:
            friend wostream &operator <<(wostream &os, Version const &version)
            {
                auto firstPos = os.tellp();
                AppendNumberIfNecessary(firstPos, version.m_majorVersion, os);
                AppendNumberIfNecessary(firstPos, version.m_minorVersion, os);
                AppendNumberIfNecessary(firstPos, version.m_buildNumber, os);
                AppendNumberIfNecessary(firstPos, version.m_revisionNumber, os);
                return os;
            }
            
            static INT Guard(INT number, wstring const &paramName);
            static void AppendNumberIfNecessary(wostream::pos_type firstPos, INT number, wostream &os);

            INT m_majorVersion;
            INT m_minorVersion;
            INT m_buildNumber;
            INT m_revisionNumber;
        };

    }   // namespace VersionDetail {

    using VersionDetail::Version;
        
}}  // namespace Urasandesu { namespace CppAnonym {

#endif  // URASANDESU_CPPANONYM_VERSION_H
