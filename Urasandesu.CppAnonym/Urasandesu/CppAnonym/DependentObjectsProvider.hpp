#pragma once
#ifndef URASANDESU_CPPANONYM_DEPENDENTOBJECTSPROVIDER_HPP
#define URASANDESU_CPPANONYM_DEPENDENTOBJECTSPROVIDER_HPP

#ifndef URASANDESU_CPPANONYM_DEPENDENTOBJECTSPROVIDERFWD_HPP
#include <Urasandesu/CppAnonym/DependentObjectsProviderFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym {

    namespace DependentObjectsProviderDetail {
        
        namespace mpl = boost::mpl;
        using namespace boost;

        template<class ReversedProvidingTypes, class I, class IEnd>
        class ATL_NO_VTABLE DependentObjectsProviderImplImpl : 
            public DependentObjectsProviderImplImpl<ReversedProvidingTypes, typename mpl::next<I>::type, IEnd>
        {
        public:
            typedef DependentObjectsProviderImplImpl<ReversedProvidingTypes, I, IEnd> this_type;
            typedef typename mpl::deref<I>::type object_type;

            object_type &Object()
            {
                if (!m_pObject)
                    m_pObject = make_shared<object_type>();
                return *m_pObject.get();
            }

        private:
            shared_ptr<object_type> m_pObject;
        };

        template<class ReversedProvidingTypes>
        class DependentObjectsProviderImplImpl<ReversedProvidingTypes, 
                                               typename mpl::end<ReversedProvidingTypes>::type, 
                                               typename mpl::end<ReversedProvidingTypes>::type> : 
            noncopyable
        {
        };

        template<class ReversedProvidingTypes, class ProvidingType>
        class ProviderOfImpl
        {
            typedef typename mpl::find<ReversedProvidingTypes, ProvidingType>::type i;
            typedef typename mpl::end<ReversedProvidingTypes>::type i_end;
        public:
            typedef DependentObjectsProviderImplImpl<ReversedProvidingTypes, i, i_end> type;
        };

        template<class ProvidingTypes>
        struct ATL_NO_VTABLE DependentObjectsProviderImpl : 
            DependentObjectsProviderImplImpl<typename mpl::reverse<ProvidingTypes>::type, 
                                             typename mpl::begin<typename mpl::reverse<ProvidingTypes>::type>::type, 
                                             typename mpl::end<typename mpl::reverse<ProvidingTypes>::type>::type>
        {
            typedef DependentObjectsProviderImpl<ProvidingTypes> this_type;
            typedef ProvidingTypes providing_types;

            template<LONG N>
            struct providing_type_at : 
                mpl::at_c<providing_types, N>
            {
            };

            template<class ProvidingType>
            struct provider_of : 
                ProviderOfImpl<typename mpl::reverse<ProvidingTypes>::type, ProvidingType>
            {
            };

            template<class ProvidingType>
            inline typename provider_of<ProvidingType>::type &ProviderOf() const
            {
                this_type *pMutableThis = const_cast<this_type *>(this);
                return static_cast<typename provider_of<ProvidingType>::type &>(*pMutableThis);
            }
        };

    }   // namespace DependentObjectsProviderDetail {

    template<class ProvidingTypes>
    struct ATL_NO_VTABLE DependentObjectsProvider : 
        DependentObjectsProviderDetail::DependentObjectsProviderImpl<ProvidingTypes>
    {
    };

}}   // namespace Urasandesu { namespace CppAnonym {

#endif  // #ifndef URASANDESU_CPPANONYM_DEPENDENTOBJECTSPROVIDER_HPP