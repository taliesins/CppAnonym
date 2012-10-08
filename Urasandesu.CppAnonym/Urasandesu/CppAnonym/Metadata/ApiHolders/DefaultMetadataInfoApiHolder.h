#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMETADATAINFOAPIHOLDER_H
#define URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMETADATAINFOAPIHOLDER_H

#ifndef URASANDESU_CPPANONYM_HOSTING_BASERUNTIMEHOSTFWD_HPP
#include <Urasandesu/CppAnonym/Hosting/BaseRuntimeHostFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_HOSTING_INTERFACES_RUNTIMEHOSTLABELFWD_HPP
#include <Urasandesu/CppAnonym/Hosting/Interfaces/RuntimeHostLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_METADATADISPENSERLABELFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/MetadataDispenserLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATADISPENSERFWD_H
#include <Urasandesu/CppAnonym/Metadata/BaseMetadataDispenserFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

    struct DefaultMetadataInfoApiHolder
    {
        typedef boost::mpl::map<boost::mpl::pair<Hosting::Interfaces::RuntimeHostLabel, Hosting::BaseRuntimeHost<> >, 
                                boost::mpl::pair<Interfaces::MetadataDispenserLabel, BaseMetadataDispenser<> > > api_cartridges;
    };

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMETADATAINFOAPIHOLDER_H