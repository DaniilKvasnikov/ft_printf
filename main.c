/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 22:40:57 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/01/14 16:10:48 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"
#include <limits.h>

int	main(void)
{
	int num;

	num = ft_printf("%lc, %lc", L'暖', L'ح');
	ft_printf("\n%d", num);
	return (0);
}
