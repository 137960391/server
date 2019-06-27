server: server.o splitstr.o link.o
	gcc server.o splitstr.o link.o -o server
server.o:
	gcc -c server.c -o  server.o
splitstr.o:
	gcc -c splitstr.c -o splitstr.o
link.o:
	gcc -c link.c -o link.o
clean:
	rm server
	rm *.o

