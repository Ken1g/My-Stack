#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "stack.h"

int main() 
{
	int i;
	my_stack* stack = create_stack(); /* create a structure "my_stack" by pointer to the structure "stack" */
 
	for (i = 0; i < 100; i++) 
		push(stack, i);
    
	for (i = 0; i < 100; i++) 
	{
		printf("%d ", peek(stack));
		printf("%d ", pop(stack));
	}
 
	delete_stack(&stack);
	return 0;
} 


