#pragma once
#ifndef URASANDESU_CPPANONYM_HOSTING_BASERUNTIMEHOSTFWD_HPP
#define URASANDESU_CPPANONYM_HOSTING_BASERUNTIMEHOSTFWD_HPP

#ifndef URASANDESU_CPPANONYM_HOSTING_APIHOLDERS_DEFAULTRUNTIMEHOSTAPIHOLDERFWD_H
#include <Urasandesu/CppAnonym/Hosting/ApiHolders/DefaultRuntimeHostApiHolderFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Hosting {

    template<
        class RuntimeHostApiHolder = ApiHolders::DefaultRuntimeHostApiHolder
    >
    class BaseRuntimeHost;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting {

#endif  // URASANDESU_CPPANONYM_HOSTING_BASERUNTIMEHOSTFWD_HPP