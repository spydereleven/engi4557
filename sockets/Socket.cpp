#include <iostream>
#include "Socket.h"

Socket::Socket()
{
  // Create a (IPv4) TCP socket descriptor
  _fd = ::socket(PF_INET, SOCK_STREAM, 0);

  if (_fd == -1)
  {
    throw std::runtime_error(strerror(errno));
  }
}

Socket::Socket(int fd)
{
  _fd = fd;
}

Socket::Socket(Socket const& socket)
{
  _fd = socket.fd();
}

Socket::~Socket()
{
  close(_fd);
}

int Socket::recv(char *buffer, const int length)
{
  int bytesRead = 0;
  int bytesRemaining = length;

  do
  {
    // Read from socket
    bytesRead = ::recv(_fd, &buffer[length - bytesRemaining], bytesRemaining, 0);

    if (bytesRead <= 0)
    {
      throw std::runtime_error("Remote side disconnected.");
    }

    bytesRemaining -= bytesRead;

  } while(bytesRead > 0 && bytesRemaining > 0);

  return length - bytesRemaining;
}

int Socket::send(const char *buffer, const int length)
{
  int bytesRead = 0;
  int bytesRemaining = length;

  do
  {
    // Send over socket
    bytesRead = ::send(_fd, &buffer[length - bytesRemaining], bytesRemaining, 0);

    if (bytesRead <= 0)
    {
      throw std::runtime_error("Remote side disconnected.");
    }

    bytesRemaining -= bytesRead;

  } while(bytesRead > 0 && bytesRemaining > 0);

  return length - bytesRemaining;
}

int Socket::fd() const
{
  return _fd;
}
