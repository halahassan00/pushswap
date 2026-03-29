/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahassan <hahassan@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 20:26:57 by hahassan          #+#    #+#             */
/*   Updated: 2026/03/14 22:00:53 by hahassan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdprintf.h"
#include <stdarg.h>

static int	formatter(int fd, char c, va_list args)
{
	int	bytes;

	bytes = 0;
	if (c == 'd' || c == 'i')
		bytes += ft_putnbr_printf(va_arg(args, int), fd);
	else if (c == 'c')
		bytes += ft_putchar_printf(va_arg(args, int), fd);
	else if (c == 's')
		bytes += ft_putstr_printf(va_arg(args, char *), fd);
	else if (c == 'p')
		bytes += ft_pointer_printf(va_arg(args, void *), fd);
	else if (c == 'u')
		bytes += ft_putunsigned_printf(va_arg(args, unsigned int), fd);
	else if (c == 'x')
		bytes += dec_to_hex_lower(va_arg(args, unsigned int), fd);
	else if (c == 'X')
		bytes += dec_to_hex_upper(va_arg(args, unsigned int), fd);
	else if (c == '%')
		bytes += ft_putchar_printf('%', fd);
	return (bytes);
}

int	ft_fdprintf(int fd, const char *s, ...)
{
	va_list	args;
	int		i;
	int		bytes;

	i = 0;
	va_start(args, s);
	bytes = 0;
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1])
		{
			bytes += formatter(fd, s[i + 1], args);
			i++;
		}
		else
			bytes += ft_putchar_printf(s[i], fd);
		i++;
	}
	va_end(args);
	return (bytes);
}
