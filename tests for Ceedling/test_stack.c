#include "unity.h"
#include "stack.h"

void setUp(void)
{

}

void tearDown(void)
{

}

void test_create_and_delete(void)
{
	my_stack* st[5];
	int ans[5];
        int i;

	for (i = 0; i < 5; i++) 
	{
		ans[i] = create_stack(&st[i]);
		TEST_ASSERT_EQUAL_INT(0, ans[i]);
		ans[i] = delete_stack(&st[i]);
		TEST_ASSERT_EQUAL_INT(0, ans[i]);
	}
}

void test_resize(void)
{
	my_stack* st;
	int i, val, size;

	create_stack(&st);
	size = st->size;
	for (i = 0; i < 10; i++)
	{
		val = resize(st);
		TEST_ASSERT_EQUAL_INT(size + 1 + i, st->size);
		TEST_ASSERT_EQUAL_INT(0, val);
	}
	delete_stack(&st);
}

void test_pop_push_peek(void)
{
	my_stack* st;
	int i, ans;
	data_type test, val;

        create_stack(&st);
        val = 0;
        for (i = 0; i < 5; i++)
        {
                val += 1;
                ans = push(st, &val);
		TEST_ASSERT_EQUAL_INT(0, ans);
        }
        for (i = 0; i < 5; i++)
        {
                ans = peek(st, &val);
                TEST_ASSERT_EQUAL_INT(0, ans);
		TEST_ASSERT_EQUAL_INT(5 - i, val);
		ans = pop(st, &val);
                TEST_ASSERT_EQUAL_INT(0, ans);
		TEST_ASSERT_EQUAL_INT(5 - i, val);
        }
        delete_stack(&st);
}
