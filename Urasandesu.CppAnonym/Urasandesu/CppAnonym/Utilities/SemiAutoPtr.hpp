#pragma once
#ifndef URASANDESU_CPPANONYM_UTILITIES_SEMIAUTOPTR_HPP
#define URASANDESU_CPPANONYM_UTILITIES_SEMIAUTOPTR_HPP

#ifndef URASANDESU_CPPANONYM_UTILITIES_DEFAULTDELETER_HPP
#include <Urasandesu/CppAnonym/Utilities/DefaultDeleter.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_DELETIONSWITCHABLEPOLICY_HPP
#include <Urasandesu/CppAnonym/Utilities/DeletionSwitchablePolicy.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_SEMIAUTOPTRFWD_HPP
#include <Urasandesu/CppAnonym/Utilities/SemiAutoPtrFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    namespace SemiAutoPtrDetail {

        namespace mpl = boost::mpl;
        using namespace boost;

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

        template<class T, class TD, class ImplD>
        struct SemiAutoPtrHolderImpl : 
            SemiAutoPtrHolder
        {
            typedef SemiAutoPtrHolderImpl<T, TD, ImplD> this_type;
            typedef SemiAutoPtrHolder base_type;
            typedef DeletionSwitchablePolicy<TD> deletion_switchable_deleter;

            explicit SemiAutoPtrHolderImpl(T *p) : 
                base_type(), 
                m_p(p),
                m_td(deletion_switchable_deleter(TD())), 
                m_impld(ImplD())
            { 
                _ASSERTE(p != NULL); 
            }

            SemiAutoPtrHolderImpl(T *p, TD td) : 
                base_type(), 
                m_p(p),
                m_td(deletion_switchable_deleter(td)), 
                m_impld(ImplD())
            { 
                _ASSERTE(p != NULL); 
            }

            SemiAutoPtrHolderImpl(T *p, TD td, ImplD impld) : 
                base_type(), 
                m_p(p),
                m_td(deletion_switchable_deleter(td)), 
                m_impld(impld)
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
                m_td(m_p);
                m_impld(this);
            }

            virtual void EnableDeletion()
            {
                m_td.EnableDeletion();
            }

            virtual void DisableDeletion()
            {
                m_td.DisableDeletion();
            }

            T *m_p;
            mutable deletion_switchable_deleter m_td;
            ImplD m_impld;
        };

        template<class T>
        class SemiAutoPtrImpl
        {
        public:
            typedef SemiAutoPtrImpl<T> this_type;
            typedef SemiAutoPtrHolder holder_type;

            template<class TD, class ImplD>
            struct holder_impl_type
            {
                typedef SemiAutoPtrHolderImpl<T, TD, ImplD> type;
            };

            typedef T element_type;
            typedef T value_type;
            typedef T *pointer;
            typedef T &reference;

            SemiAutoPtrImpl() : 
                m_pHolder()
            { }

            explicit SemiAutoPtrImpl(T *p) : 
                m_pHolder(new holder_impl_type<DefaultDeleter, DefaultDeleter>::type(p))
            { }

            template<class TD>
            SemiAutoPtrImpl(T *p, TD td) : 
                m_pHolder(new holder_impl_type<TD, DefaultDeleter>::type(p, td))
            { }

            template<class TD, class ImplD>
            SemiAutoPtrImpl(typename holder_impl_type<TD, ImplD>::type *pHolder) : 
                m_pHolder(pHolder)
            {
                _ASSERTE(pHolder != NULL); 
            }

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

        template<class TD>
        SemiAutoPtr(T *p, TD td) : 
            base_type(p, td)
        { }

        template<class TD, class ImplD>
        explicit SemiAutoPtr(SemiAutoPtrDetail::SemiAutoPtrHolderImpl<T, TD, ImplD> *pHolder) : 
            base_type(pHolder)
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