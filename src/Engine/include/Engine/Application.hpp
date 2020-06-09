/*
** EpiGimp Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#pragma once

#include <cstdint>
#include <memory>
#include <iostream>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>

#include "Engine/Settings/Settings.hpp"
#include "Scene.hpp"

namespace Engine {

/**
 * @brief The Application abstract class is the core of a C++ application with this engine.
 *
 * Inherit this class and call the start() function in your main.
 */
class Application {
public:
    /**
     * @brief Application constructor
     * @param ac Program argument count
     * @param av Program arguments
     */
    Application(int ac, char **av);

    /**
     * @brief Default destructor
     */
    virtual ~Application();

    /**
     * @brief Starts the application.
     * @param title Title of your window
     */
    auto start(const std::string_view &title) -> void;

    /**
     * @brief Called after the window has been initialized and before the application loop.
     */
    virtual auto init() -> void = 0;

    /**
     * @brief Called on application closure.
     */
    virtual auto deinit() -> void = 0;

    /**
     * @brief Called after events and before draw()
     * @param deltaTime Frame time
     */
    virtual auto tick(float deltaTime) -> void = 0;

    /**
     * @brief Called after logic and events
     */
    virtual auto draw() -> void = 0;

protected:
    sf::RenderWindow m_window;
    std::unique_ptr<Scene> m_scene{nullptr};

    std::string_view m_binName;
    std::vector<std::string_view> m_arguments;

    std::uint32_t m_fps{0};
    sf::Time m_deltaTime{};

    float m_deltaTimeSeconds{0.f};

    /**
     * @brief Creates a new scene and register it to the Application.
     * @tparam S Your Scene class, inherited from the Scene class.
     * @tparam Args Argument types to be forwarded to your Scene.
     * @param args Arguments to forward to the Scene constructor.
     * @return true on success, false otherwise.
     */
    template<typename S, typename... Args>
    auto createScene(Args &&... args) -> bool
    {
        m_scene = std::make_unique<S>(std::forward<Args>(args)...);

        if (!m_scene->onCreate(*this)) {
            std::cerr << "Failed to create scene\n";
            m_scene.reset(nullptr);
            return false;
        }
        m_scene->registerWindow(m_window);
        return true;
    }

    /**
     * @brief Reloads the view, usually after window resize.
     */
    virtual auto reloadView() -> void final;

    /**
     * @brief Process the events. Don't forget to call the parent function if overridden.
     * @param event Event to process
     */
    virtual auto processEvent(const sf::Event &event) -> void;

private:
    sf::Font m_defaultFont{};
    Settings m_settings;

    /**
     * @brief Draws the fps counter and delta time.
     */
    auto drawFps() const -> void;
};

} // namespace Engine
