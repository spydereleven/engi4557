#ifndef __SECURESOCKET_H__
#define __SECURESOCKET_H__

#include <exception>
#include <string>

#include <openssl/ssl.h> // SSL and SSL_CTX for SSL connections
#include <openssl/err.h> // Error reporting

#include "Socket.h"

class SecureSocket : public Socket
{
  public:
    SecureSocket(std::string const& keyPath, std::string const& certPath); //!< create a secure socket from scratch
    SecureSocket(int fd, SSL_CTX *context); //!< create a secure socket from socket descriptor and SSL context

    virtual ~SecureSocket();

    virtual int recv(char *buffer, const int length);
    virtual int send(const char *buffer, const int length);
    virtual void close();

    static void begin();

  protected:
    SSL_CTX* context();
    void createContext();
    void initializeSSL(SSL_CTX *context);

  private:
    SSL_CTX *_context;
    SSL *_ssl;

    void loadCerts(std::string const& keyPath, std::string const& certPath);
};

#endif
