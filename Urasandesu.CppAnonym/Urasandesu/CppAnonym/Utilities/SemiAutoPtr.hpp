#pragma once
#ifndef URASANDESU_CPPANONYM_UTILITIES_SEMIAUTOPTR_HPP
#define URASANDESU_CPPANONYM_UTILITIES_SEMIAUTOPTR_HPP

#ifndef URASANDESU_CPPANONYM_UTILITIES_AUTOPTR_HPP
#include <Urasandesu/CppAnonym/Utilities/AutoPtr.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_HEAPDELETER_HPP
#include <Urasandesu/CppAnonym/Utilities/HeapDeleter.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_DELETIONSWITCHABLEPOLICY_HPP
#include <Urasandesu/CppAnonym/Utilities/DeletionSwitchablePolicy.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_SEMIAUTOPTRFWD_HPP
#include <Urasandesu/CppAnonym/Utilities/SemiAutoPtrFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    namespace SemiAutoPtrDetail {

        using namespace boost;
        using namespace Urasandesu::CppAnonym::Utilities::AutoPtrDetail;

        struct SemiAutoPtrHolder
        {
            typedef SemiAutoPtrHolder this_type;

            SemiAutoPtrHolder() : m_useCount(0) { }
            virtual ~SemiAutoPtrHolder() { };
            virtual void *Pointer() const = 0;
            virtual void Delete() = 0;
            virtual void EnableDeletion() = 0;
            virtual void DisableDeletion() = 0;

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
        struct SemiAutoPtrHolderImpl : 
            SemiAutoPtrHolder
        {
            typedef SemiAutoPtrHolderImpl<T, D> this_type;
            typedef SemiAutoPtrHolderImplFactory<T, D> holder_factory_type;
            typedef DeletionSwitchablePolicy<D> deletion_switchable_deleter;

            typedef SimpleHeap<T, QuickHeapWithoutSubscriptOperator> object_heap_type;
            typedef HeapDeleter<object_heap_type> object_heap_deleter_type;
            typedef SemiAutoPtrHolderImpl<T, object_heap_deleter_type> holder_impl_type;

            typedef typename mpl::eval_if<
                CPP_ANONYM_HAS_MEMBER_TYPE(SemiAutoPtrImpl, factory_type, T), 
                CPP_ANONYM_GET_MEMBER_TYPE(SemiAutoPtrImpl, factory_type, T), 
                mpl::identity<void>
            >::type factory_type;

            explicit SemiAutoPtrHolderImpl(T *p) : 
                SemiAutoPtrHolder(), 
                m_p(p),
                m_d(deletion_switchable_deleter(D()))
            { 
                _ASSERTE(p != NULL); 
            }

            SemiAutoPtrHolderImpl(T *p, D d) : 
                SemiAutoPtrHolder(), 
                m_p(p),
                m_d(deletion_switchable_deleter(d))
            { 
                _ASSERTE(p != NULL); 
            }

            virtual ~SemiAutoPtrHolderImpl()
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
                //factory_type::Delete<holder_impl_type>(this);   // [2012/09/11 08:02:32] この辺実装中。。。
                //SemiAutoPtrHolderImplFactory<T, D>::Heap().Delete(this);
            }

            virtual void EnableDeletion()
            {
                m_d.EnableDeletion();
            }

            virtual void DisableDeletion()
            {
                m_d.DisableDeletion();
            }

            T *m_p;
            mutable deletion_switchable_deleter m_d;
        };

        //template<class T, class D>
        //struct SemiAutoPtrHolderImplFactory
        //{
        //    typedef SemiAutoPtrHolderImpl<T, D> holder_type;
        //    typedef SimpleHeap<holder_type, QuickHeapWithoutSubscriptOperator> holder_heap_type;
        //    static holder_heap_type &Heap() { static holder_heap_type heap; return heap; }
        //};

        template<class T>
        class SemiAutoPtrImpl
        {
        public:
            typedef SemiAutoPtrImpl<T> this_type;
            typedef SemiAutoPtrHolder holder_type;
            typedef SimpleHeap<T, QuickHeapWithoutSubscriptOperator> object_heap_type;
            typedef HeapDeleter<object_heap_type> object_heap_deleter_type;
            typedef SemiAutoPtrHolderImpl<T, object_heap_deleter_type> holder_impl_type;

            typedef SemiAutoPtrHolderImpl<T, DefaultDeleter> default_holder_impl_type;

            typedef typename mpl::eval_if<
                CPP_ANONYM_HAS_MEMBER_TYPE(SemiAutoPtrImpl, factory_type, T), 
                CPP_ANONYM_GET_MEMBER_TYPE(SemiAutoPtrImpl, factory_type, T), 
                mpl::identity<void>
            >::type factory_type;

            typedef T element_type;
            typedef T value_type;
            typedef T *pointer;
            typedef T &reference;

            SemiAutoPtrImpl() : 
                m_pHolder()
            { }

            explicit SemiAutoPtrImpl(T *p) : 
                m_pHolder(/*factory_type::New<default_holder_impl_type>(p)*/ new SemiAutoPtrHolderImpl<T, DefaultDeleter>(p) /*SemiAutoPtrHolderImplFactory<T, DefaultDeleter>::Heap().New(p)*/)
            { }

            template<class D>
            SemiAutoPtrImpl(T *p, D d) : 
                m_pHolder(/*factory_type::New<holder_impl_type>(p, d)*/ new SemiAutoPtrHolderImpl<T, D>(p, d) /*SemiAutoPtrHolderImplFactory<T, D>::Heap().New(p, d)*/)
            { }

            template<class U>
            SemiAutoPtrImpl(SemiAutoPtrImpl<U> const &other) : 
                m_pHolder(SemiAutoPtrHolderAccessor<U>::Get(other))
            { }

            inline SemiAutoPtrImpl &operator =(SemiAutoPtrImpl &other)
            {
                m_pHolder = other.m_pHolder;
                return *this;
            }

            template<class U>
            inline SemiAutoPtrImpl &operator =(SemiAutoPtrImpl<U> &other)
            {
                m_pHolder = SemiAutoPtrHolderAccessor<U>::Get(other);
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

            inline void SetAuto()
            {
                m_pHolder->EnableDeletion();
            }

            inline void SetManual()
            {
                m_pHolder->DisableDeletion();
            }

        protected:
            SemiAutoPtrImpl(intrusive_ptr<holder_type> const &pHolder) : 
                m_pHolder(pHolder)
            { }

            intrusive_ptr<holder_type> m_pHolder;

        private:
            template<class U> friend struct SemiAutoPtrHolderAccessor;
        };

        template<class U> 
        struct SemiAutoPtrHolderAccessor
        {
            typedef typename SemiAutoPtrImpl<U>::holder_type holder_type;

            static intrusive_ptr<holder_type> const &Get(SemiAutoPtrImpl<U> const &p)
            {
                return p.m_pHolder;
            }
        };

    }   // namespace SemiAutoPtrDetail {

    template<class T>
    class SemiAutoPtr : 
        public SemiAutoPtrDetail::SemiAutoPtrImpl<T>
    {
    public:
        typedef SemiAutoPtr<T> this_type;
        typedef SemiAutoPtrDetail::SemiAutoPtrImpl<T> base_type;

        SemiAutoPtr() : 
            base_type()
        { }

        explicit SemiAutoPtr(T *p) : 
            base_type(p)
        { }

        template<class D>
        SemiAutoPtr(T *p, D d) : 
            base_type(p, d)
        { }

        template<class U>
        SemiAutoPtr(SemiAutoPtr<U> const &other) : 
            base_type(other)
        { }

        inline SemiAutoPtr &operator =(SemiAutoPtr &other)
        {
            base_type::operator =(other);
            return *this;
        }

        template<class U>
        inline SemiAutoPtr &operator =(SemiAutoPtr<U> &other)
        {
            base_type::operator =(other);
            return *this;
        }
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_SEMIAUTOPTR_HPP