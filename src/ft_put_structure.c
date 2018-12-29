/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_structure.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 18:58:32 by rrhaenys          #+#    #+#             */
/*   Updated: 2018/12/27 19:17:56 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array.h"

int		ft_put_structure(t_spec *elem, va_list ap)
{
	int	index;

	index = -1;
	while (funs[++index].f != NULL)
	{
		if (funs[index].c == elem->character)
			return (funs[index].f(elem, ap));
	}
	return (0);
}