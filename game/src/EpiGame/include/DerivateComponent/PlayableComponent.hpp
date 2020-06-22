#pragma once

#include "Component.hpp"

class PlayableComponent : public Components
{
public:
    bool m_playable;

public:
    PlayableComponent(std::size_t id) : Components(id, getCompId()){};
    virtual ~PlayableComponent() = default;
    static Components *Create(const std::size_t &id) { return new PlayableComponent(id); };
    virtual void modify(bool playable)
    {
        m_playable = playable;
    };
    virtual void dump() {}
    virtual Components *clone()
    {
        return new PlayableComponent(*this);
    }
    std::size_t getEntityId() const { return m_entityId; };
    static std::size_t getCompId() { return 8; };
};
