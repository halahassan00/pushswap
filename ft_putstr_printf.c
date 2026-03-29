/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhassan <hhassan@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 17:44:04 by hhassan           #+#    #+#             */
/*   Updated: 2026/03/14 21:59:43 by hahassan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_putstr_printf(char *s, int fd)
{
	int	count;

	if (!s)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	count = 0;
	while (*s)
	{
		write(fd, s, 1);
		s++;
		count += 1;
	}
	return (count);
}
