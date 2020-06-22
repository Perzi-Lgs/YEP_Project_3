#include "Engine/Server/Server.hpp"

//cout
#include <iostream>


//exception
#include <stdexcept>

//memset
#include <cstring>

//read, write, close
#include <unistd.h>

//socket
#include <sys/types.h>
#include <sys/socket.h>

//htonl
#include <arpa/inet.h>


server::~server()
{
    close(mainSocket);
    for (auto&i:clientSocket)
        close(i.second);
    for (auto &i : connectionHandler)
        i.join();
}

server::server(std::queue<int> &queueEvent, std::mutex &mutex) : m_queueEvent(queueEvent), m_mutex(mutex)
{

}

auto server::init(int port) -> bool
{
    //create the socket
    mainSocket = socket(AF_INET, SOCK_STREAM, 0);

    //setup parameters
    sockaddr_in sockIn;
    sockIn.sin_addr.s_addr = htonl(INADDR_ANY);
    sockIn.sin_family = AF_INET;
    sockIn.sin_port = htons(port);

    //bind socket with parameters
    if (bind(mainSocket, (sockaddr *)&sockIn, sizeof(sockIn)) == -1)
    {
        perror("Bind()");
        return false;
    }

    //main socket can accept 2 client
    if (listen(mainSocket, 2) == -1)
        return false;
    return true;
}

void server::handleConnection(int clientSock, int clientNumber)
{
    char buffer[250]{};
    int nbytes = 0;

    while ((nbytes = ::read(clientSock, buffer, 250)) > 0)
    {
        std::cout << "Client " << clientNumber << " say: " << buffer << std::endl;
        
        {
            m_queueEvent.push(std::stoi(buffer));
        }

        std::memset(buffer, 0, 250);
    }

    std::cout << "Connection closed..." << std::endl;
}

auto server::run() -> void
{
    std::cout << "run()" << std::endl;

    int newClient;
    sockaddr_in client;
    size_t c;
    int clientNumber = 0;

    c = sizeof(struct sockaddr_in);

    while ((newClient = accept(mainSocket, (struct sockaddr *)&client, (socklen_t *)&c)))
    {
        clientSocket.push_back({++clientNumber, newClient});
        std::cout << "New Connection from " << inet_ntoa(client.sin_addr) << std::endl;
        connectionHandler.emplace_back(std::move(std::thread(&server::handleConnection, this, newClient, clientNumber)));
    }
}

