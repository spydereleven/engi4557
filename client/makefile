include ../makefile.inc
SOCKET_DIR=../sockets
OBJ_DIR=../bin

client : main.cpp
	g++ $(OPTS) -I../ -I$(SOCKET_DIR) $(SOCKET_DIR)/Socket.o $(SOCKET_DIR)/ClientSocket.o main.cpp -o $(OBJ_DIR)/client

.PHONY : clean

clean :
	rm -f *.o $(OBJ_DIR)/client
