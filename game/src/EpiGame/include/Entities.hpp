#pragma once

#include "Component.hpp"
// #include "Layer.hpp"

class Entities
{
private:
    std::size_t m_id;
    ComponentList m_listOfComp;
public:
    Entities() = delete;
    Entities(std::size_t id) : m_id(id){};
    Entities(const Entities &) = default;
    Entities(Entities &&) = default;
    Entities &operator=(const Entities &) = default;
    Entities &operator=(Entities &&) = default;
    ~Entities() = default;

    bool addComponent(std::size_t idOfComponent);
    bool hasComponent(std::size_t idOfComponent) const;
    bool removeComponent(std::size_t idOfComponent);
    bool removeAllComponent();

    std::size_t &getId() { return m_id; };
    std::size_t getId() const { return m_id; };
    const ComponentList getComponents() const;
    void setId(std::size_t m_id);
    void clear();
};