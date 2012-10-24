#pragma once
#ifndef URASANDESU_CPPANONYM_DEPENDENTOBJECTSPROVIDER_H
#define URASANDESU_CPPANONYM_DEPENDENTOBJECTSPROVIDER_H

#ifndef URASANDESU_CPPANONYM_DEPENDENTOBJECTSPROVIDERFWD_H
#include <Urasandesu/CppAnonym/DependentObjectsProviderFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym {

    namespace DependentObjectsProviderDetail {
        
        namespace mpl = boost::mpl;
        using namespace boost;
        using boost::is_same;
        using mpl::_;
        using mpl::_1;
        using mpl::_2;
        using mpl::at_c;
        using mpl::begin;
        using mpl::deref;
        using mpl::end;
        using mpl::filter_view;
        using mpl::find;
        using mpl::fold;
        using mpl::lambda;
        using mpl::next;
        using mpl::not_;
        using mpl::push_back;
        using mpl::reverse;
        using mpl::vector;
        using mpl::void_;


        template<class ReversedProvidingTypes, class I, class IEnd>
        class ATL_NO_VTABLE DependentObjectsProviderImplImpl : 
            public DependentObjectsProviderImplImpl<ReversedProvidingTypes, typename next<I>::type, IEnd>
        {
        public:
            typedef DependentObjectsProviderImplImpl<ReversedProvidingTypes, I, IEnd> this_type;
            typedef typename deref<I>::type object_type;

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
                                               typename end<ReversedProvidingTypes>::type, 
                                               typename end<ReversedProvidingTypes>::type> : 
            noncopyable
        {
        };

        template<class ReversedProvidingTypes, class ProvidingType>
        class ProviderOfImpl
        {
            typedef typename find<ReversedProvidingTypes, ProvidingType>::type i;
            typedef typename end<ReversedProvidingTypes>::type i_end;
        public:
            typedef DependentObjectsProviderImplImpl<ReversedProvidingTypes, i, i_end> type;
        };

        template<class ProvidingTypes>
        struct ATL_NO_VTABLE DependentObjectsProviderImpl : 
            DependentObjectsProviderImplImpl<typename reverse<ProvidingTypes>::type, 
                                             typename begin<typename reverse<ProvidingTypes>::type>::type, 
                                             typename end<typename reverse<ProvidingTypes>::type>::type>
        {
            typedef DependentObjectsProviderImpl<ProvidingTypes> this_type;
            typedef ProvidingTypes providing_types;

            template<LONG N>
            struct providing_type_at : 
                at_c<providing_types, N>
            {
            };

            template<class ProvidingType>
            struct provider_of : 
                ProviderOfImpl<typename reverse<ProvidingTypes>::type, ProvidingType>
            {
            };

            template<class ProvidingType>
            typename provider_of<ProvidingType>::type &ProviderOf() const
            {
                this_type *pMutableThis = const_cast<this_type *>(this);
                return static_cast<typename provider_of<ProvidingType>::type &>(*pMutableThis);
            }
        };

        template<class T0, CPPANONYM_DEPENDENT_OBJECTS_PROVIDER_ENUM_SHIFTED_PARAMS(class T)>
        class DesignatedSequence
        {
            typedef vector<T0, CPPANONYM_DEPENDENT_OBJECTS_PROVIDER_ENUM_SHIFTED_PARAMS(T)> types;
            typedef typename lambda<not_<is_same<_, void_> > >::type is_designated;
        public:
            typedef typename fold<filter_view<types, is_designated>, vector<>, push_back<_1, _2> >::type type;
        };

    }   // namespace DependentObjectsProviderDetail {

    template<class T0, CPPANONYM_DEPENDENT_OBJECTS_PROVIDER_ENUM_SHIFTED_PARAMS(class T)>
    struct ATL_NO_VTABLE DependentObjectsProvider : 
        DependentObjectsProviderDetail::DependentObjectsProviderImpl<
            typename DependentObjectsProviderDetail::DesignatedSequence<T0, CPPANONYM_DEPENDENT_OBJECTS_PROVIDER_ENUM_SHIFTED_PARAMS(T)>::type
        >
    {
    };

}}   // namespace Urasandesu { namespace CppAnonym {

#endif  // #ifndef URASANDESU_CPPANONYM_DEPENDENTOBJECTSPROVIDER_H