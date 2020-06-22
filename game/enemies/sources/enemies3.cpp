#include <iostream>
#include <vector>

extern "C" void enemies(std::vector<std::vector<std::string>> &m_loadedScriptname)
{
        m_loadedScriptname[1].push_back("../ScriptFile/Scene0/BonusEntity.json");
}
