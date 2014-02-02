/* 
 * File: SmartPtrChain.h
 * 
 * Author: Akira Sugiura (urasandesu@gmail.com)
 * 
 * 
 * Copyright (c) 2014 Akira Sugiura
 *  
 *  This software is MIT License.
 *  
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *  
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 *  
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 *  THE SOFTWARE.
 */


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
        using boost::is_same;
        using mpl::_1;
        using mpl::_2;
        using mpl::and_;
        using mpl::at_c;
        using mpl::back_inserter;
        using mpl::begin;
        using mpl::copy;
        using mpl::deref;
        using mpl::end;
        using mpl::eval_if;
        using mpl::find;
        using mpl::find_if;
        using mpl::fold;
        using mpl::identity;
        using mpl::lambda;
        using mpl::next;
        using mpl::not_;
        using mpl::vector;
        using mpl::void_;

        template<class Current, class ChainInfoTypes, class I, class IEnd>
        class ATL_NO_VTABLE SmartPtrChainImplImpl : 
            public SmartPtrChainImplImpl<Current, ChainInfoTypes, typename next<I>::type, IEnd>
        {
        public:
            typedef SmartPtrChainImplImpl<Current, ChainInfoTypes, I, IEnd> this_type;
            typedef typename deref<I>::type chain_info_type;
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
                                              typename end<ChainInfoTypes>::type, 
                                              typename end<ChainInfoTypes>::type> : 
            noncopyable
        {
        };

        
        
        
        
        CPP_ANONYM_DECLARE_HAS_MEMBER_TYPE(ChainInfoPrevious, previous_type);
        CPP_ANONYM_DECLARE_GET_MEMBER_TYPE(ChainInfoPrevious, previous_type);

        
        
        
        
        CPP_ANONYM_DECLARE_HAS_MEMBER_TYPE(SmartPtrChainChainInfos, chain_info_types);
        CPP_ANONYM_DECLARE_GET_MEMBER_TYPE(SmartPtrChainChainInfos, chain_info_types);

        
        
        
        
        template<class Current>
        struct ExtractPreviousOrDefault : 
            eval_if<
                CPP_ANONYM_HAS_MEMBER_TYPE(ChainInfoPrevious, Current),
                CPP_ANONYM_GET_MEMBER_TYPE(ChainInfoPrevious, Current),
                identity<Current> >
        {
        };

        
        
        
        
        template<class Last, class T>
        struct ExtractChainInfoTypesOrDefault : 
            eval_if<
                and_<
                    CPP_ANONYM_HAS_MEMBER_TYPE(SmartPtrChainChainInfos, T),
                    not_<is_same<Last, T> >
                >,
                CPP_ANONYM_GET_MEMBER_TYPE(SmartPtrChainChainInfos, T),
                identity<vector<T> > >
        {
        };

        
        
        
        
        template<class Last, class Current>
        class FlattenChainInfoImpl
        {
            typedef typename ExtractPreviousOrDefault<Current>::type previous_type;
            typedef typename ExtractChainInfoTypesOrDefault<Last, previous_type>::type chain_info_types;
            typedef vector<previous_type> previous_types;
            typedef is_same<chain_info_types, previous_types > unnecessary_more_extraction;
            typedef typename lambda<copy<FlattenChainInfoImpl<previous_type, _2>, back_inserter<_1> > >::type extract_recursively;

        public:
            typedef typename eval_if<
                                unnecessary_more_extraction, 
                                chain_info_types,
                                fold<chain_info_types, previous_types, extract_recursively> >::type type; 
        };

        
        
        
        
        template<class T>
        struct FlattenChainInfo : 
            FlattenChainInfoImpl<void_, T>
        {
        };

        
        
        
        
        template<class Current, class T>
        class IsMappable
        {
        private:
            typedef Current current;
            typedef typename FlattenChainInfo<current>::type all_mappable_types;
            typedef typename find<all_mappable_types, T>::type i;
            typedef typename end<all_mappable_types>::type i_end;

        public:
            typedef typename not_<is_same<i, i_end> > type;
        };

        
        
        
        
        template<class ChainInfo, class T>
        struct HasPreviousT : 
            is_same<typename CPP_ANONYM_GET_MEMBER_TYPE(ChainInfoPrevious, ChainInfo)::type, T>
        {
        };

        
        
        
        
        template<class ChainInfoTypes, LONG N>
        class ChainingPreviousTypeAtImpl
        {
            typedef typename at_c<ChainInfoTypes, N>::type chain_info_type;
        public:
            typedef typename chain_info_type::previous_type type;
        };

        
        
        
        
        template<class Current, class ChainInfoTypes, class ChainingPreviousType>
        class ChainFromImpl
        {
            typedef typename find_if<ChainInfoTypes, HasPreviousT<_1, ChainingPreviousType> >::type i;
            typedef typename end<ChainInfoTypes>::type i_end;
            BOOST_MPL_ASSERT((not_<is_same<i, i_end> >));
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
            Container() : 
                m_p(NULL)
            { }
            
            T *m_p;
        };

        
        
        
        
        template<class Chain, class T>
        struct MapFirstAncestorSelector
        {
            MapFirstAncestorSelector(Chain const &chain, Container<T> &Container) : 
                m_pChain(&chain),
                m_pContainer(&Container)
            { }

            template<class Previous>
            void operator()(Wrap<Previous> const &);

            Chain const *m_pChain;
            Container<T> *m_pContainer;
        };

        
        
        
        
        template<class Chain, class T>
        struct MapFirstSelector
        {
            MapFirstSelector(Chain const &chain, Container<T> &Container) : 
                m_pChain(&chain),
                m_pContainer(&Container)
            { }

            template<class Previous>
            void operator()(Wrap<Previous> const &);

            Chain const *m_pChain;
            Container<T> *m_pContainer;
        };

        
        
        
        
        template<class Current, class ChainInfoTypes>
        class ATL_NO_VTABLE SmartPtrChainImpl : 
            public SmartPtrChainImplImpl<Current, 
                                         ChainInfoTypes, 
                                         typename begin<ChainInfoTypes>::type, 
                                         typename end<ChainInfoTypes>::type>
        {
        public:
            typedef SmartPtrChainImpl<Current, ChainInfoTypes> this_type;
            typedef ChainInfoTypes chain_info_types;

            template<LONG N>
            struct chaining_previous_type_at : 
                ChainingPreviousTypeAtImpl<chain_info_types, N>
            {
            };

            template<class ChainingPreviousType>
            struct chain_from : 
                ChainFromImpl<Current, chain_info_types, ChainingPreviousType>
            {
            };

            template<class ChainingPreviousType>
            typename chain_from<ChainingPreviousType>::type &ChainFrom() const
            {
                this_type *pMutableThis = const_cast<this_type *>(this);
                return static_cast<typename chain_from<ChainingPreviousType>::type &>(*pMutableThis);
            }

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

    template<class Current, class ChainInfoTypes>
    struct ATL_NO_VTABLE SmartPtrChain : 
        SmartPtrChainDetail::SmartPtrChainImpl<Current, ChainInfoTypes>
    {
    };

}}   // namespace Urasandesu { namespace CppAnonym {

#endif  // #ifndef URASANDESU_CPPANONYM_SMARTPTRCHAIN_H
