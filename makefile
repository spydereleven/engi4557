OPTS=-g
OBJ=Socket.o ServerSocket.o

Socket.o : Socket.h Socket.cpp
	g++ $(OPTS) -c Socket.cpp

ServerSocket.o : Socket.o ServerSocket.h ServerSocket.cpp
	g++ $(OPTS) -c ServerSocket.cpp

server : main.cpp $(OBJ)
	g++ $(OPTS) $(OBJ) main.cpp -o server

default : server

clean :
	@echo "Cleaning directory..."
	rm -f server *.o

.PHONY : clean

