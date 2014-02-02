/* 
 * File: VariantPtr.h
 * 
 * Author: Akira Sugiura (urasandesu@gmail.com)
 * 
 * 
 * Copyright (c) 2014 Akira Sugiura
 *  
 *  This software is MIT License.
 *  
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *  
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 *  
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 *  THE SOFTWARE.
 */


#pragma once
#ifndef URASANDESU_CPPANONYM_UTILITIES_VARIANTPTR_H
#define URASANDESU_CPPANONYM_UTILITIES_VARIANTPTR_H

#ifndef URASANDESU_CPPANONYM_TRAITS_ISLIKEPOINTER_H
#include <Urasandesu/CppAnonym/Traits/IsLikePointer.h>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_MAXSIZETYPE_H
#include <Urasandesu/CppAnonym/Traits/MaxSizeType.h>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_VARIANTPTRFWD_H
#include <Urasandesu/CppAnonym/Utilities/VariantPtrFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    namespace VariantPtrDetail {

        namespace mpl = boost::mpl;
        using namespace boost;
        using namespace Urasandesu::CppAnonym::Traits;
        using boost::add_const;
        using boost::aligned_storage;
        using boost::alignment_of;
        using boost::is_same;
        using mpl::_;
        using mpl::_1;
        using mpl::_2;
        using mpl::and_;
        using mpl::apply;
        using mpl::bind;
        using mpl::end;
        using mpl::filter_view;
        using mpl::find_if;
        using mpl::fold;
        using mpl::lambda;
        using mpl::not_;
        using mpl::or_;
        using mpl::true_;
        using mpl::vector;
        using mpl::void_;

        template<class T0, CPPANONYM_VARIANT_PTR_ENUM_SHIFTED_PARAMS(class T)>
        class VariantPtrImpl : 
            noncopyable
        {
        public:
            typedef VariantPtrImpl<T0, CPPANONYM_VARIANT_PTR_ENUM_SHIFTED_PARAMS(T)> this_type;

            typedef vector<T0, CPPANONYM_VARIANT_PTR_ENUM_SHIFTED_PARAMS(T)> types;
            typedef typename lambda<not_<is_same<_, void_> > >::type is_designated;
            typedef fold<filter_view<types, is_designated>, true_, and_<_1, IsLikePointer<_2> > > all_types_are_like_pointer;
            //BOOST_MPL_ASSERT((typename all_types_are_like_pointer::type));

            typedef typename MaxSizeType<types>::type max_size_type;
            typedef typename aligned_storage<sizeof(max_size_type), alignment_of<max_size_type>::value>::type storage_type;

            typedef typename lambda<
                                and_<
                                    apply<is_designated, _1>, 
                                    or_<
                                        is_same<_1, _2>, 
                                        is_same<add_const<_1>, _2> 
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
                ::ZeroMemory(&m_storage, sizeof(storage_type));
            }

            template<class T>
            VariantPtrImpl(T const &p);

            template<class T>
            T &Get() const;

            template<class T>
            void Set(T const &p);

            template<class T>
            void Clear();

            template<class T>
            void Assign(this_type const &other);

            template<class T, class U0, CPPANONYM_VARIANT_PTR_ENUM_SHIFTED_PARAMS(class U)>
            void Assign(VariantPtrImpl<U0, CPPANONYM_VARIANT_PTR_ENUM_SHIFTED_PARAMS(U)> const &other);

            template<class T>
            T Detach();

        private:
            template<class U0, CPPANONYM_VARIANT_PTR_ENUM_SHIFTED_PARAMS(class U)> friend struct WhichAccessor;
            template<class U0, CPPANONYM_VARIANT_PTR_ENUM_SHIFTED_PARAMS(class U)> friend struct StorageAccessor;
            mutable storage_type m_storage;
#ifdef _DEBUG
            INT m_which;
#else
#endif

        private:
            struct Tester
            {
                Tester(int) { }
                void Dummy() { }
            };

            typedef void (Tester::*unspecified_bool_type)();

        public:
            operator unspecified_bool_type() const
            {
                return !*reinterpret_cast<max_size_type const *>(&m_storage) ? 0 : &Tester::Dummy;
            }
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
            typedef typename variant_ptr_type::storage_type storage_type;

            static storage_type const &Get(variant_ptr_type const &p)
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

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_VARIANTPTR_H
