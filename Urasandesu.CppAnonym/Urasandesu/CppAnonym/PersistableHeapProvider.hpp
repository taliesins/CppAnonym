#pragma once
#ifndef URASANDESU_CPPANONYM_PERSISTABLEHEAPPROVIDER_HPP
#define URASANDESU_CPPANONYM_PERSISTABLEHEAPPROVIDER_HPP

#ifndef URASANDESU_CPPANONYM_SIMPLEHEAPPROVIDER_HPP
#include <Urasandesu/CppAnonym/SimpleHeapProvider.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_PERSISTABLEHEAPPROVIDERFWD_HPP
#include <Urasandesu/CppAnonym/PersistableHeapProviderFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym {

    namespace Detail {

        namespace mpl = boost::mpl;
        using namespace boost;

        template<class Sequence, class I, class IEnd>
        class ATL_NO_VTABLE PersistableHeapProviderImpl : 
            SimpleHeapProvider<
                mpl::vector<
                    ObjectTag<typename mpl::deref<I>::type, QuickHeapWithoutSubscriptOperator>
                >
            >,
            public PersistableHeapProviderImpl<Sequence, typename mpl::next<I>::type, IEnd>
        {
        public:
            typedef PersistableHeapProviderImpl<Sequence, I, IEnd> this_type;
            typedef typename mpl::deref<I>::type object_type;
            typedef shared_ptr<object_type> sp_object_type;
            typedef ObjectTag<object_type, QuickHeapWithoutSubscriptOperator> obj_tag_type;
            typedef typename provider_of<obj_tag_type>::type provider_type;
            typedef std::vector<object_type *> object_ptr_vector_type;

            virtual ~PersistableHeapProviderImpl()
            {
                provider_type &provider = ProviderOf<obj_tag_type>();
                typedef object_ptr_vector_type::reverse_iterator ReverseIterator;
                for (ReverseIterator ri = Objects().rbegin(), ri_end = Objects().rend(); ri != ri_end; ++ri)
                    provider.Heap().Delete(*ri);
            }

            static sp_object_type NewStaticObject()
            {
                return sp_object_type(provider_type::StaticHeap().New(), deleter(provider_type::StaticHeap()));
            }

            sp_object_type NewObject()
            {
                provider_type &provider = ProviderOf<obj_tag_type>();
                return sp_object_type(provider.Heap().New(), deleter(provider.Heap()));
            }

            typename object_ptr_vector_type::size_type Register(sp_object_type const &p)
            {
                if (deleter *pDel = get_deleter<deleter>(p))
                {
                    pDel->DisablesDeletion();
                    Objects().push_back(p.get());
                    return Objects().size() - 1;
                }
                else
                {
                    return MAXSIZE_T;
                }
            }

            object_type *operator[](typename object_ptr_vector_type::size_type n)
            {
                return Objects()[n];
            }
        
        private:
            shared_ptr<object_ptr_vector_type> m_pObjects;

            object_ptr_vector_type &Objects()
            {
                if (!m_pObjects.get())
                    m_pObjects = make_shared<object_ptr_vector_type>();
                return *m_pObjects.get();
            }

            class deleter
            {
            public:
                deleter(typename provider_type::object_heap_type &heap) : m_pHeap(&heap) { m_disabled[0] = false; }
                void operator()(object_type *p) { if (!m_disabled[0]) m_pHeap->Delete(p); }
                void DisablesDeletion() { m_disabled[0] = true; }
            private:
                typename provider_type::object_heap_type *m_pHeap;
                bool m_disabled[1];
            };
        };

        template<class Sequence>
        class PersistableHeapProviderImpl<Sequence, 
                                             typename Traits::DistinctEnd<Sequence>::type, 
                                             typename Traits::DistinctEnd<Sequence>::type> : 
            noncopyable
        {
        };

    }   // namespace Detail


    template<class Sequence>
    class ATL_NO_VTABLE PersistableHeapProvider : 
        public Detail::PersistableHeapProviderImpl<Sequence, 
                                                  typename Traits::DistinctBegin<Sequence>::type, 
                                                  typename Traits::DistinctEnd<Sequence>::type>
    {
    public:
        typedef PersistableHeapProvider<Sequence> this_type;
        typedef Sequence sequence_type;

        template<class T>
        struct provider_of
        {
            typedef Detail::PersistableHeapProviderImpl<
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

#endif  // #ifndef URASANDESU_CPPANONYM_PERSISTABLEHEAPPROVIDER_HPP