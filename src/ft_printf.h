/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 14:22:27 by rrhaenys          #+#    #+#             */
/*   Updated: 2018/12/27 19:08:12 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <sys/types.h>
# include <stdlib.h>
# include <unistd.h>
# include "ft_rrhaenys.h"
# include "rgyles.h"

int		ft_printf(const char *format, ...);
int		ft_init_structure(t_spec *elem, char *str);
int		ft_put_structure(t_spec *elem, va_list ap);

#endif
