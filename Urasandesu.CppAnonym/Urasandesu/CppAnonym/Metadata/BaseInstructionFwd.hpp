#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_BASEINSTRUCTIONFWD_HPP
#define URASANDESU_CPPANONYM_METADATA_BASEINSTRUCTIONFWD_HPP

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTINSTRUCTIONAPIHOLDERFWD_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultInstructionApiHolderFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    template<
        class InstructionApiHolder = ApiHolders::DefaultInstructionApiHolder
    >    
    class BaseInstruction;

    typedef BaseInstruction<> Instruction;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASEINSTRUCTIONFWD_HPP