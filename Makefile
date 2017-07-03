all: stack

stack: test.o stack.o 
	gcc test.o stack.o -o stack

test.o: test.c
	gcc -c test.c

stack.o: stack.c
	gcc -c stack.c

clean:
	rm -rf *.o stack
