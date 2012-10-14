#pragma once
#ifndef URASANDESU_CPPANONYM_DISPOSABLEHEAPPROVIDER_HPP
#define URASANDESU_CPPANONYM_DISPOSABLEHEAPPROVIDER_HPP

#ifndef URASANDESU_CPPANONYM_DISPOSABLEHEAPPROVIDER_H
#include <Urasandesu/CppAnonym/DisposableHeapProvider.h>
#endif

namespace Urasandesu { namespace CppAnonym {

    namespace DisposableHeapProviderDetail {

        template<class T, class HasDispose>
        inline void DisposeCoreImpl<T, HasDispose>::DisposeCore(T *p)
        {
            // Do nothing.
        }

        template<class T>
        inline void DisposeCoreImpl<T, mpl::true_>::DisposeCore(T *p)
        {
            p->Dispose();
        }

        template<class ReversedDisposingInfoTypes, class I, class IEnd>
        DisposableHeapProviderImplImpl<ReversedDisposingInfoTypes, I, IEnd>::~DisposableHeapProviderImplImpl()
        {
            if (base_type::AnyObjects())
                Destruct(base_type::Objects());
        }

        template<class ReversedDisposingInfoTypes, class I, class IEnd>
        TempPtr<typename DisposableHeapProviderImplImpl<ReversedDisposingInfoTypes, I, IEnd>::object_type> 
            DisposableHeapProviderImplImpl<ReversedDisposingInfoTypes, I, IEnd>::NewObject()
        {
            return base_type::NewObject();
        }

        template<class ReversedDisposingInfoTypes, class I, class IEnd>
        SIZE_T 
            DisposableHeapProviderImplImpl<ReversedDisposingInfoTypes, I, IEnd>::RegisterObject(
                TempPtr<typename DisposableHeapProviderImplImpl<ReversedDisposingInfoTypes, I, IEnd>::object_type> &p
            )
        {
            return base_type::RegisterObject(p);
        }

        template<class ReversedDisposingInfoTypes, class I, class IEnd>
        typename DisposableHeapProviderImplImpl<ReversedDisposingInfoTypes, I, IEnd>::object_type *
            DisposableHeapProviderImplImpl<ReversedDisposingInfoTypes, I, IEnd>::GetObject(SIZE_T n)
        {
            return base_type::GetObject(n);
        }

        template<class ReversedDisposingInfoTypes, class I, class IEnd>
        SIZE_T 
            DisposableHeapProviderImplImpl<ReversedDisposingInfoTypes, I, IEnd>::AddPersistedHandler(
                TempPtr<typename DisposableHeapProviderImplImpl<ReversedDisposingInfoTypes, I, IEnd>::object_type> &p, 
                typename DisposableHeapProviderImplImpl<ReversedDisposingInfoTypes, I, IEnd>::persisted_handler_type const &handler
            )
        {
            return base_type::AddPersistedHandler(p, handler);
        }

        template<class ReversedDisposingInfoTypes, class I, class IEnd>
        void 
            DisposableHeapProviderImplImpl<ReversedDisposingInfoTypes, I, IEnd>::Destruct(
                std::vector<typename DisposableHeapProviderImplImpl<ReversedDisposingInfoTypes, I, IEnd>::object_type *> &objects
            )
        {
            typedef std::vector<object_type *>::reverse_iterator ReverseIterator;
            for (ReverseIterator ri = objects.rbegin(), ri_end = objects.rend(); ri != ri_end; ++ri)
                DisposeCore(*ri);
        }

        template<class ReversedDisposingInfoTypes, class I, class IEnd>
        void 
            DisposableHeapProviderImplImpl<ReversedDisposingInfoTypes, I, IEnd>::DisposeCore(
                typename DisposableHeapProviderImplImpl<ReversedDisposingInfoTypes, I, IEnd>::object_type *p
            )
        {
            typedef typename mpl::or_<
                CPP_ANONYM_HAS_MEMBER_FUNCTION(DisposingInfoDispose, object_type), 
                boost::is_base_of<IDisposable, object_type> 
            >::type HasDispose;

            typedef DisposeCoreImpl<object_type, HasDispose> Impl;

            Impl::DisposeCore(p);
        }
        
        template<class DisposingInfoTypes>
        template<class T>
        inline typename DisposableHeapProviderImpl<DisposingInfoTypes>::first_provider_of<T>::type &
            DisposableHeapProviderImpl<DisposingInfoTypes>::FirstProviderOf() const
        {
            this_type *pMutableThis = const_cast<this_type *>(this);
            return static_cast<typename first_provider_of<T>::type &>(*pMutableThis);
        }

        template<class DisposingInfoTypes>
        template<class ProvidingType>
        inline typename DisposableHeapProviderImpl<DisposingInfoTypes>::provider_of<ProvidingType>::type &
            DisposableHeapProviderImpl<DisposingInfoTypes>::ProviderOf() const
        {
            this_type *pMutableThis = const_cast<this_type *>(this);
            return static_cast<typename provider_of<ProvidingType>::type &>(*pMutableThis);
        }

    }   // namespace DisposableHeapProviderDetail {

}}   // namespace Urasandesu { namespace CppAnonym {

#endif  // #ifndef URASANDESU_CPPANONYM_DISPOSABLEHEAPPROVIDER_HPP