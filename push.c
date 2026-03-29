/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahassan <hahassan@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 21:27:49 by hahassan          #+#    #+#             */
/*   Updated: 2026/03/14 21:28:26 by hahassan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

int	pa(t_stack *a, t_stack *b)
{
	t_node	*popped;

	popped = spop(b);
	spush(a, popped->num);
	a->top->index = popped->index;
	free(popped);
	write(1, "pa\n", 3);
	return (1);
}

int	pb(t_stack *a, t_stack *b)
{
	t_node	*popped;

	popped = spop(a);
	spush(b, popped->num);
	b->top->index = popped->index;
	free(popped);
	write(1, "pb\n", 3);
	return (1);
}
