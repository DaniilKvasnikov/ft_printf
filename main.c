/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 22:40:57 by rrhaenys          #+#    #+#             */
/*   Updated: 2018/12/31 15:18:12 by rgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"

int	main(int argc, char const *argv[])
{
	double d;

	d = 100.1;
//	ft_printf("%5%\n");
//	ft_printf("%-5%\n");
//	ft_printf("%f\n", 100.1);
	//ft_printf("%f\n", 100.0);
	ft_printf("%f\n", 100.192);
	return 0;
}
