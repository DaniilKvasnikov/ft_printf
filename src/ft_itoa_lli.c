/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 18:03:05 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/01/07 18:37:11 by rgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

char		*ft_itoa_lli(long long int n)
{
	char	*res;
	int		index;

	if (n == 0)
		return (ft_strdup("0"));
	//if (n == -2147483648)
	//	return (ft_strdup("-2147483648"));
	res = ft_strnew(get_size(n));
	if (res == NULL)
		return (NULL);
	index = get_size(n);
	if (n < 0)
	{
		n *= -1;
		res[0] = '-';
	}
	res[index] = '\0';
	while (n > 0)
	{
		index--;
		res[index] = (n % 10) + '0';
		n /= 10;
	}
	return (res);
}
