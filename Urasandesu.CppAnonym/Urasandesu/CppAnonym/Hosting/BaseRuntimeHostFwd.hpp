#pragma once
#ifndef URASANDESU_CPPANONYM_HOSTING_BASERUNTIMEHOSTFWD_HPP
#define URASANDESU_CPPANONYM_HOSTING_BASERUNTIMEHOSTFWD_HPP

#ifndef URASANDESU_CPPANONYM_HOSTING_DEFAULTRUNTIMEHOSTAPIHOLDERFWD_H
#include <Urasandesu/CppAnonym/Hosting/DefaultRuntimeHostApiHolderFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Hosting {

    //struct DefaultRuntimeHostApiHolder;

    template<
        class RuntimeHostApiHolder = DefaultRuntimeHostApiHolder
    >
    class BaseRuntimeHost;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting {

#endif  // URASANDESU_CPPANONYM_HOSTING_BASERUNTIMEHOSTFWD_HPP