/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaes <rmaes@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 14:30:55 by rmaes             #+#    #+#             */
/*   Updated: 2022/08/01 17:10:51 by rmaes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <stdarg.h>
# include <stdio.h>
//DONT FORGOR TO REMOVE PLS

int		ft_printf(const char *content, ...);
int		ft_partlen(const char *s, size_t start);
void	ft_putlen(const char *s, size_t len, size_t start, size_t *wrt);
void	ft_putnbr_count(int n, size_t *wrt);
void	ft_putstr_count(char *s, size_t *wrt);
void	ft_putnbr_unsigned_count(unsigned int n, size_t *wrt);
size_t	ft_strlen(const char *s);
void	ft_putchar_count(int c, size_t *wrt);

#endif
