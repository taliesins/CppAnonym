#pragma once
#ifndef URASANDESU_CPPANONYM_UTILITIES_ANYPTR_HPP
#define URASANDESU_CPPANONYM_UTILITIES_ANYPTR_HPP

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    // NOTE: I made this class by reference to Boost.Any. 
    //       Boost.Any is permitted free of changes under Boost Software License, Version 1.0.
    //       The copyright statement is as below: 
    // 
    // Copyright Kevlin Henney, 2000, 2001, 2002. All rights reserved.
    //
    // Distributed under the Boost Software License, Version 1.0. (See
    // accompanying file LICENSE_1_0.txt or copy at
    // http://www.boost.org/LICENSE_1_0.txt)

    namespace _D3D82F28 {
        
        struct Holder
        {
            virtual ~Holder() { }
            virtual std::type_info const &GetType() const = 0;
            virtual Holder *Clone() const = 0;
        };

        template<class PointerType>
        struct PointerHolder : Holder
        {
            BOOST_MPL_ASSERT((boost::is_pointer<PointerType>));
            typedef typename Traits::RemoveConst<PointerType>::type pointer_type;
            typedef PointerHolder<pointer_type> type;
            PointerHolder(pointer_type p) : m_p(p) { }
            virtual ~PointerHolder() { delete m_p; }
            virtual std::type_info const &GetType() const { return typeid(pointer_type); }            
            virtual Holder *Clone() const { return new PointerHolder(m_p); }            
            pointer_type m_p;
        };

    }   // namespace _D3D82F28 {

    class AnyPtr
    {
    public:
        typedef _D3D82F28::Holder holder_type;

        AnyPtr() : 
            m_pHolder(NULL)
        { }

        template<class PointerType>
        AnyPtr(PointerType p) : 
            m_pHolder(new _D3D82F28::PointerHolder<PointerType>(p))
        { }

        AnyPtr(AnyPtr const &other) : 
            m_pHolder(other.IsEmpty() ? NULL : other.m_pHolder->Clone())
        { }

        ~AnyPtr() 
        { 
            if (m_pHolder != NULL)
                delete m_pHolder;
        }

        inline bool IsEmpty() const { return m_pHolder == NULL; }

        template<class PointerType>
        inline bool Is() const 
        {
            return !IsEmpty() && 
                   typeid(typename _D3D82F28::PointerHolder<PointerType>::pointer_type) == m_pHolder->GetType();
        }
        
        inline AnyPtr &Swap(AnyPtr &other) 
        { 
            std::swap(m_pHolder, other.m_pHolder); 
            return *this; 
        }

        inline AnyPtr &operator =(AnyPtr &other)
        {
            other.Swap(*this);
            return *this;
        }

        template<class PointerType>
        inline AnyPtr &operator =(PointerType p)
        {
            AnyPtr(p).Swap(*this);
            return *this;
        }

        template<class PointerType>
        inline operator PointerType()
        {
            typedef typename _D3D82F28::PointerHolder<PointerType>::type HolderType;
            return Is<PointerType>() ? static_cast<HolderType *>(m_pHolder)->m_p : NULL;
        }

    private:
        holder_type *m_pHolder;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_ANYPTR_HPP