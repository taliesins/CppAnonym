#pragma once
#ifndef URASANDESU_CPPANONYM_HOSTING_BASEHOSTINFOFWD_HPP
#define URASANDESU_CPPANONYM_HOSTING_BASEHOSTINFOFWD_HPP

#ifndef URASANDESU_CPPANONYM_HOSTING_APIHOLDERS_DEFAULTHOSTINFOAPIHOLDERFWD_H
#include <Urasandesu/CppAnonym/Hosting/ApiHolders/DefaultHostInfoApiHolderFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Hosting {

    template<
        class HostInfoApiHolder = ApiHolders::DefaultHostInfoApiHolder
    >    
    class BaseHostInfo;

    typedef BaseHostInfo<> HostInfo;

    
    
    
    
    template<
        class HostInfoApiHolder = ApiHolders::DefaultHostInfoApiHolder
    >    
    class BaseHostInfoPersistedHandler;

    typedef BaseHostInfoPersistedHandler<> HostInfoPersistedHandler;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting {

#endif  // URASANDESU_CPPANONYM_HOSTING_BASEHOSTINFOFWD_HPP