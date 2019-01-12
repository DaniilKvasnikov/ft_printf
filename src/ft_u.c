/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 14:08:48 by rgyles            #+#    #+#             */
/*   Updated: 2019/01/12 20:58:52 by rgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rgyles.h"

static unsigned long long int	get_num(t_spec *elem, va_list ap)
{
	if (elem->length.l == 1 || elem->character == 'U')
		return ((unsigned long int)va_arg(ap, unsigned long long int));
	else if (elem->length.l == 2)
		return ((unsigned long long int)va_arg(ap, unsigned long long int));
	else if (elem->length.h == 1)
		return ((unsigned short int)va_arg(ap, unsigned long long int));
	else if (elem->length.h == 2)
		return ((unsigned char)va_arg(ap, unsigned long long int));
	else if (elem->length.j >= 1)
		return ((uintmax_t)va_arg(ap, unsigned long long));
	return ((unsigned int)va_arg(ap, unsigned long long int));
}

int		ft_u(t_spec *elem, va_list ap)
{
	int						size;
	char					*str;
	unsigned long long int	n;

	n = get_num(elem, ap);
	if (n == 0 && elem->precision != -1)
		size = ft_output(elem, "\0", 0);
	else
	{
		str = ft_itoa_ui(n);
		size = ft_output(elem, str, ft_strlen(str));
		free(str);
	}
	return (size);
}
