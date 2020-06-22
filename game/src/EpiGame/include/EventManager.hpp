#pragma once

#include <queue>
#include "IEvent.hpp"

class EventManager
{
private:
    std::queue<IEvent *> m_eventQueue;
public:
    EventManager() = default;
    virtual ~EventManager() = default;
public:
    void push(IEvent *);
    int getTypeFirstEvent();
    IEvent *processEvent();
    std::size_t size() { return m_eventQueue.size(); };
    bool isEmpty() const { return m_eventQueue.empty(); };
};