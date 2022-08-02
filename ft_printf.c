/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaes <rmaes@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 14:43:03 by rmaes             #+#    #+#             */
/*   Updated: 2022/08/02 17:04:51 by rmaes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <errno.h>
#include <string.h>

static void	varread2(const char *content, size_t len, size_t *wrt, va_list ptr)
{
	if (content[len] == 'u')
		ft_putnbr_unsigned_count(va_arg(ptr, unsigned int), wrt);
	else if (content[len] == 'x')
		ft_puthexadecimal_count((va_arg(ptr, int)), 0, wrt);
	else if (content[len] == 'X')
		ft_puthexadecimal_count((va_arg(ptr, int)), 32, wrt);
	else if (content[len] == '%')
		*wrt += write(1, "%", 1);
}

static int	varread(const char *content, size_t len, size_t *wrt, va_list ptr)
{
	size_t	buf;

	buf = *wrt;
	while (buf == *wrt)
	{
		len++;
		if (content[len] == 'c')
			ft_putchar_count(va_arg(ptr, int), wrt);
		else if (content[len] == 's')
			ft_putstr_count(va_arg(ptr, char *), wrt);
		else if (content[len] == 'p')
			write(1, "not yet", 7);
		else if (content[len] == 'd')
			ft_putnbr_count(va_arg(ptr, int), wrt);
		else if (content[len] == 'i')
			ft_putnbr_count(va_arg(ptr, int), wrt);
		else
			varread2(content, len, wrt, ptr);
	}
	return (len + 1);
}

int	ft_printf(const char *content, ...)
{
	size_t	len;
	size_t	start;
	size_t	wrt;
	va_list	ptr;

	va_start(ptr, content);
	len = 0;
	start = 0;
	wrt = 0;
	while (content[start])
	{
		len = ft_partlen(content, start);
		ft_putlen(content, len, start, &wrt);
		start = len;
		if (content[len] == '%')
			start = varread(content, len, &wrt, ptr);
	}
	va_end(ptr);
	return (wrt);
}
