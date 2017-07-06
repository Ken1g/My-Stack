/*
* Resize test
*/

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "stack.h"

int main()
{
	my_stack* st;
        int i, val, test, size;
	
	create_stack(&st);
	size = st->size;
	printf("size of stack %d\n", size);
	for (i = 0; i < 10; i++)
	{  
		val = resize(st);
		printf("size of stack %d, changed with code %d  |  ", st->size, val);
		printf("IF SUCCESS: size of stack %d, changed with code 0\n", size + 1 + i);
		test += abs(st->size - size - 1 - i);
	}
	delete_stack(&st);
	if (test == 0)
                printf("TEST COMPLETED\n");
        else
                printf("TEST FAILED\n");

	return 0;       
}
