/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_up.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahassan <hahassan@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 21:24:34 by hahassan          #+#    #+#             */
/*   Updated: 2026/03/14 21:47:53 by hahassan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

void	rotate_up(t_stack *s)
{
	t_node	*old_top;

	if (!s || is_empty(s) || s->size < 2)
		return ;
	old_top = s->top;
	s->top = old_top->next;
	s->tail->next = old_top;
	old_top->next = NULL;
	s->tail = old_top;
}

int	ra(t_stack *a)
{
	rotate_up(a);
	write(1, "ra\n", 3);
	return (1);
}

int	rb(t_stack *b)
{
	rotate_up(b);
	write(1, "rb\n", 3);
	return (1);
}

int	rr(t_stack *a, t_stack *b)
{
	rotate_up(a);
	rotate_up(b);
	write(1, "rr\n", 3);
	return (2);
}
