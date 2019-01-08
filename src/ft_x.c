/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgyles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 14:09:12 by rgyles            #+#    #+#             */
/*   Updated: 2019/01/08 20:21:53 by rgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rgyles.h"
#include <stdio.h>

static char	*get_minus(char *str)
{
	char	*temp = "0123456789abcdef0";
	int		index;
	int		j;
	char	*res;
	char	c;

	res = ft_strnew(8);
	index = -1;
	while (++index < (8 - ft_strlen(str)))
		res[index] = 'f';
	j = 0;
	while (index < 8)
	{
		c = str[j++];
		if (c >= '0' && c <= '9')
			c = c - '0';
		else if (c >= 'A' && c <= 'Z')
			c = c - 'A' + 10;
		else if (c >= 'a' && c <= 'z')
			c = c - 'a' + 10;
		c = 15 - c;
		c = temp[c];
		res[index++] = c + (index == 7);
	}
	free(str);
	return (res);
}

static long long int	allocator(t_spec *elem, long long int n)
{
	if (elem->length.l == 1)
		return ((long int)n);
	else if (elem->length.j >= 1)
		return ((intmax_t)n);
	else if (elem->length.l == 0)
		return ((int)n);
	else if (elem->length.h == 1)
		return ((short int)n);
	else if (elem->length.h == 2)
		return ((unsigned int)n);
	else
		return (n);
}

int			ft_x(t_spec *elem, va_list ap)
{
	long long int	n;
	char			*str;
	char			sign;
	int				size;

	n = allocator(elem, va_arg(ap, long long int));
	sign = 1;
	if (n < 0)
	{
		sign = -1;
		n = n * (-1);
	}
	if (n == 0 && elem->precision == 0)
	{
		elem->flag.sharp = 0;
		size = ft_output(elem, "\0", 0);
	}
	else
	{
		if ((str = ft_rebase(n, 16)) == NULL)
			return (-1);
		if (sign == -1)
			str = get_minus(str);
		if (elem->flag.sharp == 1 && str[0] != '0')
			size = ft_output(elem, str, ft_strlen(str) + 2);
		else
			size = ft_output(elem, str, ft_strlen(str));	
		free(str);
	}
	return (size);
}
