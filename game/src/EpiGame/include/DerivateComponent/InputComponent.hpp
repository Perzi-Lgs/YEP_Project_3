#pragma once

#include "Component.hpp"
#include "Engine/RendererEngine/SFML/SfmlRenderer.hpp"

class InputComponent : public Components
{
public:
    Eligos::input_keys m_input;

public:
    InputComponent(std::size_t id) : Components(id, getCompId()){};
    virtual ~InputComponent() = default;
    static Components *Create(const std::size_t &id) { return new InputComponent(id); };
    virtual void modify(int input)
    {
        m_input = static_cast<Eligos::input_keys>(input);
    };
    virtual void modify(Eligos::input_keys input)
    {
        m_input = input;
    };
    virtual void dump() {}
    virtual Components *clone()
    {
        return new InputComponent(*this);
    }
    std::size_t getEntityId() const { return m_entityId; };
    static std::size_t getCompId() { return 7; };
};
