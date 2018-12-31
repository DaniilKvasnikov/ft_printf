/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 17:42:11 by rgyles            #+#    #+#             */
/*   Updated: 2018/12/31 19:18:35 by rgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rgyles.h"
#include <stdio.h>

static void	ft_putstr_len(char *str, int len)
{
	while (len-- > 0)
	{
		ft_putchar(*str);
		str++;
	}
}

int		ft_s(t_spec *elem, va_list ap)
{
	int		size;
	char	*str;
	//int		index;

	str = va_arg(ap, char*);
	if (str == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	if (elem->precision != -1)
	{
		str = ft_strsub(str, 0, elem->precision);
		size = ft_strlen(str);
		size = ft_output(elem, str, size);
		free(str);
	}
	else
	{
		size = ft_strlen(str);
		size = ft_output(elem, str, size);
	}
	/*while (size < elem->width && !elem->flag.minus)
	{
		size++;
		ft_putchar(' ');
	}
	if (elem->precision == -1)
		ft_putstr(str);
	else
		ft_putstr_len(str, elem->precision);
	while (size < elem->width && elem->flag.minus)
	{
		size++;
		ft_putchar(' ');
	}*/
	return (size);
}
