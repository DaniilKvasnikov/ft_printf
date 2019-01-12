/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 14:39:23 by rgyles            #+#    #+#             */
/*   Updated: 2019/01/12 16:16:46 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rgyles.h"

int		ft_c(t_spec *elem, va_list ap)
{
	int		size;
	int		c;

	size = 1;
	c = (int)va_arg(ap, int);
	while (size < elem->width && !elem->flag.minus)
	{
		size++;
		if (!elem->flag.zerro)
			ft_putchar(' ');
		else
			ft_putchar('0');
	}
	ft_putchar(c);
	while (size < elem->width && elem->flag.minus)
	{
		size++;
		ft_putchar(' ');
	}
	return (size);
}
