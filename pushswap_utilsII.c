#include "ft_fdprintf.h"
#include "pushswap.h"

void	error_exit(t_stack *a, t_stack *b, t_bench *ben)
{
	sfree(a);
	sfree(b);
	free(a);
	free(b);
	if (ben)
		free(ben);
	write(2, "Error\n", 6);
	exit(1);
}

void	bench_init(t_bench *bench)
{
	bench->sa = 0;
	bench->sb = 0;
	bench->ss = 0;
	bench->pa = 0;
	bench->pb = 0;
	bench->ra = 0;
	bench->rb = 0;
	bench->rr = 0;
	bench->rra = 0;
	bench->rrb = 0;
	bench->rrr = 0;
}

void	bench(t_bench *bench, float disorder, char *strategy, char *complexity)
{
	int	total;
	int	whole;
	int	decimal;

	total = bench->sa + bench->sb + bench->ss + bench->pa + bench->pb
		+ bench->ra + bench->rb + bench->rr + bench->rra + bench->rrb
		+ bench->rrr;
	whole = (int)(disorder * 100);
	decimal = (int)(disorder * 10000) % 100;
	ft_fdprintf(2, "[bench] disorder: %d.", whole);
	if (decimal < 10)
		write(2, "0", 1);
	ft_fdprintf(2, "%d%%\n", decimal);
	ft_fdprintf(2, "[bench] strategy: %s / %s\n", strategy, complexity);
	ft_fdprintf(2, "[bench] total_ops: %d\n", total);
	ft_fdprintf(2, "[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n", bench->sa,
		bench->sb, bench->ss, bench->pa, bench->pb);
	ft_fdprintf(2, "[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n",
		bench->ra, bench->rb, bench->rr, bench->rra, bench->rrb, bench->rrr);
}

void	ffree(t_stack *a, t_stack *b, t_bench *ben)
{
	sfree(a);
	sfree(b);
	free(a);
	free(b);
	free(ben);
}
