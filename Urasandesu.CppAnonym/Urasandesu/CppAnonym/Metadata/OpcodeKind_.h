#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_OPCODEKIND_H
#define URASANDESU_CPPANONYM_METADATA_OPCODEKIND_H

#ifndef URASANDESU_CPPANONYM_METADATA_OPCODEKINDTYPES_H
#include "Urasandesu/CppAnonym/Metadata/OpCodeKindTypes.h"
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    class OpCodeKind
    {
    public:
        inline OpCodeKind(OpCodeKindTypes const &type) : 
            m_type(type)
        { }

        inline OpCodeKindTypes const &GetType() const { return m_type; }

    private:
        OpCodeKindTypes m_type;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_OPCODEKIND_H