/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgyles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 14:09:12 by rgyles            #+#    #+#             */
/*   Updated: 2019/01/08 14:09:27 by rgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rgyles.h"

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

int			ft_x(t_spec *elem, va_list ap)
{
	long long int	num;
	char			*par;
	char			sign;
	int				size;

	num = (long long int)va_arg(ap, long long int);
	if (elem->length.l == 1)
		num = (long int)num;
	else if (elem->length.j >= 1)
		num = (intmax_t)num;
	else if (elem->length.l == 0)
		num = (int)num;
	else if (elem->length.h == 1)
		num = (short int)num;
	else if (elem->length.h == 2)
		num = (unsigned int)num;
	sign = 1;
	if (num < 0)
	{
		sign = -1;
		num = num * (-1);
	}
	if (num == 0 && elem->precision == 0)
	{
		elem->flag.sharp = 0;
		size = ft_output(elem, "\0", 0);
	}
	else
	{
		if ((par = ft_rebase(num, 16)) == NULL)
			return (-1);
		if (sign == -1)
			par = get_minus(par);
		if (elem->flag.sharp == 1 && num != 0)
			size = ft_output(elem, par, ft_strlen(par) + 2);
		else
			size = ft_output(elem, par, ft_strlen(par));
		free(par);
	}
	return (size);
}
