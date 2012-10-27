#pragma once
#ifndef URASANDESU_CPPANONYM_UTILITIES_TEMPPTR_HPP
#define URASANDESU_CPPANONYM_UTILITIES_TEMPPTR_HPP

#ifndef URASANDESU_CPPANONYM_CPPANONYMNOTSUPPORTEDEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymNotSupportedException.h>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_DEFAULTDELETER_HPP
#include <Urasandesu/CppAnonym/Utilities/DefaultDeleter.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_MAKEPOINTERHOLDERIMPL_H
#include <Urasandesu/CppAnonym/Traits/MakePointerHolderImpl.h>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_MAKEHEAPPOINTERHOLDERIMPL_H
#include <Urasandesu/CppAnonym/Traits/MakeHeapPointerHolderImpl.h>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_MAKEVALUEHOLDERIMPL_H
#include <Urasandesu/CppAnonym/Traits/MakeValueHolderImpl.h>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_MAKEHEAPVALUEHOLDERIMPL_H
#include <Urasandesu/CppAnonym/Traits/MakeHeapValueHolderImpl.h>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_VARIANTPTR_HPP
#include <Urasandesu/CppAnonym/Utilities/VariantPtr.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_DELETIONSWITCHABLEPOLICY_HPP
#include <Urasandesu/CppAnonym/Utilities/DeletionSwitchablePolicy.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_TEMPPTRFWD_HPP
#include <Urasandesu/CppAnonym/Utilities/TempPtrFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    namespace TempPtrDetail {

        using namespace boost;
        using namespace Urasandesu::CppAnonym::Traits;

        struct TempPtrHolder
        {
            typedef TempPtrHolder this_type;

            TempPtrHolder() : m_useCount(0) { }
            virtual ~TempPtrHolder() { };
            virtual void *Pointer() const = 0;
            virtual void Delete() = 0;
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
        struct TempPtrHolderImpl : 
            TempPtrHolder
        {
            typedef TempPtrHolderImpl<T, TD, ImplD> this_type;
            typedef TempPtrHolder base_type;
            typedef T object_type;
            typedef DeletionSwitchablePolicy<TD> object_deleter_type;
            typedef ImplD impl_deleter_type; 

            TempPtrHolderImpl(object_type *p, object_deleter_type d, impl_deleter_type impld) : 
                base_type(), 
                m_p(p),
                m_d(d),
                m_impld(impld)
            { 
                _ASSERTE(p != NULL); 
            }

            virtual ~TempPtrHolderImpl()
            {
            }

            virtual void *Pointer() const
            {
                return const_cast<typename RemoveConst<object_type>::type *>(m_p);
            }

            virtual void Delete()
            {
                m_d(m_p);
                m_impld(this);
            }

            virtual void DisableDeletion()
            {
                m_d.DisableDeletion();
            }

            object_type *m_p;
            mutable object_deleter_type m_d;
            impl_deleter_type m_impld;
        };

        template<class T, class TD, class ImplD>
        struct MakeHolderImpl : 
            Traits::MakePointerHolderImpl<T, TD, ImplD, TempPtrHolderImpl>
        {
        };

        template<
            class T, 
            class Tag
        >
        struct MakeHeapHolderImpl : 
            Traits::MakeHeapPointerHolderImpl<T, TempPtrHolderImpl, Tag>
        {
        };

        struct PersistedHandlerHolder
        {
            typedef PersistedHandlerHolder this_type;

            PersistedHandlerHolder() : m_useCount(0) { }
            virtual ~PersistedHandlerHolder() { };
            virtual void operator()(void *pSender, void *pArg) = 0;
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

        template<class Handler, class ImplD>
        struct PersistedHandlerHolderImpl : 
            PersistedHandlerHolder
        {
            typedef PersistedHandlerHolderImpl<Handler, ImplD> this_type;
            typedef PersistedHandlerHolder base_type;

            typedef typename mpl::eval_if<
                CPP_ANONYM_HAS_MEMBER_TYPE(PersistedHandlerSender, Handler), 
                CPP_ANONYM_GET_MEMBER_TYPE(PersistedHandlerSender, Handler), 
                mpl::identity<void>
            >::type sender_type;

            typedef typename mpl::eval_if<
                CPP_ANONYM_HAS_MEMBER_TYPE(PersistedHandlerArg, Handler), 
                CPP_ANONYM_GET_MEMBER_TYPE(PersistedHandlerArg, Handler), 
                mpl::identity<void>
            >::type arg_type;

            PersistedHandlerHolderImpl(Handler handler) : 
                base_type(),
                m_handler(handler),
                m_impld(ImplD())
            { }

            PersistedHandlerHolderImpl(Handler handler, ImplD impld) : 
                base_type(), 
                m_handler(handler),
                m_impld(impld)
            { }
            
            virtual ~PersistedHandlerHolderImpl() 
            { 
            }

            virtual void operator()(void *pSender, void *pArg)
            {
                m_handler(static_cast<sender_type *>(pSender), static_cast<arg_type *>(pArg));
            }

            virtual void Delete()
            {
                m_impld(this);
            }

            Handler m_handler;
            ImplD m_impld;
        };

        template<class Handler, class ImplD>
        struct MakePersistedHandlerHolderImpl : 
            Traits::MakeValueHolderImpl<Handler, ImplD, PersistedHandlerHolderImpl>
        {
        };

        template<
            class Handler, 
            class Tag
        >
        struct MakeHeapPersistedHandlerHolderImpl : 
            Traits::MakeHeapValueHolderImpl<Handler, PersistedHandlerHolderImpl, Tag>
        {
        };

        template<class T>
        class TempPtrImpl
        {
        public:
            typedef TempPtrImpl<T> this_type;
            typedef TempPtrHolder holder_type;
            typedef PersistedHandlerHolder persisted_handler_holder_type;
            typedef VariantPtr<intrusive_ptr<holder_type>, T *> variant_holder_type;
            typedef TempPtrStates state_type;
            typedef Collections::RapidVector<intrusive_ptr<persisted_handler_holder_type>, 1 > persisted_handlers_type;

            template<class TD, class ImplD>
            struct make_holder_impl : 
                MakeHolderImpl<T, TD, ImplD>
            {
            };

            template<class Tag = QuickHeapWithoutSubscriptOperator>
            struct make_heap_holder_impl : 
                MakeHeapHolderImpl<T, Tag>
            {
            };

            template<class Handler, class ImplD>
            struct make_persisted_handler_holder_impl : 
                MakePersistedHandlerHolderImpl<Handler, ImplD>
            {
            };

            template<class Handler, class Tag = QuickHeapWithoutSubscriptOperator>
            struct make_heap_persisted_handler_holder_impl : 
                MakeHeapPersistedHandlerHolderImpl<Handler, Tag>
            {
            };

            TempPtrImpl() : 
                m_pHolder(),
                m_state(TempPtrStates::TPS_NONE),
                m_persistedHandlers()
            { }

            TempPtrImpl(T *p, bool hasAlreadyPersisted) : 
                m_pHolder(),
                m_state(!hasAlreadyPersisted ? TempPtrStates::TPS_NONE : TempPtrStates::TPS_HAS_ALREADY_PERSISTED),
                m_persistedHandlers()
            { 
                if (!hasAlreadyPersisted)
                    m_pHolder.Set<intrusive_ptr<holder_type> >(new TempPtrHolderImpl<T, DefaultDeleter, DefaultDeleter>(p, DefaultDeleter(), DefaultDeleter()));
                else
                    m_pHolder.Set<T *>(p);
            }

            template<class TD>
            TempPtrImpl(T *p, TD td) : 
                m_pHolder(),
                m_state(TempPtrStates::TPS_NONE),
                m_persistedHandlers()
            { 
                m_pHolder.Set<intrusive_ptr<holder_type> >(new TempPtrHolderImpl<T, TD, DefaultDeleter>(p, td, DefaultDeleter()));
            }

            template<class TD, class ImplD>
            TempPtrImpl(TempPtrHolderImpl<T, TD, ImplD> *pHolder) : 
                m_pHolder(),
                m_state(TempPtrStates::TPS_NONE),
                m_persistedHandlers()
            { 
                m_pHolder.Set<intrusive_ptr<holder_type> >(pHolder);
            }

            TempPtrImpl(this_type const &other) : 
                m_pHolder(),
                m_state(!other.IsPersisted() ? TempPtrStates::TPS_NONE : TempPtrStates::TPS_HAS_ALREADY_PERSISTED),
                m_persistedHandlers(other.m_persistedHandlers)
            { 
                if (!other.IsPersisted())
                    m_pHolder.Assign<intrusive_ptr<holder_type> >(other.m_pHolder);
                else
                    m_pHolder.Set<T *>(other.Get());
            }

            template<class U>
            TempPtrImpl(TempPtrImpl<U> const &other) : 
                m_pHolder(),
                m_state(!other.IsPersisted() ? TempPtrStates::TPS_NONE : TempPtrStates::TPS_HAS_ALREADY_PERSISTED),
                m_persistedHandlers(PersistedHandlersAccessor<U>::Get(other))
            { 
                if (!other.IsPersisted())
                    m_pHolder.Assign<intrusive_ptr<holder_type> >(TempPtrHolderAccessor<U>::Get(other));
                else
                    m_pHolder.Set<T *>(other.Get());
            }

            ~TempPtrImpl()
            {
                switch (m_state.Value())
                {
                    case TempPtrStates::TPS_NONE:
                    case TempPtrStates::TPS_PERSISTED:
                        m_pHolder.Clear<intrusive_ptr<holder_type> >();
                        break;
                    case TempPtrStates::TPS_HAS_ALREADY_PERSISTED:
                        m_pHolder.Clear<T *>();
                        break;
                    default:
                        BOOST_THROW_EXCEPTION(CppAnonymNotSupportedException());
                }
            }

            inline this_type &operator =(this_type &other)
            {
                if (this != &other)
                {
                    if (!other.IsPersisted())
                        m_pHolder.Assign<intrusive_ptr<holder_type> >(other.m_pHolder);
                    else
                        m_pHolder.Set<T *>(other.Get());

                    m_state = !other.IsPersisted() ? TempPtrStates::TPS_NONE : TempPtrStates::TPS_HAS_ALREADY_PERSISTED;
                    
                    m_persistedHandlers = other.m_persistedHandlers;
                }
                return *this;
            }

            template<class U>
            inline TempPtrImpl &operator =(TempPtrImpl<U> &other)
            {
                if (!other.IsPersisted())
                    m_pHolder.Assign<intrusive_ptr<holder_type> >(TempPtrHolderAccessor<U>::Get(other));
                else
                    m_pHolder.Set<T *>(other.Get());

                m_state = !other.IsPersisted() ? TempPtrStates::TPS_NONE : TempPtrStates::TPS_HAS_ALREADY_PERSISTED;
                    
                typedef typename PersistedHandlersAccessor<U>::persisted_handlers_type PersistedHandlers;
                PersistedHandlers const &persistedHandlers = PersistedHandlersAccessor<U>::Get(other);
                m_persistedHandlers.reserve(persistedHandlers.size());
                m_persistedHandlers.assign(persistedHandlers.cbegin(), persistedHandlers.cend());
                
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

            inline T *operator->()
            {
                return Get();
            }

            inline T *Get() const
            {
                switch (m_state.Value())
                {
                    case TempPtrStates::TPS_NONE:
                    case TempPtrStates::TPS_PERSISTED:
                        return static_cast<T *>(m_pHolder.Get<intrusive_ptr<holder_type> >()->Pointer());
                    case TempPtrStates::TPS_HAS_ALREADY_PERSISTED:
                        return m_pHolder.Get<T *>();
                    default:
                        BOOST_THROW_EXCEPTION(CppAnonymNotSupportedException());
                }
            }

            inline T &operator *()
            {
                T *p = Get();
                _ASSERTE(p != NULL);
                return *p;
            }

            inline bool IsPersisted() const
            {
                return m_state != TempPtrStates::TPS_NONE;
            }

            inline void Persist()
            {
                if (!IsPersisted())
                {
                    TempPtrStates lastState(m_state);
                    m_state = TempPtrStates::TPS_PERSISTED;
                    if (!m_persistedHandlers.empty())
                    {
                        try
                        {
                            typedef persisted_handlers_type::iterator Iterator;
                            for (Iterator i = m_persistedHandlers.begin(), i_end = m_persistedHandlers.end(); i != i_end; ++i)
                                (**i)(this, NULL);
                        }
                        catch (...)
                        {
                            m_state = lastState;
                            throw;
                        }
                    }
                    m_pHolder.Get<intrusive_ptr<holder_type> >()->DisableDeletion();
                }
            }

            template<class Handler>
            inline SIZE_T AddPersistedHandler(Handler handler)
            {
                m_persistedHandlers.push_back(new MakePersistedHandlerHolderImpl<Handler, DefaultDeleter>::type(handler));
                return m_persistedHandlers.size() - 1;
            }

            template<class Handler, class ImplD>
            inline SIZE_T AddPersistedHandler(PersistedHandlerHolderImpl<Handler, ImplD> *pPersistedHandlerHolder)
            {
                m_persistedHandlers.push_back(pPersistedHandlerHolder);
                return m_persistedHandlers.size() - 1;
            }

            inline void RemovePersistedHandler(SIZE_T id)
            {
                _ASSERTE(id < m_persistedHandlers.size());
                m_persistedHandlers.erace(m_persistedHandlers.begin() + id);
            }

        private:
            template<class U> friend struct TempPtrHolderAccessor;
            template<class U> friend struct PersistedHandlersAccessor;
            VariantPtr<intrusive_ptr<holder_type>, T *> m_pHolder;
            TempPtrStates m_state;
            persisted_handlers_type m_persistedHandlers;
        };

        template<class U> 
        struct TempPtrHolderAccessor
        {
            typedef typename TempPtrImpl<U>::variant_holder_type variant_holder_type;

            static variant_holder_type const &Get(TempPtrImpl<U> const &p)
            {
                return p.m_pHolder;
            }
        };

        template<class U> 
        struct PersistedHandlersAccessor
        {
            typedef typename TempPtrImpl<U>::persisted_handlers_type persisted_handlers_type;

            static persisted_handlers_type const &Get(TempPtrImpl<U> const &p)
            {
                return p.m_persistedHandlers;
            }
        };

    }   // namespace TempPtrDetail {

    template<class T>
    struct TempPtr : 
        TempPtrDetail::TempPtrImpl<T>
    {
        typedef TempPtr<T> this_type;
        typedef TempPtrDetail::TempPtrImpl<T> base_type;

        TempPtr() : 
            base_type()
        { }

        TempPtr(T *p, bool hasAlreadyPersisted = false) : 
            base_type(p, hasAlreadyPersisted)
        { }

        template<class TD>
        TempPtr(T *p, TD td) : 
            base_type(p, td)
        { }

        template<class TD, class ImplD>
        explicit TempPtr(TempPtrDetail::TempPtrHolderImpl<T, TD, ImplD> *pHolder) : 
            base_type(pHolder)
        {
        }

        TempPtr(this_type const &other) : 
            base_type(other)
        { }

        template<class U>
        TempPtr(TempPtr<U> const &other) : 
            base_type(other)
        { }

        ~TempPtr()
        {
        }

        inline TempPtr &operator =(TempPtr &other)
        {
            base_type::operator =(other);
            return *this;
        }

        template<class U>
        inline TempPtr &operator =(TempPtr<U> &other)
        {
            base_type::operator =(other);
            return *this;
        }
    };

    template<class T>
    class TempPtrVector
    {
    public:
        typedef TempPtrVector<T> this_type;

        typedef std::vector<TempPtr<T> > temp_ptr_vector_type;
        typedef typename temp_ptr_vector_type::size_type size_type;
        typedef T *pointer;
        typedef T const *const_pointer;
        typedef T const *&const_reference;
        typedef T *&reference;
        typedef typename temp_ptr_vector_type::value_type value_type;

	    inline void reserve(size_type size)
        {
            m_vec.reserve(size);
        }

        inline void push_back(typename boost::call_traits<value_type>::param_type val)
        {
            m_vec.push_back(val);
        };

        inline const_pointer operator[](size_type pos) const
        {
            TempPtr<T> &p = const_cast<TempPtr<T> &>(m_vec[pos]);
            if (!p.IsPersisted())
                p.Persist();
            return p.Get();
        }

        inline pointer operator[](size_type pos)
        {
            BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
        }

        inline size_type size() const
        {
            return m_vec.size();
        }

	    inline bool empty() const
        {
            return m_vec.empty();
        }

    private:
        temp_ptr_vector_type m_vec;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_TEMPPTR_HPP