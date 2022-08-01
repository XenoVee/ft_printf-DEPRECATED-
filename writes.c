/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaes <rmaes@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 17:04:38 by rmaes             #+#    #+#             */
/*   Updated: 2022/08/01 17:05:00 by rmaes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_count(va_list ptr, size_t *wrt)
{
	int	c;

	c = va_arg(ptr, int);
	*wrt += write(1, &c, 1);
}

void	ft_putnbr_count(int n, size_t *wrt)
{
	if (n == -2147483648)
	{
		*wrt += write(1, "-2147483648", 11);
		return ;
	}
	else if (n < 0)
	{
		*wrt += write (1, "-", 1);
		ft_putnbr_count (-n, wrt);
		return ;
	}
	else if (n > 9)
	{
		ft_putnbr_count (n / 10, wrt);
		ft_putnbr_count (n % 10, wrt);
	}
	if (n > 9)
		return ;
	n = n + 48;
	*wrt += write (1, &n, 1);
	return ;
}

void	ft_putnbr_unsigned_count(unsigned int n, size_t *wrt)
{
	if (n > 9)
	{
		ft_putnbr_count (n / 10, wrt);
		ft_putnbr_count (n % 10, wrt);
	}
	if (n > 9)
		return ;
	n = n + 48;
	*wrt += write (1, &n, 1);
	return ;
}

void	ft_putstr_count(char *s, size_t *wrt)
{
	if (s)
		*wrt += write(1, s, ft_strlen(s));
}
