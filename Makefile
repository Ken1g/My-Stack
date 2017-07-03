all: stack

stack: main.o stack.o test.o
	gcc main.o stack.o test.o -o stack

main.o: main.c
	gcc -c main.c

stack.o: stack.c
	gcc -c stack.c

test.o: test.c
	gcc -c  test.c

clean:
	rm -rf *.o stack
