#pragma once
#ifndef URASANDESU_CPPANONYM_UTILITIES_HASHFWD_H
#define URASANDESU_CPPANONYM_UTILITIES_HASHFWD_H

#ifndef URASANDESU_CPPANONYM_TRAITS_HASMEMBERTYPE_H
#include <Urasandesu/CppAnonym/Traits/HasMemberType.h>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_GETMEMBERTYPE_H
#include <Urasandesu/CppAnonym/Traits/GetMemberType.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    namespace HashDetail {

        template<class T>
        struct HashImpl; 

    }   // namespace HashDetail {

    template<class T>
    struct Hash;

    template<class T>
    std::size_t HashValue(T v);

    namespace HashDetail {

        namespace mpl = boost::mpl;
        using mpl::eval_if;
        using mpl::identity;

        CPP_ANONYM_DECLARE_HAS_MEMBER_TYPE(HashActualValueType, value_type);
        CPP_ANONYM_DECLARE_GET_MEMBER_TYPE(HashActualValueType, value_type);
        
        template<class T>
        class HashDecidedByImpl
        {
            typedef typename eval_if<
                        CPP_ANONYM_HAS_MEMBER_TYPE(HashActualValueType, T),
                        CPP_ANONYM_GET_MEMBER_TYPE(HashActualValueType, T),
                        identity<T> >::type value_type;
        public:
            typedef Hash<value_type> type;
        };

    }   // namespace HashDetail {

    template<class T>
    struct HashDecidedBy : 
        HashDetail::HashDecidedByImpl<T>
    {
    };

    template<class T>
    typename HashDecidedBy<T>::type CreateHash(T);

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_HASHFWD_H