/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahassan <hahassan@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 20:42:28 by hahassan          #+#    #+#             */
/*   Updated: 2026/03/14 20:55:11 by hahassan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDPRINTF_H
# define FT_FDPRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_putnbr_printf(int n, int fd);
int	ft_pointer_printf(void *ptr, int fd);
int	ft_putchar_printf(char c, int fd);
int	ft_putstr_printf(char *s, int fd);
int	ft_putunsigned_printf(unsigned int n, int fd);
int	dec_to_hex_upper(unsigned int n, int fd);
int	dec_to_hex_lower(unsigned int n, int fd);
int	ft_fdprintf(int fd, const char *s, ...);

#endif
