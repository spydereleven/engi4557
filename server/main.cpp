#include <iostream>
#include "ScopedPtr.h"
#include "SecureServerSocket.h"
#include "ISocket.h"

void usage(std::string const& program_name)
{
  std::cerr << "Usage: " << program_name << " address port" << std::endl;
}

int main(int argc, char *argv[])
{
  std::string bind_address;
  int bind_port;

  // Get command-line parameters
  if (argc != 3)
  {
    std::cerr << "Incorrect number of arguments." << std::endl;
    usage(argv[0]);
    exit(EXIT_FAILURE);
  }
  
  // Get bind address
  bind_address = argv[1];

  // Get bind port 
  bind_port = atoi(argv[2]);

  // Check command-line parameters
  // .. port
  if (bind_port < 0 || bind_port > 65535)
  {
    std::cerr << "Invalid port number, expecting 0-65535." << std::endl;
    usage(argv[0]);
    exit(EXIT_FAILURE);
  }

  SecureSocket::begin(); // Start SSL stuff :)
  SecureServerSocket s("pkey", "cert");

  s.bind(bind_address, bind_port);
  s.listen(1);

  while(1)
  {
    try
    {
      ScopedPtr<ISocket> clientSocket = s.accept(); // We now own the client socket object

      if (clientSocket != NULL)
      {
        /*
        char buffer[4] = {0, 0, 0, 0};

        while((buffer[0] != '\r' && buffer[1] != '\n' &&
              buffer[2] != '\r' && buffer[3] != '\n') ||
              (buffer[2] != '\n' && buffer[3] != '\n') ||
              (buffer[2] != '\r' && buffer[3] != '\r'))
        {
          for(int i = 1; i < 4; i++)
            buffer[i-1] = buffer[i];

          clientSocket->recv(&buffer[3], 1);

          if (buffer[3] == '\r')
            std::cout << "\\r";
          else if (buffer[3] == '\n')
            std::cout << "\\n";

          std::cout << buffer[3];
        }
        */

        std::string msg = "HTTP/1.1 200 OK\r\n"
          "Server: Naser-inator v.0.1\r\n" 
          "Content-Length: 96\r\n"
          "Connection: close\r\n\r\n"
          "<HTML><HEAD><title>SSL'd! Awe yeah!</title></HEAD><BODY><h1>Well, hello there!</h1></BODY></HTML>";

        // Accept 10 bytes and echo them
        clientSocket->send(msg.c_str(),msg.length());
      }
    }
    catch (std::runtime_error e)
    {
      std::cerr << e.what() << std::endl;
    }
  }

  return EXIT_SUCCESS;
}
