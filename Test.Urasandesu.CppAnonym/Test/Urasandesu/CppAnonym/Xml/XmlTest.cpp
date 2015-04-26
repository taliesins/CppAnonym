/* 
 * File: XmlTest.cpp
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

#ifndef URASANDESU_CPPANONYM_XML_H
#include <Urasandesu/CppAnonym/Xml.h>
#endif

#ifndef URASANDESU_CPPANONYM_DIAGNOSTICS_PROCESS_H
#include <Urasandesu/CppAnonym/Diagnostics/Process.h>
#endif

#include <boost/serialization/vector.hpp>

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_XmlTest.*
namespace {

    namespace _64FCD0A5 {
        
        using std::vector;
        using std::wstring;

        class Arm 
        {
        public:
            Arm() { }
            explicit Arm(wstring const &name) : Name(name) { }
            wstring Name;

        private:
            friend class boost::serialization::access;
            template <class Archive>
            void serialize(Archive& archive, unsigned int version)
            {
                archive & BOOST_SERIALIZATION_NVP(Name);
            }
        };

        class Person 
        {
        public:
            int Age;
            wstring Name;
            vector<Arm> Arms;

        private:
            friend class boost::serialization::access;
            template <class Archive>
            void serialize(Archive& archive, unsigned int version)
            {
                archive & BOOST_SERIALIZATION_NVP(Age);
                archive & BOOST_SERIALIZATION_NVP(Name);
                archive & BOOST_SERIALIZATION_NVP(Arms);
            }
        };
    }   // namespace _64FCD0A5 {

    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_XmlTest, LoadingPropertyTreeApis_should_load_the_xml_which_is_made_by_dot_net_api)
    {
        using boost::filesystem::unique_path;
        using boost::lexical_cast;
        using boost::property_tree::wptree;
        using std::wstring;
        using namespace Urasandesu::CppAnonym::Diagnostics;
        using namespace Urasandesu::CppAnonym::Xml;

        // Arrange
        auto fileName = wstring(L"powershell");
        auto resultName = unique_path().native() + L".txt";
        auto arguments = wstring(L"-NoLogo -NoProfile -File ..\\..\\..\\Test\\Urasandesu\\CppAnonym\\Xml\\Export-TestXml.ps1 -PropertyTree -ResultName ") + resultName;
        ASSERT_EQ(0, Process::StartAndWaitForExit(fileName, arguments));

        
        // Act
        auto pt = wptree();
        FromUTF8(resultName) >> pt;


        // Assert
        auto str = pt.get<wstring>(L"root.str");
        ASSERT_EQ(wstring(L"PowerShell から書き換え！"), str);
        auto i = 0;
        BOOST_FOREACH (auto const& child, pt.get_child(L"root.values")) 
            ASSERT_EQ(++i, lexical_cast<int>(child.second.data()));
    }

    CPPANONYM_TEST(Urasandesu_CppAnonym_XmlTest, LoadingSerializationApis_should_load_the_xml_which_is_made_by_dot_net_api)
    {
        using boost::filesystem::unique_path;
        using boost::lexical_cast;
        using boost::property_tree::wptree;
        using boost::serialization::make_nvp;
        using std::wstring;
        using namespace _64FCD0A5;
        using namespace Urasandesu::CppAnonym::Diagnostics;
        using namespace Urasandesu::CppAnonym::Xml;

        // Arrange
        auto fileName = wstring(L"powershell");
        auto resultName = unique_path().native() + L".txt";
        auto arguments = wstring(L"-NoLogo -NoProfile -File ..\\..\\..\\Test\\Urasandesu\\CppAnonym\\Xml\\Export-TestXml.ps1 -Serialization -ResultName ") + resultName;
        ASSERT_EQ(0, Process::StartAndWaitForExit(fileName, arguments));

        
        // Act
        auto person = Person();
        FromUTF8(resultName) >> make_nvp("Person", person);


        // Assert
        ASSERT_EQ(16, person.Age);
        ASSERT_EQ(wstring(L"泉 新一"), person.Name);
        ASSERT_EQ(2, person.Arms.size());
        ASSERT_EQ(wstring(L"ミギー"), person.Arms[0].Name);
        ASSERT_EQ(wstring(L"(null)"), person.Arms[1].Name);
    }



    CPPANONYM_TEST(Urasandesu_CppAnonym_XmlTest, SavingPropertyTreeApis_should_save_the_xml_which_can_be_opened_by_dot_net_api)
    {
        using boost::filesystem::unique_path;
        using boost::lexical_cast;
        using boost::property_tree::wptree;
        using std::wstring;
        using namespace Urasandesu::CppAnonym::Diagnostics;
        using namespace Urasandesu::CppAnonym::Xml;

        // Arrange
        auto resultName = unique_path().native() + L".txt";
        auto pt = wptree();
        pt.put(L"root.str", L"C++ から書き換え！");
        pt.add(L"root.values.value", L"1");
        pt.add(L"root.values.value", L"2");
        pt.add(L"root.values.value", L"3");

        
        // Act
        ToUTF8(resultName) << pt;


        // Assert
        auto fileName = wstring(L"powershell");
        auto arguments = wstring(L"-NoLogo -NoProfile -File ..\\..\\..\\Test\\Urasandesu\\CppAnonym\\Xml\\Import-TestXml.ps1 -PropertyTree -ResultName ") + resultName;
        ASSERT_EQ(0, Process::StartAndWaitForExit(fileName, arguments));
    }

    CPPANONYM_TEST(Urasandesu_CppAnonym_XmlTest, SavingSerializationApis_should_save_the_xml_which_can_be_opened_by_dot_net_api)
    {
        using boost::filesystem::unique_path;
        using boost::lexical_cast;
        using boost::property_tree::wptree;
        using boost::serialization::make_nvp;
        using std::wstring;
        using namespace _64FCD0A5;
        using namespace Urasandesu::CppAnonym::Diagnostics;
        using namespace Urasandesu::CppAnonym::Xml;

        // Arrange
        auto resultName = unique_path().native() + L".txt";
        auto person = Person();
        person.Age = 16;
        person.Name = L"泉 新一";
        person.Arms.push_back(Arm(L"ミギー"));
        person.Arms.push_back(Arm(L"(null)"));

        
        // Act
        ToUTF8(resultName) << make_nvp("Person", person);


        // Assert
        auto fileName = wstring(L"powershell");
        auto arguments = wstring(L"-NoLogo -NoProfile -File ..\\..\\..\\Test\\Urasandesu\\CppAnonym\\Xml\\Import-TestXml.ps1 -Serialization -ResultName ") + resultName;
        ASSERT_EQ(0, Process::StartAndWaitForExit(fileName, arguments));
    }
}
