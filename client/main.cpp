#include <iostream>
#include "ClientSocket.h"

#define BUFFER_SIZE 1024

void usage(std::string const& program_name)
{
  std::cerr << "Usage: " << program_name << " address port" << std::endl;
}

int main(int argc, char *argv[])
{
  std::string remote_address;
  int remote_port;

  // Get command-line parameters
  if (argc != 3)
  {
    std::cerr << "Incorrect number of arguments." << std::endl;
    usage(argv[0]);
    exit(EXIT_FAILURE);
  }
  
  // Get remote address
  remote_address = argv[1];

  // Get remote port 
  remote_port = atoi(argv[2]);

  // Check command-line parameters
  // .. port
  if (remote_port < 0 || remote_port > 65535)
  {
    std::cerr << "Invalid port number, expecting 0-65535." << std::endl;
    usage(argv[0]);
    exit(EXIT_FAILURE);
  }

  try
  {
    ClientSocket c;
    c.connect(remote_address, remote_port);

    char buf[BUFFER_SIZE];
    int messageSize = 0;

    while(1)
    {
      // Get a message from the client
      std::cin.getline(buf, BUFFER_SIZE-1);
      messageSize = std::cin.gcount();

      if (messageSize > 0)
      {
        c.send(buf, messageSize); // Send the message
        memset(buf, 0, BUFFER_SIZE); // Clear the message buffer
        c.recv(buf, messageSize); // Listen for the echo
        std::cout << buf << std::endl; // Print out the echo
      }
    }
  }
  catch (std::runtime_error const& e)
  {
    std::cerr << e.what() << std::endl;
    exit(EXIT_FAILURE);
  }

  return EXIT_SUCCESS;
}
