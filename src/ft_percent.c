/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgyles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 14:39:40 by rgyles            #+#    #+#             */
/*   Updated: 2019/01/12 19:13:21 by rgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rgyles.h"

int		ft_percent(t_spec *elem, va_list ap)
{
	int	size;

	(void)ap;
	elem->precision = -1;
	size = ft_output(elem, "%", 1);
	return(size);
}
