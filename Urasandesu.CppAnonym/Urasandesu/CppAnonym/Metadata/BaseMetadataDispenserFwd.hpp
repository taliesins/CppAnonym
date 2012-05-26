#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATADISPENSERFWD_H
#define URASANDESU_CPPANONYM_METADATA_BASEMETADATADISPENSERFWD_H

#ifndef URASANDESU_CPPANONYM_METADATA_DEFAULTMETADATADISPENSERAPIHOLDERFWD_H
#include <Urasandesu/CppAnonym/Metadata/DefaultMetadataDispenserApiHolderFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    template<
        class MetadataDispenserApiHolder = DefaultMetadataDispenserApiHolder
    >    
    class BaseMetadataDispenser;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATADISPENSERFWD_H