#pragma once
#ifndef URASANDESU_CPPANONYM_UTILITIES_EQUALTO_HPP
#define URASANDESU_CPPANONYM_UTILITIES_EQUALTO_HPP

#ifndef URASANDESU_CPPANONYM_UTILITIES_EQUALTOFWD_HPP
#include <Urasandesu/CppAnonym/Utilities/EqualToFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    template<>
    struct EqualTo<boost::filesystem::path, boost::filesystem::path> : 
        std::binary_function<boost::filesystem::path, boost::filesystem::path, bool>
    {
        inline bool operator()(boost::filesystem::path const &x, boost::filesystem::path const &y) const
        {
            return boost::algorithm::iequals(x.native(), y.native());
        }
    };

    template<class T>
    struct EqualTo<T const *, T const *> : 
        std::binary_function<T const *, T const *, bool>
    {
        inline bool operator()(T const *x, T const *y) const
        {
            return x == y;
        }
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_EQUALTO_HPP