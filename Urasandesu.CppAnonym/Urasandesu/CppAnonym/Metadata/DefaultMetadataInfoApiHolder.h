#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_DEFAULTMETADATAINFOAPIHOLDER_H
#define URASANDESU_CPPANONYM_METADATA_DEFAULTMETADATAINFOAPIHOLDER_H

#ifndef URASANDESU_CPPANONYM_HOSTING_BASERUNTIMEHOSTFWD_HPP
#include <Urasandesu/CppAnonym/Hosting/BaseRuntimeHostFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_HOSTING_RUNTIMEHOSTLABELFWD_HPP
#include <Urasandesu/CppAnonym/Hosting/RuntimeHostLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_METADATADISPENSERLABELFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/MetadataDispenserLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATADISPENSERFWD_H
#include <Urasandesu/CppAnonym/Metadata/BaseMetadataDispenserFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    struct DefaultMetadataInfoApiHolder
    {
        typedef boost::mpl::map<boost::mpl::pair<Hosting::RuntimeHostLabel, Hosting::BaseRuntimeHost<> >, 
                                boost::mpl::pair<MetadataDispenserLabel, BaseMetadataDispenser<> > > api_cartridges;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_DEFAULTMETADATAINFOAPIHOLDER_H