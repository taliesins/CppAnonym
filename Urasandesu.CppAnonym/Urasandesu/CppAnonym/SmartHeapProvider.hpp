#pragma once
#ifndef URASANDESU_CPPANONYM_SMARTHEAPPROVIDER_HPP
#define URASANDESU_CPPANONYM_SMARTHEAPPROVIDER_HPP

#ifndef URASANDESU_CPPANONYM_SIMPLEHEAPPROVIDER_HPP
#include <Urasandesu/CppAnonym/SimpleHeapProvider.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_HEAPDELETER_HPP
#include <Urasandesu/CppAnonym/Utilities/HeapDeleter.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_TEMPPTR_HPP
#include <Urasandesu/CppAnonym/Utilities/TempPtr.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_SMARTHEAPPROVIDERFWD_HPP
#include <Urasandesu/CppAnonym/SmartHeapProviderFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym {

    namespace _32AA62CA {

        namespace mpl = boost::mpl;
        using namespace boost;

        template<class ProvidingTypes, class I, class IEnd>
        class ATL_NO_VTABLE SmartHeapProviderImpl : 
            SimpleHeapProvider<
                mpl::vector<
                    ObjectTag<typename mpl::deref<I>::type, QuickHeapWithoutSubscriptOperator>
                >
            >,
            public SmartHeapProviderImpl<ProvidingTypes, typename mpl::next<I>::type, IEnd>
        {
        public:
            typedef SmartHeapProviderImpl<ProvidingTypes, I, IEnd> this_type;
            typedef typename mpl::deref<I>::type object_type;
            typedef ObjectTag<object_type, QuickHeapWithoutSubscriptOperator> obj_tag_type;
            typedef SimpleHeapProvider<mpl::vector<obj_tag_type> > base_type;

            typedef base_type::object_heap_type object_heap_type;
            typedef Utilities::HeapDeleter<object_heap_type> object_heap_deleter_type;
            typedef object_type *object_ptr_type;
            typedef object_type const *object_const_ptr_type;

            struct static_temp_object_ptr_tag;
            typedef Utilities::TempPtr<object_type, static_temp_object_ptr_tag> static_object_temp_ptr_type;

            struct temp_object_ptr_tag;
            typedef Utilities::TempPtr<object_type, temp_object_ptr_tag> object_temp_ptr_type;

            static static_object_temp_ptr_type NewStaticObject()
            {
                return static_object_temp_ptr_type(StaticHeap().New(), object_heap_deleter_type(StaticHeap()));
            }

            object_temp_ptr_type NewObject()
            {
                return object_temp_ptr_type(base_type::Heap().New(), object_heap_deleter_type(base_type::Heap()));
            }

        private:
            static object_heap_type &StaticHeap()
            {
                static object_heap_type heap;
                return heap;
            }
        };

        template<class ProvidingTypes>
        class SmartHeapProviderImpl<ProvidingTypes, 
                                    typename Traits::DistinctEnd<ProvidingTypes>::type, 
                                    typename Traits::DistinctEnd<ProvidingTypes>::type> : 
            noncopyable
        {
        };

        template<class ProvidingTypes, class ProvidingType>
        class ProviderOfImpl
        {
            typedef typename Traits::Distinct<ProvidingTypes>::type distinct_providing_types;
            typedef typename mpl::find<distinct_providing_types, ProvidingType>::type i;
            typedef typename Traits::DistinctEnd<ProvidingTypes>::type i_end;
        public:
            typedef SmartHeapProviderImpl<ProvidingTypes, i, i_end> type;
        };

    }   // namespace _32AA62CA


    template<class ProvidingTypes>
    class ATL_NO_VTABLE SmartHeapProvider : 
        public _32AA62CA::SmartHeapProviderImpl<ProvidingTypes, 
                                                typename Traits::DistinctBegin<ProvidingTypes>::type, 
                                                typename Traits::DistinctEnd<ProvidingTypes>::type>
    {
    public:
        typedef SmartHeapProvider<ProvidingTypes> this_type;
        typedef ProvidingTypes providing_types;

        template<LONG N>
        struct providing_type_at : 
            boost::mpl::at_c<providing_types, N>
        {
        };

        template<class ProvidingType>
        class provider_of : 
            public _32AA62CA::ProviderOfImpl<providing_types, ProvidingType>
        {
        };

        template<class T>
        inline typename provider_of<T>::type &ProviderOf() const
        {
            this_type *pMutableThis = const_cast<this_type *>(this);
            return static_cast<typename provider_of<T>::type &>(*pMutableThis);
        }
    };

}}   // namespace Urasandesu { namespace CppAnonym {

#endif  // #ifndef URASANDESU_CPPANONYM_SMARTHEAPPROVIDER_HPP