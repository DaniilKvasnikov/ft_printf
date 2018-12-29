
#include "rgyles.h"
#include <stdio.h>

static char	*get_minus(char *str)
{
	char	*temp = "0123456789abcdef0";
	int		index;
	int		j;
	char	*res;
	char	c;

	res =ft_strnew(8);
	index = -1;
	while (++index < (8 - ft_strlen(str)))
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
		c = 15 - c;
		c = temp[c];
		res[index++] = c + (index == 7);
	}
	free(str);
	return (res);
}

int			ft_x(t_spec *elem, va_list ap)
{
	long long int	num;
	char			*par;
	int				size;
	char			znak;

	num = (long long int)va_arg(ap, long long int);
	if (elem->length.l == 1)
		num = (long int)num;
	else if (elem->length.l == 0)
		num = (int)num;
	else if (elem->length.h == 1)
		num = (short int)num;
	else if (elem->length.h == 2)
		num = (unsigned int)num;
	else if (elem->length.j >= 1)
		num = (intmax_t)num;
	znak = 1;
	if (num < 0)
	{
		znak = -1;
		num = num * (-1);
	}
	if ((par = ft_rebase(num, 16)) == NULL)
		return (-1);
	if (znak == -1)
		par = get_minus(par);
	size = ft_strlen(par);
	if (elem->flag.sharp > 0 && num != 0)
		size += 2;
	while (size < elem->width && !elem->flag.minus && !elem->flag.zerro)
	{
		size++;
		ft_putchar(' ');
	}
	if (elem->flag.sharp > 0 && num != 0)
		ft_putstr("0x");
	while (size < elem->width && !elem->flag.minus && elem->flag.zerro)
	{
		size++;
		ft_putchar('0');
	}
	ft_putstr(par);
	while (size < elem->width && elem->flag.minus)
	{
		size++;
		ft_putchar(' ');
	}
	free(par);
	return (size);
}
