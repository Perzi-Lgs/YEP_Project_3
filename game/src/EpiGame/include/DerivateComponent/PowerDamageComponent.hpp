#pragma once

#include <iostream>
#include "Component.hpp"

class PowerDamageComponent : public Components
{
public:
    uint16_t m_PowerDamage;
public:
    PowerDamageComponent() = default;
    PowerDamageComponent(std::size_t id) : Components(id, getCompId()){};
    virtual ~PowerDamageComponent() = default;
    static Components *Create(const std::size_t &id) { return new PowerDamageComponent(id); };
    virtual void modify(uint16_t PowerDamage) { m_PowerDamage = PowerDamage; }
    virtual void dump() { std::cout << "PowerDamage = " << m_PowerDamage << std::endl; }
    virtual Components *clone() { return new PowerDamageComponent(*this); }
    std::size_t getEntityId() const { return m_entityId; }
    static std::size_t getCompId() { return 10; };
};