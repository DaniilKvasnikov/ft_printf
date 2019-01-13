/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_o.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 14:43:52 by rgyles            #+#    #+#             */
/*   Updated: 2019/01/13 18:49:30 by rgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rgyles.h"
#include <stdio.h>

static unsigned long long int	allocator(t_spec *elem,
								unsigned long long int n)
{
	if (elem->length.l == 1 || elem->character == 'O')
		return ((unsigned long int)n);
	else if (elem->length.l == 2)
		return (n);
	else if (elem->length.h == 1)
		return ((unsigned short int)n);
	else if (elem->length.h == 2)
		return ((unsigned char)n);
	else if (elem->length.j == 1)
		return ((uintmax_t)n);
	return ((unsigned int)n);
}

int								ft_o(t_spec *elem, va_list ap)
{
	unsigned long long int	num;
	char					*par;
	int						size;

	num = allocator(elem, va_arg(ap, unsigned long long int));
	if ((par = ft_rebase(num, 8)) == NULL)
		return (-1);
	if (elem->precision != -1 && num == 0)
	{
		if (elem->flag.sharp == 1)
			size = ft_output(elem, "", 1);
		else
			size = ft_output(elem, "", 0);
	}
	else if (elem->flag.sharp == 1 && num == 0)
		size = ft_output(elem, "", 1);
	else if (elem->flag.sharp == 1)
		size = ft_output(elem, par, ft_strlen(par) + 1);
	else
		size = ft_output(elem, par, ft_strlen(par));
	free(par);
	return (size);
}
