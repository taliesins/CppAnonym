#pragma once
#ifndef URASANDESU_CPPANONYM_HEAPPROVIDER_HPP
#define URASANDESU_CPPANONYM_HEAPPROVIDER_HPP

#ifndef URASANDESU_CPPANONYM_SIMPLEHEAP_HPP
#include <Urasandesu/CppAnonym/SimpleHeap.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_DISTINCT_H
#include <Urasandesu/CppAnonym/Traits/Distinct.h>
#endif

#ifndef URASANDESU_CPPANONYM_HEAPPROVIDERFWD_HPP
#include <Urasandesu/CppAnonym/HeapProviderFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym {
    
    namespace Detail {
        
        namespace mpl = boost::mpl;

        template<
            class Key, 
            class Sequence, 
            class I, 
            class IEnd,
            class Hash,
            class EqualTo,
            class Allocator
        >
        class ATL_NO_VTABLE HeapProviderImpl : 
            public HeapProviderImpl<Key, 
                                    Sequence, 
                                    typename mpl::next<I>::type, 
                                    IEnd, 
                                    Hash,
                                    EqualTo,
                                    Allocator>
        {
        private:
            typedef HeapProviderImpl<Key, 
                                     Sequence, 
                                     I, 
                                     IEnd,
                                     Hash,
                                     EqualTo,
                                     Allocator> this_type;

            typedef typename mpl::deref<I>::type obj_type;
            
            typedef SimpleHeap<obj_type> factory_type;

            typedef Hash hash_type;
            typedef EqualTo equal_to_type;
            typedef Allocator allocator_type;
            typedef boost::unordered_map<Key, SIZE_T, hash_type, equal_to_type, allocator_type> indexes_type;
            
            typedef typename boost::call_traits<Key>::param_type key_param_type;

            boost::shared_ptr<factory_type> mutable m_pFactory;
            boost::shared_ptr<indexes_type> mutable m_pIndexes;
            
            inline factory_type &Factory() const
            {
                if (!m_pFactory.get())
                    m_pFactory = boost::make_shared<factory_type>();
                return *m_pFactory.get();
            }
            
            inline indexes_type &Indexes() const
            {
                if (!m_pIndexes.get())
                    m_pIndexes = boost::make_shared<indexes_type>();
                return *m_pIndexes.get();
            }

        public:
            inline SIZE_T Size() const
            {
                return Factory().Size();
            }
            
            inline bool Exists(key_param_type key) const
            {
                return Indexes().find(key) != Indexes().end();
            }
            
            inline obj_type *Get(key_param_type key)
            {
                return Factory()[Indexes()[key]];
            }
            
            inline obj_type const *Get(key_param_type key) const
            {
                return Factory()[Indexes()[key]];
            }
            
            inline obj_type *GetOrNew(key_param_type key)
            {
                return Exists(key) ? Get(key) : New(key);
            }
            
            inline void Set(key_param_type key, SIZE_T index)
            {
                BOOST_MPL_ASSERT((boost::is_base_of<IHeapContent<Key>, obj_type>));
                
                Indexes()[key] = index;
                Get(key)->SetKey(key);
            }
            
            inline void SetToLast(key_param_type key)
            {
                Set(key, Size() - 1);
            }
            
            inline obj_type *NewPseudo()
            {
                obj_type *pObj = Factory().New();
                return pObj;
            }

            inline obj_type *New(key_param_type key)
            {
                BOOST_MPL_ASSERT((boost::is_base_of<IHeapContent<Key>, obj_type>));
                
                if (Exists(key))
                    Get(key)->SetKey(Key());
                obj_type *pObj = Factory().New();
                SetToLast(key);
                return pObj;
            }
            
            inline obj_type *Peek() const
            {
                return Factory().Size() == 0 ? NULL : Factory()[Factory().Size() - 1];
            }

            inline void DeleteLast()
            {
                BOOST_MPL_ASSERT((boost::is_base_of<IHeapContent<Key>, obj_type>));
                
                obj_type *pObj = Peek();
                if (pObj != NULL)
                {
                    Indexes().erase(pObj->GetKey());
                    Factory().DeleteLast();
                }
            }
        };

        template<
            class Key, 
            class Sequence, 
            class Hash,
            class EqualTo,
            class Allocator
        >
        class ATL_NO_VTABLE HeapProviderImpl<Key, 
                                             Sequence, 
                                             typename Traits::DistinctEnd<Sequence>::type, 
                                             typename Traits::DistinctEnd<Sequence>::type, 
                                             Hash,
                                             EqualTo,
                                             Allocator> : 
            boost::noncopyable
        {
        };

    }   // namespace Detail


    template<
        class Key, 
        class Sequence,
        class Hash,
        class EqualTo,
        class Allocator
    >
    class ATL_NO_VTABLE HeapProvider : 
        Detail::HeapProviderImpl<Key, 
                                 Sequence, 
                                 typename Traits::DistinctBegin<Sequence>::type, 
                                 typename Traits::DistinctEnd<Sequence>::type, 
                                 Hash,
                                 EqualTo,
                                 Allocator>
    {
    public:
        typedef HeapProvider<Key, 
                             Sequence,
                             Hash,
                             EqualTo,
                             Allocator> this_type;

        typedef Key key_type;
        typedef Sequence sequence_type;

        template<class T>
        struct type_decided_by
        {
            typedef Detail::HeapProviderImpl<
                Key,
                Sequence,
                typename boost::mpl::find<
                    typename Traits::Distinct<Sequence>::type,
                    T
                >::type,
                typename Traits::DistinctEnd<Sequence>::type, 
                Hash,
                EqualTo,
                Allocator
            > type;
        };

        template<class T>
        inline typename type_decided_by<T>::type &Of()
        {
            return static_cast<typename type_decided_by<T>::type &>(*this);
        }

        template<class T>
        inline typename type_decided_by<T>::type const &Of() const
        {
            return const_cast<this_type *>(this)->Of<T>();
        }
    };




#define CPPANONYM_BEGIN_HEAP_PROVIDER_DECLARATION() \
    private: \
        template<class T> \
        Urasandesu::CppAnonym::SimpleHeap<T> *Factory(); \
    public: \
        template<class T> \
        SIZE_T Size(); \
         \
        template<class T, class Key> \
        bool Exists(Key key); \
         \
        template<class T, class Key> \
        T *Get(Key key); \
         \
        template<class T, class Key> \
        void Set(Key key, SIZE_T index); \
         \
        template<class T, class Key> \
        void SetToLast(Key key); \
         \
        template<class T> \
        T *NewPseudo(); \
         \
        template<class T, class Key> \
        T *New(Key key); \
         \
        template<class T> \
        T *Peek();


#define CPPANONYM_HEAP_PROVIDER(t, key_, name) \
    private: \
        boost::shared_ptr<Urasandesu::CppAnonym::SimpleHeap<t>> name; \
        boost::unordered_map<key_, SIZE_T> name##Indexes; \
         \
        template<> \
        Urasandesu::CppAnonym::SimpleHeap<t> *Factory() \
        { \
            if (!name.get()) \
            { \
                name = boost::make_shared<Urasandesu::CppAnonym::SimpleHeap<t>>(); \
            } \
            return name.get(); \
        } \
    public: \
        template<> \
        SIZE_T Size<t>() \
        { \
            return Factory<t>()->Size(); \
        } \
         \
        template<> \
        bool Exists<t>(key_ key) \
        { \
            return name##Indexes.find(key) != name##Indexes.end(); \
        } \
         \
        template<> \
        t *Get(key_ key) \
        { \
            return (*Factory<t>())[name##Indexes[key]]; \
        } \
         \
        template<> \
        void Set<t>(key_ key, SIZE_T index) \
        { \
            name##Indexes[key] = index; \
            Get<t>(key)->SetKey(key); \
        } \
         \
        template<> \
        void SetToLast<t>(key_ key) \
        { \
            Set<t>(key, Size<t>() - 1); \
        } \
         \
        template<> \
        t *NewPseudo() \
        { \
            t *pObj = Factory<t>()->New(); \
            return pObj; \
        } \
         \
        template<> \
        t *New(key_ key) \
        { \
            if (Exists<t>(key)) \
            { \
                Get<t>(key)->SetKey(key_()); \
            } \
            t *pObj = Factory<t>()->New(); \
            SetToLast<t>(key); \
            return pObj; \
        } \
         \
        template<> \
        t *Peek() \
        { \
            if (Factory<t>()->Size() == 0) \
            { \
                return NULL; \
            } \
            else \
            { \
                return (*Factory<t>())[Factory<t>()->Size() - 1]; \
            } \
        }

#define CPPANONYM_END_HEAP_PROVIDER_DECLARATION()

}}   // namespace Urasandesu { namespace CppAnonym {

#endif  // #ifndef URASANDESU_CPPANONYM_HEAPPROVIDER_HPP