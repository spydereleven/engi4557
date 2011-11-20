#ifndef __SOCKET_H__
#define __SOCKET_H__

#include <cstdlib>
#include <cstring>
#include <cerrno>

#include <stdexcept>

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

#include "ISocket.h"

class Socket : public virtual ISocket
{
  public:
    Socket();
    Socket(int fd);

    virtual ~Socket();

    virtual int recv(char *buffer, const int length);
    virtual int send(const char *buffer, const int length);
    virtual void close();

    virtual int fd() const; //!< get the underlying file descriptor

  private:
    int _fd;
};

#endif
