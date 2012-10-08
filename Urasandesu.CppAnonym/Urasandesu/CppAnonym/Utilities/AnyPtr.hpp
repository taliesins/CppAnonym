#pragma once
#ifndef URASANDESU_CPPANONYM_UTILITIES_ANYPTR_HPP
#define URASANDESU_CPPANONYM_UTILITIES_ANYPTR_HPP

#ifndef URASANDESU_CPPANONYM_UTILITIES_DEFAULTDELETER_HPP
#include <Urasandesu/CppAnonym/Utilities/DefaultDeleter.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_REMOVECONST_H
#include <Urasandesu/CppAnonym/Traits/RemoveConst.h>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_HEAPDELETER_HPP
#include <Urasandesu/CppAnonym/Utilities/HeapDeleter.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    namespace AnyPtrDetail {

        using namespace boost;
        
        struct AnyPtrHolder
        {
            typedef AnyPtrHolder this_type;

            AnyPtrHolder() : m_useCount(0) { }
            virtual ~AnyPtrHolder() { };
            virtual void *Pointer() const = 0;
            virtual void Delete() = 0;
            virtual std::type_info const &GetType() const = 0;

            inline friend void intrusive_ptr_add_ref(this_type *p)
            {
                ++p->m_useCount;
            }

            inline friend void intrusive_ptr_release(this_type *p)
            {
                if(--p->m_useCount == 0) 
                    p->Delete();
            }

            LONG m_useCount;
            
            //virtual ~AnyPtrHolder() { }
            //virtual std::type_info const &GetType() const = 0;
            //virtual AnyPtrHolder *Clone() const = 0;
        };

        //template<class PointerType>
        template<class T, class TD, class ImplD>
        //struct PointerHolder : 
        struct AnyPtrHolderImpl : 
            AnyPtrHolder
        {
            typedef AnyPtrHolderImpl<T, TD, ImplD> this_type;
            typedef AnyPtrHolder base_type;
            typedef T object_type;
            typedef TD object_deleter_type;
            typedef ImplD impl_deleter_type; 

            //BOOST_MPL_ASSERT((boost::is_pointer<T>));
            //typedef typename Traits::RemoveConst<T>::type pointer_type;

            AnyPtrHolderImpl(object_type *p, object_deleter_type d, impl_deleter_type impld) : 
                base_type(), 
                m_p(p),
                m_d(d),
                m_impld(impld)
            { 
                _ASSERTE(p != NULL); 
            }

            virtual ~AnyPtrHolderImpl()
            {
            }

            virtual void *Pointer() const
            {
                return const_cast<typename Traits::RemoveConst<object_type *>::type>(m_p);
            }

            virtual void Delete()
            {
                m_d(m_p);
                m_impld(this);
            }

            virtual std::type_info const &GetType() const 
            { 
                return typeid(object_type *); 
            }

            object_type *m_p;
            mutable object_deleter_type m_d;
            impl_deleter_type m_impld;

            //BOOST_MPL_ASSERT((boost::is_pointer<PointerType>));
            //typedef typename Traits::RemoveConst<PointerType>::type pointer_type;
            //typedef PointerHolder<pointer_type> type;
            //PointerHolder(pointer_type p) : m_p(p) { }
            //virtual ~PointerHolder() { delete m_p; }
            //virtual std::type_info const &GetType() const { return typeid(pointer_type); }            
            //virtual AnyPtrHolder *Clone() const { return new PointerHolder(m_p); }            
            //pointer_type m_p;
        };

        template<class T, class TD, class ImplD>
        struct MakeHolderImpl : 
            Traits::MakePointerHolderImpl<T, TD, ImplD, AnyPtrHolderImpl>
        {
        };

        template<
            class T, 
            class Tag
        >
        struct MakeHeapHolderImpl : 
            Traits::MakeHeapPointerHolderImpl<T, AnyPtrHolderImpl, Tag>
        {
        };

        class AnyPtrImpl
        {
        public:
            typedef AnyPtrImpl this_type;
            typedef AnyPtrHolder holder_type;

            AnyPtrImpl() : 
                m_pHolder()
            { }

            template<class T>
            explicit AnyPtrImpl(T *p) : 
                m_pHolder(new MakeHolderImpl<T, DefaultDeleter, DefaultDeleter>::type(p, DefaultDeleter(), DefaultDeleter()))
            { }

            template<class T, class TD>
            AnyPtrImpl(T *p, TD d) : 
                m_pHolder(new MakeHolderImpl<T, TD, DefaultDeleter>::type(p, d, DefaultDeleter()))
            { }

            template<class T, class TD, class ImplD>
            AnyPtrImpl(typename MakeHolderImpl<T, TD, ImplD>::type *pHolder) : 
                m_pHolder(pHolder)
            {
                _ASSERTE(pHolder != NULL); 
            }

            AnyPtrImpl(AnyPtrImpl const &other) : 
                m_pHolder(other.m_pHolder)
            { }

            inline AnyPtrImpl &operator =(AnyPtrImpl &other)
            {
                m_pHolder = other.m_pHolder;
                return *this;
            }

            inline bool IsEmpty() const
            {
                return !m_pHolder;
            }

            template<class Pointer>
            inline bool Is() const 
            {
                BOOST_MPL_ASSERT((is_pointer<Pointer>));
                return m_pHolder && typeid(Pointer) == m_pHolder->GetType();
            }

            template<class Pointer>
            inline operator Pointer()
            {
                return Is<Pointer>() ? static_cast<Pointer>(m_pHolder->Pointer()) : NULL;
            }

        protected:
            AnyPtrImpl(intrusive_ptr<holder_type> const &pHolder) : 
                m_pHolder(pHolder)
            { }

            intrusive_ptr<holder_type> m_pHolder;
        };

    }   // namespace AnyPtrDetail {

    struct AnyPtr : 
        AnyPtrDetail::AnyPtrImpl
    {
        typedef AnyPtr this_type;
        typedef AnyPtrDetail::AnyPtrImpl base_type;

        AnyPtr() : 
            base_type()
        { }

        template<class T>
        explicit AnyPtr(T *p) : 
            base_type(p)
        { }

        template<class T, class TD>
        AnyPtr(T *p, TD d) : 
            base_type(p, d)
        { }

        template<class T, class TD, class ImplD>
        explicit AnyPtr(AnyPtrDetail::AnyPtrHolderImpl<T, TD, ImplD> *pHolder) : 
            base_type(pHolder)
        { }

        AnyPtr(AnyPtr const &other) : 
            base_type(other)
        { }

        inline AnyPtr &operator =(AnyPtr &other)
        {
            base_type::operator =(other);
            return *this;
        }
    };

    //class AnyPtr
    //{
    //public:
    //    typedef AnyPtrDetail::AnyPtrHolder holder_type;

    //    AnyPtr() : 
    //        m_pHolder(NULL)
    //    { }

    //    template<class PointerType>
    //    AnyPtr(PointerType p) : 
    //        m_pHolder(new AnyPtrDetail::PointerHolder<PointerType>(p))
    //    { }

    //    AnyPtr(AnyPtr const &other) : 
    //        m_pHolder(other.IsEmpty() ? NULL : other.m_pHolder->Clone())
    //    { }

    //    ~AnyPtr() 
    //    { 
    //        if (m_pHolder != NULL)
    //            delete m_pHolder;
    //    }

    //    inline bool IsEmpty() const { return m_pHolder == NULL; }

    //    template<class PointerType>
    //    inline bool Is() const 
    //    {
    //        return !IsEmpty() && 
    //               typeid(typename AnyPtrDetail::PointerHolder<PointerType>::pointer_type) == m_pHolder->GetType();
    //    }
    //    
    //    inline AnyPtr &Swap(AnyPtr &other) 
    //    { 
    //        std::swap(m_pHolder, other.m_pHolder); 
    //        return *this; 
    //    }

    //    inline AnyPtr &operator =(AnyPtr &other)
    //    {
    //        other.Swap(*this);
    //        return *this;
    //    }

    //    template<class PointerType>
    //    inline AnyPtr &operator =(PointerType p)
    //    {
    //        AnyPtr(p).Swap(*this);
    //        return *this;
    //    }

    //    template<class PointerType>
    //    inline operator PointerType()
    //    {
    //        typedef typename AnyPtrDetail::PointerHolder<PointerType>::type HolderType;
    //        return Is<PointerType>() ? static_cast<HolderType *>(m_pHolder)->m_p : NULL;
    //    }

    //private:
    //    holder_type *m_pHolder;
    //};

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_ANYPTR_HPP