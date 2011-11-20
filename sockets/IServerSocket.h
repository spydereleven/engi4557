#ifndef __ISERVERSOCKET_H__
#define __ISERVERSOCKET_H__

#include <string>
#include "ISocket.h"

class IServerSocket : public virtual ISocket
{
  public:
    virtual void listen(int max_connections) = 0; 
    virtual void bind(std::string const &address, const unsigned short port) = 0; 
    virtual ISocket* accept() = 0; //!< Waits for new connection, creates Socket object, caller owns the resulting object; returns NULL pointer on failure
};

#endif
