all:  express

clean:
	rm *.o express 
	
express: main.o
	cc main.o -pthread -o express

express.o: main.c
	cc -pthread -c main.c
	