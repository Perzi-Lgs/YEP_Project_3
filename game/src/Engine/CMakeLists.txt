add_library(
        ${PROJECT_NAME}Engine
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Settings/Settings.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/Engine/Settings/Settings.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/Engine/Utils/Platform.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/Engine/Utils/Warnings.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/Engine/Json.hpp

        ${CMAKE_CURRENT_SOURCE_DIR}/include/Engine/RendererEngine/Drawable.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/Engine/RendererEngine/Renderer.hpp


        ${CMAKE_CURRENT_SOURCE_DIR}/include/Engine/RendererEngine/SFML/DrawableObject.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/Engine/RendererEngine/SFML/NoDrawableObject.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/Engine/RendererEngine/SFML/Sfml.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/Engine/RendererEngine/SFML/ISound.hpp

        ${CMAKE_CURRENT_SOURCE_DIR}/include/Engine/RendererEngine/SFML/Texture.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/Engine/RendererEngine/SFML/Texture.cpp

        ${CMAKE_CURRENT_SOURCE_DIR}/include/Engine/RendererEngine/SFML/Font.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/Engine/RendererEngine/SFML/Font.cpp

        ${CMAKE_CURRENT_SOURCE_DIR}/include/Engine/RendererEngine/SFML/SfmlRenderer.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/Engine/RendererEngine/SFML/SfmlRenderer.cpp

        ${CMAKE_CURRENT_SOURCE_DIR}/include/Engine/RendererEngine/SFML/Sprite.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/Engine/RendererEngine/SFML/Sprite.cpp

        ${CMAKE_CURRENT_SOURCE_DIR}/include/Engine/RendererEngine/SFML/Text.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/Engine/RendererEngine/SFML/Text.cpp


        )
find_package(nlohmann_json 3.2.0 REQUIRED)

target_include_directories(${PROJECT_NAME}Engine PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME}Engine PUBLIC project_warnings project_options CONAN_PKG::sfml
        nlohmann_json::nlohmann_json)
