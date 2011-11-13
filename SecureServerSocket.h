#ifndef __SECURESERVERSOCKET_H__
#define __SECURESERVERSOCKET_H__

#include "ServerSocket.h"

class SecureServerSocket : public ServerSocket
{
  public:
    SecureServerSocket();
    SecureServerSocket(std::string const& keyPath, std::string const& certPath);
    virtual ~SecureServerSocket();
};

#endif
