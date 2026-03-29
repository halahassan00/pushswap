/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhassan <hala.hassan@learner.42.tech>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 21:19:17 by hahassan          #+#    #+#             */
/*   Updated: 2026/03/29 22:47:11 by hhassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	reverse_pop(int s, t_stack *a, t_stack *b, t_bench *ben)
{
	int	largest_index;

	largest_index = s - 1;
	while (!is_empty(b))
	{
		if (b->top->index == largest_index)
		{
			ben->pa += pa(a, b);
			largest_index--;
		}
		else
			ben->rb += rb(b);
	}
}

void	push_chunks(t_stack *a, t_stack *b, t_bench *bench, t_chunk *chunk)
{
	int	j;

	j = 0;
	while ((j < chunk->chunk_size) && !is_empty(a))
	{
		if (a->top->index >= chunk->lower && a->top->index <= chunk->upper)
		{
			bench->pb += pb(a, b);
			j++;
		}
		else
			bench->ra += ra(a);
	}
}

void	init_chunk(t_chunk *chun, int chunksize)
{
	chun->lower = 0;
	chun->chunk_size = chunksize;
	chun->upper = chun->lower + chunksize - 1;
}

void	chunk_sort(t_stack *a, t_stack *b, t_bench *bench)
{
	int		i;
	int		num_of_chunks;
	int		size;
	t_chunk	chunk;

	i = 1;
	while (i * i <= a->size)
		i++;
	num_of_chunks = i - 1;
	init_chunk(&chunk, i);
	i = 0;
	size = a->size;
    if (num_of_chunks * chunk.chunk_size < size)
    {
        num_of_chunks++;
    }
	while (i < num_of_chunks)
	{
		push_chunks(a, b, bench, &chunk);
		i++;
		chunk.lower += chunk.chunk_size;
		chunk.upper = chunk.lower + chunk.chunk_size - 1;
		if (chunk.upper > size - 1)
			chunk.upper = size - 1;
	}
	reverse_pop(size, a, b, bench);
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


	spush(a, 3000);
	spush(a, 2000);
	spush(a, 1000);

	index_normalization(a);
	chunkSort(a, b, bench);
	cur = a->top;
	while (cur)
	{
		printf("%d\t", cur->num);
		cur = cur->next;
	}
}*/
