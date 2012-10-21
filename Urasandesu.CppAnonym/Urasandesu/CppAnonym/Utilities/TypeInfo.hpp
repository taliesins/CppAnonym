#pragma once
#ifndef URASANDESU_CPPANONYM_UTILITIES_TYPEINFO_HPP
#define URASANDESU_CPPANONYM_UTILITIES_TYPEINFO_HPP

#ifndef URASANDESU_CPPANONYM_TRAITS_EQUALITYCOMPARABLE_H
#include <Urasandesu/CppAnonym/Traits/EqualityComparable.h>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_HASHCOMPUTABLE_H
#include <Urasandesu/CppAnonym/Traits/HashComputable.h>
#endif

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
    class TypeInfo
    {
    public:
        TypeInfo() : 
            m_pHolder(NULL)
        { }

        template<class Type>
        TypeInfo(boost::mpl::identity<Type> const &) : 
            m_pHolder(new TypeHolder<Type>())
        { }

        TypeInfo(TypeInfo const &other) : 
            m_pHolder(other.IsEmpty() ? NULL : other.m_pHolder->Clone())
        { }

        ~TypeInfo() 
        { 
            if (m_pHolder != NULL)
                delete m_pHolder;
        }

        inline bool IsEmpty() const { return m_pHolder == NULL; }

        template<class Type>
        inline bool Is() const 
        {
            return !IsEmpty() && 
                   typeid(typename TypeHolder<Type>::type) == m_pHolder->GetType();
        }

        inline std::string const &GetRawName() const
        {
            return IsEmpty() ? m_empty : m_pHolder->GetRawName();
        }
        
        inline TypeInfo &Swap(TypeInfo &other) 
        { 
            std::swap(m_pHolder, other.m_pHolder); 
            return *this; 
        }

        inline TypeInfo &operator =(TypeInfo &other)
        {
            other.Swap(*this);
            return *this;
        }

        template<class Type>
        inline TypeInfo &operator =(boost::mpl::identity<Type> const &id)
        {
            TypeInfo(id).Swap(*this);
            return *this;
        }

        inline bool operator ==(TypeInfo const &other) const
        {
            if (IsEmpty() && other.IsEmpty())
                return true;
            else if (IsEmpty() || other.IsEmpty())
                return false;
            else
                return m_pHolder->GetType() == other.m_pHolder->GetType();
        }

        inline bool operator !=(TypeInfo const &other) const
        {
            return !(*this == other);
        }

    private:
        struct Holder
        {
            virtual ~Holder() { }
            virtual std::type_info const &GetType() const = 0;
            virtual Holder *Clone() const = 0;
            virtual std::string const &GetRawName() const = 0;
        };

        template<class Type>
        struct TypeHolder : Holder
        {
            typedef Type type;
            typedef TypeHolder<type> this_type;
            virtual ~TypeHolder() { }
            virtual std::type_info const &GetType() const { return typeid(type); }            
            virtual Holder *Clone() const { return new TypeHolder<type>(); }            
            virtual std::string const &GetRawName() const
            {
                if (m_name.empty())
                    m_name = typeid(type).raw_name();
                return m_name;
            }

            mutable std::string m_name;
        };

        Holder *m_pHolder;
        std::string m_empty;
    };

    
    
    
    
    class TypeInfoHash : 
        Traits::HashComputable<TypeInfo>
    {
    public:
        result_type operator()(param_type v) const
        {
            return boost::hash_value(v.GetRawName());
        }
    };

    
    
    
    
    class TypeInfoEqualTo : 
        Traits::EqualityComparable<TypeInfo>
    {
    public:
        result_type operator()(param_type x, param_type y) const
        {
            return x == y;
        }
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_TYPEINFO_HPP