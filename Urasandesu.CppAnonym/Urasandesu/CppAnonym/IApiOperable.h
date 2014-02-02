/* 
 * File: IApiOperable.h
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
#ifndef URASANDESU_CPPANONYM_IAPIOPERABLE_H
#define URASANDESU_CPPANONYM_IAPIOPERABLE_H

namespace Urasandesu { namespace CppAnonym {

    template<
        class HeapManagerType,
        class ApiType
    >        
    class ATL_NO_VTABLE IApiOperable
    {
    public:
        typedef HeapManagerType heap_manager_type;
        typedef ApiType api_type;
         
        IApiOperable() :
            m_pHeapManager(NULL),
            m_pApi(NULL)
        { }
        
        void Init(HeapManagerType *pHeapManager, ApiType *pApi)
        {
            m_pHeapManager = pHeapManager;
            m_pApi = pApi;
        }

        template<class T>
        T *CreatePseudo()
        {
            T *pObj = m_pHeapManager->NewPseudo<T>();
            pObj->Init(m_pHeapManager, m_pApi);
            return pObj;
        }

        HeapManagerType *GetHeapManager()
        {
            return m_pHeapManager;
        }

        ApiType *GetApi()
        {
            return m_pApi;
        }
    private:
        HeapManagerType *m_pHeapManager;
        ApiType *m_pApi;
    };
    
}}  // namespace Urasandesu { namespace CppAnonym {

#endif  // URASANDESU_CPPANONYM_IAPIOPERABLE_H
