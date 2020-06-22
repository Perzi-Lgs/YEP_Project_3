#pragma once

#include <bitset>
#include <array>
#include <map>
#include <vector>
#include <iostream>

#define MAX_COMPONENT 20

using ComponentList = std::bitset<MAX_COMPONENT>;
using ComponentArray = std::array<bool, MAX_COMPONENT>;

class Components
{
protected:
    std::size_t m_id; // * Id component
    std::size_t m_entityId; // * Id entity
public:
    Components(std::size_t idEntity, std::size_t idComp) : m_id(idComp), m_entityId(idEntity){};
    Components() = default;
    Components(const Components &) = default;
    Components(Components &&) = default;
    Components &operator=(const Components &) = default;
    Components &operator=(Components &&) = default;
    virtual ~Components() = default;

    std::size_t getId() const { return m_id; };
    std::size_t getEntityId() const { return m_entityId; };
    void setEntityId(std::size_t id) { m_entityId = id; };

    template <class T, class ...Args>
    void modify(Args... args) {
        reinterpret_cast<T *>(this)->modify(args...);
    }
    virtual Components *clone() = 0;
    virtual void dump() = 0;
};

// class ComponentofEntities
// {
// private:
//     std::vector<> m_component
// public:
//     ComponentofEntities() = default;
//     ~ComponentofEntities() = default;
// };
