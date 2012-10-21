#pragma once
#ifndef URASANDESU_CPPANONYM_SIMPLEHEAPPROVIDERFWD_HPP
#define URASANDESU_CPPANONYM_SIMPLEHEAPPROVIDERFWD_HPP

#ifndef URASANDESU_CPPANONYM_TRAITS_HASMEMBERTYPE_HPP
#include <Urasandesu/CppAnonym/Traits/HasMemberType.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_GETMEMBERTYPE_H
#include <Urasandesu/CppAnonym/Traits/GetMemberType.h>
#endif

namespace Urasandesu { namespace CppAnonym {

    namespace SimpleHeapProviderDetail {
        
        template<class ObjectTagSequence, class I, class IEnd>
        class ATL_NO_VTABLE SimpleHeapProviderImpl;

        CPP_ANONYM_DECLARE_HAS_MEMBER_TYPE(ObjectTagObject, object_type);
        CPP_ANONYM_DECLARE_GET_MEMBER_TYPE(ObjectTagObject, object_type);

        CPP_ANONYM_DECLARE_HAS_MEMBER_TYPE(ObjectTagTag, tag_type);
        CPP_ANONYM_DECLARE_GET_MEMBER_TYPE(ObjectTagTag, tag_type);

    }   // namespace SimpleHeapProviderDetail


    template<class ObjectTagSequence>
    class ATL_NO_VTABLE SimpleHeapProvider;

}}   // namespace Urasandesu { namespace CppAnonym {

#endif  // #ifndef URASANDESU_CPPANONYM_SIMPLEHEAPPROVIDERFWD_HPP