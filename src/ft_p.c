/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 14:39:49 by rgyles            #+#    #+#             */
/*   Updated: 2019/01/12 23:24:27 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rgyles.h"

int		ft_p(t_spec *elem, va_list ap)
{
	int		size;
	char	*p;

	if ((p = ft_rebase((long long)va_arg(ap, void*), 16)) == NULL)
		return (-1);
	if (*p == '0' && ft_strlen(p) && elem->precision >= 0)
	{
		free(p);
		p = ft_strnew(0);
	}
	elem->flag.sharp = 1;
	if (elem->precision < (int)ft_strlen(p))
		elem->precision = -1;
	size = ft_output(elem, p, ft_strlen(p) + 2);
	free(p);
	return (size);
}
