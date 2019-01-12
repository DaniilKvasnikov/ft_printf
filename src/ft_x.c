/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 14:09:12 by rgyles            #+#    #+#             */
/*   Updated: 2019/01/12 21:20:18 by rgyles           ###   ########.fr       */
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

int						ft_x(t_spec *elem, va_list ap)
{
	int				size;
	char			*str;
	long long int	n;

	n = allocator(elem, va_arg(ap, long long int));
	if (n == 0)
	{
		elem->flag.sharp = 0;
		str = ft_strdup("0");
		size = ft_output(elem, str, 1);
	}
	else
	{
		if (n < 0)
			str = ft_x_minus(ft_rebase(n * (-1), 16));
		else
			str = ft_rebase(n, 16);
		if (str == NULL)
			return (-1);
		if (elem->flag.sharp == 1 && str[0] != '0')
			size = ft_output(elem, str, ft_strlen(str) + 2);
		else
			size = ft_output(elem, str, ft_strlen(str));
	}
	free(str);
	return (size);
}
