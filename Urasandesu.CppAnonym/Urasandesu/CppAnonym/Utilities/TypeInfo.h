/* 
 * File: TypeInfo.h
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
#ifndef URASANDESU_CPPANONYM_UTILITIES_TYPEINFO_H
#define URASANDESU_CPPANONYM_UTILITIES_TYPEINFO_H

#ifndef URASANDESU_CPPANONYM_TRAITS_MAKEVALUEHOLDERIMPL_H
#include <Urasandesu/CppAnonym/Traits/MakeValueHolderImpl.h>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_MAKEHEAPVALUEHOLDERIMPL_H
#include <Urasandesu/CppAnonym/Traits/MakeHeapValueHolderImpl.h>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_DEFAULTDELETER_H
#include <Urasandesu/CppAnonym/Utilities/DefaultDeleter.h>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_EQUALITYCOMPARABLE_H
#include <Urasandesu/CppAnonym/Traits/EqualityComparable.h>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_HASHCOMPUTABLE_H
#include <Urasandesu/CppAnonym/Traits/HashComputable.h>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_TYPEINFOFWD_H
#include <Urasandesu/CppAnonym/Utilities/DefaultDeleter.h>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_TYPEINFOFWD_H
#include <Urasandesu/CppAnonym/Utilities/TypeInfoFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    namespace TypeInfoDetail {

        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym::Traits;
        using boost::intrusive_ptr;
        using mpl::identity;

        struct TypeInfoHolder
        {
            typedef TypeInfoHolder this_type;

            TypeInfoHolder() : 
                m_useCount(0) 
            { }
            
            virtual ~TypeInfoHolder()
            { }
            
            virtual void Delete() = 0;
            virtual std::type_info const &GetType() const = 0;
            virtual std::string const &GetRawName() const = 0;

            friend void intrusive_ptr_add_ref(this_type *p)
            {
                ++p->m_useCount;
            }
            
            friend void intrusive_ptr_release(this_type *p)
            {
                if(--p->m_useCount == 0) 
                    p->Delete();
            }

            LONG m_useCount;
        };

        
        
        
        
        template<class Type, class ImplD>
        struct TypeInfoHolderImpl : 
            TypeInfoHolder
        {
            typedef TypeInfoHolderImpl<Type, ImplD> this_type;
            typedef TypeInfoHolder base_type;
            typedef Type type_type;
            typedef ImplD impl_deleter_type; 

            TypeInfoHolderImpl(impl_deleter_type impld) : 
                base_type(), 
                m_impld(impld)
            { 
            }

            virtual ~TypeInfoHolderImpl()
            {
            }

            virtual void Delete()
            {
                m_impld(this);
            }

            virtual std::type_info const &GetType() const 
            { 
                return typeid(type_type); 
            }

            virtual std::string const &GetRawName() const
            {
                if (m_name.empty())
                    m_name = typeid(type_type).raw_name();
                return m_name;
            }

            mutable std::string m_name;
            impl_deleter_type m_impld;
        };

        
        
        
        
        template<class Type, class ImplD>
        struct MakeHolderImpl : 
            MakeValueHolderImpl<Type, ImplD, TypeInfoHolderImpl>
        {
        };

        
        
        
        
        template<
            class Type, 
            class Tag
        >
        struct MakeHeapHolderImpl : 
            MakeHeapValueHolderImpl<Type, TypeInfoHolderImpl, Tag>
        {
        };





        class TypeInfoImpl
        {
        public:
            typedef TypeInfoImpl this_type;
            typedef TypeInfoHolder holder_type;

            TypeInfoImpl() : 
                m_pHolder()
            { }

            template<class Type>
            TypeInfoImpl(identity<Type> const &) : 
                m_pHolder(new TypeInfoHolderImpl<Type, DefaultDeleter>(DefaultDeleter()))
            { }

            template<class Type, class ImplD>
            TypeInfoImpl(TypeInfoHolderImpl<Type, ImplD> *pHolder) : 
                m_pHolder(pHolder)
            {
                _ASSERTE(pHolder != NULL); 
            }

            TypeInfoImpl(TypeInfoImpl const &other) : 
                m_pHolder(other.m_pHolder)
            { }
            
            TypeInfoImpl &operator =(TypeInfoImpl &other)
            {
                if (this != &other)
                    m_pHolder = other.m_pHolder;
                return *this;
            }

            template<class Type>
            TypeInfoImpl &operator =(identity<Type> const &)
            {
                m_pHolder = new TypeInfoHolderImpl<Type, DefaultDeleter>(DefaultDeleter());
                return *this;
            }

            template<class Type, class ImplD>
            TypeInfoImpl &operator =(TypeInfoHolderImpl<Type, ImplD> *pOtherHolder) : 
            {
                _ASSERTE(pOtherHolder != NULL); 
                m_pHolder = pOtherHolder;
                return *this;
            }
            
            bool IsEmpty() const
            {
                return !m_pHolder;
            }
            
            template<class Type>
            bool Is() const 
            {
                return !IsEmpty() && typeid(Type) == m_pHolder->GetType();
            }

            std::string const &GetRawName() const
            {
                return IsEmpty() ? EmptyRawName() : m_pHolder->GetRawName();
            }

            bool operator ==(TypeInfoImpl const &other) const;

            bool operator !=(TypeInfoImpl const &other) const
            {
                return !(*this == other);
            }

        protected:
            TypeInfoImpl(intrusive_ptr<holder_type> const &pHolder) : 
                m_pHolder(pHolder)
            { }

        private:
            static std::string const &EmptyRawName()
            {
                static std::string empty;
                return empty;
            }

            intrusive_ptr<holder_type> m_pHolder;
        };

    }   // namespace TypeInfoDetail {

    struct TypeInfo : 
        TypeInfoDetail::TypeInfoImpl
    {
        typedef TypeInfo this_type;
        typedef TypeInfoDetail::TypeInfoImpl base_type;

        TypeInfo() : 
            base_type()
        { }

        template<class Type>
        TypeInfo(boost::mpl::identity<Type> const &id) : 
            base_type(id)
        { }

        template<class Type, class ImplD>
        explicit TypeInfo(TypeInfoDetail::TypeInfoHolderImpl<Type, ImplD> *pHolder) : 
            base_type(pHolder)
        { }

        TypeInfo(TypeInfo const &other) : 
            base_type(other)
        { }

        TypeInfo &operator =(TypeInfo &other)
        {
            base_type::operator =(other);
            return *this;
        }

        template<class Type>
        TypeInfo &operator =(boost::mpl::identity<Type> const &id)
        {
            base_type::operator =(id);
            return *this;
        }

        template<class Type, class ImplD>
        TypeInfo &operator =(TypeInfoDetail::TypeInfoHolderImpl<Type, ImplD> *pOtherHolder) : 
        {
            base_type::operator =(pOtherHolder);
            return *this;
        }
    };

    
    
    
    
    struct TypeInfoHash : 
        Traits::HashComputable<TypeInfo>
    {
        result_type operator()(param_type v) const
        {
            return boost::hash_value(v.GetRawName());
        }
    };

    
    
    
    
    struct TypeInfoEqualTo : 
        Traits::EqualityComparable<TypeInfo>
    {
        result_type operator()(param_type x, param_type y) const
        {
            return x == y;
        }
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_TYPEINFO_H
