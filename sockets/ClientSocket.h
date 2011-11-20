#ifndef __CLIENTSOCKET_H__
#define __CLIENTSOCKET_H__

#include "Socket.h"
#include "IClientSocket.h"

class ClientSocket : public Socket, public IClientSocket
{
  public:
    virtual ~ClientSocket();

    virtual void connect(std::string const &address, const unsigned short port);
};

#endif
