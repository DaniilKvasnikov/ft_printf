/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 17:18:02 by rrhaenys          #+#    #+#             */
/*   Updated: 2018/11/20 17:18:04 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puts(char *str)
{
	if (str == NULL)
		return ;
	ft_putstr_fd(str, 1);
	ft_putchar_fd('\n', 1);
}
