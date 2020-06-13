/*
** EpiGame Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#include <SFML/Graphics.hpp>

#include "EpiGameApp.hpp"

EpiGameApp::EpiGameApp(int ac, char **av) : Application{ac, av}
{
}

auto EpiGameApp::processEvent(const sf::Event &event) -> void
{
    Application::processEvent(event);
}

auto EpiGameApp::init() -> void
{
    m_fps_draw.setFont(m_defaultFont);
}

auto EpiGameApp::deinit() -> void
{
}

auto EpiGameApp::tick(float) -> void
{
}

auto EpiGameApp::draw() -> void
{
}
