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

        template<class ObjectTagSequence, class I, class IEnd>
        class ATL_NO_VTABLE SimpleHeapProviderImpl : 
            public SimpleHeapProviderImpl<ObjectTagSequence, typename mpl::next<I>::type, IEnd>
        {
        private:
            typedef SimpleHeapProviderImpl<ObjectTagSequence, I, IEnd> this_type;
            typedef typename mpl::deref<I>::type object_tag_type;
            typedef typename object_tag_type::object_type object_type;
            typedef typename object_tag_type::tag_type tag_type;

            boost::shared_ptr<SimpleHeap<object_type, tag_type>> mutable m_pFactory;
            
            inline SimpleHeap<object_type, tag_type> &Factory() const
            {
                if (!m_pFactory.get())
                    m_pFactory = boost::make_shared<SimpleHeap<object_type, tag_type>>();
                return *m_pFactory.get();
            }

        public:
            inline SIZE_T Size() const
            {
                return Factory().Size();
            }

            inline object_type *operator[] (SIZE_T ix)
            {
                return Factory()[ix];
            }

            inline object_type const *operator[] (SIZE_T ix) const
            {
                return Factory()[ix];
            }

            inline void *Alloc(SIZE_T num)
            {
                return Factory().Alloc(num);
            }

            inline void Construct(object_type *pObj)
            {
                Factory().Construct(pObj);
            }

            inline void Destroy(object_type *pObj)
            {
                Factory().Destroy(pObj);
            }

            inline void Deallocate(void *p, SIZE_T num)
            {
                Factory().Deallocate(p, num);
            }

            inline object_type *New()
            {
                return Factory().New();
            }
            
            inline object_type *Peek() const
            {
                return Size() == 0 ? NULL : Factory()[Size() - 1];
            }

            inline void DeleteLast()
            {
                object_type *pObj = Peek();
                if (pObj != NULL)
                    Factory().DeleteLast();
            }
        };

        template<class ObjectTagSequence>
        class ATL_NO_VTABLE SimpleHeapProviderImpl<ObjectTagSequence, 
                                             typename Traits::DistinctEnd<ObjectTagSequence>::type, 
                                             typename Traits::DistinctEnd<ObjectTagSequence>::type> : 
            boost::noncopyable
        {
        };

    }   // namespace Detail


    template<class ObjectTagSequence>
    class ATL_NO_VTABLE SimpleHeapProvider : 
        Detail::SimpleHeapProviderImpl<ObjectTagSequence, 
                                 typename Traits::DistinctBegin<ObjectTagSequence>::type, 
                                 typename Traits::DistinctEnd<ObjectTagSequence>::type>
    {
    public:
        typedef SimpleHeapProvider<ObjectTagSequence> this_type;

        template<class ObjectTag>
        struct type_decided_by
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
        inline typename type_decided_by<ObjectTag>::type &Of()
        {
            return static_cast<typename type_decided_by<ObjectTag>::type &>(*this);
        }

        template<class ObjectTag>
        inline typename type_decided_by<ObjectTag>::type const &Of() const
        {
            return const_cast<this_type *>(this)->Of<ObjectTag>();
        }
    };

}}   // namespace Urasandesu { namespace CppAnonym {

#endif  // #ifndef URASANDESU_CPPANONYM_SIMPLEHEAPPROVIDER_HPP