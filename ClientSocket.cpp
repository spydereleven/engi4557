#include "ClientSocket.h"

ClientSocket::~ClientSocket()
{
}

void ClientSocket::connect(std::string const &address, const unsigned short port)
{
  struct addrinfo hints;
  struct addrinfo *server_info_list;
  struct addrinfo *server_info;

  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_UNSPEC;      // use IPv4 or IPv6
  hints.ai_socktype = SOCK_STREAM;  // TCP socket
  hints.ai_flags = AI_PASSIVE;      // fill in my IP for me

  // Convert port (uint16) to string
  std::strings2ddtream port_str;
  port_str << port;

  getaddrinfo(_remote_address.c_str(), port_str.str().c_str(), &hints, &_server_info_list);

  // TODO find appropriate
  server_info = server_info_list;

  // Attempt to connect
  int connect_result = ::connect(_fd, server_info->ai_addr, server_info->ai_addrlen);

  // Free result of getaddrinfo
  freeaddrinfo(server_info_list);
  server_info_list = NULL;
  server_info = NULL;
  
  // Check whether we connected or not
  if (connect_result < 0)
  {
    throw std::runtime_error(strerror(errno));
  }
}
