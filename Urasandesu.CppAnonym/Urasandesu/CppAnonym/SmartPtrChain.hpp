#pragma once
#ifndef URASANDESU_CPPANONYM_SMARTPTRCHAIN_HPP
#define URASANDESU_CPPANONYM_SMARTPTRCHAIN_HPP

#ifndef URASANDESU_CPPANONYM_SMARTPTRCHAIN_H
#include <Urasandesu/CppAnonym/SmartPtrChain.h>
#endif

namespace Urasandesu { namespace CppAnonym {

    namespace SmartPtrChainDetail {

        template<class Current, class ChainInfoTypes, class I, class IEnd>
        SmartPtrChainImplImpl<Current, ChainInfoTypes, I, IEnd>::SmartPtrChainImplImpl() : 
            m_pPrevious(NULL)
        { }

        template<class Current, class ChainInfoTypes, class I, class IEnd>
        template<class T>
        T *SmartPtrChainImplImpl<Current, ChainInfoTypes, I, IEnd>::MapFirstAncestor() const
        {
            return mapper_type::MapFirstAncestor<T, previous_type>(GetCurrent()); 
        }

        template<class Current, class ChainInfoTypes, class I, class IEnd>
        template<class T>
        T *SmartPtrChainImplImpl<Current, ChainInfoTypes, I, IEnd>::MapFirst() const
        {
            return mapper_type::MapFirstAncestor<T, previous_type>(GetCurrent()); 
        }

        template<class Current, class ChainInfoTypes, class I, class IEnd>
        template<class T>
        T *SmartPtrChainImplImpl<Current, ChainInfoTypes, I, IEnd>::Map() const
        {
            return mapper_type::MapAncestor<T, previous_type>(GetCurrent()); 
        }

        template<class Current, class ChainInfoTypes, class I, class IEnd>
        template<
            class T,
            class PersistableHeapProvider
        >
        static TempPtr<T> SmartPtrChainImplImpl<Current, ChainInfoTypes, I, IEnd>::NewRootObject(PersistableHeapProvider &provider)
        {
            return constructor_type::NewRootObject<T>(provider);
        }

        template<class Current, class ChainInfoTypes, class I, class IEnd>
        template<
            class T,
            class PersistableHeapProvider
        >
        TempPtr<T> SmartPtrChainImplImpl<Current, ChainInfoTypes, I, IEnd>::NewObject(PersistableHeapProvider &provider) const
        {
            return constructor_type::NewObject<T>(static_cast<current_type &>(*const_cast<this_type *>(this)), provider);
        }
            
        template<class Current, class ChainInfoTypes, class I, class IEnd>
        typename SmartPtrChainImplImpl<Current, ChainInfoTypes, I, IEnd>::previous_type *
            SmartPtrChainImplImpl<Current, ChainInfoTypes, I, IEnd>::GetPrevious() const
        {
            return m_pPrevious;
        }

        template<class Current, class ChainInfoTypes, class I, class IEnd>
        void 
            SmartPtrChainImplImpl<Current, ChainInfoTypes, I, IEnd>::SetPrevious(
                typename SmartPtrChainImplImpl<Current, ChainInfoTypes, I, IEnd>::previous_type &previous
            )
        {
            _ASSERTE(m_pPrevious == NULL);
            m_pPrevious = &previous;
        }

        template<class Current, class ChainInfoTypes, class I, class IEnd>
        typename SmartPtrChainImplImpl<Current, ChainInfoTypes, I, IEnd>::current_type &
            SmartPtrChainImplImpl<Current, ChainInfoTypes, I, IEnd>::GetCurrent() const
        {
            this_type *pMutableThis = const_cast<this_type *>(this);
            current_type *pCurrent = static_cast<current_type *>(pMutableThis);
            return *pCurrent;
        }

        
        
        
        
        template<class T>
        Container<T>::Container() : 
            m_p(NULL)
        { }

        
        
        
        
        template<class Chain, class T>
        MapFirstAncestorSelector<Chain, T>::MapFirstAncestorSelector(Chain const &chain, Container<T> &Container) : 
            m_pChain(&chain),
            m_pContainer(&Container)
        { }

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
        MapFirstSelector<Chain, T>::MapFirstSelector(Chain const &chain, Container<T> &Container) : 
            m_pChain(&chain),
            m_pContainer(&Container)
        { }

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
        template<class ChainingPreviousType>
        inline typename SmartPtrChainImpl<Current, ChainInfoTypes>::chain_from<ChainingPreviousType>::type &
            SmartPtrChainImpl<Current, ChainInfoTypes>::ChainFrom() const
        {
            this_type *pMutableThis = const_cast<this_type *>(this);
            return static_cast<typename chain_from<ChainingPreviousType>::type &>(*pMutableThis);
        }

        template<class Current, class ChainInfoTypes>
        template<class T>
        T *SmartPtrChainImpl<Current, ChainInfoTypes>::MapFirstAncestor() const
        {
            typedef mpl::filter_view<chain_info_types, IsMappable<mpl::_, T> >::type MappableTypes;
            
            Container<T> container;
            MapFirstAncestorSelector<this_type, T> selector(*this, container);
            mpl::for_each<MappableTypes, Wrap<CPP_ANONYM_GET_MEMBER_TYPE(ChainInfoPrevious, mpl::_) > >(selector);
            return container.m_p;
        }

        template<class Current, class ChainInfoTypes>
        template<class T>
        T *SmartPtrChainImpl<Current, ChainInfoTypes>::MapFirst() const
        {
            typedef mpl::filter_view<chain_info_types, IsMappable<mpl::_, T> >::type MappableTypes;
            
            Container<T> container;
            MapFirstSelector<this_type, T> selector(*this, container);
            mpl::for_each<MappableTypes, Wrap<CPP_ANONYM_GET_MEMBER_TYPE(ChainInfoPrevious, mpl::_) > >(selector);
            return container.m_p;
        }

    }   // namespace SmartPtrChainDetail

    template<class Current, class ChainInfoTypes>
    class ATL_NO_VTABLE SmartPtrChain : 
        public SmartPtrChainDetail::SmartPtrChainImpl<Current, ChainInfoTypes>
    {
    };

}}   // namespace Urasandesu { namespace CppAnonym {

#endif  // #ifndef URASANDESU_CPPANONYM_SMARTPTRCHAIN_HPP