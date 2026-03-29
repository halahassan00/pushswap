/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahassan <hahassan@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 21:20:44 by hahassan          #+#    #+#             */
/*   Updated: 2026/03/14 21:21:02 by hahassan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

void	stack_init(t_stack *stack)
{
	stack->top = NULL;
	stack->tail = NULL;
	stack->size = 0;
	return ;
}

bool	is_empty(t_stack *stack)
{
	return (stack->size == 0);
}

t_node	*speek(t_stack *stack)
{
	return (stack->top);
}

int	ssize(t_stack *stack)
{
	return (stack->size);
}

void	spush(t_stack *stack, int number)
{
	t_node	*tmp;

	tmp = malloc(sizeof(t_node));
	if (!tmp)
		return ;
	tmp->num = number;
	tmp->next = stack->top;
	stack->top = tmp;
	if (stack->size == 0)
		stack->tail = tmp;
	stack->size++;
}
