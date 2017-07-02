#define STACK_OVERFLOW  -100
#define STACK_UNDERFLOW -101
#define OUT_OF_MEMORY   -102
#define INIT_SIZE 10 /* starting stack size */
#define ADD_SPACE 1 /* shows by how many elements the stack is increasing after resize function */

/*
 * description of structure "my_stack"
*/
typedef struct my_stack
{
	int* data; /* the pointer to stack data */
	size_t size; /* how many elements consist the stack */
	size_t top; /* the position of current element */
} my_stack;

/*
 * function which create stack, returns the pointer to the stack, which was created
*/
my_stack* create_stack() 
{
	my_stack* new_stack = NULL; /* new stack pointer is equal to NULL */
	new_stack = malloc(sizeof(my_stack)); /* allocating memory for the new stack */
	if (new_stack == NULL) 
		exit(OUT_OF_MEMORY);
	new_stack->size = INIT_SIZE; /* the size of new stack is equal to constant INIT_SIZE */
	new_stack->data = malloc(new_stack->size * sizeof(int)); /* allocating memory to the stack field "data" */
	if (new_stack->data == NULL) 
	{
		free(new_stack);
		exit(OUT_OF_MEMORY);
	}
	new_stack->top = 0; 
	return new_stack;
}

/*
 * function which delete the stack, takes pointer to pointer to stack 
*/ 
void delete_stack(my_stack** stack) 
{
	free((*stack)->data);
	free(*stack);
	*stack = NULL;
}

/*
 * function which resize the stack, takes pointer to stack 
*/ 
void resize(my_stack* stack)
{
	stack->size += ADD_SPACE;
	stack->data = realloc(stack->data, stack->size * sizeof(int));
	if (stack->data == NULL) 
		exit(STACK_OVERFLOW);
}

/*
 * put the element "value" on top of the stack, takes pointer to stack and "value"
*/
void push(my_stack* stack, int value) 
{
	if (stack->top >= stack->size) /* checks is it necessary to resize a stack */
		resize(stack);	       	
	stack->data[stack->top] = value;
	stack->top++;
}

/*
 * pops element from the top of the stack and returns it
*/
int pop(my_stack* stack) 
{
	if (stack->top == 0) 
		exit(STACK_UNDERFLOW);
	stack->top--;
	return stack->data[stack->top];
}

/*
 * return element from the top os the stack
*/
int peek(const my_stack* stack) 
{
	if (stack->top <= 0) 
		exit(STACK_UNDERFLOW);
	return stack->data[stack->top - 1];
}





