/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgyles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 15:20:28 by rgyles            #+#    #+#             */
/*   Updated: 2019/01/08 14:15:49 by rgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rgyles.h"
#include "libft.h"

static char	*ft_dtoa(double n)
{
	char	*str;
	char	*dop;
	char	*res;
	int		i;

	str = ft_itoa(n / 1);
	if (n < 0)
		n *= -1;
	dop = ft_strnew(7);
	dop[0] = '.';
	i = 0;
	while (n >= 1)
		n -= 1;
	while (++i < 7)
	{
		n *= 10.0 + 1e-9;
		dop[i] = (int)n + '0';
		while (n >= 1)
			n -= 1;
	}
	res = ft_strnew(ft_strlen(str) + ft_strlen(dop));
	ft_strcpy(res, str);
	ft_strcpy(res + ft_strlen(str), dop);
	free(str);
	free(dop);
	return (res);
}

int			ft_f(t_spec *elem, va_list ap)
{
	char	*str;
	int		size;

	str = ft_dtoa(va_arg(ap, double));
	size = ft_strlen(str);
	size = ft_output(elem, str, size);
	free(str);
	return (size);
}
