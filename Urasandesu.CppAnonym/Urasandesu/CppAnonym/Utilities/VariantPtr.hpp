#pragma once
#ifndef URASANDESU_CPPANONYM_UTILITIES_VARIANTPTR_HPP
#define URASANDESU_CPPANONYM_UTILITIES_VARIANTPTR_HPP

#ifndef URASANDESU_CPPANONYM_TRAITS_ISLIKEPOINTER_HPP
#include <Urasandesu/CppAnonym/Traits/IsLikePointer.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_MAXSIZETYPE_HPP
#include <Urasandesu/CppAnonym/Traits/MaxSizeType.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_VARIANTPTRFWD_HPP
#include <Urasandesu/CppAnonym/Utilities/VariantPtrFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    namespace VariantPtrDetail {

        namespace mpl = boost::mpl;
        using namespace boost;
        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Traits;

        template<class Types>
        class VariantPtrImpl : 
            noncopyable
        {
        public:
            typedef fold<Types, true_, and_<_1, IsLikePointer<_2> > > all_types_are_like_pointer;
            BOOST_MPL_ASSERT((typename all_types_are_like_pointer::type));

            typedef typename MaxSizeType<Types>::type max_size_type;

#ifdef _DEBUG
            VariantPtrImpl() : 
                m_which(-1)
#else
            VariantPtrImpl()
#endif
            {
                ::ZeroMemory(m_storage, sizeof(max_size_type));
            }

            template<class T>
            VariantPtrImpl(T &p)
            {
                typedef typename mpl::find<Types, T>::type I;
                typedef typename mpl::end<Types>::type IEnd;
                BOOST_MPL_ASSERT((not_<is_same<I, IEnd> >));
#ifdef _DEBUG
                m_which = I::pos::value;
#else
#endif
                ConstructionDistributor<T>::Construct<T &>(m_storage, p);
            }

            template<class T>
            T &Get()
            {
                typedef typename mpl::find<Types, T>::type I;
                typedef typename mpl::end<Types>::type IEnd;
                BOOST_MPL_ASSERT((not_<is_same<I, IEnd> >));
#ifdef _DEBUG
                _ASSERTE(m_which == I::pos::value);
#else
#endif
                return reinterpret_cast<T &>(m_storage);
            }

            template<class T>
            void Clear()
            {
                typedef typename mpl::find<Types, T>::type I;
                typedef typename mpl::end<Types>::type IEnd;
                BOOST_MPL_ASSERT((not_<is_same<I, IEnd> >));
#ifdef _DEBUG
                _ASSERTE(m_which == -1 || m_which == I::pos::value);
                m_which = -1;
#else
#endif
                DestructionDistributor<T>::Destruct(m_storage);
                ::ZeroMemory(m_storage, sizeof(max_size_type));
            }

            template<class T>
            void AssignTo(VariantPtrImpl<Types> &other)
            {
                typedef typename mpl::find<Types, T>::type I;
                typedef typename mpl::end<Types>::type IEnd;
                BOOST_MPL_ASSERT((not_<is_same<I, IEnd> >));
#ifdef _DEBUG
                _ASSERTE(m_which == I::pos::value);
#else
#endif
                if (this != &other)
                    AssignationDistributor<T>::Assign(other.m_storage, m_storage);
            }

            template<class T>
            T Detach()
            {
                typedef typename mpl::find<Types, T>::type I;
                typedef typename mpl::end<Types>::type IEnd;
                BOOST_MPL_ASSERT((not_<is_same<I, IEnd> >));
#ifdef _DEBUG
                _ASSERTE(m_which == I::pos::value);
                m_which = -1;
#else
#endif
                T p;
                ::memcpy_s(&p, sizeof(T), m_storage, sizeof(T));
                DestructionDistributor<T>::Destruct(m_storage);
                ::ZeroMemory(m_storage, sizeof(max_size_type));
                return p;
            }

        private:
            BYTE m_storage[sizeof(max_size_type)];
#ifdef _DEBUG
            INT m_which;
#else
#endif
        };

    }   // namespace VariantPtrDetail {

    template<class Types>
    struct VariantPtr : 
        VariantPtrDetail::VariantPtrImpl<Types>
    {
        typedef VariantPtr<Types> this_type;
        typedef VariantPtrDetail::VariantPtrImpl<Types> base_type;

        VariantPtr() : 
            base_type()
        { }

        template<class T>
        VariantPtr(T &p) : 
            base_type(p)
        { }
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_VARIANTPTR_HPP