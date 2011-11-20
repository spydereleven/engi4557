#include "SecureClientSocket.h"

SecureClientSocket::SecureClientSocket(std::string const& keyPath, std::string const& certPath)
  : SecureSocket(keyPath, certPath)
{
}

SecureClientSocket::~SecureClientSocket()
{
}

/** connect is taken from ClientSocket. It is easier to duplicate the code
  * than deal with complex inheritence. Perhaps this can be implemented in
  * IClientSocket.
  */
void SecureClientSocket::connect(std::string const &address, const unsigned short port)
{
  struct addrinfo hints;
  struct addrinfo *server_info_list;
  struct addrinfo *server_info;

  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_INET;      // use IPv4
  hints.ai_socktype = SOCK_STREAM;  // TCP socket
  hints.ai_flags = AI_PASSIVE;      // fill in my IP for me

  // Convert port (uint16) to string
  std::stringstream port_str;
  port_str << port;

  getaddrinfo(address.c_str(), port_str.str().c_str(), &hints, &server_info_list);

  // TODO find appropriate
  server_info = server_info_list;

  // Attempt to connect
  int connect_result = ::connect(fd(), server_info->ai_addr, server_info->ai_addrlen);

  // Free result of getaddrinfo
  freeaddrinfo(server_info_list);
  server_info_list = NULL;
  server_info = NULL;
  
  // Check whether we connected or not
  if (connect_result < 0)
  {
    throw std::runtime_error(strerror(errno));
  }
  
  // Initialize SSL object
  initializeSSL(context());
}
