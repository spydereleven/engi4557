#ifndef __CLIENTSOCKET_H__
#define __CLIENTSOCKET_H__

#include <string>
#include <sstream>

#include "Socket.h"

class ClientSocket : public Socket
{
  public:
    virtual ~ClientSocket();

    void connect(std::string const &address, const unsigned short port);
};

#endif
