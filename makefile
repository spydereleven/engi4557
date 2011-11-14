.PHONY : all clean sockets client server 

default : all

all : server client

sockets :
	$(MAKE) -C $@

client server : sockets
	$(MAKE) -C $@

clean :
	make -C sockets/ clean
	make -C server/ clean
	make -C client/ clean
