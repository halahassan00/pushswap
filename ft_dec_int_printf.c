/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_int_printf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhassan <hhassan@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 17:40:41 by hhassan           #+#    #+#             */
/*   Updated: 2026/03/14 22:00:24 by hahassan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

static int	put_char(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_putnbr_printf(int n, int fd)
{
	long	num;
	char	c;
	int		count;

	count = 0;
	num = n;
	if (num < 0)
	{
		count += put_char('-', fd);
		num = -num;
	}
	if (num >= 10)
	{
		count += ft_putnbr_printf(num / 10, fd);
	}
	c = num % 10 + '0';
	count += put_char(c, fd);
	return (count);
}
