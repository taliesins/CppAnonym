#pragma once
#ifndef URASANDESU_CPPANONYM_OBJECTTAG_HPP
#define URASANDESU_CPPANONYM_OBJECTTAG_HPP

#ifndef URASANDESU_CPPANONYM_OBJECTTAGFWD_HPP
#include <Urasandesu/CppAnonym/ObjectTagFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym {
    
    template<class Object, class Tag>
    struct ObjectTag
    {
        typedef Object object_type;
        typedef Tag tag_type;
    };

}}   // namespace Urasandesu { namespace CppAnonym {

#endif  // #ifndef URASANDESU_CPPANONYM_OBJECTTAG_HPP