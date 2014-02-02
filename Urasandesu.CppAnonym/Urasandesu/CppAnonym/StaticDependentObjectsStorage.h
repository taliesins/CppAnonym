/* 
 * File: StaticDependentObjectsStorage.h
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
#ifndef URASANDESU_CPPANONYM_STATICDEPENDENTOBJECTSSTORAGE_H
#define URASANDESU_CPPANONYM_STATICDEPENDENTOBJECTSSTORAGE_H

#ifndef URASANDESU_CPPANONYM_DEPENDENTOBJECTSPROVIDER_H
#include <Urasandesu/CppAnonym/DependentObjectsProvider.h>
#endif

#ifndef URASANDESU_CPPANONYM_STATICDEPENDENTOBJECTSSTORAGEFWD_H
#include <Urasandesu/CppAnonym/StaticDependentObjectsStorageFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym {

    namespace StaticDependentObjectsStorageDetail {

        template<class T0, CPPANONYM_STATIC_DEPENDENT_OBJECTS_STORAGE_ENUM_SHIFTED_PARAMS(class T)>
        struct DependentObjectsProvidersHost : 
            DependentObjectsProvider<T0, CPPANONYM_STATIC_DEPENDENT_OBJECTS_STORAGE_ENUM_SHIFTED_PARAMS(T)>
        {
        };

        template<class T0, CPPANONYM_STATIC_DEPENDENT_OBJECTS_STORAGE_ENUM_SHIFTED_PARAMS(class T)>
        class StaticDependentObjectsStorageImpl
        {
        public:
            typedef DependentObjectsProvidersHost<T0, CPPANONYM_STATIC_DEPENDENT_OBJECTS_STORAGE_ENUM_SHIFTED_PARAMS(T)> host_type;
        
            template<class T>
            static T &Object()
            {
                typedef typename host_type::provider_of<T>::type provider_type;
                provider_type &provider = Host().ProviderOf<T>();
                return provider.Object();
            }

        private:
            template<class T0, CPPANONYM_STATIC_DEPENDENT_OBJECTS_STORAGE_ENUM_SHIFTED_PARAMS(class T)>
            friend struct HostAccessor;

            static host_type &Host()
            {
                static host_type host;
                return host;
            }
        };

        template<class T0, CPPANONYM_STATIC_DEPENDENT_OBJECTS_STORAGE_ENUM_SHIFTED_PARAMS(class T)>
        struct HostAccessor
        {
            static DependentObjectsProvidersHost<T0, CPPANONYM_STATIC_DEPENDENT_OBJECTS_STORAGE_ENUM_SHIFTED_PARAMS(T)> &Host()
            {
                return StaticDependentObjectsStorageImpl<T0, CPPANONYM_STATIC_DEPENDENT_OBJECTS_STORAGE_ENUM_SHIFTED_PARAMS(T)>::Host();
            }
        };

    }   // namespace StaticDependentObjectsStorageDetail {

    template<class T0, CPPANONYM_STATIC_DEPENDENT_OBJECTS_STORAGE_ENUM_SHIFTED_PARAMS(class T)>
    struct StaticDependentObjectsStorage : 
        StaticDependentObjectsStorageDetail::StaticDependentObjectsStorageImpl<T0, CPPANONYM_STATIC_DEPENDENT_OBJECTS_STORAGE_ENUM_SHIFTED_PARAMS(T)>
    {
    };

}}   // namespace Urasandesu { namespace CppAnonym {

#endif  // #ifndef URASANDESU_CPPANONYM_STATICDEPENDENTOBJECTSSTORAGE_H
