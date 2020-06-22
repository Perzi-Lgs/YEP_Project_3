#pragma once

#include <iostream>
#include "Component.hpp"

class VelocityComponent : public Components
{
public:
    float m_Velocity;
public:
    VelocityComponent() = default;
    VelocityComponent(std::size_t id) : Components(id, getCompId()){};
    virtual ~VelocityComponent() = default;
    static Components *Create(const std::size_t &id) { return new VelocityComponent(id); };
    virtual void modify(float Velocity) { m_Velocity = Velocity; }
    virtual void dump() { std::cout << "Velocity = " << m_Velocity << std::endl; }
    virtual Components *clone() { return new VelocityComponent(*this); }
    std::size_t getEntityId() const { return m_entityId; }
    static std::size_t getCompId() { return 1; };
};