#pragma once
#ifndef URASANDESU_CPPANONYM_DISPOSABLEHEAPPROVIDER_HPP
#define URASANDESU_CPPANONYM_DISPOSABLEHEAPPROVIDER_HPP

#ifndef URASANDESU_CPPANONYM_SIMPLEHEAPPROVIDER_HPP
#include <Urasandesu/CppAnonym/SimpleHeapProvider.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_DISPOSABLEHEAPPROVIDERFWD_HPP
#include <Urasandesu/CppAnonym/DisposableHeapProviderFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym {

    namespace Detail {

        namespace mpl = boost::mpl;
        using namespace boost;

        template<class Sequence, class I, class IEnd>
        class ATL_NO_VTABLE DisposableHeapProviderImpl : 
            SimpleHeapProvider<
                mpl::vector<
                    ObjectTag<typename mpl::deref<I>::type, QuickHeapWithoutSubscriptOperator>
                >
            >,
            public DisposableHeapProviderImpl<Sequence, typename mpl::next<I>::type, IEnd>
        {
        public:
            typedef DisposableHeapProviderImpl<Sequence, I, IEnd> this_type;
            typedef typename mpl::deref<I>::type object_type;
            typedef ObjectTag<object_type, QuickHeapWithoutSubscriptOperator> obj_tag_type;
            typedef typename provider_of<obj_tag_type>::type provider_type;
            typedef std::vector<object_type *> object_ptr_vector_type;

            virtual ~DisposableHeapProviderImpl()
            {
                typedef object_ptr_vector_type::reverse_iterator ReverseIterator;
                for (ReverseIterator ri = Objects().rbegin(), ri_end = Objects().rend(); ri != ri_end; ++ri)
                    (*ri)->Dispose();
            }

            static object_type *NewStaticObject()
            {
                return provider_type::StaticHeap().New();
            }

            object_type *NewObject()
            {
                provider_type &provider = ProviderOf<obj_tag_type>();
                return provider.Heap().New();
            }

            typename object_ptr_vector_type::size_type Register(object_type &p)
            {
                Objects().push_back(&p);
                return Objects().size() - 1;
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
        };

        template<class Sequence>
        class DisposableHeapProviderImpl<Sequence, 
                                             typename Traits::DistinctEnd<Sequence>::type, 
                                             typename Traits::DistinctEnd<Sequence>::type> : 
            noncopyable
        {
        };

    }   // namespace Detail


    template<class Sequence>
    class ATL_NO_VTABLE DisposableHeapProvider : 
        public Detail::DisposableHeapProviderImpl<Sequence, 
                                                  typename Traits::DistinctBegin<Sequence>::type, 
                                                  typename Traits::DistinctEnd<Sequence>::type>
    {
    public:
        typedef DisposableHeapProvider<Sequence> this_type;
        typedef Sequence sequence_type;

        template<class T>
        struct provider_of
        {
            typedef Detail::DisposableHeapProviderImpl<
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

#endif  // #ifndef URASANDESU_CPPANONYM_DISPOSABLEHEAPPROVIDER_HPP