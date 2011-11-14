#ifndef __SERVERSOCKET_H__
#define __SERVERSOCKET_H__

#include <string>
#include "Socket.h"

class ServerSocket : public Socket
{
  public:
    virtual ~ServerSocket();

    void listen(int max_connections); 
    void bind(std::string const &address, const unsigned short port); 

    Socket* accept(); //!< Waits for new connection, creates Socket object, caller owns the resulting object; returns NULL pointer on failure
};

#endif
