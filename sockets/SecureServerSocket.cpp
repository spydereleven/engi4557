#include "SecureServerSocket.h"

SecureServerSocket::SecureServerSocket(std::string const& keyPath, std::string const& certPath)
  : SecureSocket(keyPath, certPath)
{
}

SecureServerSocket::~SecureServerSocket()
{
}

/** SecureServerSocket and ServerSocket have the same listen and bind
  * functions. Consider moving these implementations to IServerSocket?
  * It is easiest to just duplicate the implementations than deal with
  * complex multiple inheritence.
  */

void SecureServerSocket::listen(int max_connections)
{
  // Attempt to listen on socket
  if (::listen(fd(), max_connections) == -1)
  {
    // Failed to listen on socket
    throw std::runtime_error(strerror(errno));
  }
}

void SecureServerSocket::bind(std::string const &address, const unsigned short port)
{
  struct sockaddr_in addr;

  // Fill in binding info
  addr.sin_family = AF_INET;
  addr.sin_port = htons(port);
  addr.sin_addr.s_addr = inet_addr(address.c_str());
  memset(addr.sin_zero, 0, sizeof(addr.sin_zero));

  // Attempt to bind to socket
  if (::bind(fd(), (struct sockaddr *) &addr, sizeof(addr)) < 0)
  {
    // Failed to bind to socket
    throw std::runtime_error(strerror(errno));
  }
}

/***/

ISocket* SecureServerSocket::accept()
{
  // We repeat the code here because ServerSocket::accept() returns an object
  // that if we delete will close the socket. This is reasonable behaviour
  // normally, but in this situation it is not. This solution is easy enough
  // but is redundant. Sorry.

  int client_fd;
  struct sockaddr_storage their_addr;
  socklen_t addr_size = sizeof(their_addr);

  // Accept an incoming connection (blocking)
  client_fd = ::accept(fd(), (struct sockaddr*) &their_addr, &addr_size);

  // Copy the client object into 
  return (client_fd >= 0) ? new SecureSocket(client_fd, context()) : NULL;
}
