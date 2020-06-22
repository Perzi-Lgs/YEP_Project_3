#pragma once

#include <iostream>
#include <memory>
#include "Component.hpp"

class TeamComponent : public Components
{
public:
    bool m_isTeam;
public:
    TeamComponent(std::size_t id) : Components(id, getCompId()){};
    virtual ~TeamComponent() = default;
    static Components *Create(const std::size_t &id) { return new TeamComponent(id); };
    virtual void modify(bool isTeam)
    {
        // if isTeam is true, missile won't touch allies
        m_isTeam = isTeam;
    };
    virtual void dump() {}
    std::size_t getEntityId() const { return m_entityId; };
    virtual Components *clone()
    {
        std::cout << "CREATION COPY Team" << std::endl;
        return new TeamComponent(*this);
    }
    static std::size_t getCompId() { return 18; };
};
