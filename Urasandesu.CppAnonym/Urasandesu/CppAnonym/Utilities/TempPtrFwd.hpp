#pragma once
#ifndef URASANDESU_CPPANONYM_UTILITIES_TEMPPTRFWD_HPP
#define URASANDESU_CPPANONYM_UTILITIES_TEMPPTRFWD_HPP

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    namespace TempPtrDetail {

        struct PersistedHandler;

        CPP_ANONYM_DECLARE_HAS_MEMBER_TYPE(PersistedHandler, sender_type);
        CPP_ANONYM_DECLARE_GET_MEMBER_TYPE(PersistedHandler, sender_type);

        CPP_ANONYM_DECLARE_HAS_MEMBER_TYPE(PersistedHandler, arg_type);
        CPP_ANONYM_DECLARE_GET_MEMBER_TYPE(PersistedHandler, arg_type);

        template<class Handler>
        struct PersistedHandlerImpl;

        template<class Handler>
        struct PersistedHandlerImplFactory;

        template<class T>
        class TempPtrImpl;

    }   // namespace TempPtrDetail {

    template<class T>
    struct TempPtr;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_TEMPPTRFWD_HPP