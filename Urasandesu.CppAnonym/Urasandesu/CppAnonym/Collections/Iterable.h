/* 
 * File: Iterable.h
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
#ifndef URASANDESU_CPPANONYM_COLLECTIONS_ITERABLE_H
#define URASANDESU_CPPANONYM_COLLECTIONS_ITERABLE_H

#ifndef URASANDESU_CPPANONYM_UTILITIES_HASH_H
#include <Urasandesu/CppAnonym/Utilities/Hash.h>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_EQUALTO_H
#include <Urasandesu/CppAnonym/Utilities/EqualTo.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Collections {

    template<class InputIterator1, class InputIterator2, class EqualTo>
    bool SequenceEqual(InputIterator1 i1, InputIterator1 i_end1,
                       InputIterator2 i2, InputIterator2 i_end2, 
                       EqualTo equalTo)
    {
        while ((i1 != i_end1) && (i2 != i_end2))
        {
            if (!equalTo(*i1, *i2))
                return false;
            ++i1; ++i2;
        }
        return (i1 == i_end1) && (i2 == i_end2);
    } 

    template<class InputIterator1, class InputIterator2>
    bool SequenceEqual(InputIterator1 const &i1, InputIterator1 const &i_end1,
                       InputIterator2 const &i2, InputIterator2 const &i_end2)
    {
        return SequenceEqual(i1, i_end1, i2, i_end2, Utilities::CreateEqualTo(i1));
    } 

    template<class SinglePassRange1, class SinglePassRange2, class EqualTo>
    bool SequenceEqual(SinglePassRange1 const &rng1, SinglePassRange2 const &rng2, EqualTo equalTo)
    {
        auto i1 = boost::begin(rng1);
        auto i_end1 = boost::end(rng1);
        auto i2 = boost::begin(rng2);
        auto i_end2 = boost::end(rng2);
        return SequenceEqual(i1, i_end1, i2, i_end2, equalTo);
    } 

    template<class SinglePassRange1, class SinglePassRange2>
    bool SequenceEqual(SinglePassRange1 const &rng1, SinglePassRange2 const &rng2)
    {
        return SequenceEqual(rng1, rng2, Utilities::CreateEqualTo(rng1));
    } 


    
    
    template<class InputIterator, class Hash>
    inline std::size_t SequenceHashValue(InputIterator i, InputIterator i_end, Hash hash)
    {
        std::size_t seed = 0;
        for ( ; i != i_end; ++i)
            boost::hash_combine(seed, hash(*i));
        return seed;
    } 

    template<class InputIterator>
    inline std::size_t SequenceHashValue(InputIterator i, InputIterator i_end)
    {
        return SequenceHashValue(i, i_end, Utilities::CreateHash(i));
    } 

    template<class SinglePassRange, class Hash>
    inline std::size_t SequenceHashValue(SinglePassRange const &rng, Hash hash)
    {
        auto i = boost::begin(rng);
        auto i_end = boost::end(rng);
        return SequenceHashValue(i, i_end, hash);
    } 

    template<class SinglePassRange>
    inline std::size_t SequenceHashValue(SinglePassRange const &rng)
    {
        return SequenceHashValue(rng, Utilities::CreateHash(rng));
    } 


    
    
    template<class Sequence>
    typename Sequence::pointer ResizeIfAvailable(typename Sequence::size_type size, Sequence &v)
    {
        if (size == 0u)
        {
            return nullptr;
        }
        else
        {
            v.resize(size);
            return &v[0];
        }
    }


    
    
    namespace SequenceToStringDetail {

        namespace ToStringDetail {

            template<class T>
            struct ToStringImpl; 

        }   // namespace ToStringDetail {

        template<class T>
        struct ToString;

        namespace ToStringDetail {

            namespace mpl = boost::mpl;
            using mpl::eval_if;
            using mpl::identity;

            CPP_ANONYM_DECLARE_HAS_MEMBER_TYPE(ToStringActualValueType, value_type);
            CPP_ANONYM_DECLARE_GET_MEMBER_TYPE(ToStringActualValueType, value_type);
        
            template<class T>
            class ToStringDecidedByImpl
            {
                typedef typename eval_if<
                            CPP_ANONYM_HAS_MEMBER_TYPE(ToStringActualValueType, T),
                            CPP_ANONYM_GET_MEMBER_TYPE(ToStringActualValueType, T),
                            identity<T> >::type value_type;
            public:
                typedef ToString<value_type> type;
            };

        }   // namespace ToStringDetail {

        template<class T>
        struct ToStringDecidedBy : 
            ToStringDetail::ToStringDecidedByImpl<T>
        {
        };

        template<class T>
        typename ToStringDecidedBy<T>::type CreateToString(T const &);

    }   // namespace SequenceToStringDetail {

    namespace SequenceToStringDetail {

        using std::wostream;
        using std::wstring;

        namespace ToStringDetail {

            using std::binary_function;

            template<>
            struct ToStringImpl<BYTE> : 
                binary_function<BYTE, wostream, void>
            {
                void operator()(BYTE b, wostream &os) const
                {
                    os << boost::wformat(L"%|1$02x|") % static_cast<INT>(b);
                }
            };

        }   // namespace ToStringDetail {

        template<class T>
        struct ToString : 
            ToStringDetail::ToStringImpl<T>
        {
        };

        
        
        template<class T>
        typename ToStringDecidedBy<T>::type CreateToString(T const &)
        {
            return typename ToStringDecidedBy<T>::type();
        }


        template<class InputIterator, class ToString>
        class IteratorStringImpl
        {
        public:
            IteratorStringImpl(InputIterator const &i, InputIterator const &i_end, ToString toString) : 
                m_i(i), 
                m_i_end(i_end), 
                m_toString(toString)
            { }
            
            operator wstring() const
            {
                auto oss = std::wostringstream();
                oss << *this;
                return oss.str();
            }

        private:
            friend bool operator ==(wstring const &lhs, IteratorStringImpl const &rhs)
            {
                return lhs == wstring(rhs);
            }

            friend bool operator !=(wstring const &lhs, IteratorStringImpl const &rhs)
            {
                return !(lhs == rhs);
            }

            friend wostream &operator <<(wostream &os, IteratorStringImpl const &s)
            {
                auto _s = IteratorStringImpl(s);
                for ( ; _s.m_i != _s.m_i_end; ++_s.m_i)
                    _s.m_toString(*_s.m_i, os);
                return os;
            }

            InputIterator m_i;
            InputIterator m_i_end;
            ToString m_toString;
        };

    }   // namespace SequenceToStringDetail {

    template<class InputIterator, class ToString>
    struct IteratorString : 
        SequenceToStringDetail::IteratorStringImpl<InputIterator, ToString>
    {
        typedef SequenceToStringDetail::IteratorStringImpl<InputIterator, ToString> base_type;

        IteratorString(InputIterator const &i, InputIterator const &i_end, ToString toString) : 
            base_type(i, i_end, toString)
        { }
    };

    template<class SinglePassRange, class ToString>
    struct RangeString : 
        SequenceToStringDetail::IteratorStringImpl<typename boost::range_iterator<SinglePassRange>::type, ToString>
    {
        typedef typename boost::range_iterator<SinglePassRange>::type input_iterator_type;
        typedef SequenceToStringDetail::IteratorStringImpl<input_iterator_type, ToString> base_type;

        RangeString(input_iterator_type const &i, input_iterator_type const &i_end, ToString toString) : 
            base_type(i, i_end, toString)
        { }
    };

    template<class InputIterator, class ToString>
    inline IteratorString<InputIterator, ToString> SequenceToString(InputIterator const &i, InputIterator const &i_end, ToString toString)
    {
        return IteratorString<InputIterator, ToString>(i, i_end, toString);
    } 

    template<class InputIterator>
    inline IteratorString<InputIterator, typename SequenceToStringDetail::ToStringDecidedBy<InputIterator>::type> SequenceToString(InputIterator const &i, InputIterator const &i_end)
    {
        return SequenceToString(i, i_end, SequenceToStringDetail::CreateToString(i));
    } 

    template<class SinglePassRange, class ToString>
    inline RangeString<SinglePassRange, ToString> SequenceToString(SinglePassRange const &rng, ToString toString)
    {
        auto i = boost::begin(const_cast<SinglePassRange &>(rng));
        auto i_end = boost::end(const_cast<SinglePassRange &>(rng));
        return RangeString<SinglePassRange, ToString>(i, i_end, toString);
    } 

    template<class SinglePassRange>
    inline RangeString<SinglePassRange, typename SequenceToStringDetail::ToStringDecidedBy<typename boost::range_iterator<SinglePassRange>::type>::type> SequenceToString(SinglePassRange const &rng)
    {
        return SequenceToString(rng, SequenceToStringDetail::CreateToString(boost::begin(rng)));
    } 


    
    // The followings are STL wrappers which are removed the Assignable concept checking for iterator.
    // In Visual Studio, the compiler rarely skips the auto generation for the assignment operator of the class derived from boost::iterator_facade.
    template<class InputIterator, class UnaryPredicate> 
    inline InputIterator FindIf(InputIterator const &i, InputIterator const &i_end, UnaryPredicate pred)
    {
        using namespace std;
        _DEBUG_RANGE(i, i_end);
        _DEBUG_POINTER(pred);

		return std::find_if(i, i_end, pred);
    }

    template<class SinglePassRange, class UnaryPredicate>
    inline boost::optional<typename boost::range_value<SinglePassRange>::type> FindIf(SinglePassRange& rng, UnaryPredicate pred)
    {
        auto i = boost::begin(rng);
        auto i_end = boost::end(rng);
        auto result = FindIf(i, i_end, pred);
        if (result == i_end)
            return boost::none;
        else
            return *result;
    }

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Collections {

#endif  // URASANDESU_CPPANONYM_COLLECTIONS_ITERABLE_H
