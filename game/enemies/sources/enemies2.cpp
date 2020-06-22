#include <iostream>
#include <vector>

extern "C" void enemies(std::vector<std::vector<std::string>> &m_loadedScriptname)
{
        m_loadedScriptname[0].push_back("../ScriptFile/Scene1/StageEntity.json");
}
