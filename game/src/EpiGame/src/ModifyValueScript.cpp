#include "Script.hpp"
#include "DerivateComponent/VelocityComponent.hpp"
#include "DerivateComponent/DrawableComponent.hpp"
#include "DerivateComponent/DirectionComponent.hpp"
#include "DerivateComponent/SpriteComponent.hpp"
#include "DerivateComponent/TextComponent.hpp"
#include "DerivateComponent/FontComponent.hpp"
#include "DerivateComponent/DrawableObjectComponent.hpp"
#include "DerivateComponent/DrawableComponent.hpp"
#include "DerivateComponent/InputComponent.hpp"
#include "DerivateComponent/TeamComponent.hpp"
#include "DerivateComponent/AudioComponent.hpp"
#include "DerivateComponent/HeartPointComponent.hpp"
#include "DerivateComponent/HitboxComponent.hpp"
#include "DerivateComponent/PowerDamageComponent.hpp"
#include "DerivateComponent/BonusComponent.hpp"
#include "DerivateComponent/ShootRateComponent.hpp"
#include "DerivateComponent/PlayableComponent.hpp"
#include "DerivateComponent/PositionComponent.hpp"

void ScriptManager::modifyValue(nlohmann::detail::iter_impl<nlohmann::json> i, Components *comp)
{
    if ((*i)["id"] == PositionComponent::getCompId()) {
        comp->modify<PositionComponent>((*i)["value"]);
    }
    else if ((*i)["id"] == VelocityComponent::getCompId())
    {
        comp->modify<VelocityComponent>((*i)["value"]);
    }
    else if ((*i)["id"] == DrawableComponent::getCompId())
    {
        comp->modify<DrawableComponent>((*i)["value"]);
    }
    else if ((*i)["id"] == DirectionComponent::getCompId())
    {
        comp->modify<DirectionComponent>((*i)["value"]);
    }
    else if ((*i)["id"] == DrawableComponent::getCompId())
    {
        comp->modify<DrawableComponent>((*i)["value"]);
    }
    else if ((*i)["id"] == TeamComponent::getCompId())
    {
        comp->modify<TeamComponent>((*i)["value"]);
    }
    else if ((*i)["id"] == HitboxComponent::getCompId())
    {
        comp->modify<HitboxComponent>((*i)["value"]);
    }
    else if ((*i)["id"] == HearthPointComponent::getCompId())
    {
        comp->modify<HearthPointComponent>((*i)["value"]);
    }
    else if ((*i)["id"] == PowerDamageComponent::getCompId())
    {
        comp->modify<PowerDamageComponent>((*i)["value"]);
    }
    else if ((*i)["id"] == BonusComponent::getCompId())
    {
        comp->modify<BonusComponent>((*i)["value"]);
    }
    else if ((*i)["id"] == AudioComponent::getCompId())
    {
        comp->modify<AudioComponent>((*i)["value"]);
    }
    else if ((*i)["id"] == ShootRateComponent::getCompId())
    {
        comp->modify<ShootRateComponent>((*i)["value"]);
    }
    else if ((*i)["id"] == PlayableComponent::getCompId())
    {
        comp->modify<PlayableComponent>((*i)["value"]);
    }
    if ((*i)["id"] == SpriteComponent::getCompId())
    {
        if (m_texture.find((*i)["value"]) == m_texture.end())
        {
            m_texture.insert({(*i)["value"], new Eligos::NoDrawable::Texture()});
            m_texture[(*i)["value"]]->loadFromFile((*i)["value"]);
        }
        comp->modify<DrawableObjComponent>(m_texture[(*i)["value"]]);
    }
    if ((*i)["id"] == TextComponent::getCompId())
    {
        if (m_font.find((*i)["value"][0]) == m_font.end())
        {
            m_font.insert({(*i)["value"][0], new Eligos::NoDrawable::Font()});
            m_font[(*i)["value"][0]]->loadFromFile((*i)["value"][0]);
        }
        comp->modify<DrawableObjComponent>(m_font[(*i)["value"][0]]);
        comp->modify<DrawableObjComponent>((*i)["value"][1]);
    }
}

void ScriptManager::modify(nlohmann::detail::iter_impl<nlohmann::json> i, std::string name, Eligos::Layer *layer)
{
    if ((*i)["Entity"].contains("Position"))
    {
        for (int j = 0; j < (*i)["Entity"]["Number"]; j++)
        {
            for (int k = 0; m_GeneratedEntity[(*i)["Entity"]["Code"]].size() > k; k++)
            {
                if (m_GeneratedEntity[(*i)["Entity"]["Code"]][k]->getId() == PositionComponent::getCompId())
                {
                    m_GeneratedEntity[(*i)["Entity"]["Code"]][k]->modify<PositionComponent>((*i)["Entity"]["Position"][j]);
                    generateEntityFromScript((*i)["Entity"]["Code"], layer);
                }
                // else if ()
                    // m_GeneratedEntity[(*i)["Entity"]["Code"]][k]->modify<PositionComponent>((*i)["Entity"]["Position"][j]);
                    // generateEntityFromScript((*i)["Entity"]["Code"], layer);
            }
        }
    }
}