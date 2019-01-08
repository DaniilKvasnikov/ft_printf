/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_i.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgyles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 14:40:47 by rgyles            #+#    #+#             */
/*   Updated: 2019/01/08 14:41:25 by rgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rgyles.h"

int		ft_i(t_spec *elem, va_list ap)
{
	int		size;
	char	*str;

	str = ft_itoa(va_arg(ap, int));
	size = ft_output(elem, str, ft_strlen(str));
	free(str);
	return (size);
}
