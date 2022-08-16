/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaes <rmaes@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 14:47:15 by rmaes             #+#    #+#             */
/*   Updated: 2022/08/16 15:49:19 by rmaes            ###   ########.fr       */
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
