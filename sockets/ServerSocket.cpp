#include "ServerSocket.h"

ServerSocket::~ServerSocket()
{
}

void ServerSocket::listen(int max_connections)
{
  // Attempt to listen on socket
  if (::listen(fd(), max_connections) == -1)
  {
    // Failed to listen on socket
    throw std::runtime_error(strerror(errno));
  }
}

void ServerSocket::bind(std::string const &address, const unsigned short port)
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

ISocket* ServerSocket::accept()
{
  int client_fd;
  struct sockaddr_storage their_addr;
  socklen_t addr_size = sizeof(their_addr);

  // Accept an incoming connection (blocking)
  client_fd = ::accept(fd(), (struct sockaddr*) &their_addr, &addr_size);
  
  // Return a new socket object or NULL -- caller now owns the object
  return (client_fd >= 0) ? new Socket(client_fd) : NULL;
}
