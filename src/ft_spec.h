/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 14:05:14 by rrhaenys          #+#    #+#             */
/*   Updated: 2018/12/27 16:41:06 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SPEC_H
# define FT_SPEC_H

typedef struct	s_flag
{
	char		minus;
	char		plus;
	char		space;
	char		zerro;
	char		sharp;
}				t_flag;

typedef struct	s_len_mod
{
	char		h;
	char		l;
	char		lbig;
	char		j;
	char		z;
	char		t;
}				t_len_mod;

typedef struct	s_spec
{
	t_flag		flag;
	int			width;
	int			precision;
	t_len_mod	length;
	char		character;
}				t_spec;

#endif
