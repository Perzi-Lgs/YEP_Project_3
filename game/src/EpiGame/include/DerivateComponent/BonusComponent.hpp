#pragma once

#include <iostream>
#include "Component.hpp"

class BonusComponent : public Components
{
public:
    bool m_bonus;
public:
    BonusComponent() = default;
    BonusComponent(std::size_t id) : Components(id, getCompId()){};
    virtual ~BonusComponent() = default;
    static Components *Create(const std::size_t &id) { return new BonusComponent(id); };
    virtual void modify(bool Bonus) { m_bonus = Bonus; }
    virtual void dump() { std::cout << "Bonus = " << m_bonus << std::endl; }
    virtual Components *clone() { return new BonusComponent(*this); }
    std::size_t getEntityId() const { return m_entityId; }
    static std::size_t getCompId() { return 5; };
};