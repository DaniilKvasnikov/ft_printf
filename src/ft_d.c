/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 19:19:02 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/01/08 13:48:50 by rgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rgyles.h"
#include <stdio.h>

/*static int		ft_d_zerro(t_spec *elem, va_list ap)
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
	str = ft_itoa_lli(n * sign);
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
}*/

int		ft_d(t_spec *elem, va_list ap)
{
	long long int n;
	int size;
	char *str;
	char *tmp;

	n = va_arg(ap, long long int);
	if (elem->length.l == 1)
		str = ft_itoa_lli((long int)n, elem);
	else if (elem->length.j == 1)
		str = ft_itoa_lli((intmax_t)n, elem);
	else if (elem->length.h == 1)
		str = ft_itoa_lli((short int)n, elem);
	else if (elem->length.h == 2)
		str = ft_itoa_lli((signed char)n, elem);
	else if (elem->length.l == 2)
		str = ft_itoa_lli(n, elem);
	else
		str = ft_itoa_lli((int)n, elem);
	if (elem->precision != -1 && elem->precision > (int)ft_strlen(str))
	{
		tmp = str;
		elem->flag.zerro = 0;
		str = ft_precision(str, elem->precision);
		free(tmp);
	}
	//printf("str - %s\n", str);
	if (n == 0 && elem->precision == 0)
		size = ft_output(elem, "\0", 0);
	else if (elem->flag.plus != 0 || elem->flag.space != 0)
		size = ft_output(elem, str, ft_strlen(str) + 1);
	else
		size = ft_output(elem, str, ft_strlen(str));
	free(str);
	return (size);
}
