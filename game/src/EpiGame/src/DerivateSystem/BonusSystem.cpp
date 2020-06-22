#include "DerivateSystem/BonusSystem.hpp"

void bonusSystem::update(EventManager &, bool bonus)
{
    for (auto &it :  *m_bonus)
    {
        for (auto &it2 :*m_lifePoint)
        {
            if (it->m_bonus && bonus)
            {
                it2->m_HearthPoint += 1;
                it->m_bonus = false;
                std::cout << "LIFE: " << it2->m_HearthPoint << std::endl;
            }
        }
    }
}

void bonusSystem::update(EventManager &, std::vector<Entities> &entities)
{}