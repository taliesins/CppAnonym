#pragma once
#ifndef URASANDESU_CPPANONYM_UTILITIES_TEMPPTRFWD_H
#define URASANDESU_CPPANONYM_UTILITIES_TEMPPTRFWD_H

#ifndef URASANDESU_CPPANONYM_SAFEENUM_H
#include <Urasandesu/CppAnonym/SafeEnum.h>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_HASMEMBERTYPE_H
#include <Urasandesu/CppAnonym/Traits/HasMemberType.h>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_GETMEMBERTYPE_H
#include <Urasandesu/CppAnonym/Traits/GetMemberType.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    namespace TempPtrDetail {

        using namespace boost;

        namespace TempPtrStatesDetail {

            struct TempPtrStatesDef
            {
                enum type
                {
                    TPS_NONE, 
                    TPS_PERSISTED, 
                    TPS_HAS_ALREADY_PERSISTED, 
                    TPS_UNREACHED
                };
            };

        }   // TempPtrStatesDetail

        typedef SafeEnum<TempPtrStatesDetail::TempPtrStatesDef> TempPtrStates;

        struct TempPtrHolder;

        template<class T, class TD, class ImplD>
        struct TempPtrHolderImpl;

        template<class T, class TD, class ImplD>
        struct MakeHolderImpl;

        template<
            class T, 
            class Tag = QuickHeapWithoutSubscriptOperator
        >
        struct MakeHeapHolderImpl;

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

        template<class U> 
        struct PersistedHandlersAccessor;

    }   // namespace TempPtrDetail {

    template<class T>
    struct TempPtr;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_TEMPPTRFWD_H