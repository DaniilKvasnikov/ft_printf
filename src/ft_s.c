/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 17:42:11 by rgyles            #+#    #+#             */
/*   Updated: 2019/01/06 14:38:47 by rgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rgyles.h"
#include <stdio.h>

int		ft_s(t_spec *elem, va_list ap)
{
	int		size;
	char	*str;

	size = 0;
	str = va_arg(ap, char*);
	if (str == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	if (elem->precision != -1)
	{
		str = ft_strsub(str, 0, elem->precision);
		size = ft_strlen(str);
		size = ft_output(elem, str, size);
		free(str);
	}
	else
	{
		size = ft_strlen(str);
		size = ft_output(elem, str, size);
	}
	return (size);
}
