#pragma once
#ifndef URASANDESU_CPPANONYM_UTILITIES_ANYPOINTER_H
#define URASANDESU_CPPANONYM_UTILITIES_ANYPOINTER_H

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
    class AnyPointer
    {
    public:
        AnyPointer() : 
            m_pHolder(NULL)
        { }

        template<class PointerType>
        AnyPointer(PointerType p) : 
            m_pHolder(new PointerHolder<PointerType>(p))
        { }

        AnyPointer(AnyPointer const &other) : 
            m_pHolder(other.IsEmpty() ? NULL : other.m_pHolder->Clone())
        { }

        ~AnyPointer() 
        { 
            if (m_pHolder != NULL)
                delete m_pHolder;
        }

        inline bool IsEmpty() const { return m_pHolder == NULL; }

        template<class PointerType>
        inline bool Is() const 
        {
            return !IsEmpty() && 
                   typeid(typename PointerHolder<PointerType>::pointer_type) == m_pHolder->GetType();
        }
        
        inline AnyPointer &Swap(AnyPointer &other) 
        { 
            std::swap(m_pHolder, other.m_pHolder); 
            return *this; 
        }

        inline AnyPointer &operator =(AnyPointer &other)
        {
            other.Swap(*this);
            return *this;
        }

        template<class PointerType>
        inline AnyPointer &operator =(PointerType p)
        {
            AnyPointer(p).Swap(*this);
            return *this;
        }

        template<class PointerType>
        inline operator PointerType()
        {
            typedef typename PointerHolder<PointerType>::type HolderType;
            return Is<PointerType>() ? static_cast<HolderType *>(m_pHolder)->m_p : NULL;
        }

    private:
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

        Holder *m_pHolder;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_ANYPOINTER_H