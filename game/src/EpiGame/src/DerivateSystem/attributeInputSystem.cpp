#include "DerivateSystem/attributeInputSystem.hpp"

void attributeInputSystem::update(EventManager &, std::vector<Entities> &)
{
    for (auto &i : *m_input)
    {
        if (m_queueEvent.size()) {
            i->modify(m_queueEvent.front());
            m_queueEvent.pop();
        } else
            i->modify(Eligos::input_keys::UNKNOW);
        }
}