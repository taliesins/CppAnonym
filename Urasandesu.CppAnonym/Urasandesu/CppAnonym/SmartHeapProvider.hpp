#pragma once
#ifndef URASANDESU_CPPANONYM_SMARTHEAPPROVIDER_HPP
#define URASANDESU_CPPANONYM_SMARTHEAPPROVIDER_HPP

#ifndef URASANDESU_CPPANONYM_SIMPLEHEAPPROVIDER_HPP
#include <Urasandesu/CppAnonym/SimpleHeapProvider.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_SMARTHEAPPROVIDERFWD_HPP
#include <Urasandesu/CppAnonym/SmartHeapProviderFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym {

    namespace Detail {

        namespace mpl = boost::mpl;
        using namespace boost;

        template<class Sequence, class I, class IEnd>
        class ATL_NO_VTABLE SmartHeapProviderImpl : 
            SimpleHeapProvider<
                mpl::vector<
                    ObjectTag<typename mpl::deref<I>::type, QuickHeapWithoutSubscriptOperator>
                >
            >,
            public SmartHeapProviderImpl<Sequence, typename mpl::next<I>::type, IEnd>
        {
        public:
            typedef SmartHeapProviderImpl<Sequence, I, IEnd> this_type;
            typedef typename mpl::deref<I>::type object_type;
            typedef shared_ptr<object_type> sp_object_type;
            typedef ObjectTag<object_type, QuickHeapWithoutSubscriptOperator> obj_tag_type;
            typedef typename provider_of<obj_tag_type>::type provider_type;

            static sp_object_type NewStaticObject()
            {
                return sp_object_type(provider_type::StaticHeap().New(), deleter(provider_type::StaticHeap()));
            }

            sp_object_type NewObject()
            {
                provider_type &provider = ProviderOf<obj_tag_type>();
                return sp_object_type(provider.Heap().New(), deleter(provider.Heap()));
            }

        private:
            class deleter
            {
            public:
                deleter(typename provider_type::object_heap_type &heap) : m_pHeap(&heap) {}
                void operator()(object_type *p) { m_pHeap->Delete(p); }
            private:
                typename provider_type::object_heap_type *m_pHeap;
            };
        };

        template<class Sequence>
        class SmartHeapProviderImpl<Sequence, 
                                    typename Traits::DistinctEnd<Sequence>::type, 
                                    typename Traits::DistinctEnd<Sequence>::type> : 
            noncopyable
        {
        };

    }   // namespace Detail


    template<class Sequence>
    class ATL_NO_VTABLE SmartHeapProvider : 
        public Detail::SmartHeapProviderImpl<Sequence, 
                                             typename Traits::DistinctBegin<Sequence>::type, 
                                             typename Traits::DistinctEnd<Sequence>::type>
    {
    public:
        typedef SmartHeapProvider<Sequence> this_type;
        typedef Sequence sequence_type;

        template<class T>
        struct provider_of
        {
            typedef Detail::SmartHeapProviderImpl<
                Sequence,
                typename boost::mpl::find<
                    typename Traits::Distinct<Sequence>::type,
                    T
                >::type,
                typename Traits::DistinctEnd<Sequence>::type
            > type;
        };

        template<class T>
        inline typename provider_of<T>::type &ProviderOf() const
        {
            this_type *pMutableThis = const_cast<this_type *>(this);
            return static_cast<typename provider_of<T>::type &>(*pMutableThis);
        }
    };

}}   // namespace Urasandesu { namespace CppAnonym {

#endif  // #ifndef URASANDESU_CPPANONYM_SMARTHEAPPROVIDER_HPP