add_executable(
        ${PROJECT_NAME}
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Main.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Layer.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/ComponentHolder.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/Layer.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/ComponentHolder.hpp


        ${CMAKE_CURRENT_SOURCE_DIR}/include/DerivateSystem/attributeInputSystem.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/DerivateSystem/BonusSystem.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/DerivateSystem/changeSpeedSystem.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/DerivateSystem/ColideSystem.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/DerivateSystem/DamageSystem.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/DerivateSystem/deathSystem.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/DerivateSystem/EndGameSystem.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/DerivateSystem/GraphicPositionSystem.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/DerivateSystem/moveSystem.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/DerivateSystem/PopMissileSystem.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/DerivateSystem/RendererSystemPosition.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/DerivateSystem/RenderSystem.hpp


        ${CMAKE_CURRENT_SOURCE_DIR}/src/DerivateSystem/attributeInputSystem.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/DerivateSystem/BonusSystem.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/DerivateSystem/changeSpeedSystem.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/DerivateSystem/ColideSystem.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/DerivateSystem/DamageSystem.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/DerivateSystem/deathSystem.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/DerivateSystem/EndGameSystem.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/DerivateSystem/GraphicPositionSystem.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/DerivateSystem/moveSystem.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/DerivateSystem/PopMissileSystem.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/DerivateSystem/RendererSystemPosition.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/DerivateSystem/RenderSystem.cpp

        ${CMAKE_CURRENT_SOURCE_DIR}/include/DerivateComponent/BonusComponent.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/DerivateComponent/AudioComponent.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/DerivateComponent/DirectionComponent.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/DerivateComponent/DrawableComponent.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/DerivateComponent/DrawableObjectComponent.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/DerivateComponent/FontComponent.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/DerivateComponent/FriendEntityComponent.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/DerivateComponent/HeartPointComponent.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/DerivateComponent/HitboxComponent.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/DerivateComponent/InputComponent.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/DerivateComponent/PlayableComponent.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/DerivateComponent/PositionComponent.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/DerivateComponent/PowerDamageComponent.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/DerivateComponent/ShootRateComponent.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/DerivateComponent/SpriteComponent.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/DerivateComponent/TeamComponent.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/DerivateComponent/TextComponent.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/DerivateComponent/TextureComponent.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/DerivateComponent/VelocityComponent.hpp
        
        ${CMAKE_CURRENT_SOURCE_DIR}/include/Entities.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Entities.cpp

        ${CMAKE_CURRENT_SOURCE_DIR}/include/EventManager.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/EventManager.cpp
        
        ${CMAKE_CURRENT_SOURCE_DIR}/include/IEvent.hpp

        ${CMAKE_CURRENT_SOURCE_DIR}/include/Application.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Application.cpp

        ${CMAKE_CURRENT_SOURCE_DIR}/include/ComponentFactory.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/ComponentFactory.cpp

        ${CMAKE_CURRENT_SOURCE_DIR}/include/SystemFactory.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/SystemFactory.cpp

        ${CMAKE_CURRENT_SOURCE_DIR}/include/SystemBase.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/SystemBase.cpp

        ${CMAKE_CURRENT_SOURCE_DIR}/include/Scene.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Scene.cpp

        ${CMAKE_CURRENT_SOURCE_DIR}/include/EntitiesFactory.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/EntitiesFactory.cpp

        ${CMAKE_CURRENT_SOURCE_DIR}/include/Server.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Server.cpp
       
        ${CMAKE_CURRENT_SOURCE_DIR}/src/enemies.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/ModifyValueScript.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Script.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/Script.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/ScriptName.hpp
)

find_package(nlohmann_json 3.2.0 REQUIRED)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/../Engine/include)
target_link_libraries(${PROJECT_NAME} PRIVATE ${PROJECT_NAME}Engine ${CMAKE_DL_LIBS} nlohmann_json::nlohmann_json)


