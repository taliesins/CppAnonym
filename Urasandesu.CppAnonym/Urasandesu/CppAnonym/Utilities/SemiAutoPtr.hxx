#pragma once
#ifndef URASANDESU_CPPANONYM_UTILITIES_SEMIAUTOPTR_HXX
#define URASANDESU_CPPANONYM_UTILITIES_SEMIAUTOPTR_HXX

#ifndef URASANDESU_CPPANONYM_UTILITIES_SEMIAUTOPTR_H
#include <Urasandesu/CppAnonym/Utilities/SemiAutoPtr.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    namespace SemiAutoPtrDetail {

        template intrusive_ptr<SemiAutoPtrHolder>;

    }   // namespace SemiAutoPtrDetail {

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_SEMIAUTOPTR_HXX