/* 
 * File: SmartPtrChain.hpp
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
#ifndef URASANDESU_CPPANONYM_SMARTPTRCHAIN_HPP
#define URASANDESU_CPPANONYM_SMARTPTRCHAIN_HPP

#ifndef URASANDESU_CPPANONYM_SMARTPTRCHAIN_H
#include <Urasandesu/CppAnonym/SmartPtrChain.h>
#endif

// TODO: integrate to SmartPtrChain.h.

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
