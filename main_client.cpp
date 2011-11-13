#include <iostream>
#include "ClientSocket.h"

int main()
{
  std::string message = "Hello server.\n";

  ClientSocket c;
  c.connect("localhost", 64053);

  c.send(message.c_str(), message.length());

  try
  {
    char l;

    while (1)
    {
      c.recv(&l, 1);
      std::cout << l;
    }
  }
  catch (...)
  {
    // Swallow connection errors
  }

  std::cout << std::endl;

  return EXIT_SUCCESS;
}
