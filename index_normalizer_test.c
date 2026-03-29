#include "pushswap.h"
#include <stdio.h>

int	main(void)
{
	t_stack	*s;
	t_node	*cur;

	s = malloc(sizeof(t_stack));
	stack_init(s);
	spush(s, 55);
	spush(s, 420);
	spush(s, 0);
	spush(s, 27);
	spush(s, 7);
	index_normalization(s);
	printf(" ========== POSITIVE  STACK [7, 27, 0, 420, 55] ==========\n\n");
	cur = s->top;
	while (cur)
	{
		printf("number %d, index %d \n", cur->num, cur->index);
		cur = cur->next;
	}
	sfree(s);
	spush(s, -30);
	spush(s, -3);
	spush(s, -16);
	spush(s, -10);
	spush(s, -42);
	index_normalization(s);
	printf(" ========== NEGATIVE STACK [-42, -10, -16, -3,-30] ==========\n\n");
	cur = s->top;
	while (cur)
	{
		printf("number %d, index %d \n", cur->num, cur->index);
		cur = cur->next;
	}
	sfree(s);
	spush(s, 55);
	spush(s, -3);
	spush(s, 7);
	spush(s, 1000);
	spush(s, -42);
	index_normalization(s);
	printf(" ========== MIXED POSITIVE AND NEGATIVE STACK [-42, 1000, 7, -3, 55] ==========\n\n");
	cur = s->top;
	while (cur)
	{
		printf("number %d, index %d \n", cur->num, cur->index);
		cur = cur->next;
	}
}
