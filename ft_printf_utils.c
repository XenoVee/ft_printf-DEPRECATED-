/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaes <rmaes@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 14:47:15 by rmaes             #+#    #+#             */
/*   Updated: 2022/08/01 17:05:21 by rmaes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	int	a;

	a = 0;
	while (s[a])
		a++;
	return (a);
}

int	ft_partlen(const char *s, size_t start)
{
	int	a;

	a = start;
	while (s[a] != '%' && s[a])
		a++;
	return (a);
}

void	ft_putlen(const char *s, size_t len, size_t start, size_t *wrt)
{
	*wrt += write(1, &s[start], len - start);
}
