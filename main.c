/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 22:40:57 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/01/12 19:15:54 by rgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"
#include <limits.h>

int	main(int argc, char const *argv[])
{
	ft_printf("%O\n", LONG_MAX);
	printf("%O\n", LONG_MAX);
	return 0;
}
