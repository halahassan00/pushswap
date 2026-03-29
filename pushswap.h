#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

// structs
typedef struct s_node
{
	int				num;
	int				index;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	t_node			*tail;
	int				size;
}					t_stack;

typedef struct s_chunk
{
	int				lower;
	int				upper;
	int				chunk_size;
}					t_chunk;

typedef struct s_bench
{
	int				sa;
	int				sb;
	int				ss;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
	int				pb;
	int				pa;
}					t_bench;

typedef struct s_flags
{
	char			*strategy;
	char			*complexity;
	int				benchflag;
	int				start_index;
}					t_flags;

// stack functionalities
void				stack_init(t_stack *stack);
bool				is_empty(t_stack *stack);
t_node				*speek(t_stack *stack);
int					ssize(t_stack *stack);
void				spush(t_stack *stack, int number);
t_node				*spop(t_stack *stack);
void				sfree(t_stack *stack);

// utils
int					*stack_to_arr(t_stack *s);
float				compute_disorder(t_stack *s);
void				index_normalization(t_stack *s);
void				sort_three_elements(t_stack *s, t_bench *bench);
size_t				ft_strlen(const char *s);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_isdigit(int c);
// operations
void				swap(t_stack *s);
int					sa(t_stack *a);
int					sb(t_stack *b);
int					ss(t_stack *a, t_stack *b);
int					pa(t_stack *a, t_stack *b);
int					pb(t_stack *a, t_stack *b);
void				rotate_up(t_stack *s);
int					ra(t_stack *a);
int					rb(t_stack *b);
int					rr(t_stack *a, t_stack *b);
void				rotate_down(t_stack *s);
int					rra(t_stack *a);
int					rrb(t_stack *b);
int					rrr(t_stack *a, t_stack *b);

// simple algorithm
void				stack_manipulation(t_stack *a, t_stack *b, t_bench *bench);
void				insertion_sort(t_stack *a, t_stack *b, t_bench *bench);
void				smallest_element_to_top(t_stack *s, int n, int pos,
						t_bench *bench);

// complex (radix sort)
void				radix_sort(t_stack *a, t_stack *b, t_bench *bench);

// medium (chunk sort)
void				chunk_sort(t_stack *a, t_stack *b, t_bench *bench);
void				push_chunks(t_stack *a, t_stack *b, t_bench *bench,
						t_chunk *chunk);
void				reverse_pop(int s, t_stack *a, t_stack *b, t_bench *ben);
void				init_chunk(t_chunk *chun, int chunksize);

// adaptive sort
char				*adaptive(t_stack *a, t_stack *b, float disorder,
						t_bench *bench);

// argument parsing
int					has_duplicate(t_stack *s, int dup);
int					ft_atoi_safe(char *num, t_stack *a, t_stack *b);
void				error_exit(t_stack *a, t_stack *b, t_bench *ben);

// bench
void				bench(t_bench *bench, float disorder, char *strategy,
						char *complexity);
void				bench_init(t_bench *bench);
void				ffree(t_stack *a, t_stack *b, t_bench *ben);
#endif
