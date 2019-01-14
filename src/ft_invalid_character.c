/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_invalid_character.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgyles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 11:52:39 by rgyles            #+#    #+#             */
/*   Updated: 2019/01/14 12:17:08 by rgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rgyles.h"

int	ft_invalid_character(t_spec *elem)
{
	int size;
	char	*str;

	if (elem->character == 0)
		return (0);
	str = ft_strnew(1);
	str[0] = elem->character;
	elem->precision = -1;
	size = ft_output(elem, str, 1);
	free(str);
	return (size);
}
