#include <iostream>
#include "ScopedPtr.h"
#include "ServerSocket.h"
#include "ClientSocket.h"

int main()
{
  ServerSocket s;

  try
  {
    s.bind("0.0.0.0", 64053);
    s.listen(1);

    ScopedPtr<Socket> clientSocket(s.accept()); // We now own the client socket object

    if (clientSocket != NULL)
    {
      char buffer[11];
      memset(buffer, 0, 11);
      // Accept 10 bytes and echo them
      clientSocket->send(buffer,clientSocket->recv(buffer,10));
    }
  }
  catch (std::runtime_error e)
  {
    std::cerr << e.what() << std::endl;
  }

  return EXIT_SUCCESS;
}
