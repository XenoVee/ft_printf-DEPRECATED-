/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaes <rmaes@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 14:43:03 by rmaes             #+#    #+#             */
/*   Updated: 2022/08/01 17:06:09 by rmaes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <errno.h>
#include <string.h>

static int	varread2(const char *content, size_t len, size_t *wrt, va_list ptr)
{
	if (content[len] == 'u')
		ft_putnbr_unsigned_count(va_arg(ptr, unsigned int), wrt);
	else if (content[len] == 'x')
		write(1, "not yet", 7);
	else if (content[len] == 'X')
		write(1, "not yet", 7);
	else if (content[len] == '%')
		*wrt += write(1, "%", 1);
	else
	{
		*wrt += write(1, "%", 1);
		return (-1);
	}
	return (len);
}

static int	varread(const char *content, size_t len, size_t *wrt, va_list ptr)
{
	if (content[len] == '%')
	{
		len++;
		if (content[len] == 'c')
			ft_putstr_count(va_arg(ptr, char *), wrt);
		else if (content[len] == 's')
			ft_putstr_count(va_arg(ptr, char *), wrt);
		else if (content[len] == 'p')
			write(1, "not yet", 7);
		else if (content[len] == 'd')
			ft_putnbr_count(va_arg(ptr, int), wrt);
		else if (content[len] == 'i')
			ft_putnbr_count(va_arg(ptr, int), wrt);
		else if (varread2(content, len, wrt, ptr) == -1)
			return (len);
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
