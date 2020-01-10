all:  copy ForkCopy hello 

clean:
	rm *.o copy
	rm *.o forkcopy
	rm *.o hello

copy: copy.o
	cc MyCopy.o -o copy

copy.o: MyCopy.c
	cc -c MyCopy.c

forkcopy: copy.o
	cc ForkCopy.o -o copy

forkcopy.o: ForkCopy.c
	cc -c ForkCopy.c

hello: hello.o
	cc hello.o -o hello

hello.o: hello.c
	cc -c hello.c