/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgyles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/31 19:07:48 by rgyles            #+#    #+#             */
/*   Updated: 2019/01/08 18:38:21 by rgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rgyles.h"
#include <stdio.h>

static void	put_space(int *size)
{
	(*size)++;
	ft_putchar(' ');
}

static void	flag_check(t_spec *elem)
{
	if (elem->flag.plus == 1)
		ft_putchar('+');
	else if (elem->flag.plus == 2)
		ft_putchar('-');
	else if (elem->flag.space == 1)
		ft_putchar(' ');
}

static char	*precision_check(char *str, int size)
{
	int		i;
	char	*str_pre;

	i = ft_strlen(str);
	str_pre = ft_memset(ft_strnew(size), '0', size);
	while (size >= 0 && i >= 0)
		str_pre[size--] = str[i--];
	return (str_pre);
}

static void sharp_check(t_spec *elem, char c, int size)
{
	if (elem->character == 'p' || (elem->character == 'x' && c != '0'))
		ft_putstr("0x");
	else if (elem->character == 'X')
		ft_putstr("0X");
	else if (elem->character == 'o')
		ft_putchar('0');
}

int			ft_output(t_spec *elem, char *str, int size)
{
	if (elem->precision > 0 && elem->precision > (int)ft_strlen(str) && elem->character != 's' && *str != '0')
	{
		size += elem->precision - (int)ft_strlen(str);
		str = precision_check(str, elem->precision);
	}
	while (size < elem->width && !elem->flag.minus && !elem->flag.zerro)
		put_space(&size);
	if (elem->flag.sharp == 1)
		sharp_check(elem, str[0], size);
	if (elem->character == 'd')
		flag_check(elem);
	while (size < elem->width && !elem->flag.minus && elem->flag.zerro)
	{
		size++;
		ft_putchar('0');
	}
	ft_putstr(str);
	while (size < elem->width && elem->flag.minus)
		put_space(&size);
	return (size);
}
