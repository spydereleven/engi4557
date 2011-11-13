OPTS=-g

Socket.o : Socket.h Socket.cpp
	g++ $(OPTS) -c Socket.cpp

ServerSocket.o : Socket.o ServerSocket.h ServerSocket.cpp
	g++ $(OPTS) -c ServerSocket.cpp

ClientSocket.o : Socket.o ClientSocket.h ClientSocket.cpp
	g++ $(OPTS) -c ClientSocket.cpp

server : main.cpp Socket.o ServerSocket.o
	g++ $(OPTS) Socket.o ServerSocket.o main.cpp -o server

client : main_client.cpp Socket.o ClientSocket.o
	g++ $(OPTS) Socket.o ClientSocket.o main_client.cpp -o client

default : server

clean :
	@echo "Cleaning directory..."
	rm -f server client *.o

.PHONY : clean

