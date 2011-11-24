#include "ChatClient.h"



class ChatClient

{
public:

    void connect(std::string username, std::string password)
    {
        
    };
    
    void connect(std::string username, std::string keyPath)
    {
        
    };
    
    void disconnect()
    {
    
    };
    
    void sendToRoom(std::string roomname, std::string message)
    {
        
    };
    
    void sendToUser(std::string username, std::string message);
    {
    
    };
    
    void sendRaw(std::string message)
    {
        
    };
    
    void getRaw(std::string message)
    {
        
    };
    
    void getRoomList()
    {
        
    };
    
    void getRoomUserList(std::string roomname)
    {
    
    };
    
    void registerMessageListener(std::listener)
    {
        
    };
    
    void unregisterListener(listener)
    {
        
    };
    
    void waitForServerMessage()
    
    {
    
    };
    
private:
    std::list<IClientListener*> clientListeners;
    IClientListener* client_socket;
    
}