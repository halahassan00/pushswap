NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c stack_helpers.c  stack_helpersII.c swap.c \
    rotate_up.c rotate_down.c push.c\
	pushswap_utils.c pushswap_utilsII.c pushswap_utilsIII.c \
	simple.c medium.c complex.c adaptive.c \
	libft_funcs.c ft_putchar_printf.c ft_putstr_printf.c \
	ft_dec_int_printf.c ft_unsigned_dec_printf.c ft_pointer_printf.c \
	lower_hexadecimal_printf.c upper_hexadecimal_printf.c ft_fdprintf.c	\
	pushswap_atoi.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c pushswap.h ft_fdprintf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
