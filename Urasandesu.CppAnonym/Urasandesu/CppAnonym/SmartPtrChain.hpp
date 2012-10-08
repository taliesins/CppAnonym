#pragma once
#ifndef URASANDESU_CPPANONYM_SMARTPTRCHAIN_HPP
#define URASANDESU_CPPANONYM_SMARTPTRCHAIN_HPP

#ifndef URASANDESU_CPPANONYM_SMARTPTRCHAINFWD_HPP
#include <Urasandesu/CppAnonym/SmartPtrChainFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym {

    namespace SmartPtrChainDetail {
        
        namespace mpl = boost::mpl;
        using namespace boost;
        using namespace Urasandesu::CppAnonym::Utilities;

        template<class Current, class ChainInfoTypes, class I, class IEnd>
        class ATL_NO_VTABLE SmartPtrChainImplImpl : 
            public SmartPtrChainImplImpl<Current, ChainInfoTypes, typename mpl::next<I>::type, IEnd>
        {
        public:
            typedef SmartPtrChainImplImpl<Current, ChainInfoTypes, I, IEnd> this_type;
            typedef typename mpl::deref<I>::type chain_info_type;
            typedef typename Current current_type;
            typedef typename chain_info_type::previous_type previous_type;
            typedef typename chain_info_type::mapper_type mapper_type;
            typedef typename chain_info_type::constructor_type constructor_type;

            SmartPtrChainImplImpl() : 
                m_pPrevious(NULL)
            { }

            template<class T>
            T *MapFirstAncestor() const
            {
                return mapper_type::MapFirstAncestor<T, previous_type>(GetCurrent()); 
            }

            template<class T>
            T *MapFirst() const
            {
                return mapper_type::MapFirstAncestor<T, previous_type>(GetCurrent()); 
            }

            template<>
            current_type *MapFirst<current_type>() const
            { 
                return mapper_type::MapFirst<current_type>(GetCurrent());
            }

            template<class T>
            T *Map() const
            {
                return mapper_type::MapAncestor<T, previous_type>(GetCurrent()); 
            }

            template<>
            current_type *Map<current_type>() const
            { 
                return mapper_type::Map<current_type>(GetCurrent());
            }

            template<
                class T,
                class PersistableHeapProvider
            >
            static TempPtr<T> NewRootObject(PersistableHeapProvider &provider)
            {
                return constructor_type::NewRootObject<T>(provider);
            }

            template<
                class T,
                class PersistableHeapProvider
            >
            TempPtr<T> NewObject(PersistableHeapProvider &provider) const
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
            current_type &GetCurrent() const
            {
                this_type *pMutableThis = const_cast<this_type *>(this);
                current_type *pCurrent = static_cast<current_type *>(pMutableThis);
                return *pCurrent;
            }

            previous_type *m_pPrevious;
        };

        template<class Current, class ChainInfoTypes>
        class ATL_NO_VTABLE SmartPtrChainImplImpl<Current, 
                                              ChainInfoTypes, 
                                              typename mpl::end<ChainInfoTypes>::type, 
                                              typename mpl::end<ChainInfoTypes>::type> : 
            noncopyable
        {
        };

        template<class Current>
        struct ExtractPreviousOrDefault : 
            mpl::eval_if<
                CPP_ANONYM_HAS_MEMBER_TYPE(ChainInfoPrevious, Current),
                CPP_ANONYM_GET_MEMBER_TYPE(ChainInfoPrevious, Current),
                mpl::identity<Current> >
        {
        };

        template<class Last, class T>
        struct ExtractChainInfoTypesOrDefault : 
            mpl::eval_if<
                mpl::and_<
                    CPP_ANONYM_HAS_MEMBER_TYPE(SmartPtrChainChainInfos, T),
                    mpl::not_<boost::is_same<Last, T> >
                >,
                CPP_ANONYM_GET_MEMBER_TYPE(SmartPtrChainChainInfos, T),
                mpl::identity<mpl::vector<T> > >
        {
        };

        template<class Last, class Current>
        class FlattenChainInfoImpl
        {
            typedef typename ExtractPreviousOrDefault<Current>::type previous_type;
            typedef typename ExtractChainInfoTypesOrDefault<Last, previous_type>::type chain_info_types;

        public:
            typedef typename mpl::eval_if<
                                boost::is_same<chain_info_types, mpl::vector<previous_type> >, 
                                chain_info_types,
                                mpl::fold<
                                    chain_info_types, 
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

        template<class ChainInfo, class T>
        struct HasPreviousT : 
            boost::is_same<typename CPP_ANONYM_GET_MEMBER_TYPE(ChainInfoPrevious, ChainInfo)::type, T>
        {
        };

        template<class ChainInfoTypes, LONG N>
        class ChainingPreviousTypeAtImpl
        {
            typedef typename mpl::at_c<ChainInfoTypes, N>::type chain_info_type;
        public:
            typedef typename chain_info_type::previous_type type;
        };

        template<class Current, class ChainInfoTypes, class ChainingPreviousType>
        class ChainFromImpl
        {
            typedef typename mpl::find_if<ChainInfoTypes, HasPreviousT<mpl::_1, ChainingPreviousType> >::type i;
            typedef typename mpl::end<ChainInfoTypes>::type i_end;
            BOOST_MPL_ASSERT((mpl::not_<boost::is_same<i, i_end> >));
        public:
            typedef SmartPtrChainImplImpl<Current, ChainInfoTypes, i, i_end> type;
        };

        template<class Current, class ChainInfoTypes>
        class ATL_NO_VTABLE SmartPtrChainImpl : 
            public SmartPtrChainImplImpl<Current, 
                                         ChainInfoTypes, 
                                         typename mpl::begin<ChainInfoTypes>::type, 
                                         typename mpl::end<ChainInfoTypes>::type>
        {
        public:
            typedef SmartPtrChainImpl<Current, ChainInfoTypes> this_type;
            typedef ChainInfoTypes chain_info_types;

            template<LONG N>
            class chaining_previous_type_at : 
                public ChainingPreviousTypeAtImpl<chain_info_types, N>
            {
            };

            template<class ChainingPreviousType>
            class chain_from : 
                public ChainFromImpl<Current, chain_info_types, ChainingPreviousType>
            {
            };

            template<class ChainingPreviousType>
            inline typename chain_from<ChainingPreviousType>::type &ChainFrom() const
            {
                this_type *pMutableThis = const_cast<this_type *>(this);
                return static_cast<typename chain_from<ChainingPreviousType>::type &>(*pMutableThis);
            }

            template<class T>
            T *MapFirstAncestor() const
            {
                typedef mpl::filter_view<chain_info_types, IsMappable<mpl::_, T> >::type MappableTypes;
            
                container<T> container;
                map_first_ancestor_selector<T> selector(*this, container);
                mpl::for_each<MappableTypes, wrap<CPP_ANONYM_GET_MEMBER_TYPE(ChainInfoPrevious, mpl::_) > >(selector);
                return container.m_p;
            }

            template<class T>
            T *MapFirst() const
            {
                typedef mpl::filter_view<chain_info_types, IsMappable<mpl::_, T> >::type MappableTypes;
            
                container<T> container;
                map_first_selector<T> selector(*this, container);
                mpl::for_each<MappableTypes, wrap<CPP_ANONYM_GET_MEMBER_TYPE(ChainInfoPrevious, mpl::_) > >(selector);
                return container.m_p;
            }

            template<>
            Current *MapFirst<Current>() const
            {
                return Map<Current>();
            }

            //template<
            //    class T,
            //    class HeapProvider
            //>
            //T *NewObjectFirst(HeapProvider &provider) const
            //{
            //    container<T> container;
            //    new_object_first_selector<T, HeapProvider> selector(*this, provider, container);
            //    mpl::for_each<chain_info_types, wrap<CPP_ANONYM_GET_MEMBER_TYPE(ChainInfoPrevious, mpl::_) > >(selector);
            //    _ASSERTE(container.m_p);
            //    return container.m_p;
            //}

        private:
            template<class T>
            struct wrap
            {
            };

            template<class T>
            struct container
            {
                container() : 
                    m_p(NULL)
                { }
                T *m_p;
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

            //template<
            //    class T,
            //    class HeapProvider
            //>
            //struct new_object_first_selector
            //{
            //    new_object_first_selector(this_type const &this_, HeapProvider &provider, container<T> &container) : 
            //        m_pThis(&this_),
            //        m_pProvider(&provider),
            //        m_pContainer(&container)
            //    { }

            //    template<class Previous>
            //    void operator()(wrap<Previous> const &)
            //    {
            //        if (!m_pContainer->m_p)
            //        {
            //            typedef typename chain_from<Previous>::type PreviousChain;
            //            PreviousChain &chain = m_pThis->ChainFrom<Previous>();
            //            m_pContainer->m_p = chain.NewObject<T>(*m_pProvider);
            //        }
            //    }

            //    this_type const *m_pThis;
            //    HeapProvider *m_pProvider;
            //    container<T> *m_pContainer;
            //};
        };
    
    }   // namespace SmartPtrChainDetail

    template<class Current, class ChainInfoTypes>
    class ATL_NO_VTABLE SmartPtrChain : 
        public SmartPtrChainDetail::SmartPtrChainImpl<Current, ChainInfoTypes>
    {
    };

}}   // namespace Urasandesu { namespace CppAnonym {

#endif  // #ifndef URASANDESU_CPPANONYM_SMARTPTRCHAIN_HPP