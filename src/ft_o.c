/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_o.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgyles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 14:43:52 by rgyles            #+#    #+#             */
/*   Updated: 2019/01/06 15:20:22 by rgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rgyles.h"
#include <stdio.h>

int		ft_o(t_spec *elem, va_list ap)
{
	int		size;
	char	*par;
	char	*tmp;

	if ((par = ft_rebase(va_arg(ap, int), 8)) == NULL)
		return (-1);
	if (elem->flag.sharp == 1)
	{
		tmp = par;
		par = ft_strjoin("0", par);
		free(tmp);
	}
	size = ft_output(elem, par, ft_strlen(par));
	free(par);
	return (size);
}
