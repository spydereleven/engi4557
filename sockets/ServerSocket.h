#ifndef __SERVERSOCKET_H__
#define __SERVERSOCKET_H__

#include <string>

#include "Socket.h"
#include "IServerSocket.h"

class ServerSocket : public Socket, public IServerSocket
{
  public:
    virtual ~ServerSocket();

    virtual void listen(int max_connections); 
    virtual void bind(std::string const &address, const unsigned short port); 
    virtual ISocket* accept();
};

#endif
