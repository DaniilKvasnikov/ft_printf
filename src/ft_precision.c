/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgyles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 18:13:37 by rgyles            #+#    #+#             */
/*   Updated: 2019/01/06 19:09:40 by rgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rgyles.h"
#include <stdio.h>

char	*ft_precision(char *str, int size)
{
	int	i;
	char *str_pre;

	i = ft_strlen(str);
	//printf("str - %s\n", str);
	//if (size == 0)
	//	return (ft_strsub(str, 0, 1));
	str_pre = ft_memset(ft_strnew(size), '0', size);
	while (size >= 0 && i >= 0)
	{
		//printf("current digit - %c\n", *str);
		str_pre[size--] = str[i--];
	}
	return (str_pre);
}
