/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahassan <hahassan@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 21:32:11 by hahassan          #+#    #+#             */
/*   Updated: 2026/03/14 21:55:21 by hahassan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	index;

	index = 0;
	while (s1[index] != '\0' && s2[index] != '\0' && index < n)
	{
		if (s1[index] < s2[index])
			return (-1);
		else if (s1[index] > s2[index])
			return (1);
		else
			index++;
	}
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
