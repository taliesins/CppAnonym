#pragma once
#ifndef URASANDESU_CPPANONYM_UTILITIES_DEFAULTHASH_H
#define URASANDESU_CPPANONYM_UTILITIES_DEFAULTHASH_H

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    template<class T>
    struct DefaultHash;

    template<>
    struct DefaultHash<boost::filesystem::path> : 
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

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_DEFAULTHASH_H