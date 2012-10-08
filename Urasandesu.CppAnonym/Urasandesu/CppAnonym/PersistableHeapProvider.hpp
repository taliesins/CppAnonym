#pragma once
#ifndef URASANDESU_CPPANONYM_PERSISTABLEHEAPPROVIDER_HPP
#define URASANDESU_CPPANONYM_PERSISTABLEHEAPPROVIDER_HPP

#ifndef URASANDESU_CPPANONYM_UTILITIES_TEMPPTR_HPP
#include <Urasandesu/CppAnonym/Utilities/TempPtr.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_SIMPLEHEAPPROVIDER_HPP
#include <Urasandesu/CppAnonym/SimpleHeapProvider.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_PERSISTENTINFO_HPP
#include <Urasandesu/CppAnonym/PersistentInfo.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_PERSISTABLEHEAPPROVIDERFWD_HPP
#include <Urasandesu/CppAnonym/PersistableHeapProviderFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym {

    namespace PersistableHeapProviderDetail {

        namespace mpl = boost::mpl;
        using namespace boost;
        using namespace Urasandesu::CppAnonym::Utilities;

        template<class I>
        struct PersistentInfoFacade
        {
            typedef typename mpl::deref<I>::type persistent_info_type;
            typedef typename persistent_info_type::object_type object_type;
            typedef typename persistent_info_type::persisted_handler_type persisted_handler_type;
            typedef typename TempPtr<object_type>::make_heap_holder_impl<>::object_deleter_type object_deleter_type;
            typedef typename TempPtr<object_type>::make_heap_holder_impl<>::type holder_impl_type;
            typedef typename TempPtr<object_type>::make_heap_holder_impl<>::deleter_type holder_impl_deleter_type;
            typedef typename TempPtr<object_type>::make_heap_persisted_handler_holder_impl<persisted_handler_type>::type persisted_handler_holder_impl_type;
            typedef typename TempPtr<object_type>::make_heap_persisted_handler_holder_impl<persisted_handler_type>::deleter_type persisted_handler_holder_impl_deleter_type;
            typedef ObjectTag<object_type, QuickHeapWithoutSubscriptOperator> object_object_tag_type;
            typedef ObjectTag<holder_impl_type, QuickHeapWithoutSubscriptOperator> holder_impl_object_tag_type;
            typedef ObjectTag<persisted_handler_holder_impl_type, QuickHeapWithoutSubscriptOperator> persisted_handler_holder_impl_object_tag_type;
            typedef SimpleHeapProvider<mpl::vector<object_object_tag_type, holder_impl_object_tag_type, persisted_handler_holder_impl_object_tag_type> > base_type;
            typedef typename base_type::provider_of<object_type>::type object_provider_type;
            typedef typename base_type::provider_of<holder_impl_type>::type holder_impl_provider_type;
            typedef typename base_type::provider_of<persisted_handler_holder_impl_type>::type persisted_handler_holder_impl_provider_type;
            typedef typename object_provider_type::object_heap_type object_heap_type;
            typedef typename holder_impl_provider_type::object_heap_type holder_impl_heap_type;
            typedef typename persisted_handler_holder_impl_provider_type::object_heap_type persisted_handler_holder_impl_heap_type;
        };

        template<class ReversedPersistentInfoTypes, class I, class IEnd>
        class ATL_NO_VTABLE PersistableHeapProviderImplImpl : 
            PersistentInfoFacade<I>::base_type,
            public PersistableHeapProviderImplImpl<ReversedPersistentInfoTypes, typename mpl::next<I>::type, IEnd>
        {
        public:
            typedef typename PersistentInfoFacade<I>::base_type base_type;
            typedef typename PersistentInfoFacade<I>::object_type object_type;
            typedef typename PersistentInfoFacade<I>::persisted_handler_type persisted_handler_type;
            typedef typename PersistentInfoFacade<I>::object_deleter_type object_deleter_type;
            typedef typename PersistentInfoFacade<I>::holder_impl_type holder_impl_type;
            typedef typename PersistentInfoFacade<I>::holder_impl_deleter_type holder_impl_deleter_type;
            typedef typename PersistentInfoFacade<I>::persisted_handler_holder_impl_type persisted_handler_holder_impl_type;
            typedef typename PersistentInfoFacade<I>::persisted_handler_holder_impl_deleter_type persisted_handler_holder_impl_deleter_type;            
            typedef typename PersistentInfoFacade<I>::object_provider_type object_provider_type;
            typedef typename PersistentInfoFacade<I>::holder_impl_provider_type holder_impl_provider_type;
            typedef typename PersistentInfoFacade<I>::persisted_handler_holder_impl_provider_type persisted_handler_holder_impl_provider_type;
            typedef typename PersistentInfoFacade<I>::object_heap_type object_heap_type;
            typedef typename PersistentInfoFacade<I>::holder_impl_heap_type holder_impl_heap_type;
            typedef typename PersistentInfoFacade<I>::persisted_handler_holder_impl_heap_type persisted_handler_holder_impl_heap_type;

            ~PersistableHeapProviderImplImpl()
            {
                if (AnyObjects())
                    Destruct(ObjectHeap(), Objects());
            }

            TempPtr<object_type> NewObject()
            {
                object_deleter_type objDeleter(ObjectHeap());
                object_type *pObj = ObjectHeap().New();

                holder_impl_deleter_type implDeleter(HolderImplHeap());
                holder_impl_type *pHolderImpl = HolderImplHeap().New(pObj, objDeleter, implDeleter);

                return TempPtr<object_type>(pHolderImpl);
            }

            TempPtr<object_type> WrapRegisteredObject(object_type *pObj)
            {
#if _DEBUG
                if (AnyObjects())
                {
                    typedef std::vector<object_type *>::iterator Iterator;
                    Iterator result = std::find(Objects().begin(), Objects().end(), pObj);
                    _ASSERTE(result != Objects().end());
                }
#endif
                holder_impl_deleter_type implDeleter(HolderImplHeap());
                holder_impl_type *pHolderImpl = HolderImplHeap().New(pObj, objDeleter, implDeleter);

                TempPtr<object_type> p(pHolderImpl);
                p.Persist();
                return p;
            }

            size_t RegisterObject(TempPtr<object_type> &p)
            {
                p.Persist();
                Objects().push_back(p.Get());
                return Objects().size() - 1;
            }

            object_type *GetObject(size_t n)
            {
                return Objects()[n];
            }

            size_t AddPersistedHandler(TempPtr<object_type> &p, persisted_handler_type const &handler)
            {
                persisted_handler_holder_impl_deleter_type implDeleter(PersistedHandlerImplHeap());
                persisted_handler_holder_impl_type *pHandlerImpl = PersistedHandlerImplHeap().New(handler, implDeleter);

                return p.AddPersistedHandler(pHandlerImpl);
            }

        protected:
            std::vector<object_type *> &Objects()
            {
                if (!m_pObjects)
                    m_pObjects = make_shared<std::vector<object_type *> >();
                return *m_pObjects.get();
            }

            bool AnyObjects() const
            {
                return m_pObjects && !m_pObjects->empty();
            }

        private:            
            static void Destruct(object_heap_type &heap, std::vector<object_type *> &objects)
            {
                typedef std::vector<object_type *>::reverse_iterator ReverseIterator;
                for (ReverseIterator ri = objects.rbegin(), ri_end = objects.rend(); ri != ri_end; ++ri)
                    heap.Delete(*ri);
            }

            object_heap_type &ObjectHeap()
            {
                object_provider_type &provider = base_type::ProviderOf<object_type>();
                return provider.Heap();
            }

            holder_impl_heap_type &HolderImplHeap()
            {
                holder_impl_provider_type &provider = base_type::ProviderOf<holder_impl_type>();
                return provider.Heap();
            }

            persisted_handler_holder_impl_heap_type &PersistedHandlerImplHeap()
            {
                persisted_handler_holder_impl_provider_type &provider = base_type::ProviderOf<persisted_handler_holder_impl_type>();
                return provider.Heap();
            }

            shared_ptr<std::vector<object_type *> > m_pObjects;
        };

        template<class ReversedPersistentInfoTypes>
        class PersistableHeapProviderImplImpl<ReversedPersistentInfoTypes, 
                                              typename mpl::end<ReversedPersistentInfoTypes>::type, 
                                              typename mpl::end<ReversedPersistentInfoTypes>::type> : 
            noncopyable
        {
        };

        template<class PersistentInfo, class T>
        struct HasObjectT : 
            boost::is_same<typename CPP_ANONYM_GET_MEMBER_TYPE(PersistentInfoObject, PersistentInfo)::type, T>
        {
        };

        template<class PersistentInfoTypes, LONG N>
        class ProvidingTypeAtImpl
        {
            typedef typename mpl::at_c<PersistentInfoTypes, N>::type persistent_info_type;
        public:
            typedef typename persistent_info_type::object_type type;
        };

        template<class PersistentInfoTypes, LONG N>
        class ProvidingHandlerTypeAtImpl
        {
            typedef typename mpl::at_c<PersistentInfoTypes, N>::type persistent_info_type;
        public:
            typedef typename persistent_info_type::persisted_handler_type type;
        };

        template<class ReversedPersistentInfoTypes, class ProvidingType>
        class ProviderOfImpl
        {
            typedef typename mpl::find_if<ReversedPersistentInfoTypes, HasObjectT<mpl::_1, ProvidingType> >::type i;
            typedef typename mpl::end<ReversedPersistentInfoTypes>::type i_end;
        public:
            typedef PersistableHeapProviderImplImpl<ReversedPersistentInfoTypes, i, i_end> type;
        };

        template<class PersistentInfoTypes>
        struct ATL_NO_VTABLE PersistableHeapProviderImpl : 
            PersistableHeapProviderImplImpl<typename mpl::reverse<PersistentInfoTypes>::type, 
                                            typename mpl::begin<typename mpl::reverse<PersistentInfoTypes>::type>::type, 
                                            typename mpl::end<typename mpl::reverse<PersistentInfoTypes>::type>::type>
        {
            typedef PersistableHeapProviderImpl<PersistentInfoTypes> this_type;
            typedef PersistentInfoTypes persistent_info_types;

            template<LONG N>
            struct persistent_info_at : 
                mpl::at_c<persistent_info_types, N>
            {
            };

            template<LONG N>
            struct providing_type_at : 
                ProvidingTypeAtImpl<persistent_info_types, N>
            {
            };

            template<LONG N>
            struct providing_handler_type_at : 
                ProvidingHandlerTypeAtImpl<persistent_info_types, N>
            {
            };

            template<class ProvidingType>
            struct provider_of : 
                ProviderOfImpl<typename mpl::reverse<persistent_info_types>::type, ProvidingType>
            {
            };

            template<class ProvidingType>
            inline typename provider_of<ProvidingType>::type &ProviderOf() const
            {
                this_type *pMutableThis = const_cast<this_type *>(this);
                return static_cast<typename provider_of<ProvidingType>::type &>(*pMutableThis);
            }
        };

    }   // namespace PersistableHeapProviderDetail {

    template<class PersistentInfoTypes>
    struct ATL_NO_VTABLE PersistableHeapProvider : 
        PersistableHeapProviderDetail::PersistableHeapProviderImpl<PersistentInfoTypes>
    {
    };

}}   // namespace Urasandesu { namespace CppAnonym {

#endif  // #ifndef URASANDESU_CPPANONYM_PERSISTABLEHEAPPROVIDER_HPP