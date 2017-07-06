#define STACK_OVERFLOW  -100
#define STACK_UNDERFLOW -101
#define OUT_OF_MEMORY   -102
#define INIT_SIZE 2 /* starting stack size */
#define ADD_SPACE 1 /* shows by how many elements the stack is increasing after resize function */

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "stack.h"

int create_stack(my_stack** new_stack) 
{
	*new_stack = malloc(sizeof(my_stack));
	if (*new_stack == NULL) 
		return(OUT_OF_MEMORY);
	(*new_stack)->size = INIT_SIZE;
	(*new_stack)->data = malloc((*new_stack)->size * sizeof(int)); 
	if ((*new_stack)->data == NULL) 
	{
		free(*new_stack);
		return(OUT_OF_MEMORY);
	}
	(*new_stack)->top = 0; 
	return 0;
}

int delete_stack(my_stack** stack) 
{
	free((*stack)->data);
	free(*stack);
	*stack = NULL;
	return 0;
}

int resize(my_stack* stack)
{
	void* t;

	stack->size += ADD_SPACE;
	t = realloc(stack->data, stack->size * sizeof(int));
	if (t == NULL) 
		return(STACK_OVERFLOW);
	else
		stack->data = t;
	return 0;
}

int push(my_stack* stack, int value) 
{
	int code = 0;
	
	if (stack->top >= stack->size) /* checks is it necessary to resize a stack */
		code = resize(stack);	       	
	if (code != 0)	      	
		return(code); /* if function "resize" failed,  return the error code */
	stack->data[stack->top] = value;
	stack->top++;
	return 0;
}

int pop(my_stack* stack, int* value) 
{
	if (stack->top <= 0) 
		return(STACK_UNDERFLOW);
	stack->top--;
	*value = stack->data[stack->top];
	return 0;
}

int peek(const my_stack* stack, int* value) 
{
	if (stack->top <= 0) 
		return(STACK_UNDERFLOW);
	*value = stack->data[stack->top - 1];
	return 0;
}





