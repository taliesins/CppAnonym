#pragma once
#ifndef URASANDESU_CPPANONYM_DEPENDENTOBJECTSPROVIDER_HPP
#define URASANDESU_CPPANONYM_DEPENDENTOBJECTSPROVIDER_HPP

#ifndef URASANDESU_CPPANONYM_DEPENDENTOBJECTSPROVIDER_H
#include <Urasandesu/CppAnonym/DependentObjectsProvider.h>
#endif

namespace Urasandesu { namespace CppAnonym {

    namespace DependentObjectsProviderDetail {

        template<class ReversedProvidingTypes, class I, class IEnd>
        inline typename DependentObjectsProviderImplImpl<ReversedProvidingTypes, I, IEnd>::object_type &
            DependentObjectsProviderImplImpl<ReversedProvidingTypes, I, IEnd>::Object()
        {
            if (!m_pObject)
                m_pObject = make_shared<object_type>();
            return *m_pObject.get();
        }

        template<class ProvidingTypes>
        template<class ProvidingType>
        inline typename DependentObjectsProviderImpl<ProvidingTypes>::provider_of<ProvidingType>::type &
            DependentObjectsProviderImpl<ProvidingTypes>::ProviderOf() const
        {
            this_type *pMutableThis = const_cast<this_type *>(this);
            return static_cast<typename provider_of<ProvidingType>::type &>(*pMutableThis);
        }

    }   // namespace DependentObjectsProviderDetail {

}}   // namespace Urasandesu { namespace CppAnonym {

#endif  // #ifndef URASANDESU_CPPANONYM_DEPENDENTOBJECTSPROVIDER_HPP