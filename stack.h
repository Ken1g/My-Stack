#ifndef STACK
#define STACK
#include <stdio.h>
#include <stdlib.h>

/*
 * description of structure "my_stack"
*/
typedef struct my_stack
{
	int* data; /* the pointer to stack data */
	int size; /* how many elements consist the stack */
	int top; /* the position of current element */
} my_stack;

/* if success all functions return 0 or functions return error code */

/*
 * function which create stack, put the pointer to the new stack into "new_stack"
*/
int create_stack(my_stack* new_stack); 

/*
 * function which delete the stack, takes pointer to pointer to stack 
*/ 
int delete_stack(my_stack* stack);

/*
 * function which resize the stack, takes pointer to stack 
*/ 
int resize(my_stack* stack);

/*
 * put the element "value" on top of the stack, takes pointer to stack and "value"
*/
int push(my_stack* stack, int value); 

/*
 * pops element from the top of the stack and returns it
*/
int pop(my_stack* stack, int* value);

/*
 * return element from the top of the stack
*/
int peek(const my_stack* stack, int* value); 
#endif
