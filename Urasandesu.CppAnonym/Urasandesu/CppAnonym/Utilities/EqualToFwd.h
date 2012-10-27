#pragma once
#ifndef URASANDESU_CPPANONYM_UTILITIES_EQUALTOFWD_H
#define URASANDESU_CPPANONYM_UTILITIES_EQUALTOFWD_H

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    namespace EqualToDetail {

        template<class T>
        struct EqualToImpl;

    }   // namespace EqualToDetail {

    template<class T>
    struct EqualTo;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_EQUALTOFWD_H