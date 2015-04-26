/* 
 * File: Xml.h
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
#ifndef URASANDESU_CPPANONYM_XML_H
#define URASANDESU_CPPANONYM_XML_H

#ifndef URASANDESU_CPPANONYM_XML_XMLDEPENDSON_H
#include <Urasandesu/CppAnonym/Xml/XmlDependsOn.h>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMARGUMENTEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymArgumentException.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Xml {

    namespace XmlDetail {

        using boost::filesystem::path;
        using boost::property_tree::wptree;
        using boost::serialization::nvp;
        using boost::shared_ptr;
        using std::wostream;
        using std::wistream;

        wistream &operator >>(wistream &is, wptree &pt);

        template<class T>
        wistream &operator >>(wistream &is, nvp<T> const &p)
        {
            using boost::archive::no_header;
            using boost::archive::xml_wiarchive;
            using std::wstring;

            auto header = wstring();
            getline(is, header);

            auto iarchive = xml_wiarchive(is, no_header);
            iarchive >> p;
            return is;
        }

        template<class T>
        wistream &operator >>(shared_ptr<wistream> const &pIs, T &v)
        {
            return *pIs.get() >> v;
        }
        
        shared_ptr<wistream> FromUTF8(path const &p, bool encoderShouldEmitUTF8Identifier = true);

        wostream &operator <<(wostream &os, wptree const &pt);

        template<class T>
        wostream &operator <<(wostream &os, nvp<T> const &p)
        {
            using boost::archive::no_header;
            using boost::archive::xml_woarchive;
            using std::endl;

            os << L"<?xml version=\"1.0\" encoding=\"utf-8\"?>" << endl;

            auto oarchive = xml_woarchive(os, no_header);
            oarchive << p;
            return os;
        }

        template<class T>
        wostream &operator <<(shared_ptr<wostream> const &pOs, T const &v)
        {
            return *pOs.get() << v;
        }

        shared_ptr<wostream> ToUTF8(path const &p, bool encoderShouldEmitUTF8Identifier = true);
        
    }   // namespace XmlDetail {

    using XmlDetail::operator >>;
    using XmlDetail::FromUTF8;
    using XmlDetail::operator <<;
    using XmlDetail::ToUTF8;

}}}  // namespace Urasandesu { namespace CppAnonym { namespace Xml {

#endif  // #ifndef URASANDESU_CPPANONYM_XML_H
