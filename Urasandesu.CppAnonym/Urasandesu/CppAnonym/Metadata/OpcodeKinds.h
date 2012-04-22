#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_OPCODEKINDS_H
#define URASANDESU_CPPANONYM_METADATA_OPCODEKINDS_H

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    class OpcodeKind;

    struct OpcodeKinds
    {
        static const OpcodeKind IInternal;
        static const OpcodeKind IMacro;
        static const OpcodeKind IObjModel;
        static const OpcodeKind IPrefix;
        static const OpcodeKind IPrimitive;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_OPCODEKINDS_H