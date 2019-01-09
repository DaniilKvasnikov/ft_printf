/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_minus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgyles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 12:18:09 by rgyles            #+#    #+#             */
/*   Updated: 2019/01/09 12:29:58 by rgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rgyles.h"

char	*ft_x_minus(char *str)
{
	int		index;
	int		j;
	char	c;
	char	*res;
	char	*temp;

	if (str == NULL || (res = ft_strnew(8)) == NULL)
		return (NULL);
	temp = "0123456789abcdef0";
	ft_memset(res, 'f', 8);
	index = 8 - ft_strlen(str);
	j = 0;
	while (index < 8)
	{
		c = str[j++];
		if (c >= '0' && c <= '9')
			c = c - '0';
		else if (c >= 'a' && c <= 'z')
			c = c - 'a' + 10;
		res[index] = temp[15 - c] + (index == 7);
		index++;
	}
	free(str);
	return (res);
}
