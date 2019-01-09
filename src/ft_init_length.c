/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_length.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 01:19:13 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/01/10 01:20:06 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_length(t_spec *elem, char c)
{
	if (c == 'h')
		return (elem->length.h = (elem->length.h % 2 + 1));
	else if (c == 'l')
		return (elem->length.l = (elem->length.l % 2 + 1));
	else if (c == 'L')
		return (elem->length.lbig = (elem->length.lbig % 2 + 1));
	else if (c == 'j')
		return (elem->length.j = (elem->length.j % 2 + 1));
	else if (c == 'z')
		return (elem->length.z = (elem->length.z % 2 + 1));
	else if (c == 't')
		return (elem->length.t = (elem->length.t % 2 + 1));
	return (0);
}

char	*get_length(t_spec *elem, char *str)
{
	int	index;

	index = 0;
	while (is_length(elem, str[index]) != 0)
		index++;
	return (&(str[index]));
}
