/* 
 * File: GlobalSafeDictionary.h
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
#ifndef URASANDESU_CPPANONYM_COLLECTIONS_GLOBALSAFEDICTIONARY_H
#define URASANDESU_CPPANONYM_COLLECTIONS_GLOBALSAFEDICTIONARY_H

namespace Urasandesu { namespace CppAnonym { namespace Collections {

    template<
        typename Key, 
        typename Value, 
        typename Hash = boost::hash<Key>, 
        typename Pred = std::equal_to<Key>, 
        typename Alloc = std::allocator<std::pair<Key const, Value>> 
    > 
    class GlobalSafeDictionary : boost::noncopyable
    {
    private:
        typedef boost::lock_guard<boost::mutex> guard_type;

    public:
        typedef typename boost::call_traits<Key>::param_type in_key_type;
        typedef typename boost::call_traits<Value>::param_type in_value_type;
        typedef typename boost::call_traits<Value>::reference out_value_type;
        typedef typename boost::unordered_map<Key, Value, Hash, Pred, Alloc>::value_type entry_type;

        GlobalSafeDictionary()
        { }

        static GlobalSafeDictionary &GetInstance()
        {
            static GlobalSafeDictionary im;
            return im;
        }

        BOOL TryAdd(in_key_type key, in_value_type value)
        {
			guard_type guard(m_lock);
            if (m_map.find(key) == m_map.end())
            {
                m_map[key] = value;
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }

        BOOL TryGet(in_key_type key, out_value_type rValue) const
        {
			guard_type guard(m_lock);
            if (!m_stack.empty())
                return FALSE;
            
            if (m_map.find(key) == m_map.end())
            {
                return FALSE;
            }
            else
            {
                rValue = m_map.at(key);
                return TRUE;
            }
        }

        BOOL TryRemove(in_key_type key, out_value_type rValue)
        {
			guard_type guard(m_lock);
            if (m_map.find(key) == m_map.end())
            {
                return FALSE;
            }
            else
            {
                rValue = m_map[key];
                m_map.erase(key);
                return TRUE;
            }
        }

        BOOL GetOrAdd(in_key_type key, in_value_type value, out_value_type rValue)
        {
			guard_type guard(m_lock);
            if (m_map.find(key) == m_map.end())
                m_map[key] = value;
            
            if (!m_stack.empty())
                return FALSE;
            
            rValue = m_map.at(key);
            return TRUE;
        }

        void Clear()
        {
			guard_type guard(m_lock);
            m_map.clear();
        }

        void EnterDisabledProcessing()
        {
			guard_type guard(m_lock);
            m_stack.push(true);
        }

        BOOL ExitDisabledProcessing()
        {
			guard_type guard(m_lock);
            if (m_stack.empty())
                return FALSE;

            m_stack.pop();
            return TRUE;
        }

        BOOL IsDisabledProcessing() const
        {
			guard_type guard(m_lock);
            return !m_stack.empty();
        }

        BOOL Empty() const
        {
			guard_type guard(m_lock);
            return !m_stack.empty() || m_map.empty();
        }

        template<class UnaryOperation>
        void ForEach(UnaryOperation op)
        {
			guard_type guard(m_lock);
            BOOST_FOREACH (auto &pair, m_map)
                op(pair);
        }

        template<class UnaryOperation>
        void ForEach(UnaryOperation op) const
        {
			guard_type guard(m_lock);
            BOOST_FOREACH (auto const &pair, m_map)
                op(pair);
        }

        template<class TernaryOperation>
        Value AddOrUpdate(in_key_type key, in_value_type addValue, TernaryOperation updateValueFactory)
        {
			guard_type guard(m_lock);
            auto result = m_map.find(key);
            if (result == m_map.end())
            {
                m_map[key] = addValue;
                return addValue;
            }
            else
            {
                auto updateValue = (*result).second;
                updateValueFactory(key, updateValue, updateValue);
                m_map[key] = updateValue;
                return updateValue;
            }
        }

    private:
        mutable boost::mutex m_lock;
        boost::unordered_map<Key, Value, Hash, Pred, Alloc> m_map;
        std::stack<bool> m_stack;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Collections {

#endif  // #ifndef URASANDESU_CPPANONYM_COLLECTIONS_GLOBALSAFEDICTIONARY_H
