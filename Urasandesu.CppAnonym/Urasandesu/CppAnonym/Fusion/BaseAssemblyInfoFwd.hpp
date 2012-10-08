#pragma once
#ifndef URASANDESU_CPPANONYM_FUSION_BASEASSEMBLYINFOFWD_HPP
#define URASANDESU_CPPANONYM_FUSION_BASEASSEMBLYINFOFWD_HPP

#ifndef URASANDESU_CPPANONYM_FUSION_APIHOLDERS_DEFAULTASSEMBLYINFOAPIHOLDERFWD_H
#include <Urasandesu/CppAnonym/Fusion/ApiHolders/DefaultAssemblyInfoApiHolderFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Fusion {

    template<
        class AssemblyInfoApiHolder = ApiHolders::DefaultAssemblyInfoApiHolder
    >    
    class BaseAssemblyInfo;

    typedef BaseAssemblyInfo<> AssemblyInfo;

}}}  // namespace Urasandesu { namespace CppAnonym { namespace Fusion {

#endif  // URASANDESU_CPPANONYM_FUSION_BASEASSEMBLYINFOFWD_HPP