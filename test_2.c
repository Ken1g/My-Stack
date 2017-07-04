#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "stack.h"

int main()
{
	my_stack* st;
        int i, val;
	
	st = NULL;
	create_stack(&st);
	printf("size of stack %d\n", st->size);
	
	for (i = 0; i < 10; i++)
	{  
		val = resize(st);
		printf("size of stack %d, changed with code %d\n", st->size, val);
	}

	return 0;       
}
