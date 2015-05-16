/* 
 * File: IO.cpp
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

#ifndef URASANDESU_CPPANONYM_IO_H
#include <Urasandesu/CppAnonym/IO.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace IO {

    namespace IODetail {
        
        shared_ptr<wistream> FromUTF8(path const &p, bool encoderShouldEmitUTF8Identifier)
        {
            using boost::make_shared;
            using std::wifstream;
            using std::codecvt_utf8_utf16;
            using std::locale;

            auto pIfs = make_shared<wifstream>(p.native());
            if (pIfs->bad())
            {
                auto oss = std::wostringstream();
                oss << L"The designated file can't open: " << p.native();
                BOOST_THROW_EXCEPTION(CppAnonymArgumentException(oss.str(), L"p"));
            }
            
            if (encoderShouldEmitUTF8Identifier)
                pIfs->seekg(3);

            pIfs->imbue(locale(locale(), new codecvt_utf8_utf16<WCHAR>()));
            return pIfs;
        }

        shared_ptr<wostream> ToUTF8(path const &p, bool encoderShouldEmitUTF8Identifier)
        {
            using boost::make_shared;
            using std::codecvt_utf8_utf16;
            using std::locale;
            using std::ios;
            using std::ofstream;
            using std::wofstream;

            if (encoderShouldEmitUTF8Identifier)
            {
                auto ofs = ofstream(p.native(), ios::out | ios::binary | ios::trunc);
                if (ofs.bad())
                {
                    auto oss = std::wostringstream();
                    oss << L"The designated file can't open: " << p.native();
                    BOOST_THROW_EXCEPTION(CppAnonymArgumentException(oss.str(), L"p"));
                }
            
                BYTE bom[3];
                bom[0] = 0xEF;
                bom[1] = 0xBB;
                bom[2] = 0xBF;

                ofs.write(reinterpret_cast<CHAR const *>(bom), 3);
            }

            auto pOfs = make_shared<wofstream>(p.native(), ios::out | (encoderShouldEmitUTF8Identifier ? ios::app : 0));
            if (pOfs->bad())
            {
                auto oss = std::wostringstream();
                oss << L"The designated file can't open: " << p.native();
                BOOST_THROW_EXCEPTION(CppAnonymArgumentException(oss.str(), L"p"));
            }
            
            pOfs->imbue(locale(locale(), new codecvt_utf8_utf16<WCHAR>()));
            return pOfs;
        }
        
    }   // namespace IODetail {

}}}  // namespace Urasandesu { namespace CppAnonym { namespace IO {
