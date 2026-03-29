#include "pushswap.h"

t_node	*spop(t_stack *stack)
{
	t_node	*popped;

	if (!stack || is_empty(stack))
	{
		return (NULL);
	}
	popped = stack->top;
	stack->top = popped->next;
	stack->size--;
	if (stack->size == 0)
		stack->tail = NULL;
	popped->next = NULL;
	return (popped);
}

void	sfree(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	current = stack->top;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	stack->top = NULL;
	stack->tail = NULL;
	stack->size = 0;
}
