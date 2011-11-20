#include "SecureSocket.h"

SecureSocket::SecureSocket(std::string const& keyPath, std::string const& certPath)
  : Socket(), _context(NULL), _ssl(NULL)
{
  // Create and setup our SSL context
  createContext();
  loadCerts(keyPath, certPath);

  // Initialize SSL
  initializeSSL(_context);
}

SecureSocket::SecureSocket(int fd, SSL_CTX *context)
  : Socket(fd), _context(NULL), _ssl(NULL)
{
  initializeSSL(context); // initialize SSL from provided context
  SSL_accept(_ssl);
}

SecureSocket::~SecureSocket()
{
  if (_context)
    SSL_CTX_free(_context);

  if (_ssl)
    SSL_free(_ssl);
}

void SecureSocket::initializeSSL(SSL_CTX *context)
{
  _ssl = SSL_new(context);
  SSL_set_fd(_ssl, fd());
}

void SecureSocket::close()
{
  // Tell the client we are closing the connection.
  SSL_shutdown(_ssl);

  // We do not wait for a reply, just clear everything.
  SSL_free(_ssl);
  _ssl = NULL;

  // Close socket normally
  Socket::close();
}

int SecureSocket::recv(char *buffer, const int length)
{
  if (_ssl == NULL) throw std::logic_error("SSL object has not yet been initialized for SecureSocket.");

  int bytesRead = 0;
  int bytesRemaining = length;

  do
  {
    // Read from SSL socket
    bytesRead = SSL_read(_ssl, &buffer[length - bytesRemaining], bytesRemaining);

    if (bytesRead < 0)
    {
      ERR_print_errors_fp(stderr);
      throw std::runtime_error("Connection failure. See above for details.");
    }
    else if (bytesRead == 0)
    {
      throw std::runtime_error("Remote side disconnected.");
    }

    bytesRemaining -= bytesRead;

  } while(bytesRead > 0 && bytesRemaining > 0);

  return length - bytesRemaining;
}

int SecureSocket::send(const char *buffer, const int length)
{
  if (_ssl == NULL) throw std::logic_error("SSL object has not yet been initialized for SecureSocket.");

  int bytesSent = 0;
  int bytesRemaining = length;

  do
  {
    // Send over socket
    bytesSent = SSL_write(_ssl, &buffer[length - bytesRemaining], bytesRemaining);

    if (bytesSent < 0)
    {
      ERR_print_errors_fp(stderr);
      throw std::runtime_error("Connection failure. See above for details.");
    }
    else if (bytesSent == 0)
    {
      throw std::runtime_error("Remote side disconnected.");
    }

    bytesRemaining -= bytesSent;

  } while(bytesSent > 0 && bytesRemaining > 0);

  return length - bytesRemaining;
}

void SecureSocket::loadCerts(std::string const& keyPath, std::string const& certPath)
{
  // Load the certificate
  if (SSL_CTX_use_certificate_chain_file(_context, certPath.c_str()) <= 0)
  {
    throw std::runtime_error("Could not use certificate chain file.");
  }

  // Load the private key
  if (SSL_CTX_use_PrivateKey_file(_context, keyPath.c_str(), SSL_FILETYPE_PEM) <= 0)
  {
    throw std::runtime_error("Could not use private key file.");
  }
 
  // Verify that the two keys go together 
  if (!SSL_CTX_check_private_key(_context))
  {
    throw std::runtime_error("Private key is invalid.");
  }
}

void SecureSocket::createContext()
{
  // Create a context compatible with SSLv2, SSLv3 and TLSv1
  _context = SSL_CTX_new(SSLv23_server_method());

  if(_context == NULL)
  {
    ERR_print_errors_fp(stderr);
    throw std::runtime_error("Creation of SSL context failed.");
  }
}

SSL_CTX* SecureSocket::context()
{
  return _context;
}

void SecureSocket::begin()
{
  CRYPTO_malloc_init(); // Initialize malloc, free, etc for OpenSSL's use
  SSL_library_init(); // Initialize OpenSSL's SSL libraries
  SSL_load_error_strings(); // Load SSL error strings
  ERR_load_BIO_strings(); // Load BIO error strings
  OpenSSL_add_all_algorithms(); // Load all available encryption algorithms
}
