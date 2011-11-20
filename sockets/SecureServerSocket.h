#ifndef __SECURESERVERSOCKET_H__
#define __SECURESERVERSOCKET_H__

#include "SecureSocket.h"
#include "IServerSocket.h"

class SecureServerSocket : protected SecureSocket, public IServerSocket
{
  public:
    SecureServerSocket(std::string const& keyPath, std::string const& certPath);
    virtual ~SecureServerSocket();

    virtual void listen(int max_connections); 
    virtual void bind(std::string const &address, const unsigned short port); 
    virtual ISocket* accept();

    // Will delegate to SecureSocket's  
    //virtual int recv(char *buffer, const int length);
    //virtual int send(const char *buffer, const int length);
    //virtual void close();

  private:
    SSL_CTX *_ssl_context;

    void createContext();
};

#endif
