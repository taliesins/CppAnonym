#pragma once
#ifndef URASANDESU_CPPANONYM_UTILITIES_HASHFWD_HPP
#define URASANDESU_CPPANONYM_UTILITIES_HASHFWD_HPP

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    template<class T>
    struct Hash;

    template<class T>
    inline std::size_t HashValue(T v);

    template<class T, class Tag = boost::mpl::void_>
    struct HashDecidedBy
    {
        typedef Hash<T> type;
    };

    // Template specialization for an iterator.
    template<class T>
    struct HashDecidedBy<T, typename boost::mpl::apply<boost::mpl::always<boost::mpl::void_>, typename T::value_type>::type>
    {
        typedef Hash<typename T::value_type> type;
    };

    template<class T>
    inline typename HashDecidedBy<T>::type CreateHash(T);

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_HASHFWD_HPP