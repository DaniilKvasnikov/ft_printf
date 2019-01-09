/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xbig.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgyles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 12:01:39 by rgyles            #+#    #+#             */
/*   Updated: 2019/01/09 12:47:14 by rgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rgyles.h"

static long long int	allocator(t_spec *elem, long long int n)
{
	if (elem->length.l == 1)
		return ((long int)n);
	else if (elem->length.j >= 1)
		return ((intmax_t)n);
	else if (elem->length.l == 0)
		return ((int)n);
	else if (elem->length.h == 1)
		return ((short int)n);
	else if (elem->length.h == 2)
		return ((unsigned int)n);
	else
		return (n);
}

int						ft_xbig(t_spec *elem, va_list ap)
{
	int				size;
	char			*str;
	long long int	n;

	size = 0;
	n = allocator(elem, va_arg(ap, long long int));
	if (n == 0 && elem->precision == 0)
	{
		elem->flag.sharp = 0;
		size = ft_output(elem, "\0", 0);
	}
	else
	{
		if (n < 0)
			str = ft_x_minus(ft_rebase(n * (-1), 16));
		else
			str = ft_rebase(n, 16);
		if (str == NULL)
			return (-1);
		ft_toupper_str(str);
		if (elem->flag.sharp == 1 && str[0] != '0')
			size += 2;
		size = ft_output(elem, str, ft_strlen(str) + size);
		free(str);
	}
	return (size);
}
