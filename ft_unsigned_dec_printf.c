/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_dec_printf.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhassan <hhassan@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 17:46:16 by hhassan           #+#    #+#             */
/*   Updated: 2026/03/14 22:00:01 by hahassan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

static int	put_char(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_putunsigned_printf(unsigned int n, int fd)
{
	int	bytes;

	bytes = 0;
	if (n >= 10)
		bytes += ft_putunsigned_printf(n / 10, fd);
	bytes += put_char(n % 10 + '0', fd);
	return (bytes);
}
