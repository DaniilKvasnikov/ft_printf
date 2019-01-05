/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 19:19:02 by rrhaenys          #+#    #+#             */
/*   Updated: 2018/12/27 19:19:09 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rgyles.h"
#include <stdio.h>
#include <stdint.h>

static char	*get_null(char *str, int size)
{
	char	*res;
	int		index;
	int		j;

	if (size <= ft_strlen(str) || size <= 0)
		return (str);
	res = ft_strnew(size);
	index = -1;
	while (++index < (size - ft_strlen(str)))
		res[index] = '0';
	j = -1;
	index--;
	while (++index < size)
		res[index] = str[++j];
	free(str);
	return (res);
}

static char	*get_znak(char *str, int znak)
{
	char	*res;
	res = ft_strnew(ft_strlen(str) + 1);
	if (znak > 0)
		res[0] = '+';
	else
		res[0] = '-';
	ft_strcpy(res + 1, str);
	free(str);
	return (res);
}

int		ft_d(t_spec *elem, va_list ap)
{
	char *str;
	int size;
	long long n;
	int znak;

	znak = 1;
	if (elem->length.h == 1)
		n = (short)va_arg(ap, int);
	else if (elem->length.h == 2)
		n = (char)va_arg(ap, int);
	else if (elem->length.l == 1)
		n = (long int)va_arg(ap, long int);
	else if (elem->length.l == 2)
		n = (long long)va_arg(ap, long long);
	else if (elem->length.j >= 1)
		n = (intmax_t)va_arg(ap, intmax_t);
	else if (elem->length.z >= 1)
		n = (size_t)va_arg(ap, size_t);
	else
		n = va_arg(ap, int);
	if (n < 0)
		znak = -1;
	str = ft_itoa(n * znak);
	if (elem->flag.zerro != 0 && elem->flag.minus == 0)
		str = get_null(str, elem->width - (elem->flag.zerro > 0));
	str = get_null(str, elem->precision);
	size = ft_strlen(str);
	if (elem->flag.plus > 0 || znak < 0)
	{
		str = get_znak(str, znak);
		size = ft_strlen(str);
	}
	else if (n > 0 && elem->flag.space > 0)
	{
		size++;
		ft_putchar(' ');
	}
	while (size < elem->width && !elem->flag.minus)
	{
		size++;
		ft_putchar(' ');
	}
	ft_putstr(str);
	while (size < elem->width)
	{
		size++;
		ft_putchar(' ');
	}
	free(str);
	return (size);
}
