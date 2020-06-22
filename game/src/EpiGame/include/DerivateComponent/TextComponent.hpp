#pragma once

#include <iostream>
#include <memory>
#include "Component.hpp"
#include "Engine/RendererEngine/Drawable.hpp"
#include "Engine/RendererEngine/SFML/Text.hpp"

class TextComponent : public Components
{
public:
    std::shared_ptr<Eligos::Drawable::Text> m_text;
public:
    TextComponent(std::size_t id) : Components(id, getCompId()){};
    virtual ~TextComponent() = default;
    static Components *Create(const std::size_t &id) { return new TextComponent(id); };
    virtual void modify(Eligos::NoDrawable::Font *font)
    {
        if (!m_text) {
            m_text.reset(new Eligos::Drawable::Text(font));
        }
    };
    virtual void modify(const std::string &text)
    {
        if (m_text)
            m_text->setString(text);
    };
    virtual void dump() {}
    virtual Components *clone()
    {
        std::cout << "CREATION COPY text" << std::endl;
        return new TextComponent(*this);
    }
    static std::size_t getCompId() { return 14; };
};