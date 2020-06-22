#include <algorithm>
#include "Layer.hpp"
#include "DerivateSystem/RenderSystem.hpp"
#include "DerivateSystem/GraphicPositionSystem.hpp"
#include "DerivateSystem/attributeInputSystem.hpp"
#include "DerivateSystem/changeSpeedSystem.hpp"
#include "DerivateSystem/PopMissileSystem.hpp"
#include "DerivateSystem/ColideSystem.hpp"
#include "DerivateSystem/DamageSystem.hpp"
#include "DerivateSystem/deathSystem.hpp"
#include "DerivateSystem/BonusSystem.hpp"
#include "DerivateSystem/EndGameSystem.hpp"
#include "DerivateSystem/moveSystem.hpp"

namespace Eligos
{
    void Layer::removeEntity(Entities &entity)
    {
        for (std::size_t i = 0; i < m_entities.size(); i++)
        {
            if (m_entities[i].getId() == entity.getId()) {
                m_entities.erase(m_entities.begin() + i);
                return;
            }
        }
    }

    void Layer::removeComponent(Entities entity, int compId)
    {
        m_Holder.removeComponent(entity, compId);
    }

    void Layer::removeAllComponent(Entities entity)
    {
        m_Holder.removeAllComponent(entity);
    }

    void Layer::addEntity(Entities &entity)
    {
        m_entities.emplace_back(std::move(entity));
    }

    void Layer::addEntities(std::vector<Entities> &entities)
    {
        m_entities.insert(m_entities.end(), entities.begin(), entities.end());
    }

    bool Layer::update()
    {
        for (auto &i : m_system)
        {
            i->update(eventManager, m_entities);
            // if (!eventManager.isEmpty()) {
            // tmpEvent = eventManager.processEvent();
                // if (tmpEvent->m_type == type_event::CREATE_COMPONENT) {
            // for (auto &i : m_system) {
                // if (tmpEvent->getId() == i->getId()) {
            // using namespace std::placeholders;
            // m_threadPool.enqueue(std::bind(&SystemBase::update, &(*i), _1, _2), m_entities);
                // }
        }
        return true;
    }

    void Layer::addSystem(SystemBase *newSystem)
    {
        if (newSystem->getId() == 0) {
            std::size_t id = DrawableObjComponent::getCompId();
            static_cast<RenderSystem *>(newSystem)->init(m_Holder.template getComponent<DrawableObjComponent>(id));
        }
        else if (newSystem->getId() == 2)
        {
            std::size_t id = PositionComponent::getCompId();
            static_cast<GraphicPositionSystem *>(newSystem)->init(m_Holder.template getComponent<PositionComponent>(id));
            id = DrawableObjComponent::getCompId();
            static_cast<GraphicPositionSystem *>(newSystem)->init(m_Holder.template getComponent<DrawableObjComponent>(id));
        }
        else if (newSystem->getId() == 1)
        {
            std::size_t id = PositionComponent::getCompId();
            static_cast<moveSystem *>(newSystem)->init(m_Holder.template getComponent<PositionComponent>(id));
            id = VelocityComponent::getCompId();
            static_cast<moveSystem *>(newSystem)->init(m_Holder.template getComponent<VelocityComponent>(id));
            id = DirectionComponent::getCompId();
            static_cast<moveSystem *>(newSystem)->init(m_Holder.template getComponent<DirectionComponent>(id));
            id = TeamComponent::getCompId();
            static_cast<moveSystem *>(newSystem)->init(m_Holder.template getComponent<TeamComponent>(id));
            id = PlayableComponent::getCompId();
            static_cast<moveSystem *>(newSystem)->init(m_Holder.template getComponent<PlayableComponent>(id));
        } else if (newSystem->getId() == 5)
        {
            std::size_t id = InputComponent::getCompId();
            static_cast<attributeInputSystem *>(newSystem)->init(m_Holder.template getComponent<InputComponent>(id));
        }
        else if (newSystem->getId() == 6)
        {
            std::size_t id = InputComponent::getCompId();
            static_cast<changeSpeedSystem *>(newSystem)->init(m_Holder.template getComponent<InputComponent>(id));
            id = DirectionComponent::getCompId();
            static_cast<changeSpeedSystem *>(newSystem)->init(m_Holder.template getComponent<DirectionComponent>(id));
            id = VelocityComponent::getCompId();
            static_cast<changeSpeedSystem *>(newSystem)->init(m_Holder.template getComponent<VelocityComponent>(id));
        }
        else if (newSystem->getId() == 11)
        {
            std::size_t id = InputComponent::getCompId();
            static_cast<PopMissilesystem *>(newSystem)->init(m_Holder.template getComponent<InputComponent>(id));
            id = PositionComponent::getCompId();
            static_cast<PopMissilesystem *>(newSystem)->init(m_Holder.template getComponent<PositionComponent>(id));
            id = ShootRateComponent::getCompId();
            static_cast<PopMissilesystem *>(newSystem)->init(m_Holder.template getComponent<ShootRateComponent>(id));
        }
        else if (newSystem->getId() == 400)
        {
            std::size_t id = PositionComponent::getCompId();
            static_cast<ColideSystem *>(newSystem)->init(m_Holder.template getComponent<PositionComponent>(id));
            id = HitboxComponent::getCompId();
            static_cast<ColideSystem *>(newSystem)->init(m_Holder.template getComponent<HitboxComponent>(id));
            id = TeamComponent::getCompId();
            static_cast<ColideSystem *>(newSystem)->init(m_Holder.template getComponent<TeamComponent>(id));
            id = BonusComponent::getCompId();
            static_cast<ColideSystem *>(newSystem)->init(m_Holder.template getComponent<BonusComponent>(id));
        }
        else if (newSystem->getId() == 100)
        {
            std::size_t id = PowerDamageComponent::getCompId();
            static_cast<DamageSystem *>(newSystem)->init(m_Holder.template getComponent<PowerDamageComponent>(id));
            id = HearthPointComponent::getCompId();
            static_cast<DamageSystem *>(newSystem)->init(m_Holder.template getComponent<HearthPointComponent>(id));
        }
        else if (newSystem->getId() == 300)
        {
            std::size_t id = HearthPointComponent::getCompId();
            static_cast<deathSystem *>(newSystem)->init(m_Holder.template getComponent<HearthPointComponent>(id));
        }
        else if (newSystem->getId() == 200)
        {
            std::size_t id = BonusComponent::getCompId();
            static_cast<bonusSystem *>(newSystem)->init(m_Holder.template getComponent<BonusComponent>(id));
            id = HearthPointComponent::getCompId();
            static_cast<bonusSystem *>(newSystem)->init(m_Holder.template getComponent<HearthPointComponent>(id));
            id = PositionComponent::getCompId();
            static_cast<bonusSystem *>(newSystem)->init(m_Holder.template getComponent<PositionComponent>(id));
        }
        else if (newSystem->getId() == 500)
        {
            std::size_t id = HearthPointComponent::getCompId();
            static_cast<EndGameSystem *>(newSystem)->init(m_Holder.template getComponent<HearthPointComponent>(id));
            id = PlayableComponent::getCompId();
            static_cast<EndGameSystem *>(newSystem)->init(m_Holder.template getComponent<PlayableComponent>(id));
        }
        m_system.emplace_back(std::move(newSystem));
    }

    void init(Eligos::LayerType type)
    {
        switch (type)
        {
        case Eligos::LayerType::BACKGROUND:
            break;
        case Eligos::LayerType::GAME:
            break;
        case Eligos::LayerType::UI:
            break;
        default:
            break;
        }
    }

    void Layer::initBackground()
    {
        // ? Pas de System designer seulement dans le background
        // ? Donc fonction vide
    }

    void Layer::initGame()
    {
    }
    
    void Layer::initUI()
    {
        // ? Pas de System designer seulement dans le background
        // ? Donc fonction vide
        // ! Je donne des idees de System ducoup
        // ? Ces System seront call via Event
        // m_system.push_back(SystemFactory::Get()->CreateSystem("down hp"));
        // m_system.push_back(SystemFactory::Get()->CreateSystem(""));
    }
} // namespace Eligos
