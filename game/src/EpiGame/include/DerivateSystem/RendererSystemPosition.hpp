#pragma once

#include <memory>
#include "Engine/RendererEngine/Renderer.hpp"
#include "Engine/RendererEngine/SFML/SfmlRenderer.hpp"
#include "SystemBase.hpp"

class RendererSystemPosition : public SystemBase
{
private:
    std::unique_ptr<Eligos::RendererAPI> m_renderer;
public:
    RendererSystemPosition() : SystemBase(25), m_renderer(new Eligos::SfmlRenderer()) {}
    virtual void init();
    virtual void update(EventManager &eventManager, std::vector<Entities> &);
    virtual ~RendererSystemPosition() = default;
    // static SystemBase *Create() { return new RendererSystemPosition(); }
};