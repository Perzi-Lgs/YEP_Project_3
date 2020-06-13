/*
** EpiGimp Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#pragma once

#include <memory>

#include <Engine/Application.hpp>

class EpiGameApp final : public Engine::Application {
public:
    EpiGameApp(int ac, char **av);
    ~EpiGameApp() override = default;

    auto processEvent(const sf::Event &event) -> void override;
    auto init() -> void override;
    auto deinit() -> void override;
    auto tick(float deltaTime) -> void override;
    auto draw() -> void override;
};
