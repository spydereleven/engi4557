#ifndef __CHATCLIENT_H__
#define __CHATCLIENT_H__

#include "IClientListener.h"
#include "ClientSocket.h"

class ChatClient 
{
  public:
    ChatClient();
    ~ChatClient();

    void connect(std::string username, std::string password);
    void connect(std::string username, std::string keyPath);

    void sendToRoom(std::string roomname, std::string message);
    void sendToUser(std::string username, std::string message);
    void sendRaw(std::string message);
    void disconnect();
    void getRoomList();
    void getRoomUserList();

    void registerMessageListener(

  private:
    std::list<IClientListener*> _clientListeners;
    IClientSocket* client_socket;
};

#endif