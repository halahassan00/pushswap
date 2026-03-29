#include "pushswap.h"

static int	check_sign(size_t *i, int *sign, char *num)
{
	if (num[0] == '-')
	{
		*sign = -1;
		*i = 1;
	}
	else if (num[0] == '+')
		*i = 1;
	if (num[*i] == '\0')
		return (1);
	return (0);
}

int	ft_atoi_safe(char *num, t_stack *a, t_stack *b)
{
	long long	result;
	int			sign;
	size_t		length;
	size_t		i;

	if (!num || ft_strlen(num) == 0)
		error_exit(a, b, NULL);
	sign = 1;
	i = 0;
	if (check_sign(&i, &sign, num))
		error_exit(a, b, NULL);
	result = 0;
	length = ft_strlen(num);
	while (i < length)
	{
		if (!ft_isdigit(num[i]))
			error_exit(a, b, NULL);
		result = result * 10 + (num[i] - '0');
		i++;
	}
	if (sign == -1)
		result *= -1;
	if (result > 2147483647 || result < -2147483648)
		error_exit(a, b, NULL);
	return ((int)result);
}
