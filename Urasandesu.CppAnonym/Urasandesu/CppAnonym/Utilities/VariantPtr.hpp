#pragma once
#ifndef URASANDESU_CPPANONYM_UTILITIES_VARIANTPTR_HPP
#define URASANDESU_CPPANONYM_UTILITIES_VARIANTPTR_HPP

#ifndef URASANDESU_CPPANONYM_TRAITS_ISLIKEPOINTER_H
#include <Urasandesu/CppAnonym/Traits/IsLikePointer.h>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_MAXSIZETYPE_H
#include <Urasandesu/CppAnonym/Traits/MaxSizeType.h>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_CONSTRUCTIONDISTRIBUTOR_H
#include <Urasandesu/CppAnonym/Utilities/ConstructionDistributor.h>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_ASSIGNATIONDISTRIBUTOR_H
#include <Urasandesu/CppAnonym/Utilities/AssignationDistributor.h>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_DESTRUCTIONDISTRIBUTOR_HPP
#include <Urasandesu/CppAnonym/Utilities/DestructionDistributor.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_VARIANTPTRFWD_HPP
#include <Urasandesu/CppAnonym/Utilities/VariantPtrFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    namespace VariantPtrDetail {

        namespace mpl = boost::mpl;
        using mpl::_;
        using mpl::_1;
        using mpl::_2;
        using mpl::and_;
        using mpl::apply;
        using mpl::filter_view;
        using mpl::fold;
        using mpl::not_;
        using mpl::or_;
        using mpl::true_;
        using mpl::void_;
        using namespace boost;
        using namespace Urasandesu::CppAnonym::Traits;

        template<class T0, CPPANONYM_VARIANT_PTR_ENUM_SHIFTED_PARAMS(class T)>
        class VariantPtrImpl : 
            noncopyable
        {
        public:
            typedef VariantPtrImpl<T0, CPPANONYM_VARIANT_PTR_ENUM_SHIFTED_PARAMS(T)> this_type;

            typedef mpl::vector<T0, CPPANONYM_VARIANT_PTR_ENUM_SHIFTED_PARAMS(T)> types;
            typedef typename mpl::lambda<not_<boost::is_same<_, void_> > >::type is_designated;
            typedef fold<filter_view<types, is_designated>, true_, and_<_1, IsLikePointer<_2> > > all_types_are_like_pointer;
            BOOST_MPL_ASSERT((typename all_types_are_like_pointer::type));

            typedef typename MaxSizeType<types>::type max_size_type;

            typedef typename mpl::lambda<
                and_<
                    apply<is_designated, _1>, 
                    or_<
                        boost::is_same<_1, _2>, 
                        boost::is_same<boost::add_const<_1>, _2> 
                    > 
                > 
            >::type is_T_or_const_T;

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
            VariantPtrImpl(T const &p)
            {
                typedef typename mpl::find_if<types, mpl::bind<is_T_or_const_T, T, _1> >::type I;
                typedef typename mpl::end<types>::type IEnd;
                BOOST_MPL_ASSERT((not_<is_same<I, IEnd> >));
#ifdef _DEBUG
                m_which = I::pos::value;
#else
#endif
                ConstructionDistributor<T>::Construct<T const &>(m_storage, p);
            }

            template<class T>
            T &Get() const
            {
                typedef typename mpl::find_if<types, mpl::bind<is_T_or_const_T, T, _1> >::type I;
                typedef typename mpl::end<types>::type IEnd;
                BOOST_MPL_ASSERT((not_<is_same<I, IEnd> >));
#ifdef _DEBUG
                _ASSERTE(m_which == I::pos::value);
#else
#endif
                return *reinterpret_cast<T *>(m_storage);
            }

            template<class T>
            void Set(T const &p)
            {
                typedef typename mpl::find_if<types, mpl::bind<is_T_or_const_T, T, _1> >::type I;
                typedef typename mpl::end<types>::type IEnd;
                BOOST_MPL_ASSERT((not_<is_same<I, IEnd> >));
#ifdef _DEBUG
                _ASSERTE(m_which == -1 || m_which == I::pos::value);
                m_which = I::pos::value;
#else
#endif
                DestructionDistributor<T>::Destruct(m_storage);
                ::ZeroMemory(m_storage, sizeof(max_size_type));
                ConstructionDistributor<T>::Construct<T const &>(m_storage, p);
            }

            template<class T>
            void Clear()
            {
                typedef typename mpl::find_if<types, mpl::bind<is_T_or_const_T, T, _1> >::type I;
                typedef typename mpl::end<types>::type IEnd;
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
            void Assign(this_type const &other)
            {
                typedef typename mpl::find_if<types, mpl::bind<is_T_or_const_T, T, _1> >::type I;
                typedef typename mpl::end<types>::type IEnd;
                BOOST_MPL_ASSERT((not_<is_same<I, IEnd> >));
#ifdef _DEBUG
                _ASSERTE(m_which == -1 || m_which == I::pos::value);
                _ASSERTE(other.m_which == I::pos::value);
#else
#endif
                if (this != &other)
                {
                    DestructionDistributor<T>::Destruct(m_storage);
                    ::ZeroMemory(m_storage, sizeof(max_size_type));
                    ConstructionDistributor<T>::Construct<T const &>(m_storage, *reinterpret_cast<T *>(other.m_storage));
#ifdef _DEBUG
                    m_which = I::pos::value;
#else
#endif
                }
            }

            template<class T, class U0, CPPANONYM_VARIANT_PTR_ENUM_SHIFTED_PARAMS(class U)>
            void Assign(VariantPtrImpl<U0, CPPANONYM_VARIANT_PTR_ENUM_SHIFTED_PARAMS(U)> const &other)
            {
                typedef mpl::vector<U0, CPPANONYM_VARIANT_PTR_ENUM_SHIFTED_PARAMS(U)> OtherTypes;
                typedef typename mpl::find_if<OtherTypes, mpl::bind<is_T_or_const_T, T, _1> >::type OtherI;
                typedef typename mpl::end<OtherTypes>::type OtherIEnd;
                BOOST_MPL_ASSERT((not_<is_same<OtherI, OtherIEnd> >));

                typedef typename mpl::find_if<types, mpl::bind<is_T_or_const_T, T, _1> >::type I;
                typedef typename mpl::end<types>::type IEnd;
                BOOST_MPL_ASSERT((not_<is_same<I, IEnd> >));

#ifdef _DEBUG
                _ASSERTE(m_which == -1 || m_which == I::pos::value);
                typedef WhichAccessor<U0, CPPANONYM_VARIANT_PTR_ENUM_SHIFTED_PARAMS(U)> WhichAccessor;
                _ASSERTE(WhichAccessor::Get(other) == OtherI::pos::value);
#else
#endif

                DestructionDistributor<T>::Destruct(m_storage);
                ::ZeroMemory(m_storage, sizeof(max_size_type));
                typedef StorageAccessor<U0, CPPANONYM_VARIANT_PTR_ENUM_SHIFTED_PARAMS(U)> StorageAccessor;
                ConstructionDistributor<T>::Construct<T const &>(m_storage, *reinterpret_cast<T *>(StorageAccessor::Get(other)));
#ifdef _DEBUG
                m_which = I::pos::value;
#else
#endif
            }


            template<class T>
            T Detach()
            {
                typedef typename mpl::find_if<types, mpl::bind<is_T_or_const_T, T, _1> >::type I;
                typedef typename mpl::end<types>::type IEnd;
                BOOST_MPL_ASSERT((not_<is_same<I, IEnd> >));
#ifdef _DEBUG
                _ASSERTE(m_which == I::pos::value);
                m_which = -1;
#else
#endif
                T p(*reinterpret_cast<T *>(m_storage));
                DestructionDistributor<T>::Destruct(m_storage);
                ::ZeroMemory(m_storage, sizeof(max_size_type));
                return p;
            }

            inline operator bool() const
            {
                return !!(*this);
            }

            bool operator !() const
            {
                return !*reinterpret_cast<max_size_type const *>(m_storage);
            }

        private:
            template<class U0, CPPANONYM_VARIANT_PTR_ENUM_SHIFTED_PARAMS(class U)> friend struct WhichAccessor;
            template<class U0, CPPANONYM_VARIANT_PTR_ENUM_SHIFTED_PARAMS(class U)> friend struct StorageAccessor;
            mutable BYTE m_storage[sizeof(max_size_type)];
#ifdef _DEBUG
            INT m_which;
#else
#endif
        };

#ifdef _DEBUG
        template<class U0, CPPANONYM_VARIANT_PTR_ENUM_SHIFTED_PARAMS(class U)>
        struct WhichAccessor
        {
            typedef VariantPtrImpl<U0, CPPANONYM_VARIANT_PTR_ENUM_SHIFTED_PARAMS(U)> variant_ptr_type;

            static INT Get(variant_ptr_type const &p)
            {
                return p.m_which;
            }
        };
#else
#endif

        template<class U0, CPPANONYM_VARIANT_PTR_ENUM_SHIFTED_PARAMS(class U)>
        struct StorageAccessor
        {
            typedef VariantPtrImpl<U0, CPPANONYM_VARIANT_PTR_ENUM_SHIFTED_PARAMS(U)> variant_ptr_type;

            static BYTE * const Get(variant_ptr_type const &p)
            {
                return p.m_storage;
            }
        };

    }   // namespace VariantPtrDetail {

    template<class T0, CPPANONYM_VARIANT_PTR_ENUM_SHIFTED_PARAMS(class T)>
    struct VariantPtr : 
        VariantPtrDetail::VariantPtrImpl<T0, CPPANONYM_VARIANT_PTR_ENUM_SHIFTED_PARAMS(T)>
    {
        typedef VariantPtr<T0, CPPANONYM_VARIANT_PTR_ENUM_SHIFTED_PARAMS(T)> this_type;
        typedef VariantPtrDetail::VariantPtrImpl<T0, CPPANONYM_VARIANT_PTR_ENUM_SHIFTED_PARAMS(T)> base_type;

        VariantPtr() : 
            base_type()
        { }

        template<class T>
        VariantPtr(T const &p) : 
            base_type(p)
        { }
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_VARIANTPTR_HPP