/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 19:19:02 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/01/06 17:52:25 by rgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rgyles.h"
#include <stdio.h>

static int		ft_d_zerro(t_spec *elem, va_list ap)
{
	int n;
	int size;
	char sign;
	char *str;

	size = 0;
	sign = 1;
	if ((n = va_arg(ap, int)) < 0)
		sign = -1;
	str = ft_itoa(n * sign);
	if (elem->flag.plus > 0 || sign < 0)
	{
		if (sign > 0)
			ft_putchar('+');
		else
			ft_putchar('-');
		size++;
	}
	else if (n > 0 && elem->flag.space > 0)	
	{
		size++;
		ft_putchar(' ');
	}
	size = ft_output(elem, str, ft_strlen(str) + size);
	free(str);
	return (size);
}

int		ft_d(t_spec *elem, va_list ap)
{
	int n;
	int size;
	char sign;
	char *tmp;
	char *str;

	if (elem->flag.zerro == 1)
		return (ft_d_zerro(elem, ap));
	size = 0;
	sign = 1;
	if ((n = va_arg(ap, int)) < 0)
		sign = -1;
	str = ft_itoa(n * sign);
	if (elem->flag.plus == 1 || sign == -1)
	{
		tmp = str;
		if (sign > 0)
			str = ft_strjoin("+", str);
		else
			str = ft_strjoin("-", str);
		free(tmp);
	}
	else if (n > 0 && elem->flag.space ==1)	
	{
		tmp = str;
		str = ft_strjoin(" ", str);
		free(tmp);
	}
	size = ft_output(elem, str, ft_strlen(str) + size);
	free(str);
	return (size);
}
