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
    
    template<class T>
    struct DefaultHash<T const *> : 
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
        return DefaultHash<T>()(v);
    }


    namespace Detail {

        namespace mpl = boost::mpl;

        template<class T, class Tag = mpl::void_>
        struct CreateHashImpl
        {
            typedef DefaultHash<T> hash_type;
        };

        // Template specialization for an iterator.
        template<class T>
        struct CreateHashImpl<T, typename mpl::apply<mpl::always<mpl::void_>, typename T::value_type>::type>
        {
            typedef DefaultHash<typename T::value_type> hash_type;
        };
    
    }   // namespace Detail

    template<class T>
    inline typename Detail::CreateHashImpl<T>::hash_type CreateHash(T)
    {
        return typename Detail::CreateHashImpl<T>::hash_type();
    }

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_DEFAULTHASH_H