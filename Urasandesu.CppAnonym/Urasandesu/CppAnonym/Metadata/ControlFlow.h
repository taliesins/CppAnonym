#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_CONTROLFLOW_H
#define URASANDESU_CPPANONYM_METADATA_CONTROLFLOW_H

#ifndef URASANDESU_CPPANONYM_METADATA_CONTROLFLOWTYPES_H
#include <Urasandesu/CppAnonym/Metadata/ControlFlowTypes.h>
#endif

#ifndef URASANDESU_CPPANONYM_SAFEENUM_HPP
#include <Urasandesu/CppAnonym/SafeEnum.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_CONTROLFLOWFWD_H
#include <Urasandesu/CppAnonym/Metadata/ControlFlowFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    class ControlFlow
    {
    public:
        inline ControlFlow(ControlFlowTypes const &type) : 
            m_type(type)
        { }

        inline ControlFlowTypes const &GetType() const { return m_type; }

    private:
        ControlFlowTypes m_type;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_CONTROLFLOW_H