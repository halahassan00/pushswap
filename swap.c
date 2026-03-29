/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahassan <hahassan@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 21:21:06 by hahassan          #+#    #+#             */
/*   Updated: 2026/03/14 21:47:30 by hahassan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

void	swap(t_stack *s)
{
	t_node	*first;
	t_node	*second;

	if (is_empty(s) || s->size < 2)
		return ;
	first = s->top;
	second = first->next;
	if (s->size == 2)
		s->tail = first;
	first->next = second->next;
	second->next = first;
	s->top = second;
}

int	sa(t_stack *a)
{
	swap(a);
	write(1, "sa\n", 3);
	return (1);
}

int	sb(t_stack *b)
{
	swap(b);
	write(1, "sb\n", 3);
	return (1);
}

int	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
	return (2);
}
