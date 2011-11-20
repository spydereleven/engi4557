include ../makefile.inc
SOCKET_DIR=../sockets
OBJ_DIR=../bin
OBJS=$(SOCKET_DIR)/Socket.o $(SOCKET_DIR)/SecureSocket.o $(SOCKET_DIR)/SecureServerSocket.o
LIBS=-lssl

server : ../ScopedPtr.h main.cpp
	g++ $(OPTS) $(LIBS) -I../ -I$(SOCKET_DIR) $(OBJS) main.cpp -o $(OBJ_DIR)/server

.PHONY : clean

clean :
	rm -f *.o $(OBJ_DIR)/server
