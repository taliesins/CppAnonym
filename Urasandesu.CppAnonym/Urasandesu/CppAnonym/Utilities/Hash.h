#pragma once
#ifndef URASANDESU_CPPANONYM_UTILITIES_HASH_H
#define URASANDESU_CPPANONYM_UTILITIES_HASH_H

#ifndef URASANDESU_CPPANONYM_TRAITS_HASHCOMPUTABLE_H
#include <Urasandesu/CppAnonym/Traits/HashComputable.h>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_HASHFWD_H
#include <Urasandesu/CppAnonym/Utilities/HashFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    namespace HashDetail {

        using boost::filesystem::path;

        template<>
        struct HashImpl<path> : 
            Traits::HashComputable<path>
        {
            result_type operator()(param_type v) const
            {
                using boost::hash_combine;
                using std::locale;
                using std::toupper;
                
                typedef path::string_type String;
                
                std::size_t seed = 0;

                String const &native = v.native();
                typedef String::const_iterator ConstIterator;
                for (ConstIterator ci = native.cbegin(), ci_end = native.cend(); ci != ci_end; ++ci)
                {
                    hash_combine(seed, toupper(*ci, locale()));
                }

                return seed;
            }
        };

    }   // namespace HashDetail {

    template<>
    struct Hash<boost::filesystem::path> : 
        HashDetail::HashImpl<boost::filesystem::path>
    {
    };
    
    
    
    
    
    template<class T>
    struct Hash<T const *> : 
        Traits::HashComputable<T const *>
    {
        result_type operator()(param_type v) const
        {
            return reinterpret_cast<std::size_t>(v);
        }
    };


    
    
    
    template<class T>
    std::size_t HashValue(T v)
    {
        return Hash<T>()(v);
    }

    
    
    
    
    template<class T>
    typename HashDecidedBy<T>::type CreateHash(T)
    {
        return typename HashDecidedBy<T>::type();
    }

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_HASH_H