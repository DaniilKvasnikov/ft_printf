/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgyles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 14:39:23 by rgyles            #+#    #+#             */
/*   Updated: 2019/01/06 14:39:32 by rgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rgyles.h"
#include <stdio.h>

int		ft_c(t_spec *elem, va_list ap)
{
	int size;
	char c;

	size = 1;
	c = (unsigned int)va_arg(ap, int);
	while (size < elem->width && !elem->flag.minus)
	{
		size++;
		ft_putchar(' ');
	}
	ft_putchar(c);
	while (size < elem->width && elem->flag.minus)
	{
		size++;
		ft_putchar(' ');
	}
	return (size);
}
