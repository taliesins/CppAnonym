#pragma once
#ifndef URASANDESU_CPPANONYM_SMARTPTRCHAIN_HPP
#define URASANDESU_CPPANONYM_SMARTPTRCHAIN_HPP

#ifndef URASANDESU_CPPANONYM_SMARTPTRCHAINFWD_HPP
#include <Urasandesu/CppAnonym/SmartPtrChainFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym {

    namespace Detail {
        
        namespace mpl = boost::mpl;
        using namespace boost;

        template<class Current, class ChainInfoSequence, class I, class IEnd>
        class ATL_NO_VTABLE SmartPtrChainImpl : 
            public SmartPtrChainImpl<Current, ChainInfoSequence, typename mpl::next<I>::type, IEnd>
        {
        public:
            typedef SmartPtrChainImpl<Current, ChainInfoSequence, I, IEnd> this_type;
            typedef typename mpl::deref<I>::type chain_info_type;
            typedef typename Current current_type;
            typedef typename chain_info_type::previous_type previous_type;
            typedef typename chain_info_type::mapper_type mapper_type;
            typedef typename chain_info_type::constructor_type constructor_type;

            SmartPtrChainImpl() : 
                m_pPrevious(NULL)
            { }

            template<class T>
            boost::shared_ptr<T> MapFirstAncestor() const
            {
                return mapper_type::MapFirstAncestor<T, previous_type>(static_cast<current_type const &>(*this)); 
            }

            template<class T>
            boost::shared_ptr<T> MapFirst() const
            {
                return mapper_type::MapFirstAncestor<T, previous_type>(static_cast<current_type const &>(*this)); 
            }

            template<>
            boost::shared_ptr<current_type> MapFirst<current_type>() const
            { 
                return mapper_type::MapFirst<current_type>(static_cast<current_type const &>(*this));
            }

            template<class T>
            boost::shared_ptr<T> Map() const
            {
                return mapper_type::MapAncestor<T, previous_type>(static_cast<current_type const &>(*this)); 
            }

            template<>
            boost::shared_ptr<current_type> Map<current_type>() const
            { 
                return mapper_type::Map<current_type>(static_cast<current_type const &>(*this));
            }

            template<
                class T,
                class HeapProvider
            >
            static T *NewRootObject()
            {
                return constructor_type::NewRootObject<T, HeapProvider>();
            }

            template<
                class T,
                class HeapProvider
            >
            T *NewObject(HeapProvider &provider) const
            {
                return constructor_type::NewObject<T>(static_cast<current_type &>(*const_cast<this_type *>(this)), provider);
            }
            
            previous_type *GetPrevious() const
            {
                return m_pPrevious;
            }

            void SetPrevious(previous_type &previous)
            {
                _ASSERTE(m_pPrevious == NULL);
                m_pPrevious = &previous;
            }

        private:
            previous_type *m_pPrevious;
        };

        template<class Current, class ChainInfoSequence>
        class ATL_NO_VTABLE SmartPtrChainImpl<Current, 
                                              ChainInfoSequence, 
                                              typename Traits::DistinctEnd<ChainInfoSequence>::type, 
                                              typename Traits::DistinctEnd<ChainInfoSequence>::type> : 
            noncopyable
        {
        //public:
        //    typedef typename Current current_type;
        //    
        //    boost::weak_ptr<current_type> GetCurrent() const
        //    {
        //        return m_pCurrent;
        //    }

        //    void SetCurrent(boost::weak_ptr<current_type> const &pCurrent)
        //    {
        //        _ASSERTE(m_pCurrent.expired());
        //        m_pCurrent = pCurrent;
        //    }

        //private:
        //    boost::weak_ptr<current_type> m_pCurrent;
        };

        template<class Current>
        struct ExtractPreviousOrDefault : 
            mpl::eval_if<
                CPP_ANONYM_HAS_MEMBER_TYPE(ChainInfo, previous_type, Current),
                CPP_ANONYM_GET_MEMBER_TYPE(ChainInfo, previous_type, Current),
                mpl::identity<Current> >
        {
        };

        template<class Last, class T>
        struct ExtractChainInfoSequenceOrDefault : 
            mpl::eval_if<
                mpl::and_<
                    CPP_ANONYM_HAS_MEMBER_TYPE(SmartPtrChain, chain_info_sequence_type, T),
                    mpl::not_<boost::is_same<Last, T> >
                >,
                CPP_ANONYM_GET_MEMBER_TYPE(SmartPtrChain, chain_info_sequence_type, T),
                mpl::identity<mpl::vector<T> > >
        {
        };

        template<class Last, class Current>
        class FlattenChainInfoImpl
        {
            typedef typename ExtractPreviousOrDefault<Current>::type previous_type;
            typedef typename ExtractChainInfoSequenceOrDefault<Last, previous_type>::type chain_info_sequence_type;

        public:
            typedef typename mpl::eval_if<
                                boost::is_same<chain_info_sequence_type, mpl::vector<previous_type> >, 
                                chain_info_sequence_type,
                                mpl::fold<
                                    chain_info_sequence_type, 
                                    mpl::vector<previous_type>,
                                    mpl::copy<
                                        FlattenChainInfoImpl<previous_type, mpl::_2>, 
                                        mpl::back_inserter<mpl::_1> > > >::type type; 
        };

        template<class T>
        struct FlattenChainInfo : 
            FlattenChainInfoImpl<mpl::void_, T>
        {
        };

        template<class Current, class T>
        class IsMappable
        {
        private:
            typedef Current current;
            typedef typename FlattenChainInfo<current>::type all_mappable_types;
            typedef typename mpl::find<all_mappable_types, T>::type i;
            typedef typename mpl::end<all_mappable_types>::type i_end;

        public:
            typedef typename mpl::not_<boost::is_same<i, i_end> > type;
        };

    }   // namespace Detail


    template<class Current, class ChainInfoSequence>
    class ATL_NO_VTABLE SmartPtrChain : 
        public Detail::SmartPtrChainImpl<Current, 
                                         ChainInfoSequence, 
                                         typename Traits::DistinctBegin<ChainInfoSequence>::type, 
                                         typename Traits::DistinctEnd<ChainInfoSequence>::type>
    {
    public:
        typedef SmartPtrChain<Current, ChainInfoSequence> this_type;
        typedef ChainInfoSequence chain_info_sequence_type;

        template<class Previous>
        struct chain_from
        {
            typedef Detail::SmartPtrChainImpl<
                Current,
                chain_info_sequence_type,
                typename boost::mpl::find_if<
                    typename Traits::Distinct<chain_info_sequence_type>::type,
                    boost::is_same<Detail::CPP_ANONYM_GET_MEMBER_TYPE(ChainInfo, previous_type, boost::mpl::_1), Previous>
                >::type,
                typename Traits::DistinctEnd<chain_info_sequence_type>::type
            > type;
        };

        template<class Previous>
        inline typename chain_from<Previous>::type &ChainFrom() const
        {
            this_type *pMutableThis = const_cast<this_type *>(this);
            return static_cast<typename chain_from<Previous>::type &>(*pMutableThis);
        }

        template<class T>
        boost::shared_ptr<T> MapFirstAncestor() const
        {
            namespace mpl = boost::mpl;

            typedef mpl::filter_view<chain_info_sequence_type, Detail::IsMappable<mpl::_, T> >::type MappableTypes;
            
            container<T> container;
            map_first_ancestor_selector<T> selector(*this, container);
            mpl::for_each<MappableTypes, wrap<Detail::CPP_ANONYM_GET_MEMBER_TYPE(ChainInfo, previous_type, mpl::_) > >(selector);
            return container.m_p;
        }

        template<class T>
        boost::shared_ptr<T> MapFirst() const
        {
            namespace mpl = boost::mpl;

            typedef mpl::filter_view<chain_info_sequence_type, Detail::IsMappable<mpl::_, T> >::type MappableTypes;
            
            container<T> container;
            map_first_selector<T> selector(*this, container);
            mpl::for_each<MappableTypes, wrap<Detail::CPP_ANONYM_GET_MEMBER_TYPE(ChainInfo, previous_type, mpl::_) > >(selector);
            return container.m_p;
        }

        template<>
        boost::shared_ptr<Current> MapFirst<Current>() const
        {
            return Map<Current>();
        }

        template<
            class T,
            class HeapProvider
        >
        boost::shared_ptr<T> NewObjectFirst(HeapProvider &provider) const
        {
            namespace mpl = boost::mpl;

            container<T> container;
            new_object_first_selector<T, HeapProvider> selector(*this, provider, container);
            mpl::for_each<chain_info_sequence_type, wrap<Detail::CPP_ANONYM_GET_MEMBER_TYPE(ChainInfo, previous_type, mpl::_) > >(selector);
            _ASSERTE(container.m_p);
            return container.m_p;
        }

    private:
        template<class T>
        struct wrap
        {
        };

        template<class T>
        struct container
        {
            boost::shared_ptr<T> m_p;
        };

        template<class T>
        struct map_first_ancestor_selector
        {
            map_first_ancestor_selector(this_type const &this_, container<T> &container) : 
                m_pThis(&this_),
                m_pContainer(&container)
            { }

            template<class Previous>
            void operator()(wrap<Previous> const &)
            {
                if (!m_pContainer->m_p)
                {
                    typedef typename chain_from<Previous>::type PreviousChain;
                    PreviousChain &chain = m_pThis->ChainFrom<Previous>();
                    m_pContainer->m_p = chain.MapFirstAncestor<T>();
                }
            }

            this_type const *m_pThis;
            container<T> *m_pContainer;
        };

        template<class T>
        struct map_first_selector
        {
            map_first_selector(this_type const &this_, container<T> &container) : 
                m_pThis(&this_),
                m_pContainer(&container)
            { }

            template<class Previous>
            void operator()(wrap<Previous> const &)
            {
                if (!m_pContainer->m_p)
                {
                    typedef typename chain_from<Previous>::type PreviousChain;
                    PreviousChain &chain = m_pThis->ChainFrom<Previous>();
                    m_pContainer->m_p = chain.MapFirst<T>();
                }
            }

            this_type const *m_pThis;
            container<T> *m_pContainer;
        };

        template<
            class T,
            class HeapProvider
        >
        struct new_object_first_selector
        {
            new_object_first_selector(this_type const &this_, HeapProvider &provider, container<T> &container) : 
                m_pThis(&this_),
                m_pProvider(&provider),
                m_pContainer(&container)
            { }

            template<class Previous>
            void operator()(wrap<Previous> const &)
            {
                if (!m_pContainer->m_p)
                {
                    typedef typename chain_from<Previous>::type PreviousChain;
                    PreviousChain &chain = m_pThis->ChainFrom<Previous>();
                    m_pContainer->m_p = chain.NewObject<T>(*m_pProvider);
                }
            }

            this_type const *m_pThis;
            HeapProvider *m_pProvider;
            container<T> *m_pContainer;
        };
    };

}}   // namespace Urasandesu { namespace CppAnonym {

#endif  // #ifndef URASANDESU_CPPANONYM_SMARTPTRCHAIN_HPP