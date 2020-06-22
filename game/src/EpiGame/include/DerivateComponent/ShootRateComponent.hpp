#pragma once

#include <iostream>
#include "Component.hpp"
#include "Clock.hpp"

class ShootRateComponent : public Components
{
public:
    Clock m_clock;
    float m_time;
public:
    ShootRateComponent() = default;
    ShootRateComponent(std::size_t id) : Components(id, getCompId()){};
    virtual ~ShootRateComponent() = default;
    static Components *Create(const std::size_t &id) { return new ShootRateComponent(id); };
    virtual void modify(float a) { m_time = a; }
    virtual void dump() { std::cout << "PowerDamage = " << m_clock.getClock().count() << std::endl; }
    virtual Components *clone() { return new ShootRateComponent(*this); }
    std::size_t getEntityId() const { return m_entityId; }
    static std::size_t getCompId() { return 16; };
};