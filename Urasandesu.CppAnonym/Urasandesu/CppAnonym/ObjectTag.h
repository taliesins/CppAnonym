#pragma once
#ifndef URASANDESU_CPPANONYM_OBJECTTAG_H
#define URASANDESU_CPPANONYM_OBJECTTAG_H

#ifndef URASANDESU_CPPANONYM_OBJECTTAGFWD_H
#include <Urasandesu/CppAnonym/ObjectTagFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym {
    
    template<class Object, class Tag>
    struct ObjectTag
    {
        typedef Object object_type;
        typedef Tag tag_type;
    };

}}   // namespace Urasandesu { namespace CppAnonym {

#endif  // #ifndef URASANDESU_CPPANONYM_OBJECTTAG_H