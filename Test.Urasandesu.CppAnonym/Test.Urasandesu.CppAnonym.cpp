// Test.Urasandesu.CppAnonym.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_UTILITIES_EQUALTO_HPP
#include <Urasandesu/CppAnonym/Utilities/EqualTo.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_EQUALITYCOMPARABLE_HPP
#include <Urasandesu/CppAnonym/Traits/EqualityComparable.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_HASHCOMPUTABLE_HPP
#include <Urasandesu/CppAnonym/Traits/HashComputable.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_OBJECTTAG_HPP
#include <Urasandesu/CppAnonym/ObjectTag.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_DESTRUCTIONDISTRIBUTOR_HPP
#include <Urasandesu/CppAnonym/Utilities/DestructionDistributor.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_SIMPLEHEAP_HPP
#include <Urasandesu/CppAnonym/SimpleHeap.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_SIMPLEHEAPPROVIDER_HPP
#include <Urasandesu/CppAnonym/SimpleHeapProvider.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    // Stack にあるか Heap にあるかを判別可能。
    // Delete するかどうかを調整可能。
    // 

    template<class T>
    class ATL_NO_VTABLE SwitchIntruded
    {
    public:
        typedef T type;

        SwitchIntruded() : 
            m_enabled(false),
            m_refCount(0)
        { }
        inline bool IsEnabled() const { return m_enabled; }
        inline void SetEnabled(bool value) { m_enabled = value; }
    protected:
        ~SwitchIntruded() { }
    private:
        bool m_enabled;
        //mutable boost::detail::atomic_count m_refCount;
        mutable INT m_refCount;

        inline friend void intrusive_ptr_add_ref(type const *p)
        {
            ++p->m_refCount;
        }

        inline friend void intrusive_ptr_release(type const *p)
        {
            if (--p->m_refCount == 0 && p->IsEnabled())
                delete p;
        }
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    struct DefaultMethodNameMetadataApiHolderProto905E2503
    {
    };

    template<
        class MethodNameMetadataApiHolder = DefaultMethodNameMetadataApiHolderProto905E2503
    >    
    class BaseMethodNameMetadataProto905E2503;





    template<
        class MethodNameMetadataApiHolder = DefaultMethodNameMetadataApiHolderProto905E2503
    >    
    struct MethodNameMetadataSharedPtrEqualTo : 
        Traits::EqualityComparable<boost::shared_ptr<BaseMethodNameMetadataProto905E2503<MethodNameMetadataApiHolder> const> >
    {
        result_type operator()(param_type x, param_type y) const
        {
            _ASSERTE(x.get() != NULL && y.get() != NULL);
            
            return x->m_name == y->m_name;
        }
    };

    template<
        class MethodNameMetadataApiHolder = DefaultMethodNameMetadataApiHolderProto905E2503
    >    
    struct MethodNameMetadataSharedPtrHash : 
        Traits::HashComputable<boost::shared_ptr<BaseMethodNameMetadataProto905E2503<MethodNameMetadataApiHolder> const> >
    {
        result_type operator()(param_type v) const
        {
            using namespace boost;

            _ASSERTE(v.get() != NULL);
            
            std::size_t seed = 0;
            hash_combine(seed, hash_value(v->m_name));
            return seed;
        }
    };





    template<
        class MethodNameMetadataApiHolder = DefaultMethodNameMetadataApiHolderProto905E2503
    >    
    struct MethodNameMetadataIntrusivePtrEqualTo : 
        Traits::EqualityComparable<boost::intrusive_ptr<BaseMethodNameMetadataProto905E2503<MethodNameMetadataApiHolder> const> >
    {
        result_type operator()(param_type x, param_type y) const
        {
            _ASSERTE(x.get() != NULL && y.get() != NULL);
            
            return x->m_name == y->m_name;
        }
    };

    template<
        class MethodNameMetadataApiHolder = DefaultMethodNameMetadataApiHolderProto905E2503
    >    
    struct MethodNameMetadataIntrusivePtrHash : 
        Traits::HashComputable<boost::intrusive_ptr<BaseMethodNameMetadataProto905E2503<MethodNameMetadataApiHolder> const> >
    {
        result_type operator()(param_type v) const
        {
            using namespace boost;

            _ASSERTE(v.get() != NULL);
            
            std::size_t seed = 0;
            hash_combine(seed, hash_value(v->m_name));
            return seed;
        }
    };
    
    
    
    
    
    template<
        class MethodNameMetadataApiHolder
    >    
    class BaseMethodNameMetadataProto905E2503 : 
        public Utilities::SwitchIntruded<BaseMethodNameMetadataProto905E2503<MethodNameMetadataApiHolder> >
    {
    public:
        typedef BaseMethodNameMetadataProto905E2503<MethodNameMetadataApiHolder> this_type;

        BaseMethodNameMetadataProto905E2503()
        { }
        
        std::wstring m_name;
    };

    typedef BaseMethodNameMetadataProto905E2503<> MethodNameMetadataProto905E2503;
    




    template<
        class TypeMetadataApiHolder
    >    
    class BaseTypeMetadataProtoA1348031 : 
        public SimpleHeapProvider<
            boost::mpl::vector<
                ObjectTag<MethodNameMetadataProto905E2503, QuickHeap>
            >
        >
    {
    public:
        typedef BaseTypeMetadataProtoA1348031<TypeMetadataApiHolder> this_type;

        typedef MethodNameMetadataProto905E2503 method_name_metadata_type;

        typedef ObjectTag<MethodNameMetadataProto905E2503, QuickHeap> method_name_metadata_obj_tag_type;
        typedef typename type_decided_by<method_name_metadata_obj_tag_type>::type method_name_metadata_heap_type;

        BaseTypeMetadataProtoA1348031() { }

        method_name_metadata_type *NewMethodName(std::wstring const &name) const
        {
            this_type *mutableThis = const_cast<this_type *>(this);

            method_name_metadata_type *pMethodNameMeta = NULL;
            pMethodNameMeta = mutableThis->MethodNameMetadataHeap().New();
            pMethodNameMeta->m_name = name;
            return pMethodNameMeta;
        }

    private:
        method_name_metadata_heap_type &MethodNameMetadataHeap()
        {
            return Of<method_name_metadata_obj_tag_type>();
        }
        
        method_name_metadata_heap_type const &MethodNameMetadataHeap() const
        {
            return Of<method_name_metadata_obj_tag_type>();
        }
    };

    typedef BaseTypeMetadataProtoA1348031<boost::mpl::void_> TypeMetadataProtoA1348031;
}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    template<class T>
    boost::intrusive_ptr<T> CreateSwitchIntruded(SwitchIntruded<T> &r)
    {
        r.SetEnabled(false);
        return boost::intrusive_ptr<T>(static_cast<T *>(&r));
    }

    template<class T>
    boost::intrusive_ptr<T> CreateSwitchIntruded(SwitchIntruded<T> *p)
    {
        p->SetEnabled(true);
        return boost::intrusive_ptr<T>(static_cast<T *>(p));
    }
    

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_Test.*
namespace {

    TEST(Urasandesu_CppAnonym_Test, Test_01)
    {
        using namespace boost;
        using namespace Urasandesu::CppAnonym::Metadata;

        typedef MethodNameMetadataProto905E2503 MethodNameMetadata;
        typedef unordered_map<shared_ptr<MethodNameMetadata const>, std::wstring, MethodNameMetadataSharedPtrHash<>, MethodNameMetadataSharedPtrEqualTo<> > MethodNameMetadataMap;
        MethodNameMetadataMap map;
        BOOST_MPL_ASSERT((is_same<MethodNameMetadataMap::value_type::first_type, shared_ptr<MethodNameMetadata const> const>));
        {
            shared_ptr<MethodNameMetadata> pMethodNameMeta(make_shared<MethodNameMetadata>());
            pMethodNameMeta->m_name = L"GetType";
            map[pMethodNameMeta] = L"aiueo";
            std::wcout << map[pMethodNameMeta] << std::endl;
        }
        {
            shared_ptr<MethodNameMetadata> pMethodNameMeta(make_shared<MethodNameMetadata>());
            pMethodNameMeta->m_name = L"GetType";
            map[pMethodNameMeta] = L"kakikukeko";
            std::wcout << map[pMethodNameMeta] << std::endl;
        }

        ASSERT_EQ(1, map.size());
        for (MethodNameMetadataMap::const_iterator i = map.begin(), i_end = map.end(); i != i_end; ++i)
        {
            std::wcout << L"Key: " << (*i).first << ", Value: " << (*i).second << std::endl;
        }
    }

    TEST(Urasandesu_CppAnonym_Test, Test_02)
    {
        using namespace Urasandesu::CppAnonym::Utilities;

        typedef EqualTo<int const *> EqualTo;
        EqualTo equalTo;

        int i = 10;
        int *pi1 = &i;
        int *pi2 = &i;
        ASSERT_TRUE(equalTo(pi1, pi2));
    }

    

    
    
    TEST(Urasandesu_CppAnonym_Test, Test_03)
    {
        using namespace boost;
        using namespace Urasandesu::CppAnonym::Metadata;
        using namespace Urasandesu::CppAnonym::Utilities;

        typedef MethodNameMetadataProto905E2503 MethodNameMetadata;

        // On Heap
        {
            MethodNameMetadata *pMethodNameMeta_ = NULL;
            pMethodNameMeta_ = new MethodNameMetadata();
            intrusive_ptr<MethodNameMetadata> pMethodNameMeta(CreateSwitchIntruded(pMethodNameMeta_));
        }

        // On Stack
        {
            MethodNameMetadata methodNameMeta;
            intrusive_ptr<MethodNameMetadata> pMethodNameMeta(CreateSwitchIntruded(methodNameMeta));
        }

        // Creating object on the heap at once. After that, the object is retrieved from a set by an object on stack.
        {
            typedef MethodNameMetadataIntrusivePtrHash<> Hash;
            typedef MethodNameMetadataIntrusivePtrEqualTo<> EqualTo;
            typedef unordered_set<intrusive_ptr<MethodNameMetadata>, Hash, EqualTo> MethodNameMetadataSet;
            MethodNameMetadataSet methodNameMetaSet;
            MethodNameMetadata *pMethodNameMeta_ = NULL;
            {
                pMethodNameMeta_ = new MethodNameMetadata();
                intrusive_ptr<MethodNameMetadata> pMethodNameMeta(CreateSwitchIntruded(pMethodNameMeta_));
                pMethodNameMeta->m_name = L"aiueo";
                methodNameMetaSet.insert(pMethodNameMeta);
            }

            MethodNameMetadataSet::iterator result;
            {
                MethodNameMetadata methodNameMeta;
                methodNameMeta.m_name = L"aiueo";
                intrusive_ptr<MethodNameMetadata> pMethodNameMeta(CreateSwitchIntruded(methodNameMeta));
                result = methodNameMetaSet.find(pMethodNameMeta);
                ASSERT_NE(methodNameMetaSet.end(), result);
                ASSERT_NE(&methodNameMeta, (*result).get());
                ASSERT_EQ(pMethodNameMeta_, (*result).get());
            }
        }
    }

    

    
    
    TEST(Urasandesu_CppAnonym_Test, Test_04)
    {
        using namespace boost;
        using namespace Urasandesu::CppAnonym::Metadata;
        using namespace Urasandesu::CppAnonym::Utilities;

        typedef MethodNameMetadataProto905E2503 MethodNameMetadata;

#ifdef _DEBUG
        INT const COUNT = 10000;
#else
        INT const COUNT = 1000000;
#endif

        timer t;
        std::vector<shared_ptr<MethodNameMetadata> > vec1(COUNT);
        t.restart();
        double typicalElapsed = 0.0;

        {
            for (INT i = 0; i < COUNT; ++i)
            {
                shared_ptr<MethodNameMetadata> pMethodNameMeta(make_shared<MethodNameMetadata>());
                pMethodNameMeta->m_name = L"aiueo";
                vec1.push_back(pMethodNameMeta);
            }
        
            typicalElapsed = t.elapsed();
        }
        
        std::vector<intrusive_ptr<MethodNameMetadata> > vec2(COUNT);
        typedef MethodNameMetadataIntrusivePtrHash<> Hash;
        typedef MethodNameMetadataIntrusivePtrEqualTo<> EqualTo;
        typedef unordered_set<intrusive_ptr<MethodNameMetadata>, Hash, EqualTo> MethodNameMetadataSet;
        MethodNameMetadataSet methodNameMetaSet;
        t.restart();
        double sbElapsed = 0.0;

        {

            for (INT i = 0; i < COUNT; ++i)
            {
                MethodNameMetadata keyMethodNameMeta;
                keyMethodNameMeta.m_name = L"aiueo";
                intrusive_ptr<MethodNameMetadata> pKeyMethodNameMeta(CreateSwitchIntruded(keyMethodNameMeta));
                MethodNameMetadataSet::iterator result = methodNameMetaSet.find(pKeyMethodNameMeta);
                if (result == methodNameMetaSet.end())
                {
                    MethodNameMetadata *pMethodNameMeta_ = NULL;
                    pMethodNameMeta_ = new MethodNameMetadata();
                    pMethodNameMeta_->m_name = keyMethodNameMeta.m_name;
                    methodNameMetaSet.insert(CreateSwitchIntruded(pMethodNameMeta_));
                    std::cout << "Hoge!!" << std::endl;
                }
                else
                {
                    vec2.push_back(*result);
                }
            }

            sbElapsed = t.elapsed();
        }
        
        std::vector<MethodNameMetadata> vec3(COUNT);
        t.restart();
        double sbElapsed2 = 0.0;

        {
            for (INT i = 0; i < COUNT; ++i)
            {
                MethodNameMetadata methodNameMeta;
                methodNameMeta.m_name = L"aiueo";
                vec3.push_back(methodNameMeta);
            }
        
            sbElapsed2 = t.elapsed();
        }
        
        std::vector<MethodNameMetadata *> vec4(COUNT);
        typedef TypeMetadataProtoA1348031 TypeMetadata;
        TypeMetadata typeMeta;
        t.restart();
        double sbElapsed3 = 0.0;

        {
            for (INT i = 0; i < COUNT; ++i)
            {
                MethodNameMetadata *pMethodNameMeta = NULL;
                pMethodNameMeta = typeMeta.NewMethodName(L"aiueo");
                vec4.push_back(pMethodNameMeta);
            }
        
            sbElapsed3 = t.elapsed();
        }
        
        std::cout << "Typical Way: " << typicalElapsed << std::endl;
        std::cout << "Simple Blob: " << sbElapsed << std::endl;
        std::cout << "Simple Blob2: " << sbElapsed2 << std::endl;
        std::cout << "Simple Blob3: " << sbElapsed3 << std::endl;
        ASSERT_LT(sbElapsed, typicalElapsed);
        // -- コピーなし（vec*.push_back の部分をコメントアウト）
        // Typical Way: 0.103
        // Simple Blob: 0.187
        // Simple Blob2: 0.05
        // 
        // -- コピーあり
        // Typical Way: 0.145（x1.41 劣化）
        // Simple Blob: 0.342 (x1.82 劣化)
        // Simple Blob2: 0.341 (x6.82 劣化)

        // スタックに置く場合でも、コピーが入ると効率がやっぱり段違いに変わる。
        // スタック => ヒープ変換行う場合は、劣化率は低いけど元が遅い。
        // 通常の方法がやはり高速。メモリの断片化が起こらないのであれば・・・。

        // 通常の方法で、Boost.Pool や SimpleHeap が使えるといいのだよね。
        // 親の親に管理させるパターン + 不必要になったタイミングでクリーンアップ、ってのはどうだ？
        // →Boost.Pool が最適！

        // -- Release モードでの計測（コピーあり）
        // ★Debug モードと大きく結果が異なるのが面白い！
        // Typical Way: 1.0516                    ※ヒープバージョン
        // Simple Blob: 0.2714（x3.9 faster）     ※スタック => ヒープ変換バージョン
        // Simple Blob2: 0.2994（x3.5 faster）    ※完全コピーバージョン
        // Simple Blob2: 0.1624（x6.5 faster）    ※Boost.Pool バージョン
        // ・ヒープバージョンはやっぱり遅かった。
        // ・Boost.Pool の結果が素晴らしい。
        // ・スタック => ヒープ変換バージョンと完全コピーバージョンはほぼ同等。
        //   メンバ数が増えてくのであれば、スタック => ヒープ変換バージョンを選ぶかな？ぐらい。
        //   ただ、前述の通り、Boost.Pool の結果が素晴らしいので、これを選ぶ優位性は無さそう。
    }


}
