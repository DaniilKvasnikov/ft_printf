/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_structure.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 16:30:43 by rrhaenys          #+#    #+#             */
/*   Updated: 2018/12/31 16:30:59 by rgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_flag(t_spec *elem, char c)
{
	if (c == '-')
		return (elem->flag.minus = 1);
	else if (c == '+')
		return (elem->flag.plus = 1);
	else if (c == ' ')
		return (elem->flag.space = 1);
	else if (c == '0')
		return (elem->flag.zerro = 1);
	else if (c == '#')
		return (elem->flag.sharp = 1);
	return (0);
}

char	*get_flags(t_spec *elem, char *str)
{
	int	index;

	index = 0;
	while (is_flag(elem, str[index]))
		index++;
	return (&(str[index]));
}

int		is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (c - 48);
	return (-1);
}

char	*get_width(t_spec *elem, char *str)
{
	int	index;
	int	sum;
	int num;

	index = 0;
	sum = 0;
	while ((num = is_num(str[index])) >= 0)
	{
		sum = sum * 10 + num;
		if (sum < 0)
		{
			sum = 0;
			break ;
		}
		index++;
	}
	while ((num = is_num(str[index])) >= 0)
	{
		index++;
	}
	elem->width = sum;
	return (&(str[index]));
}

char	*get_precision(t_spec *elem, char *str)
{
	int	index;
	int	sum;
	int num;

	index = 1;
	sum = 0;
	if (str[index - 1] != '.')
	{
		elem->precision = -1;
		return (str);
	}
	while ((num = is_num(str[index])) >= 0)
	{
		sum = sum * 10 + num;
		if (sum < 0)
		{
			sum = -1;
			break ;
		}
		index++;
	}
	while ((num = is_num(str[index])) >= 0)
	{
		index++;
	}
	elem->precision = sum;
	return (&(str[index]));
}

int		is_length(t_spec *elem, char c)
{
	if (c == 'h')
		return (elem->length.h = (elem->length.h % 2 + 1));
	else if (c == 'l')
		return (elem->length.l = (elem->length.l % 2 + 1));
	else if (c == 'L')
		return (elem->length.lbig = (elem->length.lbig % 2 + 1));
	else if (c == 'j')
		return (elem->length.j = (elem->length.j % 2 + 1));
	else if (c == 'z')
		return (elem->length.z = (elem->length.z % 2 + 1));
	else if (c == 't')
		return (elem->length.t = (elem->length.t % 2 + 1));
	return (0);
}

char	*get_length(t_spec *elem, char *str)
{
	int	index;

	index = 0;
	while (is_length(elem, str[index]) != 0)
		index++;
	return (&(str[index]));
}

int		is_character(t_spec *elem, char c)
{
	char *characters;

	characters = "diouxXceEfgGsp%";
	while (*characters != '\0')
	{
		if (c == *characters)
			return (elem->character = c);
		characters++;
	}
	return (0);
}

char	*get_character(t_spec *elem, char *str)
{
	int	index;

	index = 0;
	if (is_character(elem, str[index]) != 0)
		index++;
	return (&(str[index]));
}

int		ft_init_structure(t_spec *elem, char *str)
{
	char *start;

	start = str;
//	ft_clear_structure(elem);
	str++;
	str = get_flags(elem, str);
	str = get_width(elem, str);
	str = get_precision(elem, str);
	str = get_length(elem, str);
	str = get_character(elem, str);
	print_structure(elem);
	return (str - start);
}
