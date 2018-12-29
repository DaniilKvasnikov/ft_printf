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

int		ft_d(t_spec *elem, va_list ap)
{
	char *str;
	int size;
	int n;
	char znak;

	znak = 1;
	if ((n = va_arg(ap, int)) < 0)
		znak = -1;
	str = ft_itoa(n * znak);
	size = ft_strlen(str);
	if (elem->flag.plus > 0 || znak < 0)
	{
		size++;
		if (znak > 0)
			ft_putchar('+');
		else
			ft_putchar('-');
	}
	else if (n > 0 && elem->flag.space > 0)
	{
		size++;
		ft_putchar(' ');
	}
	while (size < elem->width && !elem->flag.minus && elem->flag.zerro)
	{
		size++;
		ft_putchar('0');
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
