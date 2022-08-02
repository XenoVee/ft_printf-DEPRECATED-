/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaes <rmaes@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 17:04:38 by rmaes             #+#    #+#             */
/*   Updated: 2022/08/02 17:09:31 by rmaes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthexadecimal_count(unsigned int x, int cap, size_t *wrt)
{
	if (x < 0)
	{
		*wrt += write (1, "-", 1);
		ft_puthexadecimal_count (-x, cap, wrt);
		return ;
	}
	else if (x > 0x10 - 1)
	{
		ft_puthexadecimal_count(x / 0x10, cap, wrt);
		ft_puthexadecimal_count(x % 0x10, cap, wrt);
	}
	else if (x > 0x10 - 1)
		return ;
	if (x <= 0xf)
	{
		if (x < 0xA)
			x = x + 48;
		else if (x >= 0xA)
			x = 87 + x - cap;
		*wrt += write (1, &x, 1);
	}
}

void	ft_putchar_count(int c, size_t *wrt)
{
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
