#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_HEAPPROVIDER_HPP
#include <Urasandesu/CppAnonym/HeapProvider.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_REPLACE_H
#include <Urasandesu/CppAnonym/Traits/Replace.h>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_EXTERNALAPISTRATEGIES_H
#include <Urasandesu/CppAnonym/Traits/ExternalApiStrategies.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASETYPEMETADATAPROTOB8DF5A21_H
#include <Urasandesu/CppAnonym/Metadata/BaseTypeMetadataProtoB8DF5A21.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETHODMETADATAPROTOB8DF5A21_H
#include <Urasandesu/CppAnonym/Metadata/BaseMethodMetadataProtoB8DF5A21.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_DEFAULTMETHODMETADATAAPIPROTOB8DF5A21_H
#include <Urasandesu/CppAnonym/Metadata/DefaultMethodMetadataApiProtoB8DF5A21.h>
#endif

#ifndef URASANDESU_CPPANONYM_SIMPLEBLOB_H
#include <Urasandesu/CppAnonym/SimpleBlob.h>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymException.h>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMCOMEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymCOMException.h>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMNOTIMPLEMENTEDEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymNotImplementedException.h>
#endif

#ifndef URASANDESU_CPPANONYM_COLLECTIONS_ITERABLE_H
#include <Urasandesu/CppAnonym/Collections/Iterable.h>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_DEFAULTHASH_H
#include <Urasandesu/CppAnonym/Utilities/DefaultHash.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    template<
        class AssemblyMetadataApiType
    >    
    class BaseAssemblyMetadataProtoB8DF5A21
    {
    };

    template<
        class MetadataDispenserApiType
    >    
    class BaseMetadataDispenserProtoB8DF5A21
    {
    };

    struct ITypeMetadataApi { };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_Hosting_BaseTypeMetadataProtoB8DF5A21Test.*
namespace {

    void SetupApis(boost::filesystem::path const &asmPath, 
                   std::wstring const &typeName, 
                   IMetaDataDispenserEx **ppMetaDispApi, 
                   IMetaDataImport2 **ppMetaImpApi, 
                   mdTypeDef &mdtd)
    {
        namespace fs = boost::filesystem;

        ASSERT_HRESULT_SUCCEEDED(
            ::CoCreateInstance(CLSID_CorMetaDataDispenser, NULL, 
                               CLSCTX_INPROC_SERVER, 
                               IID_IMetaDataDispenserEx, 
                               reinterpret_cast<void **>(ppMetaDispApi))
        ); 

        ASSERT_HRESULT_SUCCEEDED(
            (*ppMetaDispApi)->OpenScope(asmPath.c_str(), ofRead, 
                                        IID_IMetaDataImport2, 
                                        reinterpret_cast<IUnknown **>(ppMetaImpApi))
        );

        ASSERT_HRESULT_SUCCEEDED(
            (*ppMetaImpApi)->FindTypeDefByName(typeName.c_str(), NULL, &mdtd)
        );
    }

    TEST(Urasandesu_CppAnonym_Hosting_BaseTypeMetadataProtoB8DF5A21Test, Test_01)
    {
        namespace fs = boost::filesystem;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Metadata;

        // Arrange
        struct TestTypeMetadataApi  
        {
            typedef INT assembly_metadata_api_type;
            typedef INT method_metadata_api_type;
            typedef boost::mpl::vector<IMetaDataImport2> child_api_types;
        };

        typedef BaseTypeMetadataProtoB8DF5A21<TestTypeMetadataApi> TypeMetadata;
        typedef TypeMetadata::assembly_metadata_type AssemblyMetadata;

        fs::path asmPath(L"C:\\Windows\\assembly\\GAC_MSIL\\System.Core\\3.5.0.0__b77a5c561934e089\\System.Core.dll");
        std::wstring typeName(L"System.Func`1");
        ATL::CComPtr<IMetaDataDispenserEx> pMetaDispApi;
        ATL::CComPtr<IMetaDataImport2> pMetaImpApi;
        mdTypeDef mdtd = mdTypeDefNil;
        SetupApis(asmPath, typeName, &pMetaDispApi, &pMetaImpApi, mdtd);


        // Act
        AssemblyMetadata asmMeta;
        TypeMetadata typeMeta;
        typeMeta.Init(asmMeta, *pMetaImpApi);
        typeMeta.SetKey(mdtd);
        mdToken mdt = typeMeta.GetToken();


        // Assert
        ASSERT_EQ(0x02000058, mdt);
    }

    
    TEST(Urasandesu_CppAnonym_Hosting_BaseTypeMetadataProtoB8DF5A21Test, Test_02)
    {
        namespace fs = boost::filesystem;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Metadata;

        // Arrange
        struct TestTypeMetadataApi;

        struct TestMethodMetadataApi : 
            IMethodMetadataApi
        {
            typedef TestTypeMetadataApi parent_api_type;
            typedef boost::mpl::vector<IMetaDataImport2> child_api_types;
        };

        struct TestTypeMetadataApi : 
            ITypeMetadataApi  
        {
            typedef INT assembly_metadata_api_type;
            typedef INT method_metadata_api_type;
            typedef boost::mpl::vector<TestMethodMetadataApi, IMetaDataImport2> child_api_types;
        };

        typedef BaseTypeMetadataProtoB8DF5A21<TestTypeMetadataApi> TypeMetadata;
        typedef TypeMetadata::assembly_metadata_type AssemblyMetadata;
        typedef TypeMetadata::method_metadata_type MethodMetadata;

        fs::path asmPath(L"C:\\Windows\\assembly\\GAC_MSIL\\System.Core\\3.5.0.0__b77a5c561934e089\\System.Core.dll");
        std::wstring typeName(L"System.Func`1");
        ATL::CComPtr<IMetaDataDispenserEx> pMetaDispApi;
        ATL::CComPtr<IMetaDataImport2> pMetaImpApi;
        mdTypeDef mdtd = mdTypeDefNil;
        SetupApis(asmPath, typeName, &pMetaDispApi, &pMetaImpApi, mdtd);


        // Act
        AssemblyMetadata asmMeta;
        TypeMetadata typeMeta;
        typeMeta.Init(asmMeta, *pMetaImpApi);
        typeMeta.SetKey(mdtd);

        
        std::wstring name(L".ctor");
        
        CallingConventions callConvention = CallingConventions::CC_HAS_THIS;
        
        TypeMetadata retType;
        retType.SetKind(TypeKinds::TK_VOID);
        
        std::vector<TypeMetadata const *> paramTypes;
        TypeMetadata paramType0(TypeKinds::TK_OBJECT);
        paramTypes.push_back(&paramType0);
        TypeMetadata paramType1(TypeKinds::TK_I);
        paramTypes.push_back(&paramType1);
        
        MethodMetadata const *pMethodMeta = typeMeta.GetMethod(name, callConvention, &retType, paramTypes);
        ASSERT_FALSE(pMethodMeta == NULL);
        mdToken mdt = pMethodMeta->GetToken();

        MethodMetadata const *pMethodMeta2 = typeMeta.GetMethod(name, callConvention, &retType, paramTypes);


        // Assert
        ASSERT_EQ(0x06000232, mdt);
        ASSERT_EQ(pMethodMeta, pMethodMeta2);
    }

    
    TEST(Urasandesu_CppAnonym_Hosting_BaseTypeMetadataProtoB8DF5A21Test, Test_03)
    {
        namespace fs = boost::filesystem;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Metadata;

        // Arrange
        struct TestTypeMetadataApi;

        struct TestMethodMetadataApi : 
            IMethodMetadataApi
        {
            typedef TestTypeMetadataApi parent_api_type;
            typedef boost::mpl::vector<IMetaDataImport2> child_api_types;
        };

        struct TestTypeMetadataApi : 
            ITypeMetadataApi  
        {
            typedef INT assembly_metadata_api_type;
            typedef INT method_metadata_api_type;
            typedef boost::mpl::vector<TestMethodMetadataApi, IMetaDataImport2> child_api_types;
        };

        typedef BaseTypeMetadataProtoB8DF5A21<TestTypeMetadataApi> TypeMetadata;
        typedef TypeMetadata::assembly_metadata_type AssemblyMetadata;
        typedef TypeMetadata::method_metadata_type MethodMetadata;

        fs::path asmPath(L"C:\\windows\\assembly\\GAC_32\\mscorlib\\2.0.0.0__b77a5c561934e089\\mscorlib.dll");
        std::wstring typeName(L"System.DateTime");
        ATL::CComPtr<IMetaDataDispenserEx> pMetaDispApi;
        ATL::CComPtr<IMetaDataImport2> pMetaImpApi;
        mdTypeDef mdtd = mdTypeDefNil;
        SetupApis(asmPath, typeName, &pMetaDispApi, &pMetaImpApi, mdtd);


        // Act
        AssemblyMetadata asmMeta;
        TypeMetadata typeMeta;
        typeMeta.Init(asmMeta, *pMetaImpApi);
        typeMeta.SetKey(mdtd);

        
        std::wstring name(L"get_Now");
        
        CallingConventions callConvention = CallingConventions::CC_STANDARD;
        
        TypeMetadata retType;
        retType.SetKind(TypeKinds::TK_VALUETYPE);
        retType.SetKey(mdtd);
        
        std::vector<TypeMetadata const *> paramTypes;

        MethodMetadata const *pMethodMeta = typeMeta.GetMethod(name, callConvention, &retType, paramTypes);
        ASSERT_FALSE(pMethodMeta == NULL);
        mdToken mdt = pMethodMeta->GetToken();

        MethodMetadata const *pMethodMeta2 = typeMeta.GetMethod(name, callConvention, &retType, paramTypes);


        // Assert
        ASSERT_EQ(0x060002D2, mdt);
        ASSERT_EQ(pMethodMeta, pMethodMeta2);
    }

    
    TEST(Urasandesu_CppAnonym_Hosting_BaseTypeMetadataProtoB8DF5A21Test, Test_04)
    {
        namespace fs = boost::filesystem;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Metadata;
     
        typedef OpCodesProtoB8DF5A21 OpCodes;
        ASSERT_STREQ(L"CEE_NOP,nop,Pop0,Push0,InlineNone,IPrimitive,1,0xFF,0x00,NEXT", OpCodes::Nop.CStr());
        ASSERT_EQ(OpCodeTypes::CEE_NOP, OpCodes::Nop.GetType().Value());
        ASSERT_STREQ(L"nop", OpCodes::Nop.GetName().c_str());
        ASSERT_EQ(StackBehaviourTypes::SBT_POP0, OpCodes::Nop.GetBehaviour0().GetType().Value());
        ASSERT_EQ(StackBehaviourTypes::SBT_PUSH0, OpCodes::Nop.GetBehaviour1().GetType().Value());
        ASSERT_EQ(OperandParamTypes::OPT_INLINE_NONE, OpCodes::Nop.GetOperandParam().GetType().Value());
        ASSERT_EQ(OpCodeKindTypes::OKT_I_PRIMITIVE, OpCodes::Nop.GetOpCodeKind().GetType().Value());
        ASSERT_EQ(1, OpCodes::Nop.GetLength());
        ASSERT_EQ(0xFF, OpCodes::Nop.GetByte1());
        ASSERT_EQ(0x00, OpCodes::Nop.GetByte2());
        ASSERT_EQ(ControlFlowTypes::CFT_NEXT, OpCodes::Nop.GetControlFlow().GetType().Value());
    }

    
    TEST(Urasandesu_CppAnonym_Hosting_BaseTypeMetadataProtoB8DF5A21Test, Test_05)
    {
        namespace fs = boost::filesystem;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Metadata;

        StackBehaviour expected = StackBehaviours::PopRef();
        expected += StackBehaviours::PopI();
        expected += StackBehaviours::PopRef();
     
        typedef OpCodesProtoB8DF5A21 OpCodes;
        ASSERT_STREQ(L"CEE_STELEM_REF,stelem.ref,PopRef+PopI+PopRef,Push0,InlineNone,IObjModel,1,0xFF,0xA2,NEXT", OpCodes::Stelem_Ref.CStr());
        ASSERT_TRUE(expected == OpCodes::Stelem_Ref.GetBehaviour0());
    }

    
    TEST(Urasandesu_CppAnonym_Hosting_BaseTypeMetadataProtoB8DF5A21Test, Test_06)
    {
        namespace fs = boost::filesystem;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Metadata;

        StackBehaviour expected = StackBehaviours::PopRef();
        expected += StackBehaviours::PopI();
     
        typedef OpCodesProtoB8DF5A21 OpCodes;
        ASSERT_TRUE(expected != OpCodes::Stfld.GetBehaviour0());
    }

    
    TEST(Urasandesu_CppAnonym_Hosting_BaseTypeMetadataProtoB8DF5A21Test, Test_07)
    {
        namespace fs = boost::filesystem;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Metadata;

        typedef OpCodesProtoB8DF5A21 OpCodes;
        typedef OpCodeProtoB8DF5A21 OpCode;
#if 0
        typedef ILGeneratorProtoB8DF5A21 ILGenerator;
        typedef InstructionProtoB8DF5A21 Instruction;
        ILGenerator gen;
        gen.EmitWriteLine(L"Hello, world!!");
        gen.Emit(OpCodes::Ret);

        std::vector<boost::shared_ptr<Instruction const> > const &insts = gen.GetInstructions();
#endif
        // Instruction は ILGenerator が管理する？
        // →いや、そうすると、「この命令いらない」が簡単にできなくなるのか。
        //   →DeleteLast の Random Access 版を作るのはそこまで難しいことではない。
        //
        // コピーで引き回す。
        // →いや、そうすると、「この命令とこの命令の間に挿入」とか「この命令をこっちの命令に置き換え」みたいなことができないか。
        //   →全くできないってことはないけど、Instruction ID みたいな Primary Key 作って管理する必要がある。
        //     →それはめんどう・・・。
        // 
        // Instruction の構造を考えてみる。
        struct Instruction
        {
            OpCode *opcode;
            boost::any operand;
            Instruction *prev;
            Instruction *next;
        };

        std::cout << "Size of: " << sizeof(Instruction) << std::endl;
        // 12 バイト
        // →微妙・・・。Boost.Pool 使ってみよう。
        //   →あかん、shared_ptr と一緒に使うには、pool_allocator 使わなきゃだけど、
        //     中で Singleton_pool 使ってる。これだと、確保→消去する Memory の単位は
        //     「Tag 単位」「型単位」しかない・・・。
        //     このインスタンスが消えたら、保持していた Memory 一緒に消すっていうのが無い・・・。

        // カスタムアロケータ作るしかなさそう・・・。
        // →アロケータは状態を持ってはいけないことになってる。ほげぇ・・・。

        // Boost.Pool 版はやっぱりそんなに早くない。
        // →でも RapidVector 利用版は、ある閾値越えると、昔作った要素保持してても無効になっちゃう件。
        //   →まあ、昔作った要素触る時は、必ず operator [] 経由で見ればいいだけなので、気にしなくていいっちゃいい。
        //     →やっぱり RapidVector 利用版そのまま使うほうが良さそう。ポインタの引き回しだけしないようにしたい。
        //       →そうなると、Instruction *prev とかはだめ。もう一度 Instrcution の構造考えてみるか・・・。

#if 0
        std::vector<Instruction const *> const &insts = gen.GetInstructions();
        // この中で遅延初期化するのがいいのか・・・？

        template<
            class ILGeneratorApiType = DefaultILGeneratorApiProtoB8DF5A21
        >
        class ILGenerator :
            public HeapProvider<
                size_t, 
                boost::mpl::vector<
                    Instruction 
                >,
                VeryQuickHeapButMustUseSubscriptOperator
            >
        {
        public:
            typedef ILGenerator<ILGeneratorApiType> this_type;

            ILGenerator() : 
                m_instructionsInitialized(false)
            { }

            std::vector<Instruction const *> const &GetInstructions() const
            {
                if (!m_instructionsInitialized)
                {
                    typedef typename type_decided_by<Instruction>::type InstructionHeap;
                    InstructionHeap &heap = Of<Instruction>();
                }
                return m_instructions;
            }

        private:
            mutable bool m_instructionsInitialized;
            std::vector<Instruction const *> m_instructions;
        };
#endif   

        //StackBehaviour expected = StackBehaviours::PopRef;
        //expected += StackBehaviours::PopI;
     
        //typedef OpCodesProtoB8DF5A21 OpCodes;
        //ASSERT_TRUE(expected != OpCodes::Stfld.GetBehaviour0());
    }
}
