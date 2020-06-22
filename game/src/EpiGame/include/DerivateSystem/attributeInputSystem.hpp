#pragma once

#include <memory>
#include <thread>
#include <queue>
#include <mutex>
#include "DerivateComponent/InputComponent.hpp"
#include "SystemBase.hpp"
#include "../Server.hpp"

class attributeInputSystem : public SystemBase
{
private:
    std::queue<int> m_queueEvent{};
    std::mutex m_mutex{};
    server m_server;
    std::shared_ptr<Eligos::RendererAPI> m_api;
    std::vector<InputComponent *> *m_input;
    std::vector<std::thread> listenCo;
public:
    attributeInputSystem() : SystemBase(5), m_server(m_queueEvent, m_mutex){
        m_server.init(3034);
        listenCo.emplace_back([this]{ m_server.run(); });
    };
    ~attributeInputSystem() = default;

    virtual void init(std::vector<InputComponent *> *obj) { m_input = obj; };
    virtual void init(std::shared_ptr<Eligos::RendererAPI> obj) { m_api = obj; };
    virtual void update(EventManager &, std::vector<Entities> &);
    virtual void dump() { std::cout << "attributeInputSystem" << std::endl; }

    static SystemBase *Create() { return new attributeInputSystem(); }
};