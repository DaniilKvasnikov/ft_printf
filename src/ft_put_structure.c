/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_structure.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 18:58:32 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/01/14 11:58:01 by rgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_rgyles.h"
#include "ft_array.h"

int		ft_put_structure(t_spec *elem, va_list ap)
{
	int	index;

	index = -1;
	while (g_funs[++index].f != NULL)
	{
		if (g_funs[index].c == elem->character)
			return (g_funs[index].f(elem, ap));
	}
	return (ft_invalid_character(elem));
}
