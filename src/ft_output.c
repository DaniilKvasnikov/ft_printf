/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgyles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/31 19:07:48 by rgyles            #+#    #+#             */
/*   Updated: 2019/01/06 20:19:43 by rgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rgyles.h"

int		ft_output(t_spec *elem, char *str, int size)
{
	while (size < elem->width && !elem->flag.minus && !elem->flag.zerro)
	{
		size++;
		ft_putchar(' ');
	}
	if (elem->character == 'p' || (elem->flag.sharp == 1 && str[0] != '0'))
		ft_putstr("0x");
	while (size < elem->width && !elem->flag.minus && elem->flag.zerro)
	{
		size++;
		ft_putchar('0');
	}
	ft_putstr(str);
	while (size < elem->width && elem->flag.minus)
	{
		size++;
		ft_putchar(' ');
	}
	return (size);
}

