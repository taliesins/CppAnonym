#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETHODBODYWRITERFWD_HPP
#define URASANDESU_CPPANONYM_METADATA_BASEMETHODBODYWRITERFWD_HPP

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMETHODBODYWRITERAPIHOLDERFWD_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultMethodBodyWriterApiHolderFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    template<
        class MethodBodyWriterApiHolder = ApiHolders::DefaultMethodBodyWriterApiHolder
    >    
    class BaseMethodBodyWriter;

    typedef BaseMethodBodyWriter<> MethodBodyWriter;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASEMETHODBODYWRITERFWD_HPP