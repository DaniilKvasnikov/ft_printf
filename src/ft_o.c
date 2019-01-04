
#include "rgyles.h"
#include <stdio.h>
#include <stdint.h>

static char	*addone(char *str)
{
	int index;

	index = -1;
	while (str[++index] != '\0')
		;
	str[--index]++;
	while (index > 0)
	{
		if (str[index] == 'g')
		{
			str[index] = 0;
			str[index - 1]++;
		}
		index--;
	}
	return (str);
}

static char	*get_minus(char *str)
{
	char	*temp = "0123456789abcdef0";
	int		index;
	int		j;
	char	*res;
	char	c;

	res =ft_strnew(8);
	index = -1;
	int size = (8 - ft_strlen(str));
	while (++index < size)
		res[index] = 'f';
	j = 0;
	while (index < 8)
	{
		c = str[j++];
		if (c >= '0' && c <= '9')
			c = c - '0';
		else if (c >= 'A' && c <= 'Z')
			c = c - 'A' + 10;
		else if (c >= 'a' && c <= 'z')
			c = c - 'a' + 10;
		res[index++] = temp[15 - c];
	}
	addone(res);
	free(str);
	return (res);
}

static char	*get_null(char *str, int size)
{
	char	*res;
	int		index;
	int		j;

	if (size <= ft_strlen(str) || size <= 0)
		return (str);
	res = ft_strnew(size);
	index = -1;
	while (++index < (size - ft_strlen(str)))
		res[index] = '0';
	j = -1;
	index--;
	while (++index < size)
		res[index] = str[++j];
	free(str);
	return (res);
}

int			ft_o(t_spec *elem, va_list ap)
{
	long long int	num;
	char			*par;
	int				size;
	char			znak;

	num = (long long int)va_arg(ap, long long int);
	if (elem->length.l == 1)
		num = (long int)num;
	else if (elem->length.h == 1)
		num = (short int)num;
	else if (elem->length.h == 2)
		num = (unsigned int)num;
	else if (elem->length.j >= 1)
		num = (intmax_t)num;
	else if (elem->length.l == 0)
		num = (int)num;
	znak = 1;
	if (num < 0)
	{
		znak = -1;
		num = num * (-1);
	}
	if ((par = ft_rebase(num, 8)) == NULL)
		return (-1);
	if (znak == -1)
		par = get_minus(par);
	par = get_null(par, elem->precision);
	if (elem->flag.sharp != 0)
		par = get_null(par, ft_strlen(par) + 1);
	if (elem->flag.zerro != 0 && !elem->flag.minus)
		par = get_null(par, elem->width);
	size = ft_strlen(par);
	while (size < elem->width && elem->flag.minus == 0)
	{
		size++;
		ft_putchar(' ');
	}
	ft_putstr(par);
	while (size < elem->width)
	{
		size++;
		ft_putchar(' ');
	}
	free(par);
	return (size);
}
