#include "pushswap.h"

int	*stack_to_arr(t_stack *s)
{
	int		n;
	int		i;
	int		*arr;
	t_node	*curr;

	n = s->size;
	curr = s->top;
	arr = malloc(sizeof(int) * n);
	if (!arr)
		return (NULL);
	i = 0;
	while (curr)
	{
		arr[i] = curr->num;
		curr = curr->next;
		i++;
	}
	return (arr);
}

static void	count_mistakes(int *arr, t_stack *s, int i, float *mistakes)
{
	int	j;

	j = i + 1;
	while (j < s->size)
	{
		if (arr[i] > arr[j])
			(*mistakes)++;
		j++;
	}
}

float	compute_disorder(t_stack *s)
{
	int		*arr;
	float	mistakes;
	float	total_pairs;
	int		i;

	i = 0;
	mistakes = 0;
	arr = stack_to_arr(s);
	if (!arr)
		return (-1);
	if (s->size < 2)
	{
		free(arr);
		return (mistakes);
	}
	total_pairs = ((float)s->size * (s->size - 1)) / 2.0f;
	while (i < s->size - 1)
	{
		count_mistakes(arr, s, i, &mistakes);
		i++;
	}
	free(arr);
	return (mistakes / total_pairs);
}

int	has_duplicate(t_stack *s, int dup)
{
	t_node	*cur;

	cur = s->top;
	while (cur)
	{
		if (cur->num == dup)
			return (1);
		cur = cur->next;
	}
	return (0);
}
