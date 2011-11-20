#ifndef __SECURECLIENTSOCKET_H__
#define __SECURECLIENTSOCKET_H__

#include "SecureSocket.h"
#include "IClientSocket.h"

class SecureClientSocket : protected SecureSocket, public IClientSocket
{
  public:
    SecureClientSocket(std::string const& keyPath, std::string const& certPath);

    virtual ~SecureClientSocket();

    virtual void connect(std::string const &address, const unsigned short port);
};

#endif
