#ifndef __ICLIENTSOCKET_H__
#define __ICLIENTSOCKET_H__

#include <string>
#include <sstream>

#include "Socket.h"
#include "IClientSocket.h"

class IClientSocket : public virtual ISocket
{
  public:
    virtual void connect(std::string const &address, const unsigned short port) = 0;
};

#endif
