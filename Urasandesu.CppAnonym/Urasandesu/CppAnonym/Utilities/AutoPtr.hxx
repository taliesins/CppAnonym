#pragma once
#ifndef URASANDESU_CPPANONYM_UTILITIES_AUTOPTR_HXX
#define URASANDESU_CPPANONYM_UTILITIES_AUTOPTR_HXX

#ifndef URASANDESU_CPPANONYM_UTILITIES_AUTOPTR_HPP
#include <Urasandesu/CppAnonym/Utilities/AutoPtr.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    namespace AutoPtrDetail {

        template intrusive_ptr<AutoPtrHolder>;

    }   // namespace AutoPtrDetail {

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_AUTOPTR_HXX