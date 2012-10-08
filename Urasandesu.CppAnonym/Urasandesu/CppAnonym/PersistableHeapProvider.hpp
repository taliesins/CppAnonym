#pragma once
#ifndef URASANDESU_CPPANONYM_PERSISTABLEHEAPPROVIDER_HPP
#define URASANDESU_CPPANONYM_PERSISTABLEHEAPPROVIDER_HPP

#ifndef URASANDESU_CPPANONYM_SIMPLEHEAPPROVIDER_HPP
#include <Urasandesu/CppAnonym/SimpleHeapProvider.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_HEAPDELETER_HPP
#include <Urasandesu/CppAnonym/Utilities/HeapDeleter.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_AUTO_PTR_HPP
#include <Urasandesu/CppAnonym/Utilities/AutoPtr.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_PERSISTABLEHEAPPROVIDERFWD_HPP
#include <Urasandesu/CppAnonym/PersistableHeapProviderFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym {

    namespace _BB53EDCD {

        namespace mpl = boost::mpl;
        using namespace boost;
        using namespace Urasandesu::CppAnonym::Utilities;

        template<class ProvidingTypes, class I, class IEnd>
        class ATL_NO_VTABLE PersistableHeapProviderImpl : 
            SimpleHeapProvider<
                mpl::vector<
                    ObjectTag<typename mpl::deref<I>::type, QuickHeapWithoutSubscriptOperator>
                >
            >,
            public PersistableHeapProviderImpl<ProvidingTypes, typename mpl::next<I>::type, IEnd>
        {
        public:
            typedef PersistableHeapProviderImpl<ProvidingTypes, I, IEnd> this_type;
            typedef typename mpl::deref<I>::type object_type;
            typedef ObjectTag<object_type, QuickHeapWithoutSubscriptOperator> obj_tag_type;
            typedef SimpleHeapProvider<mpl::vector<obj_tag_type> > base_type;
            
            typedef base_type::object_heap_type object_heap_type;
            typedef HeapDeleter<object_heap_type> object_heap_deleter_type;

            static void Destruct(object_heap_type &heap, std::vector<object_type *> &objects)
            {
                typedef std::vector<object_type *>::reverse_iterator ReverseIterator;
                for (ReverseIterator ri = objects.rbegin(), ri_end = objects.rend(); ri != ri_end; ++ri)
                    heap.Delete(*ri);
            }

            ~PersistableHeapProviderImpl()
            {
                Destruct(base_type::Heap(), Objects());
            }

            static TempPtr<object_type> NewStaticObject()
            {
                return TempPtr<object_type>(StaticHeap().New(), object_heap_deleter_type(StaticHeap()));
            }

            static size_t RegisterStaticObject(TempPtr<object_type> &p)
            {
                p.Persist();
                StaticObjects().push_back(p.Get());
                return StaticObjects().size() - 1;
            }

            static object_type *GetStaticObject(size_t n)
            {
                return StaticObjects()[n];
            }

            TempPtr<object_type> NewObject()
            {
                return TempPtr<object_type>(base_type::Heap().New(), object_heap_deleter_type(base_type::Heap()));
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

        protected:
            struct heap_and_objects
            {
                virtual ~heap_and_objects()
                {
                    this_type::Destruct(m_heap, m_objects);
                }

                object_heap_type m_heap;
                std::vector<object_type *> m_objects;
            };

            std::vector<object_type *> &Objects()
            {
                if (!m_pObjects.get())
                    m_pObjects = make_shared<std::vector<object_type *>>();
                return *m_pObjects.get();
            }

        private:
            static heap_and_objects &StaticHeapAndObjects()
            {
                static heap_and_objects heapAndObjects;
                return heapAndObjects;
            }

            static object_heap_type &StaticHeap()
            {
                return StaticHeapAndObjects().m_heap;
            }

            static std::vector<object_type *> &StaticObjects()
            {
                return StaticHeapAndObjects().m_objects;
            }

            shared_ptr<std::vector<object_type *>> m_pObjects;
        };

        template<class ProvidingTypes>
        class PersistableHeapProviderImpl<ProvidingTypes, 
                                          typename Traits::DistinctEnd<ProvidingTypes>::type, 
                                          typename Traits::DistinctEnd<ProvidingTypes>::type> : 
            noncopyable
        {
        };

        template<class ProvidingTypes, class ProvidingType>
        class ProviderOfImpl
        {
            typedef typename Traits::Distinct<ProvidingTypes>::type distinct_providing_types;
            typedef typename mpl::find<distinct_providing_types, ProvidingType>::type i;
            typedef typename Traits::DistinctEnd<ProvidingTypes>::type i_end;
        public:
            typedef PersistableHeapProviderImpl<ProvidingTypes, i, i_end> type;
        };

    }   // namespace _BB53EDCD


    template<class ProvidingTypes>
    class ATL_NO_VTABLE PersistableHeapProvider : 
        public _BB53EDCD::PersistableHeapProviderImpl<ProvidingTypes, 
                                                      typename Traits::DistinctBegin<ProvidingTypes>::type, 
                                                      typename Traits::DistinctEnd<ProvidingTypes>::type>
    {
    public:
        typedef PersistableHeapProvider<ProvidingTypes> this_type;
        typedef ProvidingTypes providing_types;

        template<LONG N>
        struct providing_type_at : 
            boost::mpl::at_c<providing_types, N>
        {
        };

        template<class ProvidingType>
        class provider_of : 
            public _BB53EDCD::ProviderOfImpl<providing_types, ProvidingType>
        {
        };

        template<class ProvidingType>
        inline typename provider_of<ProvidingType>::type &ProviderOf() const
        {
            this_type *pMutableThis = const_cast<this_type *>(this);
            return static_cast<typename provider_of<ProvidingType>::type &>(*pMutableThis);
        }
    };

}}   // namespace Urasandesu { namespace CppAnonym {

#endif  // #ifndef URASANDESU_CPPANONYM_PERSISTABLEHEAPPROVIDER_HPP