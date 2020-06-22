#pragma once

#include <iostream>
#include <memory>
#include "Component.hpp"
#include "Engine/RendererEngine/Drawable.hpp"
#include "Engine/RendererEngine/SFML/Font.hpp"

class FontComponent : public Components
{
public:
    std::shared_ptr<Eligos::NoDrawable::Font> m_font;
public:
    int x;
    int y;
    FontComponent(std::size_t id) : Components(id, getCompId()) {};
    virtual ~FontComponent() = default;
    static Components *Create(const std::size_t &id) { return new FontComponent(id); };
    virtual void modify(const std::string &path)
    {
        if (!m_font) {
            m_font.reset(new Eligos::NoDrawable::Font());
            m_font->loadFromFile(path);
        }
    };
    virtual void dump() {}
    std::size_t getEntityId() const { return m_entityId; };
    virtual Components *clone()
    {
        std::cout << "CREATION COPY Font" << std::endl;
        return new FontComponent(*this);
    }
    static std::size_t getCompId() { return 13; };
};
