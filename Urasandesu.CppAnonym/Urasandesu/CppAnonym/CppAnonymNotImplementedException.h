#pragma once
#ifndef URASANDESU_CPPANONYM_CPPANONYMNOTIMPLEMENTEDEXCEPTION_H
#define URASANDESU_CPPANONYM_CPPANONYMNOTIMPLEMENTEDEXCEPTION_H

namespace Urasandesu { namespace CppAnonym {

    struct CppAnonymNotImplementedException : CppAnonymException
    {
        CppAnonymNotImplementedException();
        CppAnonymNotImplementedException(std::string const &what);
        CppAnonymNotImplementedException(std::wstring const &what);
        CppAnonymNotImplementedException(std::string const &what, CppAnonymException &innerException);
        CppAnonymNotImplementedException(std::wstring const &what, CppAnonymException &innerException);
    };
        
}}  // namespace Urasandesu { namespace CppAnonym {

#endif  // URASANDESU_CPPANONYM_CPPANONYMNOTIMPLEMENTEDEXCEPTION_H