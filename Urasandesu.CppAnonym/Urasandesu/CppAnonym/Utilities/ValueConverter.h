#pragma once
#ifndef URASANDESU_CPPANONYM_UTILITIES_VALUECONVERTER_H
#define URASANDESU_CPPANONYM_UTILITIES_VALUECONVERTER_H

#ifndef URASANDESU_CPPANONYM_TRAITS_REPLACE_H
#include <Urasandesu/CppAnonym/Traits/Replace.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    template<
        class AssemblyMetadataApiType
    >
    class BaseAssemblyMetadata;

    typedef BaseAssemblyMetadata<boost::use_default> AssemblyMetadata;

    struct DefaultAssemblyMetadataApi;

    template<
        class AssemblyMetadataApiType
    >
    class BaseMethodMetadata;

    template<
        class AssemblyMetadataApiType
    >
    class BaseTypeMetadata;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

namespace Urasandesu { namespace CppAnonym { namespace Profiling {

    template<
        class InfoProfilingApiType
    >
    class BaseProcessProfile;

    typedef BaseProcessProfile<boost::use_default> ProcessProfile;

    struct DefaultInfoProfilingApi;
    
    template<
        class InfoProfilingApiType
    >
    class BaseModuleProfile;

    template<
        class InfoProfilingApiType
    >
    class BaseMethodProfile;

    template<
        class InfoProfilingApiType
    >
    class BaseTypeProfile;

}}}  // namespace Urasandesu { namespace CppAnonym { namespace Profiling {

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#ifdef UNP
#error This .h reserves the word "UNP" that means "Urasandesu::CppAnonym::Profiling".
#endif
#define UNP Urasandesu::CppAnonym::Profiling

#ifdef UNM
#error This .h reserves the word "UNM" that means "Urasandesu::CppAnonym::Metadata".
#endif
#define UNM Urasandesu::CppAnonym::Metadata

#ifdef UNT
#error This .h reserves the word "UNT" that means "Urasandesu::CppAnonym::Traits".
#endif
#define UNT Urasandesu::CppAnonym::Traits

    template<class ToHeapManagerType, class FromHeapManagerType>
    struct ValueConverter;


    template<
        class AssemblyMetadataApiType,
        class InfoProfilingApiType
    >
    class ValueConverter<
        UNM::BaseAssemblyMetadata<AssemblyMetadataApiType> *, 
        UNP::BaseProcessProfile<InfoProfilingApiType> *
    >
    {
    public:
        typedef typename UNT::Replace<AssemblyMetadataApiType, boost::use_default, UNM::DefaultAssemblyMetadataApi>::type assembly_meta_data_api_type;
        typedef typename UNT::Replace<InfoProfilingApiType, boost::use_default, UNP::DefaultInfoProfilingApi>::type info_profiling_api_type;

        ValueConverter() : 
            m_pAsmMeta(NULL),
            m_pProcProf(NULL),
            m_pModProf(NULL)
        {
        }
        
        void Initialize(UNM::BaseAssemblyMetadata<AssemblyMetadataApiType> *pAsmMeta, 
                        UNP::BaseProcessProfile<InfoProfilingApiType> *pProcProf, 
                        UNP::BaseModuleProfile<InfoProfilingApiType> *pModProf)
        {
            
            HRESULT hr = E_FAIL;
            
            hr = pProcProf->GetApi()->ProfilerInfo->GetModuleMetadata(
                                                pModProf->GetID(), ofRead, 
                                                assembly_meta_data_api_type::IID_IImport, 
                                                reinterpret_cast<IUnknown **>(&pAsmMeta->GetApi()->Import));
            if (FAILED(hr))
                BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
            
            m_pAsmMeta = pAsmMeta;
            m_pProcProf = pProcProf;
            m_pModProf = pModProf;
        }

        bool HasInitialized()
        {
            return m_pAsmMeta != NULL && m_pProcProf != NULL && m_pModProf != NULL;
        }

        UNM::BaseMethodMetadata<AssemblyMetadataApiType> *Convert(UNP::BaseMethodProfile<InfoProfilingApiType> *from)
        {
            using namespace Urasandesu::CppAnonym::Metadata;
            HRESULT hr = E_FAIL;
            
            CComPtr<assembly_meta_data_api_type::IImport> pImport;
            mdToken mdt = mdTokenNil;
            hr = m_pProcProf->GetApi()->ProfilerInfo->GetTokenAndMetadataFromFunction(from->GetID(), 
                                                assembly_meta_data_api_type::IID_IImport, 
                                                reinterpret_cast<IUnknown **>(&pImport), &mdt);
            if (FAILED(hr))
                BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
            
            BaseMethodMetadata<AssemblyMetadataApiType> *pMethodMeta = NULL;
            pMethodMeta = m_pAsmMeta->CreateIfNecessary<BaseMethodMetadata<AssemblyMetadataApiType>>(mdt);
            return pMethodMeta;
        }

        UNP::BaseTypeProfile<InfoProfilingApiType> *ConvertBack(UNM::BaseTypeMetadata<AssemblyMetadataApiType> *to)
        {
            using namespace Urasandesu::CppAnonym::Profiling;
            HRESULT hr = E_FAIL;
            
            ClassID classId = 0;
            hr = m_pProcProf->GetApi()->ProfilerInfo->GetClassFromToken(m_pModProf->GetID(), to->GetToken(), &classId);
            if (FAILED(hr))
                BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
            
            BaseTypeProfile<InfoProfilingApiType> *pTypeProf = NULL;
            pTypeProf = m_pProcProf->CreateIfNecessary<BaseTypeProfile<InfoProfilingApiType>>(classId);
            return pTypeProf;
        }
        
        UNP::BaseMethodProfile<InfoProfilingApiType> *ConvertBack(UNM::BaseMethodMetadata<AssemblyMetadataApiType> *to)
        {
            using namespace Urasandesu::CppAnonym::Profiling;
            HRESULT hr = E_FAIL;
            
            FunctionID funcId = 0;
            hr = m_pProcProf->GetApi()->ProfilerInfo->GetFunctionFromToken(m_pModProf->GetID(), to->GetToken(), &funcId);
            if (FAILED(hr))
                BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
            
            BaseMethodProfile<InfoProfilingApiType> *pMethodProf = NULL;
            pMethodProf = m_pProcProf->CreateIfNecessary<BaseMethodProfile<InfoProfilingApiType>>(funcId);
            return pMethodProf;
        }

    private:
        UNM::BaseAssemblyMetadata<AssemblyMetadataApiType> *m_pAsmMeta;
        UNP::BaseProcessProfile<InfoProfilingApiType> *m_pProcProf;
        UNP::BaseModuleProfile<InfoProfilingApiType> *m_pModProf;
    };

#undef UNT
#undef UNM
#undef UNP

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_VALUECONVERTER_H