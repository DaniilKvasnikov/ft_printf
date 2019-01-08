/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 18:07:37 by rgyles            #+#    #+#             */
/*   Updated: 2019/01/08 14:33:27 by rgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARRAY_H
# define FT_ARRAY_H

# include "ft_printf.h"

const t_func	funs[] = {
	{'c', &ft_c},
	{'d', &ft_d},
	{'u', &ft_u},
	{'i', &ft_i},
	{'s', &ft_s},
	{'p', &ft_p},
	{'x', &ft_x},
	{'X', &ft_xbig},
	{'%', &ft_percent},
	{'o', &ft_o},
	{'f', &ft_f},
	{'0', NULL}};

#endif
