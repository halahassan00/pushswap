#include "pushswap.h"
#include <stdio.h>

char	*adaptive(t_stack *a, t_stack *b, float disorder, t_bench *bench)
{
	if (disorder < 0.2)
	{
		insertion_sort(a, b, bench);
		return ("O(n)");
	}
	else if (disorder < 0.5)
	{
		chunk_sort(a, b, bench);
		return ("O(n√n)");
	}
	else
	{
		radix_sort(a, b, bench);
		return ("O(n log n)");
	}
}

/*int     main(void)
{
	t_stack *a;
	t_stack *b;
	t_node  *cur;

	a = malloc(sizeof(t_stack));
	b = malloc(sizeof(t_stack));
	stack_init(a);
	stack_init(b);


	spush(a, 8);
	spush(a, 7);
	spush(a, 6);
	spush(a, 4);
	spush(a, 5);
	spush(a, 3);
	spush(a, 2);
	spush(a, 0);
	spush(a, 1);

	index_normalization(a);
	bubbleSort(a);
	cur = a->top;
	while (cur)
	{
		printf("%d\t", cur->num);
		cur = cur->next;
	}
}*/
