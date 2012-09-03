#pragma once
#ifndef URASANDESU_CPPANONYM_SIMPLEHEAPPROVIDER_HPP
#define URASANDESU_CPPANONYM_SIMPLEHEAPPROVIDER_HPP

#ifndef URASANDESU_CPPANONYM_TRAITS_DISTINCT_H
#include <Urasandesu/CppAnonym/Traits/Distinct.h>
#endif

#ifndef URASANDESU_CPPANONYM_SIMPLEHEAP_HPP
#include <Urasandesu/CppAnonym/SimpleHeap.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_OBJECTTAG_HPP
#include <Urasandesu/CppAnonym/ObjectTag.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_SIMPLEHEAPPROVIDERFWD_HPP
#include <Urasandesu/CppAnonym/SimpleHeapProviderFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym {

    namespace _F67D7870 {
        
        namespace mpl = boost::mpl;
        using namespace boost;

        template<class ProvidingObjectTagTypes, class I, class IEnd>
        class ATL_NO_VTABLE SimpleHeapProviderImpl : 
            public SimpleHeapProviderImpl<ProvidingObjectTagTypes, typename mpl::next<I>::type, IEnd>
        {
        public:
            typedef SimpleHeapProviderImpl<ProvidingObjectTagTypes, I, IEnd> this_type;
            typedef typename mpl::deref<I>::type object_tag_type;
            typedef typename object_tag_type::object_type object_type;
            typedef typename object_tag_type::tag_type tag_type;
            typedef SimpleHeap<object_type, tag_type> object_heap_type;

            static object_heap_type &StaticHeap()
            {
                static object_heap_type heap;
                return heap;
            }

            object_heap_type &Heap()
            {
                if (!m_pHeap.get())
                    m_pHeap = make_shared<object_heap_type>();
                return *m_pHeap.get();
            }
        
        private:
            shared_ptr<object_heap_type> m_pHeap;
        };

        template<class ProvidingObjectTagTypes>
        class ATL_NO_VTABLE SimpleHeapProviderImpl<ProvidingObjectTagTypes, 
                                                   typename Traits::DistinctEnd<ProvidingObjectTagTypes>::type, 
                                                   typename Traits::DistinctEnd<ProvidingObjectTagTypes>::type> : 
            noncopyable
        {
        };

        template<class ObjectTag, class T>
        struct HasObjectT : 
            boost::is_same<typename CPP_ANONYM_GET_MEMBER_TYPE(ObjectTag, object_type, ObjectTag)::type, T>
        {
        };

        template<class ProvidingObjectTagTypes, LONG N>
        class ProvidingTypeAtImpl
        {
            typedef typename mpl::at_c<ProvidingObjectTagTypes, N>::type providing_object_tag_type;
        public:
            typedef typename providing_object_tag_type::object_type type;
        };

        template<class ProvidingObjectTagTypes, class ProvidingType>
        class ProviderOfImpl
        {
            typedef typename Traits::Distinct<ProvidingObjectTagTypes>::type distinct_providing_object_tag_types;
            typedef typename mpl::find_if<distinct_providing_object_tag_types, HasObjectT<mpl::_1, ProvidingType> >::type i;
            typedef typename Traits::DistinctEnd<ProvidingObjectTagTypes>::type i_end;
        public:
            typedef SimpleHeapProviderImpl<ProvidingObjectTagTypes, i, i_end> type;
        };

    }   // namespace _F67D7870


    template<class ProvidingObjectTagTypes>
    class ATL_NO_VTABLE SimpleHeapProvider : 
        public _F67D7870::SimpleHeapProviderImpl<ProvidingObjectTagTypes, 
                                                 typename Traits::DistinctBegin<ProvidingObjectTagTypes>::type, 
                                                 typename Traits::DistinctEnd<ProvidingObjectTagTypes>::type>
    {
    public:
        typedef SimpleHeapProvider<ProvidingObjectTagTypes> this_type;
        typedef ProvidingObjectTagTypes providing_object_tag_types;

        template<LONG N>
        class providing_type_at : 
            public _F67D7870::ProvidingTypeAtImpl<ProvidingObjectTagTypes, N>
        {
        };

        template<class ProvidingType>
        class provider_of : 
            public _F67D7870::ProviderOfImpl<ProvidingObjectTagTypes, ProvidingType>
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

#endif  // #ifndef URASANDESU_CPPANONYM_SIMPLEHEAPPROVIDER_HPP