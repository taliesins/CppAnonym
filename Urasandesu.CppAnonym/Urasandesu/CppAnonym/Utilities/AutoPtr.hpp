#pragma once
#ifndef URASANDESU_CPPANONYM_UTILITIES_AUTOPTR_HPP
#define URASANDESU_CPPANONYM_UTILITIES_AUTOPTR_HPP

#ifndef URASANDESU_CPPANONYM_UTILITIES_DELETIONSWITCHABLEPOLICY_HPP
#include <Urasandesu/CppAnonym/Utilities/DeletionSwitchablePolicy.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_DEFAULTDELETER_HPP
#include <Urasandesu/CppAnonym/Utilities/DefaultDeleter.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_AUTOPTRFWD_HPP
#include <Urasandesu/CppAnonym/Utilities/AutoPtrFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    namespace AutoPtrDetail {

        using namespace boost;

        struct Holder
        {
            typedef Holder this_type;

            Holder() : m_useCount(0) { }
            virtual ~Holder() { };
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

        template<class U> 
        struct HolderAccessor
        {
            typedef typename AutoPtrImpl<U>::holder_type holder_type;

            static intrusive_ptr<holder_type> const &GetHolder(AutoPtrImpl<U> const &p)
            {
                return p.m_pHolder;
            }
        };

        template<class T, class D>
        struct HolderImpl : 
            Holder
        {
            typedef HolderImpl<T, D> this_type;
            typedef HolderImplFactory<T, D> holder_factory_type;
            typedef DeletionSwitchablePolicy<D> deletion_switchable_deleter;

            explicit HolderImpl(T *p) : 
                Holder(), 
                m_p(p),
                m_dsd(deletion_switchable_deleter(D()))
            { 
                _ASSERTE(p != NULL); 
            }

            HolderImpl(T *p, D d) : 
                Holder(), 
                m_p(p),
                m_dsd(deletion_switchable_deleter(d))
            { 
                _ASSERTE(p != NULL); 
            }

            virtual ~HolderImpl()
            {
            }

            virtual void *Pointer() const
            {
                return m_p;
            }

            virtual void Delete()
            {
                m_dsd(m_p);
                HolderImplFactory<T, D>::Heap().Delete(this);
            }

            virtual void EnableDeletion()
            {
                m_dsd.EnableDeletion();
            }

            virtual void DisableDeletion()
            {
                m_dsd.DisableDeletion();
            }

            T *m_p;
            mutable deletion_switchable_deleter m_dsd;
        };

        template<class T, class D>
        struct HolderImplFactory
        {
            typedef HolderImpl<T, D> holder_type;
            typedef SimpleHeap<holder_type, QuickHeapWithoutSubscriptOperator> holder_heap_type;
            static holder_heap_type &Heap() { static holder_heap_type heap; return heap; }
        };

        template<class T>
        class AutoPtrImpl
        {
        public:
            typedef AutoPtrImpl<T> this_type;
            typedef Holder holder_type;

            typedef T element_type;
            typedef T value_type;
            typedef T *pointer;
            typedef T &reference;

            AutoPtrImpl() : 
                m_pHolder()
            { }

            explicit AutoPtrImpl(T *p) : 
                m_pHolder(HolderImplFactory<T, DefaultDeleter>::Heap().New(p))
            { }

            template<class D>
            AutoPtrImpl(T *p, D d) : 
                m_pHolder(HolderImplFactory<T, D>::Heap().New(p, d))
            { }

            template<class U>
            AutoPtrImpl(AutoPtrImpl<U> const &other) : 
                m_pHolder(HolderAccessor<U>::GetHolder(other))
            { }

            inline AutoPtrImpl &operator =(AutoPtrImpl &other)
            {
                m_pHolder = other.m_pHolder;
                return *this;
            }

            template<class U>
            inline AutoPtrImpl &operator =(AutoPtrImpl<U> &other)
            {
                m_pHolder = HolderAccessor<U>::GetHolder(other);
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
            intrusive_ptr<holder_type> m_pHolder;

        private:
            template<class U> friend struct HolderAccessor;
        };

        struct PersisterHolder
        {
            typedef PersisterHolder this_type;

            PersisterHolder() : m_useCount(0) { }
            virtual ~PersisterHolder() { };
            virtual void operator()(void *p) = 0;
            virtual void Delete() = 0;

            inline friend void intrusive_ptr_add_ref(this_type *p)
            {
                ++p->m_useCount;
            }

            inline friend void intrusive_ptr_release(this_type *p)
            {
                if(--p->m_useCount == 0) p->Delete();
            }

            LONG m_useCount;
        };

        template<class Persister>
        struct PersisterHolderImpl : 
            PersisterHolder
        {
            typedef PersisterHolderImpl<Persister> this_type;
            typedef PersisterHolder base_type;

            PersisterHolderImpl(Persister persister) : 
                base_type(),
                m_persister(persister)
            { }
            
            virtual ~PersisterHolderImpl() 
            { 
            }

            virtual void operator()(void *p)
            {
                m_persister(p);
            }

            virtual void Delete()
            {
                PersisterHolderImplFactory<Persister>::Heap().Delete(this);
            }

            Persister m_persister;
        };

        template<class Persister>
        struct PersisterHolderImplFactory
        {
            typedef PersisterHolderImpl<Persister> holder_type;
            typedef SimpleHeap<holder_type, QuickHeapWithoutSubscriptOperator> holder_heap_type;
            static holder_heap_type &Heap() { static holder_heap_type heap; return heap; }
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
    };

    //template<class T>
    //class SemiAutoPtr : 
    //    public AutoPtr<T>
    //{
    //public:
    //    typedef SemiAutoPtr<T> this_type;
    //    typedef AutoPtr<T> base_type;

    //    SemiAutoPtr() : 
    //        base_type()
    //    { }

    //    explicit SemiAutoPtr(T *p) : 
    //        base_type(p)
    //    { }

    //    template<class D>
    //    SemiAutoPtr(T *p, D d) : 
    //        base_type(p, d)
    //    { }

    //    template<class U>
    //    SemiAutoPtr(SemiAutoPtr<U> const &other) : 
    //        base_type(other)
    //    { }

    //    inline SemiAutoPtr &operator =(SemiAutoPtr &other)
    //    {
    //        base_type::operator =(other);
    //        return *this;
    //    }

    //    template<class U>
    //    inline SemiAutoPtr &operator =(SemiAutoPtr<U> &other)
    //    {
    //        base_type::operator =(other);
    //        return *this;
    //    }

    //    inline void SetAuto()
    //    {
    //        m_pHolder->EnableDeletion();
    //    }

    //    inline void SetManual()
    //    {
    //        m_pHolder->DisableDeletion();
    //    }
    //};

    //template<class T>
    //class TempPtr : 
    //    public SemiAutoPtr<T>
    //{
    //public:
    //    typedef TempPtr<T> this_type;
    //    typedef SemiAutoPtr<T> base_type;
    //    typedef AutoPtrDetail::PersisterHolder persister_holder_type;

    //    TempPtr() : 
    //        base_type(),
    //        m_isPersisted(false)
    //    { }

    //    explicit TempPtr(T *p) : 
    //        base_type(p),
    //        m_isPersisted(false)
    //    { }

    //    template<class D>
    //    TempPtr(T *p, D d) : 
    //        base_type(p, d),
    //        m_isPersisted(false)
    //    { }

    //    template<class U>
    //    TempPtr(TempPtr<U> const &other) : 
    //        base_type(other),
    //        m_isPersisted(other.IsPersisted())
    //    { }

    //    inline TempPtr &operator =(TempPtr &other)
    //    {
    //        base_type::operator =(other);
    //        m_isPersisted = other.IsPersisted();
    //        return *this;
    //    }

    //    template<class U>
    //    inline TempPtr &operator =(TempPtr<U> &other)
    //    {
    //        base_type::operator =(other);
    //        m_isPersisted = other.IsPersisted();
    //        return *this;
    //    }

    //    inline bool IsPersisted() const
    //    {
    //        return m_isPersisted;
    //    }

    //    inline void Persist()
    //    {
    //        if (!m_isPersisted)
    //        {
    //            base_type::SetManual();
    //            m_isPersisted = true;
    //            if (m_pPersisterHolder)
    //                (*m_pPersisterHolder)(this);
    //        }
    //    }

    //    template<class Persister>
    //    inline void SetPersister(Persister persister)
    //    {
    //        _ASSERTE(!m_pPersisterHolder);
    //        m_pPersisterHolder = AutoPtrDetail::PersisterHolderImplFactory<Persister>::Heap().New(persister);
    //    }

    //private:
    //    void SetAuto();
    //    void SetManual();
    //    bool m_isPersisted;
    //    boost::intrusive_ptr<persister_holder_type> m_pPersisterHolder;
    //};

    //template<class T>
    //class TempPtrVector
    //{
    //public:
    //    typedef TempPtrVector<T> this_type;

    //    typedef std::vector<TempPtr<T> > temp_ptr_vector_type;
    //    typedef typename temp_ptr_vector_type::size_type size_type;
    //    typedef T *pointer;
    //    typedef T const *const_pointer;
    //    typedef T const *&const_reference;
    //    typedef T *&reference;
    //    typedef typename temp_ptr_vector_type::value_type value_type;

	   // inline void reserve(size_type size)
    //    {
    //        m_vec.reserve(size);
    //    }

    //    inline void push_back(typename boost::call_traits<value_type>::param_type val)
    //    {
    //        m_vec.push_back(val);
    //    };

    //    inline const_pointer operator[](size_type pos) const
    //    {
    //        TempPtr<T> &p = const_cast<TempPtr<T> &>(m_vec[pos]);
    //        if (!p.IsPersisted())
    //            p.Persist();
    //        return p.Get();
    //    }

    //    inline pointer operator[](size_type pos)
    //    {
    //        BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
    //    }

    //    inline size_type size() const
    //    {
    //        return m_vec.size();
    //    }

	   // inline bool empty() const
    //    {
    //        return m_vec.empty();
    //    }

    //private:
    //    temp_ptr_vector_type m_vec;
    //};

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_AUTOPTR_HPP