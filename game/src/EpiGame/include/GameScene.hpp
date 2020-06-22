#pragma once

#include <queue>
#include "Engine/Scene.hpp"
#include "Layer.hpp"

class GameScene final : public Engine::Scene
{
private:
    std::queue<int> &m_queueEvent;
    float m_deltaTime{};

    std::vector<Eligos::Layer> m_layers{};
public:
    auto onCreate(Engine::Application &app) -> bool override;
    auto onEvent(const sf::Event &event) -> void override;
    auto onTick(float deltaTime) -> void override;
    auto onDraw() -> void override;

    auto registerWindow(sf::RenderWindow &window) -> void override;
    GameScene(std::queue<int> &m_queueEvent);
    virtual ~GameScene() = default;
};