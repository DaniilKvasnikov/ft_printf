/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 19:19:02 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/01/08 16:40:39 by rgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rgyles.h"

/*static char	*precision_check(char **str, t_spec *elem)
{
	char *tmp;

	tmp = *str;
	free(*str);
	elem->flag.zerro = 0;
	*tmp = ft_precision(tmp, elem->precision);
	return (tmp);
}*/

int			ft_d(t_spec *elem, va_list ap)
{
	long long int n;
	int size;
	char *str;
	char *tmp;

	n = va_arg(ap, long long int);
	if (elem->length.l == 1)
		str = ft_itoa_lli((long int)n, elem);
	else if (elem->length.j == 1)
		str = ft_itoa_lli((intmax_t)n, elem);
	else if (elem->length.h == 1)
		str = ft_itoa_lli((short int)n, elem);
	else if (elem->length.h == 2)
		str = ft_itoa_lli((signed char)n, elem);
	else if (elem->length.l == 2)
		str = ft_itoa_lli(n, elem);
	else
		str = ft_itoa_lli((int)n, elem);
	if (elem->precision > 0)
		elem->flag.zerro = 0;
	if (n == 0 && elem->precision == 0)
		size = ft_output(elem, "\0", 0);
	else if (elem->flag.plus != 0 || elem->flag.space != 0)
		size = ft_output(elem, str, ft_strlen(str) + 1);
	else
		size = ft_output(elem, str, ft_strlen(str));
	free(str);
	return (size);
}
