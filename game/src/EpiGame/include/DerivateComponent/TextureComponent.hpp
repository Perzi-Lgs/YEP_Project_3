#pragma once

#include <iostream>
#include <memory>
#include "Component.hpp"
#include "Engine/RendererEngine/Drawable.hpp"
#include "Engine/RendererEngine/SFML/Texture.hpp"

class TextureComponent : public Components
{
private:
    std::shared_ptr<Eligos::NoDrawable::Texture> m_texture;
    
public :
    TextureComponent(std::size_t id) : Components(id, getCompId()){};
    virtual ~TextureComponent() = default;
    static Components *Create(const std::size_t &id) { return new TextureComponent(id); };
    virtual void modify(const std::string &str)
    {
        if (!m_texture) {
            m_texture.reset(new Eligos::NoDrawable::Texture());
            m_texture->loadFromFile(str);
        }
    };
    virtual Components *clone() { return new TextureComponent(*this); };
    virtual void dump() {}
    static std::size_t getCompId() { return 15; };
};