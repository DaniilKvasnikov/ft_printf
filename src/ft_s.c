/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 17:42:11 by rgyles            #+#    #+#             */
/*   Updated: 2018/12/27 19:19:18 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rgyles.h"
#include <stdio.h>

int		ft_s(t_spec *elem, va_list ap)
{
	int		size;
	char	*str;
	int		index;

	str = va_arg(ap, char*);
	if (str == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	size = ft_strlen(str);
	while (size < elem->width && !elem->flag.minus)
	{
		size++;
		ft_putchar(' ');
	}
	ft_putstr(str);
	while (size < elem->width && elem->flag.minus)
	{
		size++;
		ft_putchar(' ');
	}
	return (size);
}
