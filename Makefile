server: server.o splitstr.o
	gcc server.o splitstr.o -o server
server.o:
	gcc -c server.c -o  server.o
splitstr.o:
	gcc -c splitstr.c -o splitstr.o
clean:
	rm server
	rm *.o

