#include "Entities.hpp"

void Entities::clear()
{
    m_listOfComp.reset();
    m_id = -1;
}

void Entities::setId(std::size_t id)
{
    m_id = id;
}

bool Entities::hasComponent(std::size_t idOfComponent) const
{
    return m_listOfComp.test(idOfComponent);
}

bool Entities::addComponent(std::size_t idOfComponent)
{
    if (!m_listOfComp.test(idOfComponent))
    {
        m_listOfComp.flip(idOfComponent);
        return true;
    }
    return false;
}

bool Entities::removeAllComponent()
{
    m_listOfComp.reset();
}

bool Entities::removeComponent(std::size_t idOfComponent)
{
    if (m_listOfComp.test(idOfComponent))
    {
        m_listOfComp.flip(idOfComponent);
        return true;
    }
    return false;
}

const ComponentList Entities::getComponents() const
{
    return m_listOfComp;
}