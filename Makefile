all: stack

stack: main.o 
	gcc main.o -o stack

main.o: main.c
	gcc -c main.c

clean:
	rm -rf *.o stack
