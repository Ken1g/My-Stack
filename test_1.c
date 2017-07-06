/*
* Create and delete test
*/

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "stack.h"

int main() 
{
	my_stack* st[5];
	int ans[5];
	int i, test;

	test = 0;
	for (i = 0; i < 5; i++)
	{
		ans[i] = create_stack(&st[i]);		
		printf("%d stack created with code %d  |  ", i, ans[i]);
		printf("IF SUCCESS: %d stack created with code 0\n", i);
		test += ans[i];
	}
	for (i = 0; i < 5; i++)
	{
		ans[i] = delete_stack(&st[i]);
		printf("%d stack deleted with code %d  |  ", i, ans[i]);
		printf("IF SUCCESS: %d stack deleted with code 0\n", i);
                test += ans[i];
	}
	if (test == 0) 
		printf("TEST COMPLETED\n");
	else 
		printf("TEST FAILED\n");
	
	return 0;
}


