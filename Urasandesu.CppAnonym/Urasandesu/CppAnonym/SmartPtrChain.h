#pragma once
#ifndef URASANDESU_CPPANONYM_SMARTPTRCHAIN_H
#define URASANDESU_CPPANONYM_SMARTPTRCHAIN_H

#ifndef URASANDESU_CPPANONYM_UTILITIES_TEMPPTR_HPP
#include <Urasandesu/CppAnonym/Utilities/TempPtr.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_SMARTPTRCHAINFWD_H
#include <Urasandesu/CppAnonym/SmartPtrChainFwd.h>
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

            SmartPtrChainImplImpl();

            template<class T>
            T *MapFirstAncestor() const;

            template<class T>
            T *MapFirst() const;

            template<>
            current_type *MapFirst<current_type>() const
            {
                return mapper_type::MapFirst<current_type>(GetCurrent());
            }

            template<class T>
            T *Map() const;

            template<>
            current_type *Map<current_type>() const
            {
                return mapper_type::Map<current_type>(GetCurrent());
            }

            template<
                class T,
                class PersistableHeapProvider
            >
            static TempPtr<T> NewRootObject(PersistableHeapProvider &provider);

            template<
                class T,
                class PersistableHeapProvider
            >
            TempPtr<T> NewObject(PersistableHeapProvider &provider) const;

            previous_type *GetPrevious() const;
            void SetPrevious(previous_type &previous);

        private:
            current_type &GetCurrent() const;

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

        CPP_ANONYM_DECLARE_HAS_MEMBER_TYPE(ChainInfoPrevious, previous_type);
        CPP_ANONYM_DECLARE_GET_MEMBER_TYPE(ChainInfoPrevious, previous_type);

        CPP_ANONYM_DECLARE_HAS_MEMBER_TYPE(SmartPtrChainChainInfos, chain_info_types);
        CPP_ANONYM_DECLARE_GET_MEMBER_TYPE(SmartPtrChainChainInfos, chain_info_types);

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

        template<class T>
        struct Wrap
        {
        };

        template<class T>
        struct Container
        {
            Container();
            T *m_p;
        };

        template<class Chain, class T>
        struct MapFirstAncestorSelector
        {
            MapFirstAncestorSelector(Chain const &chain, Container<T> &Container);

            template<class Previous>
            void operator()(Wrap<Previous> const &);

            Chain const *m_pChain;
            Container<T> *m_pContainer;
        };

        template<class Chain, class T>
        struct MapFirstSelector
        {
            MapFirstSelector(Chain const &chain, Container<T> &Container);

            template<class Previous>
            void operator()(Wrap<Previous> const &);

            Chain const *m_pChain;
            Container<T> *m_pContainer;
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
            inline typename chain_from<ChainingPreviousType>::type &ChainFrom() const;

            template<class T>
            T *MapFirstAncestor() const;

            template<class T>
            T *MapFirst() const;

            template<>
            Current *MapFirst<Current>() const
            {
                return Map<Current>();
            }
        };

    }   // namespace SmartPtrChainDetail

}}   // namespace Urasandesu { namespace CppAnonym {

#endif  // #ifndef URASANDESU_CPPANONYM_SMARTPTRCHAIN_H