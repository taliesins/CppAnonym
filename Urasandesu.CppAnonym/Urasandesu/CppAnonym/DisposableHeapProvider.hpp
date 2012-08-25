#pragma once
#ifndef URASANDESU_CPPANONYM_DISPOSABLEHEAPPROVIDER_HPP
#define URASANDESU_CPPANONYM_DISPOSABLEHEAPPROVIDER_HPP

#ifndef URASANDESU_CPPANONYM_SMARTHEAPPROVIDER_HPP
#include <Urasandesu/CppAnonym/SmartHeapProvider.hpp>
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
            SmartHeapProvider<
                mpl::vector<
                    typename mpl::deref<I>::type
                >
            >,
            public DisposableHeapProviderImpl<Sequence, typename mpl::next<I>::type, IEnd>
        {
        public:
            typedef DisposableHeapProviderImpl<Sequence, I, IEnd> this_type;
            typedef typename mpl::deref<I>::type object_type;
            typedef typename provider_of<object_type>::type provider_type;
            typedef std::vector<typename provider_type::sp_object_type> sp_object_vector_type;

            virtual ~DisposableHeapProviderImpl()
            {
                typedef sp_object_vector_type::reverse_iterator ReverseIterator;
                for (ReverseIterator ri = Objects().rbegin(), ri_end = Objects().rend(); ri != ri_end; ++ri)
                    (*ri)->Dispose();
            }

            static typename provider_type::sp_object_type NewStaticObject()
            {
                return provider_type::NewStaticObject();
            }

            typename provider_type::sp_object_type NewObject()
            {
                return ProviderOf<object_type>().NewObject();
            }

            typename sp_object_vector_type::size_type Register(typename provider_type::sp_object_type const &p)
            {
                Objects().push_back(p);
                return Objects().size() - 1;
            }

            typename provider_type::sp_object_type operator[](typename sp_object_vector_type::size_type n)
            {
                return Objects()[n];
            }
        
        private:
            shared_ptr<sp_object_vector_type> m_pObjects;

            sp_object_vector_type &Objects()
            {
                if (!m_pObjects.get())
                    m_pObjects = make_shared<sp_object_vector_type>();
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