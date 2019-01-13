/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 14:09:12 by rgyles            #+#    #+#             */
/*   Updated: 2019/01/13 16:27:37 by rgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rgyles.h"
#include <stdio.h>

static long long int	allocator(t_spec *elem, unsigned long long int n)
{
	if (elem->length.l == 1)
		return ((unsigned long int)n);
	else if (elem->length.j == 1)
		return ((uintmax_t)n);
	else if (elem->length.l == 2)
		return (n);
	else if (elem->length.h == 1)
		return ((unsigned int)n);
	else if (elem->length.h == 2)
		return ((unsigned char)n);
	else
		return ((unsigned int)n);
}

int						ft_x(t_spec *elem, va_list ap)
{
	int				size;
	char			*str;
	unsigned long long int	n;

	n = allocator(elem, va_arg(ap, unsigned long long int));
	if (n == 0)
	{
		elem->flag.sharp = 0;
		str = ft_strdup("0");
		size = ft_output(elem, str, 1);
	}
	else
	{
		if ((str = ft_rebase(n, 16)) == NULL)
			return (-1);
		if (elem->flag.sharp == 1)
			size = ft_output(elem, str, ft_strlen(str) + 2);
		else
			size = ft_output(elem, str, ft_strlen(str));
	}
	free(str);
	return (size);
}
