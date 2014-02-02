/* 
 * File: IsLikePointer.h
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
#ifndef URASANDESU_CPPANONYM_TRAITS_ISLIKEPOINTER_H
#define URASANDESU_CPPANONYM_TRAITS_ISLIKEPOINTER_H

#ifndef URASANDESU_CPPANONYM_TRAITS_HASMEMBERFUNCTION_H
#include <Urasandesu/CppAnonym/Traits/HasMemberFunction.h>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_ISLIKEPOINTERFWD_H
#include <Urasandesu/CppAnonym/Traits/IsLikePointerFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Traits {

    namespace IsLikePointerDetail {

        namespace mpl = boost::mpl;
        using boost::has_trivial_assign;
        using boost::has_trivial_constructor;
        using boost::has_trivial_copy;
        using boost::has_trivial_destructor;
        using boost::is_pointer;
        using mpl::and_;
        using mpl::not_;
        using mpl::or_;

        template<class T>
        class IsLikePointerImpl : 
            public is_pointer<T>
        {
        };

        template<class T, template<class> class CandidateSmartPtr>
        class IsLikePointerImpl<CandidateSmartPtr<T> >
        {
            CPP_ANONYM_DECLARE_HAS_MEMBER_FUNCTION(IndirectionOperator, operator*, T &, () const); 
            CPP_ANONYM_DECLARE_HAS_MEMBER_FUNCTION(MemberAccessOperator, operator->, T *, () const);
        public:
            //typedef typename and_<
            //    CPP_ANONYM_HAS_MEMBER_FUNCTION(IndirectionOperator, CandidateSmartPtr<T>), 
            //    CPP_ANONYM_HAS_MEMBER_FUNCTION(MemberAccessOperator, CandidateSmartPtr<T>), 
            typedef typename and_<
                not_<
                    or_<
                        has_trivial_constructor<CandidateSmartPtr<T> >,
                        has_trivial_copy<CandidateSmartPtr<T> >, 
                        has_trivial_assign<CandidateSmartPtr<T> >, 
                        has_trivial_destructor<CandidateSmartPtr<T> >
                    >
                >
            >::type type;
        };

    }   // namespace IsLikePointerDetail {

    template<class T>
    struct IsLikePointer : 
        IsLikePointerDetail::IsLikePointerImpl<T>
    {
    };

    template<class T, template<class> class CandidateSmartPtr>
    struct IsLikePointer<CandidateSmartPtr<T> > : 
        IsLikePointerDetail::IsLikePointerImpl<CandidateSmartPtr<T> >
    {
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Traits {

#endif  // #ifndef URASANDESU_CPPANONYM_TRAITS_ISLIKEPOINTER_H
