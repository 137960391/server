server: server.o
	gcc server.o -o server
server.0:
	gcc server.c
clean:
	rm server
	rm *.o

