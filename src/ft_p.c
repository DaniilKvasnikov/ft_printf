/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgyles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 14:39:49 by rgyles            #+#    #+#             */
/*   Updated: 2019/01/06 14:39:57 by rgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rgyles.h"
#include <stdio.h>

int		ft_p(t_spec *elem, va_list ap)
{
	int		size;
	char	*ans;
	char	*p;

	if ((p = ft_rebase((long long)va_arg(ap, void*), 16)) == NULL)
		return (-1);
	if ((ans = ft_strjoin("0x", p)) == NULL)
	{
		free(p);
		return (-1);
	}
	size = ft_output(elem, ans, 0); 
	ft_bzero(p, ft_strlen(p));
	ft_bzero(ans, ft_strlen(ans));
	free(p);
	free(ans);
	return (size);
}
