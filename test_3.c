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
        int i, ans;
	data_type test, val;

	create_stack(&st);
	test = 0;
	val = 0;
	for (i = 0; i < 5; i++) 
	{
		val += 1;
		ans = push(st, &val);
		printf("value %f pushed with code %f  |  ", val, ans);
		printf("IF SUCCESS: value %f pushed with code 0\n", val);
		test += ans;
	}
	for (i = 0; i < 5; i++)
        {
                ans = peek(st, &val);
                printf("value on the top is %f, code %f  |  ", val, ans);
		printf("IF SUCCESS: value on the top is %f, code 0\n", 5 - i);
		test += abs(val - 5 + i) + ans;
		ans = pop(st, &val);
		printf("value %f poped from the top with code %f  |  ", val, ans);
		printf("IF SUCCESS: value %f poped from the top with code 0\n", 4 - i);
		test += abs(val - 5 + i) + ans;
	}
	delete_stack(&st);
	if (test == 0)
                printf("TEST COMPLETED\n");
        else
                printf("TEST FAILED\n");

	return 0;
}




