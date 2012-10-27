#pragma once
#ifndef URASANDESU_CPPANONYM_SMARTPTRCHAIN_HPP
#define URASANDESU_CPPANONYM_SMARTPTRCHAIN_HPP

#ifndef URASANDESU_CPPANONYM_SMARTPTRCHAIN_H
#include <Urasandesu/CppAnonym/SmartPtrChain.h>
#endif

namespace Urasandesu { namespace CppAnonym {

    namespace SmartPtrChainDetail {

        template<class Chain, class T>
        template<class Previous>
        void MapFirstAncestorSelector<Chain, T>::operator()(Wrap<Previous> const &)
        {
            if (!m_pContainer->m_p)
            {
                typedef typename Chain::chain_from<Previous>::type PreviousChain;
                PreviousChain &chain = m_pChain->ChainFrom<Previous>();
                m_pContainer->m_p = chain.MapFirstAncestor<T>();
            }
        }

        
        
        

        template<class Chain, class T>
        template<class Previous>
        void MapFirstSelector<Chain, T>::operator()(Wrap<Previous> const &)
        {
            if (!m_pContainer->m_p)
            {
                typedef typename Chain::chain_from<Previous>::type PreviousChain;
                PreviousChain &chain = m_pChain->ChainFrom<Previous>();
                m_pContainer->m_p = chain.MapFirst<T>();
            }
        }

        
        
        

        template<class Current, class ChainInfoTypes>
        template<class T>
        T *SmartPtrChainImpl<Current, ChainInfoTypes>::MapFirstAncestor() const
        {
            using mpl::_;
            using mpl::filter_view;
            using mpl::for_each;

            typedef filter_view<chain_info_types, IsMappable<_, T> >::type MappableTypes;
            
            Container<T> container;
            MapFirstAncestorSelector<this_type, T> selector(*this, container);
            for_each<MappableTypes, Wrap<CPP_ANONYM_GET_MEMBER_TYPE(ChainInfoPrevious, _) > >(selector);
            return container.m_p;
        }

        template<class Current, class ChainInfoTypes>
        template<class T>
        T *SmartPtrChainImpl<Current, ChainInfoTypes>::MapFirst() const
        {
            using mpl::_;
            using mpl::filter_view;
            using mpl::for_each;

            typedef filter_view<chain_info_types, IsMappable<_, T> >::type MappableTypes;
            
            Container<T> container;
            MapFirstSelector<this_type, T> selector(*this, container);
            for_each<MappableTypes, Wrap<CPP_ANONYM_GET_MEMBER_TYPE(ChainInfoPrevious, _) > >(selector);
            return container.m_p;
        }

    }   // namespace SmartPtrChainDetail

}}   // namespace Urasandesu { namespace CppAnonym {

#endif  // #ifndef URASANDESU_CPPANONYM_SMARTPTRCHAIN_HPP