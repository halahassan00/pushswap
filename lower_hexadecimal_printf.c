/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lower_hexadecimal_printf.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhassan <hhassan@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 17:48:41 by hhassan           #+#    #+#             */
/*   Updated: 2026/03/14 21:58:08 by hahassan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_fdprintf.h"

int	dec_to_hex_lower(unsigned int n, int fd)
{
	char	*hex;
	int		count;

	count = 0;
	hex = "0123456789abcdef";
	if (n >= 16)
		count += dec_to_hex_lower(n / 16, fd);
	count += ft_putchar_printf(hex[n % 16], fd);
	return (count);
}
