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
	int i;
	
	for (i = 0; i < 5; i++)
		st[i] = NULL;
	for (i = 0; i < 5; i++)
	{
		ans[i] = create_stack(&st[i]);		
		printf("%d stack created with code %d\n",i, ans[i]);
	}
	for (i = 0; i < 5; i++)
	{
		ans[i] = delete_stack(&st[i]);
		printf("%d stack deleted with code %d\n",i, ans[i]);
	}
	
	return 0;
}


