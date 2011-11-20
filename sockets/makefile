include ../makefile.inc

default : all

all : Socket.o ServerSocket.o ClientSocket.o SecureSocket.o SecureServerSocket.o SecureClientSocket.o 

# Normal sockets

Socket.o : ISocket.h Socket.h Socket.cpp
	g++ $(OPTS) -c Socket.cpp

ServerSocket.o : ISocket.h IServerSocket.h ServerSocket.h ServerSocket.cpp
	g++ $(OPTS) -c ServerSocket.cpp
 
ClientSocket.o : IClientSocket.h ClientSocket.h ClientSocket.cpp
	g++ $(OPTS) -c ClientSocket.cpp

# Secure Sockets

SecureSocket.o : ISocket.h SecureSocket.h SecureSocket.cpp
	g++ $(OPTS) -c SecureSocket.cpp

SecureServerSocket.o : IServerSocket.h SecureServerSocket.h SecureServerSocket.cpp
	g++ $(OPTS) -c SecureServerSocket.cpp

SecureClientSocket.o : IClientSocket.h SecureClientSocket.h SecureClientSocket.cpp
	g++ $(OPTS) -c SecureClientSocket.cpp

.PHONY : all clean

clean :
	rm -f *.o
