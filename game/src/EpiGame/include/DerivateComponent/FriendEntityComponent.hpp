#pragma once

#include <iostream>
#include <memory>
#include "Component.hpp"

class FriendEntityComponent : public Components
{
public:
    int m_idFriend;
public:
    FriendEntityComponent(std::size_t id) : Components(id, getCompId()){};
    virtual ~FriendEntityComponent() = default;
    static Components *Create(const std::size_t &id) { return new FriendEntityComponent(id); };
    virtual void modify(int idFriend)
    {
        // if idFriend is true, missile won't touch allies
        m_idFriend = idFriend;
    };
    virtual void dump() {}
    std::size_t getEntityId() const { return m_entityId; };
    virtual Components *clone()
    {
        std::cout << "CREATION COPY FriendEntityComponent" << std::endl;
        return new FriendEntityComponent(*this);
    }
    static std::size_t getCompId() { return 17; };
};
