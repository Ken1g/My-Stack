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
        int i, val, ans, test;

	create_stack(&st);
	test = 0;
	for (i = 0; i < 5; i++) 
	{
		ans = push(st, i);
		printf("value %d pushed with code %d  |  ", i, ans);
		printf("IF SUCCESS: value %d pushed with code 0\n", i);
		test += ans;
	}
	for (i = 0; i < 5; i++)
        {
                ans = peek(st, &val);
                printf("value on the top is %d, code %d  |  ", val, ans);
		printf("IF SUCCESS: value on the top is %d, code 0\n", 4 - i);
		test += abs(val - 4 + i) + ans;
		ans = pop(st, &val);
		printf("value %d poped from the top with code %d  |  ", val, ans);
		printf("IF SUCCESS: value %d poped from the top with code 0\n", 4 - i);
		test += abs(val - 4 + i) + ans;
	}
	delete_stack(&st);
	if (test == 0)
                printf("TEST COMPLETED\n");
        else
                printf("TEST FAILED\n");

	return 0;
}








