/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_down.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahassan <hahassan@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 21:25:50 by hahassan          #+#    #+#             */
/*   Updated: 2026/03/14 21:48:06 by hahassan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

void	rotate_down(t_stack *s)
{
	t_node	*new_tail;

	if (!s || is_empty(s) || s->size < 2)
		return ;
	new_tail = s->top;
	while (new_tail->next->next)
		new_tail = new_tail->next;
	s->tail->next = s->top;
	s->top = s->tail;
	s->tail = new_tail;
	s->tail->next = NULL;
}

int	rra(t_stack *a)
{
	rotate_down(a);
	write(1, "rra\n", 4);
	return (1);
}

int	rrb(t_stack *b)
{
	rotate_down(b);
	write(1, "rrb\n", 4);
	return (1);
}

int	rrr(t_stack *a, t_stack *b)
{
	rotate_down(a);
	rotate_down(b);
	write(1, "rrr\n", 4);
	return (2);
}
