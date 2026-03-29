/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahassan <hahassan@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 21:20:06 by hahassan          #+#    #+#             */
/*   Updated: 2026/03/14 21:20:36 by hahassan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"
//#include <stdio.h>

// selection sort

void	smallest_element_to_top(t_stack *s, int n, int pos, t_bench *bench)
{
	int	i;

	i = 0;
	if (pos <= n / 2)
	{
		while (i < pos)
		{
			bench->ra += ra(s);
			i++;
		}
	}
	else
	{
		while (i < n - pos)
		{
			bench->rra += rra(s);
			i++;
		}
	}
}

void	stack_manipulation(t_stack *a, t_stack *b, t_bench *bench)
{
	t_node	*cur;
	int		i;
	int		j;

	cur = a->top;
	i = 0;
	j = 0;
	while (a->size > 3)
	{
		j = 0;
		cur = a->top;
		while (cur->index != i)
		{
			cur = cur->next;
			j++;
		}
		smallest_element_to_top(a, a->size, j, bench);
		bench->pb += pb(a, b);
		i++;
	}
	index_normalization(a);
	sort_three_elements(a, bench);
}

void	insertion_sort(t_stack *a, t_stack *b, t_bench *bench)
{
	index_normalization(a);
	stack_manipulation(a, b, bench);
	while (!is_empty(b))
	{
		bench->pa += pa(a, b);
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

	spush(a, 0);
	spush(a, 20);
	spush(a, 5);
	spush(a, 9);
	spush(a, 100);

	insertionSort(a, b);
	cur = a->top;
	while (cur)
	{
		printf("%d\t", cur->num);
		cur = cur->next;
	}
}*/
