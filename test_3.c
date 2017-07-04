/*
* Peek, pop and push test
*/

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "stack.h"

int main()
{
        my_stack* st;
        int i, val, ans;

        st = NULL;
        create_stack(&st);
	for (i = 0; i < 5; i++) 
	{
		ans = push(st, i);
		printf("value %d pushed with code %d\n", i, ans);
	}
	for (i = 0; i < 5; i++)
        {
                ans = peek(st, &val);
                printf("value on the top is %d, code %d\n", val, ans);
		ans = pop(st, &val);
		printf("value %d poped from the top with code %d\n", val, ans);
        }
	delete_stack(&st);

	return 0;
}








