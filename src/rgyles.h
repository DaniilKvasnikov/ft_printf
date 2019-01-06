/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgyles.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 16:56:49 by rgyles            #+#    #+#             */
/*   Updated: 2019/01/06 18:29:12 by rgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RGYLES_H
# define RGYLES_H

# include <stdarg.h>
# include <sys/types.h>
# include <stdlib.h>
# include <unistd.h>
# include "ft_spec.h"
# include "libft.h"

typedef struct	s_func
{
	char	c;
	int		(*f)(t_spec *elem, va_list ap);
}				t_func;

int		ft_c(t_spec *elem, va_list ap);
int		ft_o(t_spec *elem, va_list ap);
int		ft_d(t_spec *elem, va_list ap);
int		ft_i(t_spec *elem, va_list ap);
int		ft_u(t_spec *elem, va_list ap);
int		ft_s(t_spec *elem, va_list ap);
int		ft_p(t_spec *elem, va_list ap);
int		ft_x(t_spec *elem, va_list ap);
int		ft_xbig(t_spec *elem, va_list ap);
int		ft_percent(t_spec *elem, va_list ap);
int		ft_f(t_spec *elem, va_list ap);
int		ft_output(t_spec *elem, char *str, int size);
char	*ft_precision(char *str, int size);

#endif
