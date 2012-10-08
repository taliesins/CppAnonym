#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_HEAPPROVIDER_HPP
#include <Urasandesu/CppAnonym/HeapProvider.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_REPLACE_H
#include <Urasandesu/CppAnonym/Traits/Replace.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASETYPEMETADATA_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseTypeMetadata.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTTYPEMETADATAAPIHOLDER_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultTypeMetadataApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETHODMETADATA_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseMethodMetadata.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMETHODMETADATAAPIHOLDER_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultMethodMetadataApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_SIMPLEBLOB_HPP
#include <Urasandesu/CppAnonym/SimpleBlob.hpp>
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

#ifndef URASANDESU_CPPANONYM_UTILITIES_HASH_HPP
#include <Urasandesu/CppAnonym/Utilities/Hash.hpp>
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

#ifndef URASANDESU_CPPANONYM_UTILITIES_ANYPOINTER_H
#include <Urasandesu/CppAnonym/Utilities/AnyPointer.h>
#endif

#ifndef URASANDESU_CPPANONYM_DEFAULTSTDMETHODWRAPPER_H
#include <Urasandesu/CppAnonym/DefaultSTDMETHODWrapper.h>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_CCOMOBJECTSLIM_HPP
#include <Urasandesu/CppAnonym/Utilities/CComObjectSlim.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_IMETADATAIMPORT2IMPL_HPP
#include <Urasandesu/CppAnonym/Metadata/IMetaDataImport2Impl.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INSTRUCTION_H
#include <Urasandesu/CppAnonym/Metadata/Instruction.h>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_CARTRIDGEAPISYSTEM_HPP
#include <Urasandesu/CppAnonym/Traits/CartridgeApiSystem.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_METADATADISPENSERAPIHOLDERLABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/MetadataDispenserApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_METADATADISPENSERLABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/MetadataDispenserLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETHODNAMEMETADATA_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseMethodNameMetadata.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_ASSEMBLYMETADATAAPIHOLDERLABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/AssemblyMetadataApiHolderLabel.hpp>
#endif

namespace {

    class ATL_NO_VTABLE MyMetaDataImport;
    typedef Urasandesu::CppAnonym::Utilities::CComObjectSlim<MyMetaDataImport> MyMetaDataImportObject;

}

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    //struct AssemblyNameMetadataApiHolderLabel { };

    //template<
    //    class AssemblyNameMetadataApiHolder
    //>    
    //class BaseAssemblyNameMetadata
    //{
    //public:
    //    std::wstring const &GetName() const
    //    {
    //        return m_name;
    //    }

    //private:
    //    mutable std::wstring m_name;
    //};

    //struct AssemblyMetadataApiHolderLabel { };

    template<
        class TestAssemblyMetadataApiType
    >    
    class BaseTestAssemblyMetadata
    {
    public:
        typedef BaseTestAssemblyMetadata<TestAssemblyMetadataApiType> this_type;

        typedef typename Traits::ApiAt<TestAssemblyMetadataApiType, Interfaces::AssemblyMetadataApiHolderLabel, IMetaDataImport2>::type metadata_import_api_type;

        //typedef typename Traits::ExternalApiOrDefault<TestAssemblyMetadataApiType, AssemblyMetadataApiHolderLabel, AssemblyNameMetadataApiHolderLabel>::type assembly_name_metadata_api_type;
        //typedef BaseAssemblyNameMetadata<assembly_name_metadata_api_type> assembly_name_metadata_type;

        typedef typename Traits::ApiAt<TestAssemblyMetadataApiType, Interfaces::AssemblyMetadataApiHolderLabel, Interfaces::TypeMetadataLabel>::type type_metadata_type;

        template<class T>
        T const *FindType() const 
        {
            if (m_pType.IsEmpty())
            {
                m_pType = new T();
            } 
            return m_pType;
        }

        type_metadata_type const *GetType(std::wstring const &name, TypeKinds const &kind) const
        {
            if (name == CONSOLE_NAME)
            {
                if (m_pConsole.IsEmpty())
                {
                    this_type *mutableThis = const_cast<this_type *>(this);

                    MyMetaDataImportObject *pMetaImpApi_ = NULL;
                    MyMetaDataImportObject::CreateInstance(&pMetaImpApi_); 
                    ATL::CComPtr<metadata_import_api_type> pMetaImpApi(pMetaImpApi_);

                    m_pConsole = new type_metadata_type();
                    type_metadata_type *pConsole = m_pConsole;
                    pConsole->Init(*mutableThis, *pMetaImpApi);
                    pConsole->SetName(name);
                    pConsole->SetKind(TypeKinds::TK_CLASS);
                }
                return m_pConsole;
            }
            return NULL;
        }

        void SetName(std::wstring const &name)
        {
        }

    private:
        static std::wstring const CONSOLE_NAME;
        mutable Utilities::AnyPointer m_pType;
        mutable Utilities::AnyPointer m_pConsole;
    };
    
    template<
        class TestAssemblyMetadataApiType
    >    
    std::wstring const BaseTestAssemblyMetadata<TestAssemblyMetadataApiType>::CONSOLE_NAME = std::wstring(L"System.Console");

    //struct MetadataDispenserLabel { };

    template<
        class TestMetadataDispenserApiType
    >    
    class BaseTestMetadataDispenser
    {
    public:
        typedef BaseTestMetadataDispenser<TestMetadataDispenserApiType> this_type;

        typedef typename Traits::ApiAt<TestMetadataDispenserApiType, Interfaces::MetadataDispenserApiHolderLabel, Interfaces::AssemblyMetadataLabel>::type assembly_metadata_type;
        
        assembly_metadata_type const *LoadAssembly(std::wstring const &name) const
        {
            if (m_pMSCorLib.IsEmpty())
            {
                m_pMSCorLib = new assembly_metadata_type();
                assembly_metadata_type *pMSCorLib = m_pMSCorLib;
                pMSCorLib->SetName(L"mscorlib, Version=2.0.0.0," 
                                   L" Culture=neutral, PublicKeyToken=b77a5c561934e089");
            }
            return m_pMSCorLib;
        }

    private:
        mutable Utilities::AnyPointer m_pMSCorLib;
    };


    //class Instruction
    //{
    //public:
    //    Instruction() : 
    //        m_pOpCode(NULL)
    //    { }
    //
    //    OpCode const &GetOpCode() const
    //    {
    //        return *m_pOpCode;
    //    }
    //    
    //    void SetOpCode(OpCode const &opCode)
    //    {
    //        m_pOpCode = &opCode;
    //    }

    //    boost::any const &GetOprand() const
    //    {
    //        return m_oprand;
    //    }

    //    void SetOprand(boost::any const &oprand)
    //    {
    //        m_oprand = oprand;
    //    }

    //private:
    //    OpCode const *m_pOpCode;
    //    boost::any m_oprand;
    //};
    
    struct IILGeneratorApi { };

    struct DefaultILGeneratorApiProtoB8DF5A21 : 
        IILGeneratorApi
    { 
        typedef boost::mpl::vector<ApiHolders::DefaultMethodMetadataApiHolder> external_api_types;
    };

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

        typedef typename Traits::ApiAt<ILGeneratorApiType, IILGeneratorApi, Interfaces::MethodMetadataLabel>::type method_metadata_type;
        typedef typename Traits::ApiAt<ILGeneratorApiType, IILGeneratorApi, Interfaces::TypeMetadataLabel>::type type_metadata_type;
        typedef typename Traits::ApiAt<ILGeneratorApiType, IILGeneratorApi, Interfaces::AssemblyMetadataLabel>::type assembly_metadata_type;
        typedef typename Traits::ApiAt<ILGeneratorApiType, IILGeneratorApi, Interfaces::MetadataDispenserLabel>::type metadata_dispenser_type;

        typedef ObjectTag<Instruction, VeryQuickHeapButMustUseSubscriptOperator> instruction_obj_tag_type;
        typedef typename type_decided_by<instruction_obj_tag_type>::type instruction_heap_type;

        BaseILGeneratorProtoB8DF5A21() : 
            m_pMethodMeta(NULL),
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
            typedef OpCodes OpCodes;
            {
                Instruction *pInst = InstructionHeap().New();
                pInst->SetOpCode(OpCodes::Ldstr);
                pInst->SetOprand(std::wstring(s));
            }
            {
                Instruction *pInst = InstructionHeap().New();
                pInst->SetOpCode(OpCodes::Call);

                this_type const *immutableThis = this;

                metadata_dispenser_type const *pMetaDisp = immutableThis->FindType<metadata_dispenser_type>();
                
                std::wstring const msCorLibName(L"mscorlib, Version=2.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089");
                assembly_metadata_type const *pMSCorLib = pMetaDisp->LoadAssembly(msCorLibName);
                
                std::wstring const consoleName(L"System.Console");
                type_metadata_type const *pConsole = pMSCorLib->GetType(consoleName, TypeKinds::TK_CLASS);
                
                std::wstring const writeLineName(L"WriteLine");
                CallingConventions cc = CallingConventions::CC_STANDARD;
                type_metadata_type const *pRetType = pMSCorLib->GetType(L"System.Void", TypeKinds::TK_VOID);
                std::vector<type_metadata_type const *> paramTypes;
                paramTypes.push_back(pMSCorLib->GetType(L"System.String", TypeKinds::TK_STRING));
                method_metadata_type const *pWriteLine = pConsole->GetMethod(writeLineName, cc, pRetType, paramTypes);

                pInst->SetOprand(pWriteLine);
            }
            m_instructionsInitialized = false;
        }

        void Emit(OpCode const &op)
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

#if 0
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
            typedef boost::mpl::vector<IMetaDataImport2> external_api_types;
        };

        typedef BaseTypeMetadata<TestTypeMetadataApi> TypeMetadata;
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
            MethodMetadataApiHolderLabel
        {
            typedef boost::mpl::vector<TestTypeMetadataApi, IMetaDataImport2> external_api_types;
        };

        struct TestTypeMetadataApi : 
            TypeMetadataApiHolderLabel  
        {
            typedef INT assembly_metadata_api_type;
            typedef INT method_metadata_api_type;
            typedef boost::mpl::vector<TestMethodMetadataApi, IMetaDataImport2> external_api_types;
        };

        typedef BaseTypeMetadata<TestTypeMetadataApi> TypeMetadata;
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
            MethodMetadataApiHolderLabel
        {
            typedef boost::mpl::vector<TestTypeMetadataApi, IMetaDataImport2> external_api_types;
        };

        struct TestTypeMetadataApi : 
            TypeMetadataApiHolderLabel  
        {
            typedef INT assembly_metadata_api_type;
            typedef INT method_metadata_api_type;
            typedef boost::mpl::vector<TestMethodMetadataApi, IMetaDataImport2> external_api_types;
        };

        typedef BaseTypeMetadata<TestTypeMetadataApi> TypeMetadata;
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
     
        typedef OpCodes OpCodes;
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
     
        typedef OpCodes OpCodes;
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
     
        typedef OpCodes OpCodes;
        ASSERT_TRUE(expected != OpCodes::Stfld.GetBehaviour0());
    }

#endif
    
#define CPPANONYM_TEST(test_case_name, test_name) \
    class GTEST_TEST_CLASS_NAME_(test_case_name, test_name); \
    void CppAnonymTest(GTEST_TEST_CLASS_NAME_(test_case_name, test_name)); \
    TEST(test_case_name, test_name) \
    { \
        using namespace Urasandesu::CppAnonym; \
        try \
        { \
            CppAnonymTest(GTEST_TEST_CLASS_NAME_(test_case_name, test_name)()); \
        } \
        catch (CppAnonymException &e) \
        { \
            std::cout << boost::diagnostic_information(e) << std::endl; \
            throw; \
        } \
        catch (...) \
        { \
            std::cout << boost::diagnostic_information(boost::current_exception()) << std::endl; \
            throw; \
        } \
    } \
    void CppAnonymTest(GTEST_TEST_CLASS_NAME_(test_case_name, test_name))

    CPPANONYM_TEST(Urasandesu_CppAnonym_Hosting_BaseTypeMetadataProtoB8DF5A21Test, Test_08)
    {
        using namespace std;
        using namespace Urasandesu::CppAnonym;

        cout << "Hello, World!!" << endl;

        //int i = 10;
        //ASSERT_EQ(3, i);

        BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
    }


    //class ATL_NO_VTABLE MyMetaDataImport;
    //typedef Urasandesu::CppAnonym::Utilities::CComObjectSlim<MyMetaDataImport> MyMetaDataImportObject;

    class ATL_NO_VTABLE MyMetaDataImport : 
        public ATL::CComObjectRootEx<ATL::CComSingleThreadModel>,
        public Urasandesu::CppAnonym::Metadata::IMetaDataImport2Impl<IMetaDataImport2>
    {
    public:
        MyMetaDataImport() { }

    BEGIN_COM_MAP(MyMetaDataImport)
        COM_INTERFACE_ENTRY_IID(IID_IMetaDataImport2, IMetaDataImport2)
    END_COM_MAP()

        DECLARE_PROTECT_FINAL_CONSTRUCT()

        HRESULT FinalConstruct() { return S_OK; }
        void FinalRelease() { }
    };

    CPPANONYM_TEST(Urasandesu_CppAnonym_Hosting_BaseTypeMetadataProtoB8DF5A21Test, Test_07)
    {
        // TODO: せっかく NotImplementedException スローしてるのに Google Test で丸められちゃう。カスタム class 作ったほうが良さそうね。
        namespace fs = boost::filesystem;
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Metadata;
        using boost::any_cast;

        typedef OpCodes OpCodes;
        typedef OpCode OpCode;

        struct TestAssemblyMetadataApiHolder;

        struct TestMetadataDispenserApiHolder
        {
            typedef mpl::map<mpl::pair<Interfaces::AssemblyMetadataApiHolderLabel, TestAssemblyMetadataApiHolder>, 
                             mpl::pair<Interfaces::AssemblyMetadataLabel, BaseTestAssemblyMetadata<TestAssemblyMetadataApiHolder>>> api_cartridges;
        };

        struct TestTypeMetadataApiHolder;
    
        struct TestAssemblyMetadataApiHolder
        {
            typedef mpl::map<mpl::pair<Interfaces::TypeMetadataApiHolderLabel, TestTypeMetadataApiHolder>,
                             mpl::pair<Interfaces::TypeMetadataLabel, BaseTypeMetadata<TestTypeMetadataApiHolder>>, 
                             mpl::pair<IMetaDataImport2, IMetaDataImport2>, 
                             mpl::pair<Interfaces::MetadataDispenserLabel, BaseTestMetadataDispenser<TestMetadataDispenserApiHolder>>> api_cartridges;
        };

        struct TestMethodMetadataApiHolder;
        struct TestILGeneratorApiHolder;

        struct TestMethodNameMetadataApiHolder
        {
            typedef mpl::map<mpl::pair<Interfaces::TypeMetadataLabel, BaseTypeMetadata<TestTypeMetadataApiHolder> > > api_cartridges;
        };

        struct TestTypeMetadataApiHolder
        {
            typedef mpl::map<mpl::pair<IMetaDataImport2, IMetaDataImport2>, 
                             mpl::pair<Interfaces::AssemblyMetadataApiHolderLabel, TestAssemblyMetadataApiHolder>,
                             mpl::pair<Interfaces::MethodMetadataApiHolderLabel, TestMethodMetadataApiHolder>, 
                             mpl::pair<IILGeneratorApi, TestILGeneratorApiHolder>, 
                             mpl::pair<Interfaces::AssemblyMetadataLabel, BaseTestAssemblyMetadata<TestAssemblyMetadataApiHolder> >, 
                             mpl::pair<Interfaces::MethodNameMetadataLabel, BaseMethodNameMetadata<TestMethodMetadataApiHolder> >, 
                             mpl::pair<Interfaces::MethodMetadataLabel, BaseMethodMetadata<TestMethodMetadataApiHolder> >, 
                             mpl::pair<Interfaces::TypeMetadataLabel, BaseTypeMetadata<TestTypeMetadataApiHolder> >,
                             mpl::pair<Interfaces::MethodNameMetadataLabel, BaseMethodNameMetadata<TestMethodNameMetadataApiHolder> > > api_cartridges;
        };

        struct TestMethodMetadataApiHolder
        {
            typedef mpl::map<mpl::pair<IMetaDataImport2, IMetaDataImport2>, 
                             mpl::pair<Interfaces::TypeMetadataLabel, BaseTypeMetadata<TestTypeMetadataApiHolder> >, 
                             mpl::pair<Interfaces::MethodNameMetadataLabel, BaseMethodNameMetadata<TestMethodNameMetadataApiHolder> > > api_cartridges;
        };

        struct TestILGeneratorApiHolder
        {
            typedef mpl::map<mpl::pair<Interfaces::MetadataDispenserLabel, BaseTestMetadataDispenser<TestMetadataDispenserApiHolder>>,
                             mpl::pair<Interfaces::AssemblyMetadataLabel, BaseTestAssemblyMetadata<TestAssemblyMetadataApiHolder>>, 
                             mpl::pair<Interfaces::TypeMetadataLabel, BaseTypeMetadata<TestTypeMetadataApiHolder>>, 
                             mpl::pair<Interfaces::MethodMetadataLabel, BaseMethodMetadata<TestMethodMetadataApiHolder>>> api_cartridges;
        };

        typedef BaseILGeneratorProtoB8DF5A21<TestILGeneratorApiHolder> ILGenerator;
        typedef ILGenerator::method_metadata_type MethodMetadata;
        typedef MethodMetadata::type_metadata_type TypeMetadata;
        typedef MethodMetadata::metadata_import_api_type MetaDataImportApi;
        typedef TypeMetadata::assembly_metadata_type AssemblyMetadata;

        AssemblyMetadata asmMeta;
        
        MyMetaDataImportObject *pMetaImpApi_ = NULL;
        ASSERT_HRESULT_SUCCEEDED(MyMetaDataImportObject::CreateInstance(&pMetaImpApi_)); 
        ATL::CComPtr<MetaDataImportApi> pMetaImpApi(pMetaImpApi_);
        //MetaDataImportApi *pMetaImpApi = NULL;

        TypeMetadata typeMeta;
        typeMeta.Init(asmMeta, *pMetaImpApi);

        MethodMetadata methodMeta;
        methodMeta.Init(typeMeta, *pMetaImpApi); 
        
        ILGenerator gen;
        gen.Init(methodMeta);
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
            ASSERT_STREQ(L"WriteLine", pMethodMeta->GetName().c_str());
        }
        {
            OpCode const &op = insts[2]->GetOpCode();
            ASSERT_EQ(&OpCodes::Ret, &op);
        }
    }
}
