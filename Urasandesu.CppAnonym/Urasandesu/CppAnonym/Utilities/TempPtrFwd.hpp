#pragma once
#ifndef URASANDESU_CPPANONYM_UTILITIES_TEMPPTRFWD_HPP
#define URASANDESU_CPPANONYM_UTILITIES_TEMPPTRFWD_HPP

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    namespace TempPtrDetail {

        struct PersistedHandlerHolder;

        CPP_ANONYM_DECLARE_HAS_MEMBER_TYPE(PersistedHandlerSender, sender_type);
        CPP_ANONYM_DECLARE_GET_MEMBER_TYPE(PersistedHandlerSender, sender_type);

        CPP_ANONYM_DECLARE_HAS_MEMBER_TYPE(PersistedHandlerArg, arg_type);
        CPP_ANONYM_DECLARE_GET_MEMBER_TYPE(PersistedHandlerArg, arg_type);

        template<class Handler, class ImplD>
        struct PersistedHandlerHolderImpl;

        template<class Handler, class ImplD>
        struct MakePersistedHandlerHolderImpl;

        template<
            class Handler, 
            class Tag = QuickHeapWithoutSubscriptOperator
        >
        struct MakeHeapPersistedHandlerHolderImpl;

        template<class T>
        class TempPtrImpl;

    }   // namespace TempPtrDetail {

    template<class T>
    struct TempPtr;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_TEMPPTRFWD_HPP