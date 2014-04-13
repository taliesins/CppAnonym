/* 
 * File: VariantPtr.hpp
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
#ifndef URASANDESU_CPPANONYM_UTILITIES_VARIANTPTR_HPP
#define URASANDESU_CPPANONYM_UTILITIES_VARIANTPTR_HPP

#ifndef URASANDESU_CPPANONYM_UTILITIES_CONSTRUCTIONDISTRIBUTOR_H
#include <Urasandesu/CppAnonym/Utilities/ConstructionDistributor.h>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_ASSIGNATIONDISTRIBUTOR_H
#include <Urasandesu/CppAnonym/Utilities/AssignationDistributor.h>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_DESTRUCTIONDISTRIBUTOR_H
#include <Urasandesu/CppAnonym/Utilities/DestructionDistributor.h>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_VARIANTPTR_H
#include <Urasandesu/CppAnonym/Utilities/VariantPtr.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    namespace VariantPtrDetail {

        template<class T0, CPPANONYM_VARIANT_PTR_ENUM_SHIFTED_PARAMS(class T)>
        template<class T>
        VariantPtrImpl<T0, CPPANONYM_VARIANT_PTR_ENUM_SHIFTED_PARAMS(T)>::VariantPtrImpl(T const &p)
        {
            typedef typename find_if<types, bind<is_T_or_const_T, T, _1> >::type I;
            typedef typename end<types>::type IEnd;
            BOOST_MPL_ASSERT((not_<is_same<I, IEnd> >));
#ifdef _DEBUG
            m_which = I::pos::value;
#else
#endif
            ConstructionDistributor<T>::Construct<T const &>(&m_storage, p);
        }

        template<class T0, CPPANONYM_VARIANT_PTR_ENUM_SHIFTED_PARAMS(class T)>
        template<class T>
        T &VariantPtrImpl<T0, CPPANONYM_VARIANT_PTR_ENUM_SHIFTED_PARAMS(T)>::Get() const
        {
            typedef typename find_if<types, bind<is_T_or_const_T, T, _1> >::type I;
            typedef typename end<types>::type IEnd;
            BOOST_MPL_ASSERT((not_<is_same<I, IEnd> >));
#ifdef _DEBUG
            _ASSERTE(m_which == I::pos::value);
#else
#endif
            return *reinterpret_cast<T *>(&m_storage);
        }

        template<class T0, CPPANONYM_VARIANT_PTR_ENUM_SHIFTED_PARAMS(class T)>
        template<class T>
        void VariantPtrImpl<T0, CPPANONYM_VARIANT_PTR_ENUM_SHIFTED_PARAMS(T)>::Set(T const &p)
        {
            typedef typename find_if<types, bind<is_T_or_const_T, T, _1> >::type I;
            typedef typename end<types>::type IEnd;
            BOOST_MPL_ASSERT((not_<is_same<I, IEnd> >));
#ifdef _DEBUG
            _ASSERTE(m_which == -1 || m_which == I::pos::value);
            m_which = I::pos::value;
#else
#endif
            DestructionDistributor<T>::Destruct(&m_storage);
            ::ZeroMemory(&m_storage, sizeof(storage_type));
            ConstructionDistributor<T>::Construct<T const &>(&m_storage, p);
        }

        template<class T0, CPPANONYM_VARIANT_PTR_ENUM_SHIFTED_PARAMS(class T)>
        template<class T>
        void VariantPtrImpl<T0, CPPANONYM_VARIANT_PTR_ENUM_SHIFTED_PARAMS(T)>::Clear()
        {
            typedef typename find_if<types, bind<is_T_or_const_T, T, _1> >::type I;
            typedef typename end<types>::type IEnd;
            BOOST_MPL_ASSERT((not_<is_same<I, IEnd> >));
#ifdef _DEBUG
            _ASSERTE(m_which == -1 || m_which == I::pos::value);
            m_which = -1;
#else
#endif
            DestructionDistributor<T>::Destruct(&m_storage);
            ::ZeroMemory(&m_storage, sizeof(storage_type));
        }

        template<class T0, CPPANONYM_VARIANT_PTR_ENUM_SHIFTED_PARAMS(class T)>
        template<class T>
        void VariantPtrImpl<T0, CPPANONYM_VARIANT_PTR_ENUM_SHIFTED_PARAMS(T)>::Assign(this_type const &other)
        {
            typedef typename find_if<types, bind<is_T_or_const_T, T, _1> >::type I;
            typedef typename end<types>::type IEnd;
            BOOST_MPL_ASSERT((not_<is_same<I, IEnd> >));
#ifdef _DEBUG
            _ASSERTE(m_which == -1 || m_which == I::pos::value);
            _ASSERTE(other.m_which == -1 || other.m_which == I::pos::value);
#else
#endif
            if (this != &other)
            {
                DestructionDistributor<T>::Destruct(&m_storage);
                ::ZeroMemory(&m_storage, sizeof(storage_type));
                ConstructionDistributor<T>::Construct<T const &>(&m_storage, *reinterpret_cast<T *>(&other.m_storage));
#ifdef _DEBUG
                m_which = I::pos::value;
#else
#endif
            }
        }

        template<class T0, CPPANONYM_VARIANT_PTR_ENUM_SHIFTED_PARAMS(class T)>
        template<class T, class U0, CPPANONYM_VARIANT_PTR_ENUM_SHIFTED_PARAMS(class U)>
        void VariantPtrImpl<T0, CPPANONYM_VARIANT_PTR_ENUM_SHIFTED_PARAMS(T)>::Assign(VariantPtrImpl<U0, CPPANONYM_VARIANT_PTR_ENUM_SHIFTED_PARAMS(U)> const &other)
        {
            typedef vector<U0, CPPANONYM_VARIANT_PTR_ENUM_SHIFTED_PARAMS(U)> OtherTypes;
            typedef typename find_if<OtherTypes, bind<is_T_or_const_T, T, _1> >::type OtherI;
            typedef typename end<OtherTypes>::type OtherIEnd;
            BOOST_MPL_ASSERT((not_<is_same<OtherI, OtherIEnd> >));

            typedef typename find_if<types, bind<is_T_or_const_T, T, _1> >::type I;
            typedef typename end<types>::type IEnd;
            BOOST_MPL_ASSERT((not_<is_same<I, IEnd> >));

#ifdef _DEBUG
            _ASSERTE(m_which == -1 || m_which == I::pos::value);
            typedef WhichAccessor<U0, CPPANONYM_VARIANT_PTR_ENUM_SHIFTED_PARAMS(U)> WhichAccessor;
            _ASSERTE(WhichAccessor::Get(other) == -1 || WhichAccessor::Get(other) == OtherI::pos::value);
#else
#endif

            DestructionDistributor<T>::Destruct(&m_storage);
            ::ZeroMemory(&m_storage, sizeof(storage_type));
            typedef StorageAccessor<U0, CPPANONYM_VARIANT_PTR_ENUM_SHIFTED_PARAMS(U)> StorageAccessor;
            ConstructionDistributor<T>::Construct<T const &>(&m_storage, *reinterpret_cast<T const *>(&StorageAccessor::Get(other)));
#ifdef _DEBUG
            m_which = I::pos::value;
#else
#endif
        }


        template<class T0, CPPANONYM_VARIANT_PTR_ENUM_SHIFTED_PARAMS(class T)>
        template<class T>
        T VariantPtrImpl<T0, CPPANONYM_VARIANT_PTR_ENUM_SHIFTED_PARAMS(T)>::Detach()
        {
            typedef typename find_if<types, bind<is_T_or_const_T, T, _1> >::type I;
            typedef typename end<types>::type IEnd;
            BOOST_MPL_ASSERT((not_<is_same<I, IEnd> >));
#ifdef _DEBUG
            _ASSERTE(m_which == I::pos::value);
            m_which = -1;
#else
#endif
            T p(*reinterpret_cast<T *>(&m_storage));
            DestructionDistributor<T>::Destruct(&m_storage);
            ::ZeroMemory(&m_storage, sizeof(storage_type));
            return p;
        }

    }   // namespace VariantPtrDetail {

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_VARIANTPTR_HPP
