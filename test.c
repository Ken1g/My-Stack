#include <malloc.h>
#include <stdlib.h>
#include "stack.h"

void test_create()
{
	my_stack* st;
	st = create_stack();
	printf("The new_stack created with adress %p\n", st);
}

void info(my_stack* st)
{
	printf("This stack consist of %i elements\n", st->size);
}

void test_delete(my_stack* st)
{
	delete_stack(st);
	printf("Stack delted\n");
}
