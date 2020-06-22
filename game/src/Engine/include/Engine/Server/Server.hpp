#pragma once

#include <vector>
#include <queue>
#include <mutex>

//thread
#include <thread>
#include <utility>

class server
{
private:
    int mainSocket{};
    std::vector<std::pair<int,int>> clientSocket; //number sockets
    std::vector<std::thread> connectionHandler;
    std::queue<int> &m_queueEvent;
    std::mutex &m_mutex;
public:
    server(std::queue<int> &m_queueEvent, std::mutex &m_mutex);
    ~server();
    auto init(int port) -> bool;
    auto run() -> void;
    auto handleConnection(int socket, int clientNumber) -> void;
};