/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upper_hexadecimal_printf.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhassan <hhassan@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 19:17:05 by hhassan           #+#    #+#             */
/*   Updated: 2026/03/14 21:58:23 by hahassan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_fdprintf.h"

int	dec_to_hex_upper(unsigned int n, int fd)
{
	char	*hex;
	int		count;

	hex = "0123456789ABCDEF";
	count = 0;
	if (n >= 16)
		count += dec_to_hex_upper(n / 16, fd);
	count += ft_putchar_printf(hex[n % 16], fd);
	return (count);
}
