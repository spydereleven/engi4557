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

class Socket
{
  public:
    Socket();
    Socket(int fd);
    Socket(Socket const& socket);

    virtual ~Socket();

    virtual int recv(char *buffer, const int length);
    virtual int send(const char *buffer, const int length);

    virtual int fd() const; //!< get the underlying file descriptor
  
  private:
    int _fd;
};

#endif
