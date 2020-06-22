#pragma once

#include <iostream>
#include <memory>
#include "Component.hpp"
#include "Engine/RendererEngine/Drawable.hpp"
#include "Engine/RendererEngine/SFML/Text.hpp"
#include "Engine/RendererEngine/SFML/Sprite.hpp"

#include "DerivateComponent/TextureComponent.hpp"

class DrawableObjComponent : public Components
{
public:
    std::shared_ptr<Eligos::Drawable::Object> m_obj;
    enum class type {SPRITE, TEXT};
    type m_type;
public:
    DrawableObjComponent(std::size_t id) : Components(id, getCompId()){};
    virtual ~DrawableObjComponent() = default;
    static Components *Create(const std::size_t &id) { return new DrawableObjComponent(id); };
    virtual void modify(Eligos::NoDrawable::Font *font)
    {
        if (!m_obj)
        {
            m_obj.reset(new Eligos::Drawable::Text(font));
            m_obj->m_Type = Eligos::Drawable::Object::TYPE::TEXT;
        }
    };
    virtual void modify(const std::string &text)
    {
        if (m_obj)
            m_obj->setString(text);
    };
    virtual void modify(Eligos::NoDrawable::Texture *text)
    {
        std::cout << "CREATION TEXTURE" << std::endl;
        m_obj.reset(new Eligos::Drawable::Sprite(text));
        m_obj->m_Type = Eligos::Drawable::Object::TYPE::SPRITE;
    };
    virtual void dump() {}
    virtual Components *clone()
    {
        std::cout << "CREATION Drawable OBJ comp" << std::endl;
        return new DrawableObjComponent(*this);
    }
    std::size_t getEntityId() const { return m_entityId; };
    static std::size_t getCompId() { return 15; };
};