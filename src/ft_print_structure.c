/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_structure.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 17:52:20 by rrhaenys          #+#    #+#             */
/*   Updated: 2018/12/27 18:45:26 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"

void	print_structure(t_spec *elem)
{
	printf("%s%s=%d %s=%d %s=%d %s=%d %s=%d\n", "flags: ",
		"minus", elem->flag.minus,
		"plus", elem->flag.plus,
		"space", elem->flag.space,
		"zerro", elem->flag.zerro,
		"sharp", elem->flag.sharp);
	printf("%s=%d\n", "width", elem->width);
	printf("%s=%d\n", "precision", elem->precision);
	printf("%s%s=%d %s=%d %s=%d %s=%d %s=%d %s=%d\n", "length: ",
		"h", elem->length.h,
		"l", elem->length.l,
		"L", elem->length.lbig,
		"j", elem->length.j,
		"z", elem->length.z,
		"t", elem->length.t);
	printf("%s=%c(%d)\n", "character", elem->character, elem->character);
}
