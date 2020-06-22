#pragma once

#include <iostream>
#include <memory>
#include "Component.hpp"
#include "Engine/RendererEngine/Drawable.hpp"
#include "TextureComponent.hpp"
#include "Engine/RendererEngine/SFML/Sprite.hpp"

class SpriteComponent : public Components
{
public:
    std::shared_ptr<Eligos::Drawable::Sprite> m_sprite;
public:
    SpriteComponent(std::size_t id) : Components(0, id){};
    virtual ~SpriteComponent() = default;
    static Components *Create(const std::size_t &id) { return new SpriteComponent(id); };
    virtual void modify(Eligos::NoDrawable::Texture *text)
    {
        if (!m_sprite)
            m_sprite.reset(new Eligos::Drawable::Sprite(text));
    };
    virtual void dump() {}
    virtual Components *clone()
    {
        return new SpriteComponent(*this);
    }
    std::size_t getEntityId() const { return m_entityId; };
    static std::size_t getCompId() { return 12; };
};
