#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_OPCODEKIND_H
#define URASANDESU_CPPANONYM_METADATA_OPCODEKIND_H

#ifndef URASANDESU_CPPANONYM_METADATA_OPCODEKINDTYPES_H
#include "Urasandesu/CppAnonym/Metadata/OpcodeKindTypes.h"
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    class OpcodeKind
    {
    public:
        inline OpcodeKind(OpcodeKindTypes const &type) : 
            m_type(type)
        { }

        inline OpcodeKindTypes const &GetType() const { return m_type; }

    private:
        OpcodeKindTypes m_type;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_OPCODEKIND_H