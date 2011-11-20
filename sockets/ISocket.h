#ifndef __ISOCKET_H__
#define __ISOCKET_H__

class ISocket
{
  public:
    virtual int recv(char *buffer, const int length) = 0;
    virtual int send(const char *buffer, const int length) = 0;
    virtual void close() = 0;

    virtual int fd() const = 0; //!< get the underlying file descriptor
};

#endif
