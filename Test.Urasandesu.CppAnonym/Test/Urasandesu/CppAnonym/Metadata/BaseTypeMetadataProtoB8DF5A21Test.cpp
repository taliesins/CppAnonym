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

#ifndef URASANDESU_CPPANONYM_SIMPLEHEAPPROVIDER_HPP
#include <Urasandesu/CppAnonym/SimpleHeapProvider.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_OBJECTTAG_HPP
#include <Urasandesu/CppAnonym/ObjectTag.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_DESTRUCTIONDISTRIBUTOR_HPP
#include <Urasandesu/CppAnonym/Utilities/DestructionDistributor.hpp>
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


    class Instruction
    {
    public:
        Instruction() : 
            m_pOpCode(NULL)
        { }
    
        OpCodeProtoB8DF5A21 const &GetOpCode() const
        {
            return *m_pOpCode;
        }
        
        void SetOpCode(OpCodeProtoB8DF5A21 const &opCode)
        {
            m_pOpCode = &opCode;
        }

        boost::any const &GetOprand() const
        {
            return m_oprand;
        }

        void SetOprand(boost::any const &oprand)
        {
            m_oprand = oprand;
        }

    private:
        OpCodeProtoB8DF5A21 const *m_pOpCode;
        boost::any m_oprand;
    };
    
    struct DefaultILGeneratorApiProtoB8DF5A21 { };

    template<
        class ILGeneratorApiType = DefaultILGeneratorApiProtoB8DF5A21
    >
    class BaseILGeneratorProtoB8DF5A21 :
        public SimpleHeapProvider<
            boost::mpl::vector<
                ObjectTag<Instruction, VeryQuickHeapButMustUseSubscriptOperator>
            >
        >
    {
    public:
        typedef BaseILGeneratorProtoB8DF5A21<ILGeneratorApiType> this_type;

        typedef typename Traits::ParentApiOrDefault<ILGeneratorApiType, IMethodMetadataApi>::type method_metadata_api_type;
        typedef BaseMethodMetadataProtoB8DF5A21<method_metadata_api_type> method_metadata_type;

        //typedef typename Traits::ChildApiOrDefault<AssemblyMetadataApiType, IMetadataDispenserApi>::type metadata_dispenser_api_type;
        //typedef BaseMetadataDispenserProtoB8DF5A21<metadata_dispenser_api_type> metadata_dispenser_type;
        // Parent ～とか Child ～とか区別するのがあほらしくなってきた・・・orz

        typedef ObjectTag<Instruction, VeryQuickHeapButMustUseSubscriptOperator> instruction_obj_tag_type;
        typedef typename type_decided_by<instruction_obj_tag_type>::type instruction_heap_type;

        BaseILGeneratorProtoB8DF5A21() : 
            m_instructionsInitialized(false)
        { }
        
        void Init(method_metadata_type &methodMeta) const
        {
            _ASSERTE(m_pMethodMeta == NULL);
            
            m_pMethodMeta = &methodMeta;
        }

        template<class T>
        T const *FindType() const { return static_cast<method_metadata_type const *>(m_pMethodMeta)->FindType<T>(); }

        template<class T>
        T *FindType() { return m_pMethodMeta->FindType<T>(); }
      
        template<>
        this_type const *FindType<this_type>() const { return this; }
      
        template<>
        this_type *FindType<this_type>() { return this; }

        void EmitWriteLine(LPCWSTR s)
        {
            typedef OpCodesProtoB8DF5A21 OpCodes;
            {
                Instruction *pInst = InstructionHeap().New();
                pInst->SetOpCode(OpCodes::Ldstr);
                pInst->SetOprand(std::wstring(s));
            }
            {
                Instruction *pInst = InstructionHeap().New();
                pInst->SetOpCode(OpCodes::Call);


                //pInst->SetOprand(std::wstring(s));
            }
            m_instructionsInitialized = false;
        }

        void Emit(OpCodeProtoB8DF5A21 const &op)
        {
            Instruction *pInst = InstructionHeap().New();
            pInst->SetOpCode(op);
            m_instructionsInitialized = false;
        }

        std::vector<Instruction const *> const &GetInstructions() const
        {
            if (!m_instructionsInitialized)
            {
                SIZE_T size = InstructionHeap().Size();
                std::vector<Instruction const *> instructions(size);
                for (SIZE_T i = 0; i < size; ++i)
                    instructions[i] = InstructionHeap()[i];
                instructions.swap(m_instructions);
                m_instructionsInitialized = true;
            }
            return m_instructions;
        }

    private:
        instruction_heap_type &InstructionHeap()
        {
            return Of<instruction_obj_tag_type>();
        }
        
        instruction_heap_type const &InstructionHeap() const
        {
            return Of<instruction_obj_tag_type>();
        }

        mutable method_metadata_type *m_pMethodMeta;
        mutable bool m_instructionsInitialized;
        mutable std::vector<Instruction const *> m_instructions;
    };

    typedef BaseILGeneratorProtoB8DF5A21<> ILGeneratorProtoB8DF5A21;

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
        using boost::any_cast;

        typedef MethodMetadataProtoB8DF5A21 MethodMetadata;
        typedef OpCodesProtoB8DF5A21 OpCodes;
        typedef OpCodeProtoB8DF5A21 OpCode;
        typedef ILGeneratorProtoB8DF5A21 ILGenerator;
        ILGenerator gen;
        gen.EmitWriteLine(L"Hello, world!!");
        gen.Emit(OpCodes::Ret);

        std::vector<Instruction const *> const &insts = gen.GetInstructions();
        ASSERT_EQ(3, insts.size());
        {
            OpCode const &op = insts[0]->GetOpCode();
            std::wstring const &s = any_cast<std::wstring const &>(insts[0]->GetOprand());
            ASSERT_EQ(&OpCodes::Ldstr, &op);
            ASSERT_STREQ(L"Hello, world!!", s.c_str());
        }
        {
            OpCode const &op = insts[1]->GetOpCode();
            MethodMetadata const *pMethodMeta = any_cast<MethodMetadata const *>(insts[1]->GetOprand());
            ASSERT_EQ(&OpCodes::Call, &op);
            ASSERT_EQ(0x060007C9, pMethodMeta->GetToken());
        }
        {
            OpCode const &op = insts[2]->GetOpCode();
            ASSERT_EQ(&OpCodes::Ret, &op);
        }
    }
}
