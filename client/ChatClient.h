#ifndef __CHATCLIENT_H__
#define __CHATCLIENT_H__

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

    void getUserList();

  private:
    std::list<IMessageListener> _messageListeners;

};

class IMessageListener
{
  public:
    virtual void onMessageReceived(std::string message) = 0;
};

#endif
