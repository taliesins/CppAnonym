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
    struct MethodNameMetadataEqualTo : 
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
    struct MethodNameMetadataHash : 
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
        class MethodNameMetadataApiHolder
    >    
    class BaseMethodNameMetadataProto905E2503
    {
    public:
        BaseMethodNameMetadataProto905E2503() { }

        std::wstring m_name;
    };

    typedef BaseMethodNameMetadataProto905E2503<> MethodNameMetadataProto905E2503;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {


// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_Test.*
namespace {

    TEST(Urasandesu_CppAnonym_Test, Test_01)
    {
        using namespace boost;
        using namespace Urasandesu::CppAnonym::Metadata;

        typedef MethodNameMetadataProto905E2503 MethodNameMetadata;
        typedef unordered_map<shared_ptr<MethodNameMetadata const>, std::wstring, MethodNameMetadataHash<>, MethodNameMetadataEqualTo<> > MethodNameMetadataMap;
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

}
