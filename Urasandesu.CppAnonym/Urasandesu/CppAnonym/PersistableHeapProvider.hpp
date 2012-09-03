#pragma once
#ifndef URASANDESU_CPPANONYM_PERSISTABLEHEAPPROVIDER_HPP
#define URASANDESU_CPPANONYM_PERSISTABLEHEAPPROVIDER_HPP

#ifndef URASANDESU_CPPANONYM_SIMPLEHEAPPROVIDER_HPP
#include <Urasandesu/CppAnonym/SimpleHeapProvider.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_HEAPDELETER_HPP
#include <Urasandesu/CppAnonym/Utilities/HeapDeleter.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_TEMPORARYPOINTER_HPP
#include <Urasandesu/CppAnonym/Utilities/TemporaryPointer.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_PERSISTABLEHEAPPROVIDERFWD_HPP
#include <Urasandesu/CppAnonym/PersistableHeapProviderFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym {

    namespace _BB53EDCD {

        namespace mpl = boost::mpl;
        using namespace boost;

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
            typedef Utilities::HeapDeleter<object_heap_type> object_heap_deleter_type;
            typedef object_type *object_ptr_type;
            typedef object_type const *object_const_ptr_type;
            typedef std::vector<object_ptr_type> object_ptr_vector_type;
            typedef typename object_ptr_vector_type::size_type size_type;
            
            struct static_temp_object_ptr_tag;
            typedef Utilities::PersistableTemporaryPointer<object_type, static_temp_object_ptr_tag> static_object_temp_ptr_type;

            struct temp_object_ptr_tag;
            typedef Utilities::PersistableTemporaryPointer<object_type, temp_object_ptr_tag> object_temp_ptr_type;

            static void Destruct(object_heap_type &heap, object_ptr_vector_type &objects)
            {
                typedef object_ptr_vector_type::reverse_iterator ReverseIterator;
                for (ReverseIterator ri = objects.rbegin(), ri_end = objects.rend(); ri != ri_end; ++ri)
                    heap.Delete(*ri);
            }

            ~PersistableHeapProviderImpl()
            {
                Destruct(base_type::Heap(), Objects());
            }

            static static_object_temp_ptr_type NewStaticObject()
            {
                return static_object_temp_ptr_type(StaticHeap().New(), object_heap_deleter_type(StaticHeap()));
            }

            static size_type RegisterStaticObject(static_object_temp_ptr_type const &p)
            {
                p.Persist();
                StaticObjects().push_back(p.Get());
                return StaticObjects().size() - 1;
            }

            static object_ptr_type GetStaticObject(size_type n)
            {
                return StaticObjects()[n];
            }

            object_temp_ptr_type NewObject()
            {
                return object_temp_ptr_type(base_type::Heap().New(), object_heap_deleter_type(base_type::Heap()));
            }

            size_type RegisterObject(object_temp_ptr_type const &p)
            {
                p.Persist();
                Objects().push_back(p.Get());
                return Objects().size() - 1;
            }

            object_ptr_type GetObject(size_type n)
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
                object_ptr_vector_type m_objects;
            };

            object_ptr_vector_type &Objects()
            {
                if (!m_pObjects.get())
                    m_pObjects = make_shared<object_ptr_vector_type>();
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

            static object_ptr_vector_type &StaticObjects()
            {
                return StaticHeapAndObjects().m_objects;
            }

            shared_ptr<object_ptr_vector_type> m_pObjects;
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