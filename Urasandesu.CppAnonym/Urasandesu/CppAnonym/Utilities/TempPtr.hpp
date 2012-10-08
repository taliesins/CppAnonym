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

        template<class Handler, class ImplD>
        struct PersistedHandlerImpl : 
            PersistedHandler
        {
            typedef PersistedHandlerImpl<Handler, ImplD> this_type;
            typedef PersistedHandler base_type;

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

            PersistedHandlerImpl(Handler handler) : 
                base_type(),
                m_handler(handler),
                m_impld(ImplD())
            { }

            PersistedHandlerImpl(Handler handler, ImplD impld) : 
                base_type(), 
                m_handler(handler),
                m_impld(impld)
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
                m_impld(this);
            }

            Handler m_handler;
            ImplD m_impld;
        };

        template<class T>
        class TempPtrImpl : 
            public SemiAutoPtr<T>
        {
        public:
            typedef TempPtrImpl<T> this_type;
            typedef SemiAutoPtr<T> base_type;
            typedef PersistedHandler persisted_handler_type;
            typedef Collections::RapidVector<intrusive_ptr<persisted_handler_type>, 1 > persisted_handlers_type;

            template<class Handler, class ImplD>
            struct persisted_handler_impl_type
            {
                typedef PersistedHandlerImpl<Handler, ImplD> type;
            };

            template<class Handler>
            struct default_heap_persisted_handler_impl
            {
                struct deleter_type;
                typedef typename persisted_handler_impl_type<Handler, deleter_type>::type type;
                typedef SimpleHeap<type, QuickHeapWithoutSubscriptOperator> heap_type;
                struct deleter_type : 
                    HeapDeleter<heap_type>
                {
                    typedef HeapDeleter<heap_type> base_type;
                
                    deleter_type(heap_type &heap) : 
                        base_type(heap)
                    { }

                    template<class T>
                    void operator()(T *p) 
                    { 
                        base_type::operator()(p);
                    }
                };
            };

            TempPtrImpl() : 
                base_type(),
                m_isPersisted(false)
            { }

            explicit TempPtrImpl(T *p) : 
                base_type(p),
                m_isPersisted(false)
            { }

            template<class TD>
            TempPtrImpl(T *p, TD td) : 
                base_type(p, td),
                m_isPersisted(false)
            { }

            template<class TD, class ImplD>
            explicit TempPtrImpl(SemiAutoPtrDetail::SemiAutoPtrHolderImpl<T, TD, ImplD> *pHolder) : 
                base_type(pHolder),
                m_isPersisted(false)
            { }

            TempPtrImpl(this_type const &other) : 
                base_type(other),
                m_isPersisted(other.m_isPersisted),
                m_persistedHandlers(other.m_persistedHandlers)
            { }

            template<class U>
            TempPtrImpl(TempPtrImpl<U> const &other) : 
                base_type(other),
                m_isPersisted(other.IsPersisted()),
                m_persistedHandlers(PersistedHandlersAccessor<U>::Get(other))
            { }

            inline this_type &operator =(this_type &other)
            {
                base_type::operator =(other);
                m_isPersisted = other.m_isPersisted;
                m_persistedHandlers = other.m_persistedHandlers;
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
                        typedef persisted_handlers_type::iterator Iterator;
                        for (Iterator i = m_persistedHandlers.begin(), i_end = m_persistedHandlers.end(); i != i_end; ++i)
                            (**i)(this, NULL);
                    }
                }
            }

            template<class Handler>
            inline size_t AddPersistedHandler(Handler handler)
            {
                m_persistedHandlers.push_back(new persisted_handler_impl_type<Handler, DefaultDeleter>::type(handler));
                return m_persistedHandlers.size() - 1;
            }

            template<class Handler, class ImplD>
            inline size_t AddPersistedHandler(PersistedHandlerImpl<Handler, ImplD> *pPersistedHandler)
            {
                m_persistedHandlers.push_back(pPersistedHandler);
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
            persisted_handlers_type m_persistedHandlers;
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

        explicit TempPtr(T *p) : 
            base_type(p)
        { }

        template<class TD>
        TempPtr(T *p, TD td) : 
            base_type(p, td)
        { }

        template<class TD, class ImplD>
        explicit TempPtr(SemiAutoPtrDetail::SemiAutoPtrHolderImpl<T, TD, ImplD> *pHolder) : 
            base_type(pHolder)
        { }

        TempPtr(this_type const &other) : 
            base_type(other)
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