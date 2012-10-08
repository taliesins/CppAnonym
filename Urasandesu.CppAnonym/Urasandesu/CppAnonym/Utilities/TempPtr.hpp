#pragma once
#ifndef URASANDESU_CPPANONYM_UTILITIES_TEMPPTR_HPP
#define URASANDESU_CPPANONYM_UTILITIES_TEMPPTR_HPP

#ifndef URASANDESU_CPPANONYM_UTILITIES_SEMIAUTOPTR_HPP
#include <Urasandesu/CppAnonym/Utilities/SemiAutoPtr.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_TEMPPTRFWD_HPP
#include <Urasandesu/CppAnonym/Utilities/TempPtrFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    namespace TempPtrDetail {

        using namespace boost;

        struct PersistedHandler
        {
            typedef PersistedHandler this_type;

            PersistedHandler() : m_useCount(0) { }
            virtual ~PersistedHandler() { };
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

        template<class Handler>
        struct PersistedHandlerImpl : 
            PersistedHandler
        {
            typedef PersistedHandlerImpl<Handler> this_type;
            typedef PersistedHandler base_type;

            typedef typename mpl::eval_if<
                CPP_ANONYM_HAS_MEMBER_TYPE(PersistedHandler, sender_type, Handler), 
                CPP_ANONYM_GET_MEMBER_TYPE(PersistedHandler, sender_type, Handler), 
                mpl::identity<void>
            >::type sender_type;

            typedef typename mpl::eval_if<
                CPP_ANONYM_HAS_MEMBER_TYPE(PersistedHandler, arg_type, Handler), 
                CPP_ANONYM_GET_MEMBER_TYPE(PersistedHandler, arg_type, Handler), 
                mpl::identity<void>
            >::type arg_type;

            PersistedHandlerImpl(Handler handler) : 
                base_type(),
                m_handler(handler)
            { }
            
            virtual ~PersistedHandlerImpl() 
            { 
            }

            virtual void operator()(void *pSender, void *pArg)
            {
                m_handler(static_cast<sender_type *>(pSender), static_cast<arg_type *>(pArg));
            }

            virtual void Delete()
            {
                delete this;
                //PersistedHandlerImplFactory<Handler>::Heap().Delete(this);
            }

            Handler m_handler;
        };

        //template<class Handler>
        //struct PersistedHandlerImplFactory
        //{
        //    typedef PersistedHandlerImpl<Handler> holder_type;
        //    typedef SimpleHeap<holder_type, QuickHeapWithoutSubscriptOperator> holder_heap_type;
        //    static holder_heap_type &Heap() { static holder_heap_type heap; return heap; }
        //};

        template<class T>
        class TempPtrImpl : 
            public SemiAutoPtr<T>
        {
        public:
            typedef TempPtrImpl<T> this_type;
            typedef SemiAutoPtr<T> base_type;
            typedef PersistedHandler persisted_handler_type;
            typedef std::vector<intrusive_ptr<persisted_handler_type> > persisted_handler_vector_type;

            TempPtrImpl() : 
                base_type(),
                m_isPersisted(false)
            { }

            explicit TempPtrImpl(T *p) : 
                base_type(p),
                m_isPersisted(false)
            { }

            template<class D>
            TempPtrImpl(T *p, D d) : 
                base_type(p, d),
                m_isPersisted(false)
            { }

            template<class U>
            TempPtrImpl(TempPtrImpl<U> const &other) : 
                base_type(other),
                m_isPersisted(other.IsPersisted()),
                m_persistedHandlers(PersistedHandlersAccessor<U>::Get(other))
            { }

            inline TempPtrImpl &operator =(TempPtrImpl &other)
            {
                base_type::operator =(other);
                m_isPersisted = other.IsPersisted();
                m_persistedHandlers = PersistedHandlersAccessor<U>::Get(other);
                return *this;
            }

            template<class U>
            inline TempPtrImpl &operator =(TempPtrImpl<U> &other)
            {
                base_type::operator =(other);
                m_isPersisted = other.IsPersisted();
                m_persistedHandlers = PersistedHandlersAccessor<U>::Get(other);
                return *this;
            }

            inline bool IsPersisted() const
            {
                return m_isPersisted;
            }

            inline void Persist()
            {
                if (!m_isPersisted)
                {
                    base_type::SetManual();
                    m_isPersisted = true;
                    if (!m_persistedHandlers.empty())
                    {
                        typedef persisted_handler_vector_type::iterator Iterator;
                        for (Iterator i = m_persistedHandlers.begin(), i_end = m_persistedHandlers.end(); i != i_end; ++i)
                            (**i)(this, NULL);
                    }
                }
            }

            template<class Handler>
            inline size_t AddPersistedHandler(Handler handler)
            {
                m_persistedHandlers.push_back(new PersistedHandlerImpl<Handler>(handler) /*PersistedHandlerImplFactory<Handler>::Heap().New(handler)*/);
                return m_persistedHandlers.size() - 1;
            }

            inline void RemovePersistedHandler(size_t id)
            {
                _ASSERTE(id < m_persistedHandlers.size());
                m_persistedHandlers.erace(m_persistedHandlers.begin() + id);
            }

        private:
            template<class U> friend struct PersistedHandlersAccessor;
            void SetAuto();
            void SetManual();
            bool m_isPersisted;
            persisted_handler_vector_type m_persistedHandlers;
        };

        template<class U> 
        struct PersistedHandlersAccessor
        {
            typedef typename TempPtrImpl<U>::persisted_handler_vector_type persisted_handler_vector_type;

            static persisted_handler_vector_type const &Get(TempPtrImpl<U> const &p)
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

        explicit TempPtr(T *p) : 
            base_type(p)
        { }

        template<class D>
        TempPtr(T *p, D d) : 
            base_type(p, d)
        { }

        template<class U>
        TempPtr(TempPtr<U> const &other) : 
            base_type(other)
        { }

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