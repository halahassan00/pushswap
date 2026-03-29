/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhassan <hala.hassan@learner.42.tech>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 21:18:37 by hahassan          #+#    #+#             */
/*   Updated: 2026/03/16 13:17:25 by hhassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	sort(t_stack *a, t_stack *b, t_flags *flags, t_bench *ben)
{
	float	disorder;

	disorder = compute_disorder(a);
	if (disorder == 0)
		return ;
	index_normalization(a);
	if (ft_strncmp(flags->strategy, "Adaptive", ft_strlen("Adaptive")) == 0)
		flags->complexity = adaptive(a, b, disorder, ben);
	else if (ft_strncmp(flags->strategy, "Simple", ft_strlen("Simple")) == 0)
		insertion_sort(a, b, ben);
	else if (ft_strncmp(flags->strategy, "Medium", ft_strlen("Medium")) == 0)
		chunk_sort(a, b, ben);
	else if (ft_strncmp(flags->strategy, "Complex", ft_strlen("Complex")) == 0)
		radix_sort(a, b, ben);
	if (flags->benchflag == 1)
		bench(ben, disorder, flags->strategy, flags->complexity);
}

static int	parse_nums(t_stack *a, t_stack *b, t_flags *flags, char **argv)
{
	int	j;
	int	num;

	j = 0;
	while (argv[j])
		j++;
	j--;
	while (j >= flags->start_index)
	{
		num = ft_atoi_safe(argv[j], a, b);
		if (has_duplicate(a, num))
			return (-1);
		else
			spush(a, num);
		j--;
	}
	return (0);
}

static int	set_strategy(char *argv, t_flags *flags)
{
	if (ft_strncmp(argv, "--adaptive", ft_strlen("--adaptive")) == 0)
		flags->strategy = "Adaptive";
	else if (ft_strncmp(argv, "--simple", ft_strlen("--simple")) == 0)
	{
		flags->strategy = "Simple";
		flags->complexity = "O(n^2)";
	}
	else if (ft_strncmp(argv, "--complex", ft_strlen("--complex")) == 0)
	{
		flags->strategy = "Complex";
		flags->complexity = "O(n log n)";
	}
	else if (ft_strncmp(argv, "--medium", ft_strlen("--medium")) == 0)
	{
		flags->strategy = "Medium";
		flags->complexity = "O(n√n)";
	}
	else if (ft_strncmp(argv, "--bench", ft_strlen("--bench")) == 0)
		flags->benchflag = 1;
	else
		return (-1);
	return (0);
}

static int	parse_flags(int argc, char **argv, t_flags *flags)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] == '-')
		{
			if (set_strategy(argv[i], flags) < 0)
				return (-1);
		}
		else
		{
			flags->start_index = i;
			break ;
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_bench	*ben;
	t_flags	flags;

	if (argc < 2)
		return (0);
	a = malloc(sizeof(t_stack));
	b = malloc(sizeof(t_stack));
	stack_init(a);
	stack_init(b);
	flags.benchflag = 0;
	ben = malloc(sizeof(t_bench));
	bench_init(ben);
	flags.strategy = "Adaptive";
	flags.start_index = -1;
	if (parse_flags(argc, argv, &flags) < 0)
		error_exit(a, b, ben);
	if (flags.start_index == -1)
		return (0);
	if (parse_nums(a, b, &flags, argv) < 0)
		error_exit(a, b, ben);
	sort(a, b, &flags, ben);
	ffree(a, b, ben);
}
