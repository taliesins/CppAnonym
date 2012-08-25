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

    namespace Detail {
        
        namespace mpl = boost::mpl;
        using namespace boost;

        template<class ObjectTagSequence, class I, class IEnd>
        class ATL_NO_VTABLE SimpleHeapProviderImpl : 
            public SimpleHeapProviderImpl<ObjectTagSequence, typename mpl::next<I>::type, IEnd>
        {
        public:
            typedef SimpleHeapProviderImpl<ObjectTagSequence, I, IEnd> this_type;
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

        template<class ObjectTagSequence>
        class ATL_NO_VTABLE SimpleHeapProviderImpl<ObjectTagSequence, 
                                             typename Traits::DistinctEnd<ObjectTagSequence>::type, 
                                             typename Traits::DistinctEnd<ObjectTagSequence>::type> : 
            noncopyable
        {
        };

    }   // namespace Detail


    template<class ObjectTagSequence>
    class ATL_NO_VTABLE SimpleHeapProvider : 
        public Detail::SimpleHeapProviderImpl<ObjectTagSequence, 
                                 typename Traits::DistinctBegin<ObjectTagSequence>::type, 
                                 typename Traits::DistinctEnd<ObjectTagSequence>::type>
    {
    public:
        typedef SimpleHeapProvider<ObjectTagSequence> this_type;

        template<class ObjectTag>
        struct provider_of
        {
            typedef Detail::SimpleHeapProviderImpl<
                ObjectTagSequence,
                typename boost::mpl::find<
                    typename Traits::Distinct<ObjectTagSequence>::type,
                    ObjectTag
                >::type,
                typename Traits::DistinctEnd<ObjectTagSequence>::type
            > type;
        };

        template<class ObjectTag>
        inline typename provider_of<ObjectTag>::type &ProviderOf() const
        {
            this_type *pMutableThis = const_cast<this_type *>(this);
            return static_cast<typename provider_of<ObjectTag>::type &>(*pMutableThis);
        }
    };

}}   // namespace Urasandesu { namespace CppAnonym {

#endif  // #ifndef URASANDESU_CPPANONYM_SIMPLEHEAPPROVIDER_HPP