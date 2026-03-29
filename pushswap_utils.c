/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhassan <hala.hassan@learner.42.tech>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 21:18:06 by hahassan          #+#    #+#             */
/*   Updated: 2026/03/16 12:04:53 by hhassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	check_last_element(t_stack *s, t_bench *bench)
{
	if (s->tail->index == s->size - 1)
		return ;
	else
	{
		bench->rra += rra(s);
		bench->sa += sa(s);
	}
}

void	sort_three_elements(t_stack *s, t_bench *bench)
{
	if (speek(s)->index == 0)
		check_last_element(s, bench);
	else if (s->tail->index == 0)
	{
		if (speek(s)->index == s->size - 1)
		{
			bench->ra += ra(s);
			bench->sa += sa(s);
		}
		else
			bench->rra += rra(s);
	}
	else
	{
		if (speek(s)->index == s->size - 1)
			bench->ra += ra(s);
		else
			bench->sa += sa(s);
	}
	return ;
}

static void	sort_arr(int **arr, int i, t_stack *s)
{
	int	min_index;
	int	j;
	int	temp;

	min_index = i;
	j = i + 1;
	while (j < s->size)
	{
		if ((*arr)[j] < (*arr)[min_index])
			min_index = j;
		j++;
	}
	if (i != min_index)
	{
		temp = (*arr)[i];
		(*arr)[i] = (*arr)[min_index];
		(*arr)[min_index] = temp;
	}
}

static void	assign_indices(t_stack *s, t_node *cur, int *arr)
{
	int	i;

	i = 0;
	while (i < s->size)
	{
		if (arr[i] == cur->num)
		{
			cur->index = i;
			break ;
		}
		i++;
	}
}

void	index_normalization(t_stack *s)
{
	int		*arr;
	int		i;
	t_node	*cur;

	arr = stack_to_arr(s);
	if (!arr)
		return ;
	i = 0;
	while (i < s->size - 1)
	{
		sort_arr(&arr, i, s);
		i++;
	}
	cur = s->top;
	while (cur)
	{
		assign_indices(s, cur, arr);
		cur = cur->next;
	}
	free(arr);
	return ;
}
/*int main(void)
{
	t_stack *s;

	s = malloc(sizeof(t_stack));
	stack_init(s);
	spush(s, 1);
	spush(s, 3);
	spush(s, 2);
	index_normalization(s);
	sort_three_elements(s);
	sfree(s);
	free(s);
}*/
