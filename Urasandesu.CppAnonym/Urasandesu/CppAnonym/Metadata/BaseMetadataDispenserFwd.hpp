#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATADISPENSERFWD_H
#define URASANDESU_CPPANONYM_METADATA_BASEMETADATADISPENSERFWD_H

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMETADATADISPENSERAPIHOLDERFWD_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultMetadataDispenserApiHolderFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    template<
        class MetadataDispenserApiHolder = ApiHolders::DefaultMetadataDispenserApiHolder
    >    
    class BaseMetadataDispenser;

    typedef BaseMetadataDispenser<> MetadataDispenser;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATADISPENSERFWD_H