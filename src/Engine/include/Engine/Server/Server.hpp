#pragma once

#include <vector>

//thread
#include <thread>
#include <utility>

class server
{
private:
    int mainSocket{};
    std::vector<std::pair<int,int>> clientSocket; //number sockets
    std::vector<std::thread> connectionHandler;
public:
    server();
    ~server();
    auto init(int port) -> bool;
    auto run() -> void;
    auto handleConnection(int socket, int clientNumber) -> void;
};