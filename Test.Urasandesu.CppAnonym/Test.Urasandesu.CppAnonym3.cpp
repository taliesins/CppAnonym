// Test.Urasandesu.CppAnonym.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"

// foward declarations
namespace Urasandesu { namespace CppAnonym { namespace Interfaces {

}}} // namespace Urasandesu { namespace CppAnonym { namespace Interfaces {

namespace Urasandesu { namespace CppAnonym { namespace ApiHolders {

}}} // namespace Urasandesu { namespace CppAnonym { namespace ApiHolders {

namespace Urasandesu { namespace CppAnonym {

}}   // namespace Urasandesu { namespace CppAnonym {

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

namespace Urasandesu { namespace CppAnonym { namespace Hosting { namespace Interfaces {

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting { namespace Interfaces {

namespace Urasandesu { namespace CppAnonym { namespace Hosting { namespace ApiHolders {

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting { namespace ApiHolders {

namespace Urasandesu { namespace CppAnonym { namespace Hosting {

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting {

namespace Urasandesu { namespace CppAnonym { namespace StrongNaming { namespace Interfaces {

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace StrongNaming { namespace Interfaces {

namespace Urasandesu { namespace CppAnonym { namespace StrongNaming { namespace ApiHolders {

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace StrongNaming { namespace ApiHolders {

namespace Urasandesu { namespace CppAnonym { namespace StrongNaming {

}}}   // namespace Urasandesu { namespace CppAnonym { namespace StrongNaming {

namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace Interfaces {

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace Interfaces {

namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

namespace Urasandesu { namespace CppAnonym { namespace Fusion { namespace Interfaces {

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Fusion { namespace Interfaces {

namespace Urasandesu { namespace CppAnonym { namespace Fusion { namespace ApiHolders {

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Fusion { namespace ApiHolders {

namespace Urasandesu { namespace CppAnonym { namespace Fusion {

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Fusion {

namespace Urasandesu { namespace CppAnonym { namespace ApiHolders {

}}} // namespace Urasandesu { namespace CppAnonym { namespace ApiHolders {

namespace Urasandesu { namespace CppAnonym {

}}   // namespace Urasandesu { namespace CppAnonym {

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

namespace Urasandesu { namespace CppAnonym { namespace Hosting { namespace ApiHolders {

    namespace DefaultHostInfoApiHolderDetail {
        
        //using boost::mpl::map;
        //using boost::mpl::pair;
        //using namespace Urasandesu::CppAnonym::Hosting::Interfaces;

        //struct DefaultHostInfoApiHolderImpl
        //{
        //    typedef map<
        //        pair<HostInfoLabel, HostInfo>,
        //        pair<HostInfoPersistedHandlerLabel, HostInfoPersistedHandler>,
        //        pair<RuntimeHostLabel, RuntimeHost>,
        //        pair<RuntimeHostPersistedHandlerLabel, RuntimeHostPersistedHandler>
        //    > api_cartridges;
        //};

    }   // namespace DefaultHostInfoApiHolderDetail {

    struct DefaultHostInfoApiHolder /*: 
        DefaultHostInfoApiHolderDetail::DefaultHostInfoApiHolderImpl*/
    {
    };

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting { namespace ApiHolders {

namespace Urasandesu { namespace CppAnonym { namespace Hosting {

    template<
        class HostInfoApiHolder
    >    
    class BaseHostInfo
    {
    public:
        BaseHostInfo()
        { }
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting {

namespace Urasandesu { namespace CppAnonym { namespace StrongNaming { namespace ApiHolders {

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace StrongNaming { namespace ApiHolders {

namespace Urasandesu { namespace CppAnonym { namespace StrongNaming {

}}}   // namespace Urasandesu { namespace CppAnonym { namespace StrongNaming {

namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

namespace Urasandesu { namespace CppAnonym { namespace Fusion { namespace ApiHolders {

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Fusion { namespace ApiHolders {

namespace Urasandesu { namespace CppAnonym { namespace Fusion {

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Fusion {


// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_Test3.*
namespace {

    CPPANONYM_TEST(Urasandesu_CppAnonym_Test3, Test_01)
    {
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Hosting;
        int a = 0;

        HostInfo &hostInfo = CppAnonymStorage::Object<HostInfo>();
    }

}
