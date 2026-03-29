/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_printf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhassan <hhassan@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 19:25:11 by hhassan           #+#    #+#             */
/*   Updated: 2026/03/14 21:57:34 by hahassan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_fdprintf.h"

static int	ft_hexa_pointer(unsigned long long n, int fd)
{
	int		count;
	char	*c;

	count = 0;
	c = "0123456789abcdef";
	if (n >= 16)
		count += ft_hexa_pointer(n / 16, fd);
	count += ft_putchar_printf(c[n % 16], fd);
	return (count);
}

int	ft_pointer_printf(void *ptr, int fd)
{
	unsigned long long	add;
	int					count;

	count = 0;
	if (!ptr)
	{
		count += ft_putstr_printf("(nil)", fd);
		return (count);
	}
	add = (unsigned long long)ptr;
	count += ft_putstr_printf("0x", fd);
	count += ft_hexa_pointer(add, fd);
	return (count);
}
