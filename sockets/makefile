include ../makefile.inc

default : all

all : Socket.o ServerSocket.o ClientSocket.o

Socket.o : Socket.h Socket.cpp
	g++ $(OPTS) -c Socket.cpp

ServerSocket.o : Socket.o ServerSocket.h ServerSocket.cpp
	g++ $(OPTS) -c ServerSocket.cpp

ClientSocket.o : Socket.o ClientSocket.h ClientSocket.cpp
	g++ $(OPTS) -c ClientSocket.cpp

.PHONY : all clean

clean :
	rm -f *.o
