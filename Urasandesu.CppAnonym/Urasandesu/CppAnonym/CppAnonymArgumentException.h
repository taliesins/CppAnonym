#pragma once
#ifndef URASANDESU_CPPANONYM_CPPANONYMARGUMENTEXCEPTION_H
#define URASANDESU_CPPANONYM_CPPANONYMARGUMENTEXCEPTION_H

#ifndef URASANDESU_CPPANONYM_CPPANONYMEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymException.h>
#endif

namespace Urasandesu { namespace CppAnonym {

    class CppAnonymArgumentException : 
        public CppAnonymException
    {
    public:
        CppAnonymArgumentException();
        CppAnonymArgumentException(std::string const &what);
        CppAnonymArgumentException(std::wstring const &what);
        CppAnonymArgumentException(std::string const &what, std::string const &paramName);
        CppAnonymArgumentException(std::wstring const &what, std::wstring const &paramName);
        CppAnonymArgumentException(std::string const &what, CppAnonymException &innerException);
        CppAnonymArgumentException(std::wstring const &what, CppAnonymException &innerException);
        CppAnonymArgumentException(std::string const &what, std::string const &paramName, CppAnonymException &innerException);
        CppAnonymArgumentException(std::wstring const &what, std::wstring const &paramName, CppAnonymException &innerException);

    private:
        static void AppendMessage(std::string &what, std::wstring const &paramName);
        static void AppendMessage(std::string &what, std::string const &paramName);
    };
        
}}  // namespace Urasandesu { namespace CppAnonym {

#endif  // URASANDESU_CPPANONYM_CPPANONYMARGUMENTEXCEPTION_H