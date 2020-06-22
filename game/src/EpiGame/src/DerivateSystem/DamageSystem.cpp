#include "DerivateSystem/DamageSystem.hpp"

void DamageSystem::update(EventManager &, int dealer, int taker)
{
    std::size_t dealt = static_cast<int>(dealer);
    std::size_t take = static_cast<int>(taker);
    for (auto &it : *m_damage)
    {
        for (auto &it2 : *m_heartPoint)
        {
            if ((it2->getEntityId() == take && it->getEntityId() == dealt) || (it->getEntityId() == take && it2->getEntityId() == dealt)) {
                it2->m_HearthPoint -= it->m_PowerDamage;
            }
        }
    }
}

void DamageSystem::update(EventManager &, std::vector<Entities> &)
{

}