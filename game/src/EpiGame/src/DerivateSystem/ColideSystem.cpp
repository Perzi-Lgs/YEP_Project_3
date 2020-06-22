#include "DerivateSystem/ColideSystem.hpp"

void ColideSystem::checkColide(int indexposition, int indexhitbox, EventManager &eventManager)
{
    std::size_t indexP = static_cast<std::size_t>(indexposition);
    std::size_t indexH = static_cast<std::size_t>(indexhitbox);
    float y_top = ((*m_position)[indexP])->y - ((*m_hitbox)[indexH])->m_up;
    float y_bot = ((*m_position)[indexP])->y + ((*m_hitbox)[indexH])->m_down;
    float x_left = ((*m_position)[indexP])->x - ((*m_hitbox)[indexH])->m_backward;
    float x_right =((*m_position)[indexP])->x + ((*m_hitbox)[indexH])->m_forward;

    for (std::size_t it = std::size_t(indexposition + 1); it < m_position->size(); it++)
    {
        for (auto &it2 : *m_hitbox)
        {
            if(it2->getEntityId() == ((*m_position)[it])->getEntityId())
            {
                for (auto &it3: *m_bonus)
                {
                    if (it3->getEntityId() == ((*m_position)[it])->getEntityId())
                    {
                        if (y_top <= (((*m_position)[it])->y - it2->m_up) && y_bot >= (((*m_position)[it])->y + it2->m_down)
                        && x_left <= (((*m_position)[it])->x - it2->m_backward) && x_right >= (it2->m_forward + ((*m_position)[it])->x)
                        && (it3->m_bonus != ((*m_bonus)[indexH])->m_bonus))
                        {
                            eventManager.push(static_cast<IEvent *>(new BonusEvent(it3->m_bonus)));
                        }
                    }
                }
                for (auto &it3 : *m_team)
                {
                    if (it3->getEntityId() == ((*m_position)[it])->getEntityId())
                    {
                        if (y_top <= (((*m_position)[it])->y - it2->m_up) && y_bot >= (((*m_position)[it])->y + it2->m_down) 
                        && x_left <= (((*m_position)[it])->x -it2->m_backward) && x_right >= (it2->m_forward + ((*m_position)[it])->x) 
                        && (it3->m_isTeam != ((*m_team)[indexH])->m_isTeam))
                        {
                            std::cout << y_top << "  " << y_bot << std::endl;
                            std::cout << x_left << "  " << x_right << std::endl;
                            std::cout << ((*m_position)[it])->y - it2->m_up << "  " << ((*m_position)[it])->y + it2->m_down << std::endl;
                            std::cout <<  ((*m_position)[it])->x - it2->m_backward << "  " << it2->m_forward + ((*m_position)[it])->x << std::endl;
                            eventManager.push((IEvent *)new DamageEvent(it2->getEntityId(), ((*m_hitbox)[indexH])->getEntityId()));
                        }
                    }
                
                }
            }
        }
    }
}

void ColideSystem::update(EventManager &eventManager, std::vector<Entities> &entities)
{
    for (std::size_t it = 0; it <= (m_position->size() - 1) && m_position->size(); it++) 
    {
        for (std::size_t it2 = 0; it2 < (m_hitbox->size()); it2++)
            if (((*m_hitbox)[it2])->getEntityId() == ((*m_position)[it])->getEntityId()){
                std::cout << ((*m_hitbox)[it2])->getEntityId() << std::endl;
                checkColide(it, it2, eventManager);
            }
    }
}
