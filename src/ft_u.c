/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgyles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 14:08:48 by rgyles            #+#    #+#             */
/*   Updated: 2019/01/12 18:45:03 by rgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rgyles.h"

int		ft_u(t_spec *elem, va_list ap)
{
	int						size;
	char					*str;
	unsigned long long int	n;

	n = va_arg(ap, unsigned long long int);
	if (elem->length.l == 1 || elem->character == 'U')
		n = (unsigned long int)n;
	else if (elem->length.l == 2)
		n = (unsigned long int)n;
	else if (elem->length.j == 1)
		n = (uintmax_t)n;
	else
		n = (unsigned int)n;
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
