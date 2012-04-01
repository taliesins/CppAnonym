#pragma once
#ifndef URASANDESU_CPPANONYM_UTILITIES_DEFAULTEQUALTO_H
#define URASANDESU_CPPANONYM_UTILITIES_DEFAULTEQUALTO_H

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    template<class X, class Y>
    struct DefaultEqualTo;

    template<>
    struct DefaultEqualTo<boost::filesystem::path, boost::filesystem::path> : 
        std::binary_function<boost::filesystem::path, boost::filesystem::path, bool>
    {
        inline bool operator()(boost::filesystem::path const &x, boost::filesystem::path const &y) const
        {
            return boost::algorithm::iequals(x.native(), y.native());
        }
    };

    template<class T>
    struct DefaultEqualTo<T const *, T const *> : 
        std::binary_function<T const *, T const *, bool>
    {
        inline bool operator()(T const *x, T const *y) const
        {
            return x == y;
        }
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_DEFAULTEQUALTO_H