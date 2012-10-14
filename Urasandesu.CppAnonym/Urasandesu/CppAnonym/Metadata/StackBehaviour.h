#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_STACKBEHAVIOUR_H
#define URASANDESU_CPPANONYM_METADATA_STACKBEHAVIOUR_H

#ifndef URASANDESU_CPPANONYM_METADATA_STACKBEHAVIOURTYPES_H
#include <Urasandesu/CppAnonym/Metadata/StackBehaviourTypes.h>
#endif

#ifndef URASANDESU_CPPANONYM_COLLECTIONS_ITERABLE_H
#include <Urasandesu/CppAnonym/Collections/Iterable.h>
#endif

#ifndef URASANDESU_CPPANONYM_SAFEENUM_H
#include <Urasandesu/CppAnonym/SafeEnum.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_STACKBEHAVIOURFWD_H
#include <Urasandesu/CppAnonym/Metadata/StackBehaviourFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    class StackBehaviour
    {
    public:
        inline StackBehaviour(StackBehaviourTypes const &type) : 
            m_type(type)
        {
            m_typeList.push_back(type); 
        }

        inline StackBehaviour operator +(StackBehaviour const &other) const
        {
            return StackBehaviour(GetTypeList(), other.GetTypeList());
        }

        inline StackBehaviour &operator +=(StackBehaviour const &other)
        {
            m_typeList.insert(m_typeList.end(), other.GetTypeList().begin(), other.GetTypeList().end());
            return *this;
        }

        inline bool operator ==(StackBehaviour const &other) const
        {
            using namespace Urasandesu::CppAnonym::Collections;
            return SequenceEqual(GetTypeList().begin(), GetTypeList().end(), 
                                 other.GetTypeList().begin(), other.GetTypeList().end());
        }

        inline bool operator !=(StackBehaviour const &other) const
        {
            return !(*this == other);
        }

        inline StackBehaviourTypes const &GetType() const { return m_type; }
        inline std::vector<StackBehaviourTypes> const &GetTypeList() const { return m_typeList; }

    private:
        inline StackBehaviour(std::vector<StackBehaviourTypes> const &typeList1, std::vector<StackBehaviourTypes> const &typeList2)
        { 
            m_typeList.reserve(typeList1.size() + typeList2.size());
            m_typeList.insert(m_typeList.end(), typeList1.begin(), typeList1.end());
            m_typeList.insert(m_typeList.end(), typeList2.begin(), typeList2.end());
        }

        StackBehaviourTypes m_type;
        std::vector<StackBehaviourTypes> m_typeList;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_STACKBEHAVIOUR_H