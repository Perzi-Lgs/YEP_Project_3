#pragma once

#include "Component.hpp"
#include <iostream>

class DirectionComponent : public Components
{
public:
    float m_Direction;

public:
    DirectionComponent() = default;
    DirectionComponent(float Direction) : m_Direction(Direction){};
    DirectionComponent(std::size_t id) : Components(id, getCompId()){};
    virtual ~DirectionComponent() = default;
    static Components *Create(const std::size_t &id) { return new DirectionComponent(id); };
    virtual void modify(float Direction) { m_Direction = Direction; }
    virtual void dump() { std::cout << "Direction = " << m_Direction << std::endl; }
    virtual Components *clone() { return new DirectionComponent(*this); }
    std::size_t getEntityId() const { return m_entityId; }
    static std::size_t getCompId() { return 4; };
};