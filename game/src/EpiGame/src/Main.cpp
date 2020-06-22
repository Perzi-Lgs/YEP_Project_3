#include <iostream>
#include <dirent.h>
#include "Application.hpp"
#include "SystemFactory.hpp"
#include "ComponentFactory.hpp"
#include "EntitiesFactory.hpp"
#include "DerivateComponent/DrawableComponent.hpp"
#include "Script.hpp"
#include "DerivateSystem/RenderSystem.hpp"
#include "DerivateSystem/attributeInputSystem.hpp"
#include "DerivateSystem/changeSpeedSystem.hpp"
#include "DynamicLoader.hpp"

class MyGame : public Eligos::Application
{
    /*
        ! INFO
        ! ------------------------
        ! Pour creer une App, voici les etapes :
        * 1) Ajouter les fichiers de Script
        * 2) Register les differents Composant de l'ECS
        * 3) Generer Une Scene;
        * 4) Creer Les Layers
        * 5) INIT la Scene
        * 6) Register les Systems
    */
private:
    DLLoader loaderS;
    std::vector<std::string> jsonList;
    std::string m_dirPath;

public:
    MyGame() {
        m_api.reset(new Eligos::SfmlRenderer());
        m_loadedScriptname.push_back({DEFAULT_BCK});
        m_loadedScriptname.push_back({DEFAULT_GAME});
        m_loadedScriptname.push_back({DEFAULT_UI_HEALTH});
        getScript("../enemies/lib/");
    /*     m_loadedScriptname[1].push_back("../ScriptFile/Scene0/EnemiesEntity.json");
        m_loadedScriptname[1].push_back("../ScriptFile/Scene0/EventScript.json");
        m_loadedScriptname[1].push_back("../ScriptFile/Scene0/missile1Entity.json");
        m_loadedScriptname[1].push_back("../ScriptFile/Scene1/EnemiesEntity2.json");
        m_loadedScriptname[1].push_back("../ScriptFile/Scene0/BonusEntity.json"); */

        m_loadedScriptname[0].push_back("../ScriptFile/Scene1/StageEntity.json");
        m_loadedScriptname[0].push_back("../ScriptFile/Scene1/EventScript2.json");
        m_loadedScriptname[0].push_back("../ScriptFile/Scene2/StageEntity2.json");
        m_loadedScriptname[0].push_back("../ScriptFile/Scene2/EventScript3.json");

        m_loadedScriptname[1].push_back("../ScriptFile/Scene0/EventScript.json");
        m_loadedScriptname[1].push_back("../ScriptFile/Scene0/EventScript1.json");
        m_loadedScriptname[1].push_back("../ScriptFile/Scene0/EventBonusScript.json");
        m_loadedScriptname[1].push_back("../ScriptFile/Scene0/EventScript3.json");

        // m_loadedScriptname[1].push_back("../ScriptFile/Scene0/EventScript2.json");
        m_loadedScriptname[1].push_back("../ScriptFile/Scene0/EventScript4.json");
        m_loadedScriptname[1].push_back("../ScriptFile/Scene0/EventScript5.json");
        m_loadedScriptname[1].push_back("../ScriptFile/Scene0/EventScriptSideM.json");
        m_loadedScriptname[1].push_back("../ScriptFile/Scene0/EventScriptSideM2.json");
        try {
            generateScene();
              // m_SceneStack[0]->init(m_loadedScriptname);
            RenderSystem *sys = (RenderSystem *)SystemFactory::Get()->CreateSystem("RENDERER");
            RenderSystem *sys1 = (RenderSystem *)SystemFactory::Get()->CreateSystem("RENDERER");
            RenderSystem *sys2 = (RenderSystem *)SystemFactory::Get()->CreateSystem("RENDERER");
            sys->init(m_api);
            sys1->init(m_api);
            sys2->init(m_api);
            m_SceneStack[0]->addSystemLayer(sys, 0);
            m_SceneStack[0]->addSystemLayer(sys1, 1);
            m_SceneStack[0]->addSystemLayer(sys2, 2);

            SystemBase *graphPos = SystemFactory::Get()->CreateSystem("RENDERERPOS");
            SystemBase *graphPos1 = SystemFactory::Get()->CreateSystem("RENDERERPOS");
            SystemBase *graphPos2 = SystemFactory::Get()->CreateSystem("RENDERERPOS");

            m_SceneStack[0]->addSystemLayer(graphPos, 0);
            m_SceneStack[0]->addSystemLayer(graphPos1, 1);
            m_SceneStack[0]->addSystemLayer(graphPos2, 2);

            SystemBase *movesys = SystemFactory::Get()->CreateSystem("MOVE");
            m_SceneStack[0]->addSystemLayer(movesys, 1);
            attributeInputSystem *attSys = (attributeInputSystem *)SystemFactory::Get()->CreateSystem("ATTRIBUTE");
            attSys->init(m_api);
            m_SceneStack[0]->addSystemLayer(attSys, 1);
            SystemBase *speed = SystemFactory::Get()->CreateSystem("SPEEDCHANGE");
            m_SceneStack[0]->addSystemLayer(speed, 1);
            SystemBase *shoot = SystemFactory::Get()->CreateSystem("SHOOT");
            m_SceneStack[0]->addSystemLayer(shoot, 1);
            SystemBase *colide = SystemFactory::Get()->CreateSystem("COLIDE");
            m_SceneStack[0]->addSystemLayer(colide, 1);
            SystemBase *damage = SystemFactory::Get()->CreateSystem("DAMAGE");
            m_SceneStack[0]->addSystemLayer(damage, 1);
            SystemBase *bonus = SystemFactory::Get()->CreateSystem("BONUS");
            m_SceneStack[0]->addSystemLayer(bonus, 1);
            SystemBase *EndGame = SystemFactory::Get()->CreateSystem("ENDGAME");
            m_SceneStack[0]->addSystemLayer(EndGame, 1);
            SystemBase *death = SystemFactory::Get()->CreateSystem("DEATH");
            m_SceneStack[0]->addSystemLayer(death, 1);
        }
        catch (const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            throw std::logic_error("Invalid Game configuration");
        }
    };
    void loadLibrary(void)
    {
        for (auto &it : jsonList) 
        {
            loaderS.load(m_dirPath + it);
            loaderS.getInstance("enemies", m_loadedScriptname);
        }
    };
    void getScript(std::string dirPath)
    {
        std::cout << dirPath << std::endl;
        m_dirPath = dirPath;
        DIR *dir = opendir(dirPath.c_str());
        std::string name;
        struct dirent *entry;

        if (dir)
        {
            while ((entry = readdir(dir)))
                if (entry->d_name[strlen(entry->d_name) - 1] == 'o'
                && entry->d_name[strlen(entry->d_name) - 2] == 's'
                && entry->d_name[strlen(entry->d_name) - 3] == '.')
                {
                    name = entry->d_name;
                    jsonList.push_back(name);
                }
            closedir(dir);
            loadLibrary();
        }
        else
            throw std::runtime_error("Invalid Dir name");
    }
    virtual ~MyGame() = default;
};

using namespace Eligos;

int main(int argc, char const *argv[])
{
    try
    {
        MyGame TestGame;
        TestGame.run();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
    catch (...)
    {
        return 1;
    }
    return 0;
}

// for (auto i = 0; i < m_SceneStack.size(); i++)
// {
//     RenderSystem *sys = (RenderSystem *)SystemFactory::Get()->CreateSystem("RENDERER");
//     sys->init(m_api);
//     m_SceneStack[0]->addSystemLayer(sys, i);
// }
// // for (auto i = 0; i < m_SceneStack.size(); i++)
// // {
// //     SystemBase *graphPos = SystemFactory::Get()->CreateSystem("RENDERERPOS");
// //     m_SceneStack[0]->addSystemLayer(graphPos, i);
// // }
