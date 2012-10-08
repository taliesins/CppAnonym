#pragma once
#ifndef URASANDESU_CPPANONYM_DISPOSABLEHEAPPROVIDER_HPP
#define URASANDESU_CPPANONYM_DISPOSABLEHEAPPROVIDER_HPP

#ifndef URASANDESU_CPPANONYM_IDISPOSABLE_HPP
#include <Urasandesu/CppAnonym/IDisposable.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_PERSISTABLEHEAPPROVIDER_HPP
#include <Urasandesu/CppAnonym/PersistableHeapProvider.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_DISPOSABLEHEAPPROVIDERFWD_HPP
#include <Urasandesu/CppAnonym/DisposableHeapProviderFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym {

    namespace DisposableHeapProviderDetail {

        namespace mpl = boost::mpl;
        using namespace boost;
        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Utilities;

        template<class I>
        struct DisposingInfoFacade
        {
            typedef typename mpl::deref<I>::type disposing_info_type;
            typedef PersistableHeapProvider<disposing_info_type> base_type;
            typedef typename base_type::object_type object_type;
            typedef typename base_type::persisted_handler_type persisted_handler_type;
        };

        template<class ReversedDisposingInfoTypes, class I, class IEnd>
        class ATL_NO_VTABLE DisposableHeapProviderImplImpl : 
            public DisposingInfoFacade<I>::base_type,
            public DisposableHeapProviderImplImpl<ReversedDisposingInfoTypes, typename mpl::next<I>::type, IEnd>
        {
        public:
            typedef typename DisposingInfoFacade<I>::base_type base_type;
            typedef typename DisposingInfoFacade<I>::object_type object_type;
            typedef typename DisposingInfoFacade<I>::persisted_handler_type persisted_handler_type;

            ~DisposableHeapProviderImplImpl()
            {
                if (base_type::AnyObjects())
                    Destruct(base_type::Objects());
            }

            TempPtr<object_type> NewObject()
            {
                return base_type::NewObject();
            }

            SIZE_T RegisterObject(TempPtr<object_type> &p)
            {
                return base_type::RegisterObject(p);
            }

            object_type *GetObject(SIZE_T n)
            {
                return base_type::GetObject(n);
            }

            SIZE_T AddPersistedHandler(TempPtr<object_type> &p, persisted_handler_type const &handler)
            {
                return base_type::AddPersistedHandler(p, handler);
            }

        private:
            static void Destruct(std::vector<object_type *> &objects)
            {
                typedef std::vector<object_type *>::reverse_iterator ReverseIterator;
                for (ReverseIterator ri = objects.rbegin(), ri_end = objects.rend(); ri != ri_end; ++ri)
                    DisposeCore(*ri);
            }

            static void DisposeCore(object_type *p)
            {
                typedef typename mpl::or_<
                    CPP_ANONYM_HAS_MEMBER_FUNCTION(DisposingInfoDispose, object_type), 
                    boost::is_base_of<IDisposable, object_type> 
                >::type HasDispose;

                typedef dispose_core_impl_type<HasDispose> Impl;

                Impl::DisposeCore(p);
            }

            template<class HasDispose>
            struct dispose_core_impl_type
            {
                static inline void DisposeCore(object_type *p)
                {
                    // Do nothing.
                }
            };

            template<>
            struct dispose_core_impl_type<mpl::true_> 
            { 
                static inline void DisposeCore(object_type *p)
                {
                    p->Dispose();
                }
            };
        };

        template<class ReversedDisposingInfoTypes>
        class DisposableHeapProviderImplImpl<ReversedDisposingInfoTypes, 
                                              typename mpl::end<ReversedDisposingInfoTypes>::type, 
                                              typename mpl::end<ReversedDisposingInfoTypes>::type> : 
            noncopyable
        {
        };

        template<class DisposingInfo, class T>
        struct HasObjectT : 
            boost::is_same<typename CPP_ANONYM_GET_MEMBER_TYPE(DisposingInfoObject, DisposingInfo)::type, T>
        {
        };

        template<class DisposingInfoTypes, LONG N>
        class ProvidingTypeAtImpl
        {
            typedef typename mpl::at_c<DisposingInfoTypes, N>::type disposing_info_type;
        public:
            typedef typename disposing_info_type::object_type type;
        };

        template<class ReversedDisposingInfoTypes, class ProvidingType>
        class ProviderOfImpl
        {
            typedef typename mpl::find<ReversedDisposingInfoTypes, ProvidingType>::type i;
            typedef typename mpl::end<ReversedDisposingInfoTypes>::type i_end;
            BOOST_MPL_ASSERT((not_<boost::is_same<i, i_end> >));
        public:
            typedef DisposableHeapProviderImplImpl<ReversedDisposingInfoTypes, i, i_end> type;
        };

        template<class ReversedDisposingInfoTypes, class T>
        class IsProvidedImpl
        {
            typedef typename mpl::find_if<ReversedDisposingInfoTypes, HasObjectT<mpl::_1, T> >::type i;
            typedef typename mpl::end<ReversedDisposingInfoTypes>::type i_end;
        public:
            typedef typename mpl::not_<is_same<i, i_end> >::type type;
        };

        template<class ReversedDisposingInfoTypes, class ProvidingType>
        class ProvidingPersistedHandlerTypeAtImpl
        {
            typedef typename mpl::find_if<ReversedDisposingInfoTypes, HasObjectT<mpl::_1, ProvidingType> >::type i;
            typedef typename mpl::deref<i>::type disposing_info_type;
        public:
            typedef typename disposing_info_type::persisted_handler_type type;
        };
        
        template<class DisposingInfoTypes>
        struct ATL_NO_VTABLE DisposableHeapProviderImpl : 
            DisposableHeapProviderImplImpl<typename mpl::reverse<DisposingInfoTypes>::type, 
                                           typename mpl::begin<typename mpl::reverse<DisposingInfoTypes>::type>::type, 
                                           typename mpl::end<typename mpl::reverse<DisposingInfoTypes>::type>::type>
        {
            typedef DisposableHeapProviderImpl<DisposingInfoTypes> this_type;
            typedef DisposingInfoTypes disposing_info_types;

            template<LONG N>
            struct disposing_info_at : 
                mpl::at_c<disposing_info_types, N>
            {
            };

            template<LONG N>
            struct providing_type_at : 
                ProvidingTypeAtImpl<disposing_info_types, N>
            {
            };

            template<class ProvidingType>
            struct provider_of : 
                ProviderOfImpl<typename mpl::reverse<disposing_info_types>::type, ProvidingType>
            {
            };

            template<class T>
            struct is_provided : 
                IsProvidedImpl<typename mpl::reverse<disposing_info_types>::type, T>
            {
            };

            template<class ProvidingType>
            struct providing_persisted_handler_type_at : 
                ProvidingPersistedHandlerTypeAtImpl<typename mpl::reverse<disposing_info_types>::type, ProvidingType>
            {
            };

            template<class ProvidingType>
            inline typename provider_of<ProvidingType>::type &ProviderOf() const
            {
                this_type *pMutableThis = const_cast<this_type *>(this);
                return static_cast<typename provider_of<ProvidingType>::type &>(*pMutableThis);
            }
        };

        template<class T0, CPPANONYM_DISPOSABLE_HEAP_PROVIDER_ENUM_SHIFTED_PARAMS(class T)>
        class DesignatedSequence
        {
            typedef mpl::vector<T0, CPPANONYM_DISPOSABLE_HEAP_PROVIDER_ENUM_SHIFTED_PARAMS(T)> types;
            typedef typename mpl::lambda<not_<boost::is_same<_, void_> > >::type is_designated;
        public:
            typedef typename fold<filter_view<types, is_designated>, mpl::vector<>, mpl::push_back<_1, _2> >::type type;
        };

    }   // namespace DisposableHeapProviderDetail {

    template<class T0, CPPANONYM_DISPOSABLE_HEAP_PROVIDER_ENUM_SHIFTED_PARAMS(class T)>
    struct ATL_NO_VTABLE DisposableHeapProvider : 
        DisposableHeapProviderDetail::DisposableHeapProviderImpl<
            typename DisposableHeapProviderDetail::DesignatedSequence<T0, CPPANONYM_DISPOSABLE_HEAP_PROVIDER_ENUM_SHIFTED_PARAMS(T)>::type
        >
    {
    };

}}   // namespace Urasandesu { namespace CppAnonym {

#endif  // #ifndef URASANDESU_CPPANONYM_DISPOSABLEHEAPPROVIDER_HPP