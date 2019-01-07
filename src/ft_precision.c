/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgyles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 18:13:37 by rgyles            #+#    #+#             */
/*   Updated: 2019/01/07 18:10:35 by rgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rgyles.h"
#include <stdio.h>

char	*ft_precision(char *str, int size)
{
	int	i;
	char *str_pre;

	i = ft_strlen(str);
	str_pre = ft_memset(ft_strnew(size), '0', size);
	while (size >= 0 && i >= 0)
		str_pre[size--] = str[i--];
	return (str_pre);
}
