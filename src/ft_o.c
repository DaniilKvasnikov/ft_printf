/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_o.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgyles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 14:43:52 by rgyles            #+#    #+#             */
/*   Updated: 2019/01/08 18:23:57 by rgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rgyles.h"
#include <stdio.h>

int		ft_o(t_spec *elem, va_list ap)
{
	int		size;
	char	*par;
	//char	*tmp;

	if ((par = ft_rebase(va_arg(ap, int), 8)) == NULL)
		return (-1);
	/*if (elem->precision != -1)
	{
		tmp = par;
		par = ft_precision(par, elem->precision);
		free(tmp);
	}*/
	/*if (elem->flag.sharp == 1)
	{
		tmp = par;
		par = ft_strjoin("0", par);
		free(tmp);
	}*/
	if (elem->precision != -1 && par[0] == '0')
	{
		if (elem->flag.sharp == 1)
			size = ft_output(elem, "\0", 1);
		else 
			size = ft_output(elem, "\0", 0);
	}
	else if (elem->flag.sharp == 1)
		size = ft_output(elem, par, ft_strlen(par) + 1);
	else
		size = ft_output(elem, par, ft_strlen(par));
	free(par);
	return (size);
}
