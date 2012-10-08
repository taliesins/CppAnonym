﻿#pragma once
#ifndef URASANDESU_CPPANONYM_DISPOSABLEHEAPPROVIDER_HPP
#define URASANDESU_CPPANONYM_DISPOSABLEHEAPPROVIDER_HPP

#ifndef URASANDESU_CPPANONYM_PERSISTABLEHEAPPROVIDER_HPP
#include <Urasandesu/CppAnonym/PersistableHeapProvider.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_DISPOSABLEHEAPPROVIDERFWD_HPP
#include <Urasandesu/CppAnonym/DisposableHeapProviderFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym {

    namespace Detail {

        namespace mpl = boost::mpl;
        using namespace boost;

        template<class ProvidingTypes, class I, class IEnd>
        class ATL_NO_VTABLE DisposableHeapProviderImpl : 
            PersistableHeapProvider<
                mpl::vector<
                    typename mpl::deref<I>::type
                >
            >,
            public DisposableHeapProviderImpl<ProvidingTypes, typename mpl::next<I>::type, IEnd>
        {
        public:
            typedef DisposableHeapProviderImpl<ProvidingTypes, I, IEnd> this_type;
            typedef typename mpl::deref<I>::type object_type;
            typedef PersistableHeapProvider<mpl::vector<object_type> > base_type;

            typedef base_type::object_heap_type object_heap_type;
            typedef base_type::object_heap_deleter_type object_heap_deleter_type;
            typedef base_type::object_ptr_type object_ptr_type;
            typedef base_type::object_const_ptr_type object_const_ptr_type;
            typedef base_type::object_ptr_vector_type object_ptr_vector_type;
            typedef typename base_type::size_type size_type;
            
            typedef base_type::static_object_temp_ptr_type static_object_temp_ptr_type;

            typedef base_type::object_temp_ptr_type object_temp_ptr_type;

            static void Destruct(object_ptr_vector_type &objects)
            {
                typedef object_ptr_vector_type::reverse_iterator ReverseIterator;
                for (ReverseIterator ri = objects.rbegin(), ri_end = objects.rend(); ri != ri_end; ++ri)
                    (*ri)->Dispose();
            }

            ~DisposableHeapProviderImpl()
            {
                Destruct(base_type::Objects());
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
                return base_type::NewObject();
            }

            size_type RegisterObject(object_temp_ptr_type const &p)
            {
                return base_type::RegisterObject(p);
            }

            object_ptr_type GetObject(size_type n)
            {
                return base_type::GetObject(n);
            }
        
        protected:
            struct heap_and_objects : 
                base_type::heap_and_objects
            {
                virtual ~heap_and_objects()
                {
                    this_type::Destruct(base_type::heap_and_objects::m_objects);
                }
            };

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
        };

        template<class ProvidingTypes>
        class DisposableHeapProviderImpl<ProvidingTypes, 
                                             typename Traits::DistinctEnd<ProvidingTypes>::type, 
                                             typename Traits::DistinctEnd<ProvidingTypes>::type> : 
            noncopyable
        {
        };

    }   // namespace Detail


    template<class ProvidingTypes>
    class ATL_NO_VTABLE DisposableHeapProvider : 
        public Detail::DisposableHeapProviderImpl<ProvidingTypes, 
                                                  typename Traits::DistinctBegin<ProvidingTypes>::type, 
                                                  typename Traits::DistinctEnd<ProvidingTypes>::type>
    {
    public:
        typedef DisposableHeapProvider<ProvidingTypes> this_type;
        typedef ProvidingTypes providing_types;

        template<LONG N>
        struct providing_type_at : 
            boost::mpl::at_c<providing_types, N>
        {
        };

        template<class T>
        class provider_of
        {
            typedef typename Traits::Distinct<providing_types>::type distinct_providing_types;
            typedef typename boost::mpl::find<distinct_providing_types, T>::type i;
            typedef typename Traits::DistinctEnd<providing_types>::type i_end;
        public:
            typedef Detail::DisposableHeapProviderImpl<providing_types, i, i_end> type;
        };

        template<class T>
        inline typename provider_of<T>::type &ProviderOf() const
        {
            this_type *pMutableThis = const_cast<this_type *>(this);
            return static_cast<typename provider_of<T>::type &>(*pMutableThis);
        }
    };

}}   // namespace Urasandesu { namespace CppAnonym {

#endif  // #ifndef URASANDESU_CPPANONYM_DISPOSABLEHEAPPROVIDER_HPP