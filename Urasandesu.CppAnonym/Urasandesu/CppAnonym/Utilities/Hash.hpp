#pragma once
#ifndef URASANDESU_CPPANONYM_UTILITIES_HASH_HPP
#define URASANDESU_CPPANONYM_UTILITIES_HASH_HPP

#ifndef URASANDESU_CPPANONYM_UTILITIES_HASHFWD_HPP
#include <Urasandesu/CppAnonym/Utilities/HashFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    template<>
    struct Hash<boost::filesystem::path> : 
        std::unary_function<boost::filesystem::path, std::size_t>
    {
        std::size_t operator()(boost::filesystem::path const &x) const
        {
            typedef boost::filesystem::path::string_type string_type;
            std::size_t seed = 0;

            string_type const &native = x.native();
            for (string_type::const_iterator i = native.begin(), i_end = native.end(); i != i_end; ++i)
            {
                boost::hash_combine(seed, std::toupper(*i, std::locale()));
            }

            return seed;
        }
    };
    
    template<class T>
    struct Hash<T const *> : 
        std::unary_function<T const *, std::size_t>
    {
        inline std::size_t operator()(T const *x) const
        {
            return reinterpret_cast<std::size_t>(x);
        }
    };


    template<class T>
    inline std::size_t HashValue(T v)
    {
        return Hash<T>()(v);
    }

    
    template<class T>
    inline typename HashDecidedBy<T>::type CreateHash(T)
    {
        return typename HashDecidedBy<T>::type();
    }

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_HASH_HPP