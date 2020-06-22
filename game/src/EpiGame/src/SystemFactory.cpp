#include "SystemFactory.hpp"
#include "DerivateSystem/moveSystem.hpp"
#include "DerivateSystem/RenderSystem.hpp"
#include "DerivateSystem/GraphicPositionSystem.hpp"
#include "DerivateSystem/changeSpeedSystem.hpp"
#include "DerivateSystem/attributeInputSystem.hpp"
#include "DerivateSystem/PopMissileSystem.hpp"
#include "DerivateSystem/ColideSystem.hpp"
#include "DerivateSystem/DamageSystem.hpp"
#include "DerivateSystem/deathSystem.hpp"
#include "DerivateSystem/BonusSystem.hpp"
#include "DerivateSystem/EndGameSystem.hpp"

void SystemFactory::Register(const std::string &SystemName, CreateSystemFn pfnCreate)
{
    m_FactoryMap[SystemName] = pfnCreate;
}

SystemBase *SystemFactory::CreateSystem(const std::string &SystemName)
{
    auto it = m_FactoryMap.find(SystemName);
    if (it != m_FactoryMap.end())
        return it->second();
    return NULL;
}

SystemFactory::SystemFactory()
{
    Register("MOVE", &moveSystem::Create);
    Register("RENDERER", &RenderSystem::Create);
    Register("RENDERERPOS", &GraphicPositionSystem::Create);
    Register("ATTRIBUTE", &attributeInputSystem::Create);
    Register("SPEEDCHANGE", &changeSpeedSystem::Create);
    Register("SHOOT", &PopMissilesystem::Create);
    Register("COLIDE", &ColideSystem::Create);
    Register("DAMAGE", &DamageSystem::Create);
    Register("DEATH", &deathSystem::Create);
    Register("BONUS", &bonusSystem::Create);
    Register("ENDGAME", &EndGameSystem::Create);
}