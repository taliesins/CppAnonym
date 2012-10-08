#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_BASEILGENERATORFWD_HPP
#define URASANDESU_CPPANONYM_METADATA_BASEILGENERATORFWD_HPP

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTILGENERATORAPIHOLDERFWD_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultILGeneratorApiHolderFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    template<
        class ILGeneratorApiHolder = ApiHolders::DefaultILGeneratorApiHolder
    >    
    class BaseILGenerator;

    typedef BaseILGenerator<> ILGenerator;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASEILGENERATORFWD_HPP