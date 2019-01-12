/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_o.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 14:43:52 by rgyles            #+#    #+#             */
/*   Updated: 2019/01/12 19:57:42 by rgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rgyles.h"
#include <stdio.h>
#include <stdint.h>

static long long int	get_num(t_spec *elem, va_list ap)
{
	if (elem->length.l == 1 || elem->character == 'O')
		return ((long int)va_arg(ap, long int));
	else if (elem->length.l == 2)
		return ((long long int)va_arg(ap, long long int));
	else if (elem->length.h == 1)
		return ((short int)va_arg(ap, int));
	else if (elem->length.h == 2)
		return ((unsigned int)va_arg(ap, unsigned int));
	else if (elem->length.j >= 1)
		return ((intmax_t)va_arg(ap, intmax_t));
	return ((int)va_arg(ap, int));
}

int						ft_o(t_spec *elem, va_list ap)
{
	long long int	num;
	char			*par;
	int				size;
	char			znak;

	num = get_num(elem, ap);
	znak = 1;
	if (num < 0)
		num *= (znak = -1);
	if ((par = ft_rebase(num, 8)) == NULL)
		return (-1);
	if (elem->precision != -1 && par[0] == '0')
	{
		if (elem->flag.sharp == 1)
			size = ft_output(elem, "\0", 1);
		else
			size = ft_output(elem, "\0", 0);
	}
	else if (elem->flag.sharp == 1)
		size = ft_output(elem, par, ft_strlen(par) + 1);
	else
		size = ft_output(elem, par, ft_strlen(par));
	free(par);
	return (size);
}
