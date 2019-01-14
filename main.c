/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 22:40:57 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/01/14 18:02:21 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"
#include <limits.h>

int	main(void)
{
	int num;

	ft_printf("", 0, 0);
	num = ft_printf("{%-15p}", 0);
	ft_printf("\n%d", num);
	return (0);
}
