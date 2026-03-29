/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahassan <hahassan@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 21:18:53 by hahassan          #+#    #+#             */
/*   Updated: 2026/03/14 21:19:02 by hahassan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <stdio.h>

void	radix_sort(t_stack *a, t_stack *b, t_bench *bench)
{
	int	max;
	int	bit;
	int	size;

	bit = 0;
	max = a->size - 1;
	while (max > 0)
	{
		size = a->size;
		while (size)
		{
			if ((a->top->index >> bit) & 1)
				bench->ra += ra(a);
			else
				bench->pb += pb(a, b);
			size--;
		}
		while (!is_empty(b))
		{
			bench->pa += pa(a, b);
		}
		max = max >> 1;
		bit++;
	}
}

/*int main(void)
{
	t_stack *a;
	t_stack *b;
	t_node  *cur;

	a = malloc(sizeof(t_stack));
	b = malloc(sizeof(t_stack));
	stack_init(a);
	stack_init(b);

	spush(a, -13);
	spush(a, -3);
	spush(a, -76);
	spush(a, -40);

	index_normalization(a);
	radixSort(a, b);
	cur = a->top;
	while (cur)
	{
		printf("%d\t", cur->num);
		cur = cur->next;
	}
}*/
