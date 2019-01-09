/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 18:03:05 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/01/09 13:23:59 by rgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rgyles.h"

static int	get_size(long long int n)
{
	int		size;

	size = 0;
	if (n < 0)
	{
		n *= -1;
		size++;
	}
	while (n > 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char		*ft_itoa_lli(long long int n, t_spec *elem)
{
	char	*res;
	int		index;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -9223372036854775808)
		return (ft_strdup("-9223372036854775808"));
	if (n < 0)
	{
		elem->flag.plus = 2;
		n *= (-1);
	}
	index = get_size(n);
	if ((res = ft_strnew(index)) == NULL)
		return (NULL);
	while (n > 0)
	{
		index--;
		res[index] = (n % 10) + '0';
		n /= 10;
	}
	return (res);
}
