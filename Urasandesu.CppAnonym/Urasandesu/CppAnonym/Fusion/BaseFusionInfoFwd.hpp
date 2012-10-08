#pragma once
#ifndef URASANDESU_CPPANONYM_FUSION_BASEFUSIONINFOFWD_HPP
#define URASANDESU_CPPANONYM_FUSION_BASEFUSIONINFOFWD_HPP

#ifndef URASANDESU_CPPANONYM_FUSION_APIHOLDERS_DEFAULTFUSIONINFOAPIHOLDERFWD_H
#include <Urasandesu/CppAnonym/Fusion/ApiHolders/DefaultFusionInfoApiHolderFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Fusion {

    template<
        class FusionInfoApiHolder = ApiHolders::DefaultFusionInfoApiHolder
    >    
    class BaseFusionInfo;

    typedef BaseFusionInfo<> FusionInfo;

}}}  // namespace Urasandesu { namespace CppAnonym { namespace Fusion {

#endif  // URASANDESU_CPPANONYM_FUSION_BASEFUSIONINFOFWD_HPP