#pragma once
#ifndef URASANDESU_CPPANONYM_UTILITIES_AUTOPTR_HPP
#define URASANDESU_CPPANONYM_UTILITIES_AUTOPTR_HPP

#ifndef URASANDESU_CPPANONYM_UTILITIES_DEFAULTDELETER_HPP
#include <Urasandesu/CppAnonym/Utilities/DefaultDeleter.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_AUTOPTRFWD_HPP
#include <Urasandesu/CppAnonym/Utilities/AutoPtrFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    namespace AutoPtrDetail {

        using namespace boost;

        struct AutoPtrHolder
        {
            typedef AutoPtrHolder this_type;

            AutoPtrHolder() : m_useCount(0) { }
            virtual ~AutoPtrHolder() { };
            virtual void *Pointer() const = 0;
            virtual void Delete() = 0;

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
        };

        template<class T, class D>
        struct AutoPtrHolderImpl : 
            AutoPtrHolder
        {
            typedef AutoPtrHolderImpl<T, D> this_type;
            typedef AutoPtrHolderImplFactory<T, D> holder_factory_type;

            explicit AutoPtrHolderImpl(T *p) : 
                AutoPtrHolder(), 
                m_p(p),
                m_d(D())
            { 
                _ASSERTE(p != NULL); 
            }

            AutoPtrHolderImpl(T *p, D d) : 
                AutoPtrHolder(), 
                m_p(p),
                m_d(d)
            { 
                _ASSERTE(p != NULL); 
            }

            virtual ~AutoPtrHolderImpl()
            {
            }

            virtual void *Pointer() const
            {
                return m_p;
            }

            virtual void Delete()
            {
                m_d(m_p);
                delete this;
                //AutoPtrHolderImplFactory<T, D>::Heap().Delete(this);
            }

            T *m_p;
            mutable D m_d;
        };

        //template<class T, class D>
        //struct AutoPtrHolderImplFactory
        //{
        //    typedef AutoPtrHolderImpl<T, D> holder_type;
        //    typedef SimpleHeap<holder_type, QuickHeapWithoutSubscriptOperator> holder_heap_type;
        //    static holder_heap_type &Heap() { static holder_heap_type heap; return heap; }
        //};

        template<class T>
        class AutoPtrImpl
        {
        public:
            typedef AutoPtrImpl<T> this_type;
            typedef AutoPtrHolder holder_type;

            typedef T element_type;
            typedef T value_type;
            typedef T *pointer;
            typedef T &reference;

            AutoPtrImpl() : 
                m_pHolder()
            { }

            explicit AutoPtrImpl(T *p) : 
                m_pHolder(new AutoPtrHolderImpl<T, DefaultDeleter>(p) /*AutoPtrHolderImplFactory<T, DefaultDeleter>::Heap().New(p)*/)
            { }

            template<class D>
            AutoPtrImpl(T *p, D d) : 
                m_pHolder(new AutoPtrHolderImpl<T, D>(p, d) /*AutoPtrHolderImplFactory<T, D>::Heap().New(p, d)*/)
            { }

            template<class U>
            AutoPtrImpl(AutoPtrImpl<U> const &other) : 
                m_pHolder(AutoPtrHolderAccessor<U>::Get(other))
            { }

            inline AutoPtrImpl &operator =(AutoPtrImpl &other)
            {
                m_pHolder = other.m_pHolder;
                return *this;
            }

            template<class U>
            inline AutoPtrImpl &operator =(AutoPtrImpl<U> &other)
            {
                m_pHolder = AutoPtrHolderAccessor<U>::Get(other);
                return *this;
            }

            inline operator bool() const
            {
                return m_pHolder;
            }

            bool operator !() const
            {
                return !m_pHolder;
            }

            inline pointer operator->()
            {
                return Get();
            }

            inline pointer Get() const
            {
                return static_cast<pointer>(m_pHolder->Pointer());
            }

            inline reference operator *()
            {
                pointer p = Get();
                _ASSERTE(p != NULL);
                return *p;
            }

        protected:
            AutoPtrImpl(intrusive_ptr<holder_type> const &pHolder) : 
                m_pHolder(pHolder)
            { }

            intrusive_ptr<holder_type> m_pHolder;

        private:
            template<class U> friend struct AutoPtrHolderAccessor;
        };

        template<class U> 
        struct AutoPtrHolderAccessor
        {
            typedef typename AutoPtrImpl<U>::holder_type holder_type;

            static intrusive_ptr<holder_type> const &Get(AutoPtrImpl<U> const &p)
            {
                return p.m_pHolder;
            }
        };

    }   // namespace AutoPtrDetail {

    template<class T>
    struct AutoPtr : 
        AutoPtrDetail::AutoPtrImpl<T>
    {
        typedef AutoPtr<T> this_type;
        typedef AutoPtrDetail::AutoPtrImpl<T> base_type;

        AutoPtr() : 
            base_type()
        { }

        explicit AutoPtr(T *p) : 
            base_type(p)
        { }

        template<class D>
        AutoPtr(T *p, D d) : 
            base_type(p, d)
        { }

        template<class U>
        AutoPtr(AutoPtr<U> const &other) : 
            base_type(other)
        { }

        inline AutoPtr &operator =(AutoPtr &other)
        {
            base_type::operator =(other);
            return *this;
        }

        template<class U>
        inline AutoPtr &operator =(AutoPtr<U> &other)
        {
            base_type::operator =(other);
            return *this;
        }

    protected:
        AutoPtr(boost::intrusive_ptr<holder_type> const &pHolder) : 
            base_type(pHolder)
        { }
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_AUTOPTR_HPP