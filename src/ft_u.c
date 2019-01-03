
#include "rgyles.h"
#include <stdio.h>
#include <stdint.h>

int		ft_u(t_spec *elem, va_list ap)
{
	char *str;
	int size;
	unsigned long long n;

	if (elem->length.l == 1)
		n = (unsigned long)va_arg(ap, long);
	else if (elem->length.l == 2)
		n = (unsigned long long)va_arg(ap, long long);
	else if (elem->length.j >= 1)
		n = (intmax_t)va_arg(ap, intmax_t);
	else if (elem->length.l == 0)
		n = (unsigned int)va_arg(ap, int);
	str = ft_iutoa(n);
	size = ft_strlen(str);
	if (elem->precision != -1)
	{
		while (size < elem->precision)
		{
			size++;
			ft_putchar('0');
		}
		ft_putstr(str);
		free(str);
		return (size);
	}
	while (size < elem->width && !elem->flag.minus && elem->flag.zerro)
	{
		size++;
		ft_putchar('0');
	}
	while (size < elem->width && !elem->flag.minus && elem->precision == -1)
	{
		size++;
		ft_putchar(' ');
	}
	ft_putstr(str);
	while (size < elem->width && elem->precision == -1)
	{
		size++;
		ft_putchar(' ');
	}
	free(str);
	return (size);
}
